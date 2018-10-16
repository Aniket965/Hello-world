const sql = require('mssql');
const {dump} = require('dumper.js');

const DATABASE1 = process.env.DATABASE_SLAVE;
const DATABASE2 = process.env.DATABASE_MASTER;
const password = process.env.DB_PASSWORD;

const configConnection1 = {
    user: 'sa',
    password,
    server: process.env.DATABASE_SERVER_SLAVE, // You can use 'localhost\\instance' to connect to named instance
    database: DATABASE1,
    encrypt: false
};

const configConnection2 = {
    user: 'sa',
    password,
    server: process.env.DATABASE_SERVER_MASTER, // You can use 'localhost\\instance' to connect to named instance
    database: DATABASE2,
    encrypt: false
};

class Database {
    constructor() {
        this.pool1 = null;
        this.pool2 = null;
    }

    async connectionDatabase1() {
        this.pool1 = await new sql.ConnectionPool(configConnection1).connect();
    }

    async connectionDatabase2() {
        this.pool2 = await new sql.ConnectionPool(configConnection2).connect();
    }

    async showTablesDatabase(database) {
        let sqlString = "SELECT TABLE_NAME FROM " + database + ".INFORMATION_SCHEMA.TABLES WHERE TABLE_TYPE = 'BASE TABLE'";

        if (database == DATABASE1)
            return await this.pool1.request().query(sqlString)
        else
            return await this.pool2.request().query(sqlString)
    }

    async init() {
        await this.connectionDatabase1();
        await this.connectionDatabase2();
    }

    async describeTable(database, table) {
        let result = null;
        let sqlString = "SELECT * FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = '" + table + "'";

        switch (database) {
            case DATABASE1:
                result = await this.pool1.request().query(sqlString)
                break;
            case DATABASE2:
                result = await this.pool2.request().query(sqlString)
                break;
        }

        return result;
    }

    async closeConnections() {
        this.pool1.close();
        this.pool2.close();
    }
}

const connect = new Database();

async function compareTables(tablesA, tablesB) {
    let tablesNotInB = [];
    let inDatabaseA = false;
    let describeB = {};
    let describeA = null;
    let columnsPendingOnB = {};
    let columnsPending = null;

    for (let index = 0; index < tablesB.length; index++) {
        const tableB = tablesB[index];
        inDatabaseA = false;

        for (let index2 = 0; index2 < tablesA.length; index2++) {
            const tableA = tablesA[index2];

            if (tableB.TABLE_NAME.toString().toUpperCase() !== tableA.TABLE_NAME.toString().toUpperCase())
                continue;

            inDatabaseA = true;

            if (!describeB.hasOwnProperty(tableA.TABLE_NAME)) {
                describeB[tableA.TABLE_NAME] = await connect.describeTable(DATABASE2, tableA.TABLE_NAME);
            }

            describeA = await connect.describeTable(DATABASE1, tableB.TABLE_NAME);
            columnsPending = await compareColumnsTable(describeA.recordset, describeB[tableA.TABLE_NAME].recordset);

            if (columnsPending.length > 0)
                columnsPendingOnB[tableA.TABLE_NAME] = columnsPending;
        }

        if (!inDatabaseA) {
            tablesNotInB.push({
                table: tableB.TABLE_NAME
            });
        }
    }

    return {
        tablesNotInB,
        columnsPendingOnB
    };
}

async function compareColumnsTable(columnsA, columnsB) {
    let inColumnsB = false;
    let columnsPendingOnB = [];
    let length = null;

    columnsB.forEach(async columnB => {
        inColumnsB = false;

        columnsA.forEach(async columnA => {
            if (columnB.COLUMN_NAME.toString().toUpperCase() === columnA.COLUMN_NAME.toString().toUpperCase()) {
                inColumnsB = true;
            }
        });

        if (!inColumnsB) {
            switch (columnB.DATA_TYPE) {
                case 'varchar':
                case 'text':
                case 'varchar2':
                    length = columnB.CHARACTER_MAXIMUM_LENGTH;
                    break;

                case 'int':
                case 'decimal':
                case 'float':
                    length = columnB.NUMERIC_PRECISION + (columnB.NUMERIC_PRECISION_RADIX ? ',' + columnB.NUMERIC_PRECISION_RADIX : '');
                    break;

                default:
                    length = null;
                    break;
            }


            columnsPendingOnB.push({
                database: columnB.TABLE_CATALOG,
                table: columnB.TABLE_NAME,
                column: columnB.COLUMN_NAME,
                dataType: columnB.DATA_TYPE,
                nullable: columnB.IS_NULLABLE,
                default: columnB.COLUMN_DEFAULT,
                length: length,
                command: addColumn(columnB)
            });
        }
    });

    return columnsPendingOnB;
}

function addColumn(column) {
    let type = column.DATA_TYPE.toString() === 'varchar'
        ? column.DATA_TYPE + '(' + column.CHARACTER_MAXIMUM_LENGTH + ')'
        : column.DATA_TYPE;
    let sql = `ALTER TABLE ${column.TABLE_NAME}  ADD ${column.COLUMN_NAME} ${type} `;

    if (column.IS_NULLABLE) {
        sql = sql + ' NULL ';
    } else {
        sql = sql + ' NOT NULL ';
    }

    switch (column.DATA_TYPE) {
        case 'varchar':
        case 'varchar2':
        case 'text':
            sql = sql + 'DEFAULT \'\'';
            break;

        case 'int':
        case 'decimal':
        case 'float':
            if (column.COLUMN_DEFAULT)
                sql = sql + 'DEFAULT' + column.COLUMN_DEFAULT.replace('((', '(').replace('))', ')');
            else
                sql = sql + 'DEFAULT(0)';

            break;
    }

    if (column.DATA_TYPE != 'datetime')
    {
        sql = sql +  ' WITH VALUES '
    }
    
    sql = sql + ' ;'

    return sql;
}

async function getInfo() {
    await connect.init();

    let tablesA = await connect.showTablesDatabase(DATABASE1);
    let tablesB = await connect.showTablesDatabase(DATABASE2);
    let compare = await compareTables(tablesA.recordset, tablesB.recordset);

    // await connect.closeConnections();

    return compare;
}

module.exports = getInfo;

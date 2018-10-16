const getInfo = require('../service/database');
const xl = require('excel4node');
const {dump} = require('dumper.js');
const _ = require('lodash');

class IndexController {

    async indexAction(req, res, next) {
        res.render('index');
    }

    async tablesAction(req, res, next) {
        let data = await getInfo();

        res.render('tables', data);
    }

    async columnsAction(req, res, next) {
        let data = await getInfo();

        res.render('columns', processColumns(data));
    }

    async reportAction(req, res, next) {
        const wb = new xl.Workbook();
        const columnsWs = wb.addWorksheet('Columnas');
        const tablesWs = wb.addWorksheet('Tablas');
        const info = await getInfo();
        const styleTitle = wb.createStyle({
            font: {
                color: '#000000',
                size: 14,
                bold: true,
            },
        });
        let index = 1;

        _.forEach(info.columnsPendingOnB, columns => {
            columnsWs.cell(index, 1).string('Tabla').style(styleTitle);
            columnsWs.cell(index, 2).string('Columna').style(styleTitle);
            columnsWs.cell(index, 3).string('Tipo').style(styleTitle);
            columnsWs.cell(index, 4).string('Nullable').style(styleTitle);
            columnsWs.cell(index, 5).string('Length').style(styleTitle);
            columnsWs.cell(index, 6).string('Column Default').style(styleTitle);
            index++;

            _.forEach(columns, element => {
                columnsWs.cell(index, 1).string(IndexController.parseString(element.table));
                columnsWs.cell(index, 2).string(IndexController.parseString(element.column));
                columnsWs.cell(index, 3).string(IndexController.parseString(element.dataType));
                columnsWs.cell(index, 4).string(IndexController.parseString(element.nullable));
                columnsWs.cell(index, 5).string(IndexController.parseString(element.length));
                columnsWs.cell(index, 6).string(IndexController.parseString(element.default));
                index++;
            });

            index++;
            index++;
        });

        index = 1;
        tablesWs.cell(index, 1).string('Tablas Pendientes').style(styleTitle);
        _.forEach(info.tablesNotInB, table => {
            tablesWs.cell(index, 1).string(table.table);
            index++;
        });

        wb.write('ExcelFile.xlsx', res);
    }

    static parseString(element) {
        return element ? element.toString() : '';
    }
}

function processColumns(info) {
    let commandsAll = [];
    _.forEach(info.columnsPendingOnB, (table, key) => {
        let commands = [];
        _.forEach(table, column => {
            commands.push(column.command);
            commandsAll.push(column.command);
        });
        info.columnsPendingOnB[key].commands = commands;
    });

    info.commandsAll = commandsAll;

    return info;
}

module.exports = IndexController;

using System;
using System.Data.SqlClient;

namespace DbUtil
{
    public class DbUtil
    {
        private readonly string _connectionString;

        public DbUtil(string connectionString)
        {
            _connectionString = connectionString;
        }

        /// <summary>
        /// Run Query.
        /// </summary>
        /// <param name="query"></param>
        /// <param name="mapResponse"></param>
        /// <returns></returns>
        public T RunQuery<T>(string query, Func<SqlDataReader, T> mapResponse)
        {
            using (var connection = new SqlConnection(_connectionString))
            {
                connection.Open();
                using (var command = new SqlCommand(query, connection))
                using (var reader = command.ExecuteReader())
                {
                    return mapResponse.Invoke(reader);
                }
            }
        }

        /// <summary>
        /// Runs a query with no response
        /// </summary>
        /// <param name="query"></param>
        public void RunQuery(string query)
        {
            using (var connection = new SqlConnection(_connectionString))
            {
                connection.Open();
                using (var command = new SqlCommand(query, connection))
                {
                    command.ExecuteReader();
                }
            }
        }
    }
}

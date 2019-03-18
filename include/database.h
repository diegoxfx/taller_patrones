#pragma once
//#define OTL_ODBC_MYSQL // Compile OTL 4.0/ODBC/MySQL
//#include <otlv4.h> // include the OTL 4.0 header file
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>

class DataBase {
 public:
  static DataBase& getInstance()  {
    static DataBase db;
    return db;
  }

  void hola();
  
  static sql::Statement *stmt;
  static sql::ResultSet *res;

 private:
  DataBase();

  DataBase(DataBase const &);
  void operator=(DataBase const &);

  //otl_connect db;
  static sql::Driver *driver;
  static sql::Connection *con;
};

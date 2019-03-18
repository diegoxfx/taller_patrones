#include <database.h>
#include <iostream>

sql::Driver* DataBase::driver=nullptr;
sql::Connection* DataBase::con=nullptr;
sql::Statement* DataBase::stmt=nullptr;
sql::ResultSet* DataBase::res=nullptr;


DataBase::DataBase(){
  DataBase::driver = get_driver_instance();
  DataBase::con = DataBase::driver->connect("tcp://127.0.0.1:3306",
					    "root", "123");
  DataBase::con->setSchema("mydb");
  DataBase::stmt = DataBase::con->createStatement();
}

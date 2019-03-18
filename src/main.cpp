#include <cliente.h>
#include <factura.h>
#include <item.h>
#include <tipo_item.h>
#include <interfaz.h>
#include <database.h>
#include <dao_tipo_item.h>
#include <iostream>
#include <list>

using namespace std;

int main() {

  DataBase::getInstance();

  interfaz_consola();
  
  return 0;
}

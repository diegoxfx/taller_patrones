#include <interfaz.h>
#include <database.h>
#include <cliente.h>
#include <factura.h>
#include <item.h>
#include <tipo_item.h>
#include <dao_cliente.h>
#include <dao_factura.h>
#include <dao_tipo_item.h>
#include <dao_item.h>
#include <iostream>
#include <string>

using namespace std;

Dao<Cliente>* dc = new Dao<Cliente>();
Dao<Factura>* df = new Dao<Factura>();
Dao<Item>* di = new Dao<Item>();
Dao<TipoItem>* dti = new Dao<TipoItem>();

void interfaz_consola() {
  int estado = menu_principal;
  int opcion = 0;

  cout << " ----------------------------------------- " << endl
       << "|               Bienvenido                |" << endl
       << " ----------------------------------------- " << endl;

  while(estado != salir) {
    switch(estado) {
    case menu_principal:
      interfaz_menu_principal(estado);
      break;
    case crear:
      interfaz_menu_crear(estado);
      break;
    case leer:
      interfaz_menu_leer(estado);
      break;
    case actualizar:
      interfaz_menu_actualizar(estado);
      break;
    case borrar:
      interfaz_menu_borrar(estado);
      break;
      
    case crear_cliente:
      interfaz_crear_cliente(estado);
      break;
    case crear_factura:
      interfaz_crear_factura(estado);
      break;
    case crear_item:
      interfaz_crear_item(estado);
      break;
    case crear_tipo_item:
      interfaz_crear_tipo_item(estado);
      break;

    case leer_cliente:
      interfaz_leer_cliente(estado);
      break;
    case leer_factura:
      interfaz_leer_factura(estado);
      break;
    case leer_item:
      interfaz_leer_item(estado);
      break;
    case leer_tipo_item:
      interfaz_leer_tipo_item(estado);
      break;

    case actualizar_cliente:
      interfaz_actualizar_cliente(estado);
      break;
    case actualizar_factura:
      interfaz_actualizar_factura(estado);
      break;
    case actualizar_item:
      interfaz_actualizar_item(estado);
      break;
    case actualizar_tipo_item:
      interfaz_actualizar_tipo_item(estado);
      break;

    case borrar_cliente:
      interfaz_borrar_cliente(estado);
      break;
    case borrar_factura:
      interfaz_borrar_factura(estado);
      break;
    case borrar_item:
      interfaz_borrar_item(estado);
      break;
    case borrar_tipo_item:
      interfaz_borrar_tipo_item(estado);
      break;
    }
  }
}


void interfaz_menu_principal(int &estado) {
  int opcion;
  cout << " ----------------------------------------- " << endl
       << "|   Selecciona una opción para continuar  |" << endl
       << "| 1. Crear.                               |" << endl
       << "| 2. Leer.                                |" << endl
       << "| 3. Actualizar.                          |" << endl
       << "| 4. Borrar.                              |" << endl
       << "| 5. Salir.                               |" << endl
       << " ----------------------------------------- " << endl;

  cin >> opcion;

  switch(opcion){
  case 1:
    estado = crear;
    break;
  case 2:
    estado = leer;
    break;
  case 3:
    estado = actualizar;
    break;
  case 4:
    estado = borrar;
    break;
  case 5:
    estado = salir;
    break;
  default:
    cout << "opcion invalida, intente nuevamente" << endl;
    estado = menu_principal;
  }
}


void interfaz_menu_crear(int &estado) {
  int opcion;
  cout << " ----------------------------------------- " << endl
       << "|            ¿Qué desea crear?            |" << endl
       << "| 1. Factura.                             |" << endl
       << "| 2. Cliente.                             |" << endl
       << "| 3. Item.                                |" << endl
       << "| 4. Tipo Item.                           |" << endl
       << "| 5. Regresar.                            |" << endl
       << " ----------------------------------------- " << endl;

  cin >> opcion;

  switch(opcion){
  case 1:
    estado = crear_factura;
    break;
  case 2:
    estado = crear_cliente;
    break;
  case 3:
    estado = crear_item;
    break;
  case 4:
    estado = crear_tipo_item;
    break;
  case 5:
    estado = menu_principal;
    break;
  default:
    cout << "opcion invalida" << endl;
    break;
  }
}

void interfaz_menu_leer(int &estado) {
  int opcion;
  cout << " ----------------------------------------- " << endl
       << "|            ¿Qué desea leer?             |" << endl
       << "| 1. Factura.                             |" << endl
       << "| 2. Cliente.                             |" << endl
       << "| 3. Item.                                |" << endl
       << "| 4. Tipo Item.                           |" << endl
       << "| 5. Regresar.                            |" << endl
       << " ----------------------------------------- " << endl;

  cin >> opcion;

  switch(opcion){
  case 1:
    estado = leer_factura;
    break;
  case 2:
    estado = leer_cliente;
    break;
  case 3:
    estado = leer_item;
    break;
  case 4:
    estado = leer_tipo_item;
    break;
  case 5:
    estado = menu_principal;
    break;
  default:
    cout << "opcion invalida" << endl;
    break;
  }
}

void interfaz_menu_actualizar(int &estado) {
  int opcion;
  cout << " ----------------------------------------- " << endl
       << "|          ¿Qué desea actualizar?         |" << endl
       << "| 1. Factura.                             |" << endl
       << "| 2. Cliente.                             |" << endl
       << "| 3. Item.                                |" << endl
       << "| 4. Tipo Item.                           |" << endl
       << "| 5. Regresar.                            |" << endl
       << " ----------------------------------------- " << endl;

  cin >> opcion;

  switch(opcion){
  case 1:
    estado = actualizar_factura;
    break;
  case 2:
    estado = actualizar_cliente;
    break;
  case 3:
    estado = actualizar_item;
    break;
  case 4:
    estado = actualizar_tipo_item;
    break;
  case 5:
    estado = menu_principal;
    break;
  default:
    cout << "opcion invalida" << endl;
    break;
  }
}

void interfaz_menu_borrar(int &estado) {
  int opcion;
  cout << " ----------------------------------------- " << endl
       << "|            ¿Qué desea borrar?           |" << endl
       << "| 1. Factura.                             |" << endl
       << "| 2. Cliente.                             |" << endl
       << "| 3. Item.                                |" << endl
       << "| 4. Tipo Item.                           |" << endl
       << "| 5. Regresar.                            |" << endl
       << " ----------------------------------------- " << endl;

  cin >> opcion;

  switch(opcion){
  case 1:
    estado = borrar_factura;
    break;
  case 2:
    estado = borrar_cliente;
    break;
  case 3:
    estado = borrar_item;
    break;
  case 4:
    estado = borrar_tipo_item;
    break;
  case 5:
    estado = menu_principal;
    break;
  default:
    cout << "opcion invalida" << endl;
    break;
  }
}

void interfaz_crear_cliente(int &estado) {
  int opcion;
  int id;
  string nombre;
  string apellido;
  string genero;
  string fecha_nacimiento;
  string estado_civil;
  
  cout << " ----------------------------------------- " << endl
       << "|    Ingresa el id del nuevo cliente      | " << endl
       << " ----------------------------------------- " << endl;

  cin >> id;
  
  cout << " ----------------------------------------- " << endl
       << "|           Ingresa su nombre             |" << endl
       << " ----------------------------------------- " << endl;

  cin >> nombre;

  cout << " ----------------------------------------- " << endl
       << "|           Ingresa su apellido           |" << endl
       << " ----------------------------------------- " << endl;

  cin >> apellido;

  cout << " ----------------------------------------- " << endl
       << "|       Ingresa su género (M o F)         |" << endl
       << " ----------------------------------------- " << endl;

  cin >> genero;


  cout << " ----------------------------------------- " << endl
       << "|Ingresa su fecha nacimiento (YYYY-MM-DD)|" << endl
       << " ----------------------------------------- " << endl;

  cin >> fecha_nacimiento;

  cout << " ----------------------------------------- " << endl
       << "|        Ingresa su estado civil          |" << endl
       << " ----------------------------------------- " << endl;

  cin >> estado_civil;

  Cliente* cliente = new Cliente(id, nombre, apellido, genero,
				 fecha_nacimiento, estado_civil);

  dc->insert(*cliente);

  cout << " ----------------------------------------- " << endl
       << "|    Cliente creado satisfactoriamente    | " << endl
       << " ----------------------------------------- " << endl;

  estado = menu_principal;
}


void interfaz_crear_factura(int &estado) {
  int opcion;
  int num_factura;
  string fecha_factura;
  int id_cliente;
  float total_factura;
  string estado_factura;
  list<int> id_items;

  cout << " ----------------------------------------- " << endl
       << "|  Ingresa el numero de la nueva factura  | " << endl
       << " ----------------------------------------- " << endl;

  cin >> num_factura;
  
  cout << " ----------------------------------------- " << endl
       << "| Ingresa la fecha de factura (YYYY-MM-DD)|" << endl
       << " ----------------------------------------- " << endl;

  cin >> fecha_factura;

  cout << " ----------------------------------------- " << endl
       << "|        Ingresa el id del cliente        |" << endl
       << " ----------------------------------------- " << endl;

  cin >> id_cliente;

  cout << " ----------------------------------------- " << endl
       << "|      Ingresa el valor de la factura     |" << endl
       << " ----------------------------------------- " << endl;

  cin >> total_factura;

  cout << " ----------------------------------------- " << endl
       << "|     Ingresa el estado de la factura     |" << endl
       << " ----------------------------------------- " << endl;

  cin >> estado_factura;

  do {
    cout << " ----------------------------------------- " << endl
	 << "|        Selecciona una opcion            |" << endl
	 << "| 1. Añadir item                          |" << endl
	 << "| 2. Terminar                             |" << endl  
	 << " ----------------------------------------- " << endl;

    cin >> opcion;
    
    switch(opcion) {
    case 1: {
      int id_item;
      cout << " ----------------------------------------- " << endl
	   << "|         Ingresa el id del item          |" << endl
	   << " ----------------------------------------- " << endl;

      cin >> id_item;
      id_items.push_back(id_item);
    } break;
    case 2:
      break;
    default:
    cout << "opcion inválida" << endl;
  }
  }while(opcion != 2);

  Factura* factura = new Factura(num_factura, fecha_factura, id_cliente,
				 total_factura, estado_factura, id_items);

  df->insert(*factura);

  cout << " ----------------------------------------- " << endl
       << "|     Factura creada satisfactoriamente   | " << endl
       << " ----------------------------------------- " << endl;

  estado = menu_principal;
}


void interfaz_crear_item(int &estado) {
  int opcion;
  string descripcion;
  int id;
  int id_tipo_item;
  float valor_unidad;

  cout << " ----------------------------------------- " << endl
       << "|      Ingresa el id del nuevo item       | " << endl
       << " ----------------------------------------- " << endl;

  cin >> id;
  
  cout << " ----------------------------------------- " << endl
       << "|         Describe el nuevo item          |" << endl
       << " ----------------------------------------- " << endl;

  cin >> descripcion;

  cout << " ----------------------------------------- " << endl
       << "|       Ingresa el id del tipo item       |" << endl
       << " ----------------------------------------- " << endl;

  cin >> id_tipo_item;

  cout << " ----------------------------------------- " << endl
       << "|      Ingresa el valor de la unidad      |" << endl
       << " ----------------------------------------- " << endl;

  cin >> valor_unidad;

  Item* item = new Item(id, descripcion, valor_unidad, id_tipo_item);

  di->insert(*item);

  cout << " ----------------------------------------- " << endl
       << "|      Item creado satisfactoriamente     | " << endl
       << " ----------------------------------------- " << endl;

  estado = menu_principal;
}


void interfaz_crear_tipo_item(int &estado) {
  int opcion;
  string descripcion;
  int id;

  cout << " ----------------------------------------- " << endl
       << "|  Ingresa el id del nuevo tipo de item   | " << endl
       << " ----------------------------------------- " << endl;

  cin >> id;
  
  cout << " ----------------------------------------- " << endl
       << "|    Describe el nuevo tipo de item       | " << endl
       << " ----------------------------------------- " << endl;

  cin >> descripcion;

  TipoItem* tipo_item = new TipoItem(id, descripcion);

  dti->insert(*tipo_item);

  cout << " ----------------------------------------- " << endl
       << "|  Tipo item creado satisfactoriamente    | " << endl
       << " ----------------------------------------- " << endl;

  estado = menu_principal;
}

void interfaz_leer_cliente(int &estado) {
  int opcion;
  cout << " ----------------------------------------- " << endl
       << "|            ¿Qué desea hacer?            |" << endl
       << "| 1. Mostrar un cliente                   |" << endl
       << "| 2. Mostrar todos los clientes           |" << endl
       << "| 3. Regresar.                            |" << endl
       << " ----------------------------------------- " << endl;

  cin >> opcion;


  switch(opcion){
  case 1: {
    int id;
    Cliente* cliente;
    
    cout << " ----------------------------------------- " << endl
	 << "|        Ingrese el id del cliente        | " << endl
	 << " ----------------------------------------- " << endl;
    cin >> id;

    cliente = dc->get(id);
    cliente->imprimir();
  }
    break;
    
  case 2: {
    map<int, Cliente*> clientes;
    clientes = dc->getAll();
    for(auto& cliente: clientes) {
      cliente.second->imprimir();
    }
  }
    break;
    
  case 3:
    estado = menu_principal;
    break;
  default:
    cout << "opcion invalida" << endl;
    break;
  }
}


void interfaz_leer_factura(int &estado) {
  int opcion;
  cout << " ----------------------------------------- " << endl
       << "|            ¿Qué desea hacer?            |" << endl
       << "| 1. Mostrar una factura                  |" << endl
       << "| 2. Mostrar todos las facturas           |" << endl
       << "| 3. Regresar.                            |" << endl
       << " ----------------------------------------- " << endl;

  cin >> opcion;


  switch(opcion){
  case 1: {
    int num_factura;
    Factura* factura;
    
    cout << " ----------------------------------------- " << endl
	 << "|     Ingrese el numero de la factura     | " << endl
	 << " ----------------------------------------- " << endl;
    cin >> num_factura;

    factura = df->get(num_factura);
    factura->imprimir();
  }
    break;
    
  case 2: {
    map<int, Factura*> facturas;
    facturas = df->getAll();
    for(auto& factura: facturas) {
      factura.second->imprimir();
    }
  }
    break;
    
  case 3:
    estado = menu_principal;
    break;
  default:
    cout << "opcion invalida" << endl;
    break;
  }
}


void interfaz_leer_item(int &estado) {
  int opcion;
  cout << " ----------------------------------------- " << endl
       << "|            ¿Qué desea hacer?            |" << endl
       << "| 1. Mostrar un item                      |" << endl
       << "| 2. Mostrar todos los items              |" << endl
       << "| 3. Regresar.                            |" << endl
       << " ----------------------------------------- " << endl;

  cin >> opcion;


  switch(opcion){
  case 1: {
    int id;
    Item* item;
    
    cout << " ----------------------------------------- " << endl
	 << "|         Ingrese el id del item          | " << endl
	 << " ----------------------------------------- " << endl;
    cin >> id;

    item = di->get(id);
    item->imprimir();
  }
    break;
    
  case 2: {
    map<int, Item*> items;
    items = di->getAll();
    for(auto& item: items) {
      item.second->imprimir();
    }
  }
    break;
    
  case 3:
    estado = menu_principal;
    break;
  default:
    cout << "opcion invalida" << endl;
    break;
  }
}


void interfaz_leer_tipo_item(int &estado) {
  int opcion;
  cout << " ----------------------------------------- " << endl
       << "|            ¿Qué desea hacer?            |" << endl
       << "| 1. Mostrar un tipo item                 |" << endl
       << "| 2. Mostrar todos los tipo item          |" << endl
       << "| 3. Regresar.                            |" << endl
       << " ----------------------------------------- " << endl;

  cin >> opcion;

  switch(opcion){
  case 1: {
    int id;
    TipoItem* tipo_item;
    
    cout << " ----------------------------------------- " << endl
	 << "|      Ingrese el id del tipo item        | " << endl
	 << " ----------------------------------------- " << endl;
    cin >> id;

    tipo_item = dti->get(id);
    tipo_item->imprimir();
  }
    break;
    
  case 2: {
    map<int, TipoItem*> tipo_items;
    tipo_items = dti->getAll();
    for(auto& tipo_item: tipo_items) {
      tipo_item.second->imprimir();
    }
  }
    break;
    
  case 3:
    estado = menu_principal;
    break;
  default:
    cout << "opcion invalida" << endl;
    break;
  }
}


void interfaz_actualizar_cliente(int &estado) {
  int id, opcion;
  Cliente* cliente;

  
  cout << " ----------------------------------------- " << endl
       << "|        Ingrese el id del item           | " << endl
       << " ----------------------------------------- " << endl;
  cin >> id;

  cliente = dc->get(id);
  cliente->imprimir();
  string nombre = cliente->get_nombre();
  string apellido = cliente->get_apellido();
  string genero = cliente->get_genero();
  string fecha_nacimiento = cliente->get_fecha_nacimiento();
  string estado_civil = cliente->get_estado_civil();
  
  do {
    
    cout << " ----------------------------------------- " << endl
	 << "|      ¿Qué campo desea actualizar?       |" << endl
	 << "| 1. Nombre                               |" << endl
	 << "| 2. Apellido                             |" << endl
	 << "| 3. Genero                               |" << endl
	 << "| 4. Fecha de Nacimiento                  |" << endl
	 << "| 5. Estado CIvil                         |" << endl
	 << "| 6. Confirmar                            |" << endl
	 << "| 7. Regresar                             |" << endl
	 << " ----------------------------------------- " << endl;
    cin >> opcion;

    switch(opcion) {
    case 1:
      cout << " ----------------------------------------- " << endl
	   << "|   Ingrese el nuevo nombre del cliente   | " << endl
	   << " ----------------------------------------- " << endl;
      cin >> nombre;
      
      break;
    case 2:
      cout << " ----------------------------------------- " << endl
	   << "|  Ingrese el nuevo apellido del cliente  | " << endl
	   << " ----------------------------------------- " << endl;
      cin >> apellido;
      break;
    case 3:
      cout << " ----------------------------------------- " << endl
	   << "|   Ingrese el nuevo género del cliente   | " << endl
	   << " ----------------------------------------- " << endl;
      cin >> genero;
      break;
    case 4:
      cout << " ----------------------------------------- " << endl
	   << "|   Ingrese la nueva fecha de nacimiento  | " << endl
	   << " ----------------------------------------- " << endl;
      cin >> fecha_nacimiento;
      break;
    case 5:
      cout << " ----------------------------------------- " << endl
	   << "|      Ingrese el nuevo estado civil      | " << endl
	   << " ----------------------------------------- " << endl;
      cin >> estado_civil;
      break;
    case 6:
      cliente = new Cliente(id, nombre, apellido, genero,
			    fecha_nacimiento, estado_civil);
      dc->update(*cliente);
      estado = menu_principal;
      break;
    case 7:
      estado = menu_principal;
      break;
    default:
      cout << "opcion invalida " << endl;
      break;
    }
  }while(estado != menu_principal);
}


void interfaz_actualizar_factura(int &estado) {
  int num_factura, opcion;
  Factura* factura;
  
  cout << " ----------------------------------------- " << endl
       << "|     Ingrese el numero de la factura     | " << endl
       << " ----------------------------------------- " << endl;
  cin >> num_factura;

  factura = df->get(num_factura);
  factura->imprimir();
  string fecha_factura = factura->get_fecha_factura();
  int id_cliente = factura->get_id_cliente();
  float total_factura = factura->get_total_factura();
  string estado_factura = factura->get_estado();
  list<int> id_items = factura->get_id_items();
  
  do {
    
    cout << " ----------------------------------------- " << endl
	 << "|      ¿Qué campo desea actualizar?       |" << endl
	 << "| 1. Fecha Factura                        |" << endl
	 << "| 2. Cliente                              |" << endl
	 << "| 3. Total Factura                        |" << endl
	 << "| 4. Total Factura                        |" << endl
	 << "| 5. Items                                |" << endl
	 << "| 6. Confirmar                            |" << endl
	 << "| 7. Regresar                             |" << endl
	 << " ----------------------------------------- " << endl;
    cin >> opcion;

    switch(opcion) {
    case 1:
      cout << " ----------------------------------------- " << endl
	   << "|   Ingrese la nueva fecha de factura     | " << endl
	   << " ----------------------------------------- " << endl;
      cin >> fecha_factura;

      break;
    case 2:
      cout << " ----------------------------------------- " << endl
	   << "|    Ingrese el nuevo id del cliente     | " << endl
	   << " ----------------------------------------- " << endl;
      cin >> id_cliente;

      break;
    case 3:
      cout << " ----------------------------------------- " << endl
	   << "|   Ingrese el nuevo total de factura     | " << endl
	   << " ----------------------------------------- " << endl;
      cin >> total_factura;
      break;
    case 4:
      cout << " ----------------------------------------- " << endl
	   << "|  Ingrese el nuevo estado de la factura  | " << endl
	   << " ----------------------------------------- " << endl;
      cin >> estado_factura;
      break;
    case 5: {
      int opcion_items;
      int id_item;
      id_items = list<int>();
      do {
	
	cout << " ----------------------------------------- " << endl
	     << "|            ¿Qué desea hacer?            |" << endl
	     << "| 1. Ingresar nuevo item                  |" << endl
	     << "| 2. Confirmar                            |" << endl
	     << " ----------------------------------------- " << endl;
	cin >> opcion_items;
	if (opcion_items == 1){
	  cout << " ----------------------------------------- " << endl
	       << "|          Ingresa el id del item         |" << endl
	       << " ----------------------------------------- " << endl;
	  cin >> id_item;
	  
	  id_items.push_back(id_item);
	  }
      }while(opcion_items != 2);
    } break;
      
    case 6:
      factura = new Factura(num_factura, fecha_factura, id_cliente,
			    total_factura, estado_factura, id_items);
      df->update(*factura);
      estado = menu_principal;
      break;
    case 7:
      estado = menu_principal;
      break;
    default:
      cout << "opcion invalida " << endl;
      break;
    }
  }while(estado != menu_principal);
}


void interfaz_actualizar_item(int &estado) {
  int id, opcion;
  Item* item;
  
  cout << " ----------------------------------------- " << endl
       << "|        Ingrese el id del item           | " << endl
       << " ----------------------------------------- " << endl;
  cin >> id;

  item = di->get(id);
  item->imprimir();
  string descripcion = item->get_descripcion();
  int id_tipo_item = item->get_id_tipo_item();
  float valor_unidad = item->get_valor_unidad();
  
  do {
    
    cout << " ----------------------------------------- " << endl
	 << "|      ¿Qué campo desea actualizar?       |" << endl
	 << "| 1. Tipo Item                            |" << endl
	 << "| 2. Descripcion                          |" << endl
	 << "| 3. Valor Unidad                         |" << endl
	 << "| 4. Confirmar                            |" << endl
	 << "| 5. Regresar                             |" << endl
	 << " ----------------------------------------- " << endl;
    cin >> opcion;

    switch(opcion) {
    case 1:
      cout << " ----------------------------------------- " << endl
	   << "|   Ingrese el id del nuevo tipo item     | " << endl
	   << " ----------------------------------------- " << endl;
      cin >> id_tipo_item;

      break;
    case 2:
      cout << " ----------------------------------------- " << endl
	   << "|      Ingrese la nueva descripcion       | " << endl
	   << " ----------------------------------------- " << endl;
      cin >> descripcion;
      break;
    case 3:
      cout << " ----------------------------------------- " << endl
	   << "|   Ingrese el nuevo valor de la unidad   | " << endl
	   << " ----------------------------------------- " << endl;
      cin >> valor_unidad;
      break;
    case 4:
      item = new Item(id, descripcion, valor_unidad, id_tipo_item);
      di->update(*item);
      estado = menu_principal;
      break;
    case 5:
      estado = menu_principal;
      break;
    default:
      cout << "opcion invalida " << endl;
      break;
    }
  }while(estado != menu_principal);
}


void interfaz_actualizar_tipo_item(int &estado) {
  int id, opcion;
  TipoItem* ti;
  
  cout << " ----------------------------------------- " << endl
       << "|      Ingrese el id del tipo item        | " << endl
       << " ----------------------------------------- " << endl;
  cin >> id;

  ti = dti->get(id);
  ti->imprimir();
  string descripcion = ti->get_descripcion(); 
  do {
    
    cout << " ----------------------------------------- " << endl
	 << "|      ¿Qué campo desea actualizar?       |" << endl
	 << "| 1. Descripcion                          |" << endl
	 << "| 2. Confirmar                            |" << endl
	 << "| 3. Regresar                             |" << endl
	 << " ----------------------------------------- " << endl;
    cin >> opcion;

    switch(opcion) {
    case 1:
      cout << " ----------------------------------------- " << endl
	   << "|      Ingrese la nueva descripcion       | " << endl
	   << " ----------------------------------------- " << endl;
      cin >> descripcion;
      break;
    case 2:
      ti = new TipoItem(id, descripcion);
      dti->update(*ti);
      estado = menu_principal;
      break;
    case 3:
      estado = menu_principal;
      break;
    default:
      cout << "opcion invalida" << endl;
      break;
    }
  }while(estado != menu_principal);
}


void interfaz_borrar_cliente(int &estado) {
  int opcion, id;
  Cliente* cliente;

  cout << " ----------------------------------------- " << endl
       << "|        Ingrese el id del cliente        | " << endl
       << " ----------------------------------------- " << endl;
  cin >> id;

  cliente = dc->get(id);
  cliente->imprimir();

  cout << " ----------------------------------------- " << endl
       << "|    ¿Está seguro que desea borrarlo      | " << endl
       << "| 1. No                                   | " << endl
       << "| 2. Sí                                   | " << endl
       << " ----------------------------------------- " << endl;
  cin >> opcion;

  switch(opcion) {
  case 1:
    estado = menu_principal;
    break;
  case 2:
    dc->erase(*cliente);
    delete cliente;
    estado = menu_principal;
    break;
  default:
    cout << "opcion inválida" << endl;
  }
}



void interfaz_borrar_factura(int &estado) {
  int opcion, num_factura;
  Factura* factura;

  cout << " ----------------------------------------- " << endl
       << "|    Ingrese el número de la factura      | " << endl
       << " ----------------------------------------- " << endl;
  cin >> num_factura;

  factura = df->get(num_factura);
  factura->imprimir();

  cout << " ----------------------------------------- " << endl
       << "|    ¿Está seguro que desea borrarlo      | " << endl
       << "| 1. No                                   | " << endl
       << "| 2. Sí                                   | " << endl
       << " ----------------------------------------- " << endl;
  cin >> opcion;

  switch(opcion) {
  case 1:
    estado = menu_principal;
    break;
  case 2:
    df->erase(*factura);
    delete factura;
    estado = menu_principal;
    break;
  default:
    cout << "opcion inválida" << endl;
  }
}


void interfaz_borrar_item(int &estado) {
  int opcion, id;
  Item* item;

  cout << " ----------------------------------------- " << endl
       << "|         Ingrese el id del item          | " << endl
       << " ----------------------------------------- " << endl;
  cin >> id;

  item = di->get(id);
  item->imprimir();

  cout << " ----------------------------------------- " << endl
       << "|    ¿Está seguro que desea borrarlo      | " << endl
       << "| 1. No                                   | " << endl
       << "| 2. Sí                                   | " << endl
       << " ----------------------------------------- " << endl;
  cin >> opcion;

  switch(opcion) {
  case 1:
    estado = menu_principal;
    break;
  case 2:
    di->erase(*item);
    delete item;
    estado = menu_principal;
    break;
  default:
    cout << "opcion inválida" << endl;
  }
}


void interfaz_borrar_tipo_item(int &estado) {
  int opcion, id;
  TipoItem* ti;

  cout << " ----------------------------------------- " << endl
       << "|      Ingrese el id del tipo item        | " << endl
       << " ----------------------------------------- " << endl;
  cin >> id;

  ti = dti->get(id);
  ti->imprimir();

  cout << " ----------------------------------------- " << endl
       << "|    ¿Está seguro que desea borrarlo      | " << endl
       << "| 1. No                                   | " << endl
       << "| 2. Sí                                   | " << endl
       << " ----------------------------------------- " << endl;
  cin >> opcion;

  switch(opcion) {
  case 1:
    estado = menu_principal;
    break;
  case 2:
    dti->erase(*ti);
    delete ti;
    estado = menu_principal;
    break;
  default:
    cout << "opcion inválida" << endl;
  }
}

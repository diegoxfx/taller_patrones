#include <dao_factura.h>
#include <database.h>
#include <sstream>

Dao<Factura>::Dao(): DaoBase<Factura>() {}

Dao<Factura>::~Dao() {}

map<int, Factura*> Dao<Factura>::getAll() {
  Factura* factura;
  int num_factura, id_cliente;
  string fecha_factura, estado;
  float total_factura;
  int item_id;
  list<int>* items_id;
  ostringstream sentence;
  ostringstream sentence2;
  sql::ResultSet *res;
  sql::ResultSet *res2;
  map<int, Factura*> facturas;
  
  sentence << "SELECT * FROM Factura;";
  res = DataBase::stmt->executeQuery(sentence.str());
  while(res->next()) {
    num_factura = res->getInt("num_factura");
    id_cliente = res->getInt("Cliente_id");
    fecha_factura = res->getString("fecha_factura");
    estado = res->getString("estado");
    total_factura = res->getDouble("total_factura");
    items_id = new list<int>();

    sentence2 << "SELECT * FROM Factura_has_Item "
	    << "WHERE Factura_num_factura = " << num_factura;
    res2 = DataBase::stmt->executeQuery(sentence2.str());

    while(res2->next()) {
      item_id = res2->getInt("Item_id");
      items_id->push_back(item_id);
    }
    
    factura = new Factura(num_factura, fecha_factura, id_cliente,
			   total_factura, estado, *items_id);
    facturas.insert(pair<int, Factura*>(num_factura, factura));
  }

  delete res;

  return facturas;
}

void Dao<Factura>::insert(Factura &factura) {
  ostringstream sentence;
  int num_factura = factura.get_num_factura();
  sentence << "INSERT INTO Factura(num_factura, fecha_factura, total_factura,"
	   << "estado, Cliente_id) "
	   << "VALUES("
	   << num_factura << ", '" << factura.get_fecha_factura() << "', "
	   << factura.get_total_factura() << ", '" << factura.get_estado() << "', "
	   << factura.get_id_cliente() << ");";

  DataBase::stmt->execute(sentence.str());

  for(auto& id_item: factura.get_id_items()) {
    ostringstream sentence2;
    sentence2 << "INSERT INTO Factura_has_Item(Factura_num_factura, Item_id)"
	      << "VALUES("
	      << num_factura << ", " << id_item << ");";
    DataBase::stmt->execute(sentence2.str());
  }
}

Factura* Dao<Factura>::get(int key) {
  Factura* factura;
  int num_factura, id_cliente;
  string fecha_factura, estado;
  float total_factura;
  int id_item;
  list<int> id_items;
  ostringstream sentence;
  ostringstream sentence2;
  sql::ResultSet *res;
  sql::ResultSet *res2;
  
  sentence << "SELECT * FROM Factura;";
  sentence2 << "SELECT Item_id FROM Factura_has_Item "
	    << "WHERE Factura_num_factura = " << num_factura;
  res = DataBase::stmt->executeQuery(sentence.str());
  num_factura = res->getInt("num_factura");
  id_cliente = res->getInt("Cliente_id");
  fecha_factura = res->getString("fecha_factura");
  estado = res->getString("estado");
  total_factura = res->getDouble("total_factura");

  sentence2 << "SELECT Item_id FROM Factura_has_Item "
	    << "WHERE Factura_num_factura = " << num_factura;
  res2 = DataBase::stmt->executeQuery(sentence2.str());

  while(res2->next()) {
    id_item = res2->getInt("Item_id");
    id_items.push_back(id_item);
  }
    

  delete res;

  return new Factura(num_factura, fecha_factura, id_cliente,
		     total_factura, estado, id_items);;
}

void Dao<Factura>::update(Factura &factura) {
  ostringstream sentence;
  ostringstream sentence2;
  ostringstream sentence3;

  int num_factura = factura.get_num_factura();
  sentence << "UPDATE Factura "
	   << "SET "
	   << "fecha_factura = '" << factura.get_fecha_factura() << "', "
	   << "total_factura = " << factura.get_total_factura() << ", "
	   << "estado = " << factura.get_estado() << ", "
	   << "Cliente_id = " << factura.get_id_cliente() << ", "
	   << "WHERE id = " << num_factura << ";";

  sentence2 << "DELETE FROM Factura_has_Item "
	   << "WHERE id = " << num_factura << ";";

  DataBase::stmt->execute(sentence2.str());
  
  for(auto& item_id: factura.get_id_items()) {
    sentence3 << "INSERT INTO Factura_has_Item(Factura_num_factura, Item_id)"
	      << "VALUES("
	      << num_factura << ", " << item_id << ");";
    DataBase::stmt->execute(sentence3.str());
  }

  DataBase::stmt->execute(sentence.str());
}

void Dao<Factura>::erase(Factura &factura) {
  ostringstream sentence;
  ostringstream sentence2;
  int num_factura = factura.get_num_factura();
  
  sentence2 << "DELETE FROM Factura_has_Item "
	   << "WHERE id = " << num_factura << ";";

  DataBase::stmt->execute(sentence2.str());
  
  sentence << "DELETE FROM Factura "
	   << "WHERE id = " << factura.get_num_factura() << ";";

  DataBase::stmt->execute(sentence.str());
}

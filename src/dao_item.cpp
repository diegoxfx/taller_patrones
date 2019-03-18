#include <dao_item.h>
#include <database.h>
#include <sstream>

Dao<Item>::Dao(): DaoBase<Item>() {}

Dao<Item>::~Dao() {}

map<int, Item*> Dao<Item>::getAll() {
  Item* item;
  int id, id_tipo_item;
  string descripcion;
  float valor_unidad;
  ostringstream sentence;
  sql::ResultSet *res;
  map<int, Item*> items;
  
  sentence << "SELECT * FROM Item;";
  res = DataBase::stmt->executeQuery(sentence.str());
  while(res->next()) {
    id = res->getInt("id");
    descripcion = res->getString("descripcion");
    valor_unidad = res->getDouble("valor_unidad");
    id_tipo_item = res->getInt("TipoItem_id");
    item = new Item(id, descripcion, valor_unidad, id_tipo_item);
    items.insert(pair<int, Item*>(id, item));
  }

  delete res;

  return items;
}

void Dao<Item>::insert(Item &item) {
  ostringstream sentence;
  sentence << "INSERT INTO Item(id, descripcion, valor_unidad, TipoItem_id) "
	   << "VALUES("
	   << item.get_id() << ", '" << item.get_descripcion() << "', "
	   << item.get_valor_unidad() << ", " << item.get_id_tipo_item() << ");";

  DataBase::stmt->execute(sentence.str());
}

Item* Dao<Item>::get(int key) {
  int id, id_tipo_item;
  string descripcion;
  float valor_unidad;
  ostringstream sentence;
  sql::ResultSet *res;
  sentence << "SELECT * FROM Item "
	   << "WHERE id = " << key << ";";
  res = DataBase::stmt->executeQuery(sentence.str());
  res->next();
  
  id = res->getInt("id");
  descripcion = res->getString("descripcion");
  valor_unidad = res->getDouble("valor_unidad");
  id_tipo_item = res->getInt("TipoItem_id");

  delete res;

  return new Item(id, descripcion, valor_unidad, id_tipo_item);
}

void Dao<Item>::update(Item &item) {
  ostringstream sentence;
  sentence << "UPDATE Item "
	   << "SET "
	   << "descripcion = '" << item.get_descripcion() << "', "
	   << "valor_unidad = " << item.get_valor_unidad() << ", "
	   << "TipoItem_id = " << item.get_id_tipo_item() << " "
	   << "WHERE id = " << item.get_id() << ";";

  DataBase::stmt->execute(sentence.str());
}

void Dao<Item>::erase(Item &item) {
  ostringstream sentence;
  sentence << "DELETE FROM Item "
	   << "WHERE id = " << item.get_id() << ";";

  DataBase::stmt->execute(sentence.str());
}

#include <dao_tipo_item.h>
#include <database.h>
#include <sstream>

Dao<TipoItem>::Dao(): DaoBase<TipoItem>() {}

Dao<TipoItem>::~Dao() {}

map<int, TipoItem*> Dao<TipoItem>::getAll() {
  TipoItem* ti;
  int id;
  string descripcion;
  ostringstream sentence;
  sql::ResultSet *res;
  map<int, TipoItem*> tipo_items;
  
  sentence << "SELECT * FROM TipoItem;";
  res = DataBase::stmt->executeQuery(sentence.str());
  while(res->next()) {
    id = res->getInt("id");
    descripcion = res->getString("descripcion");
    ti = new TipoItem(id, descripcion);
    tipo_items.insert(pair<int, TipoItem*>(id, ti));
  }

  delete res;

  return tipo_items;
}

void Dao<TipoItem>::insert(TipoItem &ti) {
  ostringstream sentence;
  sentence << "INSERT INTO TipoItem(id, descripcion) "
	   << "VALUES("
	   << ti.get_id() << ", '" << ti.get_descripcion() << "');";

  DataBase::stmt->execute(sentence.str());
}

TipoItem* Dao<TipoItem>::get(int key) {
  int id;
  string descripcion;
  ostringstream sentence;
  sql::ResultSet *res;
  sentence << "SELECT * FROM TipoItem "
	   << "WHERE id = " << key << ";";
  res = DataBase::stmt->executeQuery(sentence.str());
  res->next();

  id = res->getInt("id");
  descripcion = res->getString("descripcion");

  delete res;

  return new TipoItem(id, descripcion);
}

void Dao<TipoItem>::update(TipoItem &ti) {
  ostringstream sentence;
  sentence << "UPDATE TipoItem "
	   << "SET descripcion = '" << ti.get_descripcion() << "' "
	   << "WHERE id = " << ti.get_id() << ";";

  DataBase::stmt->execute(sentence.str());
}

void Dao<TipoItem>::erase(TipoItem &ti) {
  ostringstream sentence;
  sentence << "DELETE FROM TipoItem "
	   << "WHERE id = " << ti.get_id() << ";";

  DataBase::stmt->execute(sentence.str());
}

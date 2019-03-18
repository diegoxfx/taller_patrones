#include <dao_cliente.h>
#include <database.h>
#include <sstream>

Dao<Cliente>::Dao(): DaoBase<Cliente>() {}

Dao<Cliente>::~Dao() {}

map<int, Cliente*> Dao<Cliente>::getAll() {
  Cliente* cliente;
  int id;
  string nombre, apellido, fecha_nacimiento, estado_civil;
  string genero;
  ostringstream sentence;
  sql::ResultSet *res;
  map<int, Cliente*> clientes;
  
  sentence << "SELECT * FROM Cliente;";
  res = DataBase::stmt->executeQuery(sentence.str());
  while(res->next()) {
    id = res->getInt("id");
    nombre = res->getString("nombre");
    apellido = res->getString("apellido");
    genero = res->getString("genero");
    fecha_nacimiento = res->getString("fecha_nacimiento");
    estado_civil = res->getString("estado_civil");
    cliente = new Cliente(id, nombre, apellido, genero,
			fecha_nacimiento, estado_civil);
    clientes.insert(pair<int, Cliente*>(id, cliente));
  }

  delete res;

  return clientes;
}

void Dao<Cliente>::insert(Cliente &cliente) {
  ostringstream sentence;
  sentence << "INSERT INTO Cliente(id, nombre, apellido, genero, "
	   << "fecha_nacimiento, estado_civil) "
	   << "VALUES("
	   << cliente.get_id() << ", '" << cliente.get_nombre() << "', '"
	   << cliente.get_apellido() << "', '" << cliente.get_genero() << "', '"
	   << cliente.get_fecha_nacimiento() << "', '"
	   << cliente.get_estado_civil() << "');";

  DataBase::stmt->execute(sentence.str());
}

Cliente* Dao<Cliente>::get(int key) {
  int id;
  string nombre, apellido, fecha_nacimiento, estado_civil, genero;
  ostringstream sentence;
  sql::ResultSet *res;
  
  sentence << "SELECT * FROM Cliente "
	   << "WHERE id = " << key << ";";
  res = DataBase::stmt->executeQuery(sentence.str());
  res->next();

  id = res->getInt("id");
  nombre = res->getString("nombre");
  apellido = res->getString("apellido");
  genero = res->getString("genero");
  fecha_nacimiento = res->getString("fecha_nacimiento");
  estado_civil = res->getString("estado_civil");

  delete res;

  return new Cliente(id, nombre, apellido, genero,
		     fecha_nacimiento, estado_civil);
}

void Dao<Cliente>::update(Cliente &cliente) {
  ostringstream sentence;
  sentence << "UPDATE Cliente "
	   << "SET "
	   << "nombre = '" << cliente.get_nombre() << "', "
	   << "apellido = '" << cliente.get_apellido() << "', "
	   << "genero = '" << cliente.get_genero() << "', "
	   << "fecha_nacimiento = '" << cliente.get_fecha_nacimiento() << "', "
	   << "estado_civil = '" << cliente.get_estado_civil() << "', "
	   << "WHERE id = " << cliente.get_id() << ";";

  DataBase::stmt->execute(sentence.str());
}

void Dao<Cliente>::erase(Cliente &cliente) {
  ostringstream sentence;
  sentence << "DELETE FROM Cliente "
	   << "WHERE id = " << cliente.get_id() << ";";

  DataBase::stmt->execute(sentence.str());

}

#pragma once
//#include "boost/date_time/gregorian/gregorian.hpp"
#include <string>

using namespace std;
//using namespace boost::gregorian;

class Cliente {
 public:
  Cliente();
  Cliente(int id, string nombre, string apellido, string genero,
	  string fecha_nacimiento, string estado_civil );
  ~Cliente();
  int get_id();
  string get_nombre();
  string get_apellido();
  string get_genero();
  string get_fecha_nacimiento();
  string get_estado_civil();
  void imprimir();

 private:
  int id;
  string nombre, apellido, estado_civil, fecha_nacimiento, genero;
};

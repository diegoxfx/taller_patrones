#include <cliente.h>
#include <iostream>

Cliente::Cliente(){};

Cliente::Cliente(int id, string nombre, string apellido, string genero,
	  string fecha_nacimiento, string estado_civil ) {
  this->id = id;
  this->nombre = nombre;
  this->apellido = apellido;
  this->genero = genero;
  this->fecha_nacimiento = fecha_nacimiento;
  this->estado_civil = estado_civil;
}

Cliente::~Cliente(){}

int Cliente::get_id() { return this->id;}
string Cliente::get_nombre() { return this->nombre;}
string Cliente::get_apellido() { return this->apellido;}
string Cliente::get_genero() { return this->genero;}
string Cliente::get_fecha_nacimiento() { return this->fecha_nacimiento; }
string Cliente::get_estado_civil() { return this->estado_civil;}

void Cliente::imprimir() {
  cout << "id: " << this->id << " "
       << "nombre: " << this->nombre << " "
       << "apellido: " << this->apellido << " "
       << "genero: " << this->genero << " "
       << "fecha de nacimiento: " << this->fecha_nacimiento << " "
       << "estado civil: " << this->estado_civil << endl; 
}

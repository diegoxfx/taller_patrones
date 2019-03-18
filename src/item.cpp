#include <item.h>
#include <iostream>

Item::Item(){}

Item::Item(int id, string descripcion,
	   float valor_unidad, int id_tipo_item) {
  this->id_tipo_item = id_tipo_item;
  this->id = id;
  this->descripcion = descripcion;
  this->valor_unidad = valor_unidad;
}

Item::~Item(){}

int Item::get_id_tipo_item() { return this->id_tipo_item; }
int Item::get_id() { return this->id; }
string Item::get_descripcion() { return this->descripcion; }
float Item::get_valor_unidad() { return this->valor_unidad; }

void Item::imprimir() {
 cout << "Id: " << this->id << " "
       << "Tipo Item Id:" << this->id << " "
       << "valor unidad: " << this->valor_unidad << " "
       << "Descripcion: " << this->descripcion << endl;
}

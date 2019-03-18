#include <tipo_item.h>
#include <iostream>

TipoItem::TipoItem(){}

TipoItem::TipoItem(int id, string descripcion) {
  this->id = id;
  this->descripcion = descripcion;
}

TipoItem::~TipoItem() {}

int TipoItem::get_id() { return this->id; }
string TipoItem::get_descripcion() { return this->descripcion; }

void TipoItem::imprimir() {
  cout << "Id: " << this->id << " "
       << "Descripcion: " << this->descripcion << endl;
}

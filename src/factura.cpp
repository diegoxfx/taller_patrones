#include <factura.h>
#include <iostream>

Factura::Factura(){}

Factura::Factura(int num_factura, string fecha_factura, int id_cliente,
		 float total_factura, string estado, list<int> id_items) {
  this->num_factura = num_factura;
  this->fecha_factura = fecha_factura;
  this->id_cliente = id_cliente;
  this->total_factura = total_factura;
  this->estado = estado;
  this->id_items = id_items;
}

Factura::~Factura(){}

int Factura::get_num_factura(){ return this->num_factura; }
string Factura::get_fecha_factura() { return this->fecha_factura; }
int Factura::get_id_cliente() { return this->id_cliente; }
float Factura::get_total_factura() { return this->total_factura; }
string Factura::get_estado() { return this->estado; }
list<int> Factura::get_id_items() { return this->id_items; }

void Factura::imprimir() {
  cout << "número de factura: " << this->num_factura << " "
       << "fecha: " << this->fecha_factura << " "
       << "id del cliente: " << this->id_cliente << " "
       << "total: " << this->total_factura << " "
       << "estado: " << this->estado << " "
       << "id items: ";

  for(auto& id_item: this->id_items) {
    cout << id_item << " ";
  }
  cout << endl;
}

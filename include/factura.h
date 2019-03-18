#pragma once
#include <string>
#include <list>
#include <cliente.h>
#include <item.h>

using namespace std;

class Factura {
 public:
  Factura();
  Factura(int num_factura, string fecha_factura, int id_cliente,
	  float total_factura, string estado, list<int> id_items);
  ~Factura();

  int get_num_factura();
  string get_fecha_factura();
  int get_id_cliente();
  float get_total_factura();
  string get_estado();
  list<int> get_id_items();
  void imprimir();

 private:
  int num_factura;
  string fecha_factura;
  int id_cliente;
  float total_factura;
  string estado;
  list<int> id_items;
};

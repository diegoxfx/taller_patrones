#pragma once
#include <string>

using namespace std;

class Item {
 public:
  Item();
  Item(int id, string descripcion,
       float valor_unidad, int id_tipo_item);
  ~Item();

  int get_id();
  string get_descripcion();
  float get_valor_unidad();
  int get_id_tipo_item();
  void imprimir();

 private:
  int id;
  string descripcion;
  float valor_unidad;
  int id_tipo_item;
};

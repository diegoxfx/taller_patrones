#pragma once
#include <string>

using namespace std;

class TipoItem {
 public:
  TipoItem();
  TipoItem(int id, string descripcion);
  ~TipoItem();

  int get_id();
  string get_descripcion();
  void imprimir();

 private:
  int id;
  string descripcion;
};

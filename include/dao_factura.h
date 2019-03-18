#pragma once
#include <dao.h>
#include <factura.h>

template <> class Dao<Factura>: public DaoBase<Factura> {
 public:
  Dao();
  ~Dao();

  virtual map<int, Factura*> getAll();
  virtual void insert(Factura &ti);
  virtual Factura* get(int key);
  virtual void update(Factura &factura);
  virtual void erase(Factura &factura);
};

#pragma once
#include <dao.h>
#include <cliente.h>

template <> class Dao<Cliente>: public DaoBase<Cliente> {
 public:
  Dao();
  ~Dao();

  virtual map<int, Cliente*> getAll();
  virtual void insert(Cliente &ti);
  virtual Cliente* get(int key);
  virtual void update(Cliente &cliente);
  virtual void erase(Cliente &cliente);
};

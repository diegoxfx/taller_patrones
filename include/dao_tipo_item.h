#pragma once
#include <dao.h>
#include <tipo_item.h>

template <> class Dao<TipoItem>: public DaoBase<TipoItem> {
 public:
  Dao();
  ~Dao();

  virtual map<int, TipoItem*> getAll();
  virtual void insert(TipoItem &ti);
  virtual TipoItem* get(int key);
  virtual void update(TipoItem &ti);
  virtual void erase(TipoItem &ti);
};


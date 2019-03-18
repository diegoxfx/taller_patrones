#pragma once
#include <dao.h>
#include <item.h>

template <> class Dao<Item>: public DaoBase<Item> {
 public:
  Dao();
  ~Dao();

  virtual map<int, Item*> getAll();
  virtual void insert(Item &ti);
  virtual Item* get(int key);
  virtual void update(Item &item);
  virtual void erase(Item &item);
};

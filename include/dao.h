#pragma once
#include <map>
#include <cppconn/resultset.h>
using namespace std;

template <class T> class DaoBase {
 public:
  DaoBase(){};
  ~DaoBase() {};

  virtual map<int, T* > getAll() = 0;
  virtual void insert(T &t) = 0;
  virtual T* get(int key) = 0;
  virtual void update(T &t) = 0;
  virtual void erase(T &t) = 0;

 protected:
  map<int, T*> objects;
};

template <class T> class Dao: public DaoBase<T> {
 public:
  Dao(){};
  ~Dao() {};
};

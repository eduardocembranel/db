#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "Table.hpp"
#include "Serializable.hpp"
#include <vector>


class Database {
   private:
      std::vector<Table *> tabelas;

   public:
      Database ();
      void addTable (Table *);
      Table *getTable (const std::string &);
};

#endif // !DATABASE_HPP
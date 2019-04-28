#include "Database.hpp"

Database::Database () {

}

void Database::addTable (Table *tabela) {
   tabelas.push_back(tabela);
}

Table *Database::getTable (const std::string &nome) {
   for (int i = 0; i < tabelas.size(); ++i) {
      Table *atual = tabelas[i];
      if (atual->getNome() == nome) {
         return atual;
      }
   }
   return nullptr;
}
#ifndef TABLE_HPP
#define TABLE_HPP

#include "ArquivoIndice.hpp"
#include "ArquivoDados.hpp"
#include "Serializable.hpp"
#include <vector>

class Table {
   private:
      ArquivoIndice *arqIndices;
      ArquivoDados *arqDados;
      std::string nome;

   public:
      Table (const std::string tableName) {
         nome = tableName;
         arqIndices = new ArquivoIndice(tableName + "Indices.bin");
         arqDados = new ArquivoDados(tableName + "Dados.bin"); 
      }

      void* selectByKey (int key, Serializable *elem) {
         int indice = arqIndices->getIndice(key);
         if (indice == -1 ) {
            return nullptr;
         }
         return arqDados->getData(indice, elem);
      }

      std::vector<void *> selectAll (Serializable *elem) {
         return arqDados->getAllData(elem);
      }

      int getNextId () {
		   return arqIndices->getCab()->getKeyCount();
	   }
	
	   std::string getNome () {
		   return nome;
	   }
};

#endif // !TABLE_HPP
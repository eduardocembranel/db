#ifndef ARQUIVODADOS_HPP
#define ARQUIVODADOS_HPP

#include "Arquivo.hpp"
#include "Serializable.hpp"
#include "CabecalhoDados.hpp"
#include "DisciplinaProfessor.hpp"
#include <iostream>

#include <vector>

class ArquivoDados : public Arquivo {
   private:
      CabecalhoDados *cab;

   public:
      ArquivoDados (const std::string &filePath) : Arquivo(filePath) {
         cab = new CabecalhoDados(in);
      }

      void* getData (int index, Serializable *elem) {
         int offset = cab->sizeOfMe() + index * elem->sizeOfMe();
         return elem->deserialize(in, offset);
	   }

	   bool existe (Serializable *elem) {
         return true;
	   }

      std::vector<void *> getAllData (Serializable *elem) {
         int offset = cab->sizeOfMe();
         std::vector<void *> elems;
         for (int i = 0; i < cab->getPosTopo(); ++i) {
            void *it = elem->deserialize(in, offset);
            DisciplinaProfessor *teste = (DisciplinaProfessor *)it;
            elems.push_back(it);
            offset += elem->sizeOfMe();
         }
         return elems;
      }
};

#endif // !ARQUIVODADOS_HPP
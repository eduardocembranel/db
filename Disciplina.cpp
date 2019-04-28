#include "Disciplina.hpp"
#include "utils.h"
#include <iostream>

Disciplina::Disciplina () {

}

Disciplina::Disciplina (int id, const std::string &nome) {
   this->id = id;
   this->nome = nome;
}

std::string Disciplina::getNome () const {
   return nome;
}

void Disciplina::setNome (const std::string &nome) {
   this->nome = nome;
}

int Disciplina::getId () const {
   return id;
}

int Disciplina::sizeOfMe () {
   return 104;
}

void Disciplina::serialize (std::ofstream &file, int offset) {

}

void* Disciplina::deserialize (std::ifstream &file, int offset) {
   file.seekg(offset);
   char buffer[4];
   file.read(buffer, 4);
   int id = javaByteArrayToInt(buffer);
   char temp[50];
   int i;
   for (i = 0; i < 50; ++i) {
      file.read(buffer, 2);
      temp[i] = javaByteArrayToChar(buffer);
      if (temp[i] == '\0') {
         break;
      }
   }     
   char *temp2 = new char[i];
   for (int j = 0; j < i; ++j) {
      temp2[j] = temp[j];
   }
   
   std::string nome(temp2);
   return new Disciplina(id, nome);
}

#include "Professor.hpp"
#include "utils.h"
#include <iostream>

Professor::Professor () {

}

Professor::Professor (int id, const std::string &nome) {
   this->id = id;
   this->nome = nome;
}

std::string Professor::getNome () const {
   return nome;
}

int Professor::getId () const {
   return id;
}

int Professor::sizeOfMe () {
   return 144;
}

void Professor::serialize (std::ofstream &file, int offset) {

}

void* Professor::deserialize (std::ifstream &file, int offset) {
   file.seekg(offset);
   char buffer[4];
   file.read(buffer, 4);
   int id = javaByteArrayToInt(buffer);
   char temp[70];
   int i;
   for (i = 0; i < 70; ++i) {
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
   return new Professor(id, nome);
}
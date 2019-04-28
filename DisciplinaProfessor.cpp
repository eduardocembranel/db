#include "DisciplinaProfessor.hpp"
#include "utils.h"
#include <iostream>

DisciplinaProfessor::DisciplinaProfessor () {

}

DisciplinaProfessor::DisciplinaProfessor (int id, int idProfessor, 
  int idDisciplina, int anoLetivo, const std::string &data) {
     this->id = id;
     this->idProfessor = idProfessor;
     this->idDisciplina = idDisciplina;
     this->anoLetivo = anoLetivo;
     this->dataInicio = data;
}

int DisciplinaProfessor::getIdProfessor () const {
   return idProfessor;
}

void DisciplinaProfessor::setIdProfessor (int id) {
   idProfessor = id;
}

int DisciplinaProfessor::getIdDisciplina () const {
   return idDisciplina;
}

void DisciplinaProfessor::setIdDisciplina (int id) {
   idDisciplina = id;
}

int DisciplinaProfessor::getAnoLetivo () const {
   return anoLetivo;
}

void DisciplinaProfessor::setAnoLetivo (int ano) {
   anoLetivo = ano;
}

std::string DisciplinaProfessor::getDataInicio () const {
   return dataInicio;
}

void DisciplinaProfessor::setDataInicio (const std::string &data) {
   dataInicio = data;
}

int DisciplinaProfessor::getId () const {
   return id;
}

int DisciplinaProfessor::sizeOfMe () {
   return 38;
}

void DisciplinaProfessor::serialize (std::ofstream &file, int offset) {

}

void* DisciplinaProfessor::deserialize (std::ifstream &file, int offset) {
   file.seekg(offset);
   char buffer[4];
   file.read(buffer, 4);
   int id = javaByteArrayToInt(buffer);
   file.read(buffer, 4);
   int idProfessor = javaByteArrayToInt(buffer);
   file.read(buffer, 4);
   int idDisciplina = javaByteArrayToInt(buffer);
   file.read(buffer, 4);
   int anoLetivo = javaByteArrayToInt(buffer);

   char *dataTmp = new char[11];
   for (int i = 0; i < 11; ++i) {
      file.read(buffer, 2);
      dataTmp[i] = javaByteArrayToChar(buffer);
   }
   std::string data(dataTmp);	
   return new DisciplinaProfessor(id, idProfessor, idDisciplina, anoLetivo, data);
}
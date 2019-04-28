#include "CabecalhoDados.hpp"
#include "utils.h"

CabecalhoDados::CabecalhoDados () {

}

CabecalhoDados::CabecalhoDados (std::ifstream &file) {
   posTopo = *((int *) deserialize(file, 0));
}

int CabecalhoDados::getPosTopo () const {
   return posTopo;
}

void CabecalhoDados::incTopo () {
   ++posTopo;
}

int CabecalhoDados::sizeOfMe () {
   return 4;
}

void CabecalhoDados::serialize (std::ofstream &file, int offset) {

}

void* CabecalhoDados::deserialize (std::ifstream &file, int offset) {
   file.seekg(offset);
   char buffer[4];
   file.read(buffer, 4);
   int i = javaByteArrayToInt(buffer);
   return intToVoidPointer(i);
}

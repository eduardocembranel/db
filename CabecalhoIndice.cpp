#include "CabecalhoIndice.hpp"
#include "utils.h"
#include <iostream>

CabecalhoIndice::CabecalhoIndice (std::ifstream &file) {
   CabecalhoIndice cab = *((CabecalhoIndice *) deserialize(file, 0));
   posRaiz = cab.getPosRaiz();
   posTopo = cab.getPosTopo();
   keyCount = cab.getKeyCount();
}

CabecalhoIndice::CabecalhoIndice () {

}

void CabecalhoIndice::setPosTopo (int pos) {
   posTopo = pos;
}

void CabecalhoIndice::setPosRaiz (int pos) {
   posRaiz = pos;
}

void CabecalhoIndice::setKeyCount (int keyCount) {
   this->keyCount = keyCount;
}

int CabecalhoIndice::getKeyCount () const {
   return keyCount;
}

int CabecalhoIndice::getPosRaiz () const {
   return posRaiz;
}

int CabecalhoIndice::getPosTopo () const {
   return posTopo;
}

int CabecalhoIndice::sizeOfMe () {
   return 12;
}

void CabecalhoIndice::serialize (std::ofstream &file, int offset) {

}

void* CabecalhoIndice::deserialize (std::ifstream &file, int offset) {
   file.seekg(offset);
   char buffer[4];
   file.read(buffer, 4);
   int posRaiz = javaByteArrayToInt(buffer);
   file.read(buffer, 4);
   int posTopo = javaByteArrayToInt(buffer);
   file.read(buffer, 4);
   int keyCount = javaByteArrayToInt(buffer);
   CabecalhoIndice *cab = new CabecalhoIndice();
   cab->setPosRaiz(posRaiz);
   cab->setPosTopo(posTopo);
   cab->setKeyCount(keyCount);
   return cab;
}

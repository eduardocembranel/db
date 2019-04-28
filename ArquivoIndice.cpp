#include "ArquivoIndice.hpp"

#include "BTreeNode.hpp"
#include <iostream>

ArquivoIndice::ArquivoIndice (const std::string &filePath) : Arquivo(filePath) {
   cab = new CabecalhoIndice(in);
}

CabecalhoIndice* ArquivoIndice::getCab () const {
   return cab;
}

int ArquivoIndice::getIndice (int chave) {
   if (cab->getPosRaiz() == -1) {
      return -1;
   }
   return getIndiceAux(chave, cab->getPosRaiz());
}

int ArquivoIndice::getIndiceAux (int chave, int pos) {
   if (pos == -1) {
	   return -1;
	}
   BTreeNode *no = BTreeNode::getNode(in, pos);

   int i = 0;
   while (i < no->numChaves && chave > no->chaves[i])
      ++i;
   
   if (i < no->numChaves && chave == no->chaves[i]) {
      return no->indices[i];
   }
   return getIndiceAux(chave, no->filhos[i]);
}

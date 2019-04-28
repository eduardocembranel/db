#include "BTreeNode.hpp"
#include "utils.h"

BTreeNode::BTreeNode (int chave, int indice) {
   chaves[0] = chave;
   indices[0] = indice;
   for (int i = 0; i < ORDEM + 1; ++i) {
      filhos[i] = -1;
   } 
   numChaves = 1;
}

BTreeNode::BTreeNode () {
   for (int i = 0; i < ORDEM + 1; ++i) {
      filhos[i] = -1;
   }
	numChaves = 0;
}

BTreeNode* BTreeNode::getNode (std::ifstream &file, int pos) {
   BTreeNode node;
   int offset = 12 + pos * node.sizeOfMe();
   return (BTreeNode *)node.deserialize(file, offset);
}

int BTreeNode::sizeOfMe () {
   return 76;
}

void BTreeNode::serialize (std::ofstream &file, int offset) {

}

void* BTreeNode::deserialize (std::ifstream &file, int offset) {
   BTreeNode *novo = new BTreeNode();
   file.seekg(offset);
   char buffer[4];
   file.read(buffer, 4);
   novo->numChaves = javaByteArrayToInt(buffer);
   for (int i = 0; i < ORDEM; ++i) {
      file.read(buffer, 4);
      novo->chaves[i] = javaByteArrayToInt(buffer);
   }
   for (int i = 0; i < ORDEM + 1; ++i) {
      file.read(buffer, 4);
      novo->filhos[i] = javaByteArrayToInt(buffer);
   }
   for (int i = 0; i < ORDEM; ++i) {
      file.read(buffer, 4);
      novo->indices[i] = javaByteArrayToInt(buffer);
   }
   return novo;
}

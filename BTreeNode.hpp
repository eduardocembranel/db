#ifndef BTREENODE_HPP
#define BTREENODE_HPP

#include "Serializable.hpp"
#include <fstream>

class BTreeNode : public Serializable {
   private:
      static const int ORDEM = 5;
      static const int MINIMO = 2;
      
   public:
      int numChaves;
      int chaves[ORDEM];
      int filhos[ORDEM + 1];
      int indices[ORDEM];

      BTreeNode (int, int);
      BTreeNode ();
      static BTreeNode* getNode (std::ifstream &, int);
      int sizeOfMe ();
      void serialize (std::ofstream &file, int offset);
      void* deserialize (std::ifstream &file, int offset);
};

#endif // !BTREENODE_HPP
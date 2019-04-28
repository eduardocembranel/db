#ifndef CABECALHOINDICE_HPP
#define CABECALHOINDICE_HPP

#include <fstream>
#include "Serializable.hpp"

class CabecalhoIndice : public Serializable {
   private:
      int posRaiz;
      int posTopo;
      int keyCount;

   public:
      CabecalhoIndice (std::ifstream &);
      CabecalhoIndice ();
      void setPosTopo (int);
      void setPosRaiz (int);
      void setKeyCount (int);
      int getKeyCount () const;
      int getPosRaiz () const;
      int getPosTopo () const;
      
      int sizeOfMe ();
      void serialize (std::ofstream &file, int offset);
      void* deserialize (std::ifstream &file, int offset);
};

#endif // !CABECALHOINDICE_HPP
#ifndef CABECALHODADOS_HPP
#define CABECALHODADOS_HPP

#include "Serializable.hpp"

class CabecalhoDados : public Serializable {
   private:
      int posTopo;

   public:
      CabecalhoDados ();
      CabecalhoDados (std::ifstream &);
      int getPosTopo () const;
      void incTopo ();
      int sizeOfMe ();
      void serialize (std::ofstream &file, int offset);
      void* deserialize (std::ifstream &file, int offset);
};

#endif // !CABECALHODADOS_HPP
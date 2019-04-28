#ifndef ARQUIVOINDICE_HPP
#define ARQUIVOINDICE_HPP

#include "CabecalhoIndice.hpp"
#include "Arquivo.hpp"

class ArquivoIndice : public Arquivo {
   private:
      CabecalhoIndice *cab;
   
   public:
      ArquivoIndice (const std::string &);
      CabecalhoIndice* getCab () const;
      int getIndice (int);
      int getIndiceAux (int, int);

};

#endif // !ARQUIVOINDICE_HPP

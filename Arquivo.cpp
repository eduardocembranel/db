#include "Arquivo.hpp"

/* brief: construtor padrao: abre os arquivos de leitura e escrita
* pre: nenhuma
* pos: arquivos de leitura e escrita abertos
*/
Arquivo::Arquivo (const std::string &fileName)
{
   this->fileName = fileName;
   this->in.open(fileName, std::ios::in | std::ios::binary);
}

bool Arquivo::existe () {
   return !in.fail();
}

/* brief: destrutor: fecha os arquivos de leitura e escrita 
* pre: arquivos deve estar abertos
* pos: arquivos de leitura e escrita fechados 
*/
Arquivo::~Arquivo ()
{
   this->in.close();
}
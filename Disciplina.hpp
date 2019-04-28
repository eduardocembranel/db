#ifndef DISCIPLINA_HPP
#define DISCIPLINA_HPP

#include "Serializable.hpp"

class Disciplina : public Serializable {
   private:
      int id;
      std::string nome;

   public:
      Disciplina ();
      Disciplina (int, const std::string &);
      std::string getNome () const;
      void setNome (const std::string &);
      int getId () const;
      int sizeOfMe ();
      void serialize (std::ofstream &file, int offset);
      void* deserialize (std::ifstream &file, int offset);

};


#endif // !DISCIPLINA_HPP
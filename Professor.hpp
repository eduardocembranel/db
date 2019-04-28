#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include "Serializable.hpp"

class Professor : public Serializable {
   private:
      int id;
      std::string nome;

   public:
      Professor ();
      Professor (int , const std::string &);
      std::string getNome () const;
      int getId () const;
      int sizeOfMe ();
      void serialize(std::ofstream &file, int offset);
      void* deserialize (std::ifstream &file, int offset);
};

#endif // !PROFESSOR_HPP
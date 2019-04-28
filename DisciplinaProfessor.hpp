#ifndef DISCIPLINAPROFESSOR_HPP
#define DISCIPLINAPROFESSOR_HPP

#include "Serializable.hpp"

class DisciplinaProfessor : public Serializable {
   private:
      int id;
      int idProfessor;
      int idDisciplina;
      int anoLetivo;
      std::string dataInicio;

   public:
      DisciplinaProfessor ();
      DisciplinaProfessor (int, int, int, int, const std::string &);
      int getIdProfessor () const;
      void setIdProfessor (int);
      int getIdDisciplina () const;
      void setIdDisciplina (int);
      int getAnoLetivo () const;
      void setAnoLetivo (int);
      std::string getDataInicio () const;
      void setDataInicio (const std::string &);
      int getId () const;

      int sizeOfMe ();
      void serialize (std::ofstream &file, int offset);
      void* deserialize (std::ifstream &file, int offset);
};

#endif // !DISCIPLINAPROFESSOR_HPP
#include "App.hpp"
#include "Professor.hpp"
#include "DisciplinaProfessor.hpp"
#include "Disciplina.hpp"
#include <cstdlib>
#include <iostream>
#include <limits>
#include <vector>

App::App (Database *db) {
   this->db = db;
}

void App::run () {
   int escolha = -1;
   while (escolha != 2) {
      showMainMenu();
      std::cin >> escolha;
      flushInput();
      switch (escolha) {
         case 1:
            viewConsultar();
            break;
         case 2:
            break;
         default:
            std::cout << "\nOpcao invalida!";
            promptEnterKey();
      }
   }
}

void App::showConsultar () {
   clear();
   std::cout << "[CONSULTAR DADOS]\n\n";
   std::cout << "[1]Consultar professor por ID\n";
   std::cout << "[2]Consultar professor por nome\n";
   std::cout << "[3]Consultar disciplina por ID\n";
   std::cout << "[4]Consultar disciplina por nome\n>> ";
}

void App::viewConsultar () {
   showConsultar();
   int escolha = -1;
   std::cin >> escolha;
   flushInput();
   if (escolha == 1) {
      std::cout << "\nID: ";
      int id;
      std::cin >> id;
      flushInput();
      Table *tabelaProf = db->getTable("professor");
      void *p = tabelaProf->selectByKey(id, new Professor());
      Professor *prof = (Professor *)p;
      if (prof == nullptr) {
         std::cout << "\nId inexistente na tabela!\n";
      } else {
         std::cout << "\nProfessor: " + prof->getNome() + "\n\nAssociacoes:\n";
         Table *tabelaMeio = db->getTable("disciplinaProfessor");
         Table *tabelaDisciplina = db->getTable("disciplina");
         std::vector<void *> dados = tabelaMeio->selectAll(new DisciplinaProfessor());
         bool relacionamento = false;
         for (int i = 0; i < dados.size(); ++i) {
            void *p = dados[i];
            DisciplinaProfessor *it = (DisciplinaProfessor *)dados[i];
            if (it->getIdProfessor() == id) {
               relacionamento = true;
               int ano = it->getAnoLetivo();
					std::string data = it->getDataInicio();
					int idDisciplina = it->getIdDisciplina();
               void *temp = tabelaDisciplina->selectByKey(idDisciplina, new Disciplina());
					Disciplina *disciplina = (Disciplina *)temp;
               std::cout << "\nDisciplina: " << disciplina->getNome() << "\n";
               std::cout << " Ano letivo: " << ano << "\n";
               std::cout << " Data inicio: " << data << "\n";
               delete disciplina;
            }
         }
         if (!relacionamento) {
            std::cout << "\nNenhuma disciplina cadastrada para este professor!\n";
         }
      }
   } else if (escolha == 2) {

   } else if (escolha == 3) {
      std::cout << "\nID: ";
      int id;
      std::cin >> id;
      flushInput();
      Table *tabelaDisciplina = db->getTable("disciplina");
      void *p = tabelaDisciplina->selectByKey(id, new Disciplina());
      Disciplina *disciplina = (Disciplina *)p;
      if (disciplina == nullptr) {
         std::cout << "\nId inexistente na tabela!\n";
      } else {
         std::cout << "\nDisciplina: " + disciplina->getNome() + "\n\nAssociacoes:\n";
         Table *tabelaMeio = db->getTable("disciplinaProfessor");
         Table *tabelaProfessor = db->getTable("professor");
         std::vector<void *> dados = tabelaMeio->selectAll(new DisciplinaProfessor());
         bool relacionamento = false;
         for (int i = 0; i < dados.size(); ++i) {
            void *p = dados[i];
            DisciplinaProfessor *it = (DisciplinaProfessor *)dados[i];
            if (it->getIdDisciplina() == id) {
               relacionamento = true;
               int ano = it->getAnoLetivo();
					std::string data = it->getDataInicio();
					int idProfessor = it->getIdProfessor();
               void *temp = tabelaProfessor->selectByKey(idProfessor, new Professor());
					Professor *prof = (Professor *)temp;
               std::cout << "\nProfessor: " << prof->getNome() << "\n";
               std::cout << " Ano letivo: " << ano << "\n";
               std::cout << " Data inicio: " << data << "\n";
               delete prof;
            }
         }
         if (!relacionamento) {
            std::cout << "\nNenhuma disciplina cadastrada para este professor!\n";
         }
      }
   } else if (escolha == 4) {

   }
   promptEnterKey();
}

void App::promptEnterKey () {
   std::cout << "\nPressione ENTER para continuar...";
   flushInput();
}

void App::flushInput () {
   std::cin.clear();
   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void App::showMainMenu () {
   clear();
   std::cout << "[MENU PRINCIPAL]\n\n";
   std::cout << "[1]Consultar\n";
   std::cout << "[2]Sair\n";
   std::cout << ">> ";
}

void App::clear () {
   system("clear");
}

App::~App () {

}
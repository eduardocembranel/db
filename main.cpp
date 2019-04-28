#include <iostream>

#include "Database.hpp"
#include "App.hpp"

int main () {
   Database *db = new Database();
   db->addTable(new Table("professor"));
   db->addTable(new Table("disciplina"));
   db->addTable(new Table("disciplinaProfessor"));

   App *app = new App(db);
   app->run();
   delete app;
   
   return 0;
}
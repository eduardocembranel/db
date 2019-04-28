#ifndef APP_HPP
#define APP_HPP

#include "Database.hpp"

class App {
   public:
      App (Database *);
      void run ();
      ~App ();
   
   private:
      Database *db;

      void clear ();
      void showMainMenu ();
      void promptEnterKey ();
      void flushInput ();
      void showConsultar ();
      void viewConsultar ();



};

#endif // !APP_HPP
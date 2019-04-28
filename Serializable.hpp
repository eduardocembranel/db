#ifndef SERIALIZABLE_HPP
#define SERIALIZABLE_HPP

#include <fstream>

class Serializable {
   public:
      virtual int sizeOfMe () = 0;
      virtual void serialize (std::ofstream &file, int offset) = 0;
      virtual void* deserialize (std::ifstream &file, int offset) = 0;
};

#endif // !SERIALIZABLE
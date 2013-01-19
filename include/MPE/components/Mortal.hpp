/// @file Interfaces.hpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2013-01-10


#ifndef  MORTAL_INC
#define  MORTAL_INC

#include <MPE/Config.hpp>

namespace mpe
{
   class Mortal
   {

      public:

         bool isAlive();
         void kill();
         Real getAge() const;

      protected:

         Mortal(Real theLifetime);
         void age(Real theElapsedTime);

      private:

         bool mAlive;
         Real mLifetime;
         Real mAge;
         void die();
   };

}
#endif   // ----- #ifndef MORTAL_INC  -----

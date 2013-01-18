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

   Mortal::Mortal(Real theLifetime):
      mAlive(true),
      mLifetime(theLifetime),
      mAge(0)
   {}
   inline bool Mortal::isAlive()
   {
      return mAlive;
   }
   inline void Mortal::age(Real theElapsedTime)
   {
      mAge += theElapsedTime;
      if (mAge > mLifetime)
         die();
   }
   inline void Mortal::die()
   {
      mAlive=false;
   }
   inline void Mortal::kill()
   {
      mAlive=false;
   }
   inline Real Mortal::getAge() const
   {
      return mAge;
   }
}
#endif   // ----- #ifndef MORTAL_INC  -----

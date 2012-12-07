#ifndef  SYSTEM_INC
#define  SYSTEM_INC

#include <list>
#include <boost/shared_ptr.hpp>

#include "Emitter.hpp"

namespace MPE
{
   class System: Emitter::Adder
   {
      public:

         typedef boost::shared_ptr<System> Ptr;
         System();
         ~System();
         void addParticles(float theElapsedTime);

      private:

         std::list<Particle> mParticles;
         std::list<Emitter::Ptr> mEmitters;
   };
}
#endif   // ----- #ifndef SYSTEM_INC  -----

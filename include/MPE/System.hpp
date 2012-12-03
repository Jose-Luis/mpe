#ifndef  SYSTEM_INC
#define  SYSTEM_INC

#include <list>
#include <boost/shared_ptr.hpp>

#include "Emitter.hpp"
//#include "Config.hpp"
class Emitter;
namespace MPE
{
   class System
   {
      public:

         typedef boost::shared_ptr<System> Ptr;
         System();
         ~System();

      private:

         std::list<Particle> mParticles;
         std::list<Emitter::Ptr> mEmitters;
   };
}
#endif   // ----- #ifndef SYSTEM_INC  -----

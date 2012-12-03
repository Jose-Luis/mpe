
#ifndef  EMITTER_INC
#define  EMITTER_INC

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

#include "Particle.hpp"
#include "System.hpp"
//#include "Config.hpp"
class System;

namespace MPE
{
   class Emitter
   {
      public:
        
         typedef boost::shared_ptr<Emitter> Ptr;

         Emitter();
         Emitter(System* theSystem);
         static Ptr create();
         static Ptr create(System* theSystem);
         ~Emitter();

      private:

         System* mSystem;
         float TTL;
         float PPS;
         float TotalParticles;
         
   };
}    
#endif   // ----- #ifndef EMITTER_INC  -----

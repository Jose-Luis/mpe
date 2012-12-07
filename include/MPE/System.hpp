#ifndef  SYSTEM_INC
#define  SYSTEM_INC

#include <list>
#include <map>
#include <boost/shared_ptr.hpp>

#include <MPE/Emitter.hpp>

namespace MPE
{
   class System: Emitter::Adder
   {
      public:

         System();
         ~System();

         void addEmitter(Emitter::Ptr theEmitter);
         void addParticle(const Particle& theParticle);
         void update(float theElapsedTime);
         Emitter::Ptr getEmitter(Emitter::ID theID);

      private:

         std::list<Particle> mParticles;
         std::map<Emitter::ID,Emitter::Ptr> mEmitters;
   };
}
#endif   // ----- #ifndef SYSTEM_INC  -----

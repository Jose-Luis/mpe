
#include <MPE/System.hpp>

namespace MPE
{
   void System::addEmitter(Emitter::Ptr theEmitter)
   {
      if (mEmitters.find(theEmitter->getID()) == mEmitters.end())
         mEmitters.insert(std::pair<Emitter::ID,Emitter::Ptr>(theEmitter->getID(),theEmitter));
   }

   void System::addParticle(const Particle& theParticle)
   {
      mParticles.push_back(theParticle);
   }

   void System::update(Real theElapsedTime)
   {
      for( auto anEmitter: mEmitters)
      {
         anEmitter.second->emit(*this,theElapsedTime);
      }
   }

}

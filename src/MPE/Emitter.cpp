#include <MPE/Emitter.hpp>

namespace MPE
{     
   Emitter::Emitter(Adder& theSystem):
      mSystem(theSystem)
   {
   }

   Emitter::Ptr Emitter::create(Adder& theSystem)
   {
      return boost::make_shared<Emitter>(theSystem);
   }

   void Emitter::update(float theElapsedTime)
   {
      for (auto it = mFocusses.begin(); it != mFocusses.end(); it++)
      {
         it->lifetime += theElapsedTime;
         if ( (mTTL == -1 || it->lifetime < mTTL) 
              &&
              (mTotalParticles == -1 || mTotalParticles > it->emittedParticles))
         {
            int nParticles = (mPPS * it->lifetime / 1000) - it->emittedParticles;
            it->emittedParticles += nParticles;
         }
         else if(it->lifetime > mTTL || it->emittedParticles > mTotalParticles)
         {
            mFocusses.erase(it);
         }

      }
   }

   void Emitter::emit(int theNumberOfParticles)
   {
      for (int i=0;i<theNumberOfParticles;i++)
      {
         Particle anParticle = createParticle();
         mSystem.addParticle(anParticle);
      }
   }

}


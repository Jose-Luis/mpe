#include <MPE/Emitter.hpp>
#include <cstdlib>

namespace MPE
{     
   Emitter::Emitter(ISystem& theSystem):
      mSystem(theSystem)
   {
   }

   Emitter::Ptr Emitter::create(ISystem& theSystem)
   {
      return boost::make_shared<Emitter>(theSystem);
   }

   void Emitter::update(Real theElapsedTime)
   {
      for (auto it = mFocusses.begin(); it != mFocusses.end(); it++)
      {
         it->lifetime += theElapsedTime;
         if ( (mTTL == -1 || it->lifetime < mTTL) 
               &&
               (mTotalParticles == -1 || mTotalParticles > it->emittedParticles))
         {
            Integer nParticles = (mPPS * it->lifetime / 1000) - it->emittedParticles;
            it->emittedParticles += nParticles;
            emit(nParticles);
         }
         else if(it->lifetime > mTTL || it->emittedParticles > mTotalParticles)
         {
            mFocusses.erase(it);
         }

      }
   }

   void Emitter::emit(Integer theNumberOfParticles, Focus& theFocus)
   {
      for (Integer i = 0; i < theNumberOfParticles; i++)
      {
         //Particle anParticle = createParticle(theFocus);
         //Particle anParticle = Particle(
         mSystem.addParticle(anParticle);
      }
   }

   sf::Vector2f Emitter::generatePosition(Focus& theFocus)
   {
      Real anX,anY;

      do
      {
         anX = 2*std::rand() / RAND_MAX - 1;
         anY = 2*std::rand() / RAND_MAX - 1;
      }
      while(mShape == CIRCLE && (anX*anX + anY*anY > 1));
      
      anX = (anX * theFocus.angle.cos - anY * theFocus.angle.sin) + theFocus.position.x;
      anY = (anX * theFocus.angle.sin + anY * theFocus.angle.cos) + theFocus.position.y;
     
      anX *= mSystem.getXFactor();
      anY *= mSystem.getYFactor();

      return sf::Vector2f(anX*theFocus.width,anY*theFocus.height);
   }

   //Particle Emitter::createParticle(Focus& theFocus)
   //{
      
         ////Particle(sf::Texture& theTexture, sf::Vector2f thePosition, sf::Vector2f theLinearVelocity, Real theAngularVelocity,  sf::Color theColor, Real theTTL):
   //}
}
      

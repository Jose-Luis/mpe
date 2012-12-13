// =====================================================================================
// 
//       Filename:  Emitter.cpp
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  13/12/12 21:29:26
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Jose Luis Lavado (), joseluislavado@gmail.com
//        Company:  
// 
// =====================================================================================

#include <MPE/Emitter.hpp>
#include <cstdlib>

namespace MPE
{     
   //--------------------------------------------------------------------------------------
   //       Class:  Emitter
   //      Method:  constructor
   // Description:  
   //--------------------------------------------------------------------------------------
   Emitter::Emitter(Emitter::ID theID,ISystem& theSystem):
      mID(theID),
      mSystem(theSystem)
   {
   }
   //--------------------------------------------------------------------------------------
   //       Class:  Emitter
   //      Method:  create
   // Description:  
   //--------------------------------------------------------------------------------------
   Emitter::Ptr Emitter::create(Emitter::ID theID,ISystem& theSystem)
   {
      return boost::make_shared<Emitter>(theID,theSystem);
   }
   //--------------------------------------------------------------------------------------
   //       Class:  Emitter
   //      Method:  update
   // Description:  
   //--------------------------------------------------------------------------------------
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
   //--------------------------------------------------------------------------------------
   //       Class:  Emitter
   //      Method:  emit
   // Description:  
   //--------------------------------------------------------------------------------------
   void Emitter::emit(Integer theNumberOfParticles, Focus& theFocus)
   {
      for (Integer i = 0; i < theNumberOfParticles; i++)
      {
         //Particle anParticle = Particle(...);
         mSystem.addParticle(anParticle);
      }
   }
   //--------------------------------------------------------------------------------------
   //       Class:  Emitter
   //      Method:  generateVelocity
   // Description:  
   //--------------------------------------------------------------------------------------
   sf::Vector2f Emitter::generateVelocity(Focus& theFocus, sf::Vector2f& theParticlePosition)
   {
      sf::Vector2f anVelocity;

      switch (mDispersion)
      {
         case LINEAR:
            anVelocity = mLinearVelocity;
            break;
         case RADIAL:
            anVelocity = diffVectors(theFocus.position,theParticlePosition);
            normalize(anVelocity);
            break;
         case STATIC:
            anVelocity = sf::Vector2f(0,0);
            break;
         case RANDOM:
            anVelocity = normalize(sf::Vector2f(Randomizer::get(-1,1),Randomizer::get(-1,1)));
            break;
        case REFLECT:
            anVelocity = sf::Vector2f(0,0);
            break;
        case Default:
            anVelocity = sf::Vector2f(0,0);
            break;
      }
      anVelocity = scaleVector(anVelocity,mRangeStrenght.get());

      return anVelocity;
   }
   //--------------------------------------------------------------------------------------
   //       Class:  Emitter
   //      Method:  generatePosition
   // Description:  
   //--------------------------------------------------------------------------------------
   sf::Vector2f Emitter::generatePosition(Focus& theFocus)
   {
      Real anX,anY;

      do
      {
         anX = Randomizer::get(-1,1);
         anY = Randomizer::get(-1,1);
      }
      while(mShape == CIRCLE && (anX*anX + anY*anY > 1));

      anX = (anX * theFocus.angle.cos - anY * theFocus.angle.sin) + theFocus.position.x;
      anY = (anX * theFocus.angle.sin + anY * theFocus.angle.cos) + theFocus.position.y;

      anX *= mSystem.getXFactor();
      anY *= mSystem.getYFactor();

      return sf::Vector2f(anX*theFocus.width,anY*theFocus.height);
   }
   //--------------------------------------------------------------------------------------
   //       Class:  Emitter
   //      Method:  normalize
   // Description:  
   //--------------------------------------------------------------------------------------
   inline void Emitter::normalize(sf::Vector2f& theVector)
   {
      Real anModule;

      anModule = std::sqrt(theVector.x * theVector.x + theVector.y * theVector.y);
      theVector.x /= anModule;
      theVector.y /= anModule;
   }
   //--------------------------------------------------------------------------------------
   //       Class:  Emitter
   //      Method:  scaleVector
   // Description:  
   //--------------------------------------------------------------------------------------
   inline sf::Vector2f Emitter::scaleVector(const sf::Vector2f& theVector,Real theScalar)
   {
      return sf::Vector2f(theVector.x * theScalar,theVector.y * theScalar);
   }
   //--------------------------------------------------------------------------------------
   //       Class:  Emitter
   //      Method:  diffVectors
   // Description:  
   //--------------------------------------------------------------------------------------
   inline sf::Vector2f diffVectors(const sf::Vector2f& theOrigin,const sf::Vector2f& theFinal)
   {
     return sf::Vector2f(theFinal.x-theOrigin.x,theFinal.y-theOrigin.y);
   }
   //--------------------------------------------------------------------------------------
   //       Class:  Emitter
   //      Method:  addFocus
   // Description:  
   //--------------------------------------------------------------------------------------
   void Emitter::addFocus(Focus theFocus)
   {
      mFocusses.push_back(theFocus);
   }
   //--------------------------------------------------------------------------------------
   //       Class:  Emitter
   //      Method:  getShape
   // Description:  Getter  
   //--------------------------------------------------------------------------------------
   inline Emitter::Shape Emitter::getShape (  ) const
   {
      return mShape;
   }
   //--------------------------------------------------------------------------------------
   //       Class:  Emitter
   //      Method:  setShape
   // Description:  Setter 
   //--------------------------------------------------------------------------------------
   inline void Emitter::setShape ( Shape value )
   {
      mShape	= value;
      return ;
   }
   //--------------------------------------------------------------------------------------
   //       Class:  Emitter
   //      Method:  getRangeStrenght
   // Description:  Getter
   //--------------------------------------------------------------------------------------
   inline Randomizer Emitter::getRangeStrenght (  ) const
   {
      return mRangeStrenght;
   }

   //--------------------------------------------------------------------------------------
   //       Class:  Emitter
   //      Method:  setRangeStrenght
   // Description:  Setter
   //--------------------------------------------------------------------------------------
   inline void Emitter::setRangeStrenght ( Randomizer value )
   {
      mRangeStrenght = value;
      return;
   }
   //--------------------------------------------------------------------------------------
   //       Class:  Emitter
   //      Method:  getRangeParticleTTL
   // Description:  Getter
   //--------------------------------------------------------------------------------------
   inline Randomizer Emitter::getRangeParticleTTL (  ) const
   {
      return mRangeParticleTTL;
   }
   //--------------------------------------------------------------------------------------
   //       Class:  Emitter
   //      Method:  setRangeParticleTTL
   // Description:  Setter
   //--------------------------------------------------------------------------------------
   inline void Emitter::setRangeParticleTTL ( Randomizer value )
   {
      mRangeParticleTTL = value;
      return;
   }
}


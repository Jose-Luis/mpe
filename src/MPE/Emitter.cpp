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
         updateFocusState(*it);
         if ( it->alive)
         {
            Integer nParticles = (mPPS * it->lifetime / 1000) - it->emittedParticles;
            it->emittedParticles += nParticles;
            emit(nParticles);
         }
         else 
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
            anVelocity = normalizeVector(anVelocity);
            break;
         case STATIC:
            anVelocity = sf::Vector2f(0,0);
            break;
         case RANDOM:
            anVelocity = normalizeVector(sf::Vector2f(Randomizer::get(-1,1),Randomizer::get(-1,1)));
            break;
        case REFLECT:
            anVelocity = sf::Vector2f(0,0);
            break;
        default:
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
   inline sf::Vector2f Emitter::normalizeVector(const sf::Vector2f& theVector)
   {
      Real anModule;

      anModule = std::sqrt(theVector.x * theVector.x + theVector.y * theVector.y);
      return sf::Vector2f (theVector.x / anModule, theVector.y / anModule);
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
   inline sf::Vector2f Emitter::diffVectors(const sf::Vector2f& theOrigin,const sf::Vector2f& theFinal)
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
   //      Method:  updateFocusState
   // Description:  
   //--------------------------------------------------------------------------------------
   void Emitter::updateFocusState(Focus& theFocus)
   {
      if( (theFocus.lifetime > mTTL && mTTL != -1) 
            || 
          (theFocus.emittedParticles > mTotalParticles && mTotalParticles != -1) )
            theFocus.alive = false;
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
   //      Method:  getDispersion
   // Description:  Getter
   //--------------------------------------------------------------------------------------
   inline Dispersion Emitter::getDispersion (  ) const
   {
      return mDispersion;
   }
   //--------------------------------------------------------------------------------------
   //       Class:  Emitter
   //      Method:  setDispersion
   // Description:  Setter
   //--------------------------------------------------------------------------------------
   inline void Emitter::setDispersion ( Dispersion value )
   {
      mDispersion = value;
      return;
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
   //--------------------------------------------------------------------------------------
   //       Class:  Emitter
   //      Method:  getLinearVelocity
   // Description:  Getter
   //--------------------------------------------------------------------------------------
   inline sf::Vector2f Emitter::getLinearVelocity (  ) const
   {
      return mLinearVelocity;
   }
   //--------------------------------------------------------------------------------------
   //       Class:  Emitter
   //      Method:  setLinearVelocity
   // Description:  Setter
   //--------------------------------------------------------------------------------------
   inline void Emitter::setLinearVelocity ( sf::Vector2f value )
   {
      mLinearVelocity = value;
      return;
   }
   //--------------------------------------------------------------------------------------
   //       Class:  Emitter
   //      Method:  getTTL
   // Description:  Getter
   //--------------------------------------------------------------------------------------
   inline Real Emitter::getTTL (  ) const
   {
      return mTTL;
   }
   //--------------------------------------------------------------------------------------
   //       Class:  Emitter
   //      Method:  setTTL
   // Description:  Setter
   //--------------------------------------------------------------------------------------
   inline void Emitter::setTTL ( Real value )
   {
      mTTL = value;
      return;
   }
   //--------------------------------------------------------------------------------------
   //       Class:  Emitter
   //      Method:  getPPS
   // Description:  Getter
   //--------------------------------------------------------------------------------------
   inline Real Emitter::getPPS (  ) const
   {
      return mPPS;
   }
   //--------------------------------------------------------------------------------------
   //       Class:  Emitter
   //      Method:  setPPS
   // Description:  Setter
   //--------------------------------------------------------------------------------------
   inline void Emitter::setPPS ( Real value )
   {
      mPPS = value;
      return;
   }
   //--------------------------------------------------------------------------------------
   //       Class:  Emitter
   //      Method:  getTotalParticles
   // Description:  Getter
   //--------------------------------------------------------------------------------------
   inline Integer Emitter::getTotalParticles (  ) const
   {
      return mTotalParticles;
   }
   //--------------------------------------------------------------------------------------
   //       Class:  Emitter
   //      Method:  setTotalParticles
   // Description:  Setter
   //--------------------------------------------------------------------------------------
   inline void Emitter::setTotalParticles ( Integer value )
   {
      mTotalParticles = value;
      return;
   }
}


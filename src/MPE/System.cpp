/// @file System.cpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2012-12-18

#include <MPE/System.hpp>
#include <MPE/Particle.hpp>
#include <MPE/Emitter.hpp>
#include <MPE/Focus.hpp>

namespace mpe
{
//------------------------------------------------------------------------------
//       Class:  System
//      Method:  System
// Description:  
//------------------------------------------------------------------------------
System::System ( Real theFactor ):
   mXFactor(theFactor),
   mYFactor(theFactor)
{
}
//--------------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  addEmitter
// Description:  
//--------------------------------------------------------------------------------------
void System::addEmitter(Emitter& theEmitter)
{
   EmitterID anEmitterID = theEmitter.getID();
   auto it = mEmitters.find(anEmitterID);
   if (it == mEmitters.end() )
   {
      mEmitters.insert(std::pair<EmitterID,Emitter>(anEmitterID,theEmitter));
   }
}
//--------------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  addFocus
// Description:  
//--------------------------------------------------------------------------------------
void System::addFocus(EmitterID theEmitterID,
                       gt::Vec2D  thePosition,
                       Real       theAngle)
{
   Emitter& anEmitter = getEmitter(theEmitterID);
   Focus anFocus = anEmitter.createFocus((*this),thePosition,theAngle);
   mFocusses.push_back(anFocus);
   
}
//--------------------------------------------------------------------------------------
//       Class:  System
//      Method:  addParticle
// Description:  
//--------------------------------------------------------------------------------------
void System::addParticle (Particle& theParticle)
{
   mParticles.push_back(theParticle);
}
//------------------------------------------------------------------------------
//       Class:  System
//      Method:  getEmitter
// Description:  
//------------------------------------------------------------------------------
Emitter& System::getEmitter ( EmitterID theEmitterID )
{

   auto it = mEmitters.find(theEmitterID);
   if (it != mEmitters.end() )
   {
      return it->second;
   }
   return Emitter::DUMMY;
}
//------------------------------------------------------------------------------
//       Class:  System
//      Method:  update
// Description:  
//------------------------------------------------------------------------------
void System::updateFocusses(Real theElapsedTime)
{
   for (auto it = mFocusses.begin(); it != mFocusses.end(); it++)
   {
      if (it->isAlive())
      {
         it->update(theElapsedTime);
      }
      else 
      {
         it = mFocusses.erase(it);
         it--;
      }
   }
}
//------------------------------------------------------------------------------
//       Class:  System
//      Method:  update
// Description:  
//------------------------------------------------------------------------------
void System::updateParticles(Real theElapsedTime)
{
   for (auto it = mParticles.begin(); it != mParticles.end(); it++)
   {
      if (it->isAlive())
      {
         it->update(theElapsedTime);
         it->setSpritePosition(mXFactor,mYFactor);
      }
      else 
      {
         it = mParticles.erase(it);
         it--;
      }
   }
}
//------------------------------------------------------------------------------
//       Class:  System
//      Method:  update
// Description:  
//------------------------------------------------------------------------------
void System::update (Real theElapsedTime)
{
   updateFocusses(theElapsedTime);
   updateParticles(theElapsedTime);
}
//--------------------------------------------------------------------------------------
//       Class:  System
//      Method:  draw
// Description:  
//--------------------------------------------------------------------------------------
void System::draw (sf::RenderWindow& theWindow) const
{
   std::list<Particle>::const_iterator it;
   for(it = mParticles.begin();it != mParticles.end();it++)
   {
      theWindow.draw(it->getSprite());
   }
}
}


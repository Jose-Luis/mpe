/// @file System.cpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2012-12-18

#include <MPE/classes/System.hpp>

namespace mpe
{
//------------------------------------------------------------------------------
//      Class:        System
//      Method:       getXFactor
//      Description:
//------------------------------------------------------------------------------
Real System::getXFactor() const
{
   return mXFactor;
}
//------------------------------------------------------------------------------
//      Class:        System
//      Method:       setXFactor
//      Description:
//------------------------------------------------------------------------------
void System::setXFactor(Real theXFactor)
{
   mXFactor = theXFactor;
}
//------------------------------------------------------------------------------
//      Class:        System
//      Method:       getYFactor
//      Description:
//------------------------------------------------------------------------------
Real System::getYFactor() const
{
   return mYFactor;
}
//------------------------------------------------------------------------------
//      Class:        System
//      Method:       setYFactor
//      Description:
//------------------------------------------------------------------------------
void System::setYFactor(Real theYFactor)
{
   mYFactor = theYFactor;
}
//------------------------------------------------------------------------------
//       Class:  System
//      Method:  System
// Description:
//------------------------------------------------------------------------------
System::System ():
   mXFactor(1),
   mYFactor(1)
{
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  addEmitter
// Description:
//------------------------------------------------------------------------------
void System::addEmitter(Emitter& theEmitter)
{
   EmitterID anEmitterID = theEmitter.getID();
   auto it = mEmitters.find(anEmitterID);

   if (it == mEmitters.end() )
   {
      theEmitter.setSystem(this);
      mEmitters.insert(std::pair<EmitterID, Emitter>(anEmitterID, theEmitter));
   }
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  addFocus
// Description:
//------------------------------------------------------------------------------
void System::addAffector(AffectorPtr theAffector)
{
   mAffectors.push_back(theAffector);
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  addFocus
// Description:
//------------------------------------------------------------------------------
void System::addFocus(FocusPtr theFocus)
{
   mFocusses.push_back(theFocus);
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  createFocus
// Description:
//------------------------------------------------------------------------------
FocusPtr System::createFocus(EmitterID theEmitterID,
                             Vec2  thePosition,
                             Real       theAngle,
                             GroupID    theGroups)
{
   return getEmitter(theEmitterID).createFocus(thePosition, theAngle, theGroups);
}
//------------------------------------------------------------------------------
//       Class:  System
//      Method:  addParticle
// Description:
//------------------------------------------------------------------------------
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
      if ((*it)->isAlive())
      {
         (*it)->update(theElapsedTime);
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
   for (auto affector =  mAffectors.begin();
         affector != mAffectors.end();
         affector++)
   {
      if ( (*affector)->isAlive() )
      {
         (*affector)->update(theElapsedTime);

         for (auto particle =  mParticles.begin();
               particle != mParticles.end();
               particle++)
         {
            (*affector)->affect(*particle, theElapsedTime);
         }
      }
      else
      {
         affector = mAffectors.erase(affector);
         affector++;
      }
   }

   for (auto particle =  mParticles.begin();
         particle != mParticles.end();
         particle++)
   {
      if(particle->isAlive())
      {
         particle->update(theElapsedTime);
      }
      else
      {
         particle = mParticles.erase(particle);
         particle--;
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
////////////////////////////////////// END NAMESPACE  mpe //////////////////////
}


/// @file System.cpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2012-12-18

#include <MPE/System.hpp>

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
//------------------------------------------------------------------------------
//       Class:  System
//      Method:  getEmitter
// Description:  
//------------------------------------------------------------------------------
Emitter::Ptr System::getEmitter ( Emitter::ID theEmitterID ) const
{
   Emitter::Ptr anResult;

   auto it = mEmitters.find(theEmitterID);
   if (it != mEmitters.end() )
   {
      anResult = it->second();
   }
   return anResult;
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
         mFocusses.erase(it);
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
      }
      else 
      {
         mParticles.erase(it);
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
}

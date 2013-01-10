/**
 * @file Emitter.cpp
 * @author Jose Luis Lavado
 * @version 0.1
 * @date 2012-12-18
 */

#include <MPE/classes/Emitter.hpp>
#include <MPE/classes/Focus.hpp>
#include <cstdlib>

namespace mpe
{     
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  constructor
// Description:  
//------------------------------------------------------------------------------
Emitter::Emitter(EmitterID theID):
   mID(theID),
   mRangeFocusTOL(0,0),
   mRangeFocusPPS(0,0)
{
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  generateVelocity
// Description:  
//------------------------------------------------------------------------------
gt::Vec2D Emitter::generateVelocity(const Focus& theFocus, 
                                    const gt::Vec2D& theParticlePosition) const
{
   gt::Vec2D anVelocity;

   switch (mDispersion)
   {
      case LINEAR:
         anVelocity = gt::Vec2D(theFocus.getAngle().getCos(),
                                theFocus.getAngle().getSin());
         break;
      case RADIAL:
         anVelocity = theParticlePosition - theFocus.getPosition();
         anVelocity.normalize();
         break;
      case STATIC:
         anVelocity = gt::Vec2D();
         break;
      case RANDOM:
         anVelocity = gt::Vec2D(gt::Randomizer::get(-1,1),
                                gt::Randomizer::get(-1,1));
         anVelocity.normalize();
         break;
     case REFLECT:
         anVelocity = gt::Vec2D();
         break;
     default:
         anVelocity = gt::Vec2D();
         break;
   }
   anVelocity *= mRangeParticlePOW.get();

   return anVelocity;
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  generatePosition
// Description:  
//------------------------------------------------------------------------------
gt::Vec2D Emitter::generatePosition(const Focus& theFocus) const
{
   gt::Vec2D anPosition;
   do
   {
      anPosition.x = gt::Randomizer::get(-1,1);
      anPosition.y = gt::Randomizer::get(-1,1);
   }
   while(mShape == CIRCLE && anPosition.squaremodule() > 1);

   anPosition.rotate(theFocus.getAngle());
   anPosition.scale(theFocus.getWidth(),theFocus.getHeight());
   anPosition = anPosition + theFocus.getPosition();

   return anPosition;
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  createFocus
// Description:  
//------------------------------------------------------------------------------
Focus Emitter::createFocus(System&   theSystem,
                           gt::Vec2D thePosition,
                           Real      theAngle)
{
   Focus anFocus(getFocusWidth(),
                 getFocusHeight(),
                 gt::Angle(theAngle),
                 thePosition,
                 getFocusNP(),
                 getFocusTOL(),
                 getFocusPPS(),
                 theSystem,
                 (*this));

   return anFocus;
}
////////////////////////////////////////////////////////////////////////////////
Emitter Emitter::DUMMY = Emitter("DUMMY");
}
/* Copyright (C) 
 * 2012 - Jose Luis Lavado
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 * 
 */

////--------------------------------------------------------------------------------------
////       Class:  Emitter
////      Method:  update
//// Description:  
////--------------------------------------------------------------------------------------
//void Emitter::update(Real theElapsedTime)
//{
   //for (auto it = mFocusses.begin(); it != mFocusses.end(); it++)
   //{
      //it->lifetime += theElapsedTime;
      //updateFocusState(*it);
      //if ( it->alive)
      //{
         //Integer nParticles = (mPPS * it->lifetime / 1000) - it->emittedParticles;
         //it->emittedParticles += nParticles;
         //emit(nParticles);
      //}
      //else 
      //{
         //mFocusses.erase(it);
      //}
   //}
//}
////--------------------------------------------------------------------------------------
////       Class:  Emitter
////      Method:  emit
//// Description:  
////--------------------------------------------------------------------------------------
//void Emitter::emit(Integer theNumberOfParticles, Focus& theFocus)
//{
   //for (Integer i = 0; i < theNumberOfParticles; i++)
   //{
      ////Particle anParticle = Particle(...);
      //mSystem.addParticle(anParticle);
   //}
//}

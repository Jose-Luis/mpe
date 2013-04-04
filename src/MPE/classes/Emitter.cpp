/**
 * @file Emitter.cpp
 * @author Jose Luis Lavado
 * @version 0.1
 * @date 2012-12-18
 */

#include <MPE/classes/Emitter.hpp>

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
FocusPtr Emitter::createFocus(gt::Vec2D thePosition,
                              Real      theAngle,
                              GroupID   theGroups) const
{
   FocusPtr anFocus = Focus::create(getFocusWidth(),
                                    getFocusHeight(),
                                    gt::Angle(theAngle),
                                    thePosition,
                                    getFocusNP(),
                                    getFocusTOL(),
                                    getFocusPPS(),
                                    theGroups,
                                    (*this));

   return anFocus;
}
//        ACCESORS
////////////////////////////////////////////////////////////////////////////////
EmitterID Emitter::getID() const
{
   return mID;
}
sf::Rect& Emitter::getTexRect() const
{
   return mTexRect;
}
System* Emitter::getSystem() const 
{
   return mSystem;
}
Real Emitter::getParticlePOW() const 
{
   return mRangeParticlePOW.get();
}
Real Emitter::getParticleTOL() const 
{
   return mRangeParticleTOL.get();
}
Real Emitter::getParticleAngle() const 
{
   return mRangeParticleAngle.get();
}
Real Emitter::getParticleScale() const 
{
   return mRangeParticleScale.get();
}
Real Emitter::getParticleAV() const 
{
   return mRangeParticleAV.get();
}
Real Emitter::getFocusTOL() const 
{
   return mRangeFocusTOL.get();
}
Real Emitter::getFocusWidth() const 
{
   return mRangeFocusWidth.get();
}
Real Emitter::getFocusHeight() const 
{
   return mRangeFocusHeight.get();
}
Real Emitter::getFocusPPS() const 
{
   return mRangeFocusPPS.get();
}
Integer Emitter::getFocusNP() const 
{
   return static_cast<Integer>(mRangeFocusNP.get());
}
void Emitter::setTexRect(sf::Rect<int> theTexRect);
{
   mTexRect = theTexRect;
}
void Emitter::setShape(Shape theShape)
{
   mShape = theShape;
}
void Emitter::setDispersion(Dispersion theDispersion) 
{
   mDispersion = theDispersion;
}
void Emitter::setRangeParticlePOW(Real theMin, Real theMax)
{
   mRangeParticlePOW(theMin,theMax);
}
void Emitter::setRangeParticleTOL(Real theMin, Real theMax)
{
   mRangeParticleTOL(theMin,theMax);
}
void Emitter::setRangeParticleAngle(Real theMin, Real theMax)
{
   mRangeParticleAngle(theMin,theMax);
}
void Emitter::setRangeParticleScale(Real theMin, Real theMax)
{
   mRangeParticleAngle(theMin,theMax);
}
void Emitter::setRangeParticleAV(Real theMin, Real theMax)
{
   mRangeParticleAV(theMin,theMax);
}
void Emitter::setRangeFocusWidth(Real theMin, Real theMax)
{
   mRangeFocusWidth(theMin,theMax);
}
void Emitter::setRangeFocusHeight(Real theMin, Real theMax)
{
   mRangeFocusHeight(theMin,theMax);
}
void Emitter::setRangeFocusTOL(Real theMin, Real theMax)
{
   mRangeFocusTOL(theMin,theMax);
}
void Emitter::setRangeFocusPPS(Real theMin, Real theMax)
{
   mRangeFocusPPS(theMin,theMax);
}
void Emitter::setRangeFocusNP(Real theMin,Real theMax)
{
   mRangeFocusNP(theMin,theMax);
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

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
   mRF_TOL(0,0),
   mRF_PPS(0,0)
{
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  generateVelocity
// Description:  
//------------------------------------------------------------------------------
Vec2 Emitter::generateVelocity(const Focus& theFocus, 
                               const Vec2& theParticlePosition) const

   Vec2 anVelocity;

   switch (mDispersion)
   {
      case LINEAR:
         anVelocity = Vec2(std::cos(theFocus.getAngle()),
                           std::sin(theFocus.getAngle()));
         break;
      case RADIAL:
         anVelocity = theParticlePosition - theFocus.getPosition();
         anVelocity.normalize();
         break;
      case STATIC:
         anVelocity = Vec2();
         break;
      case RANDOM:
         anVelocity = Vec2(sRealRandom(),sRealRandom());
         anVelocity.normalize();
         break;
     case REFLECT:
         anVelocity = Vec2();
         break;
     default:
         anVelocity = Vec2();
         break;
   }
   anVelocity *= mRP_POW.get();

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
      anPosition.x = sRealRandom();
      anPosition.y = sRealRandom();
   }
   while(mShape == CIRCLE && anPosition.squaremodule() > 1);

   anPosition.scale(theFocus.getWidth(),theFocus.getHeight());
   anPosition.rotate(theFocus.getAngle());
   anPosition = anPosition + theFocus.getPosition();

   return anPosition;
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  createFocus
// Description:  
//------------------------------------------------------------------------------
FocusPtr Emitter::createFocus(Vec2D   thePosition,
                              Real    theAngle,
                              GroupID theGroups) const
{
   FocusPtr anFocus = Focus::create(getFocusWidth(),
                                    getFocusHeight(),
                                    getParticleAngle(),
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
System* Emitter::getSystem() const 
{
   return mSystem;
}
Real Emitter::getParticleLV() const 
{
   return mRP_LV.get();
}
Real Emitter::getParticleTOL() const 
{
   return mRP_TOL();
}
Real Emitter::getParticleAngle() const 
{
   return mRP_Angle();
}
Real Emitter::getParticleAV() const 
{
   return mRP_AV();
}
Real Emitter::getFocusTOL() const 
{
   return mRF_TOL();
}
Real Emitter::getFocusWidth() const 
{
   return mRF_Width();
}
Real Emitter::getFocusHeight() const 
{
   return mRF_Height();
}
Real Emitter::getFocusPPS() const 
{
   return mRF_PPS();
}
Integer Emitter::getFocusNP() const 
{
   return mRF_NP();
}
void Emitter::setShape(Shape theShape)
{
   mShape = theShape;
}
void Emitter::setDispersion(Dispersion theDispersion) 
{
   mDispersion = theDispersion;
}
void Emitter::setRangeParticleWidth(Real theMin, Real theMax)
{
   mRP_Width = Randomizer<Real>{theMin,theMax};
}
void Emitter::setRangeParticleHeight(Real theMin, Real theMax)
{
   mRP_Height = Randomizer<Real>{theMin,theMax};
}
void Emitter::setRangeParticleLV(Real theMin, Real theMax)
{
   mRP_LV = Randomizer<Real>{theMin,theMax};
}
void Emitter::setRangeParticleTOL(Real theMin, Real theMax)
{
   mRP_TOL = Randomizer<Real>{theMin,theMax};
}
void Emitter::setRangeParticleAngle(Real theMin, Real theMax)
{
   mRP_Angle = Randomizer<Real>{theMin,theMax};
}
void Emitter::setRangeParticleAV(Real theMin, Real theMax)
{
   mRP_AV = Randomizer<Real>{theMin,theMax};
}
void Emitter::setRangeFocusWidth(Real theMin, Real theMax)
{
   mRF_Width = Randomizer<Real>{theMin,theMax};
}
void Emitter::setRangeFocusHeight(Real theMin, Real theMax)
{
   mRF_Height = Randomizer<Real>{theMin,theMax};
}
void Emitter::setRangeFocusTOL(Real theMin, Real theMax)
{
   mRF_TOL = Randomizer<Real>{theMin,theMax};
}
void Emitter::setRangeFocusPPS(Real theMin, Real theMax)
{
   mRF_PPS = Randomizer<Real>{theMin,theMax};
}
void Emitter::setRangeFocusNP(Integer theMin,Integer theMax)
{
   mRF_NP = Randomizer<Integer>{theMin,theMax};
}
////////////////////////////////////////////////////////////////////////////////
Emitter::DUMMY = Emitter("DUMMY");
Emitter::sRealRandom{};
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

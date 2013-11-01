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
   mGenFocTOL(0, 0),
   mGenFocPPS(0, 0)
{
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  generateVelocity
// Description:
//------------------------------------------------------------------------------
Vec2 Emitter::generateVelocity(const Focus& theFocus,
                               const Vec2& theParticlePosition) const

{
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
      anVelocity = Vec2(sRealRandom(), sRealRandom());
      anVelocity.normalize();
      break;

   case REFLECT:
      anVelocity = Vec2();
      break;

   default:
      anVelocity = Vec2();
      break;
   }

   anVelocity *= mGenParLV();

   return anVelocity;
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  generatePosition
// Description:
//------------------------------------------------------------------------------
Vec2 Emitter::generatePosition(const Focus& theFocus) const
{
   Vec2 anPosition;

   do
   {
      anPosition.init(sRealRandom(), sRealRandom());
   }
   while(mShape == CIRCLE && anPosition.squareLength() > 1);

   anPosition.scale(theFocus.getWidth(), theFocus.getHeight());
   anPosition.rotate(theFocus.getAngle());
   anPosition = anPosition + theFocus.getPosition();

   return anPosition;
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  createFocus
// Description:
//------------------------------------------------------------------------------
FocusPtr Emitter::createFocus() const
{
   FocusPtr anFocus = Focus::create((*this));

   anFocus->resetLife(getFocusTOL());
   anFocus->setWidth(getFocusWidth());
   anFocus->setHeight(getFocusHeight());
   anFocus->resetNP(getFocusNP());
   anFocus->setPPS(getFocusPPS());
   anFocus->addGroups(mpe::GROUP_A);

   return anFocus;
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  getID
// Description:
//------------------------------------------------------------------------------
EmitterID Emitter::getID() const
{
   return mID;
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  getID
// Description:
//------------------------------------------------------------------------------
System* Emitter::getSystem() const
{
   return mSystem;
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  getID
// Description:
//------------------------------------------------------------------------------
Real Emitter::getParticleSize() const
{
   return mGenParSize();
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  getID
// Description:
//------------------------------------------------------------------------------
Real Emitter::getParticleAngle() const
{
   return mGenParAngle();
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  getID
// Description:
//------------------------------------------------------------------------------
Real Emitter::getParticleLV() const
{
   return mGenParLV();
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  getID
// Description:
//------------------------------------------------------------------------------
Real Emitter::getParticleAV() const
{
   return mGenParAV();
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  getID
// Description:
//------------------------------------------------------------------------------
Real Emitter::getParticleTOL() const
{
   return mGenParTOL();
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  getID
// Description:
//------------------------------------------------------------------------------
Real Emitter::getFocusTOL() const
{
   return mGenFocTOL();
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  getID
// Description:
//------------------------------------------------------------------------------
Real Emitter::getFocusWidth() const
{
   return mGenFocWidth();
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  getID
// Description:
//------------------------------------------------------------------------------
Real Emitter::getFocusHeight() const
{
   return mGenFocHeight();
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  getID
// Description:
//------------------------------------------------------------------------------
Real Emitter::getFocusPPS() const
{
   return mGenFocPPS();
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  getID
// Description:
//------------------------------------------------------------------------------
Integer Emitter::getFocusNP() const
{
   return mGenFocNP();
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  setShape
// Description:
//------------------------------------------------------------------------------
void Emitter::setShape(Shape theShape)
{
   mShape = theShape;
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  getID
// Description:
//------------------------------------------------------------------------------
TextRect Emitter::getTextRect() const
{
   return mRect;
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  setDispersion
// Description:
//------------------------------------------------------------------------------
void Emitter::setDispersion(Dispersion theDispersion)
{
   mDispersion = theDispersion;
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  setTextRect
// Description:
//------------------------------------------------------------------------------
void Emitter::setTextRect(TextRect theTextRect)
{
   mRect = theTextRect;
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  setGeneratorParticleSize
// Description:
//------------------------------------------------------------------------------
void Emitter::setGeneratorParticleSize(Real theMin, Real theMax)
{
   mGenParSize = Generator<Real>::create(theMin,theMax);
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  setGeneratorParticleAngle
// Description:
//------------------------------------------------------------------------------
void Emitter::setGeneratorParticleAngle(Real theMin, Real theMax)
{
   mGenParAngle = Generator<Real>::create(theMin,theMax);
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  setGeneratorParticleLV
// Description:
//------------------------------------------------------------------------------
void Emitter::setGeneratorParticleLV(Real theMin, Real theMax)
{
   mGenParLV = Generator<Real>::create(theMin,theMax);
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  setGeneratorParticleAV
// Description:
//------------------------------------------------------------------------------
void Emitter::setGeneratorParticleAV(Real theMin, Real theMax)
{
   mGenParAV = Generator<Real>::create(theMin,theMax);
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  setGeneratorParticleTOL
// Description:
//------------------------------------------------------------------------------
void Emitter::setGeneratorParticleTOL(Real theMin, Real theMax)
{
   mGenParTOL = Generator<Real>::create(theMin,theMax);
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  setGeneratorFocusWidth
// Description:
//------------------------------------------------------------------------------
void Emitter::setGeneratorFocusWidth(Real theMin, Real theMax)
{
   mGenFocWidth = Generator<Real>::create(theMin,theMax);
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  setGeneratorFocusHeight
// Description:
//------------------------------------------------------------------------------
void Emitter::setGeneratorFocusHeight(Real theMin, Real theMax)
{
   mGenFocHeight = Generator<Real>::create(theMin,theMax);
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  setGeneratorFocusTOL
// Description:
//------------------------------------------------------------------------------
void Emitter::setGeneratorFocusTOL(Real theMin, Real theMax)
{
   mGenFocTOL = Generator<Real>::create(theMin,theMax);
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  setGeneratorFocusPPS
// Description:
//------------------------------------------------------------------------------
void Emitter::setGeneratorFocusPPS(Real theMin, Real theMax)
{
   mGenFocPPS = Generator<Real>::create(theMin,theMax);
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  setGeneratorFocusNP
// Description:
//------------------------------------------------------------------------------
void Emitter::setGeneratorFocusNP(Integer theMin, Integer theMax)
{
   mGenFocNP = Generator<Integer>::create(theMin,theMax);
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  setSystem
// Description:
//------------------------------------------------------------------------------
void Emitter::setSystem(System* theSystem)
{
   mSystem = theSystem;
}
////////////////////////////////////////////////////////////////////////////////
Emitter Emitter::DUMMY = Emitter("DUMMY");
Generator<Real> Emitter::sRealRandom {};
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

/// @file Particle.cpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2012-12-22

#include <MPE/classes/Particle.hpp>

namespace mpe
{
/*
*-------------------------------------------------------------------------------
*      Class:        Particle
*      Method:       Constructor
*      Description:
*-------------------------------------------------------------------------------
*/
Particle::Particle():
   Mortal(0)
{}
//------------------------------------------------------------------------------
//       Class:  Particle
//      Method:  Destructor
// Description:   
//------------------------------------------------------------------------------
Particle::~Particle() {}
//------------------------------------------------------------------------------
//      Class:        Particle
//      Method:       update
//      Description:
//------------------------------------------------------------------------------
void Particle::update(Real theElapsedTime)
{
   age(theElapsedTime);

   if( isAlive() )
   {
      mPosition += mLinearVelocity * theElapsedTime;
      mAngle += mAngularVelocity * theElapsedTime;
   }
}
//------------------------------------------------------------------------------
//       Class:  Particle
//      Method:  getWidth
// Description:  Width getter
//------------------------------------------------------------------------------
Real Particle::getSize() const
{
   return mSize;
}
//------------------------------------------------------------------------------
//       Class:  Particle
//      Method:  setSize
// Description:  A stupid method
//------------------------------------------------------------------------------
void Particle::setSize(Real theSize)
{
   mSize = theSize;
}
//------------------------------------------------------------------------------
//       Class:  Particle
//      Method:  getPosition
// Description:  Position getter
//------------------------------------------------------------------------------
Vec2 Particle::getPosition() const
{
   return mPosition;
}
//------------------------------------------------------------------------------
//       Class:  Particle
//      Method:  setPosition
// Description:  A stupid method 
//------------------------------------------------------------------------------
void Particle::setPosition(Vec2 thePosition)
{
   mPosition = thePosition;
}
//------------------------------------------------------------------------------
//       Class:  Particle
//      Method:  getAngle
// Description:  Angle getter
//------------------------------------------------------------------------------
Real Particle::getAngle() const
{
   return mAngle;
}
//------------------------------------------------------------------------------
//       Class:  Particle
//      Method:  setAngle
// Description:  A stupid method 
//------------------------------------------------------------------------------
void Particle::setAngle(Real theAngle)
{
   mAngle = theAngle;
}
//------------------------------------------------------------------------------
//      Class:        Particle
//      Method:       getLinearVelocity
//      Description:
//------------------------------------------------------------------------------
Vec2 Particle::getLinearVelocity() const
{
   return mLinearVelocity;
}
//------------------------------------------------------------------------------
//       Class:  Particle
//      Method:  setLinearVelocity
// Description:  setter
//------------------------------------------------------------------------------
void Particle::setLinearVelocity(Vec2 theLinearVelocity)
{
   mLinearVelocity = theLinearVelocity;
}
//------------------------------------------------------------------------------
//      Class:        Particle
//      Method:       getAngularVelocity
//      Description:
//------------------------------------------------------------------------------
Real Particle::getAngularVelocity() const
{
   return mAngularVelocity;
}
//------------------------------------------------------------------------------
//      Class:        Particle
//      Method:       setLinearVelocity
//      Description:
//------------------------------------------------------------------------------
void Particle::setAngularVelocity(Real theAngularVelocity)
{
   mAngularVelocity = theAngularVelocity;
}
//------------------------------------------------------------------------------
//      Class:        Particle
//      Method:       getTextRect
//      Description:
//------------------------------------------------------------------------------
TextRect Particle::getTextRect() const
{
   return mTextRect;
}
//------------------------------------------------------------------------------
//      Class:        Particle
//      Method:       setLinearVelocity
//      Description:
//------------------------------------------------------------------------------
void Particle::setTextRect(TextRect theTextRect)
{
   mTextRect = theTextRect;
}
//------------------------------------------------------------------------------
//       Class:  Particle
//      Method:  getColor
// Description:  A stupid method
//------------------------------------------------------------------------------
Color Particle::getColor() const
{
   return mColor;
}
//------------------------------------------------------------------------------
//       Class:  Particle
//      Method:  setColor
// Description:  setter
//------------------------------------------------------------------------------
void Particle::setColor(Color theColor)
{
   mColor = theColor;
}
//------------------------------------------------------------------------------
//       Class:  Particle
//      Method:  getGroups
// Description:  A stupid method 
//------------------------------------------------------------------------------
GroupID Particle::getGroups() const
{
   return mGroups;
}
//------------------------------------------------------------------------------
//       Class:  Particle
//      Method:  setGroups
// Description:  A stupid method 
//------------------------------------------------------------------------------
void Particle::setGroups(GroupID theGroups)
{
   mGroups = theGroups;
}
//--------------------------------------------------------------------------------------
//       Class:  Particle
//      Method:  belongToGroup
// Description:
//--------------------------------------------------------------------------------------
bool Particle::belongToGroup(const GroupID theGroups) const
{
   return mGroups & theGroups;
}
} /* end namespace */

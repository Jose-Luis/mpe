/// @file Affector.cpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2013-01-10

#include <MPE/classes/Affector.hpp>

namespace mpe
{
//------------------------------------------------------------------------------
//      Class:        Affector
//      Method:       constructor
//      Description:  
//------------------------------------------------------------------------------
Affector::Affector(Real theLifetime, Real theRadius, gt::Vec2D thePosition):
   Mortal(theLifetime),
   Position(thePosition)
{
   mSquareRadius = theRadius * theRadius;
}
//------------------------------------------------------------------------------
//      Class:        Affector
//      Method:       canAffect
//      Description:  
//------------------------------------------------------------------------------
bool Affector::canAffect(const gt::Vec2D& thePoint) const 
{
   return (mPosition - thePoint).squaremodule() < mSquareRadius;
}
}

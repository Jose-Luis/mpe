/// @file Affector.cpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2013-01-10

#include <MPE/classes/Affector.hpp>

namespace mpe
{
   IAffector::IAffector(Real theRadius, gt::Vec2D thePosition):
      mPosition(thePosition)
   {
      mSquareRadius = theRadius * theRadius;
   }

   bool IAffector::inRadius(const gt::Vec2D& thePoint)
   {
      return (mPosition - thePoint).squaremodule() < mSquareRadius;
   }
}

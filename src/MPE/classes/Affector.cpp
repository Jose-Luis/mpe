/// @file Affector.cpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2013-01-10

#include <MPE/classes/Affector.hpp>

namespace mpe
{
   IAffector::IAffector(Real theLifetime, Real theRadius, gt::Vec2D thePosition):
      Mortal(theLifetime),
      Position(thePosition)
   {
      mSquareRadius = theRadius * theRadius;
   }

   bool IAffector::canAffect(const gt::Vec2D& thePoint) const 
   {
      return (mPosition - thePoint).squaremodule() < mSquareRadius;
   }

   AccelarationAffector::AccelarationAffector(Real      theLifetime,
                                              Real      theRadius,
                                              gt::Vec2D thePosition,
                                              gt::Vec2D theAcceleration):
         mpe::IAffector(theLifetime,theRadius,thePosition),
         mAcceleration(theAcceleration)
   {}

   void AccelarationAffector::affect(Particle& theParticle)
   {
      theParticle.
   }
}

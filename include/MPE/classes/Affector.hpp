/// @file Affector.hpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2013-01-08

#include <MPE/classes/Particle.hpp>
#include <MPE/components/Mortal.hpp>
#include <MPE/components/Position.hpp>

namespace mpe
{

class IAffector: public Mortal, public Position
{
   public:
      /// @brief IAffector 
      /// @param theRadius
      IAffector(Real      theLifetime,
                Real      theRadius, 
                gt::Vec2D thePosition = gt::Vec2D(0,0));
      /// @brief affect    
      /// @param theParticle
      virtual void affect(Particle& theParticle,Real theElapsedTime) = 0;
      bool canAffect(const gt::Vec2D& thePoint) const;

   private:
      Real mSquareRadius;

};

class AccelarationAffector: public IAffector
{
   public:
      AccelarationAffector(Real      theLifetime,
                           Real      theRadius,
                           gt::Vec2D thePosition,
                           gt::Vec2D theAcceleration);
      
      void affect(Particle& theParticle, Real theElapsedTime);

   private:

         gt::Vec2D mAcceleration;
};

}

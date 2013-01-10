/// @file Affector.hpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2013-01-08

#include <MPE/classes/Particle.hpp>
#include <MPE/components/Mortal.hpp>

namespace mpe
{

class IAffector: public Mortal
{
   public:
      /// @brief IAffector 
      /// @param theRadius
      IAffector(Real theRadius, gt::Vec2D thePosition = gt::Vec2D(0,0));
      /// @brief affect    
      /// @param theParticle
      virtual void affect(Particle& theParticle) = 0;
      /// @brief move 
      /// @param theOffset
      void move(const gt::Vec2D& theOffset);
      /// @brief setPosition 
      /// @param thePosition
      void setPosition(const gt::Vec2D& thePosition);

   private:
      bool inRadius(const gt::Vec2D& thePoint);
      Real mSquareRadius;
      gt::Vec2D mPosition;

};
class AccelarationAffector: public IAffector
{

};

}

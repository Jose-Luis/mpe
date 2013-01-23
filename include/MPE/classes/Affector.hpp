/// @file Affector.hpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2013-01-08

#ifndef  AFFECTOR_INC
#define  AFFECTOR_INC

#include <MPE/classes/Particle.hpp>
#include <MPE/components/Mortal.hpp>

namespace mpe
{

class Affector: public Mortal
{
   public:
      /// @brief IAffector 
      /// @param theRadius
      Affector(Real      theLifetime);
      /// @brief affect    
      /// @param theParticle
      virtual void affect(Particle& theParticle,Real theElapsedTime) = 0;
};
}
#endif

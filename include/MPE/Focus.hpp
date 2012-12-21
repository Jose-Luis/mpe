/// @file Focus.hpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2012-12-21

#ifndef  FOCUS_INC
#define  FOCUS_INC

#include <GT/GT.hpp>
using namespace gt;

namespace mpe
{
class Focus
{
   public:



   private:

      bool     mAlive;            ///< Life state.
      Real     mWidth;            ///< Width.
      Real     mheight;           ///< Height.
      Angle    mAngle;            ///< Angle.
      Vec2D    mPosition;         ///< Position.
      Integer  mEmittedParticles; ///< Particles emitted by the focus.
      Real     mLifetime;         ///< The oldness of the focus.
};
}
#endif   

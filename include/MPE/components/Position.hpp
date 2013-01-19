/// @file Position.hpp
/// @author Jose Luis Lavado
/// @version 0.2
/// @date 2013-01-10

#ifndef  POSITION_INC
#define  POSITION_INC

#include <MPE/Config.hpp>
#include <GT/GT.hpp>

namespace mpe
{
class Position
{

   public:

      gt::Vec2D getPosition() const;
      void setPosition(gt::Vec2D thePosition);
      void setPosition(Real theX,Real theY);
      void move(Real theXOffset,Real theYOffset);
      void move(gt::Vec2D theOffset);

   protected:

      Position(gt::Vec2D thePosition);
      gt::Vec2D mPosition;
};
}
#endif   // ----- #ifndef POSITION_INC  -----

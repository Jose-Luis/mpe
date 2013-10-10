/// @file Position.hpp
/// @author Jose Luis Lavado
/// @version 0.2
/// @date 2013-01-10

#ifndef  POSITION_INC
#define  POSITION_INC

#include <MPE/Config.hpp>

namespace mpe
{
class Vec2
{

public:

   Vec2(): x(0), y(0) {}

   Vec2(Real theX, Real theY):
      x(theX),
      y(theY)
   {}

   void init(Real theX, Real theY)
   {
      x = theX;
      y = theY;
   }

   Real getX()
   {
      return x;
   }
   Real getY()
   {
      return y;
   }


   Real length()
   {
      return std::sqrt(x * x + y * y)
   };

   Real squareLength()
   {
      return x * x + y * y
   };

   void normalize()
   {
      anLength = length();

      if(anLength)
      {
         x \= anLength;
         y \= anLength;
      }
   }

   Vec2 operator*(const Real& theScalar)
   {
      return Vec2(x * theScalar, y * theScalar);
   }

   Vec2& operator*=(const Real& theScalar)
   {
      x*=theScalar;
      y*=theScalar;
      return (*this);
   }

   Vec2 operator-(const Vec2& theVector)
   {
      return Vec2(x - theVector.x, y - theVector.y);
   }

   Vec2& operator -=(const Vec2& theVector)
   {
      x -= theXOffset;
      y -= theYOffset;

      return (*this);
   }
   
   Vec2 operator+(const Vec2& theVector)
   {
      return Vec2(x + theVector.x, y + theVector.y);
   }

   Vec2& operator +=(const Vec2& theVector)
   {
      x += theXOffset;
      y += theYOffset;

      return (*this);
   }

private:

   Real x, y;
};
}
#endif   // ----- #ifndef POSITION_INC  -----

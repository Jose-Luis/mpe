/// @file Vec2D.hpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2012-12-18

#ifndef  VEC2D_INC
#define  VEC2D_INC

#include <cmath>
#include <GT/Angle.hpp>

namespace gt
{
////////////////////////////////////////////////////////////////////////////////
///  @class  Vec2D
///  @brief  Two dimentions vector
////////////////////////////////////////////////////////////////////////////////
class Vec2D
{
   public:

      //////////////////////////////////////////////////////////////////////////
      //                       LIFECYCLE   
      //////////////////////////////////////////////////////////////////////////
      Vec2D(Real theX, Real theY);                               // constructor
      ~Vec2D();                              // destructor
      //////////////////////////////////////////////////////////////////////////
      //                       METHODS   
      //////////////////////////////////////////////////////////////////////////
      /// @brief module 
      /// @return 
      Real module ();
      /// @brief normalize 
      /// @return 
      Vec2D& normalize(void);
      /// @brief rotate 
      /// @param angle
      /// @return 
      Vec2D& rotate(Real theAngle);
      /// @brief rotate 
      /// @param theAngle
      /// @return 
      Vec2D& rotate(Angle theAngle);
      //////////////////////////////////////////////////////////////////////////
      //                       ACCESORS   
      //////////////////////////////////////////////////////////////////////////
      /// @brief getX 
      /// @return 
      inline Real getX ( ) const {return mX;};
      /// @brief getY 
      /// @return 
      inline Real getY ( ) const {return mY;};
      //////////////////////////////////////////////////////////////////////////
      //                       MUTATORS   
      //////////////////////////////////////////////////////////////////////////
      inline void setX ( Real theX ) {mX = theX;};
      inline void setY ( Real theY ) {mY = theY;};
      //////////////////////////////////////////////////////////////////////////
      //                       OPERATORS   
      //////////////////////////////////////////////////////////////////////////

      Vec2D& operator +=(const Vec2D& theVector);
      Vec2D& operator -=(const Vec2D& theVector);
      Vec2D& operator *=(Real theFloat);
      Vec2D& operator /=(Real theFloat);
      Vec2D operator -(void) const;
      Vec2D operator +(const Vec2D& theVector) const;
      Vec2D operator -(const Vec2D& theVector) const;
      Vec2D operator *(Real theFloat) const;
      Vec2D operator /(Real theFloat) const;
      Real operator *(const Vec2D& theVector) const;
      bool operator ==(const Vec2D& theVector) const;
      bool operator !=(const Vec2D& theVector) const;
   protected:

   private:
      
      //////////////////////////////////////////////////////////////////////////
      //                       DATA MEMBERS   
      //////////////////////////////////////////////////////////////////////////
      Real mX;
      Real mY;
}; 
////////////////////////////////////////////////////////////////////////////////
//  END OF CLASS Vec2D 
////////////////////////////////////////////////////////////////////////////////
}
#endif  




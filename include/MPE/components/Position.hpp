/// @file Position.hpp
/// @author Jose Luis Lavado
/// @version 0.2
/// @date 2013-01-10

#ifndef  POSITION_INC
#define  POSITION_INC

#include <MPE/Config.hpp>
#include <GT/GT.hpp>

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
//------------------------------------------------------------------------------
//      Class:        Position
//      Method:       getPosition
//      Description:  
//------------------------------------------------------------------------------
inline gt::Vec2D Position::getPosition() const 
{
   return mPosition;
}
//------------------------------------------------------------------------------
//      Class:        Position
//      Method:       setPosition
//      Description:  
//------------------------------------------------------------------------------
inline void Position::setPosition(gt::Vec2D thePosition)
{
   mPosition=thePosition;
}

//--------------------------------------------------------------------------------------
//      Class:        Position
//      Method:       move
//      Description:  
//--------------------------------------------------------------------------------------
inline void Position::move(gt::Vec2D theOffset)
{
   mPosition += theOffset;
}
//------------------------------------------------------------------------------
//      Class:        Position
//      Method:       setPosition
//      Description:  
//------------------------------------------------------------------------------
inline void Position::setPosition(Real theX,Real theY)
{
   mPosition.x = theX;
   mPosition.y = theY;
}

//--------------------------------------------------------------------------------------
//      Class:        Position
//      Method:       move
//      Description:  
//--------------------------------------------------------------------------------------
inline void Position::move(Real theXOffset,Real theYOffset)
{
   mPosition.x += theXOffset;
   mPosition.y += theYOffset;
}
#endif   // ----- #ifndef POSITION_INC  -----

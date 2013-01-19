
#include<MPE/components/Position.hpp>

namespace mpe
{
//------------------------------------------------------------------------------
//      Class:        Position
//      Method:       getPosition
//      Description:  
//------------------------------------------------------------------------------
Position::Position(gt::Vec2D thePosition):
   mPosition(thePosition)
{}
//------------------------------------------------------------------------------
//      Class:        Position
//      Method:       getPosition
//      Description:  
//------------------------------------------------------------------------------
gt::Vec2D Position::getPosition() const 
{
   return mPosition;
}
//------------------------------------------------------------------------------
//      Class:        Position
//      Method:       setPosition
//      Description:  
//------------------------------------------------------------------------------
void Position::setPosition(gt::Vec2D thePosition)
{
   mPosition=thePosition;
}

//------------------------------------------------------------------------------
//      Class:        Position
//      Method:       move
//      Description:  
//------------------------------------------------------------------------------
void Position::move(gt::Vec2D theOffset)
{
   mPosition += theOffset;
}
//------------------------------------------------------------------------------
//      Class:        Position
//      Method:       setPosition
//      Description:  
//------------------------------------------------------------------------------
void Position::setPosition(Real theX,Real theY)
{
   mPosition.x = theX;
   mPosition.y = theY;
}

//------------------------------------------------------------------------------
//      Class:        Position
//      Method:       move
//      Description:  
//------------------------------------------------------------------------------
void Position::move(Real theXOffset,Real theYOffset)
{
   mPosition.x += theXOffset;
   mPosition.y += theYOffset;
}
}

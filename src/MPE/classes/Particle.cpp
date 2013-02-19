/// @file Particle.cpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2012-12-22

#include <MPE/classes/Particle.hpp>

namespace mpe
{
//------------------------------------------------------------------------------
//      Class:        Particle
//      Method:       Constructor
//      Description:  
//------------------------------------------------------------------------------
Particle::Particle
   (
    const sf::Texture& theTexture,
    gt::Vec2D          thePosition,
    Real               theAngle, 
    gt::Vec2D          theScale,
    gt::Vec2D          theLinearVelocity,
    Real               theAngularVelocity, 
    Real               theTTL,
    sf::Color          theColor,
    GroupID            theGroups
   ):
      Mortal(theTTL),
      Position(thePosition),
      mSprite(theTexture),
      mAngle(theAngle),
      mScale(theScale),
      mLinearVelocity(theLinearVelocity),
      mAngularVelocity(theAngularVelocity),
      mColor(theColor),
      mGroups(theGroups)
{
   mSprite.setOrigin(theTexture.getSize().x/2,theTexture.getSize().y/2);
}
//------------------------------------------------------------------------------
//      Class:        Particle
//      Method:       Destructor
//      Description:  
//------------------------------------------------------------------------------
Particle::~Particle(){}
//------------------------------------------------------------------------------
//      Class:        Particle
//      Method:       update
//      Description:  
//------------------------------------------------------------------------------
void Particle::update(Real theElapsedTime)
{
   age(theElapsedTime);
   if( isAlive() )
   {
      move( mLinearVelocity * theElapsedTime );
      mAngle += mAngularVelocity * theElapsedTime;
   }
}
//------------------------------------------------------------------------------
//      Class:        Particle
//      Method:       getLinearVelocity
//      Description:  
//------------------------------------------------------------------------------
 gt::Vec2D Particle::getLinearVelocity() const 
{
   return mLinearVelocity;
}
//------------------------------------------------------------------------------
//      Class:        Particle
//      Method:       setLinearVelocity
//      Description:  
//------------------------------------------------------------------------------
 void Particle::setLinearVelocity(gt::Vec2D theLinearVelocity)
{
   mLinearVelocity=theLinearVelocity;
}
//------------------------------------------------------------------------------
//      Class:        Particle
//      Method:       getSprite
//      Description:  
//------------------------------------------------------------------------------
 const sf::Sprite& Particle::getSprite() const
{
   return mSprite;
}
//--------------------------------------------------------------------------------------
//       Class:  Particle
//      Method:  modifyColor
// Description:  
//--------------------------------------------------------------------------------------
void Particle::modifyColor(int theR,int theG,int theB)
{
   mColor.r += theR;
   mColor.g += theG;
   mColor.b += theB;
   mSprite.setColor(mColor);
}
//--------------------------------------------------------------------------------------
//       Class:  Particle
//      Method:  modifyAlpha
// Description:  
//--------------------------------------------------------------------------------------
void Particle::modifyAlpha ( int theAlphaInc )
{
   int anAlpha = mColor.a + theAlphaInc;
   if (anAlpha > 255)
      anAlpha = 255;
   else if ( anAlpha < 0)
      anAlpha = 0;
   mColor.a = anAlpha;
   mSprite.setColor(mColor);
}
//--------------------------------------------------------------------------------------
//       Class:  Particle
//      Method:  belongToGroup
// Description:  
//--------------------------------------------------------------------------------------
bool Particle::belongToGroup(GroupID theGroups)
{
   return mGroups & theGroups;
}
}
////------------------------------------------------------------------------------
////      Class:        Particle
////      Method:       setSpritePosition
////      Description:  
////------------------------------------------------------------------------------
 //void Particle::setSpritePosition(Real theXFactor,Real theYFactor)
//{
   //mSprite.setRotation(mAngle);
   //mSprite.setPosition(mPosition.x*theXFactor,mPosition.y*theYFactor);
//}


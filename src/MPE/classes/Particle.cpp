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
    gt::Vec2D          theLinearVelocity,
    Real               theAngularVelocity, 
    Real               theTTL,
    sf::Color          theColor 
   ):
      Mortal(theTTL),
      Position(thePosition),
      mSprite(theTexture),
      mAngle(theAngle),
      mLinearVelocity(theLinearVelocity),
      mAngularVelocity(theAngularVelocity)
{
   mSprite.setColor(theColor);
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
//      Method:       setSpritePosition
//      Description:  
//------------------------------------------------------------------------------
 void Particle::setSpritePosition(Real theXFactor,Real theYFactor)
{
   mSprite.setRotation(mAngle);
   mSprite.setPosition(mPosition.x*theXFactor,mPosition.y*theYFactor);
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
}
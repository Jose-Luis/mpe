/// @file Particle.cpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2012-12-22

#include <MPE/Particle.hpp>

namespace mpe
{
   //---------------------------------------------------------------------------
   //      Class:        Particle
   //      Method:       Constructor
   //      Description:  
   //---------------------------------------------------------------------------
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
         mAlive(true),
         mSprite(theTexture),
         mLinearVelocity(theLinearVelocity),
         mAngularVelocity(theAngularVelocity),
         mTOL(theTTL)
      {
         mSprite.setPosition(thePosition.x,thePosition.y);
         mSprite.setRotation(theAngle);
         mSprite.setColor(theColor);
      }
   //---------------------------------------------------------------------------
   //      Class:        Particle
   //      Method:       Destructor
   //      Description:  
   //---------------------------------------------------------------------------
   Particle::~Particle(){}
   //---------------------------------------------------------------------------
   //      Class:        Particle
   //      Method:       update
   //      Description:  
   //---------------------------------------------------------------------------
   void Particle::update(Real theElapsedTime)
   {
      mTOL -= theElapsedTime;

      if( 0 > mTOL )
      {
         mAlive = false;
      }
      else
      {
         mSprite.move(mLinearVelocity.x*theElapsedTime,
                      mLinearVelocity.y*theElapsedTime);
         mSprite.rotate(mAngularVelocity*theElapsedTime);
      }
   }
}

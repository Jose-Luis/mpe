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
       sf::Texture& theTexture,
       gt::Vec2D    thePosition,
       Real         theAngle, 
       gt::Vec2D    theLinearVelocity,
       Real         theAngularVelocity, 
       sf::Color    theColor, 
       Real         theTTL
      ):
         mAlive(true),
         mSprite(theTexture),
         mAngularVelocity(theAngularVelocity),
         mLinearVelocity(theLinearVelocity),
         mTOL(theTTL)
      {
         mSprite.setPosition(thePosition.x,thePosition.y);
         mSprite.setColor(theColor);
         mSprite.setRotation(theAngle);
      }
   //---------------------------------------------------------------------------
   //      Class:        Particle
   //      Method:       Destructor
   //      Description:  
   //---------------------------------------------------------------------------
   Particle::~Particle(){};
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

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
         mPosition(thePosition),
         mAngle(theAngle),
         mLinearVelocity(theLinearVelocity),
         mAngularVelocity(theAngularVelocity),
         mTOL(theTTL)
      {
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
         mPosition += mLinearVelocity * theElapsedTime;
         mAngle += mAngularVelocity * theElapsedTime;
      }
   }
}



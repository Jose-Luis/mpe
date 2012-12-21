// =============================================================================
// 
//       Filename:  Particle.cpp
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  17/12/12 10:10:56
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Jose Luis Lavado (), joseluislavado@gmail.com
//        Company:  
// 
// =============================================================================

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
       sf::Vector2f thePosition,
       Real         theAngle, 
       sf::Vector2f theLinearVelocity,
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
         mSprite.move( mLinearVelocity.x*theElapsedTime ,
               mLinearVelocity.y*theElapsedTime );
         mSprite.rotate(mAngularVelocity*theElapsedTime);
      }
   }
   //------------------------------------------------------------------------------
   //       Class:  Particle
   //      Method:  isAlive
   // Description:  
   //------------------------------------------------------------------------------
   inline bool Particle::isAlive() const 
   {
      return mAlive;
   }

   //------------------------------------------------------------------------------
   //       Class:  Particle
   //      Method:  getSprite
   // Description:  Getter
   //------------------------------------------------------------------------------
   inline const sf::Sprite& Particle::getSprite (  ) const
   {
      return mSprite;
   }
   //------------------------------------------------------------------------------
   //       Class:  Particle
   //      Method:  setSprite
   // Description:  Setter
   //------------------------------------------------------------------------------
   inline void Particle::setSprite ( sf::Sprite value )
   {
      mSprite = value;
      return;
   }
   //---------------------------------------------------------------------------
   //      Class:        Particle
   //      Method:       getTOL
   //      Description:  
   //---------------------------------------------------------------------------
   inline Real Particle::getTOL() const {return mTOL;}
}

// =============================================================================
// 
//       Filename:  Particle.hpp
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  17/12/12 10:12:32
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Jose Luis Lavado (), joseluislavado@gmail.com
//        Company:  
// 
// =============================================================================

#ifndef  PARTICLE_INC
#define  PARTICLE_INC

#include <SFML/Graphics.hpp>
#include <MPE/Config.hpp>

namespace MPE
{
   class Particle
   {
      public:
         Particle
            (
             sf::Texture& theTexture, 
             sf::Vector2f thePosition, 
             Real         theAngle, 
             sf::Vector2f theLinearVelocity, 
             Real         theAngularVelocity, 
             sf::Color    theColor, 
             Real         theTOL
             );

         ~Particle();

         void                       update(Real theElapsedTime);
         inline Real                getTOL() const;
         inline bool                isAlive() const;
         inline const sf::Sprite&   getSprite ( ) const;
         inline void                setSprite ( sf::Sprite value );

      private:
         bool           mAlive;
         sf::Sprite     mSprite;
         sf::Vector2f   mLinearVelocity;
         Real           mAngularVelocity;
         Real           mTOL;
         //sf::Color mColorVelocity;
   };
}

#endif 

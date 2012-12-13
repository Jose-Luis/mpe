#ifndef  PARTICLE_INC
#define  PARTICLE_INC

#include <SFML/Graphics.hpp>
#include <MPE/Config.hpp>

namespace MPE
{
   class Particle
   {
      public:
         Particle(sf::Texture& theTexture, sf::Vector2f thePosition, sf::Vector2f theLinearVelocity, Real theAngularVelocity,  sf::Color theColor, Real theTTL):
            mSprite(theTexture),
            mAngularVelocity(theAngularVelocity),
            mLinearVelocity(theLinearVelocity),
            mTTL(theTTL)
      {
         mSprite.setPosition(thePosition.x,thePosition.y);
         mSprite.setColor(theColor);
      }
         ~Particle();

         void update(Real theElapsedTime)
         {
            mTTL -= theElapsedTime;
            mSprite.move(mLinearVelocity.x*theElapsedTime,mLinearVelocity.y*theElapsedTime);
            mSprite.rotate(mAngularVelocity*theElapsedTime);
         }
         
         Real inline getTTL() const {return mTTL;};

      private:
         sf::Sprite mSprite;
         sf::Vector2f mLinearVelocity;
         Real mAngularVelocity;
         //sf::Color mColorVelocity;
         Real mTTL;
   };
}
#endif   // ----- #ifndef PARTICLE_INC  -----

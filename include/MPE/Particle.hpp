#ifndef  PARTICLE_INC
#define  PARTICLE_INC

#include <SFML/Graphics.hpp>

namespace MPE
{
   class Particle
   {
      public:
         Particle(sf::Texture& theTexture, sf::Vector2f thePosition, sf::Vector2f theLinearVelocity, float theAngularVelocity,  sf::Color theColor, float theTTL):
            mSprite(theTexture),
            mAngularVelocity(theAngularVelocity),
            mLinearVelocity(theLinearVelocity),
            mTTL(theTTL)
      {
         mSprite.setPosition(thePosition.x,thePosition.y);
         mSprite.setColor(theColor);
      }
         ~Particle();

         void update(float theElapsedTime)
         {
            mTTL -= theElapsedTime;
            mSprite.move(mLinearVelocity.x*theElapsedTime,mLinearVelocity.y*theElapsedTime);
            mSprite.rotate(mAngularVelocity*theElapsedTime);
         }
         
         float inline getTTL() const {return mTTL;};

      private:
         sf::Sprite mSprite;
         sf::Vector2f mLinearVelocity;
         float mAngularVelocity;
         //sf::Color mColorVelocity;
         float mTTL;
   };
}
#endif   // ----- #ifndef PARTICLE_INC  -----

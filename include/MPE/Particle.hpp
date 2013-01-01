/// @file Particle.hpp
/// @brief  
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2012-12-18

#ifndef  PARTICLE_INC
#define  PARTICLE_INC

#include <SFML/Graphics.hpp>
#include <GT/GT.hpp>

namespace mpe
{
/// @class Particle
/// @brief Particle 
class Particle
{
   public:
      /// @brief  Constructor
      /// @param theTexture
      /// @param thePosition
      /// @param theAngle
      /// @param theLinearVelocity
      /// @param theAngularVelocity
      /// @param theColor
      Particle
         (
          const sf::Texture& theTexture, 
          gt::Vec2D          thePosition, 
          Real               theAngle, 
          gt::Vec2D          theLinearVelocity, 
          Real               theAngularVelocity, 
          Real               theTOL,
          sf::Color          theColor=sf::Color(255,255,255) 
          );
      /// @brief ~Particle 
      ~Particle();
      /// @brief update 
      /// @param theElapsedTime
      void update(Real theElapsedTime);
      /// @brief isAlive 
      /// @return 
      bool isAlive();
      /// @brief getSprite 
      /// @return 
      const sf::Sprite& getSprite() const;
      /// @brief setSpritePosition 
      /// @param theXFactor
      /// @param theYFactor
      void setSpritePosition(Real theXFactor,Real theYFactor);
   private:
      bool        mAlive;
      sf::Sprite  mSprite;
      gt::Vec2D   mPosition;
      Real        mAngle;
      gt::Vec2D   mLinearVelocity;
      Real        mAngularVelocity;
      Real        mTOL;
      //sf::Color mColorVelocity;
};
inline bool Particle::isAlive()
{
   return mAlive;
}
inline void Particle::setSpritePosition(Real theXFactor,Real theYFactor)
{
   mSprite.setPosition(mPosition.x*theXFactor,mPosition.y*theYFactor);
   mSprite.setRotation(mAngle);
}
inline const sf::Sprite& Particle::getSprite() const
{
   return mSprite;
}
}
#endif 
// Copyright (C) 
// 
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.


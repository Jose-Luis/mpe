/// @file Particle.hpp
/// @brief  
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2012-12-18

#ifndef  PARTICLE_INC
#define  PARTICLE_INC

#include <SFML/Graphics.hpp>
#include <GT/GT.hpp>
#include <MPE/Config.hpp>
#include <MPE/components/Mortal.hpp>
#include <MPE/components/Position.hpp>

namespace mpe
{
/// @class Particle
/// @brief Particle 
class Particle: public Mortal, public Position
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
          gt::Vec2D          theScale,
          gt::Vec2D          theLinearVelocity, 
          Real               theAngularVelocity, 
          Real               theTLL,
          sf::Color          theColor=sf::Color(255,255,255,255),
          GroupID            theGroups = mpe::NO_GROUP
          );
      /// @brief ~Particle 
      ~Particle();
      /// @brief update 
      /// @param theElapsedTime
      void update(Real theElapsedTime);
      /// @brief getSprite 
      /// @return 
      const sf::Sprite& getSprite() const;
      /// @brief setSpriteProperties
      /// @param theXFactor
      /// @param theYFactor
      inline void setSpriteProperties(Real theXFactor,Real theYFactor)
      {
         mSprite.setRotation(mAngle);
         mSprite.setPosition(mPosition.x*theXFactor,mPosition.y*theYFactor);
         mSprite.setScale(mScale.x,mScale.y);
      }
      /// @brief setColor 
      /// @param theColor
      void setColor(sf::Color theColor);
      /// @brief modifyColor 
      /// @param theR
      /// @param theG
      /// @param theB
      /// @param theA
      void modifyColor(int theR,int theG,int theB);
      /// @brief modifyAlpha 
      /// @param theAlphaInc
      void modifyAlpha(int theAlphaInc);
      /// @brief setLinearVelocity 
      /// @param theLinearVelocity
      void setLinearVelocity(gt::Vec2D theLinearVelocity);
      /// @brief getLinearVelocity 
      /// @return 
      gt::Vec2D getLinearVelocity() const;
      /// @brief belongToGroup 
      /// @param theGroup
      /// @return 
      bool belongToGroup(GroupID theGroups);
   private:
      sf::Sprite  mSprite;
      Real        mAngle;
      gt::Vec2D   mScale;
      gt::Vec2D   mLinearVelocity;
      Real        mAngularVelocity;
      sf::Color   mColor;
      GroupID     mGroups;
};
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


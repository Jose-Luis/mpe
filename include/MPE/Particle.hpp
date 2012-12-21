/// @file Particle.hpp
/// @brief  
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2012-12-18

#ifndef  PARTICLE_INC
#define  PARTICLE_INC

#include <SFML/Graphics.hpp>
#include <MPE/Config.hpp>

namespace mpe
{
class Particle
{
   public:
      //////////////////////////////////////////////////////////////////////////
      /// @brief  Constructor
      /// @param theTexture
      /// @param thePosition
      /// @param theAngle
      /// @param theLinearVelocity
      /// @param theAngularVelocity
      /// @param theColor
      //////////////////////////////////////////////////////////////////////////
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
      //////////////////////////////////////////////////////////////////////////
      /// @brief update 
      /// @param theElapsedTime
      //////////////////////////////////////////////////////////////////////////
      void                       update(Real theElapsedTime);
      //////////////////////////////////////////////////////////////////////////
      /// @brief getTOL 
      /// @return 
      //////////////////////////////////////////////////////////////////////////
      inline Real                getTOL() const;
      //////////////////////////////////////////////////////////////////////////
      /// @brief isAlive 
      /// @return 
      //////////////////////////////////////////////////////////////////////////
      inline bool                isAlive() const;
      //////////////////////////////////////////////////////////////////////////
      /// @brief getSprite 
      /// @return 
      //////////////////////////////////////////////////////////////////////////
      inline const sf::Sprite&   getSprite ( ) const;
      //////////////////////////////////////////////////////////////////////////
      /// @brief setSprite 
      /// @param value
      //////////////////////////////////////////////////////////////////////////
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


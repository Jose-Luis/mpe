/// @file Particle.hpp
/// @brief
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2012-12-18

#ifndef  PARTICLE_INC
#define  PARTICLE_INC

#include <MPE/Config.hpp>
#include <MPE/classes/Mortal.hpp>
#include <MPE/classes/Vec2.hpp>

namespace mpe
{
/// @class Particle
/// @brief Particle
class Particle: public Mortal
{
public:
   /// @brief Particle
   Particle();
   /// @brief
   /// @param theTLL
   /// @param theWidth
   /// @param theHeight
   /// @param thePosition
   /// @param theAngle
   /// @param theLinearVelocity
   /// @param theAngularVelocity
   /// @param theColor
   /// @param theGroups
   /// @return
   Particle(Real    theTLL,
            Real    theWidth,
            Real    theHeight,
            Vec2    thePosition,
            Real    theAngle,
            Vec2    theLinearVelocity,
            Real    theAngularVelocity,
            TextRect theTextRect,
            Color   theColor = Color{255, 255, 255, 255},
            GroupID theGroups = mpe::NO_GROUP);
   /// @brief ~Particle
   ~Particle();
   /// @brief update
   /// @param theElapsedTime
   void init(Real    theTLL,
             Real    theWidth,
             Real    theHeight,
             Vec2    thePosition,
             Real    theAngle,
             Vec2    theLinearVelocity,
             Real    theAngularVelocity,
             TextRect theTextRect,
             Color   theColor = Color{255, 255, 255, 255},
             GroupID theGroups = mpe::NO_GROUP);

   void update(Real theElapsedTime);

   Real getWidth() const;
   void setWidth(Real theWidth);

   Real getHeight() const;
   void setHeight(Real theHeight);

   Vec2 getPosition() const;

   Real getAngle() const;

   Vec2 getLinearVelocity() const;
   void setLinearVelocity(Vec2 theLinearVelocity);

   Real getAngularVelocity() const;
   void setAngularVelocity(Real theAngularVelocity);

   TextRect getTextRect() const;
   void setTextRect(TextRect theTextRect);

   Color getColor() const;
   void  setColor(Color theColor);

   bool belongToGroup(const GroupID theGroups) const;

private:

   Real      mWidth;
   Real      mHeight;
   Vec2      mPosition;
   Real      mAngle;
   Vec2      mLinearVelocity;
   Real      mAngularVelocity;
   TextRect  mTextRect;
   Color     mColor;
   GroupID   mGroups;
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


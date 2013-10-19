////////////////////////////////////////////////////////////////////////////////
/// @file Emitter.hpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2012-12-17
////////////////////////////////////////////////////////////////////////////////

#ifndef  EMITTER_INC
#define  EMITTER_INC

#include <cmath>
#include <random>
#include <MPE/Config.hpp>
#include <MPE/classes/Focus.hpp>
#include <MPE/classes/System.hpp>
#include <MPE/classes/Generator.hpp>

namespace mpe
{
/// @class Emitter
/// @brief Emitter is a server class for the flyweight client Focus.
class Emitter
{
public:
   static Emitter DUMMY;
   //                      INNER TYPES
   //////////////////////////////////////////////////////////////////////////
   /// @enum Shape
   /// @brief The Shape of the emitter.
   enum Shape {RECTANGLE, CIRCLE};
   /// @enum Dispersion
   /// @brief The particle dispersion performed by the emitter.
   enum Dispersion {LINEAR, RADIAL, REFLECT, RANDOM, STATIC};
   //                      LIFE CYCLE
   //////////////////////////////////////////////////////////////////////////
   /// @brief Emitter
   /// @param theID
   Emitter(EmitterID theID);
   /// @brief createFocus
   /// @return
   FocusPtr createFocus(Vec2 thePosition,
                        Real theAngle,
                        GroupID   theGroups = mpe::NO_GROUP) const;
   /// @brief Generate a random position inside the Shape of the emitter.
   /// The position is transformed by the system factor member to scale it
   /// to the world coordinates.
   /// @param theFocus
   /// @returns The initial position of the particle.
   Vec2 generatePosition(const Focus& theFocus) const;
   /// @brief Generate a velocity depending of the emitter dispertion.
   /// @param theFocus
   /// @param theParticlePosition
   /// @returns The particle velocity.
   Vec2 generateVelocity(const Focus& theFocus,
                         const Vec2&  theParticlePosition) const;
   //    ACCESSORS AND MUTATORS
   //////////////////////////////////////////////////////////////////////////
   /// @brief getID
   /// @return
   EmitterID getID() const;
   /// @brief getSystem
   /// @return
   System* getSystem() const;
   /// @brief getTextRect
   /// @return
   TextRect getTextRect() const;
   /// @brief getParticleWidth
   /// @return
   Real getParticleSize() const;
   /// @brief getFocusAngle
   /// @return
   Real getParticleAngle() const;
   /// @brief getParticleLV
   /// @return
   Real getParticleLV() const;
   /// @brief getParticleAV
   /// @return
   Real getParticleAV() const;
   /// @brief getParticleTOL
   /// @return
   Real getParticleTOL() const;
   /// @brief getFocusTOL
   /// @return
   Real getFocusTOL() const;
   /// @brief getFocusHeight
   /// @return
   Real getFocusHeight() const;
   /// @brief getFocusWidth
   /// @return
   Real getFocusWidth() const;
   /// @brief getFocusPPS
   /// @return
   Real getFocusPPS() const;
   /// @brief getFocusNP
   /// @return
   Integer getFocusNP() const;
   /// @brief setShape
   /// @param theShape
   void setShape(Shape theShape);
   /// @brief getDispersion
   /// @return
   void setDispersion(Dispersion theDispersion);
   /// @brief setRangeParticleWidth
   /// @param theRangeParticleWidth
   void setRangeParticleSize(Real theMin, Real theMax);
   /// @brief setRangeParticleAngle
   /// @param theMin
   /// @param theMax
   void setRangeParticleAngle(Real theMin, Real theMax);
   /// @brief setRangeParticlePOW
   /// @param theRangeParticlePOW
   void setRangeParticleLV(Real theMin, Real theMax);
   /// @brief setRangeParticleAV
   /// @param theMin
   /// @param theMax
   void setRangeParticleAV(Real theMin, Real theMax);
   /// @brief setRangeParticleTOL
   /// @param theRangeParticleTOL
   void setRangeParticleTOL(Real theMin, Real theMax);
   /// @brief setRangeFocusTOL
   /// @param theRangeFocusTOL
   void setRangeFocusTOL(Real theMin, Real theMax);
   /// @brief setRangeFocusWidth
   /// @param theRangeFocusWidth
   void setRangeFocusWidth(Real theMin, Real theMax);
   /// @brief setRangeFocusHeight
   /// @param theRangeFocusHeight
   void setRangeFocusHeight(Real theMin, Real theMax);
   /// @brief setRangeFocusPPS
   /// @param theRangeFocusPPS
   void setRangeFocusPPS(Real theMin, Real theMax);
   /// @brief setRangeFocusNP
   /// @param theRangeFocusNP
   void setRangeFocusNP(Integer theMin, Integer theMax);
   /// @brief setSystem
   /// @param theSystem
   void setSystem(System* theSystem);
   /// @brief setTextRect
   /// @param theTextRect
   void setTextRect(TextRect theTextRect);
private:
   //                      VARIABLES
   //////////////////////////////////////////////////////////////////////////
   EmitterID   mID;            ///< Unique EmitterID for the emitter.
   System*     mSystem;
   Shape       mShape;         ///< The emitter's shape.
   Dispersion  mDispersion;    ///< Type of paricles' dispersion.
   TextRect    mRect;
   Generator<Real> mRP_TOL;   ///< Range of particles lifetime.
   Generator<Real> mRP_Size; ///< Range of paricles width.
   Generator<Real> mRP_Angle; ///< Range of particles angle.
   Generator<Real> mRP_LV;    ///< Range of paricles impulsion.
   Generator<Real> mRP_AV;    ///< Range of particles angular velocity.
   Generator<Real> mRF_Width; ///< Range of focus width.
   Generator<Real> mRF_Height;///< Range of focus height.
   Generator<Real> mRF_TOL;   ///< Range of focus time of life.
   Generator<Real> mRF_PPS;   ///< Range of focus particles per second.
   Generator<Integer> mRF_NP; ///< Range of focus number of particles.

   static Generator<Real> sRealRandom;

};
//                END OF THE EMITTER CLASS
////////////////////////////////////////////////////////////////////////////////
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

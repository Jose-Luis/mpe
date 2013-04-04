////////////////////////////////////////////////////////////////////////////////
/// @file Emitter.hpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2012-12-17
////////////////////////////////////////////////////////////////////////////////

#ifndef  EMITTER_INC
#define  EMITTER_INC

#include <SFML/Graphics.hpp>
#include <GT/GT.hpp>
#include <MPE/Config.hpp>
#include <MPE/classes/Focus.hpp>
#include <MPE/classes/System.hpp>

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
      enum Shape{RECTANGLE,CIRCLE};
      /// @enum Dispersion
      /// @brief The particle dispersion performed by the emitter. 
      enum Dispersion{LINEAR,RADIAL,REFLECT,RANDOM,STATIC};
      //                      LIFE CYCLE
      //////////////////////////////////////////////////////////////////////////
      /// @brief Emitter 
      /// @param theID
      Emitter(EmitterID theID);
      /// @brief createFocus 
      /// @return 
      FocusPtr createFocus(gt::Vec2D thePosition,
                           Real      theAngle,
                           GroupID   theGroups = mpe::NO_GROUP) const;
      /// @brief Generate a random position inside the Shape of the emitter.
      /// The position is transformed by the system factor member to scale it 
      /// to the world coordinates.
      /// @param theFocus
      /// @returns The initial position of the particle.   
      gt::Vec2D generatePosition(const Focus& theFocus) const;
      /// @brief Generate a velocity depending of the emitter dispertion.
      /// @param theFocus
      /// @param theParticlePosition
      /// @returns The particle velocity.
      gt::Vec2D generateVelocity(const Focus&     theFocus,
                                 const gt::Vec2D& theParticlePosition) const;
      //    ACCESSORS AND MUTATORS
      //////////////////////////////////////////////////////////////////////////
      /// @brief getID 
      /// @return 
      EmitterID getID() const;
      /// @brief getSystem
      /// @return 
      System* getSystem() const;
      /// @brief getTexRect
      /// @return
      sf::Rect<int> getTexRect() const;
      /// @brief getParticlePOW 
      /// @return 
      Real getParticlePOW() const;
      /// @brief getParticleTOL 
      /// @return 
      Real getParticleTOL() const;
      /// @brief getFocusTOL 
      /// @return 
      Real getParticleAngle() const;
      /// @brief getParticleAngle 
      /// @return 
      Real getParticleScale() const;
      /// @brief getParticleAV 
      /// @return 
      Real getParticleAV() const;
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
      /// @brief setTexRect
      /// @param theTexRect
      void setTexRect(sf::Rect<int> theTexRect);
      /// @brief setRangeParticlePOW 
      /// @param theRangeParticlePOW
      void setRangeParticlePOW(Real theMin,Real theMax);
      /// @brief setRangeParticleTOL 
      /// @param theRangeParticleTOL
      void setRangeParticleTOL(Real theMin,Real theMax);
      /// @brief setRangeParticleAngle 
      /// @param theMin
      /// @param theMax
      void setRangeParticleAngle(Real theMin,Real theMax);
      /// @brief setRangeParticleScale 
      /// @param theMin
      /// @param theMax
      void setRangeParticleScale(Real theMin,Real theMax);
      /// @brief setRangeParticleAV 
      /// @param theMin
      /// @param theMax
      void setRangeParticleAV(Real theMin,Real theMax);
      /// @brief setRangeFocusTOL 
      /// @param theRangeFocusTOL
      void setRangeFocusTOL(Real theMin,Real theMax);
      /// @brief setRangeFocusWidth 
      /// @param theRangeFocusWidth
      void setRangeFocusWidth(Real theMin,Real theMax);
      /// @brief setRangeFocusHeight 
      /// @param theRangeFocusHeight
      void setRangeFocusHeight(Real theMin,Real theMax);
      /// @brief setRangeFocusPPS 
      /// @param theRangeFocusPPS
      void setRangeFocusPPS(Real theMin,Real theMax);
      /// @brief setRangeFocusNP 
      /// @param theRangeFocusNP
      void setRangeFocusNP(Real theMin,Real theMax);
      void setSystem(System* theSystem){mSystem = theSystem;};
   private:
      //                      VARIABLES
      //////////////////////////////////////////////////////////////////////////
      EmitterID       mID;               ///< Unique EmitterID for the emitter.
      System*         mSystem;
      sf::Rect<int>   mTexRect;
      Shape           mShape;            ///< The emitter's shape.
      Dispersion      mDispersion;       ///< Type of paricles' dispersion.
      gt::Randomizer  mRangeParticlePOW; ///< Range of paricles impulsion.
      gt::Randomizer  mRangeParticleTOL; ///< Range of particles lifetime.
      gt::Randomizer  mRangeParticleAngle;///< Range of particles lifetime.
      gt::Randomizer  mRangeParticleScale;///< Range of particles lifetime.
      gt::Randomizer  mRangeParticleAV;  ///< Range of particles angular velocity.
      gt::Randomizer  mRangeFocusWidth;  ///< Range of focus width.
      gt::Randomizer  mRangeFocusHeight; ///< Range of focus height.
      gt::Randomizer  mRangeFocusTOL;    ///< Range of focus time of life.
      gt::Randomizer  mRangeFocusPPS;    ///< Range of focus particles per second.
      gt::Randomizer  mRangeFocusNP;     ///< Range of focus number of particles.

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

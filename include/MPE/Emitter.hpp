////////////////////////////////////////////////////////////////////////////////
/// @file Emitter.hpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2012-12-17
////////////////////////////////////////////////////////////////////////////////

#ifndef  EMITTER_INC
#define  EMITTER_INC

#include <list>

#include <SFML/Graphics.hpp>
#include <GT/GT.hpp>
#include <MPE/Config.hpp>

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
      Focus createFocus(System&   theSystem,
                        gt::Vec2D thePosition,
                        Real      theAngle);
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
      gt::Vec2D generateVelocity(const Focus& theFocus,
                                     const gt::Vec2D& theParticlePosition) const;
      //    ACCESSORS AND MUTATORS
      //////////////////////////////////////////////////////////////////////////
      /// @brief getID 
      /// @return 
      EmitterID getID() const;
      /// @brief getTexture 
      /// @return 
      const sf::Texture& getTexture() const;
      /// @brief getParticlePOW 
      /// @return 
      Real getParticlePOW() const;
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
      /// @brief setTexture 
      /// @param theFilename
      void setTexture(std::string theFilename);
      /// @brief setShape 
      /// @param theShape
      void setShape(Shape theShape);
      /// @brief getDispersion 
      /// @return 
      void setDispersion(Dispersion theDispersion);
      /// @brief setRangeParticlePOW 
      /// @param theRangeParticlePOW
      void setRangeParticlePOW(Real theMin,Real theMax);
      /// @brief setRangeParticleTOL 
      /// @param theRangeParticleTOL
      void setRangeParticleTOL(Real theMin,Real theMax);
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
   private:
      //                      VARIABLES
      //////////////////////////////////////////////////////////////////////////
      EmitterID          mID;               ///< Unique EmitterID for the emitter.
      sf::Texture mTexture;          ///< The texture to make an Sprite.
      Shape       mShape;            ///< The emitter's shape.
      Dispersion  mDispersion;       ///< Type of paricles' dispersion.
      gt::Randomizer  mRangeParticlePOW; ///< Range of paricles impulsion.
      gt::Randomizer  mRangeParticleTOL; ///< Range of particles lifetime.
      gt::Randomizer  mRangeFocusWidth;  ///< Range of focus width.
      gt::Randomizer  mRangeFocusHeight; ///< Range of focus height.
      gt::Randomizer  mRangeFocusTOL;    ///< Range of focus time of life.
      gt::Randomizer  mRangeFocusPPS;    ///< Range of focus particles per second.
      gt::Randomizer  mRangeFocusNP;     ///< Range of focus number of particles.

};
//                END OF THE EMITTER CLASS
////////////////////////////////////////////////////////////////////////////////
//                INLINE METHODS
////////////////////////////////////////////////////////////////////////////////
inline EmitterID Emitter::getID() const
{
   return mID;
}
inline const sf::Texture& Emitter::getTexture() const
{
   return mTexture;
}
inline Real Emitter::getParticlePOW() const 
{
   return mRangeParticlePOW.get();
}
inline Real Emitter::getParticleTOL() const 
{
   return mRangeParticleTOL.get();
}
inline Real Emitter::getFocusTOL() const 
{
   return mRangeFocusTOL.get();
}
inline Real Emitter::getFocusWidth() const 
{
   return mRangeFocusWidth.get();
}
inline Real Emitter::getFocusHeight() const 
{
   return mRangeFocusHeight.get();
}
inline Real Emitter::getFocusPPS() const 
{
   return mRangeFocusPPS.get();
}
inline Integer Emitter::getFocusNP() const 
{
   return static_cast<Integer>(mRangeFocusNP.get());
}
inline void Emitter::setTexture(std::string theFilename)
{
   mTexture.loadFromFile(theFilename);
}
inline void Emitter::setShape(Shape theShape)
{
   mShape = theShape;
}
inline void Emitter::setDispersion(Dispersion theDispersion) 
{
   mDispersion = theDispersion;
}
inline void Emitter::setRangeParticlePOW(Real theMin, Real theMax)
{
   mRangeParticlePOW(theMin,theMax);
}
inline void Emitter::setRangeParticleTOL(Real theMin, Real theMax)
{
   mRangeParticleTOL(theMin,theMax);
}
inline void Emitter::setRangeFocusWidth(Real theMin, Real theMax)
{
   mRangeFocusWidth(theMin,theMax);
}
inline void Emitter::setRangeFocusHeight(Real theMin, Real theMax)
{
   mRangeFocusHeight(theMin,theMax);
}
inline void Emitter::setRangeFocusTOL(Real theMin, Real theMax)
{
   mRangeFocusTOL(theMin,theMax);
}
inline void Emitter::setRangeFocusPPS(Real theMin, Real theMax)
{
   mRangeFocusPPS(theMin,theMax);
}
inline void Emitter::setRangeFocusNP(Real theMin,Real theMax)
{
   mRangeFocusNP(theMin,theMax);
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

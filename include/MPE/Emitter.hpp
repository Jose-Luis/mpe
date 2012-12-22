////////////////////////////////////////////////////////////////////////////////
/// @file Emitter.hpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2012-12-17
////////////////////////////////////////////////////////////////////////////////

#ifndef  EMITTER_INC
#define  EMITTER_INC

#include <list>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

#include <SFML/Graphics.hpp>

#include <GT/GT.hpp>

namespace mpe
{
class Focus;
/// @brief Emitter is a server class for the flyweight client Focus.
class Emitter
{
   public:
      //                      INNER TYPES                                                                    
      //////////////////////////////////////////////////////////////////////////
      typedef boost::shared_ptr<Emitter> Ptr;
      typedef std::string ID;
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
      Emitter(ID theID);
      /// @brief ~Emitter 
      ~Emitter();
      /// @brief create an smart pointer to one Emitter. The emitter will
      /// be delete when there isn't any reference to it.
      /// @param theID
      /// @return 
      static Ptr create(ID theID);
      /// @brief createFocus 
      /// @return 
      Focus createFocus();
      /// @brief Generate a random position inside the Shape of the emitter.
      /// The position is transformed by the system factor member to scale it 
      /// to the world coordinates.
      /// @param theFocus
      /// @returns The initial position of the particle.   
      gt::Vec2D generateParticlePosition(const Focus& theFocus) const;
      /// @brief Generate a velocity depending of the emitter dispertion.
      /// @param theFocus
      /// @param theParticlePosition
      /// @returns The particle velocity.
      gt::Vec2D generateParticleVelocity(const Focus& theFocus,
                                     const gt::Vec2D& theParticlePosition) const;
      //    ACCESSORS AND MUTATORS
      //////////////////////////////////////////////////////////////////////////
      /// @brief getID 
      /// @return 
      ID getID() const;
      /// @brief getTexture 
      /// @return 
      sf::Texture getTexture() const;
      Real getParticleStrenght() const;
      Real getParticleTOL() const;
      Real getFocusTOL() const;
      Real getFocusPPS() const;
      Real getFocusNP() const;
      /// @brief setTexture 
      /// @param theFilename
      void setTexture(std::string theFilename);
      /// @brief setShape 
      /// @param theShape
      void setShape(Shape theShape);
      /// @brief getDispersion 
      /// @return 
      void setDispersion(Dispersion theDispersion);
      /// @brief setRangeParticleStrenght 
      /// @param theRangeParticleStrenght
      void setRangeParticleStrenght(gt::Randomizer theRangeParticleStrenght);
      /// @brief setRangeParticleTOL 
      /// @param theRangeParticleTOL
      void setRangeParticleTOL(gt::Randomizer theRangeParticleTOL);
      /// @brief setRangeFocusTOL 
      /// @param theRangeFocusTOL
      void setRangeFocusTOL(gt::Randomizer theRangeFocusTOL);
      /// @brief setRangeFocusPPS 
      /// @param theRangeFocusPPS
      void setRangeFocusPPS(gt::Randomizer theRangeFocusPPS);
      /// @brief setRangeFocusNP 
      /// @param theRangeFocusNP
      void setRangeFocusNP(gt::Randomizer theRangeFocusNP);
   private:
      //                      VARIABLES
      //////////////////////////////////////////////////////////////////////////
      ID          mID;               ///< Unique ID for the emitter.
      sf::Texture mTexture;          ///< The texture to make an Sprite.
      Shape       mShape;            ///< The emitter's shape.
      Dispersion  mDispersion;       ///< Type of paricles' dispersion.
      gt::Vec2D   mLinearVelocity;   ///< Type of paricles' dispersion.
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
inline Emitter::ID Emitter::getID() const
{
   return mID;
}
inline sf::Texture Emitter::getTexture() const
{
   return mTexture;
}
inline void Emitter::setTexture(std::string theFilename)
{
   mTexture.loadFromFile(theFilename);
}
inline Emitter::Shape Emitter::getShape() const
{
   return mShape;
}
inline void Emitter::setShape(Shape theShape)
{
   mShape = theShape;
}
inline Emitter::Dispersion Emitter::getDispersion() const
{
   return mDispersion;
}
inline void Emitter::setDispersion(Dispersion theDispersion) 
{
   mDispersion = theDispersion;
}
inline gt::Randomizer Emitter::getParticleStrenght() const 
{
   return mRangeParticlePOW;
}
inline void Emitter::setRangeParticleStrenght(gt::Randomizer theRangeParticleStrenght)
{
   mRangeParticlePOW=theRangeParticleStrenght;
}
inline gt::Randomizer Emitter::getParticleTOL() const 
{
   return mRangeParticleTOL;
}
inline void Emitter::setRangeParticleTOL(gt::Randomizer theRangeParticleTOL)
{
   mRangeParticleTOL=theRangeParticleTOL;
}
inline gt::Randomizer Emitter::getFocusTOL() const 
{
   return mRangeFocusTOL;
}
inline void Emitter::setRangeFocusTOL(gt::Randomizer theRangeFocusTOL)
{
   mRangeFocusTOL=theRangeFocusTOL;
}
inline gt::Randomizer Emitter::getFocusPPS() const 
{
   return mRangeFocusPPS;
}
inline void Emitter::setRangeFocusPPS(gt::Randomizer theRangeFocusPPS)
{
   mRangeFocusPPS=theRangeFocusPPS;
}
inline gt::Randomizer Emitter::getFocusNP() const 
{
   return mRangeFocusNP;
}
inline void Emitter::setRangeFocusNP(gt::Randomizer theRangeFocusNP)
{
   mRangeFocusNP=theRangeFocusNP;
}
}    
#endif  

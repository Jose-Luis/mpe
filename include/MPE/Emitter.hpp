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

#include <GT/GT.hpp>

#include <MPE/Particle.hpp>
#include <MPE/Interfaces.hpp>

namespace mpe
{
/// @class Emitter 
/// @brief Emitter is a server class for the flyweight client Focus.
///
class Emitter
{
   public:
      //                      INNER TYPES                                                                    
      //////////////////////////////////////////////////////////////////////////
      typedef boost::shared_ptr<Emitter> Ptr;
      typedef std::string ID;
      ///
      /// @enum Shape
      /// @brief The Shape of the emitter. 
      ///
      enum Shape{RECTANGLE,CIRCLE};
      ///
      /// @enum Dispersion
      /// @brief The particle dispersion performed by the emitter. 
      ///
      enum Dispersion{LINEAR,RADIAL,REFLECT,RANDOM,STATIC};
      ///
      /// @struct Focus
      /// @brief Focus is the client of the Emitter, represent each one 
      /// of the particle focus emition units.
      ///
      //                      LIFE CYCLE
      //////////////////////////////////////////////////////////////////////////
      ///
      /// @brief Emitter 
      /// @param theID
      /// @param theSystem
      ///
      Emitter(ID theID,ISystem& theSystem);
      ///
      /// @brief ~Emitter 
      ///
      ~Emitter();
      ///
      /// @brief create an smart pointer to one Emitter. The emitter will
      /// be delete when there isn't any reference to it.
      /// @param theID
      /// @param theSystem
      /// @return 
      ///
      static Ptr create(ID theID,ISystem& theSystem);

      //               PUBLIC METHODS
      //////////////////////////////////////////////////////////////////////////
      ///
      /// @brief updateFocusState check and changed the alive member of the focus.
      /// @param theFocus
      ///
      void updateFocusState(Focus& theFocus);
      ///
      /// @brief update all the Focus belonging to it.
      /// @param theElapsedTime
      ///
      void update(Real theElapsedTime);
      ///
      /// @brief addFocus one focus to the emitter. 
      /// @param theFocus
      ///
      //                      ACCESORS
      //////////////////////////////////////////////////////////////////////////
      /// @brief getID 
      /// @return Emitter::ID 
      inline ID           getID() const; 
      /// @brief getShape 
      /// @return Emitter::Shape 
      inline Shape        getShape (  ) const;
      /// @brief getDispersion 
      /// @return Emitter::Dispersion 
      inline Dispersion   getDispersion (  ) const;
      /// @brief getRangeStrenght 
      /// @return Randomizer
      inline Randomizer   getRangeStrenght (  ) const;
      /// @brief getRangeParticleTOL 
      /// @return Randomizer
      inline Randomizer   getRangeParticleTOL (  ) const;
      /// @brief getLinearVelocity 
      /// @return Vec2D 
      inline Vec2D getLinearVelocity (  ) const;
      /// @brief getTOL 
      /// @return Real
      inline Real         getTOL (  ) const;
      /// @brief getPPS 
      /// @return Real 
      inline Real         getPPS (  ) const;
      /// @brief getTotalParticles 
      /// @return Integer 
      inline Integer      getTotalParticles (  ) const;
      /// @brief setShape 
      /// @param theValue
      //                      MUTATORS
      //////////////////////////////////////////////////////////////////////////
      inline void   setShape ( Shape theValue );
      /// @brief setDispersion
      /// @param theValue
      inline void   setDispersion ( Dispersion theValue );
      /// @brief setTexture
      /// @param theValue
      inline void   setTexture ( std::string theFilename );
      /// @brief setRangeStrenght
      /// @param theValue
      inline void   setRangeStrenght ( Randomizer theValue );
      /// @brief setRangeParticleTOL
      /// @param theValue
      inline void   setRangeParticleTOL ( Randomizer theValue );
      /// @brief setLinearVelocity
      /// @param theValue
      inline void   setLinearVelocity ( Vec2D theValue );
      /// @brief setTOL
      /// @param theValue
      inline void   setTOL ( Real theValue );
      /// @brief setPPS
      /// @param theValue
      inline void   setPPS ( Real theValue );
      /// @brief setTotalParticles 
      /// @param theValue
      inline void   setTotalParticles ( Integer theValue );
      ///
      /// @brief Generate a random position inside the Shape of the emitter.
      /// The position is transformed by the system factor member to scale it 
      /// to the world coordinates.
      /// @param theFocus
      /// @returns The initial position of the particle.   
      ///
      Vec2D generatePariclePosition(const Focus& theFocus);
      ///
      /// @brief Generate a velocity depending of the emitter dispertion.
      /// @param theFocus
      /// @param theParticlePosition
      /// @returns The particle velocity.
      ///
      Vec2D generateParticleVelocity(const Focus& theFocus,
                                     const Vec2D& theParticlePosition) const;

   private:
      //                      VARIABLES
      //////////////////////////////////////////////////////////////////////////
      ID          mID;               ///< Unique ID for the emitter.
      sf::Texture mTexture;          ///< The texture to make an Sprite.
      Shape       mShape;            ///< The emitter's shape.
      Dispersion  mDispersion;       ///< Type of paricles' dispersion.
      Randomizer  mRangeParticleStrenght;    ///< Range of paricles impulsion.
      Randomizer  mRangeParticleTOL; ///< Range of particles lifetime.
      Randomizer  mRangeFocusTOL;    ///< Range of particles lifetime.
      Randomizer  mRangeFocusPPS;    ///< Range of particles lifetime.
      Randomizer  mRangeFocusTP;     ///< Number of particles emitted.
};
//                           END OF THE EMITTER CLASS
////////////////////////////////////////////////////////////////////////////////
}    
#endif  

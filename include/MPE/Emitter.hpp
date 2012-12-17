/// @file Emitter.hpp
///   Emitter class.
/// @author Jose Luis Lavado
/// @version 1
/// @date 2012-12-17

#ifndef  EMITTER_INC
#define  EMITTER_INC

#include <list>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

#include <MPE/Particle.hpp>
#include <MPE/Config.hpp>
#include <MPE/Interfaces.hpp>

namespace MPE
{
   /////////////////////////////////////////////////////////////////////////////
   ///   Emitter is a server class for the flyweight client Focus.
   /////////////////////////////////////////////////////////////////////////////
   class Emitter
   {
      public:
         ///////////////////////////////////////////////////////////////////////
         // INNER TYPES                                                                    
         ///////////////////////////////////////////////////////////////////////
         typedef boost::shared_ptr<Emitter> Ptr;
         typedef std::string ID;
         ///  The Shape of the emitter. 
         enum Shape{RECTANGLE,CIRCLE};
         ///  The particle dispersion performed by the emitter. 
         enum Dispersion{LINEAR,RADIAL,REFLECT,RANDOM,STATIC};
         /// @struct Focus.
         /// @brief Focus is the client of the Emitter, represent each one 
         /// of the particle focus emition units.
         struct Focus
         {
            bool         alive;  
            Real         width;   
            Real         height;
            Angle        angle;
            sf::Vector2f position;
            Integer      emittedParticles;
            Real         lifetime;
         };
         ///////////////////////////////////////////////////////////////////////
         // LIFE CYCLE
         ///////////////////////////////////////////////////////////////////////
         ///  The constructor. 
         /// @param theID
         /// @param theSystem
         Emitter(ID theID,ISystem& theSystem);
         ///  The destructor 
         ~Emitter();
         ///  Create an smart pointer to one Emitter. The emitter will
         /// be delete when there isn't any reference to it
         /// @param theID
         /// @param theSystem
         /// @returns a boost::shared_ptr<Emitter> 
         static Ptr create(ID theID,ISystem& theSystem);
         ///////////////////////////////////////////////////////////////////////
         // PUBLIC METHODS
         ///////////////////////////////////////////////////////////////////////
         ///  Check and changed the alive member of the focus.  
         /// @param theFocus
         void updateFocusState(Focus& theFocus);
         /// Update all the Focus belonging to it.  
         /// @param theElapsedTime
         void update(Real theElapsedTime);
         ///  Emit n particles to the mSystem member from theFocus.
         /// @param theNumberOfParticles
         /// @param theFocus
         void emit(Integer theNumberOfParticles, Focus& theFocus);
         ///  Add one focus to the emitter. 
         /// @param theFocus
         void addFocus(Focus theFocus);
         ///////////////////////////////////////////////////////////////////////
         // ACCESORS
         ///////////////////////////////////////////////////////////////////////
         inline ID           getID() const {return mID;};
         inline Shape        getShape (  ) const;
         inline Dispersion   getDispersion (  ) const;
         inline Randomizer   getRangeStrenght (  ) const;
         inline Randomizer   getRangeParticleTOL (  ) const;
         inline sf::Vector2f getLinearVelocity (  ) const;
         inline Real         getTOL (  ) const;
         inline Real         getPPS (  ) const;
         inline Integer      getTotalParticles (  ) const;
         ///////////////////////////////////////////////////////////////////////
         inline void         setShape ( Shape theValue );
         inline void         setDispersion ( Dispersion theValue );
         inline void         setTexture ( std::string theFilename );
         inline void         setRangeStrenght ( Randomizer theValue );
         inline void         setRangeParticleTOL ( Randomizer theValue );
         inline void         setLinearVelocity ( sf::Vector2f theValue );
         inline void         setTOL ( Real theValue );
         inline void         setPPS ( Real theValue );
         inline void         setTotalParticles ( Integer theValue );
         ///////////////////////////////////////////////////////////////////////
      private:
         ///////////////////////////////////////////////////////////////////////
         // VARIABLES
         ///////////////////////////////////////////////////////////////////////
         ID                mID;               ///< Unique ID for the emitter.
         ISystem&          mSystem;           ///< The system to add particles.
         sf::Texture       mTexture;          ///< The texture to make an Sprite.
         Shape             mShape;
         Dispersion        mDispersion;       ///< Type of paricles' dispersion.
         sf::Vector2f      mLinearVelocity;
         Randomizer        mRangeStrenght;    ///< Range of paricles impulsion.
         Randomizer        mRangeParticleTOL; ///< Range of particles lifetime.
         Real              mTOL;              ///< Time Of Life.
         Real              mPPS;              ///< Particles Per Second.
         Integer           mTotalParticles;
         std::list<Focus>  mFocusses;         ///< Alive focusses list.
         ///////////////////////////////////////////////////////////////////////
         // PRIVATE METHODS
         ///////////////////////////////////////////////////////////////////////
         ///  Generate a random position inside the Shape of the 
         /// emitter. The position is transformed by the system factor member to
         /// scale it to the world coordinates.
         /// @param theFocus
         /// @returns The initial position of the particle.   
         sf::Vector2f generatePosition(Focus& theFocus);
         ///  Generate a velocity depending of the emitter dispertion.
         /// @param theFocus
         /// @param theParticlePosition
         /// @returns The particle velocity.
         sf::Vector2f generateVelocity(const Focus&  theFocus,
                                       sf::Vector2f& theParticlePosition);
         ///  normalize a vector.  
         /// @param theVector
         /// @returns A vector of module 1.  
         inline sf::Vector2f normalizeVector(const sf::Vector2f& theVector);
         ///  Scale the vector.  
         /// @param theVector
         /// @param theScalar
         /// @returns The Vector scaled.
         inline sf::Vector2f scaleVector(const sf::Vector2f& theVector,
         ///  theFinal - theOrigin 
         /// @param theOrigin
         /// @param theFinal
         /// @returns The diff of the vectors.  
         inline sf::Vector2f diffVectors(const sf::Vector2f& theOrigin,
                                         const sf::Vector2f& theFinal);
         ///////////////////////////////////////////////////////////////////////
         /// THIS IS THE END...
         ///////////////////////////////////////////////////////////////////////
   };
}    

#endif  

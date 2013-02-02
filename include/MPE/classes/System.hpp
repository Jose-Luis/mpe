/// @file System.hpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2012-12-18

#ifndef  SYSTEM_INC
#define  SYSTEM_INC

#include <list>
#include <map>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <GT/GT.hpp>
#include <MPE/Config.hpp>
#include <MPE/classes/Particle.hpp>
#include <MPE/classes/Affector.hpp>
#include <MPE/classes/Emitter.hpp>
#include <MPE/classes/Focus.hpp>

namespace mpe
{
/// @class System
   class System
   {
      public:
         static System DUMMY;
         /// @brief System    
         /// @param theFactor
         System(Real theFactor);
         /// @brief addEmitter 
         /// @param theEmitter
         void     addEmitter(Emitter& theEmitter);
         /// @brief addFocus 
         /// @param theFocus
         void     addFocus(FocusPtr theFocus);
         /// @brief addFocus 
         /// @param theFocus
         void     addAffector(AffectorPtr theAffector);
         /// @brief addParticle 
         /// @param theParticle
         void     addParticle(Particle& theParticle);
         /// @brief addFocus 
         /// @param theEmitter
         /// @param thePosition
         /// @param theAngle
         FocusPtr   createFocus(EmitterID theEmitter,
                                gt::Vec2D thePosition,
                                Real      theAngle);
         /// @brief update 
         /// @param theElapsedTime
         void     update(Real theElapsedTime);
         /// @brief draw 
         /// @param theWindow
         void     draw(sf::RenderWindow& theWindow) const;
         /// @brief getEmitter 
         /// @param theEmitterID
         /// @return 
         Emitter& getEmitter(EmitterID theEmitterID);
         /// @brief getXFactor 
         /// @return 
         Real     getXFactor() const;
         /// @brief setXFactor 
         /// @param theXFactor
         void     setXFactor(Real theXFactor);
         /// @brief getYFactor 
         /// @return 
         Real     getYFactor() const;
         /// @brief setYFactor 
         /// @param theYFactor
         void     setYFactor(Real theYFactor);
      private:
         //   MEMBERS
         ///////////////////////////////////////////////////////////////////////
         Real mXFactor;
         Real mYFactor;
         std::list<FocusPtr>           mFocusses;
         std::list<AffectorPtr>        mAffectors;
         std::list<Particle>           mParticles;
         std::map<EmitterID,Emitter>   mEmitters;
         //    METHODS
         ///////////////////////////////////////////////////////////////////////
         void updateParticles(Real theElapsedTime);
         void updateFocusses (Real theElapsedTime);
   };
}
#endif 

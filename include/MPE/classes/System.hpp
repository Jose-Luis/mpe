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
         /// @brief System    
         /// @param theFactor
         System();
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
                                Real      theAngle,
                                GroupID   theGroups = mpe::NO_GROUP);
         /// @brief update 
         /// @param theElapsedTime
         void     update(Real theElapsedTime);
         /// @brief draw 
         /// @param theWindow
         void     draw(sf::RenderWindow& theWindow);
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
         /// @brief setTexture 
         /// @param theTexture
         void     setTexture(sf::Texture* theTexture);
      protected:
         //   MEMBERS
         ///////////////////////////////////////////////////////////////////////
         Real mXFactor;
         Real mYFactor;
         sf::Texture mTexture;
         sf::VertexArray mVertices;
         sf::RenderStates mStates;
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

/// @file System.hpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2012-12-18

#ifndef  SYSTEM_INC
#define  SYSTEM_INC

#include <list>
#include <map>
#include <boost/shared_ptr.hpp>

#include <SFML/Graphics.hpp>

#include <MPE/Emitter.hpp>
#include <MPE/Focus.hpp>
#include <GT/GT.hpp>

namespace mpe
{
/// @class System
   class System
   {
      public:
         /// @brief System    
         /// @param theFactor
         System(Real theFactor);
         /// @brief addEmitter 
         /// @param theEmitter
         void     addEmitter(Emitter& theEmitter);
         /// @brief addFocus 
         /// @param theEmitter
         /// @param thePosition
         /// @param theAngle
         void     addFocus(Emitter::ID theEmitter,
                           gt::Vec2D   thePosition,
                           Real        theAngle);
         /// @brief addParticle 
         /// @param theParticle
         void     addParticle(Particle& theParticle);
         /// @brief update 
         /// @param theElapsedTime
         void     update(Real theElapsedTime);
         /// @brief draw 
         /// @param theWindow
         void     draw(sf::RenderWindow& theWindow) const;
         /// @brief getEmitter 
         /// @param theEmitterID
         /// @return 
         Emitter& getEmitter(Emitter::ID theEmitterID);
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
         std::list<Focus>              mFocusses;
         std::list<Particle>           mParticles;
         std::map<Emitter::ID,Emitter> mEmitters;
         //    METHODS
         ///////////////////////////////////////////////////////////////////////
         void updateParticles(Real theElapsedTime);
         void updateFocusses (Real theElapsedTime);
   };
////////////////////////////////////////////////////////////////////////////////
/// @brief The accessor to XFactor
/// @return Real
inline Real System::getXFactor() const 
{
   return mXFactor;
}
/// @brief The mutator for XFactor
/// @param theXFactor
inline void System::setXFactor(Real theXFactor)
{
   mXFactor=theXFactor;
}
/// @brief The accessor to YFactor
/// @return Real
inline Real System::getYFactor() const 
{
   return mYFactor;
}
/// @brief The mutator for YFactor
/// @param theYFactor
inline void System::setYFactor(Real theYFactor)
{
   mYFactor=theYFactor;
}
}

#endif 

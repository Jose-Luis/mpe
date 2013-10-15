/// @file System.hpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2012-12-18

#ifndef  SYSTEM_INC
#define  SYSTEM_INC

#include <list>
#include <map>
#include <MPE/Config.hpp>
#include <MPE/classes/Particle.hpp>
#include <MPE/classes/Affector.hpp>
#include <MPE/classes/Emitter.hpp>
#include <MPE/classes/Focus.hpp>
#include <tinyxml2.h>

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
                          Vec2 thePosition,
                          Real      theAngle,
                          GroupID   theGroups = mpe::NO_GROUP);
   /// @brief update
   /// @param theElapsedTime
   void     update(Real theElapsedTime);
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
   /// @brief initFromFile
   /// @param theFilename
   bool initFromFile(std::string theFilename);
protected:
   //   MEMBERS
   ///////////////////////////////////////////////////////////////////////
   Real mXFactor;
   Real mYFactor;
   std::list<FocusPtr>           mFocusses;
   std::list<AffectorPtr>        mAffectors;
   std::list<Particle>           mParticles;
   std::map<EmitterID, Emitter>   mEmitters;
   //    METHODS
   ///////////////////////////////////////////////////////////////////////
   void updateParticles(Real theElapsedTime);
   void updateFocusses (Real theElapsedTime);
};
}
#endif

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
#include <MPE/classes/ParticleContainer.hpp>
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
   /// @param theNParticles
   /// @param theFixed
   System(size_t theNParticles,bool theFixed=true);
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
   Particle*  addParticle();
   /// @brief addFocus
   /// @param theEmitter
   /// @param thePosition
   /// @param theAngle
   FocusPtr   createFocus(EmitterID theEmitter);
   /// @brief update
   /// @param theElapsedTime
   void     update(Real theElapsedTime);
   /// @brief getEmitter
   /// @param theEmitterID
   /// @return
   Emitter& getEmitter(EmitterID theEmitterID);
   /// @brief getParticleSize 
   /// @return 
   Integer getParticlesSize();
   /// @brief getParticlesBegin
   /// @return 
   ParticleContainer::const_iterator getParticlesBegin() const;
   /// @brief getParticlesEnd 
   /// @return 
   ParticleContainer::const_iterator getParticlesEnd() const;
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
   ParticleContainer             mParticles;
   std::map<EmitterID, Emitter>  mEmitters;
   //    METHODS
   ///////////////////////////////////////////////////////////////////////
   void updateParticles(Real theElapsedTime);
   void updateFocusses (Real theElapsedTime);
};
}
#endif

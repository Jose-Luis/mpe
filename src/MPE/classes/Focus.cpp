/// @file Focus.cpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2012-12-22

#include <MPE/classes/Focus.hpp>
#include <MPE/classes/System.hpp>
#include <MPE/classes/Emitter.hpp>
#include <MPE/classes/Particle.hpp>

namespace mpe
{
//------------------------------------------------------------------------------
//      Class:        Focus
//      Method:       Focus
//      Description:  
//------------------------------------------------------------------------------
Focus::Focus(
            Real theWidth,
            Real theHeight,
            gt::Angle theAngle,
            gt::Vec2D thePosition,
            Integer theTP,
            Real theLifetime,
            Real thePPS,
            System& theSystem,
            Emitter& theEmitter
            ):
   Mortal(theLifetime),
   Position(thePosition),
   mWidth(theWidth),
   mHeight(theHeight),
   mAngle(theAngle),
   mTP(theTP),
   mEP(0),
   mPPS(thePPS),
   mEmitter(theEmitter),
   mSystem(theSystem)
{
}
//--------------------------------------------------------------------------------------
//      Class:        Focus
//      Method:       create
//      Description:  
//--------------------------------------------------------------------------------------
FocusPtr Focus::create(Real      theWidth,
                       Real      theHeight,
                       gt::Angle theAngle,
                       gt::Vec2D thePosition,
                       Integer   theTP,
                       Real      theLifetime,
                       Real      thePPS,
                       System&   theSystem,
                       Emitter&  theEmitter)
{
   return boost::make_shared<Focus>(theWidth,
                                    theHeight,
                                    theAngle,
                                    thePosition,
                                    theTP,
                                    theLifetime,
                                    thePPS,
                                    theSystem,
                                    theEmitter);
}
//------------------------------------------------------------------------------
//       Class:  Focus
//      Method:  update
// Description:  
//------------------------------------------------------------------------------
void Focus::update(Real theElapsedTime)
{
   age(theElapsedTime);
   if (isAlive() )
   {
      Integer nParticles = drain(theElapsedTime);
      emit(nParticles);
   }
}
//------------------------------------------------------------------------------
//       Class:  Focus
//      Method:  emit
// Description:  
//------------------------------------------------------------------------------
void Focus::emit(Integer theNParticles)
{
   for(int i = 0; i < theNParticles; i++)
   {
      Particle anParticle = createParticle();
      mSystem.addParticle(anParticle);
   }
}
//------------------------------------------------------------------------------
//       Class:  Focus
//      Method:  createParticle
// Description:  
//------------------------------------------------------------------------------
Particle Focus::createParticle ()
{
   gt::Vec2D anPosition = mEmitter.generatePosition(*this);
   gt::Vec2D anVelocity = mEmitter.generateVelocity(*this,anPosition);
   Particle  anParticle = Particle(mEmitter.getTexture(),
                                   anPosition,
                                   gt::Randomizer::get(0,gt::Angle::PI*2),
                                   anVelocity,
                                   gt::Randomizer::get(-1,1),
                                   mEmitter.getParticleTOL());
   return anParticle;
}
////////////////////////////////////////////////////////////////////////////////
// END NAMESPACE mpe
////////////////////////////////////////////////////////////////////////////////
}

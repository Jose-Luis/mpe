/// @file Focus.cpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2012-12-22

#include <MPE/Focus.hpp>
#include <MPE/System.hpp>
#include <MPE/Emitter.hpp>
#include <MPE/Particle.hpp>
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
            Real theTT,
            Real thePPS,
            System& theSystem,
            Emitter& theEmitter
            ):
   mAlive(true),
   mWidth(theWidth),
   mHeight(theHeight),
   mAngle(theAngle),
   mPosition(thePosition),
   mTP(theTP),
   mEP(0),
   mTT(theTT),
   mET(0),
   mPPS(thePPS),
   mEmitter(theEmitter),
   mSystem(theSystem)
{
}
//------------------------------------------------------------------------------
//       Class:  Focus
//      Method:  update
// Description:  
//------------------------------------------------------------------------------
void Focus::update(Real theElapsedTime)
{
   age(theElapsedTime);
   Integer nParticles = drain(theElapsedTime);
   emit(nParticles);
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
//------------------------------------------------------------------------------
//      Class:        Focus
//      Method:       age
//      Description:  
//------------------------------------------------------------------------------
//void Focus::age(Real theElapsedTime)
//{
   //if( mET+theElapsedTime >= mTT )
      //kill();
   //else
      //mET += theElapsedTime;
//}
//------------------------------------------------------------------------------
//      Class:        Focus
//      Method:       drain
//      Description:  
//------------------------------------------------------------------------------
//Integer Focus::drain(Real theElapsedTime)
//{
   //Integer nParticles = 0;
   //if(isAlive())
   //{
      //nParticles = (mPPS * mET / 1000) - mEP;
   //}
   //if(mEP + nParticles > mTT)
   //{
      //nParticles = nParticles - (mEP + nParticles - mTT);
      //kill();
   //}
   //return nParticles;
//}
////////////////////////////////////////////////////////////////////////////////
// END NAMESPACE mpe
////////////////////////////////////////////////////////////////////////////////
}

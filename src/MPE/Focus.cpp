/// @file Focus.cpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2012-12-22

#include <MPE/Focus.hpp>
#include <MPE/System.hpp>
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
            Emitter::Ptr theEmitter,
            System& theSystem
            ):
   mAlive(true),
   mWidth(theWidth),
   mAngle(theAngle),
   mPosition(thePosition),
   mTP(theTP),
   mEP(0),
   mTT(theTT),
   mET(0),
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
void Focus::emit ()
{
   for(int i = 0; i < nParticles;i++)
   {
      //Particle anParticle = createParticle();
      mParticles.push_back(anParticle);
   }
}
//------------------------------------------------------------------------------
//       Class:  Focus
//      Method:  createParticle
// Description:  
//------------------------------------------------------------------------------
Particle Focus::createParticle ()
{
   gt::Vec2D anPosition = mEmitter->generateParticlePosition(*this);
   gt::Vec2D anVelocity = mEmitter->generateParticleVelocity(*this,anPosition);
   Particle anParticle = Particle(
                                 mEmitter->getTexture(),
                                 anPosition,
                                 );
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

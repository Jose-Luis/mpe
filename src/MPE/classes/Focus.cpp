/// @file Focus.cpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2012-12-22

#include <MPE/classes/Focus.hpp>
#include <MPE/classes/Emitter.hpp>
#include <MPE/classes/System.hpp>

namespace mpe
{
//------------------------------------------------------------------------------
//      Class:        Focus
//      Method:       Focus
//      Description:
//------------------------------------------------------------------------------
Focus::Focus(Real           theLifetime,
             Real           theWidth,
             Real           theHeight,
             Vec2           thePosition,
             Real           theAngle,
             Integer        theTP,
             Real           thePPS,
             GroupID        theGroups,
             const Emitter& theEmitter):

   Mortal(theLifetime),
   mWidth(theWidth),
   mHeight(theHeight),
   mPosition(thePosition),
   mAngle(theAngle),
   mTP(theTP),
   mEP(0),
   mPPS(thePPS),
   mTimeAcum(0),
   mGroups(theGroups),
   mEmitter(theEmitter)
{
}
//--------------------------------------------------------------------------------------
//      Class:        Focus
//      Method:       create
//      Description:
//--------------------------------------------------------------------------------------
FocusPtr Focus::create(Real    theLifetime,
                       Real    theWidth,
                       Real    theHeight,
                       Vec2    thePosition,
                       Real    theAngle,
                       Integer theTP,
                       Real    thePPS,
                       GroupID theGroups,
                       const Emitter&  theEmitter)
{
   return FocusPtr{new Focus{theLifetime,
                             theWidth,
                             theHeight,
                             thePosition,
                             theAngle,
                             theTP,
                             thePPS,
                             theGroups,
                             theEmitter}};
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
   System* anSystem = mEmitter.getSystem();

   for(int i = 0; i < theNParticles; i++)
   {
      Particle anParticle = createParticle();
      anSystem->addParticle(anParticle);
   }
}
//------------------------------------------------------------------------------
//       Class:  Focus
//      Method:  createParticle
// Description:
//------------------------------------------------------------------------------
Particle Focus::createParticle ()
{
   Vec2 anPosition = mEmitter.generatePosition(*this);
   Particle  anParticle = Particle( mEmitter.getParticleTOL(),
                                    mEmitter.getParticleWidth(),
                                    mEmitter.getParticleHeight(),
                                    anPosition,
                                    mEmitter.getParticleAngle(),
                                    mEmitter.generateVelocity(*this, anPosition),
                                    mEmitter.getParticleAV(),
                                    Color{255, 255, 255, 255},
                                    mGroups);
   return anParticle;
}
//------------------------------------------------------------------------------
//      Class:        Focus
//      Method:       getPosition
//      Description:
//------------------------------------------------------------------------------
Vec2 Focus::getPosition() const
{
   return mPosition;
}
//------------------------------------------------------------------------------
//      Class:        Focus
//      Method:       setPosition
//      Description:
//------------------------------------------------------------------------------
void Focus::setPosition(Vec2 thePosition)
{
   mPosition = thePosition;
}
//------------------------------------------------------------------------------
//      Class:        Focus
//      Method:       getWidth
//      Description:
//------------------------------------------------------------------------------
Real Focus::getWidth() const
{
   return mWidth;
}
//------------------------------------------------------------------------------
//      Class:        Focus
//      Method:       setWidth
//      Description:
//------------------------------------------------------------------------------
void Focus::setWidth(Real theWidth)
{
   mWidth = theWidth;
}
//------------------------------------------------------------------------------
//      Class:        Focus
//      Method:       getHeight
//      Description:
//------------------------------------------------------------------------------
Real Focus::getHeight() const
{
   return mHeight;
}
//------------------------------------------------------------------------------
//      Class:        Focus
//      Method:       setHeight
//      Description:
//------------------------------------------------------------------------------
void Focus::setHeight(Real theHeight)
{
   mHeight = theHeight;
}
//------------------------------------------------------------------------------
//      Class:        Focus
//      Method:       getAngle
//      Description:
//------------------------------------------------------------------------------
Real Focus::getAngle() const
{
   return mAngle;
}
//------------------------------------------------------------------------------
//      Class:        Focus
//      Method:       setAngle
//      Description:
//------------------------------------------------------------------------------
void Focus::setAngle(Real theAngle)
{
   mAngle = theAngle;
}
//------------------------------------------------------------------------------
//      Class:        Focus
//      Method:       setPPS
//      Description:
//------------------------------------------------------------------------------
void Focus::setPPS(Real thePPS)
{
   mPPS = thePPS;
}
//------------------------------------------------------------------------------
//      Class:        Focus
//      Method:       drain
//      Description:
//------------------------------------------------------------------------------
Integer Focus::drain(Real theElapsedTime)
{
   mTimeAcum += theElapsedTime / 1000;
   Integer nParticles = mTimeAcum * mPPS;

   if(0 < nParticles)
   {
      if( mEP + nParticles > mTP)
      {
         nParticles =  mTP - mEP;
         kill();
      }
      else
      {
         mEP += nParticles;
      }

      mTimeAcum = 0;
   }

   return nParticles;
   //Integer nParticles = (mPPS * getAge() / 1000) - mEP;
}
//------------------------------------------------------------------------------
//       Class:  Focus
//      Method:
// Description:  A stupid method
//------------------------------------------------------------------------------
Real Focus::getPPS ()
{
   return mPPS;
}
////////////////////////////////////////////////////////////////////////////////
// END NAMESPACE mpe
////////////////////////////////////////////////////////////////////////////////
}

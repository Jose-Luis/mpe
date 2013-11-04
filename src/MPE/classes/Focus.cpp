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
Focus::Focus(const Emitter& theEmitter):
   Mortal(0),
   mEmitter(theEmitter)
{
}
//--------------------------------------------------------------------------------------
//      Class:        Focus
//      Method:       create
//      Description:
//--------------------------------------------------------------------------------------
FocusPtr Focus::create(const Emitter&  theEmitter)
{
   return FocusPtr{new Focus{theEmitter}};
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
      initParticle();
   }
}
//------------------------------------------------------------------------------
//       Class:  Focus
//      Method:  initParticle
// Description:  init a particle 
//------------------------------------------------------------------------------
void Focus::initParticle()
{
   Particle* anParticle = mEmitter.getSystem()->addParticle();
   if (anParticle != nullptr)
   {
      Vec2 anPosition = mEmitter.generatePosition(*this); 
      Vec2 anVelocity = mEmitter.generateVelocity(*this,anPosition); 

      anParticle->resetLife(mEmitter.getParticleTOL());                  
      anParticle->setSize(mEmitter.getParticleSize());                  
      anParticle->setTextRect(mEmitter.getTextRect());
      anParticle->setPosition(anPosition);                  
      anParticle->setAngle(mEmitter.getParticleAngle());                  
      anParticle->setLinearVelocity(anVelocity);                  
      anParticle->setAngularVelocity(mEmitter.getParticleAV());                  
      anParticle->setColor(Color{255,255,255,255});                  
      anParticle->setGroups(mGroups);                  
   }
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
//       Class:  Focus
//      Method:
// Description:  A stupid method
//------------------------------------------------------------------------------
Real Focus::getPPS ()
{
   return mPPS;
}
//------------------------------------------------------------------------------
//      Class:        Focus
//      Method:       setNP
//      Description:
//------------------------------------------------------------------------------
void Focus::resetNP(Real theNP)
{
   mTP = theNP;
   mEP = 0;
   mTimeAcum = 0;
}
//------------------------------------------------------------------------------
//      Class:        Focus
//      Method:       drain
//      Description:
//------------------------------------------------------------------------------
Integer Focus::drain(Real theElapsedTime)
{
   mTimeAcum += theElapsedTime;
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
//      Method:  addGroups
// Description:  A stupid method 
//------------------------------------------------------------------------------
void Focus::addGroups(GroupID theGroups)
{
   mGroups |= theGroups;
}
//------------------------------------------------------------------------------
//       Class:  Focus
//      Method:  removeGroups
// Description:  A stupid method 
//------------------------------------------------------------------------------
void Focus::removeGroups(GroupID theGroups)
{
   mGroups &= ~theGroups;
}
//------------------------------------------------------------------------------
//       Class:  Focus
//      Method:  removeFromAllGroups
// Description:  A stupid method 
//------------------------------------------------------------------------------
void Focus::removeFromAllGroups()
{
   mGroups = mpe::NO_GROUP;
}
////////////////////////////////////////////////////////////////////////////////
// END NAMESPACE mpe
////////////////////////////////////////////////////////////////////////////////
}

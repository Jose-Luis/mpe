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
Focus::Focus(
            Real           theWidth,
            Real           theHeight,
            gt::Angle      theAngle,
            gt::Vec2D      thePosition,
            Integer        theTP,
            Real           theLifetime,
            Real           thePPS,
            GroupID        theGroups,
            const Emitter& theEmitter
            ):
   Mortal(theLifetime),
   Position(thePosition),
   mWidth(theWidth),
   mHeight(theHeight),
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
FocusPtr Focus::create(Real      theWidth,
                       Real      theHeight,
                       gt::Angle theAngle,
                       gt::Vec2D thePosition,
                       Integer   theTP,
                       Real      theLifetime,
                       Real      thePPS,
                       GroupID   theGroups,
                       const Emitter&  theEmitter)
{
   return std::make_shared<Focus>(theWidth,
                                    theHeight,
                                    theAngle,
                                    thePosition,
                                    theTP,
                                    theLifetime,
                                    thePPS,
                                    theGroups,
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
   gt::Vec2D anPosition = mEmitter.generatePosition(*this);
   gt::Vec2D anVelocity = mEmitter.generateVelocity(*this,anPosition);
   Real anScale = mEmitter.getParticleScale();
   Particle  anParticle = Particle(mEmitter.getTexRect(),
                                   anPosition,
                                   mEmitter.getParticleAngle(),
                                   gt::Vec2D(anScale,anScale),
                                   anVelocity,
                                   mEmitter.getParticleAV(),
                                   mEmitter.getParticleTOL(),
                                   sf::Color(255,255,255),
                                   mGroups);
   return anParticle;
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
   mWidth=theWidth;
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
   mHeight=theHeight;
}
//------------------------------------------------------------------------------
//      Class:        Focus
//      Method:       getAngle
//      Description:  
//------------------------------------------------------------------------------
gt::Angle Focus::getAngle() const 
{
   return mAngle;
}
//------------------------------------------------------------------------------
//      Class:        Focus
//      Method:       setAngle
//      Description:  
//------------------------------------------------------------------------------
void Focus::setAngle(gt::Angle theAngle)
{
   mAngle=theAngle;
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
   mTimeAcum += theElapsedTime/1000;
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

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
            Real theWidth,
            Real theHeight,
            gt::Angle theAngle,
            gt::Vec2D thePosition,
            Integer theTP,
            Real theLifetime,
            Real thePPS,
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
                       const Emitter&  theEmitter)
{
   return boost::make_shared<Focus>(theWidth,
                                    theHeight,
                                    theAngle,
                                    thePosition,
                                    theTP,
                                    theLifetime,
                                    thePPS,
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
   System& anSystem = mEmitter.getSystem();
   for(int i = 0; i < theNParticles; i++)
   {
      Particle anParticle = createParticle();
      anSystem.addParticle(anParticle);
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
//      Method:       drain
//      Description:  
//------------------------------------------------------------------------------
Integer Focus::drain(Real theElapsedTime)
{
   Integer nParticles = (mPPS * getAge() / 1000) - mEP;

   if( mEP + nParticles > mTP)
   {
      nParticles =  mTP - mEP;
      kill();
   }
   else
   {
      mEP += nParticles;
   }

   return nParticles;
}
////////////////////////////////////////////////////////////////////////////////
// END NAMESPACE mpe
////////////////////////////////////////////////////////////////////////////////
}
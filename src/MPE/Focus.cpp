/// @file Focus.cpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2012-12-22

#include <MPE/Focus.hpp>
#include <MPE/System.hpp>
namespace mpe
{

//--------------------------------------------------------------------------------------
//      Class:        Focus
//      Method:       Focus
//      Description:  
//--------------------------------------------------------------------------------------
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
//--------------------------------------------------------------------------------------
//       Class:  Focus
//      Method:  update
// Description:  
//--------------------------------------------------------------------------------------
void Focus::update(Real theElapsedTime)
{
   emit();
   for (auto it = mParticles.begin(); it != mParticles.end(); it++)
   {
      if(it->isAlive())
      {
         it->update(theElapsedTime);
      }
      else 
      {
         mParticles.erase(it);
      }
   }
   return ;
}
//--------------------------------------------------------------------------------------
//       Class:  Focus
//      Method:  emit
// Description:  
//--------------------------------------------------------------------------------------
void Focus::emit ()
{
   Integer nParticles = (mPPS * mET / 1000) - mEP;
   mEP += nParticles;
   for(int i = 0; i < nParticles;i++)
   {
      //Particle anParticle = createParticle();
      mParticles.push_back(anParticle);
   }
}
}

// =============================================================================
// 
//       Filename:  System.cpp
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  17/12/12 10:56:59
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Jose Luis Lavado (), joseluislavado@gmail.com
//        Company:  
// 
// =============================================================================

#include <MPE/System.hpp>

namespace MPE
{
   
   //------------------------------------------------------------------------------
   //       Class:  System
   //      Method:  System
   // Description:  
   //------------------------------------------------------------------------------
   System::System ( Real theFactor ):
      ISystem(theFactor)
   {
   }
   //---------------------------------------------------------------------------
   //      Class:        System
   //      Method:       addEmitter
   //      Description:  
   //---------------------------------------------------------------------------
   void System::addEmitter(Emitter::Ptr theEmitter)
   {
      if(mEmitters.find(theEmitter->getID()) == mEmitters.end())
      {
         mEmitters.insert
          (std::pair<Emitter::ID,Emitter::Ptr>(theEmitter->getID(),theEmitter));
      }
   }
   //---------------------------------------------------------------------------
   //      Class:        System
   //      Method:       addParticle
   //      Description:  
   //---------------------------------------------------------------------------
   void System::addParticle(Particle& theParticle)
   {
      mParticles.push_back(theParticle);
   }
   //---------------------------------------------------------------------------
   //      Class:        System
   //      Method:       update
   //      Description:  
   //---------------------------------------------------------------------------
   void System::update(Real theElapsedTime)
   {
      for( auto anEmitter: mEmitters)
      {
         anEmitter.second->update(theElapsedTime);
      }
      for( auto it = mParticles.begin(); it != mParticles.end(); it++)
      {
         it->update(theElapsedTime);

         if( !it->isAlive() )
         {
            mParticles.erase(it);
         }
      }
   }
   //--------------------------------------------------------------------------------------
   //      Class:        System
   //      Method:       draw
   //      Description:  
   //--------------------------------------------------------------------------------------
   void System::draw ( sf::RenderWindow& theWindow ) const
   {
      for( auto anParticle: mParticles)
      {
         theWindow.draw(anParticle.getSprite());
      }
   }
   //---------------------------------------------------------------------------
   //       Class:  System
   //      Method:  getEmitter
   // Description:  
   //---------------------------------------------------------------------------
   Emitter::Ptr System::getEmitter ( Emitter::ID theEmitterID ) const
   {
      Emitter::Ptr anResult;

      auto it = mEmitters.find(theEmitterID);
      if (it != mEmitters.end() )
      {
         anResult = it->second();
      }
      return anResult;
   }
}

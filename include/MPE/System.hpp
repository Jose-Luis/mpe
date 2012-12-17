// =============================================================================
// 
//       Filename:  System.hpp
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  17/12/12 10:58:57
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Jose Luis Lavado (), joseluislavado@gmail.com
//        Company:  
// 
// =============================================================================

#ifndef  SYSTEM_INC
#define  SYSTEM_INC

#include <list>
#include <map>
#include <boost/shared_ptr.hpp>

#include <SFML/Graphics.hpp>

#include <MPE/Emitter.hpp>
#include <MPE/Interfaces.hpp>

namespace MPE
{
   class System: public ISystem
   {
      public:

         System(Real theFactor);
         ~System();

         void         addEmitter(Emitter::Ptr theEmitter);
         void         addParticle(Particle& theParticle);
         void         update(Real theElapsedTime);
         void         draw(sf::RenderWindow& theWindow) const;
         Emitter::Ptr getEmitter ( Emitter::ID theEmitterID ) const;

      private:

         std::list<Particle>                mParticles;
         std::map<Emitter::ID,Emitter::Ptr> mEmitters;
   };
}

#endif 

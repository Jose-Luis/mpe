/// @file System.hpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2012-12-18

#ifndef  SYSTEM_INC
#define  SYSTEM_INC

#include <list>
#include <map>
#include <boost/shared_ptr.hpp>

#include <SFML/Graphics.hpp>

#include <MPE/Emitter.hpp>
#include <MPE/Interfaces.hpp>

namespace mpe
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
         std::list<Focus>                   mFocusses;
         std::map<Emitter::ID,Emitter::Ptr> mEmitters;
   };
}

#endif 

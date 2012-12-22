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
#include <MPE/Focus.hpp>
#include <GT/GT.hpp>

namespace mpe
{
   class System
   {
      public:

         System(Real theFactor);
         ~System();

         void         addEmitter(Emitter::Ptr theEmitter);
         void         addFocus(Emitter::ID theEmitter,gt::Vec2D thePosition);
         void         update(Real theElapsedTime);
         void         draw(sf::RenderWindow& theWindow) const;
         Emitter::Ptr getEmitter(Emitter::ID theEmitterID) const;

      private:

         Real mXFactor;
         Real mYFactor;
         std::list<Focus>                   mFocusses;
         std::map<Emitter::ID,Emitter::Ptr> mEmitters;
   };
}

#endif 

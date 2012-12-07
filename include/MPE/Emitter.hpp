
#ifndef  EMITTER_INC
#define  EMITTER_INC

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

#include "Particle.hpp"

namespace MPE
{

   class Emitter
   {
      public:
        
         typedef boost::shared_ptr<Emitter> Ptr;
         typedef std::string ID;

         enum Shape{RECTANGLE,CIRCLE};
         enum Dispersion{LINEAR,RADIAL,RANDOM,STATIC};
         struct Context
         {
            ID emitterID;
            float width;
            float height;
            float angle;
            sf::Vector2f position;
            int emittedParticles;
            float lifetime;
         };
         struct Adder
         {
            virtual void addParticles(Context& theEmitter,float theElapsedTime);
         }

         Emitter();
         ~Emitter();
         static Ptr create();
         void emit(Adder& theSystem,Context& theEmitter);

      private:


         ID mID;
         sf::Texture mTexture;
         Shape mShape;
         Dispersion mDispersion;

         float TTL;
         float PPS;
         float TotalParticles;
         
   };
}    
#endif   // ----- #ifndef EMITTER_INC  -----

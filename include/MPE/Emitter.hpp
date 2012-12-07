
#ifndef  EMITTER_INC
#define  EMITTER_INC

#include <list>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

#include <MPE/Particle.hpp>
#include <MPE/Config.hpp>

namespace MPE
{

   class Emitter
   {
      public:
        
         typedef boost::shared_ptr<Emitter> Ptr;
         typedef std::string ID;

         enum Shape{RECTANGLE,CIRCLE};
         enum Dispersion{LINEAR,RADIAL,REFLECT,RANDOM,STATIC};
         struct Focus
         {
            float width;
            float height;
            Angle angle;
            sf::Vector2f position;
            int emittedParticles;
            float lifetime;
         };
         struct Adder
         {
            virtual void addParticle(const Particle& theParticle) = 0;
         };

         Emitter();
         ~Emitter();
         static Ptr create();
         void emit(Adder& theSystem,float theElapsedTime);
         void addFocus(Focus theFocus);
         inline ID getID() const {return mID;};

      private:


         ID mID;
         sf::Texture mTexture;
         Shape mShape;
         Dispersion mDispersion;

         float mTTL; //Time Of Life
         float mPPS; //Particles Per Second
         float mTotalParticles;
         std::list<Focus> mFocusses;
         
   };
}    
#endif   // ----- #ifndef EMITTER_INC  -----

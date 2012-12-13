
#ifndef  EMITTER_INC
#define  EMITTER_INC

#include <list>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

#include <MPE/Particle.hpp>
#include <MPE/Config.hpp>
#include <MPE/Interfaces.hpp>

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
            Real width;
            Real height;
            Angle angle;
            sf::Vector2f position;
            Integer emittedParticles;
            Real lifetime;
         };

         Emitter(ID theID,ISystem& theSystem);
         Emitter(ISystem& theSystem);
         static Ptr create(ISystem& theSystem);
         ~Emitter();
         void update(Real theElapsedTime);
         void emit(Integer theNumberOfParticles, Focus& theFocus);
         void addFocus(Focus theFocus);
         inline ID getID() const {return mID;};

      private:

         ID mID;
         sf::Texture mTexture;
         Shape mShape;
         Dispersion mDispersion;
         ISystem& mSystem;

         Randomizer mRangeParticleTTL;
         Real mTTL; //Time Of Life
         Real mPPS; //Particles Per Second
         Integer mTotalParticles;

         std::list<Focus> mFocusses;

         sf::Vector2f generatePosition(Focus& theFocus);


      public:
         
   };
}    
   #endif   // ----- #ifndef EMITTER_INC  -----

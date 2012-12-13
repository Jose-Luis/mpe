// =====================================================================================
// 
//       Filename:  Emitter.hpp
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  13/12/12 21:32:41
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Jose Luis Lavado (), joseluislavado@gmail.com
//        Company:  
// 
// =====================================================================================

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
         static Ptr create(ID theID,ISystem& theSystem);
         ~Emitter();
         void update(Real theElapsedTime);
         void emit(Integer theNumberOfParticles, Focus& theFocus);
         void addFocus(Focus theFocus);
         inline ID getID() const {return mID;};
         inline Shape getShape (  ) const;
         inline void setShape ( Shape value );

      private:

         ID mID;
         ISystem& mSystem;
         sf::Texture mTexture;
         Shape mShape;
         Dispersion mDispersion;

         sf::Vector2f mLinearVelocity;
         Randomizer mRangeStrenght;
         Randomizer mRangeParticleTTL;
         Real mTTL; //Time Of Life
         Real mPPS; //Particles Per Second
         Integer mTotalParticles;

         std::list<Focus> mFocusses;

         sf::Vector2f generatePosition(Focus& theFocus);
         sf::Vector2f generateVelocity(Focus& theFocus, sf::Vector2f& theParticlePosition);
         inline void normalize(sf::Vector2f& theVector);
         inline sf::Vector2f scaleVector(const sf::Vector2f& theVector,Real theScalar);
         inline sf::Vector2f diffVectors(const sf::Vector2f& theOrigin,const sf::Vector2f& theFinal);

   };
}    
   #endif   // ----- #ifndef EMITTER_INC  -----

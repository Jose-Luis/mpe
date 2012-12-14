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
         //////////////////  Accesors  /////////////////
         inline ID getID() const {return mID;};
         inline Shape getShape (  ) const;
         inline void setShape ( Shape value );
         inline Dispersion getDispersion (  ) const;
         inline void setDispersion ( Dispersion value );
         inline Randomizer getRangeStrenght (  ) const;
         inline void setRangeStrenght ( Randomizer value );
         inline Randomizer getRangeParticleTTL (  ) const;
         inline void setRangeParticleTTL ( Randomizer value );
         inline sf::Vector2f getLinearVelocity (  ) const;
         inline void setLinearVelocity ( sf::Vector2f value );
         inline Real getTTL (  ) const;
         inline void setTTL ( Real value );
         inline Real getPPS (  ) const;
         inline void setPPS ( Real value );
         inline Integer getTotalParticles (  ) const;
         inline void setTotalParticles ( Integer value );
         //////////////////////////////////////////////////

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

#endif  


#ifndef  INTERFACES_INC
#define  INTERFACES_INC

#include <MPE/Config.hpp>
#include <MPE/Particle.hpp>

namespace mpe
{
   class ISystem
   {
      public:

         ISystem(Real theXFactor,Real theYFactor):
            mXFactor(theXFactor),
            mYFactor(theYFactor)
         {
         }

         ISystem(Real theFactor):
            mXFactor(theFactor),
            mYFactor(theFactor)
         {
         }

         ~ISystem(){};

         virtual void addParticle(Particle&) = 0;

         //--------------------------------------------------------------------------------------
         //       Class:  ISystem
         //      Method:  get_mXFactor
         //--------------------------------------------------------------------------------------
         inline Real getXFactor (  ) const
         {
            return mXFactor;
         }		// -----  end of method ISystem::get_mXFactor  -----

         //--------------------------------------------------------------------------------------
         //       Class:  ISystem
         //      Method:  set_mXFactor
         //--------------------------------------------------------------------------------------
         inline void setXFactor ( Real value )
         {
            mXFactor	= value;
            return ;
         }		// -----  end of method ISystem::set_mXFactor  -----

         //--------------------------------------------------------------------------------------
         //       Class:  ISystem
         //      Method:  get_mYFactor
         //--------------------------------------------------------------------------------------
         inline Real getYFactor (  ) const
         {
            return mYFactor;
         }		// -----  end of method ISystem::get_mYFactor  -----

         //--------------------------------------------------------------------------------------
         //       Class:  ISystem
         //      Method:  set_mYFactor
         //--------------------------------------------------------------------------------------
         inline void setYFactor ( Real value )
         {
            mYFactor	= value;
            return ;
         }		// -----  end of method ISystem::set_mYFactor  -----

      private:

         Real mXFactor;
         Real mYFactor;
   };

   class IFocus
   {
      IFocus(
      virtual emit(Integer theNParticles) = 0;

      private:
         ISystem* mSystem;
   }
}

#endif   // ----- #ifndef INTERFACES_INC  -----

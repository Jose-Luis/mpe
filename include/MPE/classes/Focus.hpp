/// @file Focus.hpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2012-12-21

#ifndef  FOCUS_INC
#define  FOCUS_INC

#include <boost/make_shared.hpp>
#include <GT/GT.hpp>
#include <MPE/Config.hpp>
#include <MPE/components/Mortal.hpp>
#include <MPE/components/Position.hpp>
#include <MPE/classes/Particle.hpp>

namespace mpe
{
////////////////////////////////////////////////////////////////////////////////
//             CLASS FOCUS
////////////////////////////////////////////////////////////////////////////////
/// @class Focus
class Focus: public Mortal, public Position
{
   public:

      //////////////////////////////////////////////////////////////////////////
      //     METHODS
      //////////////////////////////////////////////////////////////////////////
      /// @brief create 
      /// @param theWidth
      /// @param theHeight
      /// @param theAngle
      /// @param thePosition
      /// @param theTP
      /// @param theLifetime
      /// @param thePPS
      /// @param theSystem
      /// @param 
      /// @return 
      Focus(
            Real      theWidth,
            Real      theHeight,
            gt::Angle theAngle,
            gt::Vec2D thePosition,
            Integer   theTP,
            Real      theLifetime,
            Real      thePPS,
            const Emitter&  theEmitter
           );
      static FocusPtr create(Real      theWidth,
            Real      theHeight,
            gt::Angle theAngle,
            gt::Vec2D thePosition,
            Integer   theTP,
            Real      theLifetime,
            Real      thePPS,
            const Emitter&  theEmitter);
      /// @brief update 
      /// @param theElapsedTime
      void update(Real theElapsedTime);
      //////////////////////////////////////////////////////////////////////////
      //     ACCESSORS AND MUTATORS
      //////////////////////////////////////////////////////////////////////////
      /// @brief getWidth 
      /// @return 
      Real getWidth() const;
      /// @brief setWidth 
      /// @param theWidth
      void setWidth(Real theWidth);
      /// @brief getHeight 
      /// @return 
      Real getHeight() const;
      /// @brief setHeight 
      /// @param theHeight
      void setHeight(Real theHeight);
      /// @brief getAngle 
      /// @return 
      gt::Angle getAngle() const;
      /// @brief setAngle 
      /// @param theAngle
      void setAngle(gt::Angle theAngle);

   private:
      //////////////////////////////////////////////////////////////////////////
      //     VARIABLES
      //////////////////////////////////////////////////////////////////////////
      Real      mWidth;   ///< Width.
      Real      mHeight;  ///< Height.
      gt::Angle mAngle;   ///< Angle.
      Integer   mTP;      ///< Total number of Particles. -1 = no number limits
      Integer   mEP;      ///< Particles already emitted by the focus.
      Real      mPPS;
      const Emitter&  mEmitter;///< The emitter server for the focus.
      //////////////////////////////////////////////////////////////////////////
      //     METHODS
      //////////////////////////////////////////////////////////////////////////
      void emit(Integer theNParticles);
      Integer drain(Real theElapsedTime);
      Particle createParticle();
};
}
#endif   

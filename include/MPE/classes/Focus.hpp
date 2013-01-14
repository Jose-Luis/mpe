/// @file Focus.hpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2012-12-21

#ifndef  FOCUS_INC
#define  FOCUS_INC

#include <list>
#include <cfloat>
#include <GT/GT.hpp>
#include <MPE/Config.hpp>
#include <MPE/components/Mortal.hpp>
#include <MPE/components/Position.hpp>

namespace mpe
{
////////////////////////////////////////////////////////////////////////////////
//             CLASS FOCUS
////////////////////////////////////////////////////////////////////////////////
/// @class Focus
class Focus: public Mortal, public Position
{
   public:

      Focus(
            Real      theWidth,
            Real      theHeight,
            gt::Angle theAngle,
            gt::Vec2D thePosition,
            Integer   theTP,
            Real      theLifetime,
            Real      thePPS,
            System&   theSystem,
            Emitter&  theEmitter
            );
   /////////////////////////////////////////////////////////////////////////////
   //     METHODS
   /////////////////////////////////////////////////////////////////////////////
      /// @brief update 
      /// @param theElapsedTime
      void update(Real theElapsedTime);
   /////////////////////////////////////////////////////////////////////////////
   //     ACCESSORS AND MUTATORS
   /////////////////////////////////////////////////////////////////////////////
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
   /////////////////////////////////////////////////////////////////////////////
   //     VARIABLES
   /////////////////////////////////////////////////////////////////////////////
      Real      mWidth;   ///< Width.
      Real      mHeight;  ///< Height.
      gt::Angle mAngle;   ///< Angle.
      Integer   mTP;      ///< Total number of Particles. -1 = no number limits
      Integer   mEP;      ///< Particles already emitted by the focus.
      Real      mPPS;
      Emitter&  mEmitter;///< The emitter server for the focus.
      System&   mSystem;
   /////////////////////////////////////////////////////////////////////////////
   //     METHODS
   /////////////////////////////////////////////////////////////////////////////
      void emit(Integer theNParticles);
      Integer drain(Real theElapsedTime);
      Particle createParticle();
};
//////////////////////////////////////////////////////////////////////////////// 
//        END OF CLASS FOCUS
//////////////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////////////// 
//        INLINE METHODS 
//////////////////////////////////////////////////////////////////////////////// 
//------------------------------------------------------------------------------
//      Class:        Focus
//      Method:       getWidth
//      Description:  
//------------------------------------------------------------------------------
inline Real Focus::getWidth() const 
{
   return mWidth;
}
//------------------------------------------------------------------------------
//      Class:        Focus
//      Method:       setWidth
//      Description:  
//------------------------------------------------------------------------------
inline void Focus::setWidth(Real theWidth)
{
   mWidth=theWidth;
}
//------------------------------------------------------------------------------
//      Class:        Focus
//      Method:       getHeight
//      Description:  
//------------------------------------------------------------------------------
inline Real Focus::getHeight() const 
{
   return mHeight;
}
//------------------------------------------------------------------------------
//      Class:        Focus
//      Method:       setHeight
//      Description:  
//------------------------------------------------------------------------------
inline void Focus::setHeight(Real theHeight)
{
   mHeight=theHeight;
}
//------------------------------------------------------------------------------
//      Class:        Focus
//      Method:       getAngle
//      Description:  
//------------------------------------------------------------------------------
inline gt::Angle Focus::getAngle() const 
{
   return mAngle;
}
//------------------------------------------------------------------------------
//      Class:        Focus
//      Method:       setAngle
//      Description:  
//------------------------------------------------------------------------------
inline void Focus::setAngle(gt::Angle theAngle)
{
   mAngle=theAngle;
}
//------------------------------------------------------------------------------
//      Class:        Focus
//      Method:       drain
//      Description:  
//------------------------------------------------------------------------------
inline Integer Focus::drain(Real theElapsedTime)
{
   Integer nParticles = (mPPS * getAge() / 1000) - mEP;

   if( mEP + nParticles > mTP)
   {
      nParticles =  mTP - mEP;
      kill();
   }
   else
   {
      mEP += nParticles;
   }

   return nParticles;
}
////////////////////////////////////////////////////////////////////////////////
// END NAMESPACE mpe
////////////////////////////////////////////////////////////////////////////////
}
#endif   

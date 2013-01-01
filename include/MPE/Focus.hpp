/// @file Focus.hpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2012-12-21

#ifndef  FOCUS_INC
#define  FOCUS_INC

#include <list>
#include <limits>
#include <cfloat>
#include <GT/GT.hpp>
#include <MPE/Emitter.hpp>
#include <MPE/Particle.hpp>

namespace mpe
{
class System;
class Emitter;
class Particle;
////////////////////////////////////////////////////////////////////////////////
//             CLASS FOCUS
////////////////////////////////////////////////////////////////////////////////
/// @class Focus
class Focus
{
   public:
      const static Real MAX_REAL;
      const static Integer MAX_INTEGER;

      Focus(
            Real      theWidth,
            Real      theHeight,
            gt::Angle theAngle,
            gt::Vec2D thePosition,
            Integer   theTP,
            Real      theTT,
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
      /// @brief isAlive 
      /// @return 
      bool isAlive() const;
      /// @brief setAlive 
      /// @param theAlive
      void kill();
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
      /// @brief getPosition 
      /// @return 
      gt::Vec2D getPosition() const;
      /// @brief setPosition 
      /// @param thePosition
      void setPosition(gt::Vec2D thePosition);
      /// @brief getTP 
      /// @return 
   private:
   /////////////////////////////////////////////////////////////////////////////
   //     VARIABLES
   /////////////////////////////////////////////////////////////////////////////
      bool      mAlive;   ///< Life state.
      Real      mWidth;   ///< Width.
      Real      mHeight;  ///< Height.
      gt::Angle mAngle;   ///< Angle.
      gt::Vec2D mPosition;///< Position.
      Integer   mTP;      ///< Total number of Particles. -1 = no number limits
      Integer   mEP;      ///< Particles already emitted by the focus.
      Real      mTT;      ///< Time the focus will live. -1 = no time limits
      Real      mET;      ///< Elapsed time.
      Real      mPPS;
      Emitter&  mEmitter;///< The emitter server for the focus.
      System&   mSystem;
   /////////////////////////////////////////////////////////////////////////////
   //     METHODS
   /////////////////////////////////////////////////////////////////////////////
      void emit(Integer theNParticles);
      void age(Real theElapseTime);
      Integer drain(Real theElapsedTime);
      Particle createParticle();
};
//////////////////////////////////////////////////////////////////////////////// 
//        END OF CLASS FOCUS
//////////////////////////////////////////////////////////////////////////////// 
const static Integer MAX_INTEGER = std::numeric_limits<Integer>::max();
const static Real MAX_REAL = std::numeric_limits<Real>::max();
//////////////////////////////////////////////////////////////////////////////// 
//        INLINE METHODS 
//////////////////////////////////////////////////////////////////////////////// 
//------------------------------------------------------------------------------
//      Class:        Focus
//      Method:       isAlive
//      Description:  
//------------------------------------------------------------------------------
inline bool Focus::isAlive() const 
{
   return mAlive;
}
//------------------------------------------------------------------------------
//      Class:        Focus
//      Method:       kill
//      Description:  
//------------------------------------------------------------------------------
inline void Focus::kill()
{
   mAlive=false;
}
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
//      Method:       getPosition
//      Description:  
//------------------------------------------------------------------------------
inline gt::Vec2D Focus::getPosition() const 
{
   return mPosition;
}
//------------------------------------------------------------------------------
//      Class:        Focus
//      Method:       setPosition
//      Description:  
//------------------------------------------------------------------------------
inline void Focus::setPosition(gt::Vec2D thePosition)
{
   mPosition=thePosition;
}
//------------------------------------------------------------------------------
//      Class:        Focus
//      Method:       age
//      Description:  
//------------------------------------------------------------------------------
inline void Focus::age(Real theElapsedTime)
{
   if( mET+theElapsedTime >= mTT )
      kill();
   else
      mET += theElapsedTime;
}
//------------------------------------------------------------------------------
//      Class:        Focus
//      Method:       drain
//      Description:  
//------------------------------------------------------------------------------
inline Integer Focus::drain(Real theElapsedTime)
{
   Integer nParticles = 0;
   if(isAlive())
   {
      nParticles = (mPPS * mET / 1000) - mEP;
   }
   if(mEP + nParticles > mTT)
   {
      nParticles = nParticles - (mEP + nParticles - mTT);
      kill();
   }
   return nParticles;
}
////////////////////////////////////////////////////////////////////////////////
// END NAMESPACE mpe
////////////////////////////////////////////////////////////////////////////////
}
#endif   

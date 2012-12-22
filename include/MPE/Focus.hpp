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
////////////////////////////////////////////////////////////////////////////////
//             CLASS FOCUS
////////////////////////////////////////////////////////////////////////////////
class Focus
{
   public:
      const static Real TIME_INFINITY;
      const static Integer PARTICLES_INFINITY;

      Focus(
            Real theWidth,
            Real theHeight,
            gt::Angle theAngle,
            gt::Vec2D thePosition,
            Integer theTP,
            Real theTT,
            Emitter::Ptr theEmitter,
            System& theSystem
            );
   /////////////////////////////////////////////////////////////////////////////
   //     METHODS
   /////////////////////////////////////////////////////////////////////////////
      /// @brief update 
      /// @param theElapsedTime
      void update(Real theElapsedTime);
      void age(Real theElapseTime);
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
      Emitter::Ptr getEmitter() const;
      /// @brief setEmitter 
      /// @param theEmitter
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
      Emitter::Ptr mEmitter;///< The emitter server for the focus.
      System&   mSystem;
      std::list<Particle> mParticles;
      
   /////////////////////////////////////////////////////////////////////////////
   //     METHODS
   /////////////////////////////////////////////////////////////////////////////
      void emit();
};
//////////////////////////////////////////////////////////////////////////////// 
//        END OF CLASS FOCUS
//////////////////////////////////////////////////////////////////////////////// 
const static Integer PARTICLES_INFINITY = std::numeric_limits<Integer>::max();
const static Real TIME_INFINITY = std::numeric_limits<Real>::max();
//////////////////////////////////////////////////////////////////////////////// 
//        INLINE METHODS 
//////////////////////////////////////////////////////////////////////////////// 
inline bool Focus::isAlive() const 
{
   return mAlive;
}
inline void Focus::kill()
{
   mAlive=false;
}
inline Real Focus::getWidth() const 
{
   return mWidth;
}
inline void Focus::setWidth(Real theWidth)
{
   mWidth=theWidth;
}
inline Real Focus::getHeight() const 
{
   return mHeight;
}
inline void Focus::setHeight(Real theHeight)
{
   mHeight=theHeight;
}
inline gt::Angle Focus::getAngle() const 
{
   return mAngle;
}
inline void Focus::setAngle(gt::Angle theAngle)
{
   mAngle=theAngle;
}
inline gt::Vec2D Focus::getPosition() const 
{
   return mPosition;
}
inline void Focus::setPosition(gt::Vec2D thePosition)
{
   mPosition=thePosition;
}
inline void Focus::age(Real theElapsedTime)
{
   mET += theElapsedTime;
   if(mET >= mTT)
      mAlive = false;
}
}
#endif   
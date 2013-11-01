/// @file Focus.hpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2012-12-21

#ifndef  FOCUS_INC
#define  FOCUS_INC

#include <memory>
#include <MPE/Config.hpp>
#include <MPE/classes/Particle.hpp>

namespace mpe
{
////////////////////////////////////////////////////////////////////////////////
//             CLASS FOCUS
////////////////////////////////////////////////////////////////////////////////
/// @class Focus
class Focus: public Mortal
{
public:
   //////////////////////////////////////////////////////////////////////////
   // STATIC  METHODS
   //////////////////////////////////////////////////////////////////////////
   /// @brief create
   /// @param theLifetime
   /// @param theWidth
   /// @param theHeight
   /// @param thePosition
   /// @param theAngle
   /// @param theTP
   /// @param thePPS
   /// @param theGroups
   /// @param theEmitter
   /// @return
   static FocusPtr create(const Emitter&  theEmitter);
   //////////////////////////////////////////////////////////////////////////
   //     METHODS
   //////////////////////////////////////////////////////////////////////////
   /// @brief update
   /// @param theElapsedTime
   void update(Real theElapsedTime);
   //////////////////////////////////////////////////////////////////////////
   //     ACCESSORS AND MUTATORS
   //////////////////////////////////////////////////////////////////////////
   /// @brief getPosition
   /// @return
   Vec2 getPosition() const;
   /// @brief setPosition
   /// @param thePosition
   void setPosition(Vec2 thePosition);
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
   Real getAngle() const;
   /// @brief setAngle
   /// @param theAngle
   void setAngle(Real theAngle);
   /// @brief setNP
   /// @param theNP
   void resetNP(Real theNP);
   /// @brief setPPS
   /// @param thePPS
   void setPPS(Real thePPS);
   /// @brief getPPS
   /// @return
   Real getPPS();
   /// @brief addGroups 
   /// @param theGroups
   void addGroups(GroupID theGroups);
   /// @brief removeGroups 
   /// @param theGroups
   void removeGroups(GroupID theGroups);
   /// @brief removeFromAllGroups 
   void removeFromAllGroups();

private:
   //////////////////////////////////////////////////////////////////////////
   //     VARIABLES
   //////////////////////////////////////////////////////////////////////////
   Real      mWidth;   ///< Width.
   Real      mHeight;  ///< Height.
   Vec2      mPosition;
   Real      mAngle;   ///< Angle.
   Integer   mTP;      ///< Total number of Particles. -1 = no number limits
   Integer   mEP;      ///< Particles already emitted by the focus.
   Real      mPPS;
   Real      mTimeAcum;
   GroupID   mGroups;
   const Emitter&  mEmitter;///< The emitter server for the focus.
   //////////////////////////////////////////////////////////////////////////
   //     METHODS
   //////////////////////////////////////////////////////////////////////////
   Focus(const Emitter&  theEmitter);

   void emit(Integer theNParticles);
   
   void initParticle();

   Integer drain(Real theElapsedTime);

   Particle createParticle();
};
}
#endif

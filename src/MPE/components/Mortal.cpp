#include <MPE/components/Mortal.hpp>

namespace mpe
{
//------------------------------------------------------------------------------
//      Class:        Mortal
//      Method:       constructor
//      Description:  
//------------------------------------------------------------------------------
Mortal::Mortal(Real theLifetime):
   mAlive(true),
   mLifetime(theLifetime),
   mAge(0)
{}
//------------------------------------------------------------------------------
//      Class:        Mortal
//      Method:       isAlive
//      Description:  
//------------------------------------------------------------------------------
bool Mortal::isAlive()
{
   return mAlive;
}
//------------------------------------------------------------------------------
//      Class:        Mortal
//      Method:       age
//      Description:  
//------------------------------------------------------------------------------
void Mortal::age(Real theElapsedTime)
{
   mAge += theElapsedTime;
   if (mAge > mLifetime)
      die();
}
//------------------------------------------------------------------------------
//      Class:        Mortal
//      Method:       die
//      Description:  
//------------------------------------------------------------------------------
void Mortal::die()
{
   mAlive=false;
}
//------------------------------------------------------------------------------
//      Class:        Mortal
//      Method:       kill
//      Description:  
//------------------------------------------------------------------------------
void Mortal::kill()
{
   mAlive=false;
}
//------------------------------------------------------------------------------
//      Class:        Mortal
//      Method:       getAge
//      Description:  
//------------------------------------------------------------------------------
Real Mortal::getAge() const
{
   return mAge;
}
}

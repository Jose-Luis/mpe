#include <MPE/classes/Mortal.hpp>

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
}


#ifndef  CONFIG_INC
#define  CONFIG_INC

#include <cmath>

struct Angle
{
   float value;
   float sin;
   float cos;
    
   inline void set(float theValue)
   {
      value = theValue;
      sin =  std::sin(theValue);
      cos = std::cos(theValue);
   }
};

#endif   // ----- #ifndef CONFIG_INC  -----

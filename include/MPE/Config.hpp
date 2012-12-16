#ifndef  CONFIG_INC
#define  CONFIG_INC

#include <cmath>
#include <ctime>
#include <cstdlib>

typedef float Real;
typedef int Integer;

struct Angle
{
   Real value;
   Real sin;
   Real cos;

   inline void set(Real theValue)
   {
      value = theValue;
      sin =  std::sin(theValue);
      cos = std::cos(theValue);
   }

   Angle& operator=(Real theValue)
   {
      set(theValue);
      return *this;
   }
};

class Randomizer
{

   private:

      Real min;
      Real max;

   public:

      Randomizer()
      {
         min = -1;
         max = 1;
      }

      Randomizer(Real theA,Real theB)
      {
        if ( theA > theB)
        { 
           max=theA;
           min=theB;
        }
        else
        {
           max = theB;
           min = theA;
        }
      }

      static inline void init()
      {
         std::srand(std::time(NULL));
      }

      static inline Real get(Real theMin, Real theMax)
      {
         return (theMax-theMin) * std::rand() / RAND_MAX + theMin;
      }

      Real get()
      {
         return (max-min) * std::rand() / RAND_MAX + min;
      }
};


#endif   // ----- #ifndef CONFIG_INC  -----

/// @file Randomizer.hpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2012-12-19

#ifndef  RANDOMIZER_INC
#define  RANDOMIZER_INC

#include <ctime>
#include <cstdlib>
#include <GT/Config.hpp>

namespace gt
{
class Randomizer
{
   public:

      /// @brief Randomizer 
      Randomizer();
      /// @brief Randomizer 
      /// @param theA
      /// @param theB
      Randomizer(Real theA,Real theB);
      /// @brief init 
      static inline void init();
      /// @brief get 
      /// @param theMin
      /// @param theMax
      /// @return 
      static inline Real get(Real theMin, Real theMax);
      /// @brief get 
      /// @return 
      Real get();

   private:

      Real mMin;
      Real mMax;
};
}
#endif   // ----- #ifndef RANDOMIZER_INC  -----

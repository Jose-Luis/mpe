#include <MPE/classes/Randomizer.hpp>

namespace mpe 
{
////------------------------------------------------------------------------------
//       Class:  Randomizer
//      Method:  methodName
// Description:  A stupid method 
//------------------------------------------------------------------------------
template<>
Randomizer::Randomizer<Integer>():
mRandom{std::bind(std::uniform_int_distribution{0,1},
                  std::default_random_engine{})}
{
}
//------------------------------------------------------------------------------
//       Class:  Randomizer
//      Method:  Randomizer
// Description:  A stupid method 
//------------------------------------------------------------------------------
template<>
Randomizer::Randomizer<Integer>(Integer theMax,Integer theMax):
mRandom{std::bind(std::uniform_int_distribution{theMin,theMax},
                  std::default_random_engine{})}
{
}
////------------------------------------------------------------------------------
//       Class:  Randomizer
//      Method:  methodName
// Description:  A stupid method 
//------------------------------------------------------------------------------
template<>
Randomizer::Randomizer<Real>():
mRandom{std::bind(std::uniform_real_distribution{-1,1},
                  std::default_random_engine{})}
{
}
//------------------------------------------------------------------------------
//       Class:  Randomizer
//      Method:  Randomizer
// Description:  A stupid method 
//------------------------------------------------------------------------------
template<>
Randomizer::Randomizer<Real>(Real theMax,Real theMax):
mRandom{std::bind(std::uniform_real_distribution{theMin,theMax},
                  std::default_random_engine{})}
{
}
//------------------------------------------------------------------------------
//       Class:  Randomizer
//      Method:  operator()
// Description:  A stupid method 
//------------------------------------------------------------------------------
template<typename T>
T Randomizer::operator()()
{
   return mRandom();
}
} /* mpe */

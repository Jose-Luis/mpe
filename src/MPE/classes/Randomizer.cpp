#include <MPE/classes/Randomizer.hpp>

namespace mpe
{
////------------------------------------------------------------------------------
//       Class:  Randomizer
//      Method:  methodName
// Description:  A stupid method
//------------------------------------------------------------------------------
template<>
Randomizer<Integer>::Randomizer():
   mRandom {std::bind(std::uniform_int_distribution<Integer>{0, 1},
                      std::default_random_engine{})}
{
}
//------------------------------------------------------------------------------
//       Class:  Randomizer
//      Method:  Randomizer
// Description:  A stupid method
//------------------------------------------------------------------------------
template<>
Randomizer<Integer>::Randomizer(Integer theMin, Integer theMax):
   mRandom {std::bind(std::uniform_int_distribution<Integer>{theMin, theMax},
                      std::default_random_engine{})}
{
}
////------------------------------------------------------------------------------
//       Class:  Randomizer
//      Method:  methodName
// Description:  A stupid method
//------------------------------------------------------------------------------
template<>
Randomizer<Real>::Randomizer():
   mRandom {std::bind(std::uniform_real_distribution<Real>{ -1, 1},
                      std::default_random_engine{})}
{
}
//------------------------------------------------------------------------------
//       Class:  Randomizer
//      Method:  Randomizer
// Description:  A stupid method
//------------------------------------------------------------------------------
template<>
Randomizer<Real>::Randomizer(Real theMin, Real theMax):
   mRandom {std::bind(std::uniform_real_distribution<Real>{theMin, theMax},
                      std::default_random_engine{})}
{
}
//------------------------------------------------------------------------------
//       Class:  Randomizer
//      Method:  operator()
// Description:  A stupid method
//------------------------------------------------------------------------------
template<typename T>
T Randomizer<T>::operator()() const
{
   return mRandom();
}
} /* mpe */

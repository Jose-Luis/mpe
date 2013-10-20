#include <MPE/classes/Generator.hpp>

namespace mpe
{
//------------------------------------------------------------------------------
//       Class:  Generator
//      Method:  Generator
// Description:  A stupid method 
//------------------------------------------------------------------------------
template<typename T>
Generator<T>::Generator(T theNumber):
   mGenerator{[theNumber](){return theNumber;}}
{
}
////------------------------------------------------------------------------------
//       Class:  Generator
//      Method:  methodName
// Description:  A stupid method
//------------------------------------------------------------------------------
template<>
Generator<Integer>::Generator():
   mGenerator {std::bind(std::uniform_int_distribution<Integer>{0, 1},
                      std::default_random_engine{std::random_device{}()})}
{
}
//------------------------------------------------------------------------------
//       Class:  Generator
//      Method:  Generator
// Description:  A stupid method
//------------------------------------------------------------------------------
template<>
Generator<Integer>::Generator(Integer theMin, Integer theMax):
   mGenerator {std::bind(std::uniform_int_distribution<Integer>{theMin, theMax},
                      std::default_random_engine{std::random_device{}()})}
{
}
////------------------------------------------------------------------------------
//       Class:  Generator
//      Method:  methodName
// Description:  A stupid method
//------------------------------------------------------------------------------
template<>
Generator<Real>::Generator():
   mGenerator {std::bind(std::uniform_real_distribution<Real>{ -1, 1},
                      std::default_random_engine{std::random_device{}()})}
{
}
//------------------------------------------------------------------------------
//       Class:  Generator
//      Method:  Generator
// Description:  A stupid method
//------------------------------------------------------------------------------
template<>
Generator<Real>::Generator(Real theMin, Real theMax):
   mGenerator {std::bind(std::uniform_real_distribution<Real>{theMin, theMax},
                      std::default_random_engine{std::random_device{}()})}
{
}
//------------------------------------------------------------------------------
//       Class:  Generator
//      Method:  operator()
// Description:  A stupid method
//------------------------------------------------------------------------------
template<typename T>
T Generator<T>::operator()() const
{
   return mGenerator();
}
//------------------------------------------------------------------------------
//       Class:  Generator
//      Method:  methodName
// Description:  A stupid method 
//------------------------------------------------------------------------------
template<typename T>
Generator<T> Generator<T>::create(T theMin, T theMax)
{
   return theMin==theMax?Generator<T>(theMin):Generator<T>(theMin,theMax);
}
///////////////////////////////////////////////////////////////////////////////
template class Generator<Integer>;
template class Generator<Real>;
////////////////////////////////////////////////////////////////////////////////
} /* mpe */

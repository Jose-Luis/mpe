#ifndef RANDOMIZER_TL9DCTRC
#define RANDOMIZER_TL9DCTRC

#include <random>
#include <functional>
#include <MPE/Config.hpp>

namespace mpe
{

template<typename T>
class Randomizer
{

public:
   Randomizer();
   Randomizer(T min, T max);
   T operator()() const;

private:
   std::function<T()> mRandom;

};

} /* mpe */

#endif /* end of include guard: RANDOMIZER_TL9DCTRC */

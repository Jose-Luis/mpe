#ifndef GENERATOR_TL9DCTRC
#define GENERATOR_TL9DCTRC

#include <random>
#include <functional>
#include <MPE/Config.hpp>

namespace mpe
{

template<typename T>
class Generator
{
public:
   Generator();
   Generator(T theNumber);
   Generator(T theMin, T theMax);
   T operator()() const;

private:
   std::function<T()> mGenerator;
   static std::default_random_engine sEngine;
};
} /* mpe */

#endif /* end of include guard: GENERATOR_TL9DCTRC */

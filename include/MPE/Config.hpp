
#ifndef  CONFIG_MPE_INC
#define  CONFIG_MPE_INC

#include <string>
#include <limits>
#include <cmath>
#include <GT/GT.hpp>

namespace mpe
{
class System;
class Focus;
class Emitter;
class Particle;

typedef std::string EmitterID;

const Integer MAX_INTEGER = std::numeric_limits<Integer>::max();
const Real REAL_INFINITY = std::numeric_limits<Real>::infinity();
}
#endif   // ----- #ifndef CONFIG_INC  -----


#ifndef  CONFIG_MPE_INC
#define  CONFIG_MPE_INC

#include <string>
#include <limits>
#include <cmath>
#include <boost/shared_ptr.hpp>
#include <GT/GT.hpp>

namespace mpe
{
class System;
class Focus;
class Affector;
class Emitter;
class Particle;
class Mortal;
class Position;

typedef std::string EmitterID;
typedef boost::shared_ptr<Focus> FocusPtr;
typedef boost::shared_ptr<Affector> AffectorPtr;

const Integer MAX_INTEGER = std::numeric_limits<Integer>::max();
const Real REAL_INFINITY = std::numeric_limits<Real>::infinity();
}
#endif   // ----- #ifndef CONFIG_INC  -----

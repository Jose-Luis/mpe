#include <MPE/classes/ParticleContainer.hpp>
namespace mpe 
{
   
//------------------------------------------------------------------------------
//       Class:  ParticleContainer
//      Method:  ParticleContainer
// Description:  Constructor 
//------------------------------------------------------------------------------
ParticleContainer::ParticleContainer(size_t theSize, bool theFixed):
   mParticles{new Particle[theSize]},
   mSize{0},
   mMaxSize{theSize},
   mFixedSize(theFixed)
{
}
//------------------------------------------------------------------------------
//       Class:  ParticleContainer
//      Method:  ParticleContainer
// Description:  Destructor 
//------------------------------------------------------------------------------
ParticleContainer::~ParticleContainer()
{
   delete[]mParticles;
}
//------------------------------------------------------------------------------
//       Class:  ParticleContainer
//      Method:  grow
// Description:  Increasing the size 
//------------------------------------------------------------------------------
bool ParticleContainer::grow()
{
   Particle* aParticles{new Particle[mMaxSize*2]};

   if (aParticles)
   {
      std::memcpy(aParticles,mParticles,sizeof(Particle)*mSize);
      mMaxSize *= 2;
      delete[] mParticles;
      mParticles = aParticles;

      return true;
   }
   return false;
}
//------------------------------------------------------------------------------
//       Class:  ParticleContainer
//      Method:  addParticle
// Description:  A stupid method 
//------------------------------------------------------------------------------
Particle* ParticleContainer::addParticle()            
{

      if( (mSize < mMaxSize) || (!mFixedSize && grow()) )
      {
         mSize++;
         return mParticles + mSize - 1;
      }
      return nullptr;
}
//------------------------------------------------------------------------------
//       Class:  ParticleContainer
//      Method:  remo
// Description:  A stupid method 
//------------------------------------------------------------------------------
void ParticleContainer::removeParticle(Particle* theParticle)
{
   if(mSize)
   {
      *theParticle = mParticles[mSize - 1];
      mSize--;
   }
}
} /* mpe */

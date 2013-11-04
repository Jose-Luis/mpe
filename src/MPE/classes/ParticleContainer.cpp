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
//      Method:  setSize
// Description:  A stupid method 
//------------------------------------------------------------------------------
bool ParticleContainer::setSize(size_t theNumberOfParticles)
{
   Particle* aParticles{new Particle[theNumberOfParticles]};

   if (aParticles)
   {
      mMaxSize = theNumberOfParticles; 
      size_t aSize = theNumberOfParticles>mSize?mSize:theNumberOfParticles;

      std::memcpy(aParticles,mParticles,sizeof(Particle)*aSize);
      delete[] mParticles;
      mParticles = aParticles;

      return true;
   }
   return false;
}
//------------------------------------------------------------------------------
//       Class:  ParticleContainer
//      Method:  grow
// Description:  Increasing the size 
//------------------------------------------------------------------------------
bool ParticleContainer::grow()
{
   return setSize(mMaxSize*2);
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

#include <MPE/Emitter.hpp>

namespace MPE
{     
   Emitter::Emitter()
   {
   }

   Emitter::Emitter(System::Ptr theSystem):
      mSystem(theSystem)
   {
   }

   Emitter::Ptr Emitter::create()
   {
      return boost::make_shared<Emitter>();
   }

   Emitter::Ptr Emitter::create(System::Ptr theSystem)
   {
      return boost::make_shared<Emitter>(theSystem);
   }
}


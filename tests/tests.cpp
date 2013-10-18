#include <iostream>
#include <MPE/MPE.hpp>


int test1()
{
   mpe::System aParticleSystem;
   bool aBoolean = aParticleSystem.initFromFile("Emitter.xml");

   if (aBoolean)
   {
      std::cout << "Particle system init from 'Emitter.xml'";
      mpe::Emitter& aEmitter = aParticleSystem.getEmitter("Emitter1");
      std::cout << aEmitter.getID() << " TextRect: "  << aEmitter.getTextRect().width<< "   "<< aEmitter.getTextRect().height << "\n";
      std::cout << aEmitter.getFocusWidth() << "  " << aEmitter.getParticleAngle() ;
   }
   else
   {
      std::cout << "Something was wrong...";
   }

   return EXIT_SUCCESS;
}

int test2()
{
   std::cout <<  "\nParticle size: " <<sizeof(mpe::Particle);

   return EXIT_SUCCESS;
}

int main(void)
{
   test1();
   test2();
   return EXIT_SUCCESS;
}

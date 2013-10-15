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

   return 33;
}

int main(void)
{
   test1();
   mpe::Generator<float> aGen{12.7};
   mpe::Generator<float> aGen1{10,23.5};
   std::cout << "\n\n" << aGen() << "\n" << aGen1();
   return EXIT_SUCCESS;
}

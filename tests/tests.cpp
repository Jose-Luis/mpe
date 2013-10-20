#include <iostream>
#include <MPE/MPE.hpp>


int test1()
{
   mpe::System aParticleSystem{1024};
   bool aBoolean = aParticleSystem.initFromFile("Emitter.xml");

   if (aBoolean)
   {
      std::cout << "Particle system init from 'Emitter.xml'";
      mpe::Emitter& aEmitter = aParticleSystem.getEmitter("Emitter1");
      std::cout << aEmitter.getID() << " TextRect: "  << aEmitter.getTextRect().width<< "   "<< aEmitter.getTextRect().height << "\n";
      std::cout << aEmitter.getFocusTOL() << "  " << aEmitter.getParticleAngle() ;
   }
   else
   {
      std::cout << "Something was wrong...";
   }
   
   mpe::FocusPtr aFocus{aParticleSystem.createFocus("Emitter1",mpe::Vec2(0,0),0)};
   aParticleSystem.addFocus(aFocus);
   for (int i=0; i<60;++i)
   {
      aParticleSystem.update(100);
      std::cout << "\nNumber of Particles: " << aParticleSystem.getParticlesSize();
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

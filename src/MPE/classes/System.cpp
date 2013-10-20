/// @file System.cpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2012-12-18

#include <MPE/classes/System.hpp>

namespace mpe
{
//------------------------------------------------------------------------------
//      Class:        System
//      Method:       getXFactor
//      Description:
//------------------------------------------------------------------------------
Real System::getXFactor() const
{
   return mXFactor;
}
//------------------------------------------------------------------------------
//      Class:        System
//      Method:       setXFactor
//      Description:
//------------------------------------------------------------------------------
void System::setXFactor(Real theXFactor)
{
   mXFactor = theXFactor;
}
//------------------------------------------------------------------------------
//      Class:        System
//      Method:       getYFactor
//      Description:
//------------------------------------------------------------------------------
Real System::getYFactor() const
{
   return mYFactor;
}
//------------------------------------------------------------------------------
//      Class:        System
//      Method:       setYFactor
//      Description:
//------------------------------------------------------------------------------
void System::setYFactor(Real theYFactor)
{
   mYFactor = theYFactor;
}
//------------------------------------------------------------------------------
//       Class:  System
//      Method:  System
// Description:
//------------------------------------------------------------------------------
System::System (size_t theNParticles,bool theFixed):
   mXFactor{1},
   mYFactor{1},
   mParticles{theNParticles,theFixed}
{
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  addEmitter
// Description:
//------------------------------------------------------------------------------
void System::addEmitter(Emitter& theEmitter)
{
   EmitterID anEmitterID = theEmitter.getID();
   auto it = mEmitters.find(anEmitterID);

   if (it == mEmitters.end() )
   {
      theEmitter.setSystem(this);
      mEmitters.insert(std::pair<EmitterID, Emitter>(anEmitterID, theEmitter));
   }
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  addFocus
// Description:
//------------------------------------------------------------------------------
void System::addAffector(AffectorPtr theAffector)
{
   mAffectors.push_back(theAffector);
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  addFocus
// Description:
//------------------------------------------------------------------------------
void System::addFocus(FocusPtr theFocus)
{
   mFocusses.push_back(theFocus);
}
//------------------------------------------------------------------------------
//       Class:  Emitter
//      Method:  createFocus
// Description:
//------------------------------------------------------------------------------
FocusPtr System::createFocus(EmitterID theEmitterID,
                             Vec2  thePosition,
                             Real       theAngle,
                             GroupID    theGroups)
{
   return getEmitter(theEmitterID).createFocus(thePosition, theAngle, theGroups);
}
//------------------------------------------------------------------------------
//       Class:  System
//      Method:  addParticle
// Description:
//------------------------------------------------------------------------------
Particle* System::addParticle ()
{
   return mParticles.addParticle();
}
//------------------------------------------------------------------------------
//       Class:  System
//      Method:  getEmitter
// Description:
//------------------------------------------------------------------------------
Emitter& System::getEmitter ( EmitterID theEmitterID )
{

   auto it = mEmitters.find(theEmitterID);

   if (it != mEmitters.end() )
   {
      return it->second;
   }

   return Emitter::DUMMY;
}
//------------------------------------------------------------------------------
//       Class:  System
//      Method:  update
// Description:
//------------------------------------------------------------------------------
void System::updateFocusses(Real theElapsedTime)
{
   for (auto it = mFocusses.begin(); it != mFocusses.end(); it++)
   {
      if ((*it)->isAlive())
      {
         (*it)->update(theElapsedTime);
      }
      else
      {
         it = mFocusses.erase(it);
         it--;
      }
   }
}
//------------------------------------------------------------------------------
//       Class:  System
//      Method:  update
// Description:
//------------------------------------------------------------------------------
void System::updateParticles(Real theElapsedTime)
{
   for (auto affector =  mAffectors.begin();
         affector != mAffectors.end();
         affector++)
   {
      if ( (*affector)->isAlive() )
      {
         (*affector)->update(theElapsedTime);

         for (auto particle =  mParticles.begin();
               particle != mParticles.end();
               particle++)
         {
            (*affector)->affect(*particle, theElapsedTime);
         }
      }
      else
      {
         affector = mAffectors.erase(affector);
         affector++;
      }
   }

   for (auto particle =  mParticles.begin();
         particle < mParticles.end();
         particle++)
   {
      if(particle->isAlive())
      {
         particle->update(theElapsedTime);
      }
      else
      {
          mParticles.removeParticle(particle);
      }
   }

}
//------------------------------------------------------------------------------
//       Class:  System
//      Method:  update
// Description:
//------------------------------------------------------------------------------
void System::update (Real theElapsedTime)
{
   updateFocusses(theElapsedTime);
   updateParticles(theElapsedTime);
}
//------------------------------------------------------------------------------
//       Class:  System
//      Method:  initFromFile
// Description:  load the emitter from an xml file
//------------------------------------------------------------------------------
bool System::initFromFile(std::string theFilename)
{
   tinyxml2::XMLDocument aFile;

   if (tinyxml2::XML_NO_ERROR != aFile.LoadFile(theFilename.c_str()))
   {
      return false;
   }

   tinyxml2::XMLElement* aEmittersNode {aFile.FirstChildElement("emitters")};

   if(!aEmittersNode)
   {
      return false;
   }

   tinyxml2::XMLElement* aEmitterNode {aEmittersNode->FirstChildElement("emitter")};

   while(aEmitterNode)
   {
      Emitter aEmitter {aEmitterNode->Attribute("id")};
      std::string aShape {aEmitterNode->Attribute("shape")};

      if(aShape == "CIRCLE")
      {
         aEmitter.setShape(Emitter::CIRCLE);
      }
      else if (aShape == "RECTANGLE")
      {
         aEmitter.setShape(Emitter::RECTANGLE);
      }

      std::string aDispersion {aEmitterNode->Attribute("dispersion")};

      if(aDispersion == "LINEAR")
      {
         aEmitter.setDispersion(Emitter::LINEAR);
      }
      else if(aDispersion == "RADIAL")
      {
         aEmitter.setDispersion(Emitter::RADIAL);
      }
      else if(aDispersion == "REFLECT")
      {
         aEmitter.setDispersion(Emitter::REFLECT);
      }
      else if(aDispersion == "RANDOM")
      {
         aEmitter.setDispersion(Emitter::RANDOM);
      }
      else if(aDispersion == "STATIC")
      {
         aEmitter.setDispersion(Emitter::STATIC);
      }

      tinyxml2::XMLElement* aTextRectNode {aEmitterNode->FirstChildElement("textRect")};

      if(!aTextRectNode)
      {
         return false;
      }

      aEmitter.setTextRect(TextRect {aTextRectNode->IntAttribute("x"),
                                     aTextRectNode->IntAttribute("y"),
                                     aTextRectNode->IntAttribute("width"),
                                     aTextRectNode->IntAttribute("height")
                                    });

      tinyxml2::XMLElement* aGeneratorNode {aEmitterNode->FirstChildElement("ranges")};

      if(!aGeneratorNode)
      {
         return false;
      }

      tinyxml2::XMLElement* aNode {aGeneratorNode->FirstChildElement("focusTOL")};

      if(!aNode)
      {
         return false;
      }

      aEmitter.setGeneratorFocusTOL(aNode->FloatAttribute("min"),
                                aNode->FloatAttribute("max"));

      aNode = aGeneratorNode->FirstChildElement("focusWidth");

      if(!aNode)
      {
         return false;
      }

      //float aFloat{aNode->FloatAttribute("min")};
      //float aFloat1{aNode->FloatAttribute("max")};

      aEmitter.setGeneratorFocusWidth(aNode->FloatAttribute("min"),
                                  aNode->FloatAttribute("max"));

      aNode = aGeneratorNode->FirstChildElement("focusHeight");

      if(!aNode)
      {
         return false;
      }

      aEmitter.setGeneratorFocusHeight(aNode->FloatAttribute("min"),
                                   aNode->FloatAttribute("max"));

      aNode = aGeneratorNode->FirstChildElement("focusNP");

      if(!aNode)
      {
         return false;
      }

      aEmitter.setGeneratorFocusNP(aNode->IntAttribute("min"),
                               aNode->IntAttribute("max"));

      aNode = aGeneratorNode->FirstChildElement("focusPPS");

      if(!aNode)
      {
         return false;
      }

      aEmitter.setGeneratorFocusPPS(aNode->FloatAttribute("min"),
                                aNode->FloatAttribute("max"));

      aNode = aGeneratorNode->FirstChildElement("particleTOL") ;

      if(!aNode)
      {
         return false;
      }

      aEmitter.setGeneratorParticleTOL(aNode->FloatAttribute("min"),
                                   aNode->FloatAttribute("max"));

      aNode = aGeneratorNode->FirstChildElement("particleSize") ;

      if(!aNode)
      {
         return false;
      }

      aEmitter.setGeneratorParticleSize(aNode->FloatAttribute("min"),
                                     aNode->FloatAttribute("max"));


      aNode = aGeneratorNode->FirstChildElement("particleAngle") ;

      if(!aNode)
      {
         return false;
      }

      aEmitter.setGeneratorParticleAngle(aNode->FloatAttribute("min"),
                                     aNode->FloatAttribute("max"));

      aNode = aGeneratorNode->FirstChildElement("particleLV") ;

      if(!aNode)
      {
         return false;
      }

      aEmitter.setGeneratorParticleLV(aNode->FloatAttribute("min"),
                                  aNode->FloatAttribute("max"));

      aNode = aGeneratorNode->FirstChildElement("particleAV") ;

      if(!aNode)
      {
         return false;
      }

      aEmitter.setGeneratorParticleAV(aNode->FloatAttribute("min"),
                                  aNode->FloatAttribute("max"));

      addEmitter(aEmitter);
      aEmitterNode = aEmitterNode->NextSiblingElement("emitter");
   }
   return true;
}
//------------------------------------------------------------------------------
//       Class:  System
//      Method:  getParticlesSize
// Description:  A stupid method 
//------------------------------------------------------------------------------
Integer System::getParticlesSize()
{
   return mParticles.size();
}
////////////////////////////////////// END NAMESPACE  mpe //////////////////////
}


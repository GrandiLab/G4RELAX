/////////////////////////////
// Nickolas Upole          //
// University of Chicago   //
// Winter 2016             //
// RELAXPhysicsList.cc     //
/////////////////////////////

#include "RELAXPhysicsList.hh"
#include "G4EmLivermorePhysics.hh"

RELAXPhysicsList::RELAXPhysicsList() : G4VUserPhysicsList()
{

}

RELAXPhysicsList::~RELAXPhysicsList()
{

}

void RELAXPhysicsList::ConstructParticle()
{
  ConstructBosons();
  ConstructLeptons();
  ConstructHadrons();
  ConstructShortLived();
}

void RELAXPhysicsList::ConstructBosons()
{
  G4Geantino::GeantinoDefinition();
  G4ChargedGeantino::ChargedGeantinoDefinition();
  G4Gamma::GammaDefinition();
  G4OpticalPhoton::OpticalPhotonDefinition();
}

void RELAXPhysicsList::ConstructLeptons()
{
  G4Electron::ElectronDefinition();
  G4Positron::PositronDefinition();
  G4MuonPlus::MuonPlusDefinition();
  G4MuonMinus::MuonMinusDefinition();
  G4NeutrinoE::NeutrinoEDefinition();
  G4AntiNeutrinoE::AntiNeutrinoEDefinition();
  G4NeutrinoMu::NeutrinoMuDefinition();
  G4AntiNeutrinoMu::AntiNeutrinoMuDefinition();
}

void RELAXPhysicsList::ConstructHadrons()
{
  pMesonConstructor = new G4MesonConstructor();
  pMesonConstructor->ConstructParticle();
  pBaryonConstructor = new G4BaryonConstructor();
  pBaryonConstructor->ConstructParticle();
  pIonConstructor = new G4IonConstructor();
  pIonConstructor->ConstructParticle();
}

void RELAXPhysicsList::ConstructShortLived()
{

}

void RELAXPhysicsList::ConstructProcess()
{
  ConstructEMPhysics();
  ConstructHadronPhysics();
  ConstructOpticalPhotonPhysics();
  ConstructDecayPhysics();
  AddTransportation();
}

void RELAXPhysicsList::ConstructEMPhysics()
{
  G4VPhysicsConstructor* pEMPhysicsList;
  pEMPhysicsList = new G4EmLivermorePhysics();
  pEMPhysicsList->ConstructProcess();
}

void RELAXPhysicsList::ConstructHadronPhysics()
{

}

void RELAXPhysicsList::ConstructOpticalPhotonPhysics()
{
  // Set up General Scintillation Process
  pGeneralScintillation = new G4Scintillation("Scintillation");

  // Reset the particle iterator
  auto theParticleIterator = GetParticleIterator();
  theParticleIterator->reset();

  // Loop over all particles
  while((*theParticleIterator)())
  {
    // Get Loop Variables
    pParticle = theParticleIterator->value();
    particleName = pParticle->GetParticleName();
    pProcessManager = pParticle->GetProcessManager();

    if(pGeneralScintillation->IsApplicable(*pParticle))
    {
      if(particleName == "GenericIon")
      {
        pProcessManager->AddProcess(pNucleusScintillation = new G4Scintillation("Scintillation"));
        pProcessManager->SetProcessOrderingToLast(pNucleusScintillation, idxAtRest);
        pProcessManager->SetProcessOrderingToLast(pNucleusScintillation, idxPostStep);

        pNucleusScintillation->SetTrackSecondariesFirst(true);
        pNucleusScintillation->SetScintillationYieldFactor(0.2);
        pNucleusScintillation->SetScintillationExcitationRatio(1.0);
      }

      else if(particleName == "alpha")
      {
        pProcessManager->AddProcess(pAlphaScintillation = new G4Scintillation("Scintillation"));
        pProcessManager->SetProcessOrderingToLast(pAlphaScintillation, idxAtRest);
        pProcessManager->SetProcessOrderingToLast(pAlphaScintillation, idxPostStep);

        pAlphaScintillation->SetTrackSecondariesFirst(true);
        pAlphaScintillation->SetScintillationYieldFactor(1.1);
        pAlphaScintillation->SetScintillationExcitationRatio(1.0);
      }

      else
      {
        pProcessManager->AddProcess(pGeneralScintillation = new G4Scintillation("Scintillation"));
        pProcessManager->SetProcessOrderingToLast(pGeneralScintillation, idxAtRest);
        pProcessManager->SetProcessOrderingToLast(pGeneralScintillation, idxPostStep);

        pGeneralScintillation->SetTrackSecondariesFirst(true);
        pGeneralScintillation->SetScintillationYieldFactor(1.1);
        pGeneralScintillation->SetScintillationExcitationRatio(1.0);
      }
    }

    else if(particleName == "opticalphoton")
    {
      pProcessManager->AddDiscreteProcess(pOpAbsorption = new G4OpAbsorption());
      pProcessManager->AddDiscreteProcess(pOpRayleigh = new G4OpRayleigh());
      pProcessManager->AddDiscreteProcess(pOpBoundaryProcess = new G4OpBoundaryProcess());
    }
  }
}

void RELAXPhysicsList::ConstructDecayPhysics()
{
  G4RadioactiveDecay* pRadioactiveDecay = new G4RadioactiveDecay();

  G4IonTable* pIonTable = G4ParticleTable::GetParticleTable()->GetIonTable();

  for(G4int i = 0; i < pIonTable->Entries(); i++)
  {
    particleName = pIonTable->GetParticle(i)->GetParticleName();
    particleType = pIonTable->GetParticle(i)->GetParticleType();

    if(particleName == "GenericIon")
    {
      pProcessManager = pIonTable->GetParticle(i)->GetProcessManager();
      pProcessManager->AddProcess(pRadioactiveDecay);
      pProcessManager->SetProcessOrdering(pRadioactiveDecay, idxPostStep);
      pProcessManager->SetProcessOrdering(pRadioactiveDecay, idxAtRest);
    }
  }
}

void RELAXPhysicsList::AddTransportation()
{
  G4VUserPhysicsList::AddTransportation();
}

void RELAXPhysicsList::SetCuts()
{
  G4ProductionCutsTable::GetProductionCutsTable()->SetEnergyRange(0.1*keV, 1*GeV);

  SetCutValue(0.01*um, "gamma");
}

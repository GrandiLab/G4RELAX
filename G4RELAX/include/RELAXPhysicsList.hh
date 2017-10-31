/////////////////////////////
// Nickolas Upole          //
// University of Chicago   //
// Winter 2016             //
// RELAXPhysicsList.hh     //
/////////////////////////////

#ifndef RELAXPhysicsList_h
#define RELAXPhysicsList_h 1

#include "globals.hh"

#include "G4VUserPhysicsList.hh"
#include "G4SystemOfUnits.hh"

#include "G4Geantino.hh"
#include "G4ChargedGeantino.hh"
#include "G4Gamma.hh"
#include "G4OpticalPhoton.hh"

#include "G4Electron.hh"
#include "G4Positron.hh"
#include "G4MuonPlus.hh"
#include "G4MuonMinus.hh"
#include "G4NeutrinoE.hh"
#include "G4AntiNeutrinoE.hh"
#include "G4NeutrinoMu.hh"
#include "G4AntiNeutrinoMu.hh"

#include "G4MesonConstructor.hh"
#include "G4BaryonConstructor.hh"
#include "G4IonConstructor.hh"

#include "G4ParticleDefinition.hh"
#include "G4ProcessManager.hh"

#include "G4RayleighScattering.hh"
#include "G4PhotoElectricEffect.hh"
#include "G4ComptonScattering.hh"
#include "G4GammaConversion.hh"

#include "G4eMultipleScattering.hh"
#include "G4eIonisation.hh"
#include "G4eBremsstrahlung.hh"
#include "G4eplusAnnihilation.hh"

#include "G4MuMultipleScattering.hh"
#include "G4MuIonisation.hh"
#include "G4MuBremsstrahlung.hh"
#include "G4MuPairProduction.hh"

#include "G4hMultipleScattering.hh"
#include "G4hIonisation.hh"

#include "G4Scintillation.hh"
#include "G4OpAbsorption.hh"
#include "G4OpRayleigh.hh"
#include "G4OpBoundaryProcess.hh"

#include "G4RadioactiveDecay.hh"
#include "G4IonTable.hh"

class RELAXPhysicsList : public G4VUserPhysicsList
{
public:
  RELAXPhysicsList();
  ~RELAXPhysicsList();

  // List of Functions
  virtual void ConstructParticle();
  virtual void ConstructProcess();
  virtual void SetCuts();

private:
  // List of Functions
  void ConstructBosons();
  void ConstructLeptons();
  void ConstructHadrons();
  void ConstructShortLived();
  void ConstructEMPhysics();
  void ConstructHadronPhysics();
  void ConstructOpticalPhotonPhysics();
  void ConstructDecayPhysics();
  void AddTransportation();


  // List of Particle Constructors
  G4MesonConstructor* pMesonConstructor;
  G4BaryonConstructor* pBaryonConstructor;
  G4IonConstructor* pIonConstructor;

  // List of Loop Parameters
  G4ParticleDefinition* pParticle;
  G4ProcessManager* pProcessManager;
  G4String particleName;
  G4String particleType;
  G4double particleCharge;

  // List of Gamma Processes
  G4RayleighScattering* pRayleighScattering;
  G4PhotoElectricEffect* pPhotoElectricEffect;
  G4ComptonScattering* pComptonScattering;
  G4GammaConversion* pGammaConversion;

  // List of Electron/Positron Processes
  G4eMultipleScattering* peMultipleScattering;
  G4eIonisation* peIonisation;
  G4eBremsstrahlung* peBremsstrahlung;
  G4eplusAnnihilation* peplusAnnihilation;

  // List of Muon/Muon+ Processes
  G4MuMultipleScattering* pMuMultipleScattering;
  G4MuIonisation* pMuIonisation;
  G4MuBremsstrahlung* pMuBremsstrahlung;
  G4MuPairProduction* pMuPairProduction;

  // List of Hadron Procsses
  G4hMultipleScattering* phMultipleScattering;
  G4hIonisation* phIonisation;

  // List of Scintillation/Optical Photon Processes
  G4Scintillation* pGeneralScintillation;
  G4Scintillation* pAlphaScintillation;
  G4Scintillation* pNucleusScintillation;
  G4OpAbsorption* pOpAbsorption;
  G4OpRayleigh* pOpRayleigh;
  G4OpBoundaryProcess* pOpBoundaryProcess;
};

#endif

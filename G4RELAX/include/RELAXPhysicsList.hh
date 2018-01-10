///////////////////////////
// Nickolas Upole        //
// University of Chicago //
// Summer 2016           //
// G4XCDPhysicsList.hh   //
///////////////////////////

#ifndef G4XCDPhysicsList_h
#define G4XCDPhysicsList_h 1

#include "globals.hh"

#include "G4VUserPhysicsList.hh"

#include "G4XCDPhysicsMessenger.hh"

class G4XCDPhysicsList : public G4VUserPhysicsList
{
public:
    G4XCDPhysicsList();
    ~G4XCDPhysicsList();

    // List of Functions
    void ConstructParticle();
    void ConstructProcess();
    
    void SetScintillation(G4bool mScintillation);
    void SetCerenkov(G4bool mCerenkov);

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
    void SetCuts();
    
    // List of Variables
    G4XCDPhysicsMessenger* pG4XCDPhysicsMessenger;
    
    G4bool bScintillation;
    G4bool bCerenkov;
};

#endif

//////////////////////////////
// Nickolas Upole           //
// University of Chicago    //
// Summer 2016              //
// G4XCDPhysicsMessenger.hh //
//////////////////////////////

#ifndef G4XCDPhysicsMessenger_h
#define G4XCDPhysicsMessenger_h 1

#include "globals.hh"

#include "G4UImessenger.hh"
#include "G4UIdirectory.hh"
#include "G4UIcommand.hh"
#include "G4UIcmdWithABool.hh"

class G4XCDPhysicsList;

class G4XCDPhysicsMessenger : public G4UImessenger
{
public:
    G4XCDPhysicsMessenger(G4XCDPhysicsList* pG4XCDPhysicsList);
    ~G4XCDPhysicsMessenger();
    
    void SetNewValue(G4UIcommand* pG4UICommand, G4String sNewValue);
    
private:
    G4XCDPhysicsList* pG4XCDPhysics;
    
    G4UIdirectory* pG4XCDPhysicsDir;
    
    G4UIcmdWithABool* pSetScintillationCmd;
    G4UIcmdWithABool* pSetCerenkovCmd;
};

#endif

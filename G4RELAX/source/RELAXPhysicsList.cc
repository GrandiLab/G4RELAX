//////////////////////////////
// Nickolas Upole           //
// University of Chicago    //
// Summer 2016              //
// G4XCDPhysicsMessenger.cc //
//////////////////////////////

#include "G4XCDPhysicsMessenger.hh"
#include "G4XCDPhysicsList.hh"

G4XCDPhysicsMessenger::G4XCDPhysicsMessenger(G4XCDPhysicsList* pG4XCDPhysicsList) : pG4XCDPhysics(pG4XCDPhysicsList)
{
    ///////////////////////////////
    // Set the Physics Directory //
    ///////////////////////////////
    pG4XCDPhysicsDir = new G4UIdirectory("/G4XCD/physics/");
    pG4XCDPhysicsDir->SetGuidance("Control of the G4XCD Physics.");
    
    ///////////////////////////////
    // Set the Detector Commands //
    ///////////////////////////////
    pSetScintillationCmd = new G4UIcmdWithABool("/G4XCD/physics/SetScintillation", this);
    pSetScintillationCmd->SetGuidance("Switch scintillation on (true) or off (false).");
    pSetScintillationCmd->SetDefaultValue(false);
    pSetScintillationCmd->AvailableForStates(G4State_PreInit);
    
    pSetCerenkovCmd = new G4UIcmdWithABool("/G4XCD/physics/SetCerenkov", this);
    pSetCerenkovCmd->SetGuidance("Switch Cerenkov on (true) or off (false).");
    pSetCerenkovCmd->SetDefaultValue(false);
    pSetCerenkovCmd->AvailableForStates(G4State_PreInit);
}

G4XCDPhysicsMessenger::~G4XCDPhysicsMessenger()
{
    ///////////////////////////////////////
    // Delete the Commands and Directory //
    ///////////////////////////////////////
    delete pSetScintillationCmd;
    delete pSetCerenkovCmd;
    
    delete pG4XCDPhysicsDir;
}

void G4XCDPhysicsMessenger::SetNewValue(G4UIcommand* pG4UICommand, G4String sNewValue)
{
    ///////////////////////////////////
    // Update Value for Physics List //
    ///////////////////////////////////
    if(pG4UICommand == pSetScintillationCmd)
    {
        pG4XCDPhysics->SetScintillation(&sNewValue);
    }
    
    else if(pG4UICommand == pSetCerenkovCmd)
    {
        pG4XCDPhysics->SetCerenkov(&sNewValue);
    }
}

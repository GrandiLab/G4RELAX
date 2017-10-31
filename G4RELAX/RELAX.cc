///////////////////////////
// Nickolas Upole        //
// University of Chicago //
// Winter 2016           //
// G4XCD.cc              //
///////////////////////////

#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4UIterminal.hh"
#include "G4UItcsh.hh"
#include "G4VisExecutive.hh"

#include "RELAXDetectorConstruction.hh"
#include "RELAXPhysicsList.hh"
#include "RELAXPrimaryGeneratorAction.hh"

int main(int argc, char** argv)
{
    // Construct the Run Manager/Analysis Manager
    G4RunManager* pRunManager = new G4RunManager();

    // Set Initialization Classes
    pRunManager->SetUserInitialization(new RELAXDetectorConstruction());
    pRunManager->SetUserInitialization(new RELAXPhysicsList());

    // Set Action Classes
    pRunManager->SetUserAction(new RELAXPrimaryGeneratorAction());
    pRunManager->Initialize();

    // Initialize Visualization
    G4VisManager* pVisualManager = new G4VisExecutive();
    pVisualManager->Initialize();

    // Define UI Session
    G4UIsession* pUISession = new G4UIterminal(new G4UItcsh());
    G4UImanager* pUIManager = G4UImanager::GetUIpointer();
    pUISession->SessionStart();

    // Terminate Job
    delete pUISession;
    delete pVisualManager;
    delete pRunManager;

    return 0;
}

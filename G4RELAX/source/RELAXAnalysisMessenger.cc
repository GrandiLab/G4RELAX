///////////////////////////////
// Nickolas Upole            //
// University of Chicago     //
// Summer 2016               //
// G4XCDAnalysisMessenger.cc //
///////////////////////////////

#include "G4XCDAnalysisMessenger.hh"
#include "G4XCDAnalysisManager.hh"

G4XCDAnalysisMessenger::G4XCDAnalysisMessenger(G4XCDAnalysisManager* pG4XCDAnalysisManager) : pG4XCDAM(pG4XCDAnalysisManager)
{
    ////////////////////////////////
    // Set the Analysis Directory //
    ////////////////////////////////
    pG4XCDAnalysisDir = new G4UIdirectory("/G4XCD/analysis/");
    pG4XCDAnalysisDir->SetGuidance("Control of the G4XCD Analysis.");
    
    ///////////////////////////////
    // Set the Analysis Commands //
    ///////////////////////////////
    pSetFilenameReferenceCmd = new G4UIcmdWithAString("/G4XCD/analysis/SetFilenameReference", this);
    pSetFilenameReferenceCmd->SetGuidance("Set the Root File Reference.");
    pSetFilenameReferenceCmd->SetDefaultValue("./Results/events.root");
    pSetFilenameReferenceCmd->AvailableForStates(G4State_PreInit, G4State_Idle);
}

G4XCDAnalysisMessenger::~G4XCDAnalysisMessenger()
{
    ///////////////////////////////////////
    // Delete the Commands and Directory //
    ///////////////////////////////////////
    delete pSetFilenameReferenceCmd;
    
    delete pG4XCDAnalysisDir;
}

void G4XCDAnalysisMessenger::SetNewValue(G4UIcommand* pG4UICommand, G4String sNewValue)
{
    ////////////////////////////////////////////
    // Update Value for Detector Construction //
    ////////////////////////////////////////////
    if(pG4UICommand == pSetFilenameReferenceCmd)
    {
        pG4XCDAM->SetFilenameReference(&sNewValue);

    }
}

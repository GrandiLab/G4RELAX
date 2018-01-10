//////////////////////////////
// Nickolas Upole           //
// University of Chicago    //
// Summer 2016              //
// G4XCDSteppingAction.cc   //
//////////////////////////////

#include "G4XCDSteppingAction.hh"

G4XCDSteppingAction::G4XCDSteppingAction(G4XCDAnalysisManager* pG4XCDAM) : G4UserSteppingAction()
{
    pG4XCDAnalysisManager = pG4XCDAM;
}

G4XCDSteppingAction::~G4XCDSteppingAction()
{
    
}

void G4XCDSteppingAction::UserSteppingAction(const G4Step* pStep)
{
    if(pG4XCDAnalysisManager)
    {
        pG4XCDAnalysisManager->SteppingAction(pStep);
    }
}

///////////////////////////
// Nickolas Upole        //
// University of Chicago //
// Summer 2016           //
// G4XCDRunAction.cc     //
///////////////////////////

#include "G4XCDRunAction.hh"

G4XCDRunAction::G4XCDRunAction(G4XCDAnalysisManager* pG4XCDAM) : G4UserRunAction()
{
    pG4XCDAnalysisManager = pG4XCDAM;
}

G4XCDRunAction::~G4XCDRunAction()
{
    
}

void G4XCDRunAction::BeginOfRunAction(const G4Run* pRun)
{
    if(pG4XCDAnalysisManager)
    {
        pG4XCDAnalysisManager->BeginOfRunAction(pRun);
    }
}

void G4XCDRunAction::EndOfRunAction(const G4Run* pRun)
{
    if(pG4XCDAnalysisManager)
    {
        pG4XCDAnalysisManager->EndOfRunAction(pRun);
    }
}

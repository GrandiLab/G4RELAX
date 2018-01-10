///////////////////////////
// Nickolas Upole        //
// University of Chicago //
// Summer 2016           //
// G4XCDEventAction.cc   //
///////////////////////////

#include "G4XCDEventAction.hh"

G4XCDEventAction::G4XCDEventAction(G4XCDAnalysisManager* pG4XCDAM) : G4UserEventAction()
{
    pG4XCDAnalysisManager = pG4XCDAM;
}

G4XCDEventAction::~G4XCDEventAction()
{
    
}

void G4XCDEventAction::BeginOfEventAction(const G4Event* pEvent)
{
    if(pEvent->GetEventID() % 10000 == 0)
    {
        G4cout << "Begin Event: " << pEvent->GetEventID() << G4endl;
    }
    
    if(pG4XCDAnalysisManager)
    {
        pG4XCDAnalysisManager->BeginOfEventAction(pEvent);
    }
}

void G4XCDEventAction::EndOfEventAction(const G4Event* pEvent)
{
    if(pG4XCDAnalysisManager)
    {
        pG4XCDAnalysisManager->EndOfEventAction(pEvent);
    }
}

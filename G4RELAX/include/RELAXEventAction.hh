///////////////////////////
// Nickolas Upole        //
// University of Chicago //
// Summer 2016           //
// G4XCDEventAction.hh   //
///////////////////////////

#ifndef G4XCDEventAction_h
#define G4XCDEventAction_h 1

#include "globals.hh"

#include "G4UserEventAction.hh"
#include "G4Event.hh"

#include "G4XCDAnalysisManager.hh"

class G4XCDEventAction : public G4UserEventAction
{
public:
    G4XCDEventAction(G4XCDAnalysisManager* pG4XCDAM = 0);
    ~G4XCDEventAction();
    
    // List of Functions
    virtual void BeginOfEventAction(const G4Event* pEvent);
    virtual void EndOfEventAction(const G4Event* pEvent);
    
private:
    // List of Variables
    G4XCDAnalysisManager* pG4XCDAnalysisManager;
};

#endif

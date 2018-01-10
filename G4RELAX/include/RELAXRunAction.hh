///////////////////////////
// Nickolas Upole        //
// University of Chicago //
// Summer 2016           //
// G4XCDRunAction.hh     //
///////////////////////////

#ifndef G4XCDRunAction_h
#define G4XCDRunAction_h 1

#include "globals.hh"

#include "G4UserRunAction.hh"
#include "G4Run.hh"

#include "G4XCDAnalysisManager.hh"

class G4XCDRunAction : public G4UserRunAction
{
public:
    G4XCDRunAction(G4XCDAnalysisManager* pG4XCDAM = 0);
    ~G4XCDRunAction();
    
    // List of Functions
    virtual void BeginOfRunAction(const G4Run* pRun);
    virtual void EndOfRunAction(const G4Run* pRun);
    
private:
    // List of Variables
    G4XCDAnalysisManager* pG4XCDAnalysisManager;
};

#endif

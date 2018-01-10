//////////////////////////////
// Nickolas Upole           //
// University of Chicago    //
// Summer 2016              //
// G4XCDSteppingAction.hh   //
//////////////////////////////

#ifndef G4XCDSteppingAction_h
#define G4XCDSteppingAction_h 1

#include "globals.hh"

#include "G4UserSteppingAction.hh"
#include "G4Step.hh"

#include "G4XCDAnalysisManager.hh"

class G4XCDSteppingAction : public G4UserSteppingAction
{
public:
    G4XCDSteppingAction(G4XCDAnalysisManager* pG4XCDAM = 0);
    ~G4XCDSteppingAction();
    
    // List of Functions
    virtual void UserSteppingAction(const G4Step* pStep);
    
private:
    // List of Variables
    G4XCDAnalysisManager* pG4XCDAnalysisManager;
};

#endif

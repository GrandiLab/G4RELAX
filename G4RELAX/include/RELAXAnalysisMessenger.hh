///////////////////////////////
// Nickolas Upole            //
// University of Chicago     //
// Summer 2016               //
// G4XCDAnalysisMessenger.cc //
///////////////////////////////

#ifndef G4XCDAnalysisMessenger_h
#define G4XCDAnalysisMessenger_h 1

#include "globals.hh"

#include "G4UImessenger.hh"
#include "G4UIdirectory.hh"
#include "G4UIcommand.hh"
#include "G4UIcmdWithAString.hh"

class G4XCDAnalysisManager;

class G4XCDAnalysisMessenger : public G4UImessenger
{
public:
    G4XCDAnalysisMessenger(G4XCDAnalysisManager* pG4XCDAnalysisManager);
    ~G4XCDAnalysisMessenger();
    
    void SetNewValue(G4UIcommand* pG4UICommand, G4String sNewValue);
    
private:
    G4XCDAnalysisManager* pG4XCDAM;
    
    G4UIdirectory* pG4XCDAnalysisDir;
    
    G4UIcmdWithAString* pSetFilenameReferenceCmd;
};

#endif

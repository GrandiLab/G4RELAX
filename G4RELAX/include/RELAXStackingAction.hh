//////////////////////////////
// Nickolas Upole           //
// University of Chicago    //
// Autumn 2016              //
// G4XCDStackingAction.hh   //
//////////////////////////////

#ifndef G4XCDStackingAction_h
#define G4XCDStackingAction_h 1

#include "globals.hh"

#include "G4UserStackingAction.hh"
#include "G4Track.hh"

class G4XCDStackingAction : public G4UserStackingAction
{
public:
    G4XCDStackingAction();
    ~G4XCDStackingAction();

    virtual G4ClassificationOfNewTrack ClassifyNewTrack(const G4Track* pTrack);
    
private:
    G4String sVolume;
    G4String sParticleType;
    G4String sParticleName;
};

#endif

//////////////////////////////
// Nickolas Upole           //
// University of Chicago    //
// Autumn 2016              //
// G4XCDStackingAction.cc   //
//////////////////////////////

#include "G4XCDStackingAction.hh"

G4XCDStackingAction::G4XCDStackingAction() : G4UserStackingAction()
{

}

G4XCDStackingAction::~G4XCDStackingAction()
{
    
}

G4ClassificationOfNewTrack G4XCDStackingAction::ClassifyNewTrack(const G4Track* pTrack)
{
    if(pTrack->GetParentID() == 0)
    {
        return fUrgent;
    }
    
    else
    {
        sVolume = pTrack->GetVolume()->GetName();
    
        if((sVolume == "RegionX") || (sVolume == "LXeActiveVolume") || (sVolume == "GateLXe") || (sVolume == "GateGXe") || (sVolume == "RegionY"))
        {
            sParticleType = pTrack->GetDefinition()->GetParticleType();
        
            if(sParticleType == "nucleus")
            {
                return fKill;
            }
        }
    
        else if(sVolume == "EJ301")
        {
            sParticleName = pTrack->GetDefinition()->GetParticleName();
        
            if((sParticleName == "proton") || (sParticleName == "deuteron") || (sParticleName == "C12") || (sParticleName == "C13"))
            {
                return fKill;
            }
        }
        
        return fUrgent;
    }
}

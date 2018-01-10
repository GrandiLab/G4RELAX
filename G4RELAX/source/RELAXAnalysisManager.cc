/////////////////////////////
// Nickolas Upole          //
// University of Chicago   //
// Summer 2016             //
// G4XCDAnalysisManager.cc //
/////////////////////////////

#include "G4XCDAnalysisManager.hh"

G4XCDAnalysisManager::G4XCDAnalysisManager()
{
    pG4XCDAnalysisMessenger = new G4XCDAnalysisMessenger(this);
    
    pFilenameReference = new G4String("./Results/events.root");

    pMapParticleType = new map<int, G4String>;
    pG4XCDEventData = new G4XCDEventData();
    
    dActiveVolumeX = 0.0000;
    dActiveVolumeY = 0.0000;
    dActiveVolumeZ = -92.67471*mm;
    
    dFiducialVolumeRadius = 25.0000*mm;
    dFiducialVolumeHeight = 20.0000*mm;
}

G4XCDAnalysisManager::~G4XCDAnalysisManager()
{
    delete pG4XCDAnalysisMessenger;
    
    delete pFilenameReference;
    
    delete pMapParticleType;
    delete pG4XCDEventData;
}

void G4XCDAnalysisManager::BeginOfRunAction(const G4Run* pRun)
{
    pFile = new TFile(pFilenameReference->c_str(), "RECREATE", "Results of G4XCD Simulation");
    pTree1 = new TTree("t1", "Tree containing raw data from the G4XCD Simulation");
    pTree2 = new TTree("t2", "Tree containing processed data from the G4XCD Simulation");
    pTree3 = new TTree("t3", "Tree containing nuclear recoil data from the G4XCD Simulation");
    pTree4 = new TTree("t4", "Tree containing electronic recoil data from the G4XCD Simulation");
    
    gROOT->ProcessLine("#include <vector>");
    
    pTree1->Branch("eventid", &(pG4XCDEventData->iEventID), "eventid/I");
    pTree1->Branch("trackid", "vector<int>", &pG4XCDEventData->pTrackID);
    pTree1->Branch("parentid", "vector<int>", &pG4XCDEventData->pParentID);
    pTree1->Branch("particletype", "vector<string>", &pG4XCDEventData->pParticleType);
    pTree1->Branch("parenttype", "vector<string>", &pG4XCDEventData->pParentType);
    pTree1->Branch("creatorprocess", "vector<string>", &pG4XCDEventData->pCreatorProcess);
    pTree1->Branch("depositprocess", "vector<string>", &pG4XCDEventData->pDepositingProcess);
    pTree1->Branch("volume", "vector<string>", &pG4XCDEventData->pVolume);
    pTree1->Branch("initx", "vector<double>", &pG4XCDEventData->pInitX);
    pTree1->Branch("inity", "vector<double>", &pG4XCDEventData->pInitY);
    pTree1->Branch("initz", "vector<double>", &pG4XCDEventData->pInitZ);
    pTree1->Branch("finalx", "vector<double>", &pG4XCDEventData->pFinalX);
    pTree1->Branch("finaly", "vector<double>", &pG4XCDEventData->pFinalY);
    pTree1->Branch("finalz", "vector<double>", &pG4XCDEventData->pFinalZ);
    pTree1->Branch("initkinenergy", "vector<double>", &pG4XCDEventData->pInitKinEnergy);
    pTree1->Branch("finalkinenergy", "vector<double>", &pG4XCDEventData->pFinalKinEnergy);
    pTree1->Branch("energydeposited", "vector<double>", &pG4XCDEventData->pEnergyDeposited);
    pTree1->Branch("inittime", "vector<double>", &pG4XCDEventData->pInitTime);
    pTree1->Branch("finaltime", "vector<double>", &pG4XCDEventData->pFinalTime);
    
    pTree2->Branch("eventid", &(pG4XCDEventData->iEventID), "eventid/I");
    pTree2->Branch("firstinteractiontimelxe", &(pG4XCDEventData->dFirstInteractionTimeLXe), "firstinteractiontimelxe/D");
    pTree2->Branch("totalenergydeposited", &(pG4XCDEventData->dTotalEnergyDeposited), "totalenergydeposited/D");
    pTree2->Branch("energydepositedregionx", &(pG4XCDEventData->dEnergyDepositedRegionX), "energydepositedregionx/D");
    pTree2->Branch("energydepositedactivevolume", &(pG4XCDEventData->dEnergyDepositedActiveVolume), "energydepositedactivevolume/D");
    pTree2->Branch("energydepositedfiducialvolume", &(pG4XCDEventData->dEnergyDepositedFiducialVolume), "energydepositedfiducialvolume/D");
    pTree2->Branch("energydepositedgatelxe", &(pG4XCDEventData->dEnergyDepositedGateLXe), "energydepositedgatelxe/D");
    pTree2->Branch("energydepositedgategxe", &(pG4XCDEventData->dEnergyDepositedGateGXe), "energydepositedgategxe/D");
    pTree2->Branch("energydepositedregiony", &(pG4XCDEventData->dEnergyDepositedRegionY), "energydepositedregiony/D");
    pTree2->Branch("totalinteractionsregionx", &(pG4XCDEventData->iTotalInteractionsRegionX), "totalinteractionsregionx/I");
    pTree2->Branch("totalinteractionsactivevolume", &(pG4XCDEventData->iTotalInteractionsActiveVolume), "totalinteractionsactivevolume/I");
    pTree2->Branch("totalinteractionsfiducialvolume", &(pG4XCDEventData->iTotalInteractionsFiducialVolume), "totalinteractionsfiducialvolume/I");
    pTree2->Branch("totalinteractionsgatelxe", &(pG4XCDEventData->iTotalInteractionsGateLXe), "totalinteractionsgatelxe/I");
    pTree2->Branch("totalinteractionsgategxe", &(pG4XCDEventData->iTotalInteractionsGateGXe), "totalinteractionsgategxe/I");
    pTree2->Branch("totalinteractionsregiony", &(pG4XCDEventData->iTotalInteractionsRegionY), "totalinteractionsregiony/I");
    pTree2->Branch("interactionxej301", "vector<double>", &(pG4XCDEventData->pInteractionXEJ301));
    pTree2->Branch("interactionyej301", "vector<double>", &(pG4XCDEventData->pInteractionYEJ301));
    pTree2->Branch("interactionzej301", "vector<double>", &(pG4XCDEventData->pInteractionZEJ301));
    pTree2->Branch("interactiontimeej301", "vector<double>", &(pG4XCDEventData->pInteractionTimeEJ301));
    pTree2->Branch("totalenergydepositedej301", &(pG4XCDEventData->dTotalEnergyDepositedEJ301), "totalenergydepositedej301/D");
    pTree2->Branch("totalpeej301", &(pG4XCDEventData->dTotalPEEJ301), "totalpeej301/D");
    
    pTree3->Branch("eventid", &(pG4XCDEventData->iEventID), "eventid/I");
    pTree3->Branch("firstneutroninteractionprocess", "string", &(pG4XCDEventData->sFirstNeutronInteractionProcess));
    pTree3->Branch("firstneutroninteractionvolume", "string", &(pG4XCDEventData->sFirstNeutronInteractionVolume));
    pTree3->Branch("firstneutroninteractionx", &(pG4XCDEventData->dFirstNeutronInteractionX), "firstneutroninteractionx/D");
    pTree3->Branch("firstneutroninteractiony", &(pG4XCDEventData->dFirstNeutronInteractionY), "firstneutroninteractiony/D");
    pTree3->Branch("firstneutroninteractionz", &(pG4XCDEventData->dFirstNeutronInteractionZ), "firstneutroninteractionz/D");
    pTree3->Branch("firstneutroninteractiontime", &(pG4XCDEventData->dFirstNeutronInteractionTime), "firstneutroninteractiontime/D");
    pTree3->Branch("secondneutroninteractionprocess", "string", &(pG4XCDEventData->sSecondNeutronInteractionProcess));
    pTree3->Branch("secondneutroninteractionvolume", "string", &(pG4XCDEventData->sSecondNeutronInteractionVolume));
    pTree3->Branch("secondneutroninteractionx", &(pG4XCDEventData->dSecondNeutronInteractionX), "secondneutroninteractionx/D");
    pTree3->Branch("secondneutroninteractiony", &(pG4XCDEventData->dSecondNeutronInteractionY), "secondneutroninteractiony/D");
    pTree3->Branch("secondneutroninteractionz", &(pG4XCDEventData->dSecondNeutronInteractionZ), "secondneutroninteractionz/D");
    pTree3->Branch("secondneutroninteractiontime", &(pG4XCDEventData->dSecondNeutronInteractionTime), "secondneutroninteractiontime/D");
    pTree3->Branch("elasticscattersptfe", &(pG4XCDEventData->iElasticScattersPTFE), "elasticscattersptfe/I");
    pTree3->Branch("elasticscatterssurroundinglxe", &(pG4XCDEventData->iElasticScattersSurroundingLXe), "elasticscatterssurroundinglxe/I");
    pTree3->Branch("elasticscattersregionx", &(pG4XCDEventData->iElasticScattersRegionX), "elasticscattersregionx/I");
    pTree3->Branch("elasticscattersactivevolume", &(pG4XCDEventData->iElasticScattersActiveVolume), "elasticscattersactivevolume/I");
    pTree3->Branch("elasticscattersfiducialvolume", &(pG4XCDEventData->iElasticScattersFiducialVolume), "elasticscattersfiducialvolume/I");
    pTree3->Branch("elasticscattersgatelxe", &(pG4XCDEventData->iElasticScattersGateLXe), "elasticscattersgatelxe/I");
    pTree3->Branch("elasticscattersgategxe", &(pG4XCDEventData->iElasticScattersGateGXe), "elasticscattersgategxe/I");
    pTree3->Branch("elasticscattersregiony", &(pG4XCDEventData->iElasticScattersRegionY), "elasticscattersregiony/I");
    pTree3->Branch("elasticscatterssurroundinggxe", &(pG4XCDEventData->iElasticScattersSurroundingGXe), "elasticscatterssurroundinggxe/I");
    pTree3->Branch("inelasticscattersptfe", &(pG4XCDEventData->iInelasticScattersPTFE), "inelasticscattersptfe/I");
    pTree3->Branch("inelasticscatterssurroundinglxe", &(pG4XCDEventData->iInelasticScattersSurroundingLXe), "inelasticscatterssurroundinglxe/I");
    pTree3->Branch("inelasticscattersregionx", &(pG4XCDEventData->iInelasticScattersRegionX), "inelasticscattersregionx/I");
    pTree3->Branch("inelasticscattersactivevolume", &(pG4XCDEventData->iInelasticScattersActiveVolume), "inelasticscattersactivevolume/I");
    pTree3->Branch("inelasticscattersfiducialvolume", &(pG4XCDEventData->iInelasticScattersFiducialVolume), "inelasticscattersfiducialvolume/I");
    pTree3->Branch("inelasticscattersgatelxe", &(pG4XCDEventData->iInelasticScattersGateLXe), "inelasticscattersgatelxe/I");
    pTree3->Branch("inelasticscattersgategxe", &(pG4XCDEventData->iInelasticScattersGateGXe), "inelasticscattersgategxe/I");
    pTree3->Branch("inelasticscattersregiony", &(pG4XCDEventData->iInelasticScattersRegionY), "inelasticscattersregiony/I");
    pTree3->Branch("inelasticscatterssurroundinggxe", &(pG4XCDEventData->iInelasticScattersSurroundingGXe), "inelasticscatterssurroundinggxe/I");
    pTree3->Branch("neutroncaptureptfe", &(pG4XCDEventData->iNeutronCapturePTFE), "neutroncaptureptfe/I");
    pTree3->Branch("neutroncapturesurroundinglxe", &(pG4XCDEventData->iNeutronCaptureSurroundingLXe), "neutroncapturesurroundinglxe/I");
    pTree3->Branch("neutroncaptureregionx", &(pG4XCDEventData->iNeutronCaptureRegionX), "neutroncaptureregionx/I");
    pTree3->Branch("neutroncaptureactivevolume", &(pG4XCDEventData->iNeutronCaptureActiveVolume), "neutroncaptureactivevolume/I");
    pTree3->Branch("neutroncapturefiducialvolume", &(pG4XCDEventData->iNeutronCaptureFiducialVolume), "neutroncapturefiducialvolume/I");
    pTree3->Branch("neutroncapturegatelxe", &(pG4XCDEventData->iNeutronCaptureGateLXe), "neutroncapturegatelxe/I");
    pTree3->Branch("neutroncapturegategxe", &(pG4XCDEventData->iNeutronCaptureGateGXe), "neutroncapturegategxe/I");
    pTree3->Branch("neutroncaptureregiony", &(pG4XCDEventData->iNeutronCaptureRegionY), "neutroncaptureregiony/I");
    pTree3->Branch("neutroncapturesurroundinggxe", &(pG4XCDEventData->iNeutronCaptureSurroundingGXe), "neutroncapturesurroundinggxe/I");
    
    pTree4->Branch("eventid", &(pG4XCDEventData->iEventID), "eventid/I");
    pTree4->Branch("peptfe", &(pG4XCDEventData->iPEPTFE), "peptfe/I");
    pTree4->Branch("pesurroundinglxe", &(pG4XCDEventData->iPESurroundingLXe), "pesurroundinglxe/I");
    pTree4->Branch("peregionx", &(pG4XCDEventData->iPERegionX), "peregionx/I");
    pTree4->Branch("peactivevolume", &(pG4XCDEventData->iPEActiveVolume), "peactivevolume/I");
    pTree4->Branch("pefiducialvolume", &(pG4XCDEventData->iPEFiducialVolume), "pefiducialvolume/I");
    pTree4->Branch("pegatelxe", &(pG4XCDEventData->iPEGateLXe), "pegatelxe/I");
    pTree4->Branch("pegategxe", &(pG4XCDEventData->iPEGateGXe), "pegategxe/I");
    pTree4->Branch("peregiony", &(pG4XCDEventData->iPERegionY), "peregiony/I");
    pTree4->Branch("pesurroundinggxe", &(pG4XCDEventData->iPESurroundingGXe), "pesurroundinggxe/I");
    pTree4->Branch("comptonscattersptfe", &(pG4XCDEventData->iComptonScattersPTFE), "comptonscattersptfe/I");
    pTree4->Branch("comptonscatterssurroundinglxe", &(pG4XCDEventData->iComptonScattersSurroundingLXe), "comptonscatterssurroundinglxe/I");
    pTree4->Branch("comptonscattersregionx", &(pG4XCDEventData->iComptonScattersRegionX), "comptonscattersregionx/I");
    pTree4->Branch("comptonscattersactivevolume", &(pG4XCDEventData->iComptonScattersActiveVolume), "comptonscattersactivevolume/I");
    pTree4->Branch("comptonscattersfiducialvolume", &(pG4XCDEventData->iComptonScattersFiducialVolume), "comptonscattersfiducialvolume/I");
    pTree4->Branch("comptonscattersgatelxe", &(pG4XCDEventData->iComptonScattersGateLXe), "comptonscattersgatelxe/I");
    pTree4->Branch("comptonscattersgategxe", &(pG4XCDEventData->iComptonScattersGateGXe), "comptonscattersgategxe/I");
    pTree4->Branch("comptonscattersregiony", &(pG4XCDEventData->iComptonScattersRegionY), "comptonscattersregiony/I");
    pTree4->Branch("comptonscatterssurroundinggxe", &(pG4XCDEventData->iComptonScattersSurroundingGXe), "comptonscatterssurroundinggxe/I");
}

void G4XCDAnalysisManager::BeginOfEventAction(const G4Event* pEvent)
{
    pG4XCDEventData->iEventID = pEvent->GetEventID();
}

void G4XCDAnalysisManager::SteppingAction(const G4Step* pStep)
{
    pTrack = pStep->GetTrack();
    
    pG4XCDEventData->pTrackID->push_back(pTrack->GetTrackID());
    pG4XCDEventData->pParentID->push_back(pTrack->GetParentID());
    pG4XCDEventData->pParticleType->push_back(sParticleType = pTrack->GetDefinition()->GetParticleName());
    
    if(pTrack->GetParentID())
    {
        pG4XCDEventData->pParentType->push_back((*pMapParticleType)[pTrack->GetParentID()]);
    }
    
    else
    {
        pG4XCDEventData->pParentType->push_back(G4String("none"));
    }
    
    if(pTrack->GetCreatorProcess())
    {
        pG4XCDEventData->pCreatorProcess->push_back(pTrack->GetCreatorProcess()->GetProcessName());
    }
    
    else
    {
        pG4XCDEventData->pCreatorProcess->push_back(G4String("none"));
    }
    
    pG4XCDEventData->pDepositingProcess->push_back(sDepositingProcess = pStep->GetPostStepPoint()->GetProcessDefinedStep()->GetProcessName());
    pG4XCDEventData->pVolume->push_back(sVolume = pStep->GetPreStepPoint()->GetPhysicalVolume()->GetName());
    pG4XCDEventData->pInitX->push_back(pStep->GetPreStepPoint()->GetPosition().x()/mm);
    pG4XCDEventData->pInitY->push_back(pStep->GetPreStepPoint()->GetPosition().y()/mm);
    pG4XCDEventData->pInitZ->push_back(pStep->GetPreStepPoint()->GetPosition().z()/mm);
    pG4XCDEventData->pFinalX->push_back(dInteractionX = pStep->GetPostStepPoint()->GetPosition().x()/mm);
    pG4XCDEventData->pFinalY->push_back(dInteractionY = pStep->GetPostStepPoint()->GetPosition().y()/mm);
    pG4XCDEventData->pFinalZ->push_back(dInteractionZ = pStep->GetPostStepPoint()->GetPosition().z()/mm);
    pG4XCDEventData->pInitKinEnergy->push_back(pStep->GetPreStepPoint()->GetKineticEnergy()/keV);
    pG4XCDEventData->pFinalKinEnergy->push_back(pStep->GetPostStepPoint()->GetKineticEnergy()/keV);
    pG4XCDEventData->pInitTime->push_back(pStep->GetPreStepPoint()->GetGlobalTime()/ns);
    pG4XCDEventData->pFinalTime->push_back(dInteractionTime = pStep->GetPostStepPoint()->GetGlobalTime()/ns);
    
    dEnergyDeposited = pStep->GetTotalEnergyDeposit()/keV;
    
    pSecondaryTrackVector = pStep->GetSecondaryInCurrentStep();
    
    for(int iCounter1 = 0; iCounter1 < pSecondaryTrackVector->size(); iCounter1++)
    {
        sSecondaryVolume = (*pSecondaryTrackVector)[iCounter1]->GetVolume()->GetName();
        
        if((sSecondaryVolume == "RegionX") || (sSecondaryVolume == "LXeActiveVolume") || (sSecondaryVolume == "GateLXe") || (sSecondaryVolume == "GateGXe") || (sSecondaryVolume == "RegionY"))
        {
            sSecondaryParticleType = (*pSecondaryTrackVector)[iCounter1]->GetDefinition()->GetParticleType();
            
            if(sSecondaryParticleType == "nucleus")
            {
                dEnergyDeposited += (*pSecondaryTrackVector)[iCounter1]->GetKineticEnergy()/keV;
            }
        }
        
        else if(sSecondaryVolume == "EJ301")
        {
            sSecondaryParticleName = (*pSecondaryTrackVector)[iCounter1]->GetDefinition()->GetParticleName();
            
            if((sSecondaryParticleName == "proton") || (sSecondaryParticleName == "deuteron") || (sSecondaryParticleName == "C12") || (sSecondaryParticleName == "C13"))
            {
                dEnergyDeposited += (*pSecondaryTrackVector)[iCounter1]->GetKineticEnergy()/keV;
                pG4XCDEventData->dTotalPEEJ301 += 0.084 * 1.7 * (*pSecondaryTrackVector)[iCounter1]->GetKineticEnergy()/keV;
            }
            
            else if(sSecondaryParticleName == "gamma")
            {
                dEnergyDeposited += (*pSecondaryTrackVector)[iCounter1]->GetKineticEnergy()/keV;
                pG4XCDEventData->dTotalPEEJ301 += 1.7 * (*pSecondaryTrackVector)[iCounter1]->GetKineticEnergy()/keV;
            }
        }
    }
    
    pG4XCDEventData->pEnergyDeposited->push_back(dEnergyDeposited);
    
    if(sDepositingProcess != "Transportation")
    {
        if(sVolume == "RegionX")
        {
            pG4XCDEventData->iTotalInteractionsRegionX++;
            pG4XCDEventData->dEnergyDepositedRegionX += dEnergyDeposited;
            pG4XCDEventData->dTotalEnergyDeposited += dEnergyDeposited;
            
            if(sParticleType == "neutron")
            {
                if(sDepositingProcess == "hadElastic")
                {
                    pG4XCDEventData->iElasticScattersRegionX++;
                }
                
                else if(sDepositingProcess == "neutronInelastic")
                {
                    pG4XCDEventData->iInelasticScattersRegionX++;
                }
                
                else if(sDepositingProcess == "nCapture")
                {
                    pG4XCDEventData->iNeutronCaptureRegionX++;
                }

            }
            
            else if(sParticleType == "gamma")
            {
                if(sDepositingProcess == "phot")
                {
                    pG4XCDEventData->iPERegionX++;
                }
                
                else if(sDepositingProcess == "compt")
                {
                    pG4XCDEventData->iComptonScattersRegionX++;
                }
            }
            
            if(((pG4XCDEventData->dFirstInteractionTimeLXe) < 0) || (dInteractionTime < (pG4XCDEventData->dFirstInteractionTimeLXe)))
            {
                (pG4XCDEventData->dFirstInteractionTimeLXe) = dInteractionTime;
            }
        }
        
        else if(sVolume == "LXeActiveVolume")
        {
            pG4XCDEventData->iTotalInteractionsActiveVolume++;
            pG4XCDEventData->dEnergyDepositedActiveVolume += dEnergyDeposited;
            pG4XCDEventData->dTotalEnergyDeposited += dEnergyDeposited;
            
            if(sParticleType == "neutron")
            {
                if(sDepositingProcess == "hadElastic")
                {
                    pG4XCDEventData->iElasticScattersActiveVolume++;
                }
                
                else if(sDepositingProcess == "neutronInelastic")
                {
                    pG4XCDEventData->iInelasticScattersActiveVolume++;
                }
                
                else if(sDepositingProcess == "nCapture")
                {
                    pG4XCDEventData->iNeutronCaptureActiveVolume++;
                }

            }
            
            else if(sParticleType == "gamma")
            {
                if(sDepositingProcess == "phot")
                {
                    pG4XCDEventData->iPEActiveVolume++;
                }
                
                else if(sDepositingProcess == "compt")
                {
                    pG4XCDEventData->iComptonScattersActiveVolume++;
                }
            }
            
            if(((pG4XCDEventData->dFirstInteractionTimeLXe) < 0) || (dInteractionTime < (pG4XCDEventData->dFirstInteractionTimeLXe)))
            {
                (pG4XCDEventData->dFirstInteractionTimeLXe) = dInteractionTime;
            }
            
            dInteractionRadius = TMath::Sqrt(TMath::Power(dInteractionX - dActiveVolumeX, 2) + TMath::Power(dInteractionY - dActiveVolumeY, 2));
            
            if((dInteractionRadius < dFiducialVolumeRadius) && (dInteractionZ > (dActiveVolumeZ - 0.5 * dFiducialVolumeHeight)) && (dInteractionZ < (dActiveVolumeZ + 0.5 * dFiducialVolumeHeight)))
            {
                pG4XCDEventData->iTotalInteractionsFiducialVolume++;
                pG4XCDEventData->dEnergyDepositedFiducialVolume += dEnergyDeposited;
                
                if(sParticleType == "neutron")
                {
                    if(sDepositingProcess == "hadElastic")
                    {
                        pG4XCDEventData->iElasticScattersFiducialVolume++;
                    }
                    
                    else if(sDepositingProcess == "neutronInelastic")
                    {
                        pG4XCDEventData->iInelasticScattersFiducialVolume++;
                    }
                    
                    else if(sDepositingProcess == "nCapture")
                    {
                        pG4XCDEventData->iNeutronCaptureFiducialVolume++;
                    }
                }
                
                else if(sParticleType == "gamma")
                {
                    if(sDepositingProcess == "phot")
                    {
                        pG4XCDEventData->iPEFiducialVolume++;
                    }
                    
                    else if(sDepositingProcess == "compt")
                    {
                        pG4XCDEventData->iComptonScattersFiducialVolume++;
                    }
                }
            }
        }
        
        else if(sVolume == "GateLXe")
        {
            pG4XCDEventData->iTotalInteractionsGateLXe++;
            pG4XCDEventData->dEnergyDepositedGateLXe += dEnergyDeposited;
            pG4XCDEventData->dTotalEnergyDeposited += dEnergyDeposited;
            
            if(sParticleType == "neutron")
            {
                if(sDepositingProcess == "hadElastic")
                {
                    pG4XCDEventData->iElasticScattersGateLXe++;
                }
                
                else if(sDepositingProcess == "neutronInelastic")
                {
                    pG4XCDEventData->iInelasticScattersGateLXe++;
                }
                
                else if(sDepositingProcess == "nCapture")
                {
                    pG4XCDEventData->iNeutronCaptureGateLXe++;
                }
            }
            
            else if(sParticleType == "gamma")
            {
                if(sDepositingProcess == "phot")
                {
                    pG4XCDEventData->iPEGateLXe++;
                }
                
                else if(sDepositingProcess == "compt")
                {
                    pG4XCDEventData->iComptonScattersGateLXe++;
                }
            }
            
            if(((pG4XCDEventData->dFirstInteractionTimeLXe) < 0) || (dInteractionTime < (pG4XCDEventData->dFirstInteractionTimeLXe)))
            {
                (pG4XCDEventData->dFirstInteractionTimeLXe) = dInteractionTime;
            }
        }
        
        else if(sVolume == "GateGXe")
        {
            pG4XCDEventData->iTotalInteractionsGateGXe++;
            pG4XCDEventData->dEnergyDepositedGateGXe += dEnergyDeposited;
            pG4XCDEventData->dTotalEnergyDeposited += dEnergyDeposited;
        
            if(sParticleType == "neutron")
            {
                if(sDepositingProcess == "hadElastic")
                {
                    pG4XCDEventData->iElasticScattersGateGXe++;
                }
                
                else if(sDepositingProcess == "neutronInelastic")
                {
                    pG4XCDEventData->iInelasticScattersGateGXe++;
                }
                
                else if(sDepositingProcess == "nCapture")
                {
                    pG4XCDEventData->iNeutronCaptureGateGXe++;
                }
            }
            
            else if(sParticleType == "gamma")
            {
                if(sDepositingProcess == "phot")
                {
                    pG4XCDEventData->iPEGateGXe++;
                }
                
                else if(sDepositingProcess == "compt")
                {
                    pG4XCDEventData->iComptonScattersGateGXe++;
                }
            }
            
            if(((pG4XCDEventData->dFirstInteractionTimeLXe) < 0) || (dInteractionTime < (pG4XCDEventData->dFirstInteractionTimeLXe)))
            {
                (pG4XCDEventData->dFirstInteractionTimeLXe) = dInteractionTime;
            }
        }
        
        else if(sVolume == "RegionY")
        {
            pG4XCDEventData->iTotalInteractionsRegionY++;
            pG4XCDEventData->dEnergyDepositedRegionY += dEnergyDeposited;
            pG4XCDEventData->dTotalEnergyDeposited += dEnergyDeposited;
            
            if(sParticleType == "neutron")
            {
                if(sDepositingProcess == "hadElastic")
                {
                    pG4XCDEventData->iElasticScattersRegionY++;
                }
                
                else if(sDepositingProcess == "neutronInelastic")
                {
                    pG4XCDEventData->iInelasticScattersRegionY++;
                }
                
                else if(sDepositingProcess == "nCapture")
                {
                    pG4XCDEventData->iNeutronCaptureRegionY++;
                }
            }
            
            else if(sParticleType == "gamma")
            {
                if(sDepositingProcess == "phot")
                {
                    pG4XCDEventData->iPERegionY++;
                }
                
                else if(sDepositingProcess == "compt")
                {
                    pG4XCDEventData->iComptonScattersRegionY++;
                }
            }
            
            if(((pG4XCDEventData->dFirstInteractionTimeLXe) < 0) || (dInteractionTime < (pG4XCDEventData->dFirstInteractionTimeLXe)))
            {
                (pG4XCDEventData->dFirstInteractionTimeLXe) = dInteractionTime;
            }
        }
    
        else if(sVolume == "LXe")
        {
            if(sParticleType == "neutron")
            {
                if(sDepositingProcess == "hadElastic")
                {
                    pG4XCDEventData->iElasticScattersSurroundingLXe++;
                }
                
                else if(sDepositingProcess == "neutronInelastic")
                {
                    pG4XCDEventData->iInelasticScattersSurroundingLXe++;
                }
                
                else if(sDepositingProcess == "nCapture")
                {
                    pG4XCDEventData->iNeutronCaptureSurroundingLXe++;
                }
            }
            
            else if(sParticleType == "gamma")
            {
                if(sDepositingProcess == "phot")
                {
                    pG4XCDEventData->iPESurroundingLXe++;
                }
                
                else if(sDepositingProcess == "compt")
                {
                    pG4XCDEventData->iComptonScattersSurroundingLXe++;
                }
            }
        }
    
        else if(sVolume == "GXe")
        {
            if(sParticleType == "neutron")
            {
                if(sDepositingProcess == "hadElastic")
                {
                    pG4XCDEventData->iElasticScattersSurroundingGXe++;
                }
                
                else if(sDepositingProcess == "neutronInelastic")
                {
                    pG4XCDEventData->iInelasticScattersSurroundingGXe++;
                }
                
                else if(sDepositingProcess == "nCapture")
                {
                    pG4XCDEventData->iNeutronCaptureSurroundingGXe++;
                }
            }
            
            else if(sParticleType == "gamma")
            {
                if(sDepositingProcess == "phot")
                {
                    pG4XCDEventData->iPESurroundingGXe++;
                }
                
                else if(sDepositingProcess == "compt")
                {
                    pG4XCDEventData->iComptonScattersSurroundingGXe++;
                }
            }
        }
        
        else if((sVolume == "BottomPTFE") || (sVolume == "TopPTFE"))
        {
            if(sParticleType == "neutron")
            {
                if(sDepositingProcess == "hadElastic")
                {
                    pG4XCDEventData->iElasticScattersPTFE++;
                }
        
                else if(sDepositingProcess == "neutronInelastic")
                {
                    pG4XCDEventData->iInelasticScattersPTFE++;
                }
                
                else if(sDepositingProcess == "nCapture")
                {
                    pG4XCDEventData->iNeutronCapturePTFE++;
                }

            }
            
            else if(sParticleType == "gamma")
            {
                if(sDepositingProcess == "phot")
                {
                    pG4XCDEventData->iPEPTFE++;
                }
                
                else if(sDepositingProcess == "compt")
                {
                    pG4XCDEventData->iComptonScattersPTFE++;
                }
            }
        }
        
        else if(sVolume == "EJ301")
        {
            pG4XCDEventData->pInteractionXEJ301->push_back(dInteractionX);
            pG4XCDEventData->pInteractionYEJ301->push_back(dInteractionY);
            pG4XCDEventData->pInteractionZEJ301->push_back(dInteractionZ);
            pG4XCDEventData->pInteractionTimeEJ301->push_back(dInteractionTime);
            pG4XCDEventData->dTotalEnergyDepositedEJ301 += dEnergyDeposited;
            
            /*if(sParticleType == "proton")
            {
                pG4XCDEventData->dTotalPEEJ301 += 0.084 * 1.7 * dEnergyDeposited;
            }*/
        }
        
        if((!pG4XCDEventData->iFoundFirstNeutronInteraction) && (sParticleType == "neutron"))
        {
            pG4XCDEventData->sFirstNeutronInteractionProcess = sDepositingProcess;
            pG4XCDEventData->sFirstNeutronInteractionVolume = sVolume;
            
            dInteractionRadius = TMath::Sqrt(TMath::Power(dInteractionX - dActiveVolumeX, 2) + TMath::Power(dInteractionY - dActiveVolumeY, 2));
            
            if((sVolume == "LXeActiveVolume") && (dInteractionRadius < dFiducialVolumeRadius) && (dInteractionZ > (dActiveVolumeZ - 0.5 * dFiducialVolumeHeight)) && (dInteractionZ < (dActiveVolumeZ + 0.5 * dFiducialVolumeHeight)))
            {
                pG4XCDEventData->sFirstNeutronInteractionVolume = "FiducialVolume";
            }
            
            pG4XCDEventData->dFirstNeutronInteractionX = dInteractionX;
            pG4XCDEventData->dFirstNeutronInteractionY = dInteractionY;
            pG4XCDEventData->dFirstNeutronInteractionZ = dInteractionZ;
            pG4XCDEventData->dFirstNeutronInteractionTime = dInteractionTime;
            
            pG4XCDEventData->iFoundFirstNeutronInteraction = 1;
        }
        
        else if((!pG4XCDEventData->iFoundSecondNeutronInteraction) && (sParticleType == "neutron"))
        {
            pG4XCDEventData->sSecondNeutronInteractionProcess = sDepositingProcess;
            pG4XCDEventData->sSecondNeutronInteractionVolume = sVolume;
            
            dInteractionRadius = TMath::Sqrt(TMath::Power(dInteractionX - dActiveVolumeX, 2) + TMath::Power(dInteractionY - dActiveVolumeY, 2));
            
            if((sVolume == "LXeActiveVolume") && (dInteractionRadius < dFiducialVolumeRadius) && (dInteractionZ > (dActiveVolumeZ - 0.5 * dFiducialVolumeHeight)) && (dInteractionZ < (dActiveVolumeZ + 0.5 * dFiducialVolumeHeight)))
            {
                pG4XCDEventData->sSecondNeutronInteractionVolume = "FiducialVolume";
            }
            
            pG4XCDEventData->dSecondNeutronInteractionX = dInteractionX;
            pG4XCDEventData->dSecondNeutronInteractionY = dInteractionY;
            pG4XCDEventData->dSecondNeutronInteractionZ = dInteractionZ;
            pG4XCDEventData->dSecondNeutronInteractionTime = dInteractionTime;
            
            pG4XCDEventData->iFoundSecondNeutronInteraction = 1;
        }
    }
}

void G4XCDAnalysisManager::EndOfEventAction(const G4Event* pEvent)
{
    pTree1->Fill();
    pTree2->Fill();
    pTree3->Fill();
    pTree4->Fill();
    
    pMapParticleType->clear();
    pG4XCDEventData->Clear();
}

void G4XCDAnalysisManager::EndOfRunAction(const G4Run* pRun)
{
    pFile->Write();
    pFile->Close();
}

void G4XCDAnalysisManager::SetFilenameReference(G4String* mFilenameReference)
{
    pFilenameReference = mFilenameReference;
}

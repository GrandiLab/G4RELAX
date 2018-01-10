///////////////////////////////
// Nickolas Upole            //
// University of Chicago     //
// Summer 2016               //
// G4XCDDetectorMessenger.hh //
///////////////////////////////

#ifndef G4XCDDetectorMessenger_h
#define G4XCDDetectorMessenger_h 1

#include "globals.hh"

#include "G4UImessenger.hh"
#include "G4UIdirectory.hh"
#include "G4UIcommand.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4UIcmdWithADouble.hh"

class G4XCDDetectorConstruction;

class G4XCDDetectorMessenger : public G4UImessenger
{
public:
    G4XCDDetectorMessenger(G4XCDDetectorConstruction* pG4XCDDetectorConstruction);
    ~G4XCDDetectorMessenger();
    
    void SetNewValue(G4UIcommand* pG4UICommand, G4String sNewValue);
    
private:
    G4XCDDetectorConstruction* pG4XCDDetector;
    
    G4UIdirectory* pG4XCDDir;
    G4UIdirectory* pG4XCDDetectorDir;
    
    G4UIcmdWithAString* pPTFEIndexOfRefractionDataCmd;
    G4UIcmdWithAString* pPTFEReflectivityDataCmd;
    G4UIcmdWithAString* pPTFESpecularLobeConstantDataCmd;
    G4UIcmdWithAString* pPTFESpecularSpikeConstantDataCmd;
    G4UIcmdWithAString* pPTFEBackscatterConstantDataCmd;
    G4UIcmdWithAString* pPTFEEfficiencyDataCmd;
    
    G4UIcmdWithAString* pLXeScintillationSpectrumDataCmd;
    G4UIcmdWithAString* pLXeIndexOfRefractionDataCmd;
    G4UIcmdWithAString* pLXeAbsorptionLengthDataCmd;
    G4UIcmdWithAString* pLXeRayleighScatteringLengthDataCmd;
    G4UIcmdWithADouble* pLXeFanoFactorCmd;
    G4UIcmdWithADoubleAndUnit* pLXeFastScintillationTimeConstantCmd;
    G4UIcmdWithADoubleAndUnit* pLXeSlowScintillationTimeConstantCmd;
    G4UIcmdWithAString* pLXeDensityDataCmd;
    
    G4UIcmdWithAString* pGXeScintillationSpectrumDataCmd;
    G4UIcmdWithAString* pGXeIndexOfRefractionDataCmd;
    G4UIcmdWithAString* pGXeAbsorptionLengthDataCmd;
    G4UIcmdWithAString* pGXeRayleighScatteringLengthDataCmd;
    G4UIcmdWithADouble* pGXeFanoFactorCmd;
    G4UIcmdWithADoubleAndUnit* pGXeFastScintillationTimeConstantCmd;
    G4UIcmdWithADoubleAndUnit* pGXeSlowScintillationTimeConstantCmd;
    G4UIcmdWithAString* pGXeDensityDataCmd;
    
    G4UIcmdWithADouble* pXePressureCmd;
};

#endif

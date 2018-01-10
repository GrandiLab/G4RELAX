///////////////////////////////
// Nickolas Upole            //
// University of Chicago     //
// Summer 2016               //
// G4XCDDetectorMessenger.cc //
///////////////////////////////

#include "G4XCDDetectorMessenger.hh"
#include "G4XCDDetectorConstruction.hh"

G4XCDDetectorMessenger::G4XCDDetectorMessenger(G4XCDDetectorConstruction* pG4XCDDetectorConstruction) : pG4XCDDetector(pG4XCDDetectorConstruction)
{
    ////////////////////////////////
    // Set the Detector Directory //
    ////////////////////////////////
    pG4XCDDir = new G4UIdirectory("/G4XCD/");
    pG4XCDDir->SetGuidance("Control of the G4XCD Simulation.");
    
    pG4XCDDetectorDir = new G4UIdirectory("/G4XCD/detector/");
    pG4XCDDetectorDir->SetGuidance("Control of the G4XCD Detector.");
    
    ///////////////////////////////
    // Set the Detector Commands //
    ///////////////////////////////
    pPTFEIndexOfRefractionDataCmd = new G4UIcmdWithAString("/G4XCD/detector/SetPTFEIndexOfRefractionData", this);
    pPTFEIndexOfRefractionDataCmd->SetGuidance("Set the PTFE index of refraction data.");
    pPTFEIndexOfRefractionDataCmd->SetDefaultValue("./data/PTFE/IndexOfRefraction.txt");
    pPTFEIndexOfRefractionDataCmd->AvailableForStates(G4State_PreInit, G4State_Idle);
    
    pPTFEReflectivityDataCmd = new G4UIcmdWithAString("/G4XCD/detector/SetPTFEReflectivityData", this);
    pPTFEIndexOfRefractionDataCmd->SetGuidance("Set the PTFE reflectivity data.");
    pPTFEIndexOfRefractionDataCmd->SetDefaultValue("./data/PTFE/Reflectivity.txt");
    pPTFEIndexOfRefractionDataCmd->AvailableForStates(G4State_PreInit, G4State_Idle);
    
    pPTFESpecularLobeConstantDataCmd = new G4UIcmdWithAString("/G4XCD/detector/SetPTFESpecularLobeConstantData", this);
    pPTFESpecularLobeConstantDataCmd->SetGuidance("Set the PTFE specular lobe constant data.");
    pPTFESpecularLobeConstantDataCmd->SetDefaultValue("./data/PTFE/SpecularLobeConstant.txt");
    pPTFESpecularLobeConstantDataCmd->AvailableForStates(G4State_PreInit, G4State_Idle);
    
    pPTFESpecularSpikeConstantDataCmd = new G4UIcmdWithAString("/G4XCD/detector/SetPTFESpecularSpikeConstantData", this);
    pPTFESpecularSpikeConstantDataCmd->SetGuidance("Set the PTFE specular spike constant data.");
    pPTFESpecularSpikeConstantDataCmd->SetDefaultValue("./data/PTFE/SpecularSpikeConstant.txt");
    pPTFESpecularSpikeConstantDataCmd->AvailableForStates(G4State_PreInit, G4State_Idle);
    
    pPTFEBackscatterConstantDataCmd = new G4UIcmdWithAString("/G4XCD/detector/SetPTFEBackscatterConstantData", this);
    pPTFEBackscatterConstantDataCmd->SetGuidance("Set the PTFE backscatter constant data.");
    pPTFEBackscatterConstantDataCmd->SetDefaultValue("./data/PTFE/BackscatterConstant.txt");
    pPTFEBackscatterConstantDataCmd->AvailableForStates(G4State_PreInit, G4State_Idle);
    
    pPTFEEfficiencyDataCmd = new G4UIcmdWithAString("/G4XCD/detector/SetPTFEEfficiencyData", this);
    pPTFEEfficiencyDataCmd->SetGuidance("Set the PTFE efficiency data.");
    pPTFEEfficiencyDataCmd->SetDefaultValue("./data/PTFE/Effiency.txt");
    pPTFEEfficiencyDataCmd->AvailableForStates(G4State_PreInit, G4State_Idle);
    
    pLXeScintillationSpectrumDataCmd = new G4UIcmdWithAString("/G4XCD/detector/SetLXeScintillationSpectrumData", this);
    pLXeScintillationSpectrumDataCmd->SetGuidance("Set the LXe scintillation spectrum data.");
    pLXeScintillationSpectrumDataCmd->SetDefaultValue("./data/LXe/ScintillationSpectrum.txt");
    pLXeScintillationSpectrumDataCmd->AvailableForStates(G4State_PreInit, G4State_Idle);
    
    pLXeIndexOfRefractionDataCmd = new G4UIcmdWithAString("/G4XCD/detector/SetLXeIndexOfRefractionData", this);
    pLXeIndexOfRefractionDataCmd->SetGuidance("Set the LXe index of refraction data.");
    pLXeIndexOfRefractionDataCmd->SetDefaultValue("./data/LXe/IndexOfRefraction.txt");
    pLXeIndexOfRefractionDataCmd->AvailableForStates(G4State_PreInit, G4State_Idle);
    
    pLXeAbsorptionLengthDataCmd = new G4UIcmdWithAString("/G4XCD/detector/SetLXeAbsorptionLengthData", this);
    pLXeAbsorptionLengthDataCmd->SetGuidance("Set the LXe absorption length data.");
    pLXeAbsorptionLengthDataCmd->SetDefaultValue("./data/LXe/AbsorptionLength.txt");
    pLXeAbsorptionLengthDataCmd->AvailableForStates(G4State_PreInit, G4State_Idle);
    
    pLXeRayleighScatteringLengthDataCmd = new G4UIcmdWithAString("/G4XCD/detector/SetLXeRayleighScatteringLengthData", this);
    pLXeRayleighScatteringLengthDataCmd->SetGuidance("Set the LXe Rayleigh scattering length data.");
    pLXeRayleighScatteringLengthDataCmd->SetDefaultValue("./data/LXe/RayleighScatteringLength.txt");
    pLXeRayleighScatteringLengthDataCmd->AvailableForStates(G4State_PreInit, G4State_Idle);
    
    pLXeFanoFactorCmd = new G4UIcmdWithADouble("/G4XCD/detector/SetLXeFanoFactor", this);
    pLXeFanoFactorCmd->SetGuidance("Set the LXe fano factor.");
    pLXeFanoFactorCmd->SetDefaultValue(0.033);
    pLXeFanoFactorCmd->AvailableForStates(G4State_PreInit, G4State_Idle);
    
    pLXeFastScintillationTimeConstantCmd = new G4UIcmdWithADoubleAndUnit("/G4XCD/detector/SetLXeFastScintillationTimeConstant", this);
    pLXeFastScintillationTimeConstantCmd->SetGuidance("Set the LXe fast scintillation time constant.");
    pLXeFastScintillationTimeConstantCmd->SetUnitCategory("Time");
    pLXeFastScintillationTimeConstantCmd->SetDefaultValue(2.2*ns);
    pLXeFastScintillationTimeConstantCmd->SetDefaultUnit("ns");
    pLXeFastScintillationTimeConstantCmd->AvailableForStates(G4State_PreInit, G4State_Idle);
    
    pLXeSlowScintillationTimeConstantCmd = new G4UIcmdWithADoubleAndUnit("/G4XCD/detector/SetLXeSlowScintillationTimeConstant", this);
    pLXeSlowScintillationTimeConstantCmd->SetGuidance("Set the LXe slow scintillation time constant.");
    pLXeSlowScintillationTimeConstantCmd->SetUnitCategory("Time");
    pLXeSlowScintillationTimeConstantCmd->SetDefaultValue(27.0*ns);
    pLXeSlowScintillationTimeConstantCmd->SetDefaultUnit("ns");
    pLXeSlowScintillationTimeConstantCmd->AvailableForStates(G4State_PreInit, G4State_Idle);
    
    pLXeDensityDataCmd = new G4UIcmdWithAString("/G4XCD/detector/SetLXeDensityData", this);
    pLXeDensityDataCmd->SetGuidance("Set the LXe density data.");
    pLXeDensityDataCmd->SetDefaultValue("./data/LXe/Density.txt");
    pLXeDensityDataCmd->AvailableForStates(G4State_PreInit, G4State_Idle);
    
    pGXeScintillationSpectrumDataCmd = new G4UIcmdWithAString("/G4XCD/detector/SetGXeScintillationSpectrumData", this);
    pGXeScintillationSpectrumDataCmd->SetGuidance("Set the GXe scintillation spectrum data.");
    pGXeScintillationSpectrumDataCmd->SetDefaultValue("./data/LXe/ScintillationSpectrum.txt");
    pGXeScintillationSpectrumDataCmd->AvailableForStates(G4State_PreInit, G4State_Idle);

    pGXeIndexOfRefractionDataCmd = new G4UIcmdWithAString("/G4XCD/detector/SetGXeIndexOfRefractionData", this);
    pGXeIndexOfRefractionDataCmd->SetGuidance("Set the GXe index of refraction data.");
    pGXeIndexOfRefractionDataCmd->SetDefaultValue("./data/GXe/IndexOfRefraction.txt");
    pGXeIndexOfRefractionDataCmd->AvailableForStates(G4State_PreInit, G4State_Idle);
    
    pGXeAbsorptionLengthDataCmd = new G4UIcmdWithAString("/G4XCD/detector/SetGXeAbsorptionLengthData", this);
    pGXeAbsorptionLengthDataCmd->SetGuidance("Set the GXe absorption length data.");
    pGXeAbsorptionLengthDataCmd->SetDefaultValue("./data/GXe/AbsorptionLength.txt");
    pGXeAbsorptionLengthDataCmd->AvailableForStates(G4State_PreInit, G4State_Idle);
    
    pGXeRayleighScatteringLengthDataCmd = new G4UIcmdWithAString("/G4XCD/detector/SetGXeRayleighScatteringLengthData", this);
    pGXeRayleighScatteringLengthDataCmd->SetGuidance("Set the GXe Rayleigh scattering length data.");
    pGXeRayleighScatteringLengthDataCmd->SetDefaultValue("./data/GXe/RayleighScatteringLength.txt");
    pGXeRayleighScatteringLengthDataCmd->AvailableForStates(G4State_PreInit, G4State_Idle);
    
    pGXeFanoFactorCmd = new G4UIcmdWithADouble("/G4XCD/detector/SetGXeFanoFactor", this);
    pGXeFanoFactorCmd->SetGuidance("Set the GXe fano factor.");
    pGXeFanoFactorCmd->SetDefaultValue(0.033);
    pGXeFanoFactorCmd->AvailableForStates(G4State_PreInit, G4State_Idle);
    
    pGXeFastScintillationTimeConstantCmd = new G4UIcmdWithADoubleAndUnit("/G4XCD/detector/SetGXeFastScintillationTimeConstant", this);
    pGXeFastScintillationTimeConstantCmd->SetGuidance("Set the GXe fast scintillation time constant.");
    pGXeFastScintillationTimeConstantCmd->SetUnitCategory("Time");
    pGXeFastScintillationTimeConstantCmd->SetDefaultValue(2.2*ns);
    pGXeFastScintillationTimeConstantCmd->SetDefaultUnit("ns");
    pGXeFastScintillationTimeConstantCmd->AvailableForStates(G4State_PreInit, G4State_Idle);
    
    pGXeSlowScintillationTimeConstantCmd = new G4UIcmdWithADoubleAndUnit("/G4XCD/detector/SetGXeSlowScintillationTimeConstant", this);
    pGXeSlowScintillationTimeConstantCmd->SetGuidance("Set the GXe slow scintillation time constant.");
    pGXeSlowScintillationTimeConstantCmd->SetUnitCategory("Time");
    pGXeSlowScintillationTimeConstantCmd->SetDefaultValue(27.0*ns);
    pGXeSlowScintillationTimeConstantCmd->SetDefaultUnit("ns");
    pGXeSlowScintillationTimeConstantCmd->AvailableForStates(G4State_PreInit, G4State_Idle);
    
    pGXeDensityDataCmd = new G4UIcmdWithAString("/G4XCD/detector/SetGXeDensityData", this);
    pGXeDensityDataCmd->SetGuidance("Set the GXe density data.");
    pGXeDensityDataCmd->SetDefaultValue("./data/GXe/Density.txt");
    pGXeDensityDataCmd->AvailableForStates(G4State_PreInit, G4State_Idle);
    
    pXePressureCmd = new G4UIcmdWithADouble("/G4XCD/detector/SetXePressure", this);
    pXePressureCmd->SetGuidance("Set the pressure of the liquid and gaseous xenon in psi.");
    pXePressureCmd->SetDefaultValue(17.35);
    pXePressureCmd->AvailableForStates(G4State_PreInit, G4State_Idle);
}

G4XCDDetectorMessenger::~G4XCDDetectorMessenger()
{
    ///////////////////////////////////////
    // Delete the Commands and Directory //
    ///////////////////////////////////////
    delete pPTFEIndexOfRefractionDataCmd;
    delete pPTFEReflectivityDataCmd;
    delete pPTFESpecularLobeConstantDataCmd;
    delete pPTFESpecularSpikeConstantDataCmd;
    delete pPTFEBackscatterConstantDataCmd;
    delete pPTFEEfficiencyDataCmd;
    
    delete pLXeScintillationSpectrumDataCmd;
    delete pLXeIndexOfRefractionDataCmd;
    delete pLXeAbsorptionLengthDataCmd;
    delete pLXeRayleighScatteringLengthDataCmd;
    delete pLXeFanoFactorCmd;
    delete pLXeFastScintillationTimeConstantCmd;
    delete pLXeSlowScintillationTimeConstantCmd;
    delete pLXeDensityDataCmd;
    
    delete pGXeScintillationSpectrumDataCmd;
    delete pGXeIndexOfRefractionDataCmd;
    delete pGXeAbsorptionLengthDataCmd;
    delete pGXeRayleighScatteringLengthDataCmd;
    delete pGXeFanoFactorCmd;
    delete pGXeFastScintillationTimeConstantCmd;
    delete pGXeSlowScintillationTimeConstantCmd;
    delete pGXeDensityDataCmd;
    
    delete pXePressureCmd;
    
    delete pG4XCDDetectorDir;
}

void G4XCDDetectorMessenger::SetNewValue(G4UIcommand* pG4UICommand, G4String sNewValue)
{
    ////////////////////////////////////////////
    // Update Value for Detector Construction //
    ////////////////////////////////////////////
    if(pG4UICommand == pPTFEIndexOfRefractionDataCmd)
    {
        pG4XCDDetector->SetPTFEIndexOfRefraction(&sNewValue);
    }
    
    else if(pG4UICommand == pPTFEReflectivityDataCmd)
    {
        pG4XCDDetector->SetPTFEReflectivity(&sNewValue);
    }
    
    else if(pG4UICommand == pPTFESpecularLobeConstantDataCmd)
    {
        pG4XCDDetector->SetPTFESpecularLobeConstant(&sNewValue);
    }
    
    else if(pG4UICommand == pPTFESpecularSpikeConstantDataCmd)
    {
        pG4XCDDetector->SetPTFESpecularSpikeConstant(&sNewValue);
    }
    
    else if(pG4UICommand == pPTFEBackscatterConstantDataCmd)
    {
        pG4XCDDetector->SetPTFEBackscatterConstant(&sNewValue);
    }
    
    else if(pG4UICommand == pPTFEEfficiencyDataCmd)
    {
        pG4XCDDetector->SetPTFEEfficiency(&sNewValue);
    }
    
    else if(pG4UICommand == pLXeScintillationSpectrumDataCmd)
    {
        pG4XCDDetector->SetLXeScintillationSpectrumData(&sNewValue);
    }
    
    else if(pG4UICommand == pLXeIndexOfRefractionDataCmd)
    {
        pG4XCDDetector->SetLXeIndexOfRefractionData(&sNewValue);
    }
    
    else if(pG4UICommand == pLXeAbsorptionLengthDataCmd)
    {
        pG4XCDDetector->SetLXeAbsorptionLengthData(&sNewValue);
    }
    
    else if(pG4UICommand == pLXeRayleighScatteringLengthDataCmd)
    {
        pG4XCDDetector->SetLXeRayleighScatteringLengthData(&sNewValue);
    }
    
    else if(pG4UICommand == pLXeFanoFactorCmd)
    {
        pG4XCDDetector->SetLXeFanoFactor(pLXeFanoFactorCmd->GetNewDoubleValue(sNewValue));
    }
    
    else if(pG4UICommand == pLXeFastScintillationTimeConstantCmd)
    {
        pG4XCDDetector->SetLXeFastScintillationTimeConstant(pLXeFastScintillationTimeConstantCmd->GetNewDoubleValue(sNewValue));
    }
    
    else if(pG4UICommand == pLXeSlowScintillationTimeConstantCmd)
    {
        pG4XCDDetector->SetLXeSlowScintillationTimeConstant(pLXeSlowScintillationTimeConstantCmd->GetNewDoubleValue(sNewValue));
    }
    
    else if(pG4UICommand == pLXeDensityDataCmd)
    {
        pG4XCDDetector->SetLXeDensityData(&sNewValue);
    }
    
    else if(pG4UICommand == pGXeScintillationSpectrumDataCmd)
    {
        pG4XCDDetector->SetGXeScintillationSpectrumData(&sNewValue);
    }
    
    else if(pG4UICommand == pGXeIndexOfRefractionDataCmd)
    {
        pG4XCDDetector->SetGXeIndexOfRefractionData(&sNewValue);
    }
    
    else if(pG4UICommand == pGXeAbsorptionLengthDataCmd)
    {
        pG4XCDDetector->SetGXeAbsorptionLengthData(&sNewValue);
    }
    
    else if(pG4UICommand == pGXeRayleighScatteringLengthDataCmd)
    {
        pG4XCDDetector->SetGXeRayleighScatteringLengthData(&sNewValue);
    }
    
    else if(pG4UICommand == pGXeFanoFactorCmd)
    {
        pG4XCDDetector->SetGXeFanoFactor(pGXeFanoFactorCmd->GetNewDoubleValue(sNewValue));
    }
    
    else if(pG4UICommand == pGXeFastScintillationTimeConstantCmd)
    {
        pG4XCDDetector->SetGXeFastScintillationTimeConstant(pGXeFastScintillationTimeConstantCmd->GetNewDoubleValue(sNewValue));
    }
    
    else if(pG4UICommand == pGXeSlowScintillationTimeConstantCmd)
    {
        pG4XCDDetector->SetGXeSlowScintillationTimeConstant(pGXeSlowScintillationTimeConstantCmd->GetNewDoubleValue(sNewValue));
    }
    
    else if(pG4UICommand == pGXeDensityDataCmd)
    {
        pG4XCDDetector->SetGXeDensityData(&sNewValue);
    }
    
    else if(pG4UICommand == pXePressureCmd)
    {
        pG4XCDDetector->SetXePressure(pXePressureCmd->GetNewDoubleValue(sNewValue));
    }
}

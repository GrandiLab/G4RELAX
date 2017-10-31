//////////////////////////////////
// Bruno Petrucci               //
// University of Chicago        //
// Fall 2017                    //
// RELAXDetectorConstruction.hh //
//////////////////////////////////

#ifndef RELAXDetectorConstruction_h
#define RELAXDetectorConstruction_h 1

#include <math.h>

#include "globals.hh"

#include "G4VUserDetectorConstruction.hh"
#include "G4SystemOfUnits.hh"
#include "G4Element.hh"
#include "G4Material.hh"
#include "G4Box.hh"
#include "G4GenericPolycone.hh"
#include "G4Tubs.hh"
#include "G4Sphere.hh"
#include "G4UnionSolid.hh"
#include "G4SubtractionSolid.hh"
#include "G4RotationMatrix.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4VisAttributes.hh"

class RELAXDetectorConstruction : public G4VUserDetectorConstruction
{
public:
  RELAXDetectorConstruction();
  virtual ~RELAXDetectorConstruction();

  virtual G4VPhysicalVolume* Construct();

private:
  // List of Functions
  void DefineMaterials();
  void ConstructLaboratory();

  // List of Isotopes
  G4Isotope* pH1Isotope;
  G4Isotope* pH2Isotope;

  G4Isotope* pBe9Isotope;

  G4Isotope* pB10Isotope;
  G4Isotope* pB11Isotope;

  G4Isotope* pC12Isotope;
  G4Isotope* pC13Isotope;

  G4Isotope* pN14Isotope;
  G4Isotope* pN15Isotope;

  G4Isotope* pO16Isotope;
  G4Isotope* pO17Isotope;
  G4Isotope* pO18Isotope;

  G4Isotope* pF19Isotope;

  G4Isotope* pNa23Isotope;

  G4Isotope* pMg24Isotope;
  G4Isotope* pMg25Isotope;
  G4Isotope* pMg26Isotope;

  G4Isotope* pAl27Isotope;

  G4Isotope* pSi28Isotope;
  G4Isotope* pSi29Isotope;
  G4Isotope* pSi30Isotope;

  G4Isotope* pP31Isotope;

  G4Isotope* pS32Isotope;
  G4Isotope* pS33Isotope;
  G4Isotope* pS34Isotope;
  G4Isotope* pS36Isotope;

  G4Isotope* pAr36Isotope;
  G4Isotope* pAr38Isotope;
  G4Isotope* pAr40Isotope;

  G4Isotope* pK39Isotope;
  G4Isotope* pK40Isotope;
  G4Isotope* pK41Isotope;

  G4Isotope* pCa40Isotope;
  G4Isotope* pCa42Isotope;
  G4Isotope* pCa43Isotope;
  G4Isotope* pCa44Isotope;
  G4Isotope* pCa46Isotope;
  G4Isotope* pCa48Isotope;

  G4Isotope* pTi46Isotope;
  G4Isotope* pTi47Isotope;
  G4Isotope* pTi48Isotope;
  G4Isotope* pTi49Isotope;
  G4Isotope* pTi50Isotope;

  G4Isotope* pCr50Isotope;
  G4Isotope* pCr52Isotope;
  G4Isotope* pCr53Isotope;
  G4Isotope* pCr54Isotope;

  G4Isotope* pMn55Isotope;

  G4Isotope* pFe54Isotope;
  G4Isotope* pFe56Isotope;
  G4Isotope* pFe57Isotope;
  G4Isotope* pFe58Isotope;

  G4Isotope* pCo59Isotope;

  G4Isotope* pNi58Isotope;
  G4Isotope* pNi60Isotope;
  G4Isotope* pNi61Isotope;
  G4Isotope* pNi62Isotope;
  G4Isotope* pNi64Isotope;

  G4Isotope* pCu63Isotope;
  G4Isotope* pCu65Isotope;

  G4Isotope*  pMo92Isotope;
  G4Isotope*  pMo94Isotope;
  G4Isotope*  pMo95Isotope;
  G4Isotope*  pMo96Isotope;
  G4Isotope*  pMo97Isotope;
  G4Isotope*  pMo98Isotope;
  G4Isotope* pMo100Isotope;

  G4Isotope* pSb121Isotope;
  G4Isotope* pSb123Isotope;

  G4Isotope* pXe124Isotope;
  G4Isotope* pXe126Isotope;
  G4Isotope* pXe128Isotope;
  G4Isotope* pXe129Isotope;
  G4Isotope* pXe130Isotope;
  G4Isotope* pXe131Isotope;
  G4Isotope* pXe132Isotope;
  G4Isotope* pXe134Isotope;
  G4Isotope* pXe136Isotope;

  G4Isotope* pPb204Isotope;
  G4Isotope* pPb206Isotope;
  G4Isotope* pPb207Isotope;
  G4Isotope* pPb208Isotope;

  // List of Elements
  G4Element* pHElement;
  G4Element* pBeElement;
  G4Element* pBElement;
  G4Element* pCElement;
  G4Element* pNElement;
  G4Element* pOElement;
  G4Element* pFElement;
  G4Element* pNaElement;
  G4Element* pMgElement;
  G4Element* pAlElement;
  G4Element* pSiElement;
  G4Element* pPElement;
  G4Element* pSElement;
  G4Element* pArElement;
  G4Element* pKElement;
  G4Element* pCaElement;
  G4Element* pTiElement;
  G4Element* pCrElement;
  G4Element* pMnElement;
  G4Element* pFeElement;
  G4Element* pCoElement;
  G4Element* pNiElement;
  G4Element* pCuElement;
  G4Element* pMoElement;
  G4Element* pSbElement;
  G4Element* pXeElement;
  G4Element* pPbElement;

  // List of Materials
  G4Material* pAirMaterial;
  G4Material* pConcreteMaterial;
  G4Material* pLeadMaterial;
  G4Material* pAluminumOxideMaterial;
  G4Material* pBerylliumOxideMaterial;
  G4Material* pBorosilicateGlassMaterial;
  G4Material* pJBWeldMaterial;
  G4Material* pAcrylicMaterial;
  G4Material* pStainlessSteelMaterial;
  G4Material* pVacuumMaterial;
  G4Material* pGXeMaterial;
  G4Material* pLXeMaterial;
  G4Material* pPTFEMaterial;
  G4Material* pKovarMaterial;
  G4Material* pQuartzMaterial;
  G4Material* pPhotocathodeMaterial;
  G4Material* pCeramicMaterial;

  /////////////////////////
  // List for Laboratory //
  /////////////////////////
 
  // List of Variables
  G4double dLaboratoryLength;
  G4double dLaboratoryWidth;
  G4double dLaboratoryHeight;

  // List of Shapes
  G4Box* pLaboratoryBox;

  // List of Volumes
  G4LogicalVolume* pMotherLV;
  G4LogicalVolume* pLaboratoryLV;
  G4VPhysicalVolume* pLaboratoryPV;
};

#endif

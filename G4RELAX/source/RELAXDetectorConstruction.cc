//////////////////////////////////
// Nickolas Upole               //
// University of Chicago        //
// Winter 2016                  //
// RELAXDetectorConstruction.cc //
//////////////////////////////////

#include "RELAXDetectorConstruction.hh"

RELAXDetectorConstruction::RELAXDetectorConstruction() : G4VUserDetectorConstruction()
{

}

RELAXDetectorConstruction::~RELAXDetectorConstruction()
{

}

G4VPhysicalVolume* RELAXDetectorConstruction::Construct()
{
  DefineMaterials();
  ConstructLaboratory();

  return pLaboratoryPV;
}

void RELAXDetectorConstruction::DefineMaterials()
{
  // Create Isotopes
  pH1Isotope = new G4Isotope("H1", 1, 1, 1.007825*g/mole);
  pH2Isotope = new G4Isotope("H2", 1, 2, 2.014102*g/mole);

  pBe9Isotope = new G4Isotope("Be9", 4, 5, 9.012182*g/mole);

  pB10Isotope = new G4Isotope("B10", 5, 5, 10.012937*g/mole);
  pB11Isotope = new G4Isotope("B11", 5, 6, 11.009305*g/mole);

  pC12Isotope = new G4Isotope("C12", 6, 6, 12.000000*g/mole);
  pC13Isotope = new G4Isotope("C13", 6, 7, 13.003355*g/mole);

  pN14Isotope = new G4Isotope("N14", 7, 7, 14.003074*g/mole);
  pN15Isotope = new G4Isotope("N15", 7, 8, 15.000109*g/mole);

  pO16Isotope = new G4Isotope("O16", 8,  8, 15.994915*g/mole);
  pO17Isotope = new G4Isotope("O17", 8,  9, 16.999132*g/mole);
  pO18Isotope = new G4Isotope("O18", 8, 10, 17.999160*g/mole);

  pF19Isotope = new G4Isotope("F19", 9, 10, 18.998403*g/mole);

  pNa23Isotope = new G4Isotope("Na23", 11, 12, 22.989770*g/mole);

  pMg24Isotope = new G4Isotope("Mg24", 12, 12, 23.985042*g/mole);
  pMg25Isotope = new G4Isotope("Mg25", 12, 13, 24.985837*g/mole);
  pMg26Isotope = new G4Isotope("Mg26", 12, 14, 25.982593*g/mole);

  pAl27Isotope = new G4Isotope("Al27", 13, 14, 26.981538*g/mole);

  pSi28Isotope = new G4Isotope("Si28", 14, 14, 27.976927*g/mole);
  pSi29Isotope = new G4Isotope("Si29", 14, 15, 28.976495*g/mole);
  pSi30Isotope = new G4Isotope("Si30", 14, 16, 29.973770*g/mole);

  pP31Isotope = new G4Isotope("P31", 15, 16, 30.973762*g/mole);

  pS32Isotope = new G4Isotope("S32", 16, 16, 31.972071*g/mole);
  pS33Isotope = new G4Isotope("S33", 16, 17, 32.971458*g/mole);
  pS34Isotope = new G4Isotope("S34", 16, 18, 33.967867*g/mole);
  pS36Isotope = new G4Isotope("S36", 16, 20, 35.967081*g/mole);

  pAr36Isotope = new G4Isotope("Ar36", 18, 18, 35.967546*g/mole);
  pAr38Isotope = new G4Isotope("Ar38", 18, 20, 37.962732*g/mole);
  pAr40Isotope = new G4Isotope("Ar40", 18, 22, 39.962383*g/mole);

  pK39Isotope = new G4Isotope("K39", 19, 20, 38.963707*g/mole);
  pK40Isotope = new G4Isotope("K40", 19, 21, 39.963999*g/mole);
  pK41Isotope = new G4Isotope("K41", 19, 22, 40.961826*g/mole);

  pCa40Isotope = new G4Isotope("Ca40", 20, 20, 39.962591*g/mole);
  pCa42Isotope = new G4Isotope("Ca42", 20, 22, 41.958618*g/mole);
  pCa43Isotope = new G4Isotope("Ca43", 20, 23, 42.958767*g/mole);
  pCa44Isotope = new G4Isotope("Ca44", 20, 24, 43.955481*g/mole);
  pCa46Isotope = new G4Isotope("Ca46", 20, 26, 45.953693*g/mole);
  pCa48Isotope = new G4Isotope("Ca48", 20, 28, 47.952534*g/mole);

  pTi46Isotope = new G4Isotope("Ti46", 22, 24, 45.952629*g/mole);
  pTi47Isotope = new G4Isotope("Ti47", 22, 25, 46.951764*g/mole);
  pTi48Isotope = new G4Isotope("Ti48", 22, 26, 47.947947*g/mole);
  pTi49Isotope = new G4Isotope("Ti49", 22, 27, 48.947871*g/mole);
  pTi50Isotope = new G4Isotope("Ti50", 22, 28, 49.944792*g/mole);

  pCr50Isotope = new G4Isotope("Cr50", 24, 26, 49.946050*g/mole);
  pCr52Isotope = new G4Isotope("Cr52", 24, 28, 51.940512*g/mole);
  pCr53Isotope = new G4Isotope("Cr53", 24, 29, 52.940654*g/mole);
  pCr54Isotope = new G4Isotope("Cr54", 24, 30, 53.938885*g/mole);

  pMn55Isotope = new G4Isotope("Mn55", 25, 30, 54.938050*g/mole);

  pFe54Isotope = new G4Isotope("Fe54", 26, 28, 53.939615*g/mole);
  pFe56Isotope = new G4Isotope("Fe56", 26, 30, 55.934942*g/mole);
  pFe57Isotope = new G4Isotope("Fe57", 26, 31, 56.935399*g/mole);
  pFe58Isotope = new G4Isotope("Fe58", 26, 32, 57.933280*g/mole);

  pCo59Isotope = new G4Isotope("Co59", 27, 32, 58.933200*g/mole);

  pNi58Isotope = new G4Isotope("Ni58", 28, 30, 57.935348*g/mole);
  pNi60Isotope = new G4Isotope("Ni60", 28, 32, 59.930791*g/mole);
  pNi61Isotope = new G4Isotope("Ni61", 28, 33, 60.931060*g/mole);
  pNi62Isotope = new G4Isotope("Ni62", 28, 34, 61.928349*g/mole);
  pNi64Isotope = new G4Isotope("Ni64", 28, 36, 63.927970*g/mole);

  pCu63Isotope = new G4Isotope("Cu63", 29, 34, 62.929601*g/mole);
  pCu65Isotope = new G4Isotope("Cu65", 29, 36, 64.927794*g/mole);

   pMo92Isotope = new G4Isotope("Mo92",  42, 50, 91.906810*g/mole);
   pMo94Isotope = new G4Isotope("Mo94",  42, 52, 93.905088*g/mole);
   pMo95Isotope = new G4Isotope("Mo95",  42, 53, 94.905841*g/mole);
   pMo96Isotope = new G4Isotope("Mo96",  42, 54, 95.904679*g/mole);
   pMo97Isotope = new G4Isotope("Mo97",  42, 55, 96.906021*g/mole);
   pMo98Isotope = new G4Isotope("Mo98",  42, 56, 97.905408*g/mole);
  pMo100Isotope = new G4Isotope("Mo100", 42, 58, 99.907477*g/mole);

  pSb121Isotope = new G4Isotope("Sb121", 51, 70, 120.903818*g/mole);
  pSb123Isotope = new G4Isotope("Sb123", 51, 72, 122.904216*g/mole);

  pXe124Isotope = new G4Isotope("Xe124", 54, 70, 123.905896*g/mole);
  pXe126Isotope = new G4Isotope("Xe126", 54, 72, 125.904269*g/mole);
  pXe128Isotope = new G4Isotope("Xe128", 54, 74, 127.903530*g/mole);
  pXe129Isotope = new G4Isotope("Xe129", 54, 75, 128.904779*g/mole);
  pXe130Isotope = new G4Isotope("Xe130", 54, 76, 129.903508*g/mole);
  pXe131Isotope = new G4Isotope("Xe131", 54, 77, 130.905082*g/mole);
  pXe132Isotope = new G4Isotope("Xe132", 54, 78, 131.904154*g/mole);
  pXe134Isotope = new G4Isotope("Xe134", 54, 80, 133.905395*g/mole);
  pXe136Isotope = new G4Isotope("Xe136", 54, 82, 135.907220*g/mole);

  pPb204Isotope = new G4Isotope("Pb204", 82, 122, 203.973029*g/mole);
  pPb206Isotope = new G4Isotope("Pb206", 82, 124, 205.974449*g/mole);
  pPb207Isotope = new G4Isotope("Pb207", 82, 125, 206.975881*g/mole);
  pPb208Isotope = new G4Isotope("Pb208", 82, 126, 207.976636*g/mole);

  // Create Elements
  pHElement = new G4Element("Hydrogen", "H", 2);
  pHElement->AddIsotope(pH1Isotope, 99.9885*perCent);
  pHElement->AddIsotope(pH2Isotope,  0.0155*perCent);

  pBeElement = new G4Element("Beryllium", "Be", 1);
  pBeElement->AddIsotope(pBe9Isotope, 100*perCent);

  pBElement = new G4Element("Boron", "B", 2);
  pBElement->AddIsotope(pB10Isotope, 19.9000*perCent);
  pBElement->AddIsotope(pB11Isotope, 80.1000*perCent);

  pCElement = new G4Element("Carbon", "C", 2);
  pCElement->AddIsotope(pC12Isotope, 98.9300*perCent);
  pCElement->AddIsotope(pC13Isotope,  1.0700*perCent);

  pNElement = new G4Element("Nitrogen", "N", 2);
  pNElement->AddIsotope(pN14Isotope, 99.6320*perCent);
  pNElement->AddIsotope(pN15Isotope,  0.3680*perCent);

  pOElement = new G4Element("Oxygen", "O", 3);
  pOElement->AddIsotope(pO16Isotope, 99.757*perCent);
  pOElement->AddIsotope(pO17Isotope,  0.038*perCent);
  pOElement->AddIsotope(pO18Isotope,  0.205*perCent);

  pFElement = new G4Element("Fluorine", "F", 1);
  pFElement->AddIsotope(pF19Isotope, 100*perCent);

  pNaElement = new G4Element("Sodium", "Na", 1);
  pNaElement->AddIsotope(pNa23Isotope, 100*perCent);

  pMgElement = new G4Element("Magnesium", "Mg", 3);
  pMgElement->AddIsotope(pMg24Isotope, 78.9900*perCent);
  pMgElement->AddIsotope(pMg25Isotope, 10.0000*perCent);
  pMgElement->AddIsotope(pMg26Isotope, 11.0100*perCent);

  pAlElement = new G4Element("Aluminum", "Al", 1);
  pAlElement->AddIsotope(pAl27Isotope, 100*perCent);

  pSiElement = new G4Element("Silicon", "Si", 3);
  pSiElement->AddIsotope(pSi28Isotope, 92.2297*perCent);
  pSiElement->AddIsotope(pSi29Isotope,  4.6832*perCent);
  pSiElement->AddIsotope(pSi30Isotope,  3.0872*perCent);

  pPElement = new G4Element("Phosphorus", "P", 1);
  pPElement->AddIsotope(pP31Isotope, 100*perCent);

  pSElement = new G4Element("Sulfur", "S", 4);
  pSElement->AddIsotope(pS32Isotope, 94.9300*perCent);
  pSElement->AddIsotope(pS33Isotope,  0.7600*perCent);
  pSElement->AddIsotope(pS34Isotope,  4.2900*perCent);
  pSElement->AddIsotope(pS36Isotope,  0.0200*perCent);

  pArElement = new G4Element("Argon", "Ar", 3);
  pArElement->AddIsotope(pAr36Isotope,  0.3365*perCent);
  pArElement->AddIsotope(pAr38Isotope,  0.0632*perCent);
  pArElement->AddIsotope(pAr40Isotope, 99.6003*perCent);

  pKElement = new G4Element("Potassium", "K", 3);
  pKElement->AddIsotope(pK39Isotope, 93.2581*perCent);
  pKElement->AddIsotope(pK40Isotope,  0.0117*perCent);
  pKElement->AddIsotope(pK41Isotope,  6.7302*perCent);

  pCaElement = new G4Element("Calcium", "Ca", 6);
  pCaElement->AddIsotope(pCa40Isotope, 96.9410*perCent);
  pCaElement->AddIsotope(pCa42Isotope,  0.6470*perCent);
  pCaElement->AddIsotope(pCa43Isotope,  0.1350*perCent);
  pCaElement->AddIsotope(pCa44Isotope,  2.0860*perCent);
  pCaElement->AddIsotope(pCa46Isotope,  0.0040*perCent);
  pCaElement->AddIsotope(pCa48Isotope,  0.1870*perCent);

  pTiElement = new G4Element("Titanium", "Ti", 5);
  pTiElement->AddIsotope(pTi46Isotope,  8.2500*perCent);
  pTiElement->AddIsotope(pTi47Isotope,  7.4400*perCent);
  pTiElement->AddIsotope(pTi48Isotope, 73.7200*perCent);
  pTiElement->AddIsotope(pTi49Isotope,  5.4100*perCent);
  pTiElement->AddIsotope(pTi50Isotope,  5.1800*perCent);

  pCrElement = new G4Element("Chromium", "Cr", 4);
  pCrElement->AddIsotope(pCr50Isotope,  4.3450*perCent);
  pCrElement->AddIsotope(pCr52Isotope, 83.7890*perCent);
  pCrElement->AddIsotope(pCr53Isotope,  9.5010*perCent);
  pCrElement->AddIsotope(pCr54Isotope,  2.3650*perCent);

  pMnElement = new G4Element("Manganese", "Mn", 1);
  pMnElement->AddIsotope(pMn55Isotope, 100*perCent);

  pFeElement = new G4Element("Iron", "Fe", 4);
  pFeElement->AddIsotope(pFe54Isotope,  5.8450*perCent);
  pFeElement->AddIsotope(pFe56Isotope, 91.7540*perCent);
  pFeElement->AddIsotope(pFe57Isotope,  2.1190*perCent);
  pFeElement->AddIsotope(pFe58Isotope,  0.2820*perCent);

  pCoElement = new G4Element("Cobalt", "Co", 1);
  pCoElement->AddIsotope(pCo59Isotope, 100*perCent);

  pNiElement = new G4Element("Nickel", "Ni", 5);
  pNiElement->AddIsotope(pNi58Isotope, 68.0769*perCent);
  pNiElement->AddIsotope(pNi60Isotope, 26.2231*perCent);
  pNiElement->AddIsotope(pNi61Isotope,  1.1399*perCent);
  pNiElement->AddIsotope(pNi62Isotope,  3.6345*perCent);
  pNiElement->AddIsotope(pNi64Isotope,  0.9256*perCent);

  pCuElement = new G4Element("Copper", "Cu", 2);
  pCuElement->AddIsotope(pCu63Isotope, 69.1700*perCent);
  pCuElement->AddIsotope(pCu65Isotope, 30.8300*perCent);

  pMoElement = new G4Element("Molybdenum", "Mo", 7);
  pMoElement->AddIsotope(pMo92Isotope, 14.8400*perCent);
  pMoElement->AddIsotope(pMo94Isotope,  9.2500*perCent);
  pMoElement->AddIsotope(pMo95Isotope, 15.9200*perCent);
  pMoElement->AddIsotope(pMo96Isotope, 16.6800*perCent);
  pMoElement->AddIsotope(pMo97Isotope,  9.5500*perCent);
  pMoElement->AddIsotope(pMo98Isotope, 24.1300*perCent);
  pMoElement->AddIsotope(pMo100Isotope, 9.6300*perCent);

  pSbElement = new G4Element("Antimony", "Sb", 2);
  pSbElement->AddIsotope(pSb121Isotope, 57.2100*perCent);
  pSbElement->AddIsotope(pSb123Isotope, 42.7900*perCent);

  pXeElement = new G4Element("Xenon", "Xe", 9);
  pXeElement->AddIsotope(pXe124Isotope,  0.0900*perCent);
  pXeElement->AddIsotope(pXe126Isotope,  0.0900*perCent);
  pXeElement->AddIsotope(pXe128Isotope,  1.9200*perCent);
  pXeElement->AddIsotope(pXe129Isotope, 26.4400*perCent);
  pXeElement->AddIsotope(pXe130Isotope,  4.0800*perCent);
  pXeElement->AddIsotope(pXe131Isotope, 21.1800*perCent);
  pXeElement->AddIsotope(pXe132Isotope, 26.8900*perCent);
  pXeElement->AddIsotope(pXe134Isotope, 10.4400*perCent);
  pXeElement->AddIsotope(pXe136Isotope,  8.8700*perCent);

  pPbElement = new G4Element("Lead", "Pb", 4);
  pPbElement->AddIsotope(pPb204Isotope,  1.4000*perCent);
  pPbElement->AddIsotope(pPb206Isotope, 24.1000*perCent);
  pPbElement->AddIsotope(pPb207Isotope, 22.1000*perCent);
  pPbElement->AddIsotope(pPb208Isotope, 52.4000*perCent);

  // Create Materials
  pAirMaterial = new G4Material("Air", 0.00120479*g/cm3, 4, kStateGas);
  pAirMaterial->AddElement(pNElement, 75.5268*perCent);
  pAirMaterial->AddElement(pOElement, 23.1781*perCent);
  pAirMaterial->AddElement(pArElement, 1.2827*perCent);
  pAirMaterial->AddElement(pCElement, 0.0124*perCent);
    
  pConcreteMaterial = new G4Material("Concrete", 2.3000*g/cm3, 10, kStateSolid);
  pConcreteMaterial->AddElement(pOElement, 52.9107*perCent);
  pConcreteMaterial->AddElement(pSiElement, 33.7021*perCent);
  pConcreteMaterial->AddElement(pCaElement, 4.4000*perCent);
  pConcreteMaterial->AddElement(pAlElement, 3.3872*perCent);
  pConcreteMaterial->AddElement(pNaElement, 1.6000*perCent);
  pConcreteMaterial->AddElement(pFeElement, 1.4000*perCent);
  pConcreteMaterial->AddElement(pKElement, 1.3000*perCent);
  pConcreteMaterial->AddElement(pHElement, 1.0000*perCent);
  pConcreteMaterial->AddElement(pMgElement, 0.2000*perCent);
  pConcreteMaterial->AddElement(pCElement, 0.1000*perCent);

  pLeadMaterial = new G4Material("Lead", 11.3500*g/cm3, 1, kStateSolid);
  pLeadMaterial->AddElement(pPbElement, 100.0000*perCent);

  pAluminumOxideMaterial = new G4Material("AluminumOxide", 3.9500*g/cm3, 2, kStateSolid);
  pAluminumOxideMaterial->AddElement(pOElement,  3);
  pAluminumOxideMaterial->AddElement(pAlElement, 2);

  pBerylliumOxideMaterial = new G4Material("BerylliumOxide", 3.0100*g/cm3, 2, kStateSolid);
  pBerylliumOxideMaterial->AddElement(pBeElement, 1);
  pBerylliumOxideMaterial->AddElement(pOElement,  1);
  
  pBorosilicateGlassMaterial = new G4Material("BorosilicateGlass", 2.2300*g/cm3, 5, kStateSolid);
  pBorosilicateGlassMaterial->AddElement(pOElement, 60);
  pBorosilicateGlassMaterial->AddElement(pSiElement, 26);
  pBorosilicateGlassMaterial->AddElement(pBElement, 9);
  pBorosilicateGlassMaterial->AddElement(pNaElement, 3);
  pBorosilicateGlassMaterial->AddElement(pAlElement, 1);

  pJBWeldMaterial = new G4Material("JBWeld", 1.1600*g/cm3, 6, kStateSolid);
  pJBWeldMaterial->AddElement(pOElement,  28.4333*perCent);
  pJBWeldMaterial->AddElement(pCElement,  26.4333*perCent);
  pJBWeldMaterial->AddElement(pFeElement, 21.3334*perCent);
  pJBWeldMaterial->AddElement(pHElement,  15.6000*perCent);
  pJBWeldMaterial->AddElement(pCaElement,  8.0000*perCent);
  pJBWeldMaterial->AddElement(pNElement,   0.2000*perCent);

  pAcrylicMaterial = new G4Material("Acrylic", 1.180*g/cm3, 3, kStateSolid);
  pAcrylicMaterial->AddElement(pCElement, 59.98*perCent);
  pAcrylicMaterial->AddElement(pOElement, 31.96*perCent);
  pAcrylicMaterial->AddElement(pHElement, 8.05*perCent);
  
  pStainlessSteelMaterial = new G4Material("Stainless Steel", 8.0000*g/cm3, 10, kStateSolid);
  pStainlessSteelMaterial->AddElement(pFeElement, 65.4950*perCent);
  pStainlessSteelMaterial->AddElement(pCrElement, 17.0000*perCent);
  pStainlessSteelMaterial->AddElement(pNiElement, 12.0000*perCent);
  pStainlessSteelMaterial->AddElement(pMoElement,  2.5000*perCent);
  pStainlessSteelMaterial->AddElement(pMnElement,  2.0000*perCent);
  pStainlessSteelMaterial->AddElement(pSiElement,  0.7500*perCent);
  pStainlessSteelMaterial->AddElement(pNElement,   0.1000*perCent);
  pStainlessSteelMaterial->AddElement(pCElement,   0.0800*perCent);
  pStainlessSteelMaterial->AddElement(pPElement,   0.0450*perCent);
  pStainlessSteelMaterial->AddElement(pSElement,   0.0300*perCent);
 
  pVacuumMaterial = new G4Material("Vacuum", 1.0e-20*g/cm3, 4, kStateGas);
  pVacuumMaterial->AddElement(pNElement, 75.5268*perCent);
  pVacuumMaterial->AddElement(pOElement, 23.1781*perCent);
  pVacuumMaterial->AddElement(pArElement, 1.2827*perCent);
  pVacuumMaterial->AddElement(pCElement, 0.0124*perCent);
    
  pGXeMaterial = new G4Material("GXe", 0.0011655*g/cm3, 1, kStateGas);
  pGXeMaterial->AddElement(pXeElement, 100*perCent);
    
  pLXeMaterial = new G4Material("LXe", 2.9223*g/cm3, 1, kStateLiquid);
  pLXeMaterial->AddElement(pXeElement, 100*perCent);
    
  pPTFEMaterial = new G4Material("PTFE", 2.200*g/cm3, 2, kStateSolid);
  pPTFEMaterial->AddElement(pFElement, 4);
  pPTFEMaterial->AddElement(pCElement, 2);
    
  pKovarMaterial = new G4Material("Kovar", 8.330*g/cm3, 6, kStateSolid);
  pKovarMaterial->AddElement(pFeElement, 53.4900*perCent);
  pKovarMaterial->AddElement(pNiElement, 29.0000*perCent);
  pKovarMaterial->AddElement(pCoElement, 17.0000*perCent);
  pKovarMaterial->AddElement(pMnElement, 0.3000*perCent);
  pKovarMaterial->AddElement(pSiElement, 0.2000*perCent);
  pKovarMaterial->AddElement(pCElement,  0.0100*perCent);
    
  pQuartzMaterial = new G4Material("Quartz", 2.201*g/cm3, 2, kStateSolid);
  pQuartzMaterial->AddElement(pSiElement, 1);
  pQuartzMaterial->AddElement(pOElement, 2);
    
  pPhotocathodeMaterial = new G4Material("PhotocathodeAl", 8.000*g/cm3, 1, kStateSolid);
  pPhotocathodeMaterial->AddElement(pAlElement, 1);
    
  pCeramicMaterial = new G4Material("Ceramic", 4.000*g/cm3, 2, kStateSolid);
  pCeramicMaterial->AddElement(pOElement, 3);
  pCeramicMaterial->AddElement(pAlElement, 2);
}

void RELAXDetectorConstruction::ConstructLaboratory()
{
  //////////////////////////
  // Construct Laboratory //
  //////////////////////////

  // Set Laboratory Variables
  dLaboratoryLength = 28.000 * 2.54 * cm;
  dLaboratoryWidth = 16.000 * 2.54 * cm;
  dLaboratoryHeight = 43.000 * 2.54 * cm;

  // Create Laboratory
  pLaboratoryBox = new G4Box
  ("LaboratoryBox", 0.5 * dLaboratoryLength, 0.5 * dLaboratoryWidth, 0.5 * dLaboratoryHeight);
  pLaboratoryLV = new G4LogicalVolume
  (pLaboratoryBox, pAirMaterial, "LaboratoryLV");
  pLaboratoryPV = new G4PVPlacement
  (0, G4ThreeVector(), pLaboratoryLV, "Laboratory", 0, false, 0);

  pLaboratoryLV->SetVisAttributes(G4VisAttributes::Invisible);

  // Set Mother Logical Volume
  pMotherLV = pLaboratoryLV;

  ///// COnstruct some piece
  //Define the arrays for radius and height
G4double Rad1 = 32.0*mm;
G4double Rad2 = 35.0*mm;
G4double Rad3 = 35.0*mm;
G4double Rad4 = 43.0*mm;
G4double Rad5 = 43.0*mm;
G4double Rad6 = 52.5*mm;
G4double Rad7 = 52.5*mm;
G4double Rad8 = 54.0*mm;
G4double Rad9 = 54.0*mm;
G4double Rad10 = 36.0*mm;
G4double Rad11 = 36.0*mm;
G4double Rad12 = 35.0*mm;
G4double Rad13 = 35.0*mm;
G4double Rad14 = 36.0*mm;
G4double Rad15 = 36.0*mm;
G4double Rad16 = 54.0*mm;
G4double Rad17 = 54.0*mm;
G4double Rad18 = 52.5*mm;
G4double Rad19 = 52.5*mm;
G4double Rad20 = 43.0*mm;
G4double Rad21 = 43.0*mm;
G4double Rad22 = 35.0*mm;
G4double Rad23 = 35.0*mm;
G4double Rad24 = 32.0*mm;

G4double Hgt1 = 20.525*mm;
G4double Hgt2 = 20.525*mm;
G4double Hgt3 = 19.125*mm;
G4double Hgt4 = 19.125*mm;
G4double Hgt5 = 20.625*mm;
G4double Hgt6 = 20.625*mm;
G4double Hgt7 = 18.875*mm;
G4double Hgt8 = 18.875*mm;
G4double Hgt9 = 15.125*mm;
G4double Hgt10 = 15.125*mm;
G4double Hgt11 = 16.125*mm;
G4double Hgt12 = 16.125*mm;
G4double Hgt13 = -14.875*mm;
G4double Hgt14 = -14.875*mm;
G4double Hgt15 = -13.875*mm;
G4double Hgt16 = -13.875*mm;
G4double Hgt17 = -20.625*mm;
G4double Hgt18 = -20.625*mm;
G4double Hgt19 = -19.375*mm;
G4double Hgt20 = -19.375*mm;
G4double Hgt21 = -17.875*mm;
G4double Hgt22 = -17.875*mm;
G4double Hgt23 = -19.275*mm;
G4double Hgt24 = -19.275*mm;

G4double RadArray [] = {Rad1, Rad2, Rad3, Rad4, Rad5, Rad6, Rad7, Rad8, Rad9, Rad10, Rad11, Rad12, Rad13, Rad14, Rad15, Rad16, Rad17, Rad18, Rad19, Rad20, Rad21, Rad22, Rad23, Rad24};

G4double HgtArray [] = {Hgt1, Hgt2, Hgt3, Hgt4, Hgt5, Hgt6, Hgt7, Hgt8, Hgt9, Hgt10, Hgt11, Hgt12, Hgt13, Hgt14, Hgt15, Hgt16, Hgt17, Hgt18, Hgt19, Hgt20, Hgt21, Hgt22, Hgt23, Hgt24};

//Finally, we define the solid

G4double TP_x = 0.0*m;
G4double TP_y = 0.0*m;
G4double TP_z = 0.0*m;

G4GenericPolycone* pTeflonPieceS = new G4GenericPolycone("Teflon Piece", 0, 2*M_PI, 24, RadArray, HgtArray);

G4LogicalVolume* pTeflonPieceLV = new G4LogicalVolume(pTeflonPieceS, pPTFEMaterial, "Teflon Piece");

G4VPhysicalVolume* pG4pTeflonPiecePV = new G4PVPlacement(0, G4ThreeVector(TP_x, TP_y, TP_z), pTeflonPieceLV, "Teflon Piece", pMotherLV, false, 0);

  G4VisAttributes* pTeflonVA = new G4VisAttributes(G4Colour(0.0, 1.0, 1.0));
  pTeflonVA->SetForceSolid(true);
  pTeflonPieceLV->SetVisAttributes(pTeflonVA);

}


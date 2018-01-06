/////////////////////////////////////
// Nickolas Upole & Bruno Petrucci //
// University of Chicago           //
// Fall 2017                       //
// RELAXDetectorConstruction.cc    //
/////////////////////////////////////

#include "RELAXDetectorConstruction.hh"
#include "G4ios.hh"
#include "math.h"

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
    G4Isotope* pH1Isotope = new G4Isotope("H1", 1, 1, 1.007825*g/mole);
    G4Isotope* pH2Isotope = new G4Isotope("H2", 1, 2, 2.014102*g/mole);

    G4Isotope* pBe9Isotope = new G4Isotope("Be9", 4, 5, 9.012182*g/mole);

    G4Isotope* pB10Isotope = new G4Isotope("B10", 5, 5, 10.012937*g/mole);
    G4Isotope* pB11Isotope = new G4Isotope("B11", 5, 6, 11.009305*g/mole);

    G4Isotope* pC12Isotope = new G4Isotope("C12", 6, 6, 12.000000*g/mole);
    G4Isotope* pC13Isotope = new G4Isotope("C13", 6, 7, 13.003355*g/mole);

    G4Isotope* pN14Isotope = new G4Isotope("N14", 7, 7, 14.003074*g/mole);
    G4Isotope* pN15Isotope = new G4Isotope("N15", 7, 8, 15.000109*g/mole);

    G4Isotope* pO16Isotope = new G4Isotope("O16", 8,  8, 15.994915*g/mole);
    G4Isotope* pO17Isotope = new G4Isotope("O17", 8,  9, 16.999132*g/mole);
    G4Isotope* pO18Isotope = new G4Isotope("O18", 8, 10, 17.999160*g/mole);

    G4Isotope* pF19Isotope = new G4Isotope("F19", 9, 10, 18.998403*g/mole);

    G4Isotope* pNa23Isotope = new G4Isotope("Na23", 11, 12, 22.989770*g/mole);

    G4Isotope* pMg24Isotope = new G4Isotope("Mg24", 12, 12, 23.985042*g/mole);
    G4Isotope* pMg25Isotope = new G4Isotope("Mg25", 12, 13, 24.985837*g/mole);
    G4Isotope* pMg26Isotope = new G4Isotope("Mg26", 12, 14, 25.982593*g/mole);

    G4Isotope* pAl27Isotope = new G4Isotope("Al27", 13, 14, 26.981538*g/mole);

    G4Isotope* pSi28Isotope = new G4Isotope("Si28", 14, 14, 27.976927*g/mole);
    G4Isotope* pSi29Isotope = new G4Isotope("Si29", 14, 15, 28.976495*g/mole);
    G4Isotope* pSi30Isotope = new G4Isotope("Si30", 14, 16, 29.973770*g/mole);

    G4Isotope* pP31Isotope = new G4Isotope("P31", 15, 16, 30.973762*g/mole);

    G4Isotope* pS32Isotope = new G4Isotope("S32", 16, 16, 31.972071*g/mole);
    G4Isotope* pS33Isotope = new G4Isotope("S33", 16, 17, 32.971458*g/mole);
    G4Isotope* pS34Isotope = new G4Isotope("S34", 16, 18, 33.967867*g/mole);
    G4Isotope* pS36Isotope = new G4Isotope("S36", 16, 20, 35.967081*g/mole);

    G4Isotope* pAr36Isotope = new G4Isotope("Ar36", 18, 18, 35.967546*g/mole);
    G4Isotope* pAr38Isotope = new G4Isotope("Ar38", 18, 20, 37.962732*g/mole);
    G4Isotope* pAr40Isotope = new G4Isotope("Ar40", 18, 22, 39.962383*g/mole);

    G4Isotope* pK39Isotope = new G4Isotope("K39", 19, 20, 38.963707*g/mole);
    G4Isotope* pK40Isotope = new G4Isotope("K40", 19, 21, 39.963999*g/mole);
    G4Isotope* pK41Isotope = new G4Isotope("K41", 19, 22, 40.961826*g/mole);

    G4Isotope* pCa40Isotope = new G4Isotope("Ca40", 20, 20, 39.962591*g/mole);
    G4Isotope* pCa42Isotope = new G4Isotope("Ca42", 20, 22, 41.958618*g/mole);
    G4Isotope* pCa43Isotope = new G4Isotope("Ca43", 20, 23, 42.958767*g/mole);
    G4Isotope* pCa44Isotope = new G4Isotope("Ca44", 20, 24, 43.955481*g/mole);
    G4Isotope* pCa46Isotope = new G4Isotope("Ca46", 20, 26, 45.953693*g/mole);
    G4Isotope* pCa48Isotope = new G4Isotope("Ca48", 20, 28, 47.952534*g/mole);

    G4Isotope* pTi46Isotope = new G4Isotope("Ti46", 22, 24, 45.952629*g/mole);
    G4Isotope* pTi47Isotope = new G4Isotope("Ti47", 22, 25, 46.951764*g/mole);
    G4Isotope* pTi48Isotope = new G4Isotope("Ti48", 22, 26, 47.947947*g/mole);
    G4Isotope* pTi49Isotope = new G4Isotope("Ti49", 22, 27, 48.947871*g/mole);
    G4Isotope* pTi50Isotope = new G4Isotope("Ti50", 22, 28, 49.944792*g/mole);

    G4Isotope* pCr50Isotope = new G4Isotope("Cr50", 24, 26, 49.946050*g/mole);
    G4Isotope* pCr52Isotope = new G4Isotope("Cr52", 24, 28, 51.940512*g/mole);
    G4Isotope* pCr53Isotope = new G4Isotope("Cr53", 24, 29, 52.940654*g/mole);
    G4Isotope* pCr54Isotope = new G4Isotope("Cr54", 24, 30, 53.938885*g/mole);

    G4Isotope* pMn55Isotope = new G4Isotope("Mn55", 25, 30, 54.938050*g/mole);

    G4Isotope* pFe54Isotope = new G4Isotope("Fe54", 26, 28, 53.939615*g/mole);
    G4Isotope* pFe56Isotope = new G4Isotope("Fe56", 26, 30, 55.934942*g/mole);
    G4Isotope* pFe57Isotope = new G4Isotope("Fe57", 26, 31, 56.935399*g/mole);
    G4Isotope* pFe58Isotope = new G4Isotope("Fe58", 26, 32, 57.933280*g/mole);

    G4Isotope* pCo59Isotope = new G4Isotope("Co59", 27, 32, 58.933200*g/mole);

    G4Isotope* pNi58Isotope = new G4Isotope("Ni58", 28, 30, 57.935348*g/mole);
    G4Isotope* pNi60Isotope = new G4Isotope("Ni60", 28, 32, 59.930791*g/mole);
    G4Isotope* pNi61Isotope = new G4Isotope("Ni61", 28, 33, 60.931060*g/mole);
    G4Isotope* pNi62Isotope = new G4Isotope("Ni62", 28, 34, 61.928349*g/mole);
    G4Isotope* pNi64Isotope = new G4Isotope("Ni64", 28, 36, 63.927970*g/mole);

    G4Isotope* pCu63Isotope = new G4Isotope("Cu63", 29, 34, 62.929601*g/mole);
    G4Isotope* pCu65Isotope = new G4Isotope("Cu65", 29, 36, 64.927794*g/mole);

    G4Isotope* pMo92Isotope = new G4Isotope("Mo92",  42, 50, 91.906810*g/mole);
    G4Isotope* pMo94Isotope = new G4Isotope("Mo94",  42, 52, 93.905088*g/mole);
    G4Isotope* pMo95Isotope = new G4Isotope("Mo95",  42, 53, 94.905841*g/mole);
    G4Isotope* pMo96Isotope = new G4Isotope("Mo96",  42, 54, 95.904679*g/mole);
    G4Isotope* pMo97Isotope = new G4Isotope("Mo97",  42, 55, 96.906021*g/mole);
    G4Isotope* pMo98Isotope = new G4Isotope("Mo98",  42, 56, 97.905408*g/mole);
    G4Isotope* pMo100Isotope = new G4Isotope("Mo100", 42, 58, 99.907477*g/mole);

    G4Isotope* pSb121Isotope = new G4Isotope("Sb121", 51, 70, 120.903818*g/mole);
    G4Isotope* pSb123Isotope = new G4Isotope("Sb123", 51, 72, 122.904216*g/mole);

    G4Isotope* pXe124Isotope = new G4Isotope("Xe124", 54, 70, 123.905896*g/mole);
    G4Isotope* pXe126Isotope = new G4Isotope("Xe126", 54, 72, 125.904269*g/mole);
    G4Isotope* pXe128Isotope = new G4Isotope("Xe128", 54, 74, 127.903530*g/mole);
    G4Isotope* pXe129Isotope = new G4Isotope("Xe129", 54, 75, 128.904779*g/mole);
    G4Isotope* pXe130Isotope = new G4Isotope("Xe130", 54, 76, 129.903508*g/mole);
    G4Isotope* pXe131Isotope = new G4Isotope("Xe131", 54, 77, 130.905082*g/mole);
    G4Isotope* pXe132Isotope = new G4Isotope("Xe132", 54, 78, 131.904154*g/mole);
    G4Isotope* pXe134Isotope = new G4Isotope("Xe134", 54, 80, 133.905395*g/mole);
    G4Isotope* pXe136Isotope = new G4Isotope("Xe136", 54, 82, 135.907220*g/mole);

    G4Isotope* pPb204Isotope = new G4Isotope("Pb204", 82, 122, 203.973029*g/mole);
    G4Isotope* pPb206Isotope = new G4Isotope("Pb206", 82, 124, 205.974449*g/mole);
    G4Isotope* pPb207Isotope = new G4Isotope("Pb207", 82, 125, 206.975881*g/mole);
    G4Isotope* pPb208Isotope = new G4Isotope("Pb208", 82, 126, 207.976636*g/mole);

    // Create Elements
    G4Element* pHElement = new G4Element("Hydrogen", "H", 2);
    pHElement->AddIsotope(pH1Isotope, 99.9885*perCent);
    pHElement->AddIsotope(pH2Isotope,  0.0155*perCent);

    G4Element* pBeElement = new G4Element("Beryllium", "Be", 1);
    pBeElement->AddIsotope(pBe9Isotope, 100*perCent);

    G4Element* pBElement = new G4Element("Boron", "B", 2);
    pBElement->AddIsotope(pB10Isotope, 19.9000*perCent);
    pBElement->AddIsotope(pB11Isotope, 80.1000*perCent);

    G4Element* pCElement = new G4Element("Carbon", "C", 2);
    pCElement->AddIsotope(pC12Isotope, 98.9300*perCent);
    pCElement->AddIsotope(pC13Isotope,  1.0700*perCent);

    G4Element* pNElement = new G4Element("Nitrogen", "N", 2);
    pNElement->AddIsotope(pN14Isotope, 99.6320*perCent);
    pNElement->AddIsotope(pN15Isotope,  0.3680*perCent);

    G4Element* pOElement = new G4Element("Oxygen", "O", 3);
    pOElement->AddIsotope(pO16Isotope, 99.757*perCent);
    pOElement->AddIsotope(pO17Isotope,  0.038*perCent);
    pOElement->AddIsotope(pO18Isotope,  0.205*perCent);

    G4Element* pFElement = new G4Element("Fluorine", "F", 1);
    pFElement->AddIsotope(pF19Isotope, 100*perCent);

    G4Element* pNaElement = new G4Element("Sodium", "Na", 1);
    pNaElement->AddIsotope(pNa23Isotope, 100*perCent);

    G4Element* pMgElement = new G4Element("Magnesium", "Mg", 3);
    pMgElement->AddIsotope(pMg24Isotope, 78.9900*perCent);
    pMgElement->AddIsotope(pMg25Isotope, 10.0000*perCent);
    pMgElement->AddIsotope(pMg26Isotope, 11.0100*perCent);

    G4Element* pAlElement = new G4Element("Aluminum", "Al", 1);
    pAlElement->AddIsotope(pAl27Isotope, 100*perCent);

    G4Element* pSiElement = new G4Element("Silicon", "Si", 3);
    pSiElement->AddIsotope(pSi28Isotope, 92.2297*perCent);
    pSiElement->AddIsotope(pSi29Isotope,  4.6832*perCent);
    pSiElement->AddIsotope(pSi30Isotope,  3.0872*perCent);

    G4Element* pPElement = new G4Element("Phosphorus", "P", 1);
    pPElement->AddIsotope(pP31Isotope, 100*perCent);

    G4Element* pSElement = new G4Element("Sulfur", "S", 4);
    pSElement->AddIsotope(pS32Isotope, 94.9300*perCent);
    pSElement->AddIsotope(pS33Isotope,  0.7600*perCent);
    pSElement->AddIsotope(pS34Isotope,  4.2900*perCent);
    pSElement->AddIsotope(pS36Isotope,  0.0200*perCent);

    G4Element* pArElement = new G4Element("Argon", "Ar", 3);
    pArElement->AddIsotope(pAr36Isotope,  0.3365*perCent);
    pArElement->AddIsotope(pAr38Isotope,  0.0632*perCent);
    pArElement->AddIsotope(pAr40Isotope, 99.6003*perCent);

    G4Element* pKElement = new G4Element("Potassium", "K", 3);
    pKElement->AddIsotope(pK39Isotope, 93.2581*perCent);
    pKElement->AddIsotope(pK40Isotope,  0.0117*perCent);
    pKElement->AddIsotope(pK41Isotope,  6.7302*perCent);

    G4Element* pCaElement = new G4Element("Calcium", "Ca", 6);
    pCaElement->AddIsotope(pCa40Isotope, 96.9410*perCent);
    pCaElement->AddIsotope(pCa42Isotope,  0.6470*perCent);
    pCaElement->AddIsotope(pCa43Isotope,  0.1350*perCent);
    pCaElement->AddIsotope(pCa44Isotope,  2.0860*perCent);
    pCaElement->AddIsotope(pCa46Isotope,  0.0040*perCent);
    pCaElement->AddIsotope(pCa48Isotope,  0.1870*perCent);

    G4Element* pTiElement = new G4Element("Titanium", "Ti", 5);
    pTiElement->AddIsotope(pTi46Isotope,  8.2500*perCent);
    pTiElement->AddIsotope(pTi47Isotope,  7.4400*perCent);
    pTiElement->AddIsotope(pTi48Isotope, 73.7200*perCent);
    pTiElement->AddIsotope(pTi49Isotope,  5.4100*perCent);
    pTiElement->AddIsotope(pTi50Isotope,  5.1800*perCent);

    G4Element* pCrElement = new G4Element("Chromium", "Cr", 4);
    pCrElement->AddIsotope(pCr50Isotope,  4.3450*perCent);
    pCrElement->AddIsotope(pCr52Isotope, 83.7890*perCent);
    pCrElement->AddIsotope(pCr53Isotope,  9.5010*perCent);
    pCrElement->AddIsotope(pCr54Isotope,  2.3650*perCent);

    G4Element* pMnElement = new G4Element("Manganese", "Mn", 1);
    pMnElement->AddIsotope(pMn55Isotope, 100*perCent);

    G4Element* pFeElement = new G4Element("Iron", "Fe", 4);
    pFeElement->AddIsotope(pFe54Isotope,  5.8450*perCent);
    pFeElement->AddIsotope(pFe56Isotope, 91.7540*perCent);
    pFeElement->AddIsotope(pFe57Isotope,  2.1190*perCent);
    pFeElement->AddIsotope(pFe58Isotope,  0.2820*perCent);

    G4Element* pCoElement = new G4Element("Cobalt", "Co", 1);
    pCoElement->AddIsotope(pCo59Isotope, 100*perCent);

    G4Element* pNiElement = new G4Element("Nickel", "Ni", 5);
    pNiElement->AddIsotope(pNi58Isotope, 68.0769*perCent);
    pNiElement->AddIsotope(pNi60Isotope, 26.2231*perCent);
    pNiElement->AddIsotope(pNi61Isotope,  1.1399*perCent);
    pNiElement->AddIsotope(pNi62Isotope,  3.6345*perCent);
    pNiElement->AddIsotope(pNi64Isotope,  0.9256*perCent);

    G4Element* pCuElement = new G4Element("Copper", "Cu", 2);
    pCuElement->AddIsotope(pCu63Isotope, 69.1700*perCent);
    pCuElement->AddIsotope(pCu65Isotope, 30.8300*perCent);

    G4Element* pMoElement = new G4Element("Molybdenum", "Mo", 7);
    pMoElement->AddIsotope(pMo92Isotope, 14.8400*perCent);
    pMoElement->AddIsotope(pMo94Isotope,  9.2500*perCent);
    pMoElement->AddIsotope(pMo95Isotope, 15.9200*perCent);
    pMoElement->AddIsotope(pMo96Isotope, 16.6800*perCent);
    pMoElement->AddIsotope(pMo97Isotope,  9.5500*perCent);
    pMoElement->AddIsotope(pMo98Isotope, 24.1300*perCent);
    pMoElement->AddIsotope(pMo100Isotope, 9.6300*perCent);

    G4Element* pSbElement = new G4Element("Antimony", "Sb", 2);
    pSbElement->AddIsotope(pSb121Isotope, 57.2100*perCent);
    pSbElement->AddIsotope(pSb123Isotope, 42.7900*perCent);

    G4Element* pXeElement = new G4Element("Xenon", "Xe", 9);
    pXeElement->AddIsotope(pXe124Isotope,  0.0900*perCent);
    pXeElement->AddIsotope(pXe126Isotope,  0.0900*perCent);
    pXeElement->AddIsotope(pXe128Isotope,  1.9200*perCent);
    pXeElement->AddIsotope(pXe129Isotope, 26.4400*perCent);
    pXeElement->AddIsotope(pXe130Isotope,  4.0800*perCent);
    pXeElement->AddIsotope(pXe131Isotope, 21.1800*perCent);
    pXeElement->AddIsotope(pXe132Isotope, 26.8900*perCent);
    pXeElement->AddIsotope(pXe134Isotope, 10.4400*perCent);
    pXeElement->AddIsotope(pXe136Isotope,  8.8700*perCent);

    G4Element* pPbElement = new G4Element("Lead", "Pb", 4);
    pPbElement->AddIsotope(pPb204Isotope,  1.4000*perCent);
    pPbElement->AddIsotope(pPb206Isotope, 24.1000*perCent);
    pPbElement->AddIsotope(pPb207Isotope, 22.1000*perCent);
    pPbElement->AddIsotope(pPb208Isotope, 52.4000*perCent);

    // Create Materials
    G4Material* pAirMaterial = new G4Material("Air", 0.00120479*g/cm3, 4, kStateGas);
    pAirMaterial->AddElement(pNElement, 75.5268*perCent);
    pAirMaterial->AddElement(pOElement, 23.1781*perCent);
    pAirMaterial->AddElement(pArElement, 1.2827*perCent);
    pAirMaterial->AddElement(pCElement, 0.0124*perCent);

    G4Material* pConcreteMaterial = new G4Material("Concrete", 2.3000*g/cm3, 10, kStateSolid);
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

    G4Material* pLeadMaterial = new G4Material("Lead", 11.3500*g/cm3, 1, kStateSolid);
    pLeadMaterial->AddElement(pPbElement, 100.0000*perCent);

    G4Material* pAluminumOxideMaterial = new G4Material("AluminumOxide", 3.9500*g/cm3, 2, kStateSolid);
    pAluminumOxideMaterial->AddElement(pOElement,  3);
    pAluminumOxideMaterial->AddElement(pAlElement, 2);

    G4Material* pBerylliumOxideMaterial = new G4Material("BerylliumOxide", 3.0100*g/cm3, 2, kStateSolid);
    pBerylliumOxideMaterial->AddElement(pBeElement, 1);
    pBerylliumOxideMaterial->AddElement(pOElement,  1);

    G4Material* pBorosilicateGlassMaterial = new G4Material("BorosilicateGlass", 2.2300*g/cm3, 5, kStateSolid);
    pBorosilicateGlassMaterial->AddElement(pOElement, 60);
    pBorosilicateGlassMaterial->AddElement(pSiElement, 26);
    pBorosilicateGlassMaterial->AddElement(pBElement, 9);
    pBorosilicateGlassMaterial->AddElement(pNaElement, 3);
    pBorosilicateGlassMaterial->AddElement(pAlElement, 1);

    G4Material* pJBWeldMaterial = new G4Material("JBWeld", 1.1600*g/cm3, 6, kStateSolid);
    pJBWeldMaterial->AddElement(pOElement,  28.4333*perCent);
    pJBWeldMaterial->AddElement(pCElement,  26.4333*perCent);
    pJBWeldMaterial->AddElement(pFeElement, 21.3334*perCent);
    pJBWeldMaterial->AddElement(pHElement,  15.6000*perCent);
    pJBWeldMaterial->AddElement(pCaElement,  8.0000*perCent);
    pJBWeldMaterial->AddElement(pNElement,   0.2000*perCent);

    G4Material* pAcrylicMaterial = new G4Material("Acrylic", 1.180*g/cm3, 3, kStateSolid);
    pAcrylicMaterial->AddElement(pCElement, 59.98*perCent);
    pAcrylicMaterial->AddElement(pOElement, 31.96*perCent);
    pAcrylicMaterial->AddElement(pHElement, 8.05*perCent);

    G4Material* pStainlessSteelMaterial = new G4Material("Stainless Steel", 8.0000*g/cm3, 10, kStateSolid);
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

    G4Material* pVacuumMaterial = new G4Material("Vacuum", 1.0e-20*g/cm3, 4, kStateGas);
    pVacuumMaterial->AddElement(pNElement, 75.5268*perCent);
    pVacuumMaterial->AddElement(pOElement, 23.1781*perCent);
    pVacuumMaterial->AddElement(pArElement, 1.2827*perCent);
    pVacuumMaterial->AddElement(pCElement, 0.0124*perCent);

    G4Material* pGXeMaterial = new G4Material("GXe", 0.0011655*g/cm3, 1, kStateGas);
    pGXeMaterial->AddElement(pXeElement, 100*perCent);

    G4Material* pLXeMaterial = new G4Material("LXe", 2.9223*g/cm3, 1, kStateLiquid);
    pLXeMaterial->AddElement(pXeElement, 100*perCent);

    G4Material* pPTFEMaterial = new G4Material("PTFE", 2.200*g/cm3, 2, kStateSolid);
    pPTFEMaterial->AddElement(pFElement, 4);
    pPTFEMaterial->AddElement(pCElement, 2);

    G4Material* pKovarMaterial = new G4Material("Kovar", 8.330*g/cm3, 6, kStateSolid);
    pKovarMaterial->AddElement(pFeElement, 53.4900*perCent);
    pKovarMaterial->AddElement(pNiElement, 29.0000*perCent);
    pKovarMaterial->AddElement(pCoElement, 17.0000*perCent);
    pKovarMaterial->AddElement(pMnElement, 0.3000*perCent);
    pKovarMaterial->AddElement(pSiElement, 0.2000*perCent);
    pKovarMaterial->AddElement(pCElement,  0.0100*perCent);

    G4Material* pQuartzMaterial = new G4Material("Quartz", 2.201*g/cm3, 2, kStateSolid);
    pQuartzMaterial->AddElement(pSiElement, 1);
    pQuartzMaterial->AddElement(pOElement, 2);

    G4Material* pPhotocathodeMaterial = new G4Material("Photocathode", 8.000*g/cm3, 1, kStateSolid);
    pPhotocathodeMaterial->AddElement(pAlElement, 1);
    G4Material* pCeramicMaterial = new G4Material("Ceramic", 4.000*g/cm3, 2, kStateSolid);
    pCeramicMaterial->AddElement(pOElement, 3);
    pCeramicMaterial->AddElement(pAlElement, 2);
}

void RELAXDetectorConstruction::ConstructLaboratory()
{
    //////////////////////////
    // Construct Laboratory //
    //////////////////////////

    // Set Laboratory Variables
    G4double dLaboratoryLength = 400.000 * cm;
    G4double  dLaboratoryWidth = 400.000 * cm;
    G4double dLaboratoryHeight = 400.000 * cm;

    // Create Laboratory
    G4Box* pLaboratoryBox = new G4Box("LaboratoryBox", 0.5 * dLaboratoryLength, 0.5 * dLaboratoryWidth, 0.5 * dLaboratoryHeight);
    pLaboratoryLV = new G4LogicalVolume(pLaboratoryBox, G4Material::GetMaterial("Air"), "LaboratoryLV");
    pLaboratoryPV = new G4PVPlacement(0, G4ThreeVector(), pLaboratoryLV, "Laboratory", 0, false, 0);

    pLaboratoryLV->SetVisAttributes(G4VisAttributes::Invisible);

    // Set Mother Logical Volume
    pMotherLV = pLaboratoryLV;


    //////////////////////
    // Construct PTFE00 //
    //////////////////////

    // Set PTFE00Stock Variables
    G4double  dPTFE00StockRadius1 = 29.00 * mm;
    G4double  dPTFE00StockRadius2 = 54.00 * mm;
    G4double  dPTFE00StockRadius3 = dPTFE00StockRadius2;
    G4double  dPTFE00StockRadius4 = 37.65 * mm;
    G4double  dPTFE00StockRadius5 = dPTFE00StockRadius4;
    G4double  dPTFE00StockRadius6 = dPTFE00StockRadius1;

    G4double dPTFE00StockRadiusArray[] = { dPTFE00StockRadius1,
                                      dPTFE00StockRadius2,
                                      dPTFE00StockRadius3,
                                      dPTFE00StockRadius4,
                                      dPTFE00StockRadius5,
                                      dPTFE00StockRadius6};

    G4double  dPTFE00StockHeight1 = 15.00 * mm;
    G4double  dPTFE00StockHeight2 = dPTFE00StockHeight1;
    G4double  dPTFE00StockHeight3 = 10.00 * mm;
    G4double  dPTFE00StockHeight4 = dPTFE00StockHeight3;
    G4double  dPTFE00StockHeight5 = -dPTFE00StockHeight1;
    G4double  dPTFE00StockHeight6 = dPTFE00StockHeight5;

    G4double dPTFE00StockHeightArray[] = { dPTFE00StockHeight1,
                                      dPTFE00StockHeight2,
                                      dPTFE00StockHeight3,
                                      dPTFE00StockHeight4,
                                      dPTFE00StockHeight5,
                                      dPTFE00StockHeight6};

    // Set Subtraction solid variables
    G4double dPTFE00StockWingInnerRadius = 46.0 * mm;
    G4double dPTFE00StockWingOuterRadius = dPTFE00StockWingInnerRadius + 20.0 * mm;
    G4double dPTFE00StockWingHeight = 2 * dPTFE00StockHeight1;
    G4double dPTFE00StockWingStartAngle = 12.45 * deg;

    G4double dPTFE00StockWingX = 0.00 * mm;
    G4double dPTFE00StockWingY = 0.00 * mm;
    G4double dPTFE00StockWingZ = 0.00 * mm;

    G4ThreeVector dPTFE00StockWingXYZ(dPTFE00StockWingX, dPTFE00StockWingY, dPTFE00StockWingZ);

    G4RotationMatrix dPTFE00StockWingRot1;
    dPTFE00StockWingRot1.rotateZ(0.00);
    G4Transform3D dPTFE00StockWingTransform1(dPTFE00StockWingRot1, dPTFE00StockWingXYZ);

    G4RotationMatrix dPTFE00StockWingRot2;
    dPTFE00StockWingRot2.rotateZ(120.0 * deg);
    G4Transform3D dPTFE00StockWingTransform2(dPTFE00StockWingRot2, dPTFE00StockWingXYZ);

    G4RotationMatrix dPTFE00StockWingRot3;
    dPTFE00StockWingRot3.rotateZ(240.0 * deg);
    G4Transform3D dPTFE00StockWingTransform3(dPTFE00StockWingRot3, dPTFE00StockWingXYZ);

    // Set PTFE00Stock placement values
    G4double dPTFE00StockPlacementX = 0.000 * mm;
    G4double dPTFE00StockPlacementY = 0.000 * mm;
    G4double dPTFE00StockPlacementZ = 0.000 * mm;
    G4ThreeVector dPTFE00StockPlacement(dPTFE00StockPlacementX, dPTFE00StockPlacementY, dPTFE00StockPlacementZ);

    // Create subtraction solids
    G4Tubs* pPTFE00StockWingS = new G4Tubs("pPTFE00StockWingS", dPTFE00StockWingInnerRadius, dPTFE00StockWingOuterRadius, dPTFE00StockWingHeight, 0.5 * dPTFE00StockWingStartAngle, -dPTFE00StockWingStartAngle + 120.0 * deg);

	G4GenericPolycone* pPTFE00Stock = new G4GenericPolycone("PTFE00Stock", 0, 2 * M_PI, 6, dPTFE00StockRadiusArray, dPTFE00StockHeightArray);

	G4SubtractionSolid* pPTFE00StockWingSub1 = new G4SubtractionSolid("pPTFE00StockWingSub1", pPTFE00Stock, pPTFE00StockWingS, dPTFE00StockWingTransform1);
	G4SubtractionSolid* pPTFE00StockWingSub2 = new G4SubtractionSolid("pPTFE00StockWingSub2", pPTFE00StockWingSub1, pPTFE00StockWingS, dPTFE00StockWingTransform2);
	G4SubtractionSolid* pPTFE00StockWing = new G4SubtractionSolid("pPTFE00StockWing", pPTFE00StockWingSub2, pPTFE00StockWingS, dPTFE00StockWingTransform3);


    // Create PTFE00
    pPTFE00LV = new G4LogicalVolume(pPTFE00StockWing, G4Material::GetMaterial("PTFE"), "PTFE00");
//    pPTFE00PV = new G4PVPlacement(0, dPTFE00StockPlacement, pPTFE00LV, "PTFE00", pMotherLV, false, 0);


    //////////////////////
    // Construct PTFE01 //
    //////////////////////

    // Set PTFE01 Variables
    G4double   dPTFE01StockRadius1 = 32.00 * mm;
    G4double   dPTFE01StockRadius2 = 35.00 * mm;
    G4double   dPTFE01StockRadius3 = dPTFE01StockRadius2;
    G4double   dPTFE01StockRadius4 = 43.00 * mm;
    G4double   dPTFE01StockRadius5 = dPTFE01StockRadius4;
    G4double   dPTFE01StockRadius6 = dPTFE00StockRadius2;
    G4double   dPTFE01StockRadius7 = dPTFE00StockRadius2;
    G4double   dPTFE01StockRadius8 = dPTFE01StockRadius4;
    G4double   dPTFE01StockRadius9 = dPTFE01StockRadius4;
    G4double  dPTFE01StockRadius10 = dPTFE01StockRadius2;
    G4double  dPTFE01StockRadius11 = dPTFE01StockRadius2;
    G4double  dPTFE01StockRadius12 = dPTFE01StockRadius1;


    G4double dPTFE01StockRadiusArray[] = { dPTFE01StockRadius1,
                                      dPTFE01StockRadius2,
                                      dPTFE01StockRadius3,
                                      dPTFE01StockRadius4,
                                      dPTFE01StockRadius5,
                                      dPTFE01StockRadius6,
                                      dPTFE01StockRadius7,
                                      dPTFE01StockRadius8,
                                      dPTFE01StockRadius9,
                                      dPTFE01StockRadius10,
                                      dPTFE01StockRadius11,
                                      dPTFE01StockRadius12};

    G4double   dPTFE01StockHeight1 = 26.525 * mm;
    G4double   dPTFE01StockHeight2 = dPTFE01StockHeight1;
    G4double   dPTFE01StockHeight3 = 25.125 * mm;
    G4double   dPTFE01StockHeight4 = dPTFE01StockHeight3;
    G4double   dPTFE01StockHeight5 = 26.625 * mm;
    G4double   dPTFE01StockHeight6 = dPTFE01StockHeight5;
    G4double   dPTFE01StockHeight7 = -dPTFE01StockHeight5;
    G4double   dPTFE01StockHeight8 = -dPTFE01StockHeight5;
    G4double   dPTFE01StockHeight9 = 22.875 * mm;
    G4double  dPTFE01StockHeight10 = dPTFE01StockHeight9;
    G4double  dPTFE01StockHeight11 = 21.475 * mm;
    G4double  dPTFE01StockHeight12 = dPTFE01StockHeight11;

    G4double dPTFE01StockHeightArray[] = { dPTFE01StockHeight1,
                                      dPTFE01StockHeight2,
                                      dPTFE01StockHeight3,
                                      dPTFE01StockHeight4,
                                      dPTFE01StockHeight5,
                                      dPTFE01StockHeight6,
                                      dPTFE01StockHeight7,
                                      dPTFE01StockHeight8,
                                      dPTFE01StockHeight9,
                                      dPTFE01StockHeight10,
                                      dPTFE01StockHeight11,
                                      dPTFE01StockHeight12};

    //Set Subtraction Solid Variables
    G4double dPTFE01StockBox1Length = 2 * 12.075 * mm;
    G4double dPTFE01StockBox1Width = 3.00 * mm;
    G4double dPTFE01StockBox1Height = 2 * 1.5 * mm;

    G4double dPTFE01StockXenonVentTubInnerRadius = dPTFE01StockRadius4 - 0.1 * mm;
    G4double dPTFE01StockXenonVentTubOuterRadius = dPTFE01StockRadius4 + 20.00 * mm;
    G4double dPTFE01StockXenonVentTubHeight = 46.00 * mm;

    G4double dPTFE01StockCylinder1InnerRadius = 0.00 * mm;
    G4double dPTFE01StockCylinder1OuterRadius = 4.00 * mm;
    G4double dPTFE01StockCylinder1Height = 3.00 * mm;

    G4double dPTFE01StockWing1InnerRadius = 46.0 * mm;
    G4double dPTFE01StockWing1OuterRadius = dPTFE01StockWing1InnerRadius + 20.0 * mm;
    G4double dPTFE01StockWing1Height = 2 * dPTFE01StockHeight5;
    G4double dPTFE01StockWing1StartAngle = 32.255 * deg;

    G4double dPTFE01StockWing2InnerRadius = 46.0 * mm;
    G4double dPTFE01StockWing2OuterRadius = dPTFE01StockWing2InnerRadius + 20.0 * mm;
    G4double dPTFE01StockWing2Height = 2 * dPTFE01StockHeight5 - 5 * mm;
    G4double dPTFE01StockWing2StartAngle = 12.45 * deg;

    G4double dPTFE01StockBox1R = dPTFE01StockRadius2;
    G4double dPTFE01StockBox1X = dPTFE01StockBox1R * (cos(10.5 * deg) * mm);
    G4double dPTFE01StockBox1Y = dPTFE01StockBox1R * (sin(10.5 * deg) * mm);
    G4double dPTFE01StockBox1Z = dPTFE01StockHeight5;

    G4double dPTFE01StockXenonVentTubX = 0.00 * mm;
    G4double dPTFE01StockXenonVentTubY = 0.00 * mm;
    G4double dPTFE01StockXenonVentTubZ = 2.25 * mm + dPTFE01StockXenonVentTubHeight/2 + dPTFE01StockHeight7;

    G4double dPTFE01StockCylinder1R = 47.75 * mm;
    G4double dPTFE01StockCylinder1X = dPTFE01StockCylinder1R * (cos(10.5 * deg) * mm);
    G4double dPTFE01StockCylinder1Y = dPTFE01StockCylinder1R * (sin(10.5 * deg) * mm);
    G4double dPTFE01StockCylinder1Z = dPTFE01StockHeight1;

    G4double dPTFE01StockWing1X = 0.00 * mm;
    G4double dPTFE01StockWing1Y = 0.00 * mm;
    G4double dPTFE01StockWing1Z = 0.00 * mm;

    G4double dPTFE01StockWing2X = 0.00 * mm;
    G4double dPTFE01StockWing2Y = 0.00 * mm;
    G4double dPTFE01StockWing2Z = dPTFE01StockHeight7;

    G4RotationMatrix dPTFE01StockCylinder1Rot;
    dPTFE01StockCylinder1Rot.rotateZ(0.00);

    G4ThreeVector dPTFE01StockWing1XYZ(dPTFE01StockWing1X,dPTFE01StockWing1Y,dPTFE01StockWing1Z);

    G4ThreeVector dPTFE01StockWing2XYZ(dPTFE01StockWing2X,dPTFE01StockWing2Y,dPTFE01StockWing2Z);

    G4ThreeVector dPTFE01StockXenonVentTubXYZ1(dPTFE01StockXenonVentTubX,dPTFE01StockXenonVentTubY,dPTFE01StockXenonVentTubZ);
    G4RotationMatrix dPTFE01StockXenonVentTubRot1;
    dPTFE01StockXenonVentTubRot1.rotateZ(2 * M_PI/3 + M_PI/6);
    G4Transform3D dPTFE01StockXenonVentTubTransform1(dPTFE01StockXenonVentTubRot1, dPTFE01StockXenonVentTubXYZ1);

    G4ThreeVector dPTFE01StockXenonVentTubXYZ2(dPTFE01StockXenonVentTubX,dPTFE01StockXenonVentTubY,dPTFE01StockXenonVentTubZ);
    G4RotationMatrix dPTFE01StockXenonVentTubRot2;
    dPTFE01StockXenonVentTubRot2.rotateZ(M_PI/6);
    G4Transform3D dPTFE01StockXenonVentTubTransform2(dPTFE01StockXenonVentTubRot2, dPTFE01StockXenonVentTubXYZ2);

    G4ThreeVector dPTFE01StockXenonVentTubXYZ3(dPTFE01StockXenonVentTubX,dPTFE01StockXenonVentTubY,dPTFE01StockXenonVentTubZ);
    G4RotationMatrix dPTFE01StockXenonVentTubRot3;
    dPTFE01StockXenonVentTubRot3.rotateZ(4 * M_PI/3 + M_PI/6);
    G4Transform3D dPTFE01StockXenonVentTubTransform3(dPTFE01StockXenonVentTubRot3, dPTFE01StockXenonVentTubXYZ3);

    G4ThreeVector dPTFE01StockBox1XYZ(dPTFE01StockBox1X, dPTFE01StockBox1Y, dPTFE01StockBox1Z);
    G4RotationMatrix dPTFE01StockBox1Rot;
    dPTFE01StockBox1Rot.rotateZ(10.5 * deg);
    G4Transform3D dPTFE01StockBox1Transform(dPTFE01StockBox1Rot, dPTFE01StockBox1XYZ);

    G4ThreeVector dPTFE01StockCylinder1XYZ(dPTFE01StockCylinder1X,dPTFE01StockCylinder1Y,dPTFE01StockCylinder1Z);
    G4Transform3D dPTFE01StockCylinder1Transform(dPTFE01StockCylinder1Rot,dPTFE01StockCylinder1XYZ);

    G4RotationMatrix dPTFE01StockWing1Rot1;
    dPTFE01StockWing1Rot1.rotateZ(0.00);
    G4Transform3D dPTFE01StockWing1Transform1(dPTFE01StockWing1Rot1,dPTFE01StockWing1XYZ);

    G4RotationMatrix dPTFE01StockWing1Rot2;
    dPTFE01StockWing1Rot2.rotateZ(120 * deg);
    G4Transform3D dPTFE01StockWing1Transform2(dPTFE01StockWing1Rot2,dPTFE01StockWing1XYZ);

    G4RotationMatrix dPTFE01StockWing1Rot3;
    dPTFE01StockWing1Rot3.rotateZ(240 * deg);
    G4Transform3D dPTFE01StockWing1Transform3(dPTFE01StockWing1Rot3,dPTFE01StockWing1XYZ);

    G4RotationMatrix dPTFE01StockWing2Rot1;
    dPTFE01StockWing2Rot1.rotateZ(0.00);
    G4Transform3D dPTFE01StockWing2Transform1(dPTFE01StockWing2Rot1,dPTFE01StockWing2XYZ);

    G4RotationMatrix dPTFE01StockWing2Rot2;
    dPTFE01StockWing2Rot2.rotateZ(120 * deg);
    G4Transform3D dPTFE01StockWing2Transform2(dPTFE01StockWing2Rot2,dPTFE01StockWing2XYZ);

    G4RotationMatrix dPTFE01StockWing2Rot3;
    dPTFE01StockWing2Rot3.rotateZ(240 * deg);
    G4Transform3D dPTFE01StockWing2Transform3(dPTFE01StockWing2Rot3,dPTFE01StockWing2XYZ);

    // Set PTFE01 placement values
    G4double dPTFE01StockPlacementX = 0.00 * mm;
    G4double dPTFE01StockPlacementY = 0.00 * mm;
    G4double dPTFE01StockPlacementZ = dPTFE01StockHeight5 + dPTFE00StockHeight1;
    G4ThreeVector dPTFE01StockPlacement(dPTFE01StockPlacementX, dPTFE01StockPlacementY, dPTFE01StockPlacementZ);

    // Create Subtraction Solids
    G4Box* pPTFE01StockBox1S = new G4Box("pPTFE01StockBox1S", 0.5 * dPTFE01StockBox1Length, 0.5 * dPTFE01StockBox1Width, 0.5 * dPTFE01StockBox1Height);
    G4Tubs* pPTFE01StockXenonVentTub = new G4Tubs("pPTFE01StockXenonVentTub", dPTFE01StockXenonVentTubInnerRadius, dPTFE01StockXenonVentTubOuterRadius, 0.5 * dPTFE01StockXenonVentTubHeight, 0, M_PI/3);
    G4Tubs* pPTFE01StockCylinder1Tub = new G4Tubs("pPTFE01StockCylinder1Tub", dPTFE01StockCylinder1InnerRadius, dPTFE01StockCylinder1OuterRadius, 0.5 * dPTFE01StockCylinder1Height, 0, 2 * M_PI);
    G4Tubs* pPTFE01StockWing1S = new G4Tubs("pPTFE01StockWing1S", dPTFE01StockWing1InnerRadius, dPTFE01StockWing1OuterRadius, dPTFE01StockWing1Height, 0.5 * dPTFE01StockWing1StartAngle, -dPTFE01StockWing1StartAngle + 120 * deg);
    G4Tubs* pPTFE01StockWing2S = new G4Tubs("pPTFE01StockWing2S", dPTFE01StockWing2InnerRadius, dPTFE01StockWing2OuterRadius, dPTFE01StockWing2Height, 0.5 * dPTFE01StockWing2StartAngle, -dPTFE01StockWing2StartAngle + 120 * deg);

    G4GenericPolycone* pPTFE01Stock = new G4GenericPolycone("PTFE01Stock", 0, 2 * M_PI, 12, dPTFE01StockRadiusArray, dPTFE01StockHeightArray);

    G4SubtractionSolid* pPTFE01StockBox1 = new G4SubtractionSolid("pPTFE01StockBox1", pPTFE01Stock, pPTFE01StockBox1S, dPTFE01StockBox1Transform);

    G4SubtractionSolid* pPTFE01StockXenonVentTubSub1 = new G4SubtractionSolid("pPTFE01StockXenonVentTubSub1", pPTFE01StockBox1, pPTFE01StockXenonVentTub, dPTFE01StockXenonVentTubTransform1);
    G4SubtractionSolid* pPTFE01StockXenonVentTubSub2 = new G4SubtractionSolid("pPTFE01StockXenonVentTubSub2", pPTFE01StockXenonVentTubSub1, pPTFE01StockXenonVentTub, dPTFE01StockXenonVentTubTransform2);
    G4SubtractionSolid* pPTFE01StockXenonVent = new G4SubtractionSolid("pPTFE01StockXenonVentTub", pPTFE01StockXenonVentTubSub2, pPTFE01StockXenonVentTub, dPTFE01StockXenonVentTubTransform3);

    G4SubtractionSolid* pPTFE01StockCylinder1 = new G4SubtractionSolid("pPTFE01StockCylinder1", pPTFE01StockXenonVent, pPTFE01StockCylinder1Tub, dPTFE01StockCylinder1Transform);

    G4SubtractionSolid* pPTFE01StockWing1Sub1 = new G4SubtractionSolid("pPTFE01StockWing1Sub1", pPTFE01StockCylinder1, pPTFE01StockWing1S, dPTFE01StockWing1Transform1);
    G4SubtractionSolid* pPTFE01StockWing1Sub2 = new G4SubtractionSolid("pPTFE01StockWing1Sub2", pPTFE01StockWing1Sub1, pPTFE01StockWing1S, dPTFE01StockWing1Transform2);
    G4SubtractionSolid* pPTFE01StockWing1 = new G4SubtractionSolid("pPTFE01StockWing1", pPTFE01StockWing1Sub2, pPTFE01StockWing1S, dPTFE01StockWing1Transform3);

    G4SubtractionSolid* pPTFE01StockWing2Sub1 = new G4SubtractionSolid("pPTFE01StockWing2Sub1", pPTFE01StockWing1, pPTFE01StockWing2S, dPTFE01StockWing2Transform1);
    G4SubtractionSolid* pPTFE01StockWing2Sub2 = new G4SubtractionSolid("pPTFE01StockWing2Sub2", pPTFE01StockWing2Sub1, pPTFE01StockWing2S, dPTFE01StockWing2Transform2);
    G4SubtractionSolid* pPTFE01StockWing2 = new G4SubtractionSolid("pPTFE01StockWing2", pPTFE01StockWing2Sub2, pPTFE01StockWing2S, dPTFE01StockWing2Transform3);

    // Create PTFE01
    pPTFE01LV = new G4LogicalVolume(pPTFE01StockWing2, G4Material::GetMaterial("PTFE"), "PTFE01");
//    pPTFE01PV = new G4PVPlacement(0, dPTFE01StockPlacement, pPTFE01LV, "PTFE01", pMotherLV, false, 0);

    //////////////////////
    // Construct PTFE02 //
    //////////////////////

    // Set PTFE02Stock Variables
    G4double  dPTFE02StockRadius1 = dPTFE01StockRadius1;
    G4double  dPTFE02StockRadius2 = dPTFE01StockRadius2;
    G4double  dPTFE02StockRadius3 = dPTFE01StockRadius2;
    G4double  dPTFE02StockRadius4 = dPTFE01StockRadius4;
    G4double  dPTFE02StockRadius5 = dPTFE01StockRadius4;
    G4double  dPTFE02StockRadius6 = dPTFE00StockRadius2;
    G4double  dPTFE02StockRadius7 = dPTFE00StockRadius2;
    G4double  dPTFE02StockRadius8 = 36.000 * mm;
    G4double  dPTFE02StockRadius9 = dPTFE02StockRadius8;
    G4double dPTFE02StockRadius10 = dPTFE01StockRadius2;
    G4double dPTFE02StockRadius11 = dPTFE01StockRadius2;
    G4double dPTFE02StockRadius12 = dPTFE02StockRadius8;
    G4double dPTFE02StockRadius13 = dPTFE02StockRadius8;
    G4double dPTFE02StockRadius14 = dPTFE00StockRadius2;
    G4double dPTFE02StockRadius15 = dPTFE00StockRadius2;
    G4double dPTFE02StockRadius16 = dPTFE01StockRadius4;
    G4double dPTFE02StockRadius17 = dPTFE01StockRadius4;
    G4double dPTFE02StockRadius18 = dPTFE01StockRadius2;
    G4double dPTFE02StockRadius19 = dPTFE01StockRadius2;
    G4double dPTFE02StockRadius20 = dPTFE02StockRadius1;

    G4double dPTFE02StockRadiusArray[] = { dPTFE02StockRadius1,
                                      dPTFE02StockRadius2,
                                      dPTFE02StockRadius3,
                                      dPTFE02StockRadius4,
                                      dPTFE02StockRadius5,
                                      dPTFE02StockRadius6,
                                      dPTFE02StockRadius7,
                                      dPTFE02StockRadius8,
                                      dPTFE02StockRadius9,
                                      dPTFE02StockRadius10,
                                      dPTFE02StockRadius11,
                                      dPTFE02StockRadius12,
                                      dPTFE02StockRadius13,
                                      dPTFE02StockRadius14,
                                      dPTFE02StockRadius15,
                                      dPTFE02StockRadius16,
                                      dPTFE02StockRadius17,
                                      dPTFE02StockRadius18,
                                      dPTFE02StockRadius19,
                                      dPTFE02StockRadius20};

    G4double  dPTFE02StockHeight1 = 19.85 * mm;
    G4double  dPTFE02StockHeight2 = dPTFE02StockHeight1;
    G4double  dPTFE02StockHeight3 = 18.45 * mm;
    G4double  dPTFE02StockHeight4 = dPTFE02StockHeight3;
    G4double  dPTFE02StockHeight5 = 19.95 * mm;
    G4double  dPTFE02StockHeight6 = dPTFE02StockHeight5;
    G4double  dPTFE02StockHeight7 = 14.45 * mm;
    G4double  dPTFE02StockHeight8 = dPTFE02StockHeight7;
    G4double  dPTFE02StockHeight9 = 15.45 * mm;
    G4double dPTFE02StockHeight10 = dPTFE02StockHeight9;
    G4double dPTFE02StockHeight11 = -15.55 * mm;
    G4double dPTFE02StockHeight12 = dPTFE02StockHeight11;
    G4double dPTFE02StockHeight13 = -14.55 * mm;
    G4double dPTFE02StockHeight14 = dPTFE02StockHeight13;
    G4double dPTFE02StockHeight15 = -dPTFE02StockHeight5;
    G4double dPTFE02StockHeight16 = -dPTFE02StockHeight5;
    G4double dPTFE02StockHeight17 = -dPTFE02StockHeight3;
    G4double dPTFE02StockHeight18 = -dPTFE02StockHeight3;
    G4double dPTFE02StockHeight19 = -dPTFE02StockHeight1;
    G4double dPTFE02StockHeight20 = -dPTFE02StockHeight1;

    G4double dPTFE02StockHeightArray[] = { dPTFE02StockHeight1,
                                      dPTFE02StockHeight2,
                                      dPTFE02StockHeight3,
                                      dPTFE02StockHeight4,
                                      dPTFE02StockHeight5,
                                      dPTFE02StockHeight6,
                                      dPTFE02StockHeight7,
                                      dPTFE02StockHeight8,
                                      dPTFE02StockHeight9,
                                     dPTFE02StockHeight10,
                                     dPTFE02StockHeight11,
                                     dPTFE02StockHeight12,
                                     dPTFE02StockHeight13,
                                     dPTFE02StockHeight14,
                                     dPTFE02StockHeight15,
                                     dPTFE02StockHeight16,
                                     dPTFE02StockHeight17,
                                     dPTFE02StockHeight18,
                                     dPTFE02StockHeight19,
                                     dPTFE02StockHeight20};

    // Set Subtraction Solids Variables
    G4double dPTFE02StockBox1Length = 3.175 * mm;
    G4double dPTFE02StockBox1Width = 3.971 * mm;
    G4double dPTFE02StockBox1Height = 2 * 1.587 * mm;

    G4double dPTFE02StockBox2Length = 2 * 12.075 * mm;
    G4double dPTFE02StockBox2Width = 3.00 * mm;
    G4double dPTFE02StockBox2Height = 2 * 1.5 * mm;

    G4double dPTFE02StockCylinder1InnerRadius = 0.0 * mm; // Large one on top
    G4double dPTFE02StockCylinder1OuterRadius = 3.0 * mm;
    G4double dPTFE02StockCylinder1Height = 4.0 * mm;

    G4double dPTFE02StockCylinder2InnerRadius = 0.0 * mm; // Smaller one on top
    G4double dPTFE02StockCylinder2OuterRadius = 1.5875 * mm;
    G4double dPTFE02StockCylinder2Height = 8 * mm; // Has to go through

    G4double dPTFE02StockCylinder3InnerRadius = 0.0 * mm; // Large one on bottom
    G4double dPTFE02StockCylinder3OuterRadius = 3.0 * mm;
    G4double dPTFE02StockCylinder3Height = 4.0 * mm;

    G4double dPTFE02StockCylinder4InnerRadius = 0.0 * mm; // Larger one on top wing
    G4double dPTFE02StockCylinder4OuterRadius = 4.0 * mm;
    G4double dPTFE02StockCylinder4Height = 12.0 * mm; // Has to go through

    G4double dPTFE02StockWingInnerRadius = 46.0 * mm;
    G4double dPTFE02StockWingOuterRadius = dPTFE02StockWingInnerRadius + 20.0 * mm;
    G4double dPTFE02StockWingHeight = 2 * dPTFE02StockHeight5;
    G4double dPTFE02StockWingStartAngle = 32.255 * deg;

    G4double dPTFE02StockBox1R = 39.00 * mm + 0.5 * dPTFE02StockBox1Length;
    G4double dPTFE02StockBox1X1 = dPTFE02StockBox1R * (cos(39 * deg) * mm);
    G4double dPTFE02StockBox1X2 = dPTFE02StockBox1R * (cos(21 * deg) * mm);
    G4double dPTFE02StockBox1X3 = dPTFE02StockBox1R * (cos(81 * deg) * mm);
    G4double dPTFE02StockBox1X4 = -dPTFE02StockBox1X1;
    G4double dPTFE02StockBox1X5 = -dPTFE02StockBox1X2;
    G4double dPTFE02StockBox1X6 = -dPTFE02StockBox1X3;
    G4double dPTFE02StockBox1Y1 = dPTFE02StockBox1R * (sin(39 * deg) * mm);
    G4double dPTFE02StockBox1Y2 = -dPTFE02StockBox1R * (sin(21 * deg) * mm);
    G4double dPTFE02StockBox1Y3 = -dPTFE02StockBox1R * (sin(81 * deg) * mm);
    G4double dPTFE02StockBox1Y4 = -dPTFE02StockBox1Y1;
    G4double dPTFE02StockBox1Y5 = -dPTFE02StockBox1Y2;
    G4double dPTFE02StockBox1Y6 = -dPTFE02StockBox1Y3;

    G4double dPTFE02StockBox2R = dPTFE01StockRadius2;
    G4double dPTFE02StockBox2X = dPTFE02StockBox2R * (cos(10.5 * deg) * mm);
    G4double dPTFE02StockBox2Y = dPTFE02StockBox2R * (sin(10.5 * deg) * mm);
    G4double dPTFE02StockBox2Z = dPTFE02StockHeight15;

    G4double dPTFE02StockCylinder1R = 39.00 * mm;
    G4double dPTFE02StockCylinder1X1 = dPTFE02StockCylinder1R * (cos(69 * deg) * mm);
    G4double dPTFE02StockCylinder1X2 = dPTFE02StockCylinder1R * (cos(9 * deg) * mm);
    G4double dPTFE02StockCylinder1X3 = dPTFE02StockCylinder1R * (cos(51 * deg) * mm);
    G4double dPTFE02StockCylinder1X4 = -dPTFE02StockCylinder1X1;
    G4double dPTFE02StockCylinder1X5 = -dPTFE02StockCylinder1X2;
    G4double dPTFE02StockCylinder1X6 = -dPTFE02StockCylinder1X3;
    G4double dPTFE02StockCylinder1Y1 = dPTFE02StockCylinder1R * (sin(69 * deg) * mm);
    G4double dPTFE02StockCylinder1Y2 = dPTFE02StockCylinder1R * (sin(9 * deg) * mm);
    G4double dPTFE02StockCylinder1Y3 = -dPTFE02StockCylinder1R * (sin(51 * deg) * mm);
    G4double dPTFE02StockCylinder1Y4 = -dPTFE02StockCylinder1Y1;
    G4double dPTFE02StockCylinder1Y5 = -dPTFE02StockCylinder1Y2;
    G4double dPTFE02StockCylinder1Y6 = -dPTFE02StockCylinder1Y3;

    G4double dPTFE02StockCylinder2R = 39.00 * mm;
    G4double dPTFE02StockCylinder2X1 = dPTFE02StockCylinder2R * (cos(39 * deg) * mm);
    G4double dPTFE02StockCylinder2X2 = dPTFE02StockCylinder2R * (cos(21 * deg) * mm);
    G4double dPTFE02StockCylinder2X3 = dPTFE02StockCylinder2R * (cos(81 * deg) * mm);
    G4double dPTFE02StockCylinder2X4 = -dPTFE02StockCylinder2X1;
    G4double dPTFE02StockCylinder2X5 = -dPTFE02StockCylinder2X2;
    G4double dPTFE02StockCylinder2X6 = -dPTFE02StockCylinder2X3;
    G4double dPTFE02StockCylinder2Y1 = dPTFE02StockCylinder2R * (sin(39 * deg) * mm);
    G4double dPTFE02StockCylinder2Y2 = -dPTFE02StockCylinder2R * (sin(21 * deg) * mm);
    G4double dPTFE02StockCylinder2Y3 = -dPTFE02StockCylinder2R * (sin(81 * deg) * mm);
    G4double dPTFE02StockCylinder2Y4 = -dPTFE02StockCylinder2Y1;
    G4double dPTFE02StockCylinder2Y5 = -dPTFE02StockCylinder2Y2;
    G4double dPTFE02StockCylinder2Y6 = -dPTFE02StockCylinder2Y3;

    G4double dPTFE02StockCylinder3R = 39.00 * mm;
    G4double dPTFE02StockCylinder3X1 = dPTFE02StockCylinder3R * (cos(51 * deg) * mm);
    G4double dPTFE02StockCylinder3X2 = dPTFE02StockCylinder3R * (cos(9 * deg) * mm);
    G4double dPTFE02StockCylinder3X3 = dPTFE02StockCylinder3R * (cos(69 * deg) * mm);
    G4double dPTFE02StockCylinder3X4 = -dPTFE02StockCylinder3X1;
    G4double dPTFE02StockCylinder3X5 = -dPTFE02StockCylinder3X2;
    G4double dPTFE02StockCylinder3X6 = -dPTFE02StockCylinder3X3;
    G4double dPTFE02StockCylinder3Y1 = dPTFE02StockCylinder3R * (sin(51 * deg) * mm);
    G4double dPTFE02StockCylinder3Y2 = -dPTFE02StockCylinder3R * (sin(9 * deg) * mm);
    G4double dPTFE02StockCylinder3Y3 = -dPTFE02StockCylinder3R * (sin(69 * deg) * mm);
    G4double dPTFE02StockCylinder3Y4 = -dPTFE02StockCylinder3Y1;
    G4double dPTFE02StockCylinder3Y5 = -dPTFE02StockCylinder3Y2;
    G4double dPTFE02StockCylinder3Y6 = -dPTFE02StockCylinder3Y3;

    G4double dPTFE02StockCylinder4R1 = 47.75 * mm;
    G4double dPTFE02StockCylinder4X1 = dPTFE02StockCylinder4R1 * (cos(10.5 * deg) * mm);
    G4double dPTFE02StockCylinder4Y1 = dPTFE02StockCylinder4R1 * (sin(10.5 * deg) * mm);

    G4double dPTFE02StockCylinder4R2 = 47.75 * mm;
    G4double dPTFE02StockCylinder4X2 = dPTFE02StockCylinder4R2 * (cos(10.5 * deg) * mm);
    G4double dPTFE02StockCylinder4Y2 = dPTFE02StockCylinder4R2 * (sin(10.5 * deg) * mm);

    G4double dPTFE02StockCylinder1Z = dPTFE02StockHeight3;
    G4double dPTFE02StockCylinder2Z = dPTFE02StockHeight3;
    G4double dPTFE02StockCylinder3Z = dPTFE02StockHeight17;
    G4double dPTFE02StockCylinder4Z1 = dPTFE02StockHeight5;
    G4double dPTFE02StockCylinder4Z2 = dPTFE02StockHeight13;
    G4double dPTFE02StockBox1Z = dPTFE02StockHeight3;

    G4double dPTFE02StockWingX = 0.00 * mm;
    G4double dPTFE02StockWingY = 0.00 * mm;
    G4double dPTFE02StockWingZ = 0.00 * mm;

	G4ThreeVector dPTFE02StockWingXYZ(dPTFE02StockWingX, dPTFE02StockWingY, dPTFE02StockWingZ);

    G4RotationMatrix dPTFE02StockCylinderRot;
    dPTFE02StockCylinderRot.rotateZ(0.00);

    G4ThreeVector dPTFE02StockCylinder1XYZ1(dPTFE02StockCylinder1X1,dPTFE02StockCylinder1Y1,dPTFE02StockCylinder1Z);
    G4Transform3D dPTFE02StockCylinder1Transform1(dPTFE02StockCylinderRot, dPTFE02StockCylinder1XYZ1);

    G4ThreeVector dPTFE02StockCylinder1XYZ2(dPTFE02StockCylinder1X2,dPTFE02StockCylinder1Y2,dPTFE02StockCylinder1Z);
    G4Transform3D dPTFE02StockCylinder1Transform2(dPTFE02StockCylinderRot, dPTFE02StockCylinder1XYZ2);

    G4ThreeVector dPTFE02StockCylinder1XYZ3(dPTFE02StockCylinder1X3,dPTFE02StockCylinder1Y3,dPTFE02StockCylinder1Z);
    G4Transform3D dPTFE02StockCylinder1Transform3(dPTFE02StockCylinderRot, dPTFE02StockCylinder1XYZ3);

    G4ThreeVector dPTFE02StockCylinder1XYZ4(dPTFE02StockCylinder1X4,dPTFE02StockCylinder1Y4,dPTFE02StockCylinder1Z);
    G4Transform3D dPTFE02StockCylinder1Transform4(dPTFE02StockCylinderRot, dPTFE02StockCylinder1XYZ4);

    G4ThreeVector dPTFE02StockCylinder1XYZ5(dPTFE02StockCylinder1X5,dPTFE02StockCylinder1Y5,dPTFE02StockCylinder1Z);
    G4Transform3D dPTFE02StockCylinder1Transform5(dPTFE02StockCylinderRot, dPTFE02StockCylinder1XYZ5);

    G4ThreeVector dPTFE02StockCylinder1XYZ6(dPTFE02StockCylinder1X6,dPTFE02StockCylinder1Y6,dPTFE02StockCylinder1Z);
    G4Transform3D dPTFE02StockCylinder1Transform6(dPTFE02StockCylinderRot, dPTFE02StockCylinder1XYZ6);

    G4ThreeVector dPTFE02StockCylinder2XYZ1(dPTFE02StockCylinder2X1,dPTFE02StockCylinder2Y1,dPTFE02StockCylinder2Z);
    G4Transform3D dPTFE02StockCylinder2Transform1(dPTFE02StockCylinderRot, dPTFE02StockCylinder2XYZ1);

    G4ThreeVector dPTFE02StockCylinder2XYZ2(dPTFE02StockCylinder2X2,dPTFE02StockCylinder2Y2,dPTFE02StockCylinder2Z);
    G4Transform3D dPTFE02StockCylinder2Transform2(dPTFE02StockCylinderRot, dPTFE02StockCylinder2XYZ2);

    G4ThreeVector dPTFE02StockCylinder2XYZ3(dPTFE02StockCylinder2X3,dPTFE02StockCylinder2Y3,dPTFE02StockCylinder2Z);
    G4Transform3D dPTFE02StockCylinder2Transform3(dPTFE02StockCylinderRot, dPTFE02StockCylinder2XYZ3);

    G4ThreeVector dPTFE02StockCylinder2XYZ4(dPTFE02StockCylinder2X4,dPTFE02StockCylinder2Y4,dPTFE02StockCylinder2Z);
    G4Transform3D dPTFE02StockCylinder2Transform4(dPTFE02StockCylinderRot, dPTFE02StockCylinder2XYZ4);

    G4ThreeVector dPTFE02StockCylinder2XYZ5(dPTFE02StockCylinder2X5,dPTFE02StockCylinder2Y5,dPTFE02StockCylinder2Z);
    G4Transform3D dPTFE02StockCylinder2Transform5(dPTFE02StockCylinderRot, dPTFE02StockCylinder2XYZ5);

    G4ThreeVector dPTFE02StockCylinder2XYZ6(dPTFE02StockCylinder2X6,dPTFE02StockCylinder2Y6,dPTFE02StockCylinder2Z);
    G4Transform3D dPTFE02StockCylinder2Transform6(dPTFE02StockCylinderRot, dPTFE02StockCylinder2XYZ6);

    G4ThreeVector dPTFE02StockCylinder3XYZ1(dPTFE02StockCylinder3X1,dPTFE02StockCylinder3Y1,dPTFE02StockCylinder3Z);
    G4Transform3D dPTFE02StockCylinder3Transform1(dPTFE02StockCylinderRot, dPTFE02StockCylinder3XYZ1);

    G4ThreeVector dPTFE02StockCylinder3XYZ2(dPTFE02StockCylinder3X2,dPTFE02StockCylinder3Y2,dPTFE02StockCylinder3Z);
    G4Transform3D dPTFE02StockCylinder3Transform2(dPTFE02StockCylinderRot, dPTFE02StockCylinder3XYZ2);

    G4ThreeVector dPTFE02StockCylinder3XYZ3(dPTFE02StockCylinder3X3,dPTFE02StockCylinder3Y3,dPTFE02StockCylinder3Z);
    G4Transform3D dPTFE02StockCylinder3Transform3(dPTFE02StockCylinderRot, dPTFE02StockCylinder3XYZ3);

    G4ThreeVector dPTFE02StockCylinder3XYZ4(dPTFE02StockCylinder3X4,dPTFE02StockCylinder3Y4,dPTFE02StockCylinder3Z);
    G4Transform3D dPTFE02StockCylinder3Transform4(dPTFE02StockCylinderRot, dPTFE02StockCylinder3XYZ4);

    G4ThreeVector dPTFE02StockCylinder3XYZ5(dPTFE02StockCylinder3X5,dPTFE02StockCylinder3Y5,dPTFE02StockCylinder3Z);
    G4Transform3D dPTFE02StockCylinder3Transform5(dPTFE02StockCylinderRot, dPTFE02StockCylinder3XYZ5);

    G4ThreeVector dPTFE02StockCylinder3XYZ6(dPTFE02StockCylinder3X6,dPTFE02StockCylinder3Y6,dPTFE02StockCylinder3Z);
    G4Transform3D dPTFE02StockCylinder3Transform6(dPTFE02StockCylinderRot, dPTFE02StockCylinder3XYZ6);

    G4ThreeVector dPTFE02StockBox1XYZ1(dPTFE02StockBox1X1,dPTFE02StockBox1Y1,dPTFE02StockBox1Z);
    G4RotationMatrix dPTFE02StockBox1Rot1;
    dPTFE02StockBox1Rot1.rotateZ(-51 * deg);
    G4Transform3D dPTFE02StockBox1Transform1(dPTFE02StockBox1Rot1, dPTFE02StockBox1XYZ1);

    G4ThreeVector dPTFE02StockBox1XYZ2(dPTFE02StockBox1X2,dPTFE02StockBox1Y2,dPTFE02StockBox1Z);
    G4RotationMatrix dPTFE02StockBox1Rot2;
    dPTFE02StockBox1Rot2.rotateZ(-111 * deg);
    G4Transform3D dPTFE02StockBox1Transform2(dPTFE02StockBox1Rot2, dPTFE02StockBox1XYZ2);

    G4ThreeVector dPTFE02StockBox1XYZ3(dPTFE02StockBox1X3,dPTFE02StockBox1Y3,dPTFE02StockBox1Z);
    G4RotationMatrix dPTFE02StockBox1Rot3;
    dPTFE02StockBox1Rot3.rotateZ(-171 * deg);
    G4Transform3D dPTFE02StockBox1Transform3(dPTFE02StockBox1Rot3, dPTFE02StockBox1XYZ3);

    G4ThreeVector dPTFE02StockBox1XYZ4(dPTFE02StockBox1X4,dPTFE02StockBox1Y4,dPTFE02StockBox1Z);
    G4RotationMatrix dPTFE02StockBox1Rot4;
    dPTFE02StockBox1Rot4.rotateZ(-231 * deg);
    G4Transform3D dPTFE02StockBox1Transform4(dPTFE02StockBox1Rot4, dPTFE02StockBox1XYZ4);

    G4ThreeVector dPTFE02StockBox1XYZ5(dPTFE02StockBox1X5,dPTFE02StockBox1Y5,dPTFE02StockBox1Z);
    G4RotationMatrix dPTFE02StockBox1Rot5;
    dPTFE02StockBox1Rot5.rotateZ(-291 * deg);
    G4Transform3D dPTFE02StockBox1Transform5(dPTFE02StockBox1Rot5, dPTFE02StockBox1XYZ5);

    G4ThreeVector dPTFE02StockBox1XYZ6(dPTFE02StockBox1X6,dPTFE02StockBox1Y6,dPTFE02StockBox1Z);
    G4RotationMatrix dPTFE02StockBox1Rot6;
    dPTFE02StockBox1Rot6.rotateZ(9 * deg);
    G4Transform3D dPTFE02StockBox1Transform6(dPTFE02StockBox1Rot6, dPTFE02StockBox1XYZ6);

    G4ThreeVector dPTFE02StockBox2XYZ(dPTFE02StockBox2X, dPTFE02StockBox2Y, dPTFE02StockBox2Z);
    G4RotationMatrix dPTFE02StockBox2Rot;
    dPTFE02StockBox2Rot.rotateZ(10.5 * deg);
    G4Transform3D dPTFE02StockBox2Transform(dPTFE02StockBox2Rot, dPTFE02StockBox2XYZ);

    G4ThreeVector dPTFE02StockCylinder4XYZ1(dPTFE02StockCylinder4X1, dPTFE02StockCylinder4Y1,dPTFE02StockCylinder4Z1);
   	G4Transform3D dPTFE02StockCylinder4Transform1(dPTFE02StockCylinderRot, dPTFE02StockCylinder4XYZ1);

   	G4ThreeVector dPTFE02StockCylinder4XYZ2(dPTFE02StockCylinder4X2, dPTFE02StockCylinder4Y2, dPTFE02StockCylinder4Z2);
   	G4Transform3D dPTFE02StockCylinder4Transform2(dPTFE02StockCylinderRot, dPTFE02StockCylinder4XYZ2);

   	G4RotationMatrix dPTFE02StockWingRot1;
   	dPTFE02StockWingRot1.rotateZ(0.00);
   	G4Transform3D dPTFE02StockWingTransform1(dPTFE02StockWingRot1, dPTFE02StockWingXYZ);

   	G4RotationMatrix dPTFE02StockWingRot2;
   	dPTFE02StockWingRot2.rotateZ(120 * deg);
   	G4Transform3D dPTFE02StockWingTransform2(dPTFE02StockWingRot2, dPTFE02StockWingXYZ);

   	G4RotationMatrix dPTFE02StockWingRot3;
   	dPTFE02StockWingRot3.rotateZ(240 * deg);
   	G4Transform3D dPTFE02StockWingTransform3(dPTFE02StockWingRot3, dPTFE02StockWingXYZ);

    // Set PTFE02 Placement Values
    G4double dPTFE02StockPlacementX = 0.000 * mm;
    G4double dPTFE02StockPlacementY = 0.000 * mm;
    G4double dPTFE02StockPlacementZ = dPTFE01StockPlacementZ + dPTFE02StockHeight5 + dPTFE01StockHeight5;
    G4ThreeVector dPTFE02StockPlacement(dPTFE02StockPlacementX, dPTFE02StockPlacementY, dPTFE02StockPlacementZ);

    // Create Subtraction Solids
    G4Tubs* pPTFE02StockCylinder1S = new G4Tubs("pPTFE02StockCylinder1S", dPTFE02StockCylinder1InnerRadius, dPTFE02StockCylinder1OuterRadius, 0.5 * dPTFE02StockCylinder1Height, 0, 2 * M_PI);
    G4Tubs* pPTFE02StockCylinder2S = new G4Tubs("pPTFE02StockCylinder2S", dPTFE02StockCylinder2InnerRadius, dPTFE02StockCylinder2OuterRadius, 0.5 * dPTFE02StockCylinder2Height, 0, 2 * M_PI);
    G4Tubs* pPTFE02StockCylinder3S = new G4Tubs("pPTFE02StockCylinder3S", dPTFE02StockCylinder3InnerRadius, dPTFE02StockCylinder3OuterRadius, 0.5 * dPTFE02StockCylinder3Height, 0, 2 * M_PI);
    G4Box* pPTFE02StockBox1S = new G4Box("pPTFE02StockBox1S",0.5 * dPTFE02StockBox1Length,0.5 * dPTFE02StockBox1Width,0.5 * dPTFE02StockBox1Height);
    G4Box* pPTFE02StockBox2S = new G4Box("pPTFE02StockBox2S", 0.5 * dPTFE02StockBox2Length, 0.5 * dPTFE02StockBox2Width, 0.5 * dPTFE02StockBox2Height);
    G4Tubs* pPTFE02StockWingS = new G4Tubs("pPTFE02StockWingS", dPTFE02StockWingInnerRadius, dPTFE02StockWingOuterRadius, dPTFE02StockWingHeight, 0.5 * dPTFE02StockWingStartAngle, -dPTFE02StockWingStartAngle + 120 * deg);

    G4Tubs* pPTFE02StockCylinder4S = new G4Tubs("pPTFE02StockCylinder4S", dPTFE02StockCylinder4InnerRadius, dPTFE02StockCylinder4OuterRadius, 0.5 * dPTFE02StockCylinder4Height, 0, 2 * M_PI);

    G4GenericPolycone* pPTFE02Stock = new G4GenericPolycone("PTFE02Stock", 0, 2 * M_PI, 20, dPTFE02StockRadiusArray, dPTFE02StockHeightArray);

    G4SubtractionSolid* pPTFE02StockBox1Sub1 = new G4SubtractionSolid("pPTFE02StockBox1Sub1",pPTFE02Stock,pPTFE02StockBox1S,dPTFE02StockBox1Transform1);
    G4SubtractionSolid* pPTFE02StockBox1Sub2 = new G4SubtractionSolid("pPTFE02StockBox1Sub2",pPTFE02StockBox1Sub1,pPTFE02StockBox1S,dPTFE02StockBox1Transform2);
    G4SubtractionSolid* pPTFE02StockBox1Sub3 = new G4SubtractionSolid("pPTFE02StockBox1Sub3",pPTFE02StockBox1Sub2,pPTFE02StockBox1S,dPTFE02StockBox1Transform3);
    G4SubtractionSolid* pPTFE02StockBox1Sub4 = new G4SubtractionSolid("pPTFE02StockBox1Sub4",pPTFE02StockBox1Sub3,pPTFE02StockBox1S,dPTFE02StockBox1Transform4);
    G4SubtractionSolid* pPTFE02StockBox1Sub5 = new G4SubtractionSolid("pPTFE02StockBox1Sub5",pPTFE02StockBox1Sub4,pPTFE02StockBox1S,dPTFE02StockBox1Transform5);
    G4SubtractionSolid*     pPTFE02StockBox1 = new G4SubtractionSolid("pPTFE02StockBox1",pPTFE02StockBox1Sub5,pPTFE02StockBox1S,dPTFE02StockBox1Transform6);


    G4SubtractionSolid* pPTFE02StockCylinder1Sub1 = new G4SubtractionSolid("pPTFE02StockCylinder1Sub1",pPTFE02StockBox1,pPTFE02StockCylinder1S,dPTFE02StockCylinder1Transform1);
    G4SubtractionSolid* pPTFE02StockCylinder1Sub2 = new G4SubtractionSolid("pPTFE02StockCylinder1Sub2",pPTFE02StockCylinder1Sub1,pPTFE02StockCylinder1S,dPTFE02StockCylinder1Transform2);
    G4SubtractionSolid* pPTFE02StockCylinder1Sub3 = new G4SubtractionSolid("pPTFE02StockCylinder1Sub3",pPTFE02StockCylinder1Sub2,pPTFE02StockCylinder1S,dPTFE02StockCylinder1Transform3);
    G4SubtractionSolid* pPTFE02StockCylinder1Sub4 = new G4SubtractionSolid("pPTFE02StockCylinder1Sub4",pPTFE02StockCylinder1Sub3,pPTFE02StockCylinder1S,dPTFE02StockCylinder1Transform4);
    G4SubtractionSolid* pPTFE02StockCylinder1Sub5 = new G4SubtractionSolid("pPTFE02StockCylinder1Sub5",pPTFE02StockCylinder1Sub4,pPTFE02StockCylinder1S,dPTFE02StockCylinder1Transform5);
    G4SubtractionSolid*     pPTFE02StockCylinder1 = new G4SubtractionSolid("pPTFE02StockCylinder1",pPTFE02StockCylinder1Sub5,pPTFE02StockCylinder1S,dPTFE02StockCylinder1Transform6);

    G4SubtractionSolid* pPTFE02StockCylinder2Sub1 = new G4SubtractionSolid("pPTFE02StockCylinder2Sub1",pPTFE02StockCylinder1,pPTFE02StockCylinder2S,dPTFE02StockCylinder2Transform1);
    G4SubtractionSolid* pPTFE02StockCylinder2Sub2 = new G4SubtractionSolid("pPTFE02StockCylinder2Sub2",pPTFE02StockCylinder2Sub1,pPTFE02StockCylinder2S,dPTFE02StockCylinder2Transform2);
    G4SubtractionSolid* pPTFE02StockCylinder2Sub3 = new G4SubtractionSolid("pPTFE02StockCylinder2Sub3",pPTFE02StockCylinder2Sub2,pPTFE02StockCylinder2S,dPTFE02StockCylinder2Transform3);
    G4SubtractionSolid* pPTFE02StockCylinder2Sub4 = new G4SubtractionSolid("pPTFE02StockCylinder2Sub4",pPTFE02StockCylinder2Sub3,pPTFE02StockCylinder2S,dPTFE02StockCylinder2Transform4);
    G4SubtractionSolid* pPTFE02StockCylinder2Sub5 = new G4SubtractionSolid("pPTFE02StockCylinder2Sub5",pPTFE02StockCylinder2Sub4,pPTFE02StockCylinder2S,dPTFE02StockCylinder2Transform5);
    G4SubtractionSolid*     pPTFE02StockCylinder2 = new G4SubtractionSolid("pPTFE02StockCylinder2",pPTFE02StockCylinder2Sub5,pPTFE02StockCylinder2S,dPTFE02StockCylinder2Transform6);

    G4SubtractionSolid* pPTFE02StockCylinder3Sub1 = new G4SubtractionSolid("pPTFE02StockCylinder3Sub1",pPTFE02StockCylinder2,pPTFE02StockCylinder3S,dPTFE02StockCylinder3Transform1);
    G4SubtractionSolid* pPTFE02StockCylinder3Sub2 = new G4SubtractionSolid("pPTFE02StockCylinder3Sub2",pPTFE02StockCylinder3Sub1,pPTFE02StockCylinder3S,dPTFE02StockCylinder3Transform2);
    G4SubtractionSolid* pPTFE02StockCylinder3Sub3 = new G4SubtractionSolid("pPTFE02StockCylinder3Sub3",pPTFE02StockCylinder3Sub2,pPTFE02StockCylinder3S,dPTFE02StockCylinder3Transform3);
    G4SubtractionSolid* pPTFE02StockCylinder3Sub4 = new G4SubtractionSolid("pPTFE02StockCylinder3Sub4",pPTFE02StockCylinder3Sub3,pPTFE02StockCylinder3S,dPTFE02StockCylinder3Transform4);
    G4SubtractionSolid* pPTFE02StockCylinder3Sub5 = new G4SubtractionSolid("pPTFE02StockCylinder3Sub5",pPTFE02StockCylinder3Sub4,pPTFE02StockCylinder3S,dPTFE02StockCylinder3Transform5);
    G4SubtractionSolid*     pPTFE02StockCylinder3 = new G4SubtractionSolid("pPTFE02StockCylinder3",pPTFE02StockCylinder3Sub5,pPTFE02StockCylinder3S,dPTFE02StockCylinder3Transform6);

    G4SubtractionSolid* pPTFE02StockBox2 = new G4SubtractionSolid("pPTFE02StockBox2", pPTFE02StockCylinder3, pPTFE02StockBox2S, dPTFE02StockBox2Transform);

    G4SubtractionSolid* pPTFE02StockCylinder4Sub1 = new G4SubtractionSolid("pPTFE02StockCylinder4Sub1",pPTFE02StockBox2,pPTFE02StockCylinder4S,dPTFE02StockCylinder4Transform1);
    G4SubtractionSolid* 	pPTFE02StockCylinder4 = new G4SubtractionSolid("pPTFE02StockCylinder4",pPTFE02StockCylinder4Sub1,pPTFE02StockCylinder4S,dPTFE02StockCylinder4Transform2);

    G4SubtractionSolid* pPTFE02StockWingSub1 = new G4SubtractionSolid("pPTFE02StockWingSub1", pPTFE02StockCylinder4, pPTFE02StockWingS, dPTFE02StockWingTransform1);
    G4SubtractionSolid* pPTFE02StockWingSub2 = new G4SubtractionSolid("pPTFE02StockWingSub2", pPTFE02StockWingSub1, pPTFE02StockWingS, dPTFE02StockWingTransform2);
    G4SubtractionSolid* pPTFE02StockWing = new G4SubtractionSolid("pPTFE02StockWing", pPTFE02StockWingSub2, pPTFE02StockWingS, dPTFE02StockWingTransform3);

    // Create PTFE02
    pPTFE02LV = new G4LogicalVolume(pPTFE02StockWing, G4Material::GetMaterial("PTFE"), "PTFE02");
//    pPTFE02PV = new G4PVPlacement(0, dPTFE02StockPlacement, pPTFE02LV, "PTFE02", pMotherLV, false, 0);

    //////////////////////
    // Construct PTFE03 //
    //////////////////////

    // Set PTFE03 Variables
    G4double  dPTFE03StockRadius1 = dPTFE01StockRadius1;
    G4double  dPTFE03StockRadius2 = dPTFE01StockRadius2;
    G4double  dPTFE03StockRadius3 = dPTFE01StockRadius2;
    G4double  dPTFE03StockRadius4 = dPTFE01StockRadius4;
    G4double  dPTFE03StockRadius5 = dPTFE01StockRadius4;
    G4double  dPTFE03StockRadius6 = dPTFE00StockRadius2;
    G4double  dPTFE03StockRadius7 = dPTFE00StockRadius2;
    G4double  dPTFE03StockRadius8 = dPTFE01StockRadius4;
    G4double  dPTFE03StockRadius9 = dPTFE01StockRadius4;
    G4double dPTFE03StockRadius10 = dPTFE01StockRadius2;
    G4double dPTFE03StockRadius11 = dPTFE01StockRadius2;
    G4double dPTFE03StockRadius12 = dPTFE01StockRadius1;

    G4double dPTFE03StockRadiusArray[] = { dPTFE03StockRadius1,
                                      dPTFE03StockRadius2,
                                      dPTFE03StockRadius3,
                                      dPTFE03StockRadius4,
                                      dPTFE03StockRadius5,
                                      dPTFE03StockRadius6,
                                      dPTFE03StockRadius7,
                                      dPTFE03StockRadius8,
                                      dPTFE03StockRadius9,
                                      dPTFE03StockRadius10,
                                      dPTFE03StockRadius11,
                                      dPTFE03StockRadius12};

    G4double  dPTFE03StockHeight1 = 2.4 * mm;
    G4double  dPTFE03StockHeight2 = dPTFE03StockHeight1;
    G4double  dPTFE03StockHeight3 = 1.0 * mm;
    G4double  dPTFE03StockHeight4 = dPTFE03StockHeight3;
    G4double  dPTFE03StockHeight5 = 2.5 * mm;
    G4double  dPTFE03StockHeight6 = dPTFE03StockHeight5;
    G4double  dPTFE03StockHeight7 = -dPTFE03StockHeight5;
    G4double  dPTFE03StockHeight8 = -dPTFE03StockHeight5;
    G4double  dPTFE03StockHeight9 = -dPTFE03StockHeight3;
    G4double dPTFE03StockHeight10 = -dPTFE03StockHeight3;
    G4double dPTFE03StockHeight11 = -dPTFE03StockHeight1;
    G4double dPTFE03StockHeight12 = -dPTFE03StockHeight1;

    G4double dPTFE03StockHeightArray[] = { dPTFE03StockHeight1,
                                      dPTFE03StockHeight2,
                                      dPTFE03StockHeight3,
                                      dPTFE03StockHeight4,
                                      dPTFE03StockHeight5,
                                      dPTFE03StockHeight6,
                                      dPTFE03StockHeight7,
                                      dPTFE03StockHeight8,
                                      dPTFE03StockHeight9,
                                      dPTFE03StockHeight10,
                                      dPTFE03StockHeight11,
                                      dPTFE03StockHeight12};

    // Set Subtraction Solid variables
    G4double dPTFE03StockCylinder1InnerRadius = 0.0 * mm;
    G4double dPTFE03StockCylinder1OuterRadius = 4.0 * mm;
    G4double dPTFE03StockCylinder1Height = 12.0 * mm; // Has to go through

    G4double dPTFE03StockWingInnerRadius = 46.0 * mm;
    G4double dPTFE03StockWingOuterRadius = dPTFE03StockWingInnerRadius + 20.0 * mm;
    G4double dPTFE03StockWingHeight = 2 * dPTFE03StockHeight5;
    G4double dPTFE03StockWingStartAngle = 32.255 * deg;

    G4double dPTFE03StockCylinder1R = 47.75 * mm;
    G4double dPTFE03StockCylinder1X = dPTFE03StockCylinder1R * (cos(10.5 * deg) * mm);
    G4double dPTFE03StockCylinder1Y = dPTFE03StockCylinder1R * (sin(10.5 * deg) * mm);
    G4double dPTFE03StockCylinder1Z = dPTFE03StockHeight5;

    G4double dPTFE03StockWingX = 0.00 * mm;
    G4double dPTFE03StockWingY = 0.00 * mm;
    G4double dPTFE03StockWingZ = 0.00 * mm;

    G4RotationMatrix dPTFE03StockCylinderRot;
    dPTFE03StockCylinderRot.rotateZ(0.00);

    G4ThreeVector dPTFE03StockWingXYZ(dPTFE03StockWingX, dPTFE03StockWingY, dPTFE03StockWingZ);

    G4ThreeVector dPTFE03StockCylinder1XYZ(dPTFE03StockCylinder1X, dPTFE03StockCylinder1Y, dPTFE03StockCylinder1Z);
    G4Transform3D dPTFE03StockCylinder1Transform(dPTFE03StockCylinderRot, dPTFE03StockCylinder1XYZ);

    G4RotationMatrix dPTFE03StockWingRot1;
    dPTFE03StockWingRot1.rotateZ(0.00 * mm);
    G4Transform3D dPTFE03StockWingTransform1(dPTFE03StockWingRot1, dPTFE03StockWingXYZ);

    G4RotationMatrix dPTFE03StockWingRot2;
    dPTFE03StockWingRot2.rotateZ(120 * deg);
    G4Transform3D dPTFE03StockWingTransform2(dPTFE03StockWingRot2, dPTFE03StockWingXYZ);

    G4RotationMatrix dPTFE03StockWingRot3;
    dPTFE03StockWingRot3.rotateZ(240 * deg);
    G4Transform3D dPTFE03StockWingTransform3(dPTFE03StockWingRot3, dPTFE03StockWingXYZ);

    // Set PTFE03 Placement Values
    G4double dPTFE03StockPlacementX = 0.000 * mm;
    G4double dPTFE03StockPlacementY = 0.000 * mm;
    G4double dPTFE03StockPlacementZ = dPTFE02StockPlacementZ + dPTFE03StockHeight5 + dPTFE02StockHeight5;
    G4ThreeVector dPTFE03StockPlacement(dPTFE03StockPlacementX, dPTFE03StockPlacementY, dPTFE03StockPlacementZ);

    // Create Subtraction Solids
    G4Tubs* pPTFE03StockCylinder1S = new G4Tubs("pPTFE03StockCylinder1S", dPTFE03StockCylinder1InnerRadius, dPTFE03StockCylinder1OuterRadius, 0.5 * dPTFE03StockCylinder1Height, 0, 2 * M_PI);
    G4Tubs* pPTFE03StockWingS = new G4Tubs("pPTFE03StockWingS", dPTFE03StockWingInnerRadius, dPTFE03StockWingOuterRadius, dPTFE03StockWingHeight, 0.5 * dPTFE03StockWingStartAngle, -dPTFE03StockWingStartAngle + 120 * deg);

    G4GenericPolycone* pPTFE03Stock = new G4GenericPolycone("pPTFE03Stock", 0, 2 * M_PI, 12, dPTFE03StockRadiusArray, dPTFE03StockHeightArray);
    
    G4SubtractionSolid* pPTFE03StockCylinder1 = new G4SubtractionSolid("pPTFE03StockCylinder1", pPTFE03Stock, pPTFE03StockCylinder1S, dPTFE03StockCylinder1Transform);

    G4SubtractionSolid* pPTFE03StockWingSub1 = new G4SubtractionSolid("pPTFE03StockWingSub1", pPTFE03StockCylinder1, pPTFE03StockWingS, dPTFE03StockWingTransform1);
    G4SubtractionSolid* pPTFE03StockWingSub2 = new G4SubtractionSolid("pPTFE03StockWingSub2", pPTFE03StockWingSub1, pPTFE03StockWingS, dPTFE03StockWingTransform2);
    G4SubtractionSolid* pPTFE03StockWing = new G4SubtractionSolid("pPTFE03StockWing", pPTFE03StockWingSub2, pPTFE03StockWingS, dPTFE03StockWingTransform3);

    // Create PTFE03
    pPTFE03LV = new G4LogicalVolume(pPTFE03StockWing, G4Material::GetMaterial("PTFE"), "PTFE03");
//    pPTFE03PV = new G4PVPlacement(0, dPTFE03StockPlacement, pPTFE03LV, "PTFE03", pMotherLV, false, 0);

    //////////////////////
    // Construct PTFE04 //
    //////////////////////

    // Set PTFE04 Variables
    G4double  dPTFE04StockRadius1 = dPTFE01StockRadius1;
    G4double  dPTFE04StockRadius2 = dPTFE01StockRadius2;
    G4double  dPTFE04StockRadius3 = dPTFE01StockRadius2;
    G4double  dPTFE04StockRadius4 = dPTFE01StockRadius4;
    G4double  dPTFE04StockRadius5 = dPTFE01StockRadius4;
    G4double  dPTFE04StockRadius6 = dPTFE00StockRadius2;
    G4double  dPTFE04StockRadius7 = dPTFE00StockRadius2;
    G4double  dPTFE04StockRadius8 = dPTFE01StockRadius4;
    G4double  dPTFE04StockRadius9 = dPTFE01StockRadius4;
    G4double dPTFE04StockRadius10 = dPTFE01StockRadius2;
    G4double dPTFE04StockRadius11 = dPTFE01StockRadius2;
    G4double dPTFE04StockRadius12 = dPTFE01StockRadius1;

    G4double dPTFE04StockRadiusArray[] = { dPTFE04StockRadius1,
                                      dPTFE04StockRadius2,
                                      dPTFE04StockRadius3,
                                      dPTFE04StockRadius4,
                                      dPTFE04StockRadius5,
                                      dPTFE04StockRadius6,
                                      dPTFE04StockRadius7,
                                      dPTFE04StockRadius8,
                                      dPTFE04StockRadius9,
                                      dPTFE04StockRadius10,
                                      dPTFE04StockRadius11,
                                      dPTFE04StockRadius12};

    G4double  dPTFE04StockHeight1 = 4.9 * mm;
    G4double  dPTFE04StockHeight2 = dPTFE04StockHeight1;
    G4double  dPTFE04StockHeight3 = 3.5 * mm;
    G4double  dPTFE04StockHeight4 = dPTFE04StockHeight3;
    G4double  dPTFE04StockHeight5 = 5.0 * mm;
    G4double  dPTFE04StockHeight6 = dPTFE04StockHeight5;
    G4double  dPTFE04StockHeight7 = -dPTFE04StockHeight5;
    G4double  dPTFE04StockHeight8 = -dPTFE04StockHeight5;
    G4double  dPTFE04StockHeight9 = -dPTFE04StockHeight3;
    G4double dPTFE04StockHeight10 = -dPTFE04StockHeight3;
    G4double dPTFE04StockHeight11 = -dPTFE04StockHeight1;
    G4double dPTFE04StockHeight12 = -dPTFE04StockHeight1;

    G4double dPTFE04StockHeightArray[] = { dPTFE04StockHeight1,
                                      dPTFE04StockHeight2,
                                      dPTFE04StockHeight3,
                                      dPTFE04StockHeight4,
                                      dPTFE04StockHeight5,
                                      dPTFE04StockHeight6,
                                      dPTFE04StockHeight7,
                                      dPTFE04StockHeight8,
                                      dPTFE04StockHeight9,
                                      dPTFE04StockHeight10,
                                      dPTFE04StockHeight11,
                                      dPTFE04StockHeight12};

    // Set Subtraction Solids Variables
    G4double dPTFE04StockCylinder1InnerRadius = 0.0 * mm; // Large one on bottom
    G4double dPTFE04StockCylinder1OuterRadius = 3.0 * mm;
    G4double dPTFE04StockCylinder1Height = 4.0 * mm;

    G4double dPTFE04StockCylinder2InnerRadius = 0.0 * mm; // Larger one on top wing
    G4double dPTFE04StockCylinder2OuterRadius = 4.0 * mm;
    G4double dPTFE04StockCylinder2Height = 22.0 * mm; // Has to go through

    G4double dPTFE04StockWingInnerRadius = 46.0 * mm;
    G4double dPTFE04StockWingOuterRadius = dPTFE04StockWingInnerRadius + 20.0 * mm;
    G4double dPTFE04StockWingHeight = 2 * dPTFE04StockHeight5;
    G4double dPTFE04StockWingStartAngle = 32.255 * deg;

    G4double dPTFE04StockCylinder1R = 39.00 * mm;
    G4double dPTFE04StockCylinder1X1 = dPTFE04StockCylinder1R * (cos(51 * deg) * mm);
    G4double dPTFE04StockCylinder1X2 = dPTFE04StockCylinder1R * (cos(9 * deg) * mm);
    G4double dPTFE04StockCylinder1X3 = dPTFE04StockCylinder1R * (cos(69 * deg) * mm);
    G4double dPTFE04StockCylinder1X4 = -dPTFE04StockCylinder1X1;
    G4double dPTFE04StockCylinder1X5 = -dPTFE04StockCylinder1X2;
    G4double dPTFE04StockCylinder1X6 = -dPTFE04StockCylinder1X3;
    G4double dPTFE04StockCylinder1Y1 = dPTFE04StockCylinder1R * (sin(51 * deg) * mm);
    G4double dPTFE04StockCylinder1Y2 = -dPTFE04StockCylinder1R * (sin(9 * deg) * mm);
    G4double dPTFE04StockCylinder1Y3 = -dPTFE04StockCylinder1R * (sin(69 * deg) * mm);
    G4double dPTFE04StockCylinder1Y4 = -dPTFE04StockCylinder1Y1;
    G4double dPTFE04StockCylinder1Y5 = -dPTFE04StockCylinder1Y2;
    G4double dPTFE04StockCylinder1Y6 = -dPTFE04StockCylinder1Y3;
    G4double dPTFE04StockCylinder1Z = dPTFE04StockHeight9;

    G4double dPTFE04StockCylinder2R = 47.75 * mm;
    G4double dPTFE04StockCylinder2X = dPTFE04StockCylinder2R * (cos(10.5 * deg) * mm);
    G4double dPTFE04StockCylinder2Y = dPTFE04StockCylinder2R * (sin(10.5 * deg) * mm);
    G4double dPTFE04StockCylinder2Z = dPTFE04StockHeight5;

    G4double dPTFE04StockWingX = 0.00 * mm;
    G4double dPTFE04StockWingY = 0.00 * mm;
    G4double dPTFE04StockWingZ = 0.00 * mm;

    G4RotationMatrix dPTFE04StockCylinderRot;
    dPTFE04StockCylinderRot.rotateZ(0.00);

    G4ThreeVector dPTFE04StockWingXYZ(dPTFE04StockWingX, dPTFE04StockWingY, dPTFE04StockWingZ);

    G4ThreeVector dPTFE04StockCylinder1XYZ1(dPTFE04StockCylinder1X1,dPTFE04StockCylinder1Y1,dPTFE04StockCylinder1Z);
    G4Transform3D dPTFE04StockCylinder1Transform1(dPTFE04StockCylinderRot, dPTFE04StockCylinder1XYZ1);

    G4ThreeVector dPTFE04StockCylinder1XYZ2(dPTFE04StockCylinder1X2,dPTFE04StockCylinder1Y2,dPTFE04StockCylinder1Z);
    G4Transform3D dPTFE04StockCylinder1Transform2(dPTFE04StockCylinderRot, dPTFE04StockCylinder1XYZ2);

    G4ThreeVector dPTFE04StockCylinder1XYZ3(dPTFE04StockCylinder1X3,dPTFE04StockCylinder1Y3,dPTFE04StockCylinder1Z);
    G4Transform3D dPTFE04StockCylinder1Transform3(dPTFE04StockCylinderRot, dPTFE04StockCylinder1XYZ3);

    G4ThreeVector dPTFE04StockCylinder1XYZ4(dPTFE04StockCylinder1X4,dPTFE04StockCylinder1Y4,dPTFE04StockCylinder1Z);
    G4Transform3D dPTFE04StockCylinder1Transform4(dPTFE04StockCylinderRot, dPTFE04StockCylinder1XYZ4);

    G4ThreeVector dPTFE04StockCylinder1XYZ5(dPTFE04StockCylinder1X5,dPTFE04StockCylinder1Y5,dPTFE04StockCylinder1Z);
    G4Transform3D dPTFE04StockCylinder1Transform5(dPTFE04StockCylinderRot, dPTFE04StockCylinder1XYZ5);

    G4ThreeVector dPTFE04StockCylinder1XYZ6(dPTFE04StockCylinder1X6,dPTFE04StockCylinder1Y6,dPTFE04StockCylinder1Z);
    G4Transform3D dPTFE04StockCylinder1Transform6(dPTFE04StockCylinderRot, dPTFE04StockCylinder1XYZ6);

    G4ThreeVector dPTFE04StockCylinder2XYZ(dPTFE04StockCylinder2X, dPTFE04StockCylinder2Y,dPTFE04StockCylinder2Z);
   	G4Transform3D dPTFE04StockCylinder2Transform(dPTFE04StockCylinderRot, dPTFE04StockCylinder2XYZ);

   	G4RotationMatrix dPTFE04StockWingRot1;
   	dPTFE04StockWingRot1.rotateZ(0.00);
   	G4Transform3D dPTFE04StockWingTransform1(dPTFE04StockWingRot1, dPTFE04StockWingXYZ);

   	G4RotationMatrix dPTFE04StockWingRot2;
   	dPTFE04StockWingRot2.rotateZ(120 * deg);
   	G4Transform3D dPTFE04StockWingTransform2(dPTFE04StockWingRot2, dPTFE04StockWingXYZ);

   	G4RotationMatrix dPTFE04StockWingRot3;
   	dPTFE04StockWingRot3.rotateZ(240 * deg);
   	G4Transform3D dPTFE04StockWingTransform3(dPTFE04StockWingRot3, dPTFE04StockWingXYZ);

    // Set Stock Placement Values
    G4double dPTFE04StockPlacementX = 0.000 * mm;
    G4double dPTFE04StockPlacementY = 0.000 * mm;
    G4double dPTFE04StockPlacementZ = dPTFE03StockPlacementZ + dPTFE03StockHeight5 + dPTFE04StockHeight5;
    G4ThreeVector dPTFE04StockPlacement(dPTFE04StockPlacementX, dPTFE04StockPlacementY, dPTFE04StockPlacementZ);

    // Create Subtraction Solids
	G4Tubs* pPTFE04StockCylinder1S = new G4Tubs("pPTFE04StockCylinder1S", dPTFE04StockCylinder1InnerRadius, dPTFE04StockCylinder1OuterRadius, 0.5 * dPTFE04StockCylinder1Height, 0, 2 * M_PI);
	G4Tubs* pPTFE04StockCylinder2S = new G4Tubs("pPTFE04StockCylinder2S", dPTFE04StockCylinder2InnerRadius, dPTFE04StockCylinder2OuterRadius, 0.5 * dPTFE04StockCylinder2Height, 0, 2 * M_PI);
	G4Tubs* pPTFE04StockWingS = new G4Tubs("pPTFE04StockWingS", dPTFE04StockWingInnerRadius, dPTFE04StockWingOuterRadius, dPTFE04StockWingHeight, 0.5 * dPTFE04StockWingStartAngle, -dPTFE04StockWingStartAngle + 120 * deg);
    
    G4GenericPolycone* pPTFE04Stock  = new G4GenericPolycone("PTFE04Stock", 0, 2 * M_PI, 12, dPTFE04StockRadiusArray, dPTFE04StockHeightArray);

    G4SubtractionSolid* pPTFE04StockCylinder1Sub1 = new G4SubtractionSolid("pPTFE04StockCylinder1Sub1",pPTFE04Stock,pPTFE04StockCylinder1S,dPTFE04StockCylinder1Transform1);
    G4SubtractionSolid* pPTFE04StockCylinder1Sub2 = new G4SubtractionSolid("pPTFE04StockCylinder1Sub2",pPTFE04StockCylinder1Sub1,pPTFE04StockCylinder1S,dPTFE04StockCylinder1Transform2);
    G4SubtractionSolid* pPTFE04StockCylinder1Sub3 = new G4SubtractionSolid("pPTFE04StockCylinder1Sub3",pPTFE04StockCylinder1Sub2,pPTFE04StockCylinder1S,dPTFE04StockCylinder1Transform3);
    G4SubtractionSolid* pPTFE04StockCylinder1Sub4 = new G4SubtractionSolid("pPTFE04StockCylinder1Sub4",pPTFE04StockCylinder1Sub3,pPTFE04StockCylinder1S,dPTFE04StockCylinder1Transform4);
    G4SubtractionSolid* pPTFE04StockCylinder1Sub5 = new G4SubtractionSolid("pPTFE04StockCylinder1Sub5",pPTFE04StockCylinder1Sub4,pPTFE04StockCylinder1S,dPTFE04StockCylinder1Transform5);
    G4SubtractionSolid*     pPTFE04StockCylinder1 = new G4SubtractionSolid("pPTFE04StockCylinder1",pPTFE04StockCylinder1Sub5,pPTFE04StockCylinder1S,dPTFE04StockCylinder1Transform6);

    G4SubtractionSolid* pPTFE04StockCylinder2 = new G4SubtractionSolid("pPTFE04StockCylinder2",pPTFE04StockCylinder1,pPTFE04StockCylinder2S,dPTFE04StockCylinder2Transform);

    G4SubtractionSolid* pPTFE04StockWingSub1 = new G4SubtractionSolid("pPTFE04StockWingSub1",pPTFE04StockCylinder2,pPTFE04StockWingS,dPTFE04StockWingTransform1);
    G4SubtractionSolid* pPTFE04StockWingSub2 = new G4SubtractionSolid("pPTFE04StockWingSub2",pPTFE04StockWingSub1,pPTFE04StockWingS,dPTFE04StockWingTransform2);
    G4SubtractionSolid* pPTFE04StockWing = new G4SubtractionSolid("pPTFE04StockWing",pPTFE04StockWingSub2,pPTFE04StockWingS,dPTFE04StockWingTransform3);

    // Create PTFE04
    pPTFE04LV = new G4LogicalVolume(pPTFE04StockWing , G4Material::GetMaterial("PTFE"), "PTFE04");
//    pPTFE04PV = new G4PVPlacement(0, dPTFE04StockPlacement, pPTFE04LV, "PTFE04", pMotherLV, false, 0);

    //////////////////////
    // Construct PTFE05 //
    //////////////////////

    // Set Stock Variables
    G4double   dPTFE05StockRadius1 = 0.0 * mm;
    G4double   dPTFE05StockRadius2 = 46.0 * mm;
    G4double   dPTFE05StockRadius3 = dPTFE05StockRadius2;
    G4double   dPTFE05StockRadius4 = dPTFE00StockRadius2;
    G4double   dPTFE05StockRadius5 = dPTFE00StockRadius2;
    G4double   dPTFE05StockRadius6 = dPTFE01StockRadius4;
    G4double   dPTFE05StockRadius7 = dPTFE01StockRadius4;
    G4double   dPTFE05StockRadius8 = dPTFE01StockRadius2;
    G4double   dPTFE05StockRadius9 = dPTFE01StockRadius2;
    G4double  dPTFE05StockRadius10 = dPTFE05StockRadius1;

    G4double dPTFE05StockRadiusArray[] = { dPTFE05StockRadius1,
                                      dPTFE05StockRadius2,
                                      dPTFE05StockRadius3,
                                      dPTFE05StockRadius4,
                                      dPTFE05StockRadius5,
                                      dPTFE05StockRadius6,
                                      dPTFE05StockRadius7,
                                      dPTFE05StockRadius8,
                                  	  dPTFE05StockRadius9,
                                  	  dPTFE05StockRadius10};

    G4double   dPTFE05StockHeight1 = 14.0 * mm;
    G4double   dPTFE05StockHeight2 = dPTFE05StockHeight1;
    G4double   dPTFE05StockHeight3 = -8.5 * mm;
    G4double   dPTFE05StockHeight4 = dPTFE05StockHeight3;
    G4double   dPTFE05StockHeight5 = -dPTFE05StockHeight1;
    G4double   dPTFE05StockHeight6 = -dPTFE05StockHeight1;
    G4double   dPTFE05StockHeight7 = -12.5 * mm;
    G4double   dPTFE05StockHeight8 = dPTFE05StockHeight7;
    G4double   dPTFE05StockHeight9 = -13.9 * mm;
    G4double  dPTFE05StockHeight10 = dPTFE05StockHeight9;

    G4double dPTFE05StockHeightArray[] = { dPTFE05StockHeight1,
                                      dPTFE05StockHeight2,
                                      dPTFE05StockHeight3,
                                      dPTFE05StockHeight4,
                                      dPTFE05StockHeight5,
                                      dPTFE05StockHeight6,
                                      dPTFE05StockHeight7,
                                      dPTFE05StockHeight8,
                                  	  dPTFE05StockHeight9,
                                  	  dPTFE05StockHeight10};

 	// Set Subtraction Solid variables
    G4double dPTFE05StockWing1InnerRadius = dPTFE05StockRadius2 + 0.05 * mm;
    G4double dPTFE05StockWing1OuterRadius = dPTFE05StockWing1InnerRadius + 20.0 * mm;
    G4double dPTFE05StockWing1Height = 2 * dPTFE05StockHeight1;
    G4double dPTFE05StockWing1StartAngle = 32.255 * deg;

    G4double dPTFE05StockWing2InnerRadius = dPTFE01StockRadius4 + 0.	5 * mm;
    G4double dPTFE05StockWing2OuterRadius = dPTFE05StockWing2InnerRadius + 20 * mm;
    G4double dPTFE05StockWing2Height = dPTFE05StockHeight1 - dPTFE05StockHeight3;
    G4double dPTFE05StockWing2StartAngle = 12.5 * deg;

    G4double dPTFE05StockCylinder1InnerRadius = 0.0 * mm; // Large one on bottom
    G4double dPTFE05StockCylinder1OuterRadius = 3.0 * mm;
    G4double dPTFE05StockCylinder1Height = 4.0 * mm;

    G4double dPTFE05StockCylinder2InnerRadius = 0.0 * mm; // Larger one on top wing
    G4double dPTFE05StockCylinder2OuterRadius = 4.0 * mm;
    G4double dPTFE05StockCylinder2Height = 13.0 * mm; // Has to go through
/*
    G4double   dPTFE05PMTSignalFTBoxSide = 28.0 * mm;
    G4double dPTFE05PMTSignalFTBoxHeight = 40.0 * mm;

    G4double dPTFE05PMTSignalFTTubInnerRadius = 3.175 * mm;
    G4double dPTFE05PMTSignalFTTubOuterRadius = dPTFE05PMTSignalFTTubInnerRadius + 5.0 * mm;
    G4double dPTFE05PMTSignalFTTubHeight      = 2 * dPTFE05PMTSignalFTBoxHeight;
*/
    G4double dPTFE05StockWing1X = 0.00 * mm;
    G4double dPTFE05StockWing1Y = 0.00 * mm;
    G4double dPTFE05StockWing1Z = 0.00 * mm;

    G4double dPTFE05StockWing2X = 0.00 * mm;
    G4double dPTFE05StockWing2Y = 0.00 * mm;
    G4double dPTFE05StockWing2Z = dPTFE05StockHeight1;

    G4double dPTFE05StockCylinder1R = 39.00 * mm;
    G4double dPTFE05StockCylinder1X1 = dPTFE05StockCylinder1R * (cos(69 * deg) * mm);
    G4double dPTFE05StockCylinder1X2 = dPTFE05StockCylinder1R * (cos(9 * deg) * mm);
    G4double dPTFE05StockCylinder1X3 = dPTFE05StockCylinder1R * (cos(51 * deg) * mm);
    G4double dPTFE05StockCylinder1X4 = -dPTFE05StockCylinder1X1;
    G4double dPTFE05StockCylinder1X5 = -dPTFE05StockCylinder1X2;
    G4double dPTFE05StockCylinder1X6 = -dPTFE05StockCylinder1X3;
    G4double dPTFE05StockCylinder1Y1 = dPTFE05StockCylinder1R * (sin(69 * deg) * mm);
    G4double dPTFE05StockCylinder1Y2 = dPTFE05StockCylinder1R * (sin(9 * deg) * mm);
    G4double dPTFE05StockCylinder1Y3 = -dPTFE05StockCylinder1R * (sin(51 * deg) * mm);
    G4double dPTFE05StockCylinder1Y4 = -dPTFE05StockCylinder1Y1;
    G4double dPTFE05StockCylinder1Y5 = -dPTFE05StockCylinder1Y2;
    G4double dPTFE05StockCylinder1Y6 = -dPTFE05StockCylinder1Y3;
    G4double dPTFE05StockCylinder1Z = dPTFE05StockHeight9;

    G4double dPTFE05StockCylinder2R = 47.75 * mm;
    G4double dPTFE05StockCylinder2X = dPTFE05StockCylinder2R * (cos(10.5 * deg) * mm);
    G4double dPTFE05StockCylinder2Y = dPTFE05StockCylinder2R * (sin(10.5 * deg) * mm);
    G4double dPTFE05StockCylinder2Z = dPTFE05StockHeight3;
/*
    G4double dPTFE05PMTSignalFTX1 = dPTFE05PMTSignalFTTubInnerRadius - 0.5 * dPTFE05PMTSignalFTBoxSide;
    G4double dPTFE05PMTSignalFTX2 = -dPTFE05PMTSignalFTX1;
    G4double dPTFE05PMTSignalFTY1 = 0.5 * dPTFE05PMTSignalFTBoxSide - dPTFE05PMTSignalFTTubInnerRadius;
    G4double dPTFE05PMTSignalFTY2 = -dPTFE05PMTSignalFTY1;
    G4double  dPTFE05PMTSignalFTZ = 0.00 * mm;

    G4double dPTFE05StockPMTSubX1 = -15.0 * mm;
    G4double dPTFE05StockPMTSubX2 = -dPTFE05StockPMTSubX1;
    G4double dPTFE05StockPMTSubY1 = 15.0 * mm;
    G4double dPTFE05StockPMTSubY2 = -dPTFE05StockPMTSubY1;
    G4double dPTFE05StockPMTSubZ =  dPTFE05StockHeight1;
*/
    G4ThreeVector dPTFE05StockWing1XYZ(dPTFE05StockWing1X, dPTFE05StockWing1Y, dPTFE05StockWing1Z);

    G4ThreeVector dPTFE05StockWing2XYZ(dPTFE05StockWing2X, dPTFE05StockWing2Y, dPTFE05StockWing2Z);

    G4RotationMatrix dPTFE05StockCylinderRot;
    dPTFE05StockCylinderRot.rotateZ(0.00);

    G4RotationMatrix dPTFE05StockWing1Rot1;
    dPTFE05StockWing1Rot1.rotateZ(0.00);
    G4Transform3D dPTFE05StockWing1Transform1(dPTFE05StockWing1Rot1, dPTFE05StockWing1XYZ);

    G4RotationMatrix dPTFE05StockWing1Rot2;
    dPTFE05StockWing1Rot2.rotateZ(120 * deg);
    G4Transform3D dPTFE05StockWing1Transform2(dPTFE05StockWing1Rot2, dPTFE05StockWing1XYZ);

    G4RotationMatrix dPTFE05StockWing1Rot3;
    dPTFE05StockWing1Rot3.rotateZ(240 * deg);
    G4Transform3D dPTFE05StockWing1Transform3(dPTFE05StockWing1Rot3, dPTFE05StockWing1XYZ);

    G4RotationMatrix dPTFE05StockWing2Rot1;
    dPTFE05StockWing2Rot1.rotateZ(0.00);
    G4Transform3D dPTFE05StockWing2Transform1(dPTFE05StockWing2Rot1, dPTFE05StockWing2XYZ);

    G4RotationMatrix dPTFE05StockWing2Rot2;
    dPTFE05StockWing2Rot2.rotateZ(120 * deg);
    G4Transform3D dPTFE05StockWing2Transform2(dPTFE05StockWing2Rot2, dPTFE05StockWing2XYZ);

    G4RotationMatrix dPTFE05StockWing2Rot3;
    dPTFE05StockWing2Rot3.rotateZ(240 * deg);
    G4Transform3D dPTFE05StockWing2Transform3(dPTFE05StockWing2Rot3, dPTFE05StockWing2XYZ);

    G4ThreeVector dPTFE05StockCylinder1XYZ1(dPTFE05StockCylinder1X1,dPTFE05StockCylinder1Y1,dPTFE05StockCylinder1Z);
    G4Transform3D dPTFE05StockCylinder1Transform1(dPTFE05StockCylinderRot, dPTFE05StockCylinder1XYZ1);
/*
    G4ThreeVector dPTFE05PMTSignalFTXYZ1(dPTFE05PMTSignalFTX1,dPTFE05PMTSignalFTY1,dPTFE05PMTSignalFTZ);
    G4RotationMatrix dPTFE05PMTSignalFTRot1;
    dPTFE05PMTSignalFTRot1.rotateZ(0.5 * M_PI);
    G4Transform3D dPTFE05PMTSignalFTTransform1(dPTFE05PMTSignalFTRot1, dPTFE05PMTSignalFTXYZ1);

    G4ThreeVector dPTFE05PMTSignalFTXYZ2(dPTFE05PMTSignalFTX2,dPTFE05PMTSignalFTY1,dPTFE05PMTSignalFTZ);
    G4RotationMatrix dPTFE05PMTSignalFTRot2;
    dPTFE05PMTSignalFTRot2.rotateZ(0.00);
    G4Transform3D dPTFE05PMTSignalFTTransform2(dPTFE05PMTSignalFTRot2, dPTFE05PMTSignalFTXYZ2);

    G4ThreeVector dPTFE05PMTSignalFTXYZ3(dPTFE05PMTSignalFTX2,dPTFE05PMTSignalFTY2,dPTFE05PMTSignalFTZ);
    G4RotationMatrix dPTFE05PMTSignalFTRot3;
    dPTFE05PMTSignalFTRot3.rotateZ(1.5 * M_PI);
    G4Transform3D dPTFE05PMTSignalFTTransform3(dPTFE05PMTSignalFTRot3, dPTFE05PMTSignalFTXYZ3);

    G4ThreeVector dPTFE05PMTSignalFTXYZ4(dPTFE05PMTSignalFTX1,dPTFE05PMTSignalFTY2,dPTFE05PMTSignalFTZ);
    G4RotationMatrix dPTFE05PMTSignalFTRot4;
    dPTFE05PMTSignalFTRot4.rotateZ(M_PI);
    G4Transform3D dPTFE05PMTSignalFTTransform4(dPTFE05PMTSignalFTRot4, dPTFE05PMTSignalFTXYZ4);

    G4ThreeVector dPTFE05StockPMTSubXYZ1(dPTFE05StockPMTSubX1,dPTFE05StockPMTSubY1,dPTFE05StockPMTSubZ);
*/
    G4ThreeVector dPTFE05StockCylinder1XYZ2(dPTFE05StockCylinder1X2,dPTFE05StockCylinder1Y2,dPTFE05StockCylinder1Z);
    G4Transform3D dPTFE05StockCylinder1Transform2(dPTFE05StockCylinderRot, dPTFE05StockCylinder1XYZ2);

    G4ThreeVector dPTFE05StockCylinder1XYZ3(dPTFE05StockCylinder1X3,dPTFE05StockCylinder1Y3,dPTFE05StockCylinder1Z);
    G4Transform3D dPTFE05StockCylinder1Transform3(dPTFE05StockCylinderRot, dPTFE05StockCylinder1XYZ3);

    G4ThreeVector dPTFE05StockCylinder1XYZ4(dPTFE05StockCylinder1X4,dPTFE05StockCylinder1Y4,dPTFE05StockCylinder1Z);
    G4Transform3D dPTFE05StockCylinder1Transform4(dPTFE05StockCylinderRot, dPTFE05StockCylinder1XYZ4);

    G4ThreeVector dPTFE05StockCylinder1XYZ5(dPTFE05StockCylinder1X5,dPTFE05StockCylinder1Y5,dPTFE05StockCylinder1Z);
    G4Transform3D dPTFE05StockCylinder1Transform5(dPTFE05StockCylinderRot, dPTFE05StockCylinder1XYZ5);

    G4ThreeVector dPTFE05StockCylinder1XYZ6(dPTFE05StockCylinder1X6,dPTFE05StockCylinder1Y6,dPTFE05StockCylinder1Z);
    G4Transform3D dPTFE05StockCylinder1Transform6(dPTFE05StockCylinderRot, dPTFE05StockCylinder1XYZ6);

    G4ThreeVector dPTFE05StockCylinder2XYZ(dPTFE05StockCylinder2X, dPTFE05StockCylinder2Y,dPTFE05StockCylinder2Z);
   	G4Transform3D dPTFE05StockCylinder2Transform(dPTFE05StockCylinderRot, dPTFE05StockCylinder2XYZ);
/*
    G4ThreeVector dPTFE05PMTSignalFTXYZ1(dPTFE05PMTSignalFTX1,dPTFE05PMTSignalFTY1,dPTFE05PMTSignalFTZ);
    G4RotationMatrix dPTFE05PMTSignalFTRot1;
    dPTFE05PMTSignalFTRot1.rotateZ(0.5 * M_PI);
    G4Transform3D dPTFE05PMTSignalFTTransform1(dPTFE05PMTSignalFTRot1, dPTFE05PMTSignalFTXYZ1);

    G4ThreeVector dPTFE05PMTSignalFTXYZ2(dPTFE05PMTSignalFTX2,dPTFE05PMTSignalFTY1,dPTFE05PMTSignalFTZ);
    G4RotationMatrix dPTFE05PMTSignalFTRot2;
    dPTFE05PMTSignalFTRot2.rotateZ(0.00);
    G4Transform3D dPTFE05PMTSignalFTTransform2(dPTFE05PMTSignalFTRot2, dPTFE05PMTSignalFTXYZ2);

    G4ThreeVector dPTFE05PMTSignalFTXYZ3(dPTFE05PMTSignalFTX2,dPTFE05PMTSignalFTY2,dPTFE05PMTSignalFTZ);
    G4RotationMatrix dPTFE05PMTSignalFTRot3;
    dPTFE05PMTSignalFTRot3.rotateZ(1.5 * M_PI);
    G4Transform3D dPTFE05PMTSignalFTTransform3(dPTFE05PMTSignalFTRot3, dPTFE05PMTSignalFTXYZ3);

    G4ThreeVector dPTFE05PMTSignalFTXYZ4(dPTFE05PMTSignalFTX1,dPTFE05PMTSignalFTY2,dPTFE05PMTSignalFTZ);
    G4RotationMatrix dPTFE05PMTSignalFTRot4;
    dPTFE05PMTSignalFTRot4.rotateZ(M_PI);
    G4Transform3D dPTFE05PMTSignalFTTransform4(dPTFE05PMTSignalFTRot4, dPTFE05PMTSignalFTXYZ4);

    G4ThreeVector dPTFE05StockPMTSubXYZ1(dPTFE05StockPMTSubX1,dPTFE05StockPMTSubY1,dPTFE05StockPMTSubZ);
    G4Transform3D dPTFE05StockPMTSubTransform1(dPTFE05StockPMTSubRot, dPTFE05StockPMTSubXYZ1);

    G4ThreeVector dPTFE05StockPMTSubXYZ2(dPTFE05StockPMTSubX2,dPTFE05StockPMTSubY1,dPTFE05StockPMTSubZ);
    G4Transform3D dPTFE05StockPMTSubTransform2(dPTFE05StockPMTSubRot, dPTFE05StockPMTSubXYZ2);

    G4ThreeVector dPTFE05StockPMTSubXYZ3(dPTFE05StockPMTSubX2,dPTFE05StockPMTSubY2,dPTFE05StockPMTSubZ);
    G4Transform3D dPTFE05StockPMTSubTransform3(dPTFE05StockPMTSubRot, dPTFE05StockPMTSubXYZ3);

    G4ThreeVector dPTFE05StockPMTSubXYZ4(dPTFE05StockPMTSubX1,dPTFE05StockPMTSubY2,dPTFE05StockPMTSubZ);
    G4Transform3D dPTFE05StockPMTSubTransform4(dPTFE05StockPMTSubRot, dPTFE05StockPMTSubXYZ4);
*/
    // Set PTFE05 Placement Values
    G4double dPTFE05StockPlacementX = 0.000 * mm;
    G4double dPTFE05StockPlacementY = 0.000 * mm;
    G4double dPTFE05StockPlacementZ = dPTFE04StockPlacementZ + dPTFE04StockHeight5 + dPTFE05StockHeight1;
    G4ThreeVector dPTFE05StockPlacement(dPTFE05StockPlacementX, dPTFE05StockPlacementY, dPTFE05StockPlacementZ);

    G4double testX = 0.000 * mm;
    G4double testY = 0.000 * mm;
    G4double testZ = dPTFE04StockPlacementZ + dPTFE04StockHeight5 + 2 * dPTFE05StockHeight1;
    G4ThreeVector testPlacement(testX, testY, testZ);


    // Create Subtraction Solids
    G4Tubs* pPTFE05StockWing1S = new G4Tubs("pPTFE05StockWing1S", dPTFE05StockWing1InnerRadius, dPTFE05StockWing1OuterRadius, dPTFE05StockWing1Height, 0.5 * dPTFE05StockWing1StartAngle, -dPTFE05StockWing1StartAngle + 120.0 * deg);
    G4Tubs* pPTFE05StockWing2S = new G4Tubs("pPTFE05StockWing2S", dPTFE05StockWing2InnerRadius, dPTFE05StockWing2OuterRadius, dPTFE05StockWing2Height, 0.5 * dPTFE05StockWing2StartAngle + 60 * deg, -dPTFE05StockWing2StartAngle + 120 * deg);
    G4Tubs* pPTFE05StockCylinder1S = new G4Tubs("pPTFE05StockCylinder1S", dPTFE05StockCylinder1InnerRadius, dPTFE05StockCylinder1OuterRadius, 0.5 * dPTFE05StockCylinder1Height, 0, 2 * M_PI);
   	G4Tubs* pPTFE05StockCylinder2S = new G4Tubs("pPTFE05StockCylinder2S",dPTFE05StockCylinder2InnerRadius, dPTFE05StockCylinder2OuterRadius, 0.5 * dPTFE05StockCylinder2Height, 0, 2 * M_PI);

    G4GenericPolycone* pPTFE05Stock = new G4GenericPolycone("PTFE05", 0, 2 * M_PI, 10, dPTFE05StockRadiusArray, dPTFE05StockHeightArray);

    G4SubtractionSolid* pPTFE05StockWing1Sub1 = new G4SubtractionSolid("pPTFE05StockWing1Sub1", pPTFE05Stock, pPTFE05StockWing1S, dPTFE05StockWing1Transform1);
    G4SubtractionSolid* pPTFE05StockWing1Sub2 = new G4SubtractionSolid("pPTFE05StockWing1Sub2", pPTFE05StockWing1Sub1, pPTFE05StockWing1S, dPTFE05StockWing1Transform2);
    G4SubtractionSolid* pPTFE05StockWing1 = new G4SubtractionSolid("pPTFE05Stock1Wing", pPTFE05StockWing1Sub2, pPTFE05StockWing1S, dPTFE05StockWing1Transform3);

    G4SubtractionSolid* pPTFE05StockWing2Sub1 = new G4SubtractionSolid("pPTFE05StockWing2Sub1", pPTFE05StockWing1, pPTFE05StockWing2S, dPTFE05StockWing2Transform1);
    G4SubtractionSolid* pPTFE05StockWing2Sub2 = new G4SubtractionSolid("pPTFE05StockWing2Sub2", pPTFE05StockWing2Sub1, pPTFE05StockWing2S, dPTFE05StockWing2Transform2);
    G4SubtractionSolid* pPTFE05StockWing2 = new G4SubtractionSolid("pPTFE05StockWing2", pPTFE05StockWing2Sub2, pPTFE05StockWing2S, dPTFE05StockWing2Transform3);

    G4SubtractionSolid* pPTFE05StockCylinder1Sub1 = new G4SubtractionSolid("pPTFE05StockCylinder1Sub1",pPTFE05StockWing1,pPTFE04StockCylinder1S,dPTFE05StockCylinder1Transform1);
    G4SubtractionSolid* pPTFE05StockCylinder1Sub2 = new G4SubtractionSolid("pPTFE05StockCylinder1Sub2",pPTFE05StockCylinder1Sub1,pPTFE05StockCylinder1S,dPTFE05StockCylinder1Transform2);
    G4SubtractionSolid* pPTFE05StockCylinder1Sub3 = new G4SubtractionSolid("pPTFE05StockCylinder1Sub3",pPTFE05StockCylinder1Sub2,pPTFE05StockCylinder1S,dPTFE05StockCylinder1Transform3);
    G4SubtractionSolid* pPTFE05StockCylinder1Sub4 = new G4SubtractionSolid("pPTFE05StockCylinder1Sub4",pPTFE05StockCylinder1Sub3,pPTFE05StockCylinder1S,dPTFE05StockCylinder1Transform4);
    G4SubtractionSolid* pPTFE05StockCylinder1Sub5 = new G4SubtractionSolid("pPTFE05StockCylinder1Sub5",pPTFE05StockCylinder1Sub4,pPTFE05StockCylinder1S,dPTFE05StockCylinder1Transform5);
    G4SubtractionSolid*     pPTFE05StockCylinder1 = new G4SubtractionSolid("pPTFE05StockCylinder1",pPTFE05StockCylinder1Sub5,pPTFE05StockCylinder1S,dPTFE05StockCylinder1Transform6);

    G4SubtractionSolid* pPTFE05StockCylinder2 = new G4SubtractionSolid("pPTFE05StockCylinder2",pPTFE05StockCylinder1,pPTFE05StockCylinder2S,dPTFE05StockCylinder2Transform);

    // Create PTFE05
    pPTFE05LV = new G4LogicalVolume(pPTFE05StockWing2Sub1, G4Material::GetMaterial("PTFE"), "PTFE05");
    pPTFE05PV = new G4PVPlacement(0, dPTFE05StockPlacement, pPTFE05LV, "PTFE05", pMotherLV, false, 0);
    G4LogicalVolume* test = new G4LogicalVolume(pPTFE05StockWing2S, G4Material::GetMaterial("PTFE"), "test");
    G4VPhysicalVolume* testpv = new G4PVPlacement(0, testPlacement, test, "test", pMotherLV, false, 0);

    //////////////////////
    // Construct PTFE06 //
    //////////////////////

    // Set PTFE06 Stock Variables
    G4double dPTFE06StockInnerRadius = 0.0 * mm;
    G4double dPTFE06StockOuterRadius = 37.0 * mm;
    G4double dPTFE06StockHeight = 5.0 * mm;

   // Set Subtraction Solid Variables
    G4double dPTFE06PMTSignalFTBoxLength  = 17.0 * mm;
    G4double dPTFE06PMTSignalFTBoxWidth   = 19.6 * mm;
    G4double  dPTFE06PMTSignalFTBoxHeight = 2.0 * dPTFE06StockHeight;

    G4double dPTFE06PMTSignalFTTubInnerRadius = 3.17 * mm;
    G4double dPTFE06PMTSignalFTTubOuterRadius = dPTFE06PMTSignalFTTubInnerRadius + 5.0 * mm;
    G4double dPTFE06PMTSignalFTTubHeight      = 2.0 * dPTFE06PMTSignalFTBoxHeight;

    G4double dPTFE06PMTSignalFTX1 = dPTFE06PMTSignalFTTubInnerRadius + 0.005 * mm - 0.5 * dPTFE06PMTSignalFTBoxLength;
    G4double dPTFE06PMTSignalFTX2 = -dPTFE06PMTSignalFTX1;
    G4double dPTFE06PMTSignalFTY1 = 0.5 * dPTFE06PMTSignalFTBoxWidth - dPTFE06PMTSignalFTTubInnerRadius - 0.005 * mm;
    G4double dPTFE06PMTSignalFTY2 = -dPTFE06PMTSignalFTY1;
    G4double  dPTFE06PMTSignalFTZ = 0.00 * mm;

    G4double dPTFE06SubX1 = -15.0 * mm;
    G4double dPTFE06SubX2 = -dPTFE06SubX1;
    G4double dPTFE06SubY1 = 15.0 * mm;
    G4double dPTFE06SubY2 = -dPTFE06SubY1;
    G4double dPTFE06SubZ = 0.00 * mm;

    G4RotationMatrix dPTFE06SubRot;
    dPTFE06SubRot.rotateZ(0.00);

    G4ThreeVector dPTFE06PMTSignalFTXYZ1(dPTFE06PMTSignalFTX1,dPTFE06PMTSignalFTY1,dPTFE06PMTSignalFTZ);
    G4RotationMatrix dPTFE06PMTSignalFTRot1;
    dPTFE06PMTSignalFTRot1.rotateZ(0.5 * M_PI);
    G4Transform3D dPTFE06PMTSignalFTTransform1(dPTFE06PMTSignalFTRot1, dPTFE06PMTSignalFTXYZ1);

    G4ThreeVector dPTFE06PMTSignalFTXYZ2(dPTFE06PMTSignalFTX2,dPTFE06PMTSignalFTY1,dPTFE06PMTSignalFTZ);
    G4RotationMatrix dPTFE06PMTSignalFTRot2;
    dPTFE06PMTSignalFTRot2.rotateZ(0.00);
    G4Transform3D dPTFE06PMTSignalFTTransform2(dPTFE06PMTSignalFTRot2, dPTFE06PMTSignalFTXYZ2);

    G4ThreeVector dPTFE06PMTSignalFTXYZ3(dPTFE06PMTSignalFTX2,dPTFE06PMTSignalFTY2,dPTFE06PMTSignalFTZ);
    G4RotationMatrix dPTFE06PMTSignalFTRot3;
    dPTFE06PMTSignalFTRot3.rotateZ(1.5 * M_PI);
    G4Transform3D dPTFE06PMTSignalFTTransform3(dPTFE06PMTSignalFTRot3, dPTFE06PMTSignalFTXYZ3);

    G4ThreeVector dPTFE06PMTSignalFTXYZ4(dPTFE06PMTSignalFTX1,dPTFE06PMTSignalFTY2,dPTFE06PMTSignalFTZ);
    G4RotationMatrix dPTFE06PMTSignalFTRot4;
    dPTFE06PMTSignalFTRot4.rotateZ(M_PI);
    G4Transform3D dPTFE06PMTSignalFTTransform4(dPTFE06PMTSignalFTRot4, dPTFE06PMTSignalFTXYZ4);

    G4ThreeVector dPTFE06SubXYZ1(dPTFE06SubX1,dPTFE06SubY1,dPTFE06SubZ);
    G4Transform3D dPTFE06SubTransform1(dPTFE06SubRot, dPTFE06SubXYZ1);

    G4ThreeVector dPTFE06SubXYZ2(dPTFE06SubX2,dPTFE06SubY1,dPTFE06SubZ);
    G4Transform3D dPTFE06SubTransform2(dPTFE06SubRot, dPTFE06SubXYZ2);

    G4ThreeVector dPTFE06SubXYZ3(dPTFE06SubX2,dPTFE06SubY2,dPTFE06SubZ);
    G4Transform3D dPTFE06SubTransform3(dPTFE06SubRot, dPTFE06SubXYZ3);

    G4ThreeVector dPTFE06SubXYZ4(dPTFE06SubX1,dPTFE06SubY2,dPTFE06SubZ);
    G4Transform3D dPTFE06SubTransform4(dPTFE06SubRot, dPTFE06SubXYZ4);

    // Set PTFE06 Placement Values
    G4double dPTFE06PlacementX = 0.00 * mm;
    G4double dPTFE06PlacementY = 0.00 * mm;
    G4double dPTFE06PlacementZ = dPTFE05StockPlacementZ + 40 * mm;
    G4ThreeVector dPTFE06Placement(dPTFE06PlacementX, dPTFE06PlacementY, dPTFE06PlacementZ);
  
    // Create Subtraction Solids
    G4Box*  pPTFE06PMTSignalFTBox = new G4Box("PTFE06PMTSignalFTBox", 0.5 * dPTFE06PMTSignalFTBoxLength, 0.5 * dPTFE06PMTSignalFTBoxWidth, 0.5 * dPTFE06PMTSignalFTBoxHeight);
    G4Tubs* pPTFE06PMTSignalFTTub = new G4Tubs("PTFE06PMTSignalFTTub", dPTFE06PMTSignalFTTubInnerRadius, dPTFE06PMTSignalFTTubOuterRadius, 0.5 * dPTFE06PMTSignalFTTubHeight, 0, 0.5 * M_PI);
    
    G4SubtractionSolid* pPTFE06PMTSignalFTSub1 = new G4SubtractionSolid("pTFE06PMTSignalFTSub1", pPTFE06PMTSignalFTBox, pPTFE06PMTSignalFTTub, dPTFE06PMTSignalFTTransform1);
    G4SubtractionSolid* pPTFE06PMTSignalFTSub2 = new G4SubtractionSolid("pTFE06PMTSignalFTSub2", pPTFE06PMTSignalFTSub1, pPTFE06PMTSignalFTTub, dPTFE06PMTSignalFTTransform2);
    G4SubtractionSolid* pPTFE06PMTSignalFTSub3 = new G4SubtractionSolid("pTFE06PMTSignalFTSub3", pPTFE06PMTSignalFTSub2, pPTFE06PMTSignalFTTub, dPTFE06PMTSignalFTTransform3);
    G4SubtractionSolid*     pPTFE06PMTSignalFT = new G4SubtractionSolid("pTFE06PMTSignalFT", pPTFE06PMTSignalFTSub3, pPTFE06PMTSignalFTTub, dPTFE06PMTSignalFTTransform4);

    G4Tubs* pPTFE06Stock = new G4Tubs("PTFE06Stock", dPTFE06StockInnerRadius, dPTFE06StockOuterRadius, 0.5 * dPTFE06StockHeight, 0, 2 * M_PI);

    G4SubtractionSolid* pPTFE06Sub1 = new G4SubtractionSolid("pPTFE06Sub1", pPTFE06Stock, pPTFE06PMTSignalFT, dPTFE06SubTransform1);
    G4SubtractionSolid* pPTFE06Sub2 = new G4SubtractionSolid("pPTFE06Sub2", pPTFE06Sub1, pPTFE06PMTSignalFT, dPTFE06SubTransform2);
    G4SubtractionSolid* pPTFE06Sub3 = new G4SubtractionSolid("pPTFE06Sub3", pPTFE06Sub2, pPTFE06PMTSignalFT, dPTFE06SubTransform3);
    G4SubtractionSolid*     pPTFE06 = new G4SubtractionSolid("pPTFE06", pPTFE06Sub3, pPTFE06PMTSignalFT, dPTFE06SubTransform4);

    // Create PTFE06
    pPTFE06LV = new G4LogicalVolume(pPTFE06, G4Material::GetMaterial("PTFE"), "PTFE06");
//    pPTFE06PV = new G4PVPlacement(0, dPTFE06Placement, pPTFE06LV, "PTFE06", pMotherLV, false, 0);

    ////////////////////////
    // Construct PMT Ring //
    ////////////////////////

    // Set PMTRing Variables
    G4double dPMTRingRadius1 = 37.69 * mm;
    G4double dPMTRingRadius2 = 41.5 * mm;
    G4double dPMTRingHeight  = 2.48 * mm;

    // Set PMTRing Placement Values
    G4double dPMTRingPlacementX = 0.00 * mm;
    G4double dPMTRingPlacementY = 0.00 * mm;
    G4double dPMTRingPlacementZ = dPTFE01StockPlacementZ + dPTFE01StockHeight9 - 0.5 * dPMTRingHeight;

    G4ThreeVector dPMTRingPlacement(dPMTRingPlacementX, dPMTRingPlacementY, dPMTRingPlacementZ);

    // Create PMTRing
    G4Tubs* pPMTRing = new G4Tubs("PMTRing", dPMTRingRadius1, dPMTRingRadius2, 0.5 * dPMTRingHeight, 0, 2 * M_PI);
    pPMTRingLV = new G4LogicalVolume(pPMTRing, G4Material::GetMaterial("Stainless Steel"), "PMTRing");
//    pPMTRingPV = new G4PVPlacement(0, dPMTRingPlacement, pPMTRingLV, "PMTRing", pMotherLV, false, 0);

    //////////////////////////
    // Construct Grid Rings //
    //////////////////////////

    // Set Ring Variables
    G4double dGridRadius1 = 35.915 * mm;
    G4double dGridRadius2 = 40.915 * mm;
    G4double dGridHeight  = 2.48 * mm;

    // Create Grid solid and LV
    G4Tubs* pGrid = new G4Tubs("Grid", dGridRadius1, dGridRadius2, 0.5 * dGridHeight, 0, 2 * M_PI);
    pGridLV = new G4LogicalVolume(pGrid, G4Material::GetMaterial("Stainless Steel"), "Grid");

    // Set Placement Variables
    G4double dGridPlacementX = 0.00 * mm;
    G4double dGridPlacementY = 0.00 * mm;

    G4double dCathodePlacementZ = dPTFE01StockPlacementZ + dPTFE01StockHeight3 + 0.5 * dGridHeight;
    G4double dGatePlacementZ = dPTFE02StockPlacementZ + dPTFE02StockHeight3 + 0.5 * dGridHeight;
    G4double dAnodePlacementZ = dPTFE03StockPlacementZ + dPTFE03StockHeight3 + 0.5 * dGridHeight;
    G4double dScreeningMeshPlacementZ = dPTFE04StockPlacementZ + dPTFE04StockHeight3 + 0.5 * dGridHeight;

    G4ThreeVector  dCathodePlacement(dGridPlacementX, dGridPlacementY, dCathodePlacementZ);
    G4ThreeVector  dGatePlacement(dGridPlacementX, dGridPlacementY, dGatePlacementZ);
    G4ThreeVector  dAnodePlacement(dGridPlacementX, dGridPlacementY, dAnodePlacementZ);
    G4ThreeVector  dScreeningMeshPlacement(dGridPlacementX, dGridPlacementY, dScreeningMeshPlacementZ);

    // Create PVs
//    pCathodePV = new G4PVPlacement(0, dCathodePlacement, pGridLV, "Cathode", pMotherLV, false, 0);
//    pGatePV = new G4PVPlacement(0, dGatePlacement, pGridLV, "Gate", pMotherLV, false, 0);
//    pAnodePV = new G4PVPlacement(0, dAnodePlacement, pGridLV, "Anode", pMotherLV, false, 0);
//    pScreeningMeshPV = new G4PVPlacement(0, dScreeningMeshPlacement, pGridLV, "Screening Mesh", pMotherLV, false, 0);

    // Give the pieces color and shape
    G4VisAttributes * pPTFE00VisAtt = new G4VisAttributes(G4Colour::White());
    pPTFE00VisAtt->SetForceSolid(true);
    pPTFE00LV->SetVisAttributes(pPTFE00VisAtt);

    G4VisAttributes * pPTFE01VisAtt = new G4VisAttributes(G4Colour::White());
    pPTFE01VisAtt->SetForceSolid(true);
    pPTFE01LV->SetVisAttributes(pPTFE01VisAtt);

    G4VisAttributes * pPTFE02VisAtt = new G4VisAttributes(G4Colour::White());
    pPTFE02VisAtt->SetForceSolid(true);
    pPTFE02LV->SetVisAttributes(pPTFE02VisAtt);

    G4VisAttributes * pPTFE03VisAtt = new G4VisAttributes(G4Colour::White());
    pPTFE03VisAtt->SetForceSolid(true);
    pPTFE03LV->SetVisAttributes(pPTFE03VisAtt);

    G4VisAttributes * pPTFE04VisAtt = new G4VisAttributes(G4Colour::White());
    pPTFE04VisAtt->SetForceSolid(true);
    pPTFE04LV->SetVisAttributes(pPTFE04VisAtt);

    G4VisAttributes * pPTFE05VisAtt = new G4VisAttributes(G4Colour::White());
    pPTFE05VisAtt->SetForceSolid(true);
    pPTFE05LV->SetVisAttributes(pPTFE05VisAtt);

    G4VisAttributes * testVisAtt = new G4VisAttributes(G4Colour::Red());
    testVisAtt->SetForceSolid(true);
    test->SetVisAttributes(testVisAtt);

    G4VisAttributes * pPTFE06VisAtt = new G4VisAttributes(G4Colour::White());
    pPTFE06VisAtt->SetForceSolid(true);
    pPTFE06LV->SetVisAttributes(pPTFE06VisAtt);

    G4VisAttributes * pPMTRingVisAtt = new G4VisAttributes(G4Colour::Gray());
    pPMTRingVisAtt->SetForceSolid(true);
    pPMTRingLV->SetVisAttributes(pPMTRingVisAtt);

    G4VisAttributes * pGridVisAtt = new G4VisAttributes(G4Colour::Gray());
    pGridVisAtt->SetForceSolid(true);
    pGridLV->SetVisAttributes(pGridVisAtt);

}

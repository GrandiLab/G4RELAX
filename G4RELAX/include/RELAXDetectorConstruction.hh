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
    std::map<G4String, G4Material*>* GetMaterialTable();

    // List of Volumes
    G4LogicalVolume* pMotherLV;

    G4LogicalVolume* pLaboratoryLV;
    G4VPhysicalVolume* pLaboratoryPV;

    G4LogicalVolume* pPTFE00LV;
    G4VPhysicalVolume* pPTFE00PV;
    G4LogicalVolume* pPTFE01LV;
    G4VPhysicalVolume* pPTFE01PV;
    G4LogicalVolume* pPTFE02LV;
    G4VPhysicalVolume* pPTFE02PV;
    G4LogicalVolume* pPTFE03LV;
    G4VPhysicalVolume* pPTFE03PV;
};

#endif

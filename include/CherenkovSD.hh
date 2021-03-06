//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// Yakov Kulinich
//
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#ifndef CherenkovSD_h
#define CherenkovSD_h 1

#include "G4VSensitiveDetector.hh"
#include "CherenkovHit.hh"

#include "TH1D.h"
#include "TH2D.h"
#include "TH3D.h"
#include "LinkDef.h"
#include <vector>
class SharedData;
class G4Step;
class G4HCofThisEvent;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class CherenkovSD : public G4VSensitiveDetector
{
public:
  CherenkovSD(G4String, SharedData*, int modNumber);
  ~CherenkovSD();

  void HistInitialize();
 
  void Initialize(G4HCofThisEvent*);
  G4bool ProcessHits(G4Step*, G4TouchableHistory*);
  void EndOfEvent(G4HCofThisEvent*);

private:
  SharedData* m_sd;
  
  CherenkovHitsCollection* radiatorCollection;
  int HCID;
  int fModNumber;
  //  TH2D* h2_radNum_eDep;
  int         fTrackID;
  int         fModNb;
  int         fRadNb;
  double      fEdep;
  int         fPid;
  double      fX;
  double      fY;
  double      fZ;
  double      fPx;
  double      fPy;
  double      fPz;
  int         fEventNo;  
  double      fEnergy;
  double      fCharge;
  int         fModNRadiators[5];
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif


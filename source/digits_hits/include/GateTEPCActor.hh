/*----------------------
  Copyright (C): OpenGATE Collaboration

  This software is distributed under the terms
  of the GNU Lesser General  Public Licence (LGPL)
  See LICENSE.md for further details
  ----------------------*/

/* ---------------------------------------------------------------------------- *
 *                                                                              *
 *  Class Description :                                                         *
 *                                                                              *
 *  Record the lineal energy distribution generated by radiation in a           *
 *  Tissue Equivalent Proportional Counter (TEPC) used for microdosimetric      *
 *  measurements                                                                *
 *                                                                              *
 *  Version 1.0 2017/02/08 Francois SMEKENS LPC Clermont-ferrand                *
 * -----------------------------------------------------------------------------*/

#include "GateConfiguration.h"
#ifdef G4ANALYSIS_USE_ROOT

/*!
  \class  GateTEPCActor
  \author francois.smekens@clermont.in2p3.fr
*/

#ifndef GATETEPCACTOR_HH
#define GATETEPCACTOR_HH

#include "GateVActor.hh"
#include "GateActorMessenger.hh"
#include "GateDiscreteSpectrum.hh"

#include <TROOT.h>
#include <TFile.h>
#include <TH1.h>

//-----------------------------------------------------------------------------
/// \brief Actor recording the linear energy distribution in a TEPC-like volume
class GateTEPCActor : public GateVActor
{
public:

  virtual ~GateTEPCActor();

  //-----------------------------------------------------------------------------
  // This macro initialize the CreatePrototype and CreateInstance
  FCT_FOR_AUTO_CREATOR_ACTOR(GateTEPCActor)

  //-----------------------------------------------------------------------------
  // Constructs the sensor
  virtual void Construct();

  //-----------------------------------------------------------------------------
  // Callbacks
  virtual void BeginOfRunAction(const G4Run * r);
  virtual void BeginOfEventAction(const G4Event *) ;
  virtual void UserSteppingAction(const GateVVolume *, const G4Step*);

  virtual void PreUserTrackingAction(const GateVVolume *, const G4Track*) ;
  virtual void PostUserTrackingAction(const GateVVolume *, const G4Track*) ;
  virtual void EndOfEventAction(const G4Event*);

  //-----------------------------------------------------------------------------
  /// Saves the data collected to the file
  virtual void SaveData();
  virtual void ResetData();

  virtual void Initialize(G4HCofThisEvent*){}
  virtual void EndOfEvent(G4HCofThisEvent*){}

  void BuildMaterial(double);
  
  //-----------------------------------------------------------------------------
  /// Set parameters
  double GetPressure() { return mPressure; }
  double GetEmin() { return mEmin; }
  double GetEmax() { return mEmax; }
  int GetEBinNumber()  { return mEBinNumber; }
  bool GetELogscale() { return mELogscale; }
  bool GetNormByEvent() { return mNormByEvent; }

  //-----------------------------------------------------------------------------
  /// Get parameters
  void SetEmin(double v) { mEmin = v; }
  void SetEmax(double v) { mEmax = v; }
  void SetEBinNumber(int v) { mEBinNumber = v; }
  void SetELogscale(bool v) { mELogscale = v; }
  void SetENOrders(int v) { mENOrders = v; }
  void SetNormByEvent(bool v) { mNormByEvent = v; }
  void SetSaveAsText(bool v) { mSaveAsText = v; }

protected:
  GateTEPCActor(G4String name, G4int depth=0);

  // ROOT file output
  TFile *pTfile;  
  TH1D  *pLETspectrum;
  
  // User parameters
  double mPressure;
  double mEmin;
  double mEmax;
  int mEBinNumber;
  bool mELogscale;
  int mENOrders;
  bool mNormByEvent;
  bool mSaveAsText;
  
  // Temporary parameters
  int eventNumber;
  double edepByEvent;
  bool newEvent;
  double effectiveChord;
  
  GateActorMessenger* pMessenger;


};

MAKE_AUTO_CREATOR_ACTOR(TEPCActor,GateTEPCActor)


#endif /* end #define GATETEPCACTOR_HH */
#endif

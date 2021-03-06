// -*- C++ -*-
//
// Package:     SiStripMonitorSummary
// Class  :     SiStripMonitorCondDataOnDemandExample
// 
// Original Author:  Evelyne Delmeire
//


#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include "DQM/SiStripMonitorSummary/interface/SiStripMonitorCondDataOnDemandExample.h"
#include "DQM/SiStripMonitorSummary/interface/SiStripClassToMonitorCondData.h"

#include "TH1F.h"
#include "TH2F.h"
#include "TProfile.h"

// std
#include <cstdlib>
#include <string>
#include <cmath>
#include <numeric>
#include <algorithm>


//
// ----- Constructor
//
SiStripMonitorCondDataOnDemandExample::SiStripMonitorCondDataOnDemandExample(edm::ParameterSet const& iConfig):conf_(iConfig){}
// -----



//
// ----- Destructor
// 
SiStripMonitorCondDataOnDemandExample::~SiStripMonitorCondDataOnDemandExample(){}
// -----




//
// ----- beginRun
//    
void SiStripMonitorCondDataOnDemandExample::beginRun(edm::Run const& run, edm::EventSetup const& eSetup) {  
  eventCounter_=0;
  condDataMonitoring_ = new SiStripClassToMonitorCondData(conf_);
  condDataMonitoring_->beginRun(eSetup);
  
  

} // beginRun
// -----



//
// ----- beginJob
//
void SiStripMonitorCondDataOnDemandExample::beginJob(void){} //beginJob



//
// ----- Analyze
//
void SiStripMonitorCondDataOnDemandExample::analyze(edm::Event const& iEvent, edm::EventSetup const& eSetup){
  //eventCounter_++; 

  // on demand type I : eventSetup and detId to be passed
  // output : ME's corresponding to that detId
  
  
  //if(eventCounter_==1){ condDataMonitoring_ -> getModMEsOnDemand(eSetup,369125542);}
  
  // on demand type II : eventSetup, subdetector-type(TIB/TOB/TEC/TID), 
  //                                 subdetector-side for TEC/TID (0 for TIB and TOB)
  //                                 layer_number (0=all layers)
 
  //if(eventCounter_==2){ condDataMonitoring_ -> getLayerMEsOnDemand(eSetup,"TEC",0,1);}
  //condDataMonitoring_ -> getModMEsOnDemand(eSetup,369125542);
  condDataMonitoring_ -> getLayerMEsOnDemand(eSetup,"TEC",2,4);

  
  
} // analyze
// -----



//
// ----- endRun
//    
void SiStripMonitorCondDataOnDemandExample::endRun(edm::Run const& run, edm::EventSetup const& eSetup) {

  condDataMonitoring_->endRun(eSetup);       

} // endRun
// -----



//
// ----- endJob
//
void SiStripMonitorCondDataOnDemandExample::endJob(void){} //endJob


#include "FWCore/Framework/interface/MakerMacros.h"
  DEFINE_FWK_MODULE(SiStripMonitorCondDataOnDemandExample);

  

#include "TH1F.h"
#include "TChain.h"
#include "TBranch.h"
#include "TROOT.h"
#include "TSystem.h"
#include "TClonesArray.h"

// #ifdef __CLING__
R__LOAD_LIBRARY(libDelphes)
#include "classes/DelphesClasses.h"
#include "external/ExRootAnalysis/ExRootTreeReader.h"
// #endif

#include <iostream>

void HbbHbb_PhaseII_Analysis_RealTalk()
{
  gSystem->Load("libDelphes");

  std::string inputfilename="Samples/delphes/gfhhbbbb_mad_925001.root";
  TChain *chain=new TChain("Delphes");
  chain->Add(inputfilename.c_str());
  std::cout<<"Opened input file "<<inputfilename<<std::endl;
  
  // Create object of class ExRootTreeReader
  ExRootTreeReader *treeReader = new ExRootTreeReader(chain);
  Long64_t numberOfEntries = treeReader->GetEntries();
  std::cout<<"numberOfEntries = "<<numberOfEntries<<std::endl;
  
  // Get pointers to branches used in this analysis
  TClonesArray *branchParticle = treeReader->UseBranch("Particle");
  
  for (Int_t i=0; i<numberOfEntries; ++i)
  {
    treeReader->ReadEntry(i);
    
    Int_t nParticles=branchParticle->GetEntries();
    std::cout<<"nParticles = "<<nParticles<<std::endl;
  }
      
}

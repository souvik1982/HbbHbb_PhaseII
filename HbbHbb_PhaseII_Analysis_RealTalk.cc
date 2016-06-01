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

double jet_btag_cut=4;

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
  TClonesArray *b_Jet = treeReader->UseBranch("Jet");
  
  for (Int_t i_event=0; i_event<numberOfEntries; ++i_event)
  {
    treeReader->ReadEntry(i_event);
    
    std::cout<<"Event "<<i_event<<std::endl;
    int nCBjets=0;
    for (Int_t i_jet=0; i_jet<b_Jet->GetEntries(); ++i_jet)
    {
      Jet *jet = (Jet*)b_Jet->At(0);
      
      std::cout<<"Jet pT = "<<jet->PT<<std::endl;
      std::cout<<"Jet eta = "<<jet->Eta<<std::endl;
      std::cout<<"Jet btag = "<<jet->BTag<<std::endl;
    }
    std::cout<<" === "<<std::endl;
  }
      
}

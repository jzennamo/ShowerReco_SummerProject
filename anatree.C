#define anatree_cxx
#include "anatree.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void anatree::Loop()
{
//   To execute this code you will do this:
//      > root -l
//      Root > .L anatree.C
//  (or to compile :  Root > .L anatree.C+)
//      Root > anatree t
//      Root > t.Loop();       // Loop on all entries

  TH1F* StartPointOffset = new TH1F("startpointoffset","; Start Point Offset (cm); Number", 50, 0, 1000);

   if (fChain == 0) return;

   /// Define how many entries are in the tree:
   /// Start
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   ///End 


   /// Here we START to loop over all entries in the TTree
   /// these are events, so be careful how you think of these events
   /// Start
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
   /// End
      
      std::cout << "\n ########################### \n Looking at Event == " << jentry << std::endl; 

      /* List of useful variables that you might want to look at:

	 event -- this is what you call event number
	 subrun -- this is what you call subrun

	 RECONSTRUCTION INFORMATION:
	 nshowers -- The number of reconstruted showers (N) 
	 showerID[N] -- A unique shower ID, just a number (int)
	 shwr_bestplane[N] -- The plane that has the largest (spatial) projection of hits, this is the P you should use typically 
	 shwr_length[N] -- The length of the shower in blah dimensions
	 shwr_startdcosx[N] -- the "i" component of the unit vector describing the direction
	 shwr_startdcosy[N] -- the "j" component of the unit vector describing the direction
	 shwr_startdcosz[N] -- the "k" component of the unit vector describing the direction
	 shwr_startx[N] -- the "x" posistion start point 
	 shwr_starty[N] -- the "y" posistion start point 
	 shwr_startz[N] -- the "z" posistion start point 
	 shwr_totEng[N][P] -- The total energy of the shower in plane P (focus on P == 2 for now)
	 shwr_mipEng[N][P] -- The total energy of the shower in plane P (focus on P == 2 for now)
	 shwr_dedx[N][P] -- The total energy deposited at the start of the shower 

	 MC TRUTH INFORMATION: 
	 geant_list_size -- The number of particles (N), you will usually only be intrested in the first particle 
         pdg[N] -- The pdg of the n-th particle in the list
	 Eng[N] -- The TRUE energy of the n-th particle 
	 Px[N] -- X-projection of the n-th particle momentum
	 Py[N] -- Y-projection of the n-th particle momentum
	 Pz[N] -- Z-projection of the n-th particle momentum
	 P[N] -- n-th particle momentum
	 StartPointx[N] -- X-projection of the n-th start point
	 StartPointy[N] -- Y-projection of the n-th start point
	 StartPointz[N] -- X-projection of the n-th start point
	 theta[N] -- The theta of the n-th particle 
	 phi[N] -- the phi of the n-th paritlce 
      */

      //Here you will build your code, build whatever you want! MUHAHAHAHAHAHAHAHAHAHAHAHA@

      //// EXAMPLE loop through all reco showers in event

	  
	  // This is to calculate the distance between the starting point of the shower and the MC
      if(nshowers == 1){	
		  
		  if (pdg == 22){

			  // distance formula
			  double dist = sqrt(pow((shwr_startx[0] - EndPointx[0]), 2) + pow((shwr_starty[0] - EndPointy[0]), 2) + pow((shwr_startz[0] - EndPointz[0]), 2));
		  }
		  else
		  {
			  double dist = sqrt(pow((shwr_startx[0] - StartPointx[0]), 2) + pow((shwr_starty[0] - StartPointy[0]), 2) + pow((shwr_startz[0] - EndPointz[0]), 2));
		  }
	// Histogram (TH1F)  -> Fill(var) [function, var] 
		StartPointOffset->Fill(dist);
	
		std::cout << "X difference: " << fabs(shwr_startx[0] - EndPointx[0])  << std::endl;
		std::cout << "Y difference: " <<  fabs(StartPointy[0] - EndPointy[0]) << std::endl;
		std::cout << "Z difference: " << fabs(StartPointz[0] - EndPointz[0]) << std::endl;

      }

	e max_eng = 0;
	int max_N = 0;

	// Number of Showers
	














	/*
	  // This is to find showers that are not fully reconstructed


		double distfromstart = 0;
		double particledist = 0;
		double particlenum = 0;
		
		for (int i = 1; i <= N; i++)
		  {
				 if (pdg[i] == 13 || pdg[i] == -13)
				  {
					  if (pdg[0] == 22)
					  {
						  particledist = sqrt(pow(EndPointx[0] - EndPointx[i], 2) + pow(EndPointy[0] - EndPointy[i], 2) + pow(EndPointz[0] - EndPointz[i], 2));
					  }
					  else (pdg[0] == 13)
					  {
						  particledist = sqrt(pow(StartPointx[0] - EndPointx[i], 2) + pow(StartPointy[0] - EndPointy[i], 2) + pow(StartPointz[0] - EndPointz[i], 2));
					  }
				  }

				  if (distfromstart < particledist)
				  {
					  distfromstart = particledist;
				  }
				 
		  }
		  
	doubl
	for(int n = 0; n < nshowers; n++){
	double temp_eng = shwr_totEng[n][2]; 
	
	if(max_eng < temp_eng) {max_eng = temp_eng; max_N = n;}
	
	}
      */
      ////// END

   /// Here is the end of the loop
   /// Start
   }
   /// End

   TFile *f = new TFile("Awesome_Shower_Reco_Vetting_Booyah.root", "RECREATE");
   
   StartPointOffset->Write();
   f->Write();
   f->Close();
  

}

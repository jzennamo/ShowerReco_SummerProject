#define anatree_cxx
#include "anatree.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>


void anatree::Loop(Long64_t max_entry)
{
	//   To execute this code you will do this:
	//      > root -l
	//      Root > .L anatree.C
	//  (or to compile :  Root > .L anatree.C+)
	//      Root > anatree t
	// (or add a file: Root > anatree t("eminus/blahblah.root")  )
	//      Root > t.Loop();       // Loop on all entries
	// (or small number of events: Root > t.Loop(500)  )


	TH1F* StartPointOffset = new TH1F("startpointoffset", "; Start Point Offset (cm); Number", 50, 0, 1000);
	TH1F* NumShowers = new TH1F("Number_of_Showers", "; Shower Number; Number of Events", 5, 0, 5);
	TH1F* ParticleDist = new TH1F("Particle_Distance ", "; Particle Distance; Number of Particles", 50, 50, 1650);
	TH1F* xAngleOffset = new TH1F("X_angle_Offset ", "; Angle; Number of Particles", 20, 0, 360);
	TH1F* yAngleOffset = new TH1F("Y_angle_Offset ", "; Angle; Number of Particles", 20, 0, 360);
	TH1F* zAngleOffset = new TH1F("Z_angle_Offset ", "; Angle; Number of Particles", 20, 0, 360);
	TH1F* GoodReco = new TH1F("Good Reco ", "; Angle; Number of Particles", 20, 0, 360);


	if (fChain == 0) return;

	/// Define how many entries are in the tree:
	/// Start
	Long64_t nentries = fChain->GetEntriesFast();
	Long64_t nbytes = 0, nb = 0;
	if (max_entry == -1) max_entry = nentries;
	///End 


	/// Here we START to loop over all entries in the TTree
	/// these are events, so be careful how you think of these events
	/// Start
	for (Long64_t jentry = 0; jentry < nentries && jentry < max_entry; jentry++) {
		Long64_t ientry = LoadTree(jentry);
		if (ientry < 0) break;
		nb = fChain->GetEntry(jentry);   nbytes += nb;
		/// End
		if ((jentry % 1000) == 0){ std::cout << "\t\t\t ### " << int(100 * jentry / nentries) << "% done !" << std::endl; }


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
		if (nshowers == 1)
		{
			if (pdg == 22)
			{
				// distance formula
				double dist = sqrt(pow((shwr_startx[0] - EndPointx[0]), 2) + pow((shwr_starty[0] - EndPointy[0]), 2) + pow((shwr_startz[0] - EndPointz[0]), 2));
			}
			else if (pdg == -13 || pdg == 13)
			{
				double dist = sqrt(pow((shwr_startx[0] - StartPointx[0]), 2) + pow((shwr_starty[0] - StartPointy[0]), 2) + pow((shwr_startz[0] - EndPointz[0]), 2));
			}
			
			// Histogram (TH1F)  -> Fill(var) [function, var] 
			StartPointOffset->Fill(dist);

			// std::cout << "X difference: " << fabs(shwr_startx[0] - EndPointx[0]) << std::endl;
			// std::cout << "Y difference: " << fabs(StartPointy[0] - EndPointy[0]) << std::endl;
			// std::cout << "Z difference: " << fabs(StartPointz[0] - EndPointz[0]) << std::endl;
		}


		// Number of Showers

		NumShowers->Fill(nshowers);
		// std::cout << "Number of Showers: " << nshowers << std::endl << std::endl;

		// go through every particle in the shower and find its energy relative to the total energy and find out how far it travels



		// find photons with large energy in the shower

		for (int i = 1; i < geant_list_size; i++)
		{
			if (Eng[i] >= Eng[0] * 0.05 && pdg[i] == 22)
			{
				double particledist = sqrt(pow((StartPointx[i] - StartPointx[0]), 2) + pow((StartPointy[i] - StartPointy[0]), 2) + pow((StartPointz[i] - StartPointz[0]), 2));
			}

			ParticleDist->Fill(particledist);
		}

		//use momentum to calculate the mc angle and then compare it to the other shwr angle and create three plots (one for each plane)
		
				float cx_angle = Px[0] / P[0];
				float cy_angle = Py[0] / P[0];
				float cz_angle = Pz[0] / P[0];

				float xdiff = fabs(shwr_startdcosx[0] - cx_angle);
				float ydiff = fabs(shwr_startdcosy[0] - cy_angle);
				float zdiff = fabs(shwr_startdcosz[0] - cz_angle);

				const double minangle = TMath::Cos(5 * 180 /3.14);

				if (xdiff > minangle)
				{
					xAngleOffset->Fill(xdiff*180/3.14);
				}
				
				if (ydiff > minangle)
				{
					yAngleOffset->Fill(ydiff*180/3.14);
				}
				if (zdiff > minangle)
				{
					zAngleOffset->Fill(zdiff*180/3.14);
				}
	   
		// good reconstructed showers
		// must have correct shower direction and shower starting position

				if (nshowers == 1)
				{
					if (pdg == 22)
					{
						// distance formula
						double dist = sqrt(pow((shwr_startx[0] - EndPointx[0]), 2) + pow((shwr_starty[0] - EndPointy[0]), 2) + pow((shwr_startz[0] - EndPointz[0]), 2));
					}
					else if (pdg == -13 || pdg == 13)
					{
						double dist = sqrt(pow((shwr_startx[0] - StartPointx[0]), 2) + pow((shwr_starty[0] - StartPointy[0]), 2) + pow((shwr_startz[0] - EndPointz[0]), 2));
					}

					// Histogram (TH1F)  -> Fill(var) [function, var] 
					Goodreco->Fill(dist);
				}
	   /*

	   // figure out distance between showers but i need a shower end variable...

	    
	   if (nshowers > 1)
	   {
	   for (int i = 0; i < nshowers; i++)
	   {
	   for (int j = i+1; j < i; j++)
	   {
	   // distance between the end of the first shower and the beginning of the second shower
	   shwrdistdiff = shwrendx
	   shwrdist = sqrt(pow((shwr_startx[0] - EndPointx[0]), 2) + pow((shwr_starty[0] - EndPointy[0]), 2) + pow((shwr_startz[0] - EndPointz[0]), 2));
	   }
	   }
	   }

	   // This is to find showers that are not fully reconstructed


	   double distfromstart = 0;
	   double particledist = 0;
	   double particlenum = 0;

	   // calculating length of MC
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

	   double
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
   NumShowers->Write();
   ParticleDist->Write();
   xAngleOffset->Write();
   yAngleOffset->Write();
   zAngleOffset->Write();

   f->Write();
   f->Close();
}

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

	TH1F* StartPointOffset = new TH1F("Start_Point_Offset", "Start Point Offset; Distance(cm); Number of Events", 25, 0, 1000);	//how far off is the shower start from the MC start; plot distance in m
	TH1F* NumShowers = new TH1F("Number_of_Showers", "; Number of showers; Number of Events", 6, -0.5, 5.5);		// plot number of showers
	TH1F* PhotonDist = new TH1F("Photon_Distance", "; Photon Distance(cm); Number of Particles", 50, 50, 2000);	// how far does a brem photon travel
	//TH1F* xAngleOffset = new TH1F("X_angle_Offset ", "; Angle(degrees); Number of Particles", 360, 0, 360);		// how far off is the direction in the x plane in degrees
	//TH1F* yAngleOffset = new TH1F("Y_angle_Offset ", "; Angle(degrees); Number of Particles", 360, 0, 360);		// how far off is the direction in the x plane in degrees
	//TH1F* zAngleOffset = new TH1F("Z_angle_Offset ", "; Angle(degrees); Number of Particles", 360, 0, 360);		// how far off is the direction in the x plane in degrees

	TH1F* StartPointOffsetGoodReco = new TH1F("start_Point_offset_Good_Reco", "; Start Point Offset(cm); Number", 100, 0, 360);
	//TH1F* yAngleOffsetGoodReco = new TH1F("Y_angle_Offset_Good_Reco ", "; Angle(degrees); Number of Particles", 360, 0, 100);
	//TH1F* xAngleOffsetGoodReco = new TH1F("X_angle_Offset_Good_Reco ", "; Angle(degrees); Number of Events", 360, 0 0, 360);
	//TH1F* zAngleOffsetGoodReco = new TH1F("Z_angle_Offset_Good_Reco ", "; Angle(degrees); Number of Particles", 360, 0, 360);

	TH1F* NumShowersGoodRecoEng = new TH1F("Energy_One_Good_Shower", "; Energy(MeV); Number of Events", 25, 100, 2000);
	TH1F* NumShowersBadRecoEng = new TH1F("Energy_One_Bad_Shower", "; Energy(MeV); Number of Events", 25, 100, 2000);
	TH1F* Energy = new TH1F("Energy", "; Energy(MeV); Number of Events", 25, 100, 2000);
	//TH1F* XAngleGoodRecoEng = new TH1F("X_angle_Good_Reco_Energy ", "; Energy(MeV); Number of Events", 25, 100, 2000);
	//TH1F* YAngleGoodRecoEng = new TH1F("Y_angle_Good_Reco_Energy ", "; Energy(MeV); Number of Events", 25, 100, 2000);
	//TH1F* ZAngleGoodRecoEng = new TH1F("Z_angle_Good_Reco_Energy ", "; Energy(MeV); Number of Events", 25, 100, 2000);
	//TH1F* DistGoodRecoEng = new TH1F("Distance_Good_Reco_Energy ", "; Energy(MeV); Number of Events", 25, 100, 2000);
	TH1F* BremphotonEng = new TH1F("Brem_Energy ", "; Energy(MeV); Number of Events", 25, 100, 2000);
	TH1F* NoShowerEng = new TH1F("No_Shower_Energy ", "Energy of Events with No Reconstructed Showers; Energy(MeV); Number of Events", 25, 100, 2000);
	TH1F* StartPointOffsetGoodRecoEng = new TH1F("Start_Point_Offset_Good_Reco_Eng", "; Energy(MeV); Number of Events", 25, 100, 2000);
	TH1F* SuperStartPointOffsetGoodRecoEng = new TH1F("Super_Start_Point_Offset_Good_Reco_Eng", "; Energy(MeV); Number of Events", 25, 100, 2000);

	TH1F* MoreThanOneShowerEng = new TH1F("MoreThanOneShowerEng ", "; Energy(MeV); Number of Events", 25, 100, 2000);

	TH1F* GoodRecoEng = new TH1F("Good_Reco ", "Energy of Good Reconstructed Showers; Energy(MeV); Number of Events", 25, 100, 2000);
	TH1F* AngleGoodRecoEng = new TH1F("Angle_Good_Reco_Energy ", " Energy of Showers with Good Reconstructed Angles; Energy(MeV); Number of Events", 25, 100, 2000);

	TH1F* ShowersGoodRecoEng = new TH1F("Showers_Good_Reco ", "Energy of Good Reconstructed Showers; Energy(MeV); Number of Events", 25, 100, 2000);

	TH1F* EffShowersGoodRecoEng = new TH1F("ShowersEffGoodRecoEng", ";Energy(MeV); ", 25, 100, 2000); // GoodRecoEng/Energy

	TH1F* EffNumShowers = new TH1F("EffNumShowers", "; Energy(MeV);", 25, 100, 2000); // Efficiency of at Least One Reconstructed Shower
	TH1F* EffDist = new TH1F("EffDist", ";Energy(MeV);", 25, 100, 2000); // StartPointOffsetGoodRecoEng/Energy
	TH1F* EffSuperDist = new TH1F("EffSuperDist", ";Energy(MeV);", 25, 100, 2000); // StartPointOffsetGoodRecoEng/Energy

	TH1F* EffGoodRecoEng = new TH1F("EffGoodRecoEng", ";Energy(MeV); ", 25, 100, 2000); // GoodRecoEng/Energy
	TH1F* EffNoShowerEng = new TH1F("EffNoShowerEng", "; Energy(MeV); ", 25, 100, 2000); // NoShowerEng/Energy
	// TH1F* EffStartPointEng = new TH1F("EffStartPointEng", " Efficiency of Showers with Good Start Point Offset;Energy(MeV); ", 25, 100, 2000); // StartPointOffsetGoodRecoEng/Energy

	TH1F* MisshalfShowerEng = new TH1F("MisshalfShowerEng ", "; Energy(MeV); Number of Events", 25, 100, 2000);

	TH1F* GoodRecoTrueEng = new TH1F("GoodRecoTrueEng ", "; Energy(MeV); Number of Events", 25, 100, 2000);
	TH1F* GoodRecoDiffEng = new TH1F("GoodRecoDiffEng ", "; Difference(MeV); Number of Events", 25, -1000, 1000);

	TH1F* MissBegShowerEng = new TH1F("MissBegShowerEng ", "; Energy(MeV); Number of Events", 25, 100, 2000);

	//TH1F* DiffxAngle = new TH1F("Diff_xAngle", "; Angle(degrees); Number of Particles", 360, -360, 360);
	//TH1F* DiffyAngle = new TH1F("Diff_yAngle", "; Angle(degrees); Number of Particles", 360, -360, 360);
	//TH1F* DiffzAngle = new TH1F("Diff_zAngle", "; Angle(degrees); Number of Particles", 360, -360, 360);


	TH1F* Diffxdist = new TH1F("Diffxdist", "Shower Start - MC Start (x Direction); Distance(cm); Number of Events", 300, -3, 3);
	TH1F* Diffydist = new TH1F("Diffydist", "Shower Start - MC Start (y Direction); Distance(cm); Number of Events", 300, -3, 3);
	TH1F* Diffzdist = new TH1F("Diffzdist", "Shower Start - MC Start (z Direction); Distance(cm); Number of Events", 300, -3, 3);

	TH1F* DiffMCxdist = new TH1F("DiffMCxdist", "Shower Start - MC Shower Start (x Direction); Distance(cm); Number of Events", 300, -3, 3);
	TH1F* DiffMCydist = new TH1F("DiffMCydist", "Shower Start - MC Shower Start (y Direction); Distance(cm); Number of Events", 300, -3, 3);
	TH1F* DiffMCzdist = new TH1F("DiffMCzdist", "Shower Start - MC Shower Start (z Direction); Distance(cm); Number of Events", 300, -3, 3);

	TH1F* DiffMCCombxdist = new TH1F("DiffMCCombxdist", "Shower Start - MC Shower Comb Start (x Direction); Distance(cm); Number of Events", 300, -3, 3);
	TH1F* DiffMCCombydist = new TH1F("DiffMCCombydist", "Shower Start - MC Shower Comb Start (y Direction); Distance(cm); Number of Events", 300, -3, 3);
	TH1F* DiffMCCombzdist = new TH1F("DiffMCCombzdist", "Shower Start - MC Shower Comb Start (z Direction); Distance(cm); Number of Events", 300, -3, 3);


	TH1F* Showerstartx = new TH1F("Showerstartx", "; Distance(cm); Number of Events", 30, -100, 300);
	TH1F* Showerstarty = new TH1F("Showerstarty", "; Distance(cm); Number of Events", 30, -300, 300);
	TH1F* Showerstartz = new TH1F("Showerstartz", "; Distance(cm); Number of Events", 30, -100, 1000);

	TH1F* MCstartx = new TH1F("MCstartx", "; Distance(cm); Number of Events", 30, -100, 300);
	TH1F* MCstarty = new TH1F("MCstarty", "; Distance(cm); Number of Events", 30, -300, 300);
	TH1F* MCstartz = new TH1F("MCstartz", "; Distance(cm); Number of Events", 30, -100, 1000);

	THStack * ShowerEnergy = new THStack("Shower", "");
	THStack * ShowerEnergy1 = new THStack("Shower1", "");

	THStack * ShowerAngle = new THStack("ShowerAngle", "");

	TH1F* NoShowerAng = new TH1F("No_Shower_Angle ", "Angle of Events with No Reconstructed Showers; Angle(Degrees); Number of Events", 360, 0, 360);
	TH1F* NumShowersGoodRecoAng = new TH1F("NumShowersGoodRecoAng", "; Angle(Degrees); Number of Events", 360, 0, 360);
	TH1F* MoreThanOneShowerAng = new TH1F("MoreThanOneShowerAng ", "; Angle(Degrees); Number of Events", 360, 0, 360);

	//TH1F* TotalEng = new TH1F("TotalEng ", "; Energy(MeV); Number of Events", 100, 0, 2000);
	//TH1F* ChargedPartEng = new TH1F("ChargedPartEng ", "; Energy(MeV); Number of Events", 100, 0, 2000);

	//TH1F* DiffTotalEng = new TH1F("DiffTotalEng ", "; Energy(MeV); Number of Events", 100, -1000, 1000);
	//TH1F* DiffChargedPartEng = new TH1F("DiffChargedPartEng ", "; Energy(MeV); Number of Events", 100, -1000, 1000);

	TH1F* Nshowersratioeng = new TH1F("Nshowersratioeng ", "; Energy(MeV); Number of Events", 25, 100, 2000);

	TH1F* xzdiffang = new TH1F("xzdiffang ", "; theta_xz (Degrees); Number of Events", 180, 0, 180);
	TH1F* yzdiffang = new TH1F("yzdiffang ", "; theta_yz (Degrees); Number of Events", 180, 0, 180);
	
	TH1F* OneShowerxzAng = new TH1F("OneShowerxzAng ", "; Angle(Degrees); Number of Events", 60, 0, 360);
	TH1F* OneShoweryzAng = new TH1F("OneShoweryzAng ", "; Angle(Degrees); Number of Events", 60, 0, 360);

	TH1F* MoreThanOneShowerxzAng = new TH1F("MoreThanOneShowerxzAng ", "; Angle(Degrees); Number of Events", 60, 0, 360);
	TH1F* MoreThanOneShoweryzAng = new TH1F("MoreThanOneShoweryzAng ", "; Angle(Degrees); Number of Events", 60, 0, 360);

	TH1F* XZ_angle = new TH1F("XZ_angle ", "; Angle(Degrees); Number of Events", 36, -180, 180);
	TH1F* YZ_angle = new TH1F("YZ_angle ", "; Angle(Degrees); Number of Events", 36, -180, 180);

	TH1F* ActualEng = new TH1F("ActualEng ", "; Energy(MeV); Number of Events", 25, 100, 2000);

	TH1F* MCxzangle = new TH1F("MCxzangle ", "; Angle(Degrees); Number of Events", 36, -180, 180);
	TH1F* MCyzangle = new TH1F("MCyzangle ", "; Angle(Degrees); Number of Events", 36, -180, 180);


	TH1F* DistTPC1 = new TH1F("DistTPC1", "; Distance; Number of Events", 50, -500, 500);
	TH1F* Disttot1 = new TH1F("Disttot1", "; Distance; Number of Events", 50, -500, 500);

	TH1F* DistTPC0 = new TH1F("DistTPC0", "; Distance; Number of Events", 50, -500, 500);
	TH1F* Disttot0 = new TH1F("Disttot0", "; Distance; Number of Events", 50, -500, 500);

	TH1F* noshowerstartx = new TH1F("noshowerstartx", "; Distance; Number of Events", 50, -500, 500);
	TH1F* oneshowerstartx = new TH1F("oneshowerstartx", "; Distance; Number of Events", 50, -500, 500);

	TH1F* noshowerenergy = new TH1F("noshowerenergy ", "; Energy(MeV); Number of Events", 25, 100, 2000);
	TH1F* atleastoneshowereng = new TH1F("atleastoneshowereng ", "; Energy(MeV); Number of Events", 25, 100, 2000);
	
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
		if ((jentry % 1000) == 0){ std::cout << "\t\t\t ### " << int(100 * jentry / nentries) << "% done!" << std::endl; }


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
		   phi[N] -- the phi of the n-th particle
		   */

		//Here you will build your code, build whatever you want! MUHAHAHAHAHAHAHAHAHAHAHAHA@

		//// EXAMPLE loop through all reco showers in event


		// define boolean variables
		bool Nshowers = false;		// true if the number of showers is 1 
		bool Dist = false;			// true if the shower start is within 2.5 cm of MC start
		//bool Xangle = false;		// true if the x angle is within 5 degrees
		//bool Yangle = false;		// true if the y angle is within 5 degrees
		//bool Zangle = false;		// true if the z angle is within 5 degrees
		bool Bremphoton = false;	// true if the photon has at least 5% of the total shower energy
		bool Angle = false;			// true if all three angles are within 5 degrees
		bool XZAngle = false;		// true if the xz angle is within the minangle
		bool YZAngle = false;		// true if the yz angle is within th minangle

		double dist = 0;					// starting position distance from MC start
		double EngMeV = Eng[0] * 1000;		// Energy of the first particle in MeV
		
		double mindistance = 2.5;			// min distance that shower start can be from MC start
		double radtodegrees = 180 / 3.14;	// conversion factor
		double minangle = 15;				// minumum angle that is considered not too far off from actual

		// This is to calculate the distance between the starting point of the shower and the MC
		// any number of showers greater than zero

		double tempdist = 0;				// variable to help find the shortest distance of a shower to the MC start
		int goodshowernumber = 0;			// variables that saves the "best" shower...the shower that is closest to the MC start
		if (nshowers > 0)
		{

			if (pdg[0] == 22)			// photon
			{
				// distance formula
				dist = sqrt(pow((shwr_startx[0] - EndPointx[0]), 2) + pow((shwr_starty[0] - EndPointy[0]), 2) + pow((shwr_startz[0] - EndPointz[0]), 2));
			}

			else	// electron or positron
			{
				// distance formula
				dist = sqrt(pow((shwr_startx[0] - StartPointx[0]), 2) + pow((shwr_starty[0] - StartPointy[0]), 2) + pow((shwr_startz[0] - StartPointz[0]), 2));

			}

			goodshowernumber = 0;
			//std::cout << "shower number: " << nshowers << std::endl;
			//std::cout << "first shower dist: " << dist << std::endl;
			if (nshowers > 1)
			{
				for (int i = 1; i < nshowers; i++)
				{
					if (pdg[0] == 22)			// photon
					{
						// distance formula
						tempdist = sqrt(pow((shwr_startx[i] - EndPointx[0]), 2) + pow((shwr_starty[i] - EndPointy[0]), 2) + pow((shwr_startz[i] - EndPointz[0]), 2));
					}

					else	// electron or positron
					{
						// distance formula
						tempdist = sqrt(pow((shwr_startx[i] - StartPointx[0]), 2) + pow((shwr_starty[i] - StartPointy[0]), 2) + pow((shwr_startz[i] - StartPointz[0]), 2));

					}

					//std::cout << "temp shower dist: " <<  tempdist << std::endl;
				
					if (dist > tempdist)
					{
						dist = tempdist;
						goodshowernumber = i;
					}
				
				}
			}
			//std::cout << "final shower dist: " << dist << std::endl << std::endl;
			StartPointOffset->Fill(dist);
		
			double MCxz_angle = TMath::ATan2(Px[0] / P[0], Pz[0] / P[0]);
			double MCyz_angle = TMath::ATan2(Py[0] / P[0], Pz[0] / P[0]);

			double mag = sqrt(pow(shwr_startdcosx[goodshowernumber], 2) + pow(shwr_startdcosy[goodshowernumber], 2) + pow(shwr_startdcosz[goodshowernumber], 2));
			double xz_angle = TMath::ATan2(shwr_startdcosx[goodshowernumber] / mag, shwr_startdcosz[goodshowernumber] / mag);
			double yz_angle = TMath::ATan2(shwr_startdcosy[goodshowernumber] / mag, shwr_startdcosz[goodshowernumber] / mag);

			double xzdiff = fabs((xz_angle - MCxz_angle) * radtodegrees);
			double yzdiff = fabs((yz_angle - MCyz_angle) * radtodegrees);


			if (xzdiff >= 180)
			{
				xzdiff = 360 - xzdiff;
			}

			if (yzdiff >= 180)
			{
				yzdiff = 360 - yzdiff;
			}

			xzdiffang->Fill(xzdiff);
			yzdiffang->Fill(yzdiff);

		}

		// Histogram (TH1F)  -> Fill(var) [function, var] 
	
		if (nshowers == 0)
		{

			//std::cout << "dist: " << dist << std::endl;
			//std::cout << "shwr: " << shwr_startx[0] << std::endl;
			//std::cout << "endp: " << StartPointx[0] << stdl::endl;
			//std::cout << "show: " << nshowers << std::endl << std::endl;

			noshowerstartx->Fill(shwr_startx[0]);
			//noshowshoweng->Fill(shwr_totEng)
			//std::cout << "shower number: " << nshowers << std::endl;
			//std::cout << "shower energy: " << shwr_totEng[0][0] << std::endl;
			noshowerenergy->Fill(shwr_totEng[0][0]);
		}

		if (nshowers == 1)
		{
			oneshowerstartx->Fill(shwr_startx[0]);
		}
		
		Showerstartx->Fill(shwr_startx[0]);
		Showerstarty->Fill(shwr_starty[0]);
		Showerstartz->Fill(shwr_startz[0]);

		MCstartx->Fill(StartPointx[0]);
		MCstarty->Fill(StartPointy[0]);
		MCstartz->Fill(StartPointz[0]);

		/*
		  std::cout << "X difference: " << fabs(shwr_startx[0] - EndPointx[0]) << std::endl;
		  std::cout << "Y difference: " << fabs(StartPointy[0] - EndPointy[0]) << std::endl;
		  std::cout << "Z difference: " << fabs(StartPointz[0] - EndPointz[0]) << std::endl;

		  */

		// Number of Showers
		NumShowers->Fill(nshowers);

		// go through every particle in the shower and find its energy relative to the total energy and find out how far it travels
		// find photons with large energy in the shower
		// catastrophic brem
		for (int i = 1; i < geant_list_size; i++)	// checks every particle in the event
		{
			if (Eng[i] >= Eng[0] * 0.05 && pdg[i] == 22)	// if photon has 5% or more of the total energy
			{
				// calculate distance
				Bremphoton = true;
				double photondist = sqrt(pow((StartPointx[i] - StartPointx[0]), 2) + pow((StartPointy[i] - StartPointy[0]), 2) + pow((StartPointz[i] - StartPointz[0]), 2));

				PhotonDist->Fill(photondist);
			}

			// if it is a brem photon then put it in the histogram
			if (Bremphoton)
			{
				BremphotonEng->Fill(EngMeV);
				Bremphoton = false;
			}
		}

			// use momentum to calculate the MC angle and then compare it to the other shower angle and create three plots (one for each plane)
			// cosine of the angle

			//double cx_angle = Px[0] / P[0];
			//double cy_angle = Py[0] / P[0];
			//double cz_angle = Pz[0] / P[0];

			//std::cout << "MCxz_angle: " << MCxz_angle << std::endl;
			//std::cout << "theta_xz[0]: " << theta_xz[0] << std::endl;
			//std::cout << "MCyz_angle: " << MCyz_angle << std::endl;
			//std::cout << "theta_yz[0]: " << theta_yz[0] << std::endl;

			// difference in angle between the shower start and the MC start
			//double xdiff = fabs(TMath::ACos(shwr_startdcosx[0]) - TMath::ACos(cx_angle));
			//double ydiff = fabs(TMath::ACos(shwr_startdcosy[0]) - TMath::ACos(cy_angle));
			//double zdiff = fabs(TMath::ACos(shwr_startdcosz[0]) - TMath::ACos(cz_angle));

			// calculate the shower angle 

			/*
			double tempmag = 0;
			double tempxz_angle = 0;
			double tempyz_angle = 0;

			//std::cout << "x shower angle: " << shwr_startdcosx[0] << std::endl;
			for (int i = 1; i < nshowers; i++)
			{
				tempmag = sqrt(pow(shwr_startdcosx[i], 2) + pow(shwr_startdcosy[i], 2) + pow(shwr_startdcosz[i], 2));
				tempxz_angle = TMath::ATan2(shwr_startdcosx[i] / mag, shwr_startdcosz[i] / mag);
				tempyz_angle = TMath::ATan2(shwr_startdcosy[i] / mag, shwr_startdcosz[i] / mag);

				if (tempxz_angle < xz_angle)
				{
					xz_angle = tempxz_angle;
				}

				if (tempyz_angle < yz_angle)
				{
					yz_angle = tempyz_angle;
				}
			}
			*/
			//std::cout << theta_xz[0] << std::endl;

			//MCxzangle->Fill((MCxz_angle * radtodegrees));
			//MCyzangle->Fill((MCyz_angle * radtodegrees));

			//YZ_angle->Fill(yz_angle * radtodegrees);
			//XZ_angle->Fill(xz_angle * radtodegrees);

			// calculate the shower angle offset in degrees
			
	
		//std::cout << yz_angle << std::endl;
		//std::cout << theta_xz[0] << std::endl;

		// angles in degrees
		//xdiff = xdiff * radtodegrees;
		//ydiff = ydiff * radtodegrees;
		//zdiff = zdiff * radtodegrees;

		// fill in with the angle difference
		//xAngleOffset->Fill(xdiff);
		//yAngleOffset->Fill(ydiff);
		//zAngleOffset->Fill(zdiff);

		// good reconstructed showers
		// must have correct shower direction and shower starting position and only one shower
		if (nshowers == 1)	// only want one shower
		{
			Nshowers = true;
			NumShowersGoodRecoEng->Fill(EngMeV);	// if there is only one shower then plot the energy of that shower
			OneShowerxzAng->Fill(xzdiff);			// if there is only one shower then plot the xz diff angle
			OneShoweryzAng->Fill(yzdiff);			// if there is only one shower then plot the yz diff angle
		}

		if (dist <= mindistance)
		{
			Dist = true;
		}


		// starting position is within 2.5 cm (mindistance)
		if (Dist && Nshowers)
		{
			// Histogram (TH1F)  -> Fill(var) [function, var]
			StartPointOffsetGoodReco->Fill(dist);
			StartPointOffsetGoodRecoEng->Fill(EngMeV);
			//DistGoodRecoEng->Fill(EngMeV);

			if (dist < 1.0)
			{
				SuperStartPointOffsetGoodRecoEng->Fill(EngMeV);
			}
		}

	

		// if any of the angles is within the minimum angle then we want to add it to the histogram and make the bool true
		/*
		if (xdiff <= minangle)
		{
			Xangle = true;
			xAngleOffsetGoodReco->Fill(xdiff);
			XAngleGoodRecoEng->Fill(EngMeV);
		}

		if (ydiff <= minangle)
		{
			Yangle = true;
			yAngleOffsetGoodReco->Fill(ydiff);
			YAngleGoodRecoEng->Fill(EngMeV);
		}

		if (zdiff <= minangle)
		{
			Zangle = true;
			zAngleOffsetGoodReco->Fill(zdiff);
			ZAngleGoodRecoEng->Fill(EngMeV);
		}

		// if all three angles are within minangle then we make the bool variables Angle true
		if (Xangle && Yangle && Zangle)
		{
			AngleGoodRecoEng->Fill(EngMeV);
			Angle = true;
			Xangle = false;
			Yangle = false;
			Zangle = false;
		}

		*/

		if (xzdiff < minangle)
		{
			XZAngle = true;
		}

		if (yzdiff < minangle)
		{
			YZAngle = true;
		}

		if (XZAngle && YZAngle)
		{
			Angle = true;
		}

		if (nshowers == 0)
		{
			NoShowerEng->Fill(EngMeV);
			//NoShowerAng->Fill(xdiff);
		}

		// comparing the shower energy and the energy of the first particle
		// we want to make a stricter cut here
		// so the distance should be within 1.0 cm and the angle difference is within 1.0 degrees

		if (Nshowers && (dist <= 1.0) && xzdiff < 1.0 && yzdiff < 1.0)
		{
			GoodRecoTrueEng->Fill(shwr_totEng[0][shwr_bestplane[0]]);
			GoodRecoDiffEng->Fill(EngMeV - shwr_totEng[0][shwr_bestplane[0]]);
		}

		// we also want to compare the angle of the shower to the angle of the first particle
		// using the same cuts which are the distance is within 1.0 cm and only one shower

		
		if (Nshowers && Dist && Angle)
		{
			GoodRecoEng->Fill(EngMeV);
			//Angle = false;
		}

		if (nshowers > 0 && Dist && Angle)
		{
			ShowersGoodRecoEng->Fill(EngMeV);
		}

		if (Nshowers && !Dist && !Angle)
		{
			NumShowersBadRecoEng->Fill(EngMeV);
		}

		if (nshowers > 1)
		{
			MoreThanOneShowerEng->Fill(EngMeV);
			MoreThanOneShowerxzAng->Fill(xzdiff);
			MoreThanOneShoweryzAng->Fill(yzdiff);
		}
		
		// we also want to compare the starting position of the shower to the starting position of the first particle
		// any shower number
		if nshowers > 0)
		{
			if (pdg[0] == 22)
			{
				Diffxdist->Fill(shwr_startx[0] - EndPointx[0]);
				Diffydist->Fill(shwr_starty[0] - EndPointy[0]);
				Diffzdist->Fill(shwr_startz[0] - EndPointz[0]);
			}

			else if (pdg[0] == 11 || pdg[0] == -11)
			{
				Diffxdist->Fill(shwr_startx[0] - StartPointx[0]);
				Diffydist->Fill(shwr_starty[0] - StartPointy[0]);
				Diffzdist->Fill(shwr_startz[0] - StartPointz[0]);
			}
		}

		if (nshowers > 0)
		{
			DiffMCCombxdist->Fill(shwr_startx[0] - mcshwr_CombEngX[0]);
			DiffMCCombydist->Fill(shwr_starty[0] - mcshwr_CombEngY[0]);
			DiffMCCombzdist->Fill(shwr_startz[0] - mcshwr_CombEngZ[0]);

			DiffMCxdist->Fill(shwr_startx[0] - mcshwr_startX[0]);
			DiffMCydist->Fill(shwr_starty[0] - mcshwr_startY[0]);
			DiffMCzdist->Fill(shwr_startz[0] - mcshwr_startZ[0]);
		}


		//double toteng = 0;
		//double chargedtoteng = 0;

		double StartdistTPC = 0;
		double EnddistTPC = 0;
		double Startdisttot = 0;
		double Enddisttot = 0;

		double distTPC = 0;
		double disttot = 0;

		double actualenergy = 0;


		//if (Nshowers && (dist <= 1.0) && xdiff < 1.0 && ydiff < 1.0 && zdiff < 1.0)
		//{
			//toteng = 0;
			//chargedtoteng = 0;

		for (int i = 0; i < geant_list_size; i++)
		{
			//if (EndPointx_tpcAV[i] != -99999)
			//{
			StartdistTPC = sqrt(pow(StartPointx_tpcAV[i], 2) + pow(StartPointy_tpcAV[i], 2) + pow(StartPointz_tpcAV[i], 2));
			EnddistTPC = sqrt(pow(EndPointx_tpcAV[i], 2) + pow(EndPointy_tpcAV[i], 2) + pow(EndPointz_tpcAV[i], 2));

			Startdisttot = sqrt(pow(StartPointx[i], 2) + pow(StartPointy[i], 2) + pow(StartPointz[i], 2));
			Enddisttot = sqrt(pow(EndPointx[i], 2) + pow(EndPointy[i], 2) + pow(EndPointz[i], 2));

			distTPC = StartdistTPC - EnddistTPC;
			disttot = Startdisttot - Enddisttot;

			actualenergy += Eng[i] * distTPC / disttot;

			if (inTPCActive[i] == 1)
			{
				DistTPC1->Fill(distTPC);
				Disttot1->Fill(disttot);

				//std::cout << "1" << std::endl;
			}

			if (inTPCActive[i] == 0)
			{
				DistTPC0->Fill(distTPC);
				Disttot0->Fill(disttot);

				//std::cout << distTPC << std::endl;
				//std::cout << "0" << std::endl;
			}
			//}
		}
		/*
		for (int i = 0; i < geant_list_size; i++)
		{
			if (inTPCActive == 0 && EndPointx_tpcAV[i] != -99999)
			{
				std::cout << "inTPCActive: " << inTPCActive[i] << std::endl;
				std::cout << "start point x: " << EndPointx_tpcAV[i] << std::endl;
				std::cout << "start point y: " << EndPointy_tpcAV[i] << std::endl;
				std::cout << "start point z: " << EndPointz_tpcAV[i] << std::endl << std::endl;
			}
		}
		*/
			//ChargedPartEng += actualenergy;

			// energy deposited from the particle minus the rest energy
			// kinetic energy of the particle
			//chargedtoteng += Eng[i] - EndE[i];
		
		ActualEng->Fill(actualenergy);

		// particles that cross the boundary
		// what is their distance

					//if (!(EndPointx_tpcAV[i] == -99999))
					//{
						//toteng = toteng + Eng[i] - EndE[i];
						//std::cout << toteng << std::endl << std::endl;
					//}
				//}
			//}c1
			
			//std:cout << "initial energy: " << Eng[i] << std::endl;
			//std::cout << "final energy: " << EndE[i] * 1000 << std::endl << std::endl;
			//std::cout << "particle " << i << ": " << chargedtoteng << std::endl;


			//std::cout << "Shower Total Energy: " << jentry << " : " << shwr_totEng[0][shwr_bestplane[0]] << std::endl;
			//std::cout << "Charged Total Energy: " << jentry << " : " << chargedtoteng * 1000 << std::endl;
			//std::cout << "Total Energy within Detector: " << jentry << " : " << toteng * 1000 << std::endl << std::endl;

			//ChargedPartEng->Fill(chargedtoteng * 1000);
			//TotalEng->Fill(toteng * 1000);

			//DiffChargedPartEng->Fill(shwr_totEng[0][shwr_bestplane[0]] - chargedtoteng * 1000);
			//DiffTotalEng->Fill(shwr_totEng[0][shwr_bestplane[0]] - toteng * 1000);
		//}

		//std::cout << "x: " << EndPointx_tpcAV[i] << std::endl;
		//std::cout << "y: " << EndPointy_tpcAV[i] << std::endl;
		//std::cout << "z: " << EndPointz_tpcAV[i] << std::endl;
	
			if (nshowers == 0)
			{
				double ratio = double(geant_list_size_in_tpcAV / (1.0 * geant_list_size));
				//std::cout << ratio << std::endl;

				if (ratio < 0.25)
				{
					Nshowersratioeng->Fill(EngMeV);
				}
			}

		Angle = false;
		Nshowers = false;
		Dist = false;

		Energy->Fill(EngMeV);



		if (nshowers > 0)
		{
			atleastoneshowereng->Fill(EngMeV);
		}

		////// END

		/// Here is the end of the loop
		/// Start

	}

	/// End

	TFile *f = new TFile("Awesome_Shower_Reco_Vetting_Booyah.root", "RECREATE");

	StartPointOffset->Write();
	NumShowers->Write();
	PhotonDist->Write();
	//xAngleOffset->Write();
	//yAngleOffset->Write();
	//zAngleOffset->Write();

	StartPointOffsetGoodReco->Write();
	//xAngleOffsetGoodReco->Write();
	//yAngleOffsetGoodReco->Write();
	//zAngleOffsetGoodReco->Write();

	f->Write();
	f->Close();

	//gStyle->SetOptStat(0000);
	gStyle->SetPadBorderMode(0);

	//comment out gStyle and do hist->SetStats(true);
	

	TCanvas* c1 = new TCanvas("c1", "", 700, 700);
	c1->SetLeftMargin(.1);
	c1->SetBottomMargin(.1);
	c1->SetTopMargin(.075);
	c1->SetRightMargin(.15);
	c1->cd();

	//Line attributes: https://root.cern.ch/root/html/TAttLine.html
	//Color Choices: https://root.cern.ch/root/html/TColor.html

	NumShowers->SetLineColor(kBlue);
	NumShowers->SetLineWidth(3);
	//NumShowers->SetStats(false);
	NumShowers->Draw();

	//TLegend* leg = new TLegend(0.5, 0.82, 0.92, 0.98);
	//leg->SetFillColor(kWhite);
	//leg->SetTextSize(0.03);
	//leg->AddEntry(NumShowers, "Number of Showers", "l");
	//leg->Draw();

	TCanvas* c2 = new TCanvas("c2", "", 700, 700);
	c2->SetLeftMargin(.1);
	c2->SetBottomMargin(.1);
	c2->SetTopMargin(.075);
	c2->SetRightMargin(.15);
	c2->cd();

	Disttot1->SetLineColor(kBlack);
	Disttot1->SetLineWidth(3);
	Disttot1->Draw();

	DistTPC1->SetLineColor(kBlue);
	DistTPC1->SetLineWidth(3);
	DistTPC1->Draw("same");
	
	TCanvas* c3 = new TCanvas("c3", "", 700, 700);
	c3->SetLeftMargin(.1);
	c3->SetBottomMargin(.1);
	c3->SetTopMargin(.075);
	c3->SetRightMargin(.15);
	c3->cd();

	Disttot0->SetLineColor(kBlack);
	Disttot0->SetLineWidth(3);
	Disttot0->Draw();

	DistTPC0->SetLineColor(kBlue);
	DistTPC0->SetLineWidth(3);
	DistTPC0->Draw("same");
	
	TCanvas* c4 = new TCanvas("c4", "", 700, 700);
	c4->SetLeftMargin(.1);
	c4->SetBottomMargin(.1);
	c4->SetTopMargin(.075);
	c4->SetRightMargin(.15);
	c4->cd();

	Energy->SetLineColor(kGray);
	Energy->SetLineWidth(3);
	Energy->Draw();

	TLegend* leg = new TLegend(0.5, 0.82, 0.92, 0.98);
	leg->SetFillColor(kWhite);
	leg->SetTextSize(0.05);
	leg->AddEntry(Energy, "All Showers", "l");
	leg->Draw();

	TCanvas* c5 = new TCanvas("c5", "", 700, 700);
	c5->SetLeftMargin(.1);
	c5->SetBottomMargin(.1);
	c5->SetTopMargin(.075);
	c5->SetRightMargin(.15);
	c5->cd();

	BremphotonEng->SetLineColor(kBlue);
	BremphotonEng->SetLineWidth(3);
	BremphotonEng->Draw();

	TLegend* leg = new TLegend(0.5, 0.82, 0.92, 0.98);
	leg->SetFillColor(kWhite);
	leg->SetTextSize(0.03);
	leg->AddEntry(BremphotonEng, "Brem Photon Energy", "l");
	leg->Draw();

	TCanvas* c6 = new TCanvas("c6", "", 700, 700);
	c6->SetLeftMargin(.1);
	c6->SetBottomMargin(.1);
	c6->SetTopMargin(.075);
	c6->SetRightMargin(.15);
	c6->cd();

	NoShowerEng->SetLineColor(kBlue);
	NoShowerEng->SetLineWidth(3);
	NoShowerEng->Draw();

	TCanvas* c7 = new TCanvas("c7", "", 700, 700);
	c7->SetLeftMargin(.1);
	c7->SetBottomMargin(.1);
	c7->SetTopMargin(.075);
	c7->SetRightMargin(.15);
	c7->cd();

	OneShowerxzAng->SetLineColor(kBlack);
	OneShowerxzAng->SetLineWidth(3);
	OneShowerxzAng->Draw();

	//yAngleOffsetGoodReco->SetLineColor(kRed);
	//yAngleOffsetGoodReco->SetLineWidth(3);
	//yAngleOffsetGoodReco->SetLineStyle(4);
	//yAngleOffsetGoodReco->Draw("same");

	//TLegend* leg = new TLegend(0.5, 0.82, 0.92, 0.98);
	//leg->SetFillColor(kWhite);
	//leg->SetTextSize(0.03);
	//leg->AddEntry(yAngleOffset, "All Showers", "l");
	//leg->AddEntry(yAngleOffsetGoodReco, "Good Showers (y angle within 5 degrees)", "l");
	//leg->Draw();

	TCanvas* c8 = new TCanvas("c8", "", 700, 700);
	c8->SetLeftMargin(.1);
	c8->SetBottomMargin(.1);
	c8->SetTopMargin(.075);
	c8->SetRightMargin(.15);
	c8->cd();

	OneShoweryzAng->SetLineColor(kBlack);
	OneShoweryzAng->SetLineWidth(3);
	OneShoweryzAng->Draw();

	//zAngleOffsetGoodReco->SetLineColor(kRed);
	//zAngleOffsetGoodReco->SetLineWidth(3);
	//zAngleOffsetGoodReco->SetLineStyle(4);
	//zAngleOffsetGoodReco->Draw("same");

	//TLegend* leg = new TLegend(0.5, 0.82, 0.92, 0.98);
	//leg->SetFillColor(kWhite);
	//leg->SetTextSize(0.03);
	//leg->AddEntry(zAngleOffset, "All Showers", "l");
	//leg->AddEntry(zAngleOffsetGoodReco, "Good Showers (z angle within 5 degrees)", "l");
	//leg->Draw();
	

	TCanvas* c9 = new TCanvas("c9", "", 700, 700);
	c9->SetLeftMargin(.1);
	c9->SetBottomMargin(.1);
	c9->SetTopMargin(.075);
	c9->SetRightMargin(.15);
	c9->cd();

	EffNumShowers->Divide(atleastoneshowereng, Energy);

	EffNumShowers->SetLineColor(kRed);
	EffNumShowers->SetLineWidth(3);
	EffNumShowers->SetStats(false);
	EffNumShowers->Draw();

	TCanvas* c10 = new TCanvas("c10", "", 700, 700);
	c10->SetLeftMargin(.1);
	c10->SetBottomMargin(.1);
	c10->SetTopMargin(.075);
	c10->SetRightMargin(.15);
	c10->cd();

	EffDist->Divide(StartPointOffsetGoodRecoEng, Energy);

	EffDist->SetLineColor(kGreen);
	EffDist->SetLineWidth(3);
	EffDist->SetStats(false);
	EffDist->Draw();

	EffSuperDist->Divide(SuperStartPointOffsetGoodRecoEng, Energy);

	EffSuperDist->SetLineColor(kBlue);
	EffSuperDist->SetLineWidth(3);
	EffSuperDist->SetStats(false);
	EffSuperDist->Draw("same");


	TCanvas* c11 = new TCanvas("c11", "", 700, 700);
	c11->SetLeftMargin(.1);
	c11->SetBottomMargin(.1);
	c11->SetTopMargin(.075);
	c11->SetRightMargin(.15);
	c11->cd();

	GoodRecoEng->SetLineColor(kRed);
	GoodRecoEng->SetLineWidth(3);
	GoodRecoEng->Draw();

	TCanvas* c12 = new TCanvas("c12", "", 700, 700);
	c12->SetLeftMargin(.1);
	c12->SetBottomMargin(.1);
	c12->SetTopMargin(.075);
	c12->SetRightMargin(.15);
	c12->cd();

	EffGoodRecoEng->Divide(GoodRecoEng, Energy);

	EffGoodRecoEng->SetLineColor(kCyan + 2);
	EffGoodRecoEng->SetLineWidth(3);
	EffGoodRecoEng->SetStats(false);
	EffGoodRecoEng->Draw();

	EffShowersGoodRecoEng->Divide(ShowersGoodRecoEng, Energy);

	EffShowersGoodRecoEng->SetLineColor(kGreen);
	EffShowersGoodRecoEng->SetLineWidth(3);
	EffShowersGoodRecoEng->SetStats(false);
	EffShowersGoodRecoEng->Draw("same");

	/*
	TCanvas* c13 = new TCanvas("c13", "", 700, 700);
	c13->SetLeftMargin(.1);
	c13->SetBottomMargin(.1);
	c13->SetTopMargin(.075);
	c13->SetRightMargin(.15);
	c13->cd();

	Energy->SetLineColor(kGreen);
	Energy->SetLineWidth(3);
	Energy->SetMinimum(0);
	Energy->Draw();

	NumShowersGoodRecoEng->SetLineColor(kRed);
	NumShowersGoodRecoEng->SetLineWidth(3);
	NumShowersGoodRecoEng->Draw("same");

	GoodRecoEng->SetLineColor(kBlue);
	GoodRecoEng->SetLineWidth(3);
	GoodRecoEng->Draw("same");

	AngleGoodRecoEng->SetLineColor(kRed);
	AngleGoodRecoEng->SetLineWidth(3);
	AngleGoodRecoEng->SetLineStyle(4);
	AngleGoodRecoEng->Draw("same");

	StartPointOffsetGoodRecoEng->SetLineColor(kBlue);
	StartPointOffsetGoodRecoEng->SetLineWidth(3);
	StartPointOffsetGoodRecoEng->Draw("same");
	StartPointOffsetGoodRecoEng->SetLineStyle(3);

	TLegend* leg = new TLegend(0.5, 0.82, 0.92, 0.98);
	leg->SetFillColor(kWhite);
	leg->SetTextSize(0.03);
	leg->AddEntry(Energy, "All Showers", "l");
	leg->AddEntry(NumShowersGoodRecoEng, "One Shower", "l");
	leg->AddEntry(GoodRecoEng, "Good Reconstruction", "l");
	leg->AddEntry(AngleGoodRecoEng, "All angles within 5 degrees", "l");
	leg->AddEntry(StartPointOffsetGoodRecoEng, "Start within 2.5 cm", "l");
	leg->Draw();
	*/

	TCanvas* c14 = new TCanvas("c14", "", 700, 700);
	c14->SetLeftMargin(.1);
	c14->SetBottomMargin(.1);
	c14->SetTopMargin(.075);
	c14->SetRightMargin(.15);
	c14->cd();

	GoodRecoDiffEng->SetLineColor(kCyan + 2);
	GoodRecoDiffEng->SetLineWidth(3);
	GoodRecoDiffEng->Draw();

	TLegend* leg = new TLegend(0.5, 0.82, 0.92, 0.98);
	leg->SetFillColor(kWhite);
	leg->SetTextSize(0.03);
	leg->AddEntry(GoodRecoDiffEng, "Shower Energy - MC Energy", "l");
	leg->Draw();

	TCanvas* c15 = new TCanvas("c15", "", 700, 700);
	c15->SetLeftMargin(.1);
	c15->SetBottomMargin(.1);
	c15->SetTopMargin(.075);
	c15->SetRightMargin(.15);
	c15->cd();

	EffNoShowerEng->Divide(NoShowerEng, Energy);

	EffNoShowerEng->SetLineColor(kCyan + 2);
	EffNoShowerEng->SetLineWidth(3);
	EffNoShowerEng->SetStats(false);
	EffNoShowerEng->Draw();

	TCanvas* c16 = new TCanvas("c16", "", 700, 700);
	c16->SetLeftMargin(.1);
	c16->SetBottomMargin(.1);
	c16->SetTopMargin(.075);
	c16->SetRightMargin(.15);
	c16->cd();

	MoreThanOneShowerEng->SetLineColor(kGreen);
	MoreThanOneShowerEng->SetLineWidth(3);
	MoreThanOneShowerEng->Draw();

	TLegend* leg = new TLegend(0.5, 0.82, 0.92, 0.98);
	leg->SetFillColor(kWhite);
	leg->SetTextSize(0.03);
	leg->AddEntry(MoreThanOneShowerEng, "More Than One Shower Energy", "l");
	leg->Draw();

	TCanvas* c17 = new TCanvas("c17", "", 700, 700);
	c17->SetLeftMargin(.1);
	c17->SetBottomMargin(.1);
	c17->SetTopMargin(.075);
	c17->SetRightMargin(.15);
	c17->cd();

	StartPointOffset->SetLineColor(kRed);
	StartPointOffset->SetLineWidth(3);
	StartPointOffset->Draw();

	/* TCanvas* c18 = new TCanvas("c18", "", 700, 700);
	c18->SetLeftMargin(.1);
	c18->SetBottomMargin(.1);
	c18->SetTopMargin(.075);
	c18->SetRightMargin(.15);
	c18->cd();

	MissBegShowerEng->SetLineColor(kRed);
	MissBegShowerEng->SetLineWidth(3);
	MissBegShowerEng->Draw();

	TLegend* leg = new TLegend(0.5, 0.82, 0.92, 0.98);
	leg->SetFillColor(kWhite);
	leg->SetTextSize(0.03);
	leg->AddEntry(MissBegShowerEng, "Misses Beginning of Shower", "l");
	leg->Draw();
	*/


	TCanvas* c19 = new TCanvas("c19", "", 700, 700);
	c19->SetLeftMargin(.1);
	c19->SetBottomMargin(.1);
	c19->SetTopMargin(.075);
	c19->SetRightMargin(.15);
	c19->cd();

	MoreThanOneShowerxzAng->SetLineColor(kRed);
	MoreThanOneShowerxzAng->SetLineWidth(3);
	MoreThanOneShowerxzAng->SetStats(true);
	MoreThanOneShowerxzAng->Draw();

	//TLegend* leg = new TLegend(0.5, 0.82, 0.92, 0.98);
	//leg->SetFillColor(kWhite);
	//leg->SetTextSize(0.03);
	//leg->AddEntry(DiffxAngle, "x Angle Offset", "l");
	//leg->Draw();

	
	TCanvas* c20 = new TCanvas("c20", "", 700, 700);
	c20->SetLeftMargin(.1);
	c20->SetBottomMargin(.1);
	c20->SetTopMargin(.075);
	c20->SetRightMargin(.15);
	c20->cd();

	MoreThanOneShoweryzAng->SetLineColor(kRed);
	MoreThanOneShoweryzAng->SetLineWidth(3);
	MoreThanOneShoweryzAng->SetStats(true);
	MoreThanOneShoweryzAng->Draw();

	//TLegend* leg = new TLegend(0.5, 0.82, 0.92, 0.98);
	//leg->SetFillColor(kWhite);
	//leg->SetTextSize(0.03);
	//leg->AddEntry(DiffyAngle, "y Angle Offset", "l");
	//leg->Draw();
	
	TCanvas* c21 = new TCanvas("c21", "", 700, 700);
	c21->SetLeftMargin(.1);
	c21->SetBottomMargin(.1);
	c21->SetTopMargin(.075);
	c21->SetRightMargin(.15);
	c21->cd();

	ActualEng->SetLineColor(kRed);
	ActualEng->SetLineWidth(3);
	ActualEng->SetStats(true);
	ActualEng->Draw();
	
	
	TCanvas* c22 = new TCanvas("c22", "", 700, 700);
	c22->SetLeftMargin(.1);
	c22->SetBottomMargin(.1);
	c22->SetTopMargin(.075);
	c22->SetRightMargin(.15);
	c22->cd();

	Diffxdist->SetLineColor(kBlue);
	Diffxdist->SetLineWidth(3);
	Diffxdist->SetStats(true);
	Diffxdist->Draw();

	TCanvas* c23 = new TCanvas("c23", "", 700, 700);
	c23->SetLeftMargin(.1);
	c23->SetBottomMargin(.1);
	c23->SetTopMargin(.075);
	c23->SetRightMargin(.15);
	c23->cd();

	Diffydist->SetLineColor(kBlue);
	Diffydist->SetLineWidth(3);
	Diffydist->SetStats(true);
	Diffydist->Draw();

	TCanvas* c24 = new TCanvas("c24", "", 700, 700);
	c24->SetLeftMargin(.1);
	c24->SetBottomMargin(.1);
	c24->SetTopMargin(.075);
	c24->SetRightMargin(.15);
	c24->cd();

	Diffzdist->SetLineColor(kBlue);
	Diffzdist->SetLineWidth(3);
	Diffzdist->SetStats(true);
	Diffzdist->Draw();
	
	TCanvas* c25 = new TCanvas("c25", "", 700, 700);
	c25->SetLeftMargin(.1);
	c25->SetBottomMargin(.1);
	c25->SetTopMargin(.075);
	c25->SetRightMargin(.15);
	c25->cd();

	//Energy->SetLineColor(kRed);
	//Energy->SetFillColor(kRed);
	//Energy->SetLineWidth(3);
	//Energy->SetMinimum(0);
	//Energy->Draw();

	NoShowerEng->SetFillColor(kBlue);
	NoShowerEng->SetLineColor(kBlue);
	NoShowerEng->SetStats(false);
	ShowerEnergy->Add(NoShowerEng);

	NumShowersGoodRecoEng->SetFillColor(kGray);
	NumShowersGoodRecoEng->SetLineColor(kGray);
	NumShowersGoodRecoEng->SetStats(false);
	ShowerEnergy->Add(NumShowersGoodRecoEng);

	MoreThanOneShowerEng->SetFillColor(kGreen);
	MoreThanOneShowerEng->SetLineColor(kGreen);
	MoreThanOneShowerEng->SetStats(false);
	ShowerEnergy->Add(MoreThanOneShowerEng);

	
	//NumShowersGoodRecoEng->SetFillColor(kGray);
	

	//NumShowersBadRecoEng->SetFillColor(kCyan + 2);
	//ShowerEnergy->Add(NumShowersBadRecoEng);

	//GoodRecoEng->SetFillColor(kRed);
	//GoodRecoEng->SetLineColor(kRed);
	//ShowerEnergy->Add(GoodRecoEng);

	ShowerEnergy->Draw();


	TLegend* leg = new TLegend(0.5, 0.82, 0.92, 0.98);
	leg->SetFillColor(kWhite);
	leg->SetTextSize(0.03);
	//leg->AddEntry(Energy, "Events with Any Number of Showers", "l");
	leg->AddEntry(MoreThanOneShowerEng, "Events with More than One Shower", "l");
	leg->AddEntry(NoShowerEng, "Events with No Shower", "l");
	leg->AddEntry(NumShowersGoodRecoEng, "Events with One Shower", "l");
	leg->Draw();

	TCanvas* c26 = new TCanvas("c26", "", 700, 700);
	c26->SetLeftMargin(.1);
	c26->SetBottomMargin(.1);
	c26->SetTopMargin(.075);
	c26->SetRightMargin(.15);
	c26->cd();

	//Energy->SetLineColor(kGray);
	//Energy->SetFillColor(kGray);
	//Energy->SetLineWidth(3);
	//Energy->SetMinimum(0);
	//Energy->SetMaximum(1000);
	//Energy->Draw();

	NumShowersGoodRecoAng->SetLineColor(kGray);
	NumShowersGoodRecoAng->SetFillColor(kGray);
	NumShowersGoodRecoAng->SetLineWidth(3);
	NumShowersGoodRecoAng->SetMinimum(0);
	NumShowersGoodRecoAng->Draw();

	MoreThanOneShowerAng->SetFillColor(kGreen);
	MoreThanOneShowerAng->SetStats(false);
	ShowerAngle->Add(MoreThanOneShowerAng);

	NoShowerAng->SetFillColor(kBlue);
	NoShowerAng->SetStats(false);
	ShowerAngle->Add(NoShowerAng);

	//NumShowersBadRecoEng->SetLineColor(kCyan + 2);
	//NumShowersBadRecoEng->SetFillColor(kCyan + 2);
	//NumShowersBadRecoEng->SetStats(false);
	//ShowerEnergy1->Add(NumShowersBadRecoEng);

	//GoodRecoEng->SetFillColor(kPink);
	//GoodRecoEng->SetLineColor(kRed);
	//GoodRecoEng->SetStats(false);
	//ShowerEnergy1->Add(GoodRecoEng);

	//AngleGoodRecoEng->SetFillColor(kRed);
	//AngleGoodRecoEng->SetLineColor(kRed);
	//AngleGoodRecoEng->SetStats(false);
	//ShowerEnergy1->Add(AngleGoodRecoEng);



	ShowerAngle->Draw("same");

	//TLegend* leg = new TLegend(0.5, 0.82, 0.92, 0.98);
	//leg->SetFillColor(kWhite);
	//leg->SetTextSize(0.03);
	//leg->AddEntry(Energy, "Events with Any Number of Showers", "l");
	//leg->AddEntry(MoreThanOneShowerEng, "Events with More than One Shower", "l");
	//leg->AddEntry(NoShowerEng, "Events with No Shower", "l");
	//leg->AddEntry(NumShowersBadRecoEng, "Bad Reco", "l");
	//leg->AddEntry(NumShowersGoodRecoEng, "All Events with One Shower", "l");
	//leg->AddEntry(AngleGoodRecoEng, "Good Angle Reco", "l");
	//leg->Draw();

	TCanvas* c27 = new TCanvas("c27", "", 700, 700);
	c27->SetLeftMargin(.1);
	c27->SetBottomMargin(.1);
	c27->SetTopMargin(.075);
	c27->SetRightMargin(.15);
	c27->cd();

	MCyzangle->SetLineColor(kRed);
	MCyzangle->Draw();

	TCanvas* c28 = new TCanvas("c28", "", 700, 700);
	c28->SetLeftMargin(.1);
	c28->SetBottomMargin(.1);
	c28->SetTopMargin(.075);
	c28->SetRightMargin(.15);
	c28->cd();

	MCxzangle->SetLineColor(kRed);
	MCxzangle->Draw();
	
	TCanvas* c29 = new TCanvas("c29", "", 700, 700);
	c29->SetLeftMargin(.1);
	c29->SetBottomMargin(.1);
	c29->SetTopMargin(.075);
	c29->SetRightMargin(.15);
	c29->cd();

	//XZ_angle->SetFillColor(kRed);
	XZ_angle->SetLineColor(kRed);
	XZ_angle->Draw();

	TCanvas* c30 = new TCanvas("c30", "", 700, 700);
	c30->SetLeftMargin(.1);
	c30->SetBottomMargin(.1);
	c30->SetTopMargin(.075);
	c30->SetRightMargin(.15);
	c30->cd();

	//YZ_angle->SetFillColor(kRed);
	YZ_angle->SetLineColor(kRed);
	YZ_angle->Draw();
	

	TCanvas* c31 = new TCanvas("c31", "", 700, 700);
	c31->SetLeftMargin(.1);
	c31->SetBottomMargin(.1);
	c31->SetTopMargin(.075);
	c31->SetRightMargin(.15);
	c31->cd();

	Nshowersratioeng->SetFillColor(kRed);
	Nshowersratioeng->SetLineColor(kRed);
	Nshowersratioeng->Draw();
	
	TCanvas* c32 = new TCanvas("c32", "", 700, 700);
	c32->SetLeftMargin(.1);
	c32->SetBottomMargin(.1);
	c32->SetTopMargin(.075);
	c32->SetRightMargin(.15);
	c32->cd();

	//xzdiffang->SetFillColor(kRed);
	xzdiffang->SetLineColor(kRed);
	xzdiffang->SetLineWidth(3);
	xzdiffang->Draw();
	
	TCanvas* c33 = new TCanvas("c33", "", 700, 700);
	c33->SetLeftMargin(.1);
	c33->SetBottomMargin(.1);
	c33->SetTopMargin(.075);
	c33->SetRightMargin(.15);
	c33->cd();

	//yzdiffang->SetFillColor(kRed);
	yzdiffang->SetLineColor(kRed);
	yzdiffang->SetLineWidth(3);
	yzdiffang->Draw();


	TCanvas* c34 = new TCanvas("c34", "", 700, 700);
	c34->SetLeftMargin(.1);
	c34->SetBottomMargin(.1);
	c34->SetTopMargin(.075);
	c34->SetRightMargin(.15);
	c34->cd();

	Showerstartx->SetLineColor(kRed);
	Showerstartx->Draw();

	TCanvas* c35 = new TCanvas("c35", "", 700, 700);
	c35->SetLeftMargin(.1);
	c35->SetBottomMargin(.1);
	c35->SetTopMargin(.075);
	c35->SetRightMargin(.15);
	c35->cd();

	Showerstarty->SetLineColor(kRed);
	Showerstarty->Draw();

	TCanvas* c36 = new TCanvas("c36", "", 700, 700);
	c36->SetLeftMargin(.1);
	c36->SetBottomMargin(.1);
	c36->SetTopMargin(.075);
	c36->SetRightMargin(.15);
	c36->cd();

	Showerstartz->SetLineColor(kRed);
	Showerstartz->Draw();


	TCanvas* c37 = new TCanvas("c37", "", 700, 700);
	c37->SetLeftMargin(.1);
	c37->SetBottomMargin(.1);
	c37->SetTopMargin(.075);
	c37->SetRightMargin(.15);
	c37->cd();

	MCstartx->SetLineColor(kRed);
	MCstartx->Draw();

	TCanvas* c38 = new TCanvas("c38", "", 700, 700);
	c38->SetLeftMargin(.1);
	c38->SetBottomMargin(.1);
	c38->SetTopMargin(.075);
	c38->SetRightMargin(.15);
	c38->cd();

	MCstarty->SetLineColor(kRed);
	MCstarty->Draw();


	TCanvas* c39 = new TCanvas("c39", "", 700, 700);
	c39->SetLeftMargin(.1);
	c39->SetBottomMargin(.1);
	c39->SetTopMargin(.075);
	c39->SetRightMargin(.15);
	c39->cd();

	MCstartz->SetLineColor(kRed);
	MCstartz->Draw();


	TCanvas* c40 = new TCanvas("c40", "", 700, 700);
	c40->SetLeftMargin(.1);
	c40->SetBottomMargin(.1);
	c40->SetTopMargin(.075);
	c40->SetRightMargin(.15);
	c40->cd();

	noshowerstartx->SetLineColor(kRed);
	noshowerstartx->SetMaximum(1000);
	noshowerstartx->Draw();

	oneshowerstartx->SetLineColor(kBlue);
	oneshowerstartx->Draw("same");

	TCanvas* c41 = new TCanvas("c41", "", 700, 700);
	c41->SetLeftMargin(.1);
	c41->SetBottomMargin(.1);
	c41->SetTopMargin(.075);
	c41->SetRightMargin(.15);
	c41->cd();

	noshowerenergy->SetLineColor(kRed);
	noshowerenergy->Draw();

	NumShowersGoodRecoEng->SetLineColor(kGray);
	NumShowersGoodRecoEng->Draw("same");


	TCanvas* c42 = new TCanvas("c42", "", 700, 700);
	c42->SetLeftMargin(.1);
	c42->SetBottomMargin(.1);
	c42->SetTopMargin(.075);
	c42->SetRightMargin(.15);
	c42->cd();

	noshowerstartx->SetLineColor(kRed);
	noshowerstartx->SetMaximum(1000);
	noshowerstartx->DrawNormalized("",1);

	oneshowerstartx->SetLineColor(kBlue);
	oneshowerstartx->DrawNormalized("same",1);	

	
TCanvas* c43 = new TCanvas("c43", "", 700, 700);
	c43->SetLeftMargin(.1);
	c43->SetBottomMargin(.1);
	c43->SetTopMargin(.075);
	c43->SetRightMargin(.15);
	c43->cd();

	DiffMCxdist->SetLineColor(kBlue);
	DiffMCxdist->SetLineWidth(3);
	DiffMCxdist->SetStats(true);
	DiffMCxdist->Draw();

	TCanvas* c44 = new TCanvas("c44", "", 700, 700);
	c44->SetLeftMargin(.1);
	c44->SetBottomMargin(.1);
	c44->SetTopMargin(.075);
	c44->SetRightMargin(.15);
	c44->cd();

	DiffMCydist->SetLineColor(kBlue);
	DiffMCydist->SetLineWidth(3);
	DiffMCydist->SetStats(true);
	DiffMCydist->Draw();

	TCanvas* c45 = new TCanvas("c45", "", 700, 700);
	c45->SetLeftMargin(.1);
	c45->SetBottomMargin(.1);
	c45->SetTopMargin(.075);
	c45->SetRightMargin(.15);
	c45->cd();

	DiffMCzdist->SetLineColor(kBlue);
	DiffMCzdist->SetLineWidth(3);
	DiffMCzdist->SetStats(true);
	DiffMCzdist->Draw();
	
	TCanvas* c46 = new TCanvas("c46", "", 700, 700);
	c46->SetLeftMargin(.1);
	c46->SetBottomMargin(.1);
	c46->SetTopMargin(.075);
	c46->SetRightMargin(.15);
	c46->cd();

	DiffMCCombxdist->SetLineColor(kBlue);
	DiffMCCombxdist->SetLineWidth(3);
	DiffMCCombxdist->SetStats(true);
	DiffMCCombxdist->Draw();

	TCanvas* c47 = new TCanvas("c47", "", 700, 700);
	c47->SetLeftMargin(.1);
	c47->SetBottomMargin(.1);
	c47->SetTopMargin(.075);
	c47->SetRightMargin(.15);
	c47->cd();

	DiffMCCombydist->SetLineColor(kBlue);
	DiffMCCombydist->SetLineWidth(3);
	DiffMCCombydist->SetStats(true);
	DiffMCCombydist->Draw();

	TCanvas* c48 = new TCanvas("c48", "", 700, 700);
	c48->SetLeftMargin(.1);
	c48->SetBottomMargin(.1);
	c48->SetTopMargin(.075);
	c48->SetRightMargin(.15);
	c48->cd();

	DiffMCCombzdist->SetLineColor(kBlue);
	DiffMCCombzdist->SetLineWidth(3);
	DiffMCCombzdist->SetStats(true);
	DiffMCCombzdist->Draw();

	
	}

/*

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

/*
// should check all three planes
// counter; checks if angle is off in every shower
int angcount = 0;

// multiple showers
for (int i = 1; (i < nshowers) && (nshowers > 1); i++)	// we start with the second shower
{
if ((Xangle && Yangle && Zangle && Dist))		// we check if the first shower has a correct direction and starting position
{
angcount++;
}

// difference in angle of the shower we are looking at (other than the first shower)
double xanglediff = 0;
double yanglediff = 0;
double zanglediff = 0;
double shwrxstartdiff = 0;
double shwrystartdiff = 0;
double shwrzstartdiff = 0;

// angle difference between two showers
double ang = 0;

//for (int j = 0; j < geant_List_size; i++)

shwrxstartdiff = shwr_startx[i] - StartPointx[j];
shwrystartdiff = shwr_starty[i] - StartPointy[j];
shwrzstartdiff = shwr_startz[i] - StartPointz[j];

//if (shwrxstartdiff <= mindistance && shwrystartdiff <= mindistance && shwrzstartdiff <= mindistance)

// checks to see if all the angles are within the minangle
if (fabs(xanglediff) <= minangle && fabs(yanglediff) <= minangle && fabs(zanglediff) <= minangle)
{

double shwr1;
double shwr2;

shwr1 = sqrt(pow(shwr_startx[i - 1], 2) + pow(shwr_starty[i - 1], 2) + pow(shwr_startz[i - 1], 2));
shwr2 = sqrt(pow(shwr_startx[i], 2) + pow(shwr_starty[i], 2) + pow(shwr_startz[i], 2));

ang = TMath::ACos((shwr_startx[i - 1] * shwr_startx[i] + shwr_starty[i - 1] * shwr_starty[i] + shwr_startz[i - 1] * shwr_startz[i]) / (shwr1*shwr2));

ang = ang * radtodegrees;

if (ang > minangle)	// if the angle is within the minangle then we will consider it to be a well reconstructed shower
{
angcount++;
//all well reconstructed (good angle in all three planes an) and collinear
}

if (angcount == nshowers)
{
//MultShowerCorrectEng->Fill(EngMeV);
}

else
{
//MultShowerWrongEng->Fill(EngMeV);

*/

/*
double min = 0;
double partdisttoshower = 0;

for (int i = 0; i < nshowers && nshowers > 1; i++)
{
for (int j = 1; j < geant_list_size; j++)
{
double distance = sqrt(pow((shwr_startx[i] - StartPointx[j]), 2) + pow((shwr_starty[i] - StartPointy[j]), 2) + pow((shwr_startz[i] - StartPointz[j]), 2));

if (distance < mindistance)
{
for (int k = j + 1; partdisttoshower < distance; k++)
{
partdisttoshower = sqrt(pow((shwr_startx[i] - StartPointx[k]), 2) + pow((shwr_starty[i] - StartPointy[k]), 2) + pow((shwr_startz[i] - StartPointz[k]), 2));

if (partdisttoshower < distance)
{
min = k;
}

}

// check if angle is within cut and also check if direction is within the cut
// if it is then we know that it is a mult shower that has been reconstructed correctly
}
}
}

*/

/*
if (Nshowers && Angle)
{
bool check = false;

if (0.5*(shwr_totEng[0][shwr_bestplane[0]]) <= EngMeV)		// checks if the shower energy is half or less of the first particle in the MC
{
for (int j = 1; j < geant_list_size; j++)		// checks if the starting point is somewhere close to the shower
{
double distance = sqrt(pow((shwr_startx[0] - StartPointx[j]), 2) + pow((shwr_starty[0] - StartPointy[j]), 2) + pow((shwr_startz[0] - StartPointz[j]), 2));

if (distance <= mindistance)		// cant use the bool Dist
{
MisshalfShowerEng->Fill(EngMeV);
}
}
}

MissBegShowerEng->Fill(EngMeV);
}


*/


/*
if (Nshowers)
{
double diffxangle = TMath::ACos(shwr_startdcosx[0]) - TMath::ACos(cx_angle);
DiffxAngle->Fill(diffxangle * radtodegrees);

double diffyangle = TMath::ACos(shwr_startdcosy[0]) - TMath::ACos(cy_angle);
DiffyAngle->Fill(diffyangle * radtodegrees);

double diffzangle = TMath::ACos(shwr_startdcosz[0]) - TMath::ACos(cz_angle);
DiffzAngle->Fill(diffzangle * radtodegrees);

//std::cout << "shower angle: " << TMath::ACos(shwr_startdcosx[0]) * radtodegrees << std::endl;
//std::cout << "true angle: " << TMath::ACos(cx_angle) * radtodegrees << std::endl;
//std::cout << "difference: " << TMath::ACos(shwr_startdcosx[0]) * radtodegrees - TMath::ACos(cx_angle) * radtodegrees << std::endl << std::endl;


}
*/

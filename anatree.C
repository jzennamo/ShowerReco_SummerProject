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

	TH1F* StartPointOffset = new TH1F("Start_Point_Offset", "; Start Point Offset(cm); Number", 100, 0, 100);	//how far off is the shower start from the MC start; plot distance in m
	TH1F* NumShowers = new TH1F("Number_of_Showers", "; Shower Number; Number of Events", 5, -0.5, 5.5);		// plot number of showers
	TH1F* PhotonDist = new TH1F("Photon_Distance", "; Photon Distance(cm); Number of Particles", 50, 50, 1500);	// how far does a brem photon travel
	TH1F* xAngleOffset = new TH1F("X_angle_Offset ", "; Angle(degrees); Number of Particles", 360, 0, 360);		// how far off is the direction in the x plane in degrees
	TH1F* yAngleOffset = new TH1F("Y_angle_Offset ", "; Angle(degrees); Number of Particles", 360, 0, 360);		// how far off is the direction in the x plane in degrees
	TH1F* zAngleOffset = new TH1F("Z_angle_Offset ", "; Angle(degrees); Number of Particles", 360, 0, 360);		// how far off is the direction in the x plane in degrees

	TH1F* StartPointOffsetGoodReco = new TH1F("start_Point_offset_Good_Reco", "; Start Point Offset(cm); Number", 100, 0, 100);
	TH1F* xAngleOffsetGoodReco = new TH1F("X_angle_Offset_Good_Reco ", "; Angle(degrees); Number of Particles", 360, 0, 360);
	TH1F* yAngleOffsetGoodReco = new TH1F("Y_angle_Offset_Good_Reco ", "; Angle(degrees); Number of Particles", 360, 0, 360);
	TH1F* zAngleOffsetGoodReco = new TH1F("Z_angle_Offset_Good_Reco ", "; Angle(degrees); Number of Particles", 360, 0, 360);

	TH1F* NumShowersGoodRecoEng = new TH1F("Energy_One_Shower", "; Energy(MeV); Number of Events", 100, 0, 1200);
	TH1F* Energy = new TH1F("Energy", "; Energy(MeV); Number of Events", 100, 0, 1200);
	TH1F* XAngleGoodRecoEng = new TH1F("X_angle_Good_Reco_Energy ", "; Energy(MeV); Number of Events", 100, 0, 1200);
	TH1F* YAngleGoodRecoEng = new TH1F("Y_angle_Good_Reco_Energy ", "; Energy(MeV); Number of Events", 100, 0, 1200);
	TH1F* ZAngleGoodRecoEng = new TH1F("Z_angle_Good_Reco_Energy ", "; Energy(MeV); Number of Events", 100, 0, 1200);
	TH1F* DistGoodRecoEng = new TH1F("Distance_Good_Reco_Energy ", "; Energy(MeV); Number of Events", 100, 0, 1200);
	TH1F* BremphotonEng = new TH1F("Brem_Energy ", "; Energy(MeV); Number of Events", 100, 0, 1200);
	TH1F* NoShowerEng = new TH1F("No_Shower_Energy ", "; Energy(MeV); Number of Events", 100, 0, 1200);
	TH1F* StartPointOffsetGoodRecoEng = new TH1F("Start_Point_Offset_Good_Reco_Eng", "; Energy(MeV); Number of Events", 100, 0, 1200);
	TH1F* MoreThanOneShowerEng = new TH1F("MoreThanOneShowerEng ", "; Energy(MeV); Number of Events", 100, 0, 1200);

	TH1F* GoodRecoEng = new TH1F("Good_Reco ", "; Energy(MeV); Number of Events", 100, 0, 1200);
	TH1F* AngleGoodRecoEng = new TH1F("Angle_Good_Reco_Energy ", "; Energy(MeV); Number of Events", 100, 0, 1200);

	TH1F* EffNumShowers = new TH1F("EffNumShowers", "NumShowersGoodRecoEng/Energy", 100, 0, 1200);
	TH1F* EffDist = new TH1F("EffDist", "StartPointOffsetGoodRecoEng/Energy", 100, 0, 1200);
	TH1F* EffGoodRecoEng = new TH1F("EffGoodRecoEng", "GoodRecoEng/Energy", 100, 0, 1200);
	TH1F* EffNoShowerEng = new TH1F("EffNoShowerEng", "NoShowerEng/Energy", 100, 0, 1200);

	TH1F* EffStartPointEng = new TH1F("EffStartPointEng", "StartPointOffsetGoodRecoEng/Energy", 100, 0, 1200);



	TH1F* MisshalfShowerEng = new TH1F("MisshalfShowerEng ", "; Energy(MeV); Number of Events", 100, 0, 1200);


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
	bool Xangle = false;		// true if the x angle is within 5 degrees
	bool Yangle = false;		// true if the y angle is within 5 degrees
	bool Zangle = false;		// true if the z angle is within 5 degrees
	bool Bremphoton = false;	// true if the photon has at least 5% of the total shower energy
	bool Angle = false;			// true if all three angles are within 5 degrees

	double dist = 0;			// starting position distance from MC start
	double EngMeV = Eng[0] * 1000;	// Energy of the first particle in MeV
	double mindistance = 2.5;		// min distance that shower start can be from MC start

		// This is to calculate the distance between the starting point of the shower and the MC
		if (nshowers == 1)			// we want to check events that have only one shower
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
		    
		    // Histogram (TH1F)  -> Fill(var) [function, var] 
		    StartPointOffset->Fill(dist);
		    
		    /*
		      std::cout << "X difference: " << fabs(shwr_startx[0] - EndPointx[0]) << std::endl;
		      std::cout << "Y difference: " << fabs(StartPointy[0] - EndPointy[0]) << std::endl;
		      std::cout << "Z difference: " << fabs(StartPointz[0] - EndPointz[0]) << std::endl;
		      
		    */
		  }

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

		
		//use momentum to calculate the MC angle and then compare it to the other shower angle and create three plots (one for each plane)
		// cosine of the angle
		
		double cx_angle = Px[0] / P[0];
		double cy_angle = Py[0] / P[0];
		double cz_angle = Pz[0] / P[0];
		
		// difference in angle between the shower start and the MC start
		double xdiff = fabs(TMath::ACos(shwr_startdcosx[0]) - TMath::ACos(cx_angle));
		double ydiff = fabs(TMath::ACos(shwr_startdcosy[0]) - TMath::ACos(cy_angle));
		double zdiff = fabs(TMath::ACos(shwr_startdcosz[0]) - TMath::ACos(cz_angle));

		// conversion factor
		double radtodegrees = 180 / 3.14;

		// angles in degrees
		xdiff = xdiff * radtodegrees;
		ydiff = ydiff * radtodegrees;
		zdiff = zdiff * radtodegrees;
		
		// minumum angle that is considered not too far off from actual
		double minangle = 5.0;


		// fill in with the angle difference
		xAngleOffset->Fill(xdiff);
		yAngleOffset->Fill(ydiff);
		zAngleOffset->Fill(zdiff);

		// good reconstructed showers
		// must have correct shower direction and shower starting position and only one shower
		if (nshowers == 1)	// only want one shower
		{
			Nshowers = true;
		}
		
		// starting position is within 2.5 cm (mindistance)
		if (dist <= mindistance)
		{
			// Histogram (TH1F)  -> Fill(var) [function, var]
			Dist = true;
			StartPointOffsetGoodReco->Fill(dist);
			StartPointOffsetGoodRecoEng->Fill(EngMeV);
		}
		
		// if any of the angles is within the minimum angle then we want to add it to the histogram and make the bool true
		if (xdiff <= minangle)
		{
			Xangle = true;
			xAngleOffsetGoodReco->Fill(xdiff);
		}
		    
		if (ydiff <= minangle)
		{
			Yangle = true;
			yAngleOffsetGoodReco->Fill(ydiff);
		}
		    
		if (zdiff <= minangle)
		{
			Zangle = true;
			zAngleOffsetGoodReco->Fill(zdiff);
		}

		// if there is only one shower then plot the energy of that shower
		if (nshowers == 1)
		{
			NumShowersGoodRecoEng->Fill(EngMeV);
			//Nshowers = false;
		}
		
		// NumShowersEng->Fill(EngMeV);

		// checks if the angle is within 5 degrees in all three planes and if it is, fills it in the histogram
		if (Xangle)
		{
			XAngleGoodRecoEng->Fill(EngMeV);
		}
		    
		if (Yangle)
		{
			YAngleGoodRecoEng->Fill(EngMeV);
		}

		if (Zangle)
		{
			ZAngleGoodRecoEng->Fill(EngMeV);
		}

		// multiple showers
		for (int i = 1; (i < nshowers) && (nshowers > 1); i++)	// we start with the second shower
		{
			if (Xangle && Yangle && Zangle)		// we check if the first shower has a correct direction
			{
				// difference in angle of the shower we are looking at (other than the first shower)
				double xanglediff = 0;			
				double yanglediff = 0;
				double zanglediff = 0;

				// counter; checks if angle is off in every shower
				int angcounter = 0;

				// angle difference between two showers
				double ang = 0;

				// checks to see if all the angles are within the minangle
				if (fabs(xanglediff) <= minangle && fabs(yanglediff) <= minangle && fabs(zanglediff) <= minangle)	
				{
					double shwr1;
					double shwr2;

					shwr1 = sqrt(pow(shwr_startx[i - 1], 2) + pow(shwr_starty[i - 1], 2) + pow(shwr_startz[i - 1], 2));
					shwr2 = sqrt(pow(shwr_startx[i], 2) + pow(shwr_starty[i], 2) + pow(shwr_startz[i], 2));

					ang = TMath::ACos((shwr_startx[i - 1] * shwr_startx[i] + shwr_starty[i - 1] * shwr_starty[i] + shwr_startz[i - 1] * shwr_startz[i]) / (shwr1*shwr2));
					
					ang = ang * radtodegrees;

					if (ang < minangle)	// if the angle is within the minangle then we will consider it to be a well reconstructed shower
					{
						angcounter++;
						//all well reconstructed (good angle in all three planes an) and collinear
					}

					if (angcounter == nshowers)
					{
				
					}
				}
				
				
				}
			}
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

		if ((nshowers == 1) && Angle)
		{
			if (0.5*(shwr_totEng[0][shwr_bestplane[0]]) <= Eng[0] * 1000)		// checks if the shower energy is half or less of the first particle in the MC
			{
				for (int j = 1; j < geant_list_size; j++)		// checks if the starting point is somewhere close to the shower
				{
					double distance = sqrt(pow((shwr_startx[0] - StartPointx[j]), 2) + pow((shwr_starty[0] - StartPointy[j]), 2) + pow((shwr_startz[0] - StartPointz[j]), 2));

					if (distance <= mindistance)
					{
						MisshalfShowerEng->Fill(EngMeV);
					}
				}
			}
		}

		if (Dist)
		{
			DistGoodRecoEng->Fill(EngMeV);
			Dist = false;
		}

		if (nshowers == 0)
		{
			NoShowerEng->Fill(EngMeV);
		}

		if ((nshowers == 1) && (dist <= mindistance) && Angle)
		{
			GoodRecoEng->Fill(EngMeV);
			Angle = false;
		}
	
		Energy->Fill(EngMeV);

		if (nshowers > 1)
		{
			MoreThanOneShowerEng->Fill(EngMeV);
		}



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

		    ////// END
		    
		    /// Here is the end of the loop
		    /// Start

	}

	/// End
	
	TFile *f = new TFile("Awesome_Shower_Reco_Vetting_Booyah.root", "RECREATE");
   
	StartPointOffset->Write();
	NumShowers->Write();
	PhotonDist->Write();
	xAngleOffset->Write();
	yAngleOffset->Write();
	zAngleOffset->Write();
	
	StartPointOffsetGoodReco->Write();
	xAngleOffsetGoodReco->Write();
	yAngleOffsetGoodReco->Write();
	zAngleOffsetGoodReco->Write();
	
	f->Write();
	f->Close();
	
	gStyle->SetOptStat(0000);
	gStyle->SetPadBorderMode(0);
	


	TCanvas* c1 = new TCanvas("c1","",700,700);
	c1->SetLeftMargin(.1);
	c1->SetBottomMargin(.1);
	c1->SetTopMargin(.075);
	c1->SetRightMargin(.15);
	c1->cd();
	
   //Line attributes: https://root.cern.ch/root/html/TAttLine.html
   //Color Choices: https://root.cern.ch/root/html/TColor.html
	NumShowers->SetLineColor(kPink+8);
	NumShowers->SetLineWidth(3);
	NumShowers->Draw();

	TLegend* leg = new TLegend(0.5, 0.82, 0.92, 0.98);
	leg->SetFillColor(kWhite);
	leg->SetTextSize(0.04);
	leg->AddEntry(NumShowers, "Number of Showers", "l");
	leg->Draw();



	TCanvas* c2 = new TCanvas("c2","",700,700);
	c2->SetLeftMargin(.1);
	c2->SetBottomMargin(.1);
	c2->SetTopMargin(.075);
	c2->SetRightMargin(.15);
	c2->cd();
	
	xAngleOffset->SetLineColor(kBlack);
	xAngleOffset->SetLineWidth(3);
	xAngleOffset->Draw();
	
	xAngleOffsetGoodReco->SetLineColor(kRed);
	xAngleOffsetGoodReco->SetLineWidth(3);
	xAngleOffsetGoodReco->SetLineStyle(4);
	xAngleOffsetGoodReco->Draw("same");
	
	TLegend* leg=new TLegend(0.5,0.82,0.92,0.98);
	leg->SetFillColor(kWhite);
	leg->SetTextSize(0.025);
	leg->AddEntry(xAngleOffset,"All Showers","l");
	leg->AddEntry(xAngleOffsetGoodReco,"Good Showers (x angle within 5 degrees)","l");
	leg->Draw();



	TCanvas* c3 = new TCanvas("c3", "", 700, 700);
	c3->SetLeftMargin(.1);
	c3->SetBottomMargin(.1);
	c3->SetTopMargin(.075);
	c3->SetRightMargin(.15);
	c3->cd();

	MisshalfShowerEng->SetLineColor(kRed);
	MisshalfShowerEng->SetLineWidth(3);
	MisshalfShowerEng->Draw();
	


	TCanvas* c4 = new TCanvas("c4", "", 700, 700);
	c4->SetLeftMargin(.1);
	c4->SetBottomMargin(.1);
	c4->SetTopMargin(.075);
	c4->SetRightMargin(.15);
	c4->cd();

	Energy->SetLineColor(kYellow);
	Energy->SetLineWidth(3);
	Energy->Draw();

	NumShowersGoodRecoEng->SetLineColor(kMagenta);
	NumShowersGoodRecoEng->SetLineWidth(3);
	NumShowersGoodRecoEng->Draw("same");

	TLegend* leg = new TLegend(0.5, 0.82, 0.92, 0.98);
	leg->SetFillColor(kWhite);
	leg->SetTextSize(0.05);
	leg->AddEntry(Energy, "All Showers", "l");
	leg->AddEntry(NumShowersGoodRecoEng, "One Shower", "l");
	leg->Draw();



	TCanvas* c5 = new TCanvas("c5", "", 700, 700);
	c5->SetLeftMargin(.1);
	c5->SetBottomMargin(.1);
	c5->SetTopMargin(.075);
	c5->SetRightMargin(.15);
	c5->cd();

	BremphotonEng->SetLineColor(kYellow);
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

	NoShowerEng->SetLineColor(kRed);
	NoShowerEng->SetLineWidth(3);
	NoShowerEng->Draw();

	TLegend* leg = new TLegend(0.5, 0.82, 0.92, 0.98);
	leg->SetFillColor(kWhite);
	leg->SetTextSize(0.04);
	leg->AddEntry(NoShowerEng, "No Shower Reconstructed", "l");
	leg->Draw();



	TCanvas* c7 = new TCanvas("c7", "", 700, 700);
	c7->SetLeftMargin(.1);
	c7->SetBottomMargin(.1);
	c7->SetTopMargin(.075);
	c7->SetRightMargin(.15);
	c7->cd();

	yAngleOffset->SetLineColor(kBlack);
	yAngleOffset->SetLineWidth(3);
	yAngleOffset->Draw();

	yAngleOffsetGoodReco->SetLineColor(kRed);
	yAngleOffsetGoodReco->SetLineWidth(3);
	yAngleOffsetGoodReco->SetLineStyle(4);
	yAngleOffsetGoodReco->Draw("same");

	TLegend* leg = new TLegend(0.5, 0.82, 0.92, 0.98);
	leg->SetFillColor(kWhite);
	leg->SetTextSize(0.04);
	leg->AddEntry(yAngleOffset, "All Showers", "l");
	leg->AddEntry(yAngleOffsetGoodReco, "Good Showers (y angle within 5 degrees)", "l");
	leg->Draw();



	TCanvas* c8 = new TCanvas("c8", "", 700, 700);
	c8->SetLeftMargin(.1);
	c8->SetBottomMargin(.1);
	c8->SetTopMargin(.075);
	c8->SetRightMargin(.15);
	c8->cd();

	zAngleOffset->SetLineColor(kBlack);
	zAngleOffset->SetLineWidth(3);
	zAngleOffset->Draw();

	zAngleOffsetGoodReco->SetLineColor(kRed);
	zAngleOffsetGoodReco->SetLineWidth(3);
	zAngleOffsetGoodReco->SetLineStyle(4);
	zAngleOffsetGoodReco->Draw("same");

	TLegend* leg = new TLegend(0.5, 0.82, 0.92, 0.98);
	leg->SetFillColor(kWhite);
	leg->SetTextSize(0.04);
	leg->AddEntry(zAngleOffset, "All Showers", "l");
	leg->AddEntry(zAngleOffsetGoodReco, "Good Showers (z angle within 5 degrees)", "l");
	leg->Draw();
	

	TCanvas* c9 = new TCanvas("c9", "", 700, 700);
	c9->SetLeftMargin(.1);
	c9->SetBottomMargin(.1);
	c9->SetTopMargin(.075);
	c9->SetRightMargin(.15);
	c9->cd();

	EffNumShowers->Divide(NumShowersGoodRecoEng, Energy);

	EffNumShowers->SetLineColor(kMagenta);
	EffNumShowers->SetLineWidth(3);
	EffNumShowers->Draw();



	TCanvas* c10 = new TCanvas("c10", "", 700, 700);
	c10->SetLeftMargin(.1);
	c10->SetBottomMargin(.1);
	c10->SetTopMargin(.075);
	c10->SetRightMargin(.15);
	c10->cd();
	
	EffDist->Divide(StartPointOffsetGoodRecoEng, Energy);

	EffDist->SetLineColor(kCyan+2);
	EffDist->SetLineWidth(3);
	EffDist->Draw();
	
	
	TCanvas* c11 = new TCanvas("c11", "", 700, 700);
	c11->SetLeftMargin(.1);
	c11->SetBottomMargin(.1);
	c11->SetTopMargin(.075);
	c11->SetRightMargin(.15);
	c11->cd();

	GoodRecoEng->SetLineColor(kCyan + 2);
	GoodRecoEng->SetLineWidth(3);
	GoodRecoEng->Draw();

	TLegend* leg = new TLegend(0.5, 0.82, 0.92, 0.98);
	leg->SetFillColor(kWhite);
	leg->SetTextSize(0.04);
	leg->AddEntry(GoodRecoEng, "GoodRecoEng", "l");
	leg->Draw();

	

	TCanvas* c12 = new TCanvas("c12", "", 700, 700);
	c12->SetLeftMargin(.1);
	c12->SetBottomMargin(.1);
	c12->SetTopMargin(.075);
	c12->SetRightMargin(.15);
	c12->cd();
	
	EffGoodRecoEng->Divide(GoodRecoEng, Energy);

	EffGoodRecoEng->SetLineColor(kCyan + 2);
	EffGoodRecoEng->SetLineWidth(3);
	EffGoodRecoEng->Draw();
	
	TCanvas* c13 = new TCanvas("c13", "", 700, 700);
	c13->SetLeftMargin(.1);
	c13->SetBottomMargin(.1);
	c13->SetTopMargin(.075);
	c13->SetRightMargin(.15);
	c13->cd();

	Energy->SetLineColor(kSpring);
	Energy->SetLineWidth(3);
	Energy->Draw();

	NumShowersGoodRecoEng->SetLineColor(kMagenta);
	NumShowersGoodRecoEng->SetLineWidth(3);
	NumShowersGoodRecoEng->Draw("same");

	GoodRecoEng->SetLineColor(kCyan + 2);
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
	leg->SetTextSize(0.04);
	leg->AddEntry(Energy, "All Showers", "l");
	leg->AddEntry(NumShowersGoodRecoEng, "One Shower", "l");
	leg->AddEntry(GoodRecoEng, "Good Reconstruction", "l");
	leg->AddEntry(AngleGoodRecoEng, "All angles within 5 degrees", "l");
	leg->AddEntry(StartPointOffsetGoodRecoEng, "Start within 2.5 cm", "l");
	leg->Draw();
	
	TCanvas* c14 = new TCanvas("c14", "", 700, 700);
	c14->SetLeftMargin(.1);
	c14->SetBottomMargin(.1);
	c14->SetTopMargin(.075);
	c14->SetRightMargin(.15);
	c14->cd();
	


	TCanvas* c15 = new TCanvas("c15", "", 700, 700);
	c15->SetLeftMargin(.1);
	c15->SetBottomMargin(.1);
	c15->SetTopMargin(.075);
	c15->SetRightMargin(.15);
	c15->cd();

	EffNoShowerEng->Divide(NoShowerEng, Energy);

	EffNoShowerEng->SetLineColor(kCyan + 2);
	EffNoShowerEng->SetLineWidth(3);
	EffNoShowerEng->Draw();

	TCanvas* c16 = new TCanvas("c16", "", 700, 700);
	c16->SetLeftMargin(.1);
	c16->SetBottomMargin(.1);
	c16->SetTopMargin(.075);
	c16->SetRightMargin(.15);
	c16->cd();

	NoShowerEng->SetLineColor(kRed);
	NoShowerEng->SetLineWidth(3);
	NoShowerEng->Draw();

	NumShowersGoodRecoEng->SetLineColor(kBlack);
	NumShowersGoodRecoEng->SetLineWidth(3);
	NumShowersGoodRecoEng->Draw("same");

	MoreThanOneShowerEng->SetLineColor(kBlue);
	MoreThanOneShowerEng->SetLineWidth(3);
	MoreThanOneShowerEng->Draw("same");
}

/*


// two or more showers; at least one in the wrong direction/start
if (nshowers == 0)
{

NoShowerTotEng->Fill(Eng[0]);

}


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

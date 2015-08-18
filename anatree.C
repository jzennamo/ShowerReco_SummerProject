#define anatree_cxx
#include "anatree.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>


double Find_Angle(double angle);



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

	TH1F* StartPointOffset = new TH1F("Start_Point_Offset", "Start Point Offset; Distance(cm); Number of Events", 250, 0, 10);	//how far off is the shower start from the MC start; plot distance in m
	
	TH1F* Startpointoffsetgreaterthan60dist = new TH1F("Startpointoffsetgreaterthan60dist", "Start Point Offset; Distance(cm); Number of Events", 250, 0, 10);
	TH1F* Startpointoffsetlessthan60dist = new TH1F("Startpointoffsetlessthan60dist", "Start Point Offset; Distance(cm); Number of Events", 250, 0, 10);

	TH1F* Startpointoffsetgreaterthan50dist = new TH1F("Startpointoffsetgreaterthan50dist", "Start Point Offset; Distance(cm); Number of Events", 250, 0, 10);
	TH1F* Startpointoffsetgreaterthan70dist = new TH1F("Startpointoffsetgreaterthan70dist", "Start Point Offset; Distance(cm); Number of Events", 250, 0, 10);
	TH1F* Startpointoffsetgreaterthan80dist = new TH1F("Startpointoffsetgreaterthan80dist", "Start Point Offset; Distance(cm); Number of Events", 250, 0, 10);
	TH1F* Startpointoffsetgreaterthan90dist = new TH1F("Startpointoffsetgreaterthan90dist", "Start Point Offset; Distance(cm); Number of Events", 250, 0, 10);
	TH1F* Startpointoffsetgreaterthan100dist = new TH1F("Startpointoffsetgreaterthan100dist", "Start Point Offset; Distance(cm); Number of Events", 250, 0, 10);

	TH1F* Uplanedist = new TH1F("Uplanedist", "Start Point Offset; Distance(cm); Number of Events", 200, 0, 10);
	TH1F* Vplanedist = new TH1F("Vplanedist", "Start Point Offset; Distance(cm); Number of Events", 200, 0, 10);
	TH1F* Yplanedist = new TH1F("Yplanedist", "Start Point Offset; Distance(cm); Number of Events", 200, 0, 10);

	TH1F* ParallelAngledist = new TH1F("ParallelAngledist", "Start Point Offset; Distance(cm); Number of Events", 200, 0, 10);
	TH1F* NotParallelAngledist = new TH1F("NotParallelAngledist", "Start Point Offset; Distance(cm); Number of Events", 200, 0, 10);


	TH1F* Unotplanedist = new TH1F("Unotplanedist", "Start Point Offset; Distance(cm); Number of Events", 200, 0, 10);
	TH1F* Vnotplanedist = new TH1F("Vnotplanedist", "Start Point Offset; Distance(cm); Number of Events", 200, 0, 10);
	TH1F* Ynotplanedist = new TH1F("Ynotplanedist", "Start Point Offset; Distance(cm); Number of Events", 200, 0, 10);


	TH1F* GoodAngledist = new TH1F("GoodAngledist", "Start Point Offset; Distance(cm); Number of Events", 100, 0, 10);

	TH1F* Anglegreaterthan60dist = new TH1F("Anglegreaterthan60", "Start Point Offset; Distance(cm); Number of Events", 100, 0, 10);
	TH1F* Anglelessthanminus60dist = new TH1F("Anglelessthanminus60", "Start Point Offset; Distance(cm); Number of Events", 100, 0, 10);

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

	TH1F* EffShowersGoodRecoEng = new TH1F("ShowersEffGoodRecoEng", ";Energy(MeV);Efficiency ", 25, 100, 2000); // GoodRecoEng/Energy

	TH1F* EffNumShowers = new TH1F("EffNumShowers", "; Energy(MeV);Efficiency", 25, 100, 2000); // Efficiency of at Least One Reconstructed Shower
	TH1F* EffDist = new TH1F("EffDist", ";Energy(MeV);", 25, 100, 2000); // StartPointOffsetGoodRecoEng/Energy
	TH1F* EffSuperDist = new TH1F("EffSuperDist", ";Energy(MeV);", 25, 100, 2000); // StartPointOffsetGoodRecoEng/Energy

	TH1F* EffGoodRecoEng = new TH1F("EffGoodRecoEng", ";Energy(MeV); Efficiency", 25, 100, 2000); // GoodRecoEng/Energy
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

	TH1F* Diffxdistmaggreaterthan60 = new TH1F("Diffxdistmaggreaterthan60", "Shower Start - MC Start (x Direction); Distance(cm); Number of Events", 300, -3, 3);
	TH1F* Diffxdistmaglessthan60 = new TH1F("Diffxdistmaglessthan60", "Shower Start - MC Start (x Direction); Distance(cm); Number of Events", 300, -3, 3);

	TH1F* Diffydistmaggreaterthan60 = new TH1F("Diffydistmaggreaterthan60", "Shower Start - MC Start (y Direction); Distance(cm); Number of Events", 300, -3, 3);
	TH1F* Diffydistmaglessthan60 = new TH1F("Diffydistmaglessthan60", "Shower Start - MC Start (y Direction); Distance(cm); Number of Events", 300, -3, 3);

	TH1F* Diffzdistmaggreaterthan60 = new TH1F("Diffzdistmaggreaterthan60", "Shower Start - MC Start (z Direction); Distance(cm); Number of Events", 300, -3, 3);
	TH1F* Diffzdistmaglessthan60 = new TH1F("Diffzdistmaglessthan60", "Shower Start - MC Start (z Direction); Distance(cm); Number of Events", 300, -3, 3);


	TH1F* Diffxdistgreaterthan60 = new TH1F("Diffxdistgreaterthan60", "Shower Start - MC Start (x Direction); Distance(cm); Number of Events", 300, -3, 3);
	TH1F* Diffxdistlessthanminus60 = new TH1F("Diffxdistlessthanminus60", "Shower Start - MC Start (x Direction); Distance(cm); Number of Events", 300, -3, 3);

	TH1F* Diffydistgreaterthan60 = new TH1F("Diffydistgreaterthan60", "Shower Start - MC Start (y Direction); Distance(cm); Number of Events", 300, -3, 3);
	TH1F* Diffydistlessthanminus60 = new TH1F("Diffydistlessminusthan60", "Shower Start - MC Start (y Direction); Distance(cm); Number of Events", 300, -3, 3);

	TH1F* Diffzdistgreaterthan60 = new TH1F("Diffzdistgreaterthan60", "Shower Start - MC Start (z Direction); Distance(cm); Number of Events", 300, -3, 3);
	TH1F* Diffzdistlessthanminus60 = new TH1F("Diffzdistlessthanminus60", "Shower Start - MC Start (z Direction); Distance(cm); Number of Events", 300, -3, 3);

	TH1F* Posmomentumxdist = new TH1F("Posmomentumxdist", "Shower Start - MC Start (x Direction); Distance(cm); Number of Events", 300, -3, 3);
	TH1F* Negmomentumxdist = new TH1F("Negmomemtumxdist", "Shower Start - MC Start (x Direction); Distance(cm); Number of Events", 300, -3, 3);

	TH1F* Posmomentumydist = new TH1F("Posmomentumydist", "Shower Start - MC Start (y Direction); Distance(cm); Number of Events", 300, -3, 3);
	TH1F* Negmomentumydist = new TH1F("Negmomemtumydist", "Shower Start - MC Start (y Direction); Distance(cm); Number of Events", 300, -3, 3);

	TH1F* Posmomentumzdist = new TH1F("Posmomentumzdist", "Shower Start - MC Start (z Direction); Distance(cm); Number of Events", 300, -3, 3);
	TH1F* Negmomentumzdist = new TH1F("Negmomemtumzdist", "Shower Start - MC Start (z Direction); Distance(cm); Number of Events", 300, -3, 3);

	TH1F* Startpointoffsetxzangledistlessthan = new TH1F("Startpointoffsetxzangledistlessthan", "Start offset MC xz Angle; Distance(cm); Number of Events", 250, 0, 10);
	TH1F* EndStartpointoffsetxzangledist = new TH1F("EndStartpointoffsetxzangledist", "Start offset MC xz Angle; Distance(cm); Number of Events", 250, 0, 10);
	TH1F* EndStartpointoffsetyzangledist = new TH1F("EndStartpointoffsetyzangledist", "Start offset MC xz Angle; Distance(cm); Number of Events", 250, 0, 10);
	TH1F* NotEndStartpointoffsetxzangledist = new TH1F("NotEndStartpointoffsetxzangledist", "Start offset MC xz Angle; Distance(cm); Number of Events", 250, 0, 10);
	TH1F* NotEndStartpointoffsetyzangledist = new TH1F("NotEndStartpointoffsetyzangledist", "Start offset MC xz Angle; Distance(cm); Number of Events", 250, 0, 10);

	TH1F* DiffMCxdist = new TH1F("DiffMCxdist", "Shower Start - MC Shower Start (x Direction); Distance(cm); Number of Events", 300, -3, 3);
	TH1F* DiffMCydist = new TH1F("DiffMCydist", "Shower Start - MC Shower Start (y Direction); Distance(cm); Number of Events", 300, -3, 3);
	TH1F* DiffMCzdist = new TH1F("DiffMCzdist", "Shower Start - MC Shower Start (z Direction); Distance(cm); Number of Events", 300, -3, 3);

	TH1F* DiffMCCxdist = new TH1F("DiffMCCxdist", "MC Shower Comb Start - MC Shower Start (x Direction); Distance(cm); Number of Events", 300, -3, 3);
	TH1F* DiffMCCydist = new TH1F("DiffMCCydist", "MC Shower Comb Start - MC Shower Start (y Direction); Distance(cm); Number of Events", 300, -3, 3);
	TH1F* DiffMCCzdist = new TH1F("DiffMCCzdist", "MC Shower Comb Start - MC Shower Start (z Direction); Distance(cm); Number of Events", 300, -3, 3);


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
	THStack * ycomponent = new THStack("ycomponent", "");

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

	TH1F* Showereng = new TH1F("Energy of Shower ", "; Energy(MeV); Number of Events", 25, 100, 2000);
	TH1F* FirstParticleEng = new TH1F(" ", "; Energy(MeV); Number of Events", 25, 100, 2000);
	TH1F* EffEng = new TH1F("EffEng ", "; Energy(MeV); Number of Events", 25, 100, 2000);

	TH1F* Negativededxdist = new TH1F("Negativededxdist", "Start Point Offset; Distance(cm); Number of Events", 1000, 0, 100);
	TH1F* Negativededxxzang = new TH1F("Negativededxxzang ", "; theta_xz (Degrees); Number of Events", 180, 0, 180);
	TH1F* Negativededxyzang = new TH1F("Negativededxyzang ", "; theta_yz (Degrees); Number of Events", 180, 0, 180);

	TH1F* DiffParticleeng = new TH1F("DiffParticleeng", "; Energy(MeV); Number of Events", 2000, -2000, 2000);

	TH1F* RatiolessTotDist = new TH1F("RatiolessTotDist", "Start Point Offset; Distance(cm); Number of Events", 600, 0, 150);
	TH1F* RatiomoreTotDist = new TH1F("RatiomoreTotDist", "Start Point Offset; Distance(cm); Number of Events", 600, 0, 150);

	TH1F* RatiolessTotxzAng = new TH1F("RatiolessTotxzAng", "; Angle(Degrees); Number of Events", 180, 0, 180);
	TH1F* RatiomoreTotxzAng = new TH1F("RatiomoreTotxzAng", "; Angle(Degrees); Number of Events", 180, 0, 180);

	TH1F* RatiolessTotyzAng = new TH1F("RatiolessTotyzAng", "; Angle(Degrees); Number of Events", 180, 0, 180);
	TH1F* RatiomoreTotyzAng = new TH1F("RatiomoreTotyzAng", "; Angle(Degrees); Number of Events", 180, 0, 180);

	TH1F* RatiolessTotdedx = new TH1F("RatiolessTotdedx", "; ; Number of Events", 60, -15, 15);
	TH1F* Startoffsetdistdedx = new TH1F("Startoffsetdistdedx", "; ; Number of Events", 60, -15, 15);

	TH1F* Startdir_MCshwrxzang = new TH1F("Startdir_MCshwrxzang ", "; theta (Degrees); Number of Events", 180, 0, 180);
	TH1F* Startdir_MCshwryzang = new TH1F("Startdir_MCshwryzang ", "; theta (Degrees); Number of Events", 180, 0, 180);

	TH1F* Startdir_shwrxzang = new TH1F("Startdir_shwrxzang ", "; theta (Degrees); Number of Events", 180, 0, 180);
	TH1F* Startdir_shwryzang = new TH1F("Startdir_shwryzang ", "; theta (Degrees); Number of Events", 180, 0, 180);

	TH1F* Startdir_firstpartxzang = new TH1F("Startdir_firstpartxzang ", "; theta (Degrees); Number of Events", 180, 0, 180);
	TH1F* Startdir_firstpartyzang = new TH1F("Startdir_firstpartyzang ", "; theta (Degrees); Number of Events", 180, 0, 180);

	TH1F* MCshwr_firstpartxzang = new TH1F("MCshwr_firstpartxzang ", "; theta (Degrees); Number of Events", 180, 0, 180);
	TH1F* MCshwr_firstpartyzang = new TH1F("MCshwr_firstpartyzang ", "; theta (Degrees); Number of Events", 180, 0, 180);

	TH1F* Shwr_firstpartxzang = new TH1F("Shwr_firstpartxzang ", "; theta (Degrees); Number of Events", 180, 0, 180);
	TH1F* Shwr_firstpartyzang = new TH1F("Shwr_firstpartyzang ", "; theta (Degrees); Number of Events", 180, 0, 180);

	TH1F* bestplanededx = new TH1F("bestplanededx ", "; MeV/cm; Number of Events", 50, -20, 20);
	TH1F* diffshower_dedx = new TH1F("diffshower_dedx ", "; MeV/cm; Number of Events", 50, -20, 20);

	TH1F* MCshower_dedx = new TH1F("MCshower_dedx ", "; ; Number of Events", 50, -50, 50);
	TH1F* Recoshowerbest_dedx = new TH1F("Recoshowerbest_dedx ", "; ; Number of Events", 50, -50, 50);

	TH1F* Recoshower1_dedx = new TH1F("Recoshower1_dedx ", "; ; Number of Events", 50, -50, 50);
	TH1F* Recoshower2_dedx = new TH1F("Recoshower2_dedx ", "; ; Number of Events", 50, -50, 50);
	TH1F* Recoshower3_dedx = new TH1F("Recoshower3_dedx ", "; ; Number of Events", 50, -50, 50);

	THStack * Negativededx = new THStack("Negativededx", "");

	TH1F* NotinTPCdedx = new TH1F("NotinTPCdedx", "; ; Number of Events", 25, -100, 0);
	TH1F* PoorRecodedx = new TH1F("PoorRecodedx", "; ; Number of Events", 25, -100, 0);
	TH1F* Negdedx = new TH1F("Negdedx", "; ; Number of Events", 25, -100, 0);

	TH1F* NegativeEnergyFirstPartdedx = new TH1F("NegativeEnergyFirstPartdedx ", "; Energy(MeV); Number of Events", 25, 100, 2000);

	TH1F* NegativededxShowerEnergy = new TH1F("NegativededxShowerEnergy ", "; Energy(MeV); Number of Events", 25, 100, 2000);
	TH1F* NegativededxFirstPart_MCshwreng = new TH1F("NegativededxFirstPart_MCshwreng ", "; Energy(MeV); Number of Events", 40, -2000, 2000);

	TH1F* NegativededxMCShowerEnergy = new TH1F("NegativededxMCShowerEnergy ", "; Energy(MeV); Number of Events", 25, 100, 2000);
	TH1F* Negativededxfirstpart_Recoshowerenergy = new TH1F("Negativededxfirstpart_Recoshowerenergy ", "; Energy(MeV); Number of Events", 40, -2000, 2000);
	TH1F* NegativededxMCshwr_Recoshowerenergy = new TH1F("NegativededxMCshwr_Recoshowerenergy ", "; Energy(MeV); Number of Events", 40, -2000, 2000);

	TH2D* Positionxy = new TH2D("Positionxy", " ; x distance (cm); y distance (cm)", 256, -128.0, 128.0, 117, -116.5, 116.5);
	TH2D* Positionyz = new TH2D("Positionyz", " ; y distance (cm); z distance (cm)", 117, -116.5, 116.5, 1036, 0, 1036);

	TH2D* DistvsAngleyz = new TH2D("DistvsAngleyz", " ; 3D distance (cm); yz Angle (degrees)", 250, 0, 10, 36, -180, 180);
	TH2D* DistvsAnglexz = new TH2D("DistvsAnglexz", " ; 3D distance (cm); xz Angle (degrees)", 250, 0, 10, 36, -180, 180);
	TH2D* DistvsAnglexy = new TH2D("DistvsAnglexy", " ; 3D distance (cm); xy Angle (degrees)", 250, 0, 10, 36, -180, 180);

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
		   shwr_startdcosy[N] -- the "j" component of the unit vector dfescribing the direction
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
		double EngMeV = mcshwr_CombEngE[0];	// Energy of the first particle in MeV
		
		double mindistance = 2.5;			// min distance that shower start can be from MC start
		double radtodegrees = 180 / 3.14;	// conversion factor
		double minangle = 15;				// minumum angle that is considered not too far off from actual

		// This is to calculate the distance between the starting point of the shower and the MC
		// any number of showers greater than zero
		
		double tempdist = 0;				// variable to help find the shortest distance of a shower to the MC start
		int goodshowernumber = 0;			// variables that saves the "best" shower...the shower that is closest to the MC start
		double xzdiff = 0;					// xz angle offset
		double yzdiff = 0;					// yz angle offset
		double MCxz_angle = 0;				// MC xz angle
		double MCyz_angle = 0;				// MC yz angle
		double MCxy_angle;					// MC xy angle
		double MCmag = 0;					// magnitude of the direction of the MC shower (using comb eng)
		double xz_angle = 0;				// reconstructed shower xz angle
		double yz_angle = 0;				// reconstructed shower yz angle
		double mag = 0;						// mag of direction of reconstructed showers
		double firstpartxz_angle = 0;		// xz angle using momentum of first MC particle
		double firstpartyz_angle = 0;		// yz angle using momentum of first MC particle
		double startxzdir = 0;				// using startdir to find xz direction
		double startyzdir = 0;				// using startdir to find yz direction

		// angle differences
		double startdir_MCshwrxzang = 0;	// Startdir - MC shower xz angle
		double startdir_MCshwryzang = 0;	// Startdir - MC shower yz angle
		double startdir_shwrxzang = 0;		// Startdir - reconstructed shower xz angle
		double startdir_shwryzang = 0;		// Startdir - reconstructed shower yz angle
		double startdir_firstpartxzang = 0;	// Startdir - first MC particle xz angle
		double startdir_firstpartyzang = 0;	// Startdir - first MC particle yz angle
		double mcshwr_firstpartxzang = 0;	// MC shower start - first MC particle xz angle
		double mcshwr_firstpartyzang = 0;	// MC shower start - first MC particle yz angle
		double shwr_firstpartxzang = 0;		// reconstructed shower - first MC particle xz angle
		double shwr_firstpartyzang = 0;		// reconstructed shower - first MC particle yz angle
		
		double startdirmag = 0;				// magnitude of the start direction	of MC shower using variables Startdir

		double smallestdiffdedx = 0;		// this is the smallest difference between the calculated dedx and the MC dedx	
		double tempdedx = 0;				// stores a temporary dedx value
		int bestdedx = 0;					// this is the plane that has the min dedx

		// if the number of showers is greater than one then we want to look at the energy and the angle offsets
		if (nshowers > 0)
		{
			MoreThanOneShowerEng->Fill(EngMeV);
			MoreThanOneShowerxzAng->Fill(xzdiff);
			MoreThanOneShoweryzAng->Fill(yzdiff);
		}

		// nshowers has to be greater than 0 because at nshower == 0 the variables (shower start, etc) are not empty
		if (nshowers > 0)
		{
			// distance formula to find the 3D displacement of the shower start and the MC shower start
			dist = sqrt(pow((shwr_startx[0] - mcshwr_CombEngX[0]), 2) + pow((shwr_starty[0] - mcshwr_CombEngY[0]), 2) + pow((shwr_startz[0] - mcshwr_CombEngZ[0]), 2));

			// if there is more than one shower we want the shower that is closest to the MC shower start
			if (nshowers > 1)
			{
				for (int i = 1; i < nshowers; i++)
				{
					// distance formula
					tempdist = sqrt(pow((shwr_startx[i] - mcshwr_CombEngX[0]), 2) + pow((shwr_starty[i] - mcshwr_CombEngY[0]), 2) + pow((shwr_startz[i] - mcshwr_CombEngZ[0]), 2));

					// we want the shower that is closest to the start of the MC shower
					if (dist > tempdist)
					{
						dist = tempdist;
						goodshowernumber = i;
					}
				}
			}

			// fills it in with the shower start offset
			StartPointOffset->Fill(dist);

			// xz and yz angles of the first particle
			firstpartxz_angle = TMath::ATan2(Px[0] / P[0], Pz[0] / P[0]);
			firstpartyz_angle = TMath::ATan2(Py[0] / P[0], Pz[0] / P[0]);

			// xz and yz angles using MC start directions
			startdirmag = sqrt(pow(mcshwr_StartDirX[0], 2) + pow(mcshwr_StartDirY[0], 2) + pow(mcshwr_StartDirZ[0], 2));
			startxzdir = TMath::ATan2(mcshwr_StartDirX[0] / startdirmag, mcshwr_StartDirZ[0] / startdirmag);
			startyzdir = TMath::ATan2(mcshwr_StartDirY[0] / startdirmag, mcshwr_StartDirZ[0] / startdirmag);

			// xz and yz angles of the MC shower
			MCmag = sqrt(pow(mcshwr_CombEngPx[0], 2) + pow(mcshwr_CombEngPy[0], 2) + pow(mcshwr_CombEngPz[0], 2));
			MCxz_angle = TMath::ATan2(mcshwr_CombEngPx[0] / MCmag, mcshwr_CombEngPz[0] / MCmag);
			MCyz_angle = TMath::ATan2(mcshwr_CombEngPy[0] / MCmag, mcshwr_CombEngPz[0] / MCmag);
			MCxy_angle = TMath::ATan2(mcshwr_CombEngPx[0] / MCmag, mcshwr_CombEngPy[0] / MCmag);

			// xz and yz angles of the reconstructed shower
			mag = sqrt(pow(shwr_startdcosx[goodshowernumber], 2) + pow(shwr_startdcosy[goodshowernumber], 2) + pow(shwr_startdcosz[goodshowernumber], 2));
			xz_angle = TMath::ATan2(shwr_startdcosx[goodshowernumber] / mag, shwr_startdcosz[goodshowernumber] / mag);
			yz_angle = TMath::ATan2(shwr_startdcosy[goodshowernumber] / mag, shwr_startdcosz[goodshowernumber] / mag);

			// xz and yz angle difference between the MC shower and the reconstructed shower
			xzdiff = fabs((xz_angle - MCxz_angle) * radtodegrees);
			yzdiff = fabs((yz_angle - MCyz_angle) * radtodegrees);

			// makes sure the angle magnitude is between 0 to 180
			xzdiff = Find_Angle(xzdiff);
			yzdiff = Find_Angle(yzdiff);

			// filled with the angle offsets
			xzdiffang->Fill(xzdiff);
			yzdiffang->Fill(yzdiff);

			// filled with the MC angles
			MCxzangle->Fill(MCxz_angle * radtodegrees);
			MCyzangle->Fill(MCyz_angle * radtodegrees);

			//filled with the shower angle
			YZ_angle->Fill(yz_angle * radtodegrees);
			XZ_angle->Fill(xz_angle * radtodegrees);

			// start direction - MC shower angle
			startdir_MCshwrxzang = fabs(startxzdir - MCxz_angle)*radtodegrees;
			startdir_MCshwryzang = fabs(startyzdir - MCyz_angle)*radtodegrees;
			


			// MC yz angle is greater than or equal to 50.0 degrees then we want to see the start position offset
			if (fabs(MCyz_angle * radtodegrees) >= 50.0)
			{
				Startpointoffsetgreaterthan50dist->Fill(dist);
			}

			// magnitude of MC yz angle is greater than or equal to 60.0 degrees then we want to see the start position offset
			if (fabs(MCyz_angle * radtodegrees) >= 60.0)
			{
				GoodAngledist->Fill(dist);
				Startpointoffsetgreaterthan60dist->Fill(dist);

				// magnitude of MC yz angle is between 90.0 and 180.0
				if ((fabs(MCyz_angle * radtodegrees) >= 90.0) && (fabs(MCyz_angle * radtodegrees) <= 180.0))
				{
					EndStartpointoffsetyzangledist->Fill(dist);
				}
				else
				{
					NotEndStartpointoffsetyzangledist->Fill(dist);
				}

				/*
				if (dist >= 1.2 && dist <= 1.8)
				{
					std::cout << "run: " << run << std::endl;
					std::cout << "subrun: " << subrun << std::endl;
					std::cout << "event: " << event << std::endl << std::endl;
				}
				*/
			}
			else
			{
				Startpointoffsetlessthan60dist->Fill(dist);
			}

			if (fabs(MCyz_angle * radtodegrees) >= 70.0)
			{
				Startpointoffsetgreaterthan70dist->Fill(dist);
			}

			if (fabs(MCyz_angle * radtodegrees) >= 80.0)
			{
				Startpointoffsetgreaterthan80dist->Fill(dist);
			}

			// if either angle is at 90 degrees
			if ((fabs(MCxz_angle * radtodegrees) >= 90.0) || (fabs(MCyz_angle * radtodegrees) >= 90.0))
			{
				Startpointoffsetgreaterthan90dist->Fill(dist);
			}

			if (fabs(MCyz_angle * radtodegrees) >= 100.0)
			{
				Startpointoffsetgreaterthan100dist->Fill(dist);
			}

			if (MCyz_angle * radtodegrees >= 60.0)
			{
				Anglegreaterthan60dist->Fill(dist);
			}
	
			else if (MCyz_angle * radtodegrees <= -60.0)
			{
				Anglelessthanminus60dist->Fill(dist);
			}
			
			// 2D of distance offset vs angle

			//if ((dist >= 1.0) && (dist <= 2.0))
			//{
				DistvsAngleyz->Fill(dist, MCyz_angle * radtodegrees);
				DistvsAnglexz->Fill(dist, MCxz_angle * radtodegrees);
				DistvsAnglexy->Fill(dist, MCxy_angle * radtodegrees);
				
			//}

			//magnitude of the MC xz angle is greater than or equal to 60.0 degrees
			if ((fabs(MCxz_angle * radtodegrees) >= 60.0))
			{
				Startpointoffsetxzangledistlessthan->Fill(dist);

				// magnitude of the MC xz angle is between 90.0 and 180.0 degrees
				if ((fabs(MCxz_angle * radtodegrees) >= 90.0) && (fabs(MCxz_angle * radtodegrees) <= 180.0))
				{
					EndStartpointoffsetxzangledist->Fill(dist);
				}
				// or not
				else
				{
					NotEndStartpointoffsetxzangledist->Fill(dist);
				}
			}

			// parallel to either of the three wire planes
			if ((MCyz_angle * radtodegrees <= 35.0) && (MCyz_angle * radtodegrees >= 25.0) || (MCyz_angle * radtodegrees <= -145.0) && (MCyz_angle * radtodegrees >= -155.0)
				|| (MCyz_angle * radtodegrees >= -35.0) && (MCyz_angle * radtodegrees <= -25.0) || (MCyz_angle * radtodegrees >= 145.0) && (MCyz_angle * radtodegrees <= 155.0)
			 || (MCyz_angle * radtodegrees >= 85.0) && (MCyz_angle * radtodegrees <= 95.0) || (MCyz_angle * radtodegrees >= -95.0) && (MCyz_angle * radtodegrees <= -85.0))
			{
				ParallelAngledist->Fill(dist);
			}
			else
			{
				NotParallelAngledist->Fill(dist);
			}
			// this checks if the MC yz angle is approximately parallel to the U wire plane
			// not actually sure if this corresponds to the U plane or the V plane
			if ((MCyz_angle * radtodegrees <= 35.0) && (MCyz_angle * radtodegrees >= 25.0) || (MCyz_angle * radtodegrees <= -145.0) && (MCyz_angle * radtodegrees >= -155.0))
			{
				Uplanedist->Fill(dist);

				//std::cout << "run: " << run << std::endl;
				//std::cout << "subrun: " << subrun << std::endl;
				//std::cout << "event: " << event << std::endl << std::endl;
			}

			// if the angle is not parallel to the U/V plane then is the start position offset
			else
			{
				Unotplanedist->Fill(dist);
			}

			// this checks if the MC yz angle is approximately parallel to the V wire plane
			// not actually sure if this corresponds to the U plane or the V plane
			if ((MCyz_angle * radtodegrees >= -35.0) && (MCyz_angle * radtodegrees <= -25.0) || (MCyz_angle * radtodegrees >= 145.0) && (MCyz_angle * radtodegrees <= 155.0))
			{
				Vplanedist->Fill(dist);
			}
			// if the angle is not parallel to the U/V plane then is the start position offset
			else
			{
				Vnotplanedist->Fill(dist);
			}

			// this checks if the MC yz angle is approximately parallel to the Y wire plane
			if ((MCyz_angle * radtodegrees >= 85.0) && (MCyz_angle * radtodegrees <= 95.0) || (MCyz_angle * radtodegrees >= -95.0) && (MCyz_angle * radtodegrees <= -85.0))
			{
				Yplanedist->Fill(dist);
			}
			// if the angle is not parallel to the Y plane then what is the start position offset
			else
			{
				Ynotplanedist->Fill(dist);
			}
			
			// checks what is 0 degrees and what is 90 degrees
			/*if (fabs(MCxz_angle * radtodegrees) <= 2.0)
			{
				std::cout << "x: " << Px[0] << std::endl;
				std::cout << "y: " << Py[0] << std::endl;
				std::cout << "z: " << Pz[0] << std::endl;
			}
			*/

			startdir_MCshwrxzang = Find_Angle(startdir_MCshwrxzang);
			startdir_MCshwryzang = Find_Angle(startdir_MCshwryzang);

			Startdir_MCshwrxzang->Fill(startdir_MCshwrxzang);
			Startdir_MCshwryzang->Fill(startdir_MCshwryzang);

			// start direction - shower angle
			startdir_shwrxzang = fabs(startxzdir - xz_angle)*radtodegrees;
			startdir_shwryzang = fabs(startyzdir - yz_angle)*radtodegrees;

			startdir_shwrxzang = Find_Angle(startdir_shwrxzang);
			startdir_shwryzang = Find_Angle(startdir_shwryzang);

			Startdir_shwrxzang->Fill(startdir_shwrxzang);
			Startdir_shwryzang->Fill(startdir_shwryzang);

			// start direction - MC first particle
			startdir_firstpartxzang = fabs(startxzdir - firstpartxz_angle)*radtodegrees;
			startdir_firstpartyzang = fabs(startyzdir - firstpartyz_angle)*radtodegrees;

			startdir_firstpartxzang = Find_Angle(startdir_firstpartxzang);
			startdir_firstpartyzang = Find_Angle(startdir_firstpartyzang);

			Startdir_firstpartxzang->Fill(startdir_firstpartxzang);
			Startdir_firstpartyzang->Fill(startdir_firstpartyzang);

			// MC shower - MC first particle
			mcshwr_firstpartxzang = fabs(MCxz_angle - firstpartxz_angle)*radtodegrees;
			mcshwr_firstpartyzang = fabs(MCyz_angle - firstpartyz_angle)*radtodegrees;

			mcshwr_firstpartxzang = Find_Angle(mcshwr_firstpartxzang);
			mcshwr_firstpartyzang = Find_Angle(mcshwr_firstpartyzang);

			MCshwr_firstpartxzang->Fill(mcshwr_firstpartxzang);
			MCshwr_firstpartyzang->Fill(mcshwr_firstpartyzang);

			// shower start - first particle
			shwr_firstpartxzang = fabs(xz_angle - firstpartxz_angle)*radtodegrees;
			shwr_firstpartyzang = fabs(yz_angle - firstpartyz_angle)*radtodegrees;

			shwr_firstpartxzang = Find_Angle(shwr_firstpartxzang);
			shwr_firstpartyzang = Find_Angle(shwr_firstpartyzang);

			Shwr_firstpartxzang->Fill(shwr_firstpartxzang);
			Shwr_firstpartyzang->Fill(shwr_firstpartyzang);

			// we also want to compare the starting position of the shower to the starting position of the first particle
			// any shower number greater than 0
			if (pdg[0] == 11 || pdg[0] == -11)
			{
					// difference in the reconstructed shower start position and the first particle in the MC truth
					Diffxdist->Fill(shwr_startx[goodshowernumber] - StartPointx[0]);
					Diffydist->Fill(shwr_starty[goodshowernumber] - StartPointy[0]);
					Diffzdist->Fill(shwr_startz[goodshowernumber] - StartPointz[0]);

					// difference in the reconstructed shower start position and the MC shower comb energy start
					DiffMCCombxdist->Fill(shwr_startx[goodshowernumber] - mcshwr_CombEngX[0]);
					DiffMCCombydist->Fill(shwr_starty[goodshowernumber] - mcshwr_CombEngY[0]);
					DiffMCCombzdist->Fill(shwr_startz[goodshowernumber] - mcshwr_CombEngZ[0]);

					// difference in the reconstructed shower start and the MC shower start
					DiffMCxdist->Fill(shwr_startx[goodshowernumber] - mcshwr_startX[0]);
					DiffMCydist->Fill(shwr_starty[goodshowernumber] - mcshwr_startY[0]);
					DiffMCzdist->Fill(shwr_startz[goodshowernumber] - mcshwr_startZ[0]);

					// difference in the MC shower comb energy start and the MC shower start
					DiffMCCxdist->Fill(mcshwr_CombEngX[0] - mcshwr_startX[0]);
					DiffMCCydist->Fill(mcshwr_CombEngY[0] - mcshwr_startY[0]);
					DiffMCCzdist->Fill(mcshwr_CombEngZ[0] - mcshwr_startZ[0]);

					// MC yz angle is greater than 60 degrees then fill with the shower start difference
					if ((fabs(MCyz_angle * radtodegrees) >= 60.0))
					{
						Diffxdistmaggreaterthan60->Fill(shwr_startx[goodshowernumber] - StartPointx[0]);
						Diffydistmaggreaterthan60->Fill(shwr_starty[goodshowernumber] - StartPointy[0]);
						Diffzdistmaggreaterthan60->Fill(shwr_startz[goodshowernumber] - StartPointz[0]);
					
						//std::cout << "run: " << run << std::endl;
						//std::cout << "subrun: " << subrun << std::endl;
						//std::cout << "event: " << event << std::endl << std::endl;
						
					}

					else
					{
						Diffxdistmaglessthan60->Fill(shwr_startx[goodshowernumber] - StartPointx[0]);
						Diffydistmaglessthan60->Fill(shwr_starty[goodshowernumber] - StartPointy[0]);
						Diffzdistmaglessthan60->Fill(shwr_startz[goodshowernumber] - StartPointz[0]);
					}

					if ((MCyz_angle * radtodegrees >= 60.0) && (MCyz_angle * radtodegrees <= 180.0))
					{
						Diffxdistgreaterthan60->Fill(shwr_startx[goodshowernumber] - StartPointx[0]);
						Diffydistgreaterthan60->Fill(shwr_starty[goodshowernumber] - StartPointy[0]);
						Diffzdistgreaterthan60->Fill(shwr_startz[goodshowernumber] - StartPointz[0]);
					}

					else if ((MCyz_angle * radtodegrees >= -180.0) && (MCyz_angle * radtodegrees <= -60.0))
					{
						Diffxdistlessthanminus60->Fill(shwr_startx[goodshowernumber] - StartPointx[0]);
						Diffydistlessthanminus60->Fill(shwr_starty[goodshowernumber] - StartPointy[0]);
						Diffzdistlessthanminus60->Fill(shwr_startz[goodshowernumber] - StartPointz[0]);
					}

					// we want to see how the start position is bias
					// whether the shower start is before the actual shower start or if it is after the atual shower start
					if (Px[0] > 0)
					{
						Posmomentumxdist->Fill(shwr_startx[goodshowernumber] - StartPointx[0]);
					}

					else
					{
						Negmomentumxdist->Fill(shwr_startx[goodshowernumber] - StartPointx[0]);
					}

					if (Py[0] > 0)
					{
						Posmomentumydist->Fill(shwr_starty[goodshowernumber] - StartPointy[0]);
					}

					else
					{
						Negmomentumydist->Fill(shwr_starty[goodshowernumber] - StartPointy[0]);
					}

					if (Pz[0] > 0)
					{
						Posmomentumzdist->Fill(shwr_startz[goodshowernumber] - StartPointz[0]);
					}

					else
					{
						Negmomentumzdist->Fill(shwr_startz[goodshowernumber] - StartPointz[0]);
					}
			
			}

			else if (pdg[0] == 22)
			{
				// calculate the start positon offset
				// for first particle in MC truth
				Diffxdist->Fill(shwr_startx[goodshowernumber] - EndPointx[0]);
				Diffydist->Fill(shwr_starty[goodshowernumber] - EndPointy[0]);
				Diffzdist->Fill(shwr_startz[goodshowernumber] - EndPointz[0]);

				//for MC shower comb energy
				DiffMCCombxdist->Fill(shwr_startx[goodshowernumber] - mcshwr_CombEngX[0]);
				DiffMCCombydist->Fill(shwr_starty[goodshowernumber] - mcshwr_CombEngY[0]);
				DiffMCCombzdist->Fill(shwr_startz[goodshowernumber] - mcshwr_CombEngZ[0]);

				//  for MC shower end
				DiffMCxdist->Fill(shwr_startx[goodshowernumber] - mcshwr_endX[0]);
				DiffMCydist->Fill(shwr_starty[goodshowernumber] - mcshwr_endY[0]);
				DiffMCzdist->Fill(shwr_startz[goodshowernumber] - mcshwr_endZ[0]);

				DiffMCCxdist->Fill(mcshwr_CombEngX[0] - mcshwr_endX[0]);
				DiffMCCydist->Fill(mcshwr_CombEngY[0] - mcshwr_endY[0]);
				DiffMCCzdist->Fill(mcshwr_CombEngZ[0] - mcshwr_endZ[0]);
				
				if ((fabs(MCyz_angle * radtodegrees) >= 60.0))
				{
					Diffxdistmaggreaterthan60->Fill(shwr_startx[goodshowernumber] - EndPointx[0]);
					Diffydistmaggreaterthan60->Fill(shwr_starty[goodshowernumber] - EndPointy[0]);
					Diffzdistmaggreaterthan60->Fill(shwr_startz[goodshowernumber] - EndPointz[0]);
				}

				else
				{
					Diffxdistmaglessthan60->Fill(shwr_startx[goodshowernumber] - EndPointx[0]);
					Diffydistmaglessthan60->Fill(shwr_starty[goodshowernumber] - EndPointy[0]);
					Diffzdistmaglessthan60->Fill(shwr_startz[goodshowernumber] - EndPointz[0]);
				}

				if ((MCyz_angle * radtodegrees >= 60.0) && (MCyz_angle * radtodegrees <= 180.0))
				{
					Diffxdistgreaterthan60->Fill(shwr_startx[goodshowernumber] - EndPointx[0]);
					Diffydistgreaterthan60->Fill(shwr_starty[goodshowernumber] - EndPointy[0]);
					Diffzdistgreaterthan60->Fill(shwr_startz[goodshowernumber] - EndPointz[0]);
				}

				else if ((MCyz_angle * radtodegrees >= -180.0) && (MCyz_angle * radtodegrees <= -60.0))
				{
					Diffxdistlessthanminus60->Fill(shwr_startx[goodshowernumber] - EndPointx[0]);
					Diffydistlessthanminus60->Fill(shwr_starty[goodshowernumber] - EndPointy[0]);
					Diffzdistlessthanminus60->Fill(shwr_startz[goodshowernumber] - EndPointz[0]);
				}

				// we want to see how the start position is bias
				// whether the shower start is before the actual shower start or if it is after the atual shower start
				if (Px[0] > 0)
				{
					Posmomentumxdist->Fill(shwr_startx[goodshowernumber] - EndPointx[0]);
				}
				else
				{
					Negmomentumxdist->Fill(shwr_startx[goodshowernumber] - EndPointx[0]);
				}
				if (Py[0] > 0)
				{
					Posmomentumydist->Fill(shwr_starty[goodshowernumber] - EndPointy[0]);
				}
				else
				{
					Negmomentumydist->Fill(shwr_starty[goodshowernumber] - EndPointy[0]);
				}
				if (Pz[0] > 0)
				{
					Posmomentumzdist->Fill(shwr_startz[goodshowernumber] - EndPointz[0]);
				}
				else
				{
					Negmomentumzdist->Fill(shwr_startz[goodshowernumber] - EndPointz[0]);
				}
			}

			// if the angles are within the cut then the boolean variable is true
			if (xzdiff < minangle)
			{
				XZAngle = true;
			}
			if (yzdiff < minangle)
			{
				YZAngle = true;
			}

			// if both booleans are true then Angle is true
			if (XZAngle && YZAngle)
			{
				Angle = true;
			}
		}

		// looking at events with only one shower
		// we first find the plane that has the smallest dedx value
		// compare that value with the value of the dedx of the best plane
		if (nshowers > 0)
		{
			smallestdiffdedx = 0;	// this is the smallest difference between the calculated dedx and the MC dedx
			bestdedx = 0;			// this is the plane that has the smallest difference in dedx
			tempdedx = 0;			// this is a variable holder

			for (int i = 0; i < 3; i++)
			{
				smallestdiffdedx = fabs(mcshwr_dEdx[0] - shwr_dedx[0][0]);
				tempdedx = fabs(mcshwr_dEdx[0] - shwr_dedx[0][i]);

				if (smallestdiffdedx > tempdedx)
				{
					smallestdiffdedx = tempdedx;
					bestdedx = i;
				}
			}

			// checks to see if the best plane has the best dedx?
			bestplanededx->Fill(shwr_dedx[0][bestdedx] - shwr_dedx[0][shwr_bestplane[0]]);

			// this is the difference in dedx of the MC and of the Reconstructed Shower with the dedx of the min plane
			diffshower_dedx->Fill(shwr_dedx[goodshowernumber][bestdedx] - mcshwr_dEdx[0]);

			MCshower_dedx->Fill(mcshwr_dEdx[0]);
			Recoshowerbest_dedx->Fill(shwr_dedx[goodshowernumber][bestdedx]);

			Recoshower1_dedx->Fill(shwr_dedx[0][0]);
			Recoshower2_dedx->Fill(shwr_dedx[0][1]);
			Recoshower3_dedx->Fill(shwr_dedx[0][2]);
		}

		// negative dedx
		// we first check if any of the planes have a negative dedx
		if ((shwr_dedx[0][0] < 0) || (shwr_dedx[0][1] < 0) || (shwr_dedx[0][2]) < 0))
		{
			// fill with the position of the first MC particle
			if (pdg[0] == 11 || pdg[0] == -11)
			{
				Positionxy->Fill(StartPointx[0], StartPointy[0]);
				Positionyz->Fill(StartPointy[0], StartPointz[0]);
			}
			else
			{
				Positionxy->Fill(EndPointx[0], EndPointy[0]);
				Positionyz->Fill(StartPointy[0], StartPointz[0]);
			}
			// values of the negative dedx in the first plane
			if ((shwr_dedx[0][0] < 0))
			{
				Negdedx->Fill(shwr_dedx[0][0]);

				// if dedx is negative is the shower in the tpc?
				if (mcshwr_dEdx[0] == -99999)
				{
					NotinTPCdedx->Fill(shwr_dedx[0][0]);
				}
				else
				{
					// if it is in the TPC is it poorly reconstructed?
					if ((dist > 2.5) || (xzdiff > 15) || (yzdiff > 15))
					{
						PoorRecodedx->Fill(shwr_dedx[0][0]);
					}
				}
			}

			// values of the negative dedx in the second plane
			else if (shwr_dedx[0][1] < 0)
			{
				Negdedx->Fill(shwr_dedx[0][1]);

				// if dedx is negative is the shower in the tpc?
				if (mcshwr_dEdx[0] == -99999)
				{
					NotinTPCdedx->Fill(shwr_dedx[0][1]);
				}

				else
				{
					// if it is in the TPC is it poorly reconstructed?
					if ((dist > 2.5) || (xzdiff > 15) || (yzdiff > 15))
					{
						PoorRecodedx->Fill(shwr_dedx[0][0]);
					}
				}
			}

			// values of the negative dedx in the third plane
			else if (shwr_dedx[0][2]) < 0)
			{
				Negdedx->Fill(shwr_dedx[0][2]);

				// if dedx is negative is the shower in the tpc?
				if (mcshwr_dEdx[0] == -99999)
				{
					NotinTPCdedx->Fill(shwr_dedx[0][2]);
				}

				else
				{
					// if it is in the TPC is it poorly reconstructed?
					if ((dist > 2.5) || (xzdiff > 15) || (yzdiff > 15))
					{
						PoorRecodedx->Fill(shwr_dedx[0][0]);
					}
				}
			}
		}

		// looking at showers with negative dedx
		if (nshowers > 0)
		{
			if ((shwr_dedx[0][0] < 0) || (shwr_dedx[0][1] < 0) || (shwr_dedx[0][2]) < 0))
			{
				Negativededxdist->Fill(dist);
				Negativededxxzang->Fill(xzdiff);
				Negativededxyzang->Fill(yzdiff);
				
				NegativeEnergyFirstPartdedx->Fill(Eng[0] * 1000);
				NegativededxMCShowerEnergy->Fill(mcshwr_CombEngE[0]);
				NegativededxFirstPart_MCshwreng->Fill(Eng[0] * 1000 - mcshwr_CombEngE[0]);

				NegativededxShowerEnergy->Fill(shwr_totEng[goodshowernumber][bestdedx]);
				Negativededxfirstpart_Recoshowerenergy->Fill(Eng[0] * 1000 - shwr_totEng[goodshowernumber][bestdedx]);
				NegativededxMCshwr_Recoshowerenergy->Fill(mcshwr_CombEngE[0] - shwr_totEng[goodshowernumber][bestdedx]);
			}	
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

		// good reconstructed showers
		// must have correct shower direction and shower starting position and only one shower
		if (nshowers == 1)	// only want one shower
		{
			Nshowers = true;
			NumShowersGoodRecoEng->Fill(EngMeV);	// if there is only one shower then plot the energy of that shower
			OneShowerxzAng->Fill(xzdiff);			// if there is only one shower then plot the xz diff angle
			OneShoweryzAng->Fill(yzdiff);			// if there is only one shower then plot the yz diff angle
		
			oneshowerstartx->Fill(shwr_startx[0]);
		
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

		if (nshowers == 0)
		{
			NoShowerEng->Fill(EngMeV);
			//NoShowerAng->Fill(xdiff);

			//std::cout << "dist: " << dist << std::endl;
			//std::cout << "shwr: " << shwr_startx[0] << std::endl;
			//std::cout << "endp: " << StartPointx[0] << stdl::endl;
			//std::cout << "show: " << nshowers << std::endl << std::endl;

			noshowerstartx->Fill(shwr_startx[0]);
			//noshowshoweng->Fill(shwr_totEng)
			//std::cout << "shower number: " << nshowers << std::endl;
			//std::cout << "shower energy: " << shwr_totEng[0][0] << std::endl;
			noshowerenergy->Fill(shwr_totEng[0][0]);

			double ratio = double(geant_list_size_in_tpcAV / (1.0 * geant_list_size));
			//std::cout << ratio << std::endl;

			// how much of the shower is contained and how does that affect the energy of the shower
			if (ratio < 0.25)
			{
				Nshowersratioeng->Fill(EngMeV);
			}

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

		// one shower within good start and angle offsets
		if (Nshowers && dist <= 1.0 && Angle)
		{
			GoodRecoEng->Fill(EngMeV);
			//Angle = false;
		}

		// showers with good start and angle offsets
		if (nshowers > 0 && Dist && Angle)
		{
			ShowersGoodRecoEng->Fill(EngMeV);
		}

		// one shower with bad start and angle offsets
		if (Nshowers && !Dist && !Angle)
		{
			NumShowersBadRecoEng->Fill(EngMeV);
		}

		//std::cout << "MC shower start x: " << mcshwr_startX[0] << std::endl;
		//std::cout << "MC shower start Comb x: " << mcshwr_CombEngX[0] << std::endl;
		//std::cout << "MC shower end:" << mcshwr_endX[0] << std::endl;
		//std::cout << "EndPointx[0]: " << EndPointx[0] << std::endl;
		//std::cout << "Reco Shower start x: " << shwr_startx[0] << std::endl << std::endl;

		Energy->Fill(EngMeV);

		// find the total energy of all the showers per event
		// so we can compare this with the MC shower energy

		double toteng = 0;
		
		if (nshowers > 0)
		{
			//for (int i = 0; i < nshowers; i++)
			//{
				// this is the total energy of all the showers
			//	toteng += shwr_totEng[i][shwr_bestplane[i]];
			//}

			Showereng->Fill(shwr_totEng[goodshowernumber][shwr_bestplane[goodshowernumber]]);

			FirstParticleEng->Fill(Eng[0] * 1000);

			// we want to compare the total energy of all the showers to the MC truth shower energy
			DiffParticleeng->Fill(shwr_totEng[goodshowernumber][shwr_bestplane[goodshowernumber]] - EngMeV);

			// if its under a certain ratio what are the characteristics of the shower
			if (shwr_totEng[goodshowernumber][shwr_bestplane[goodshowernumber]] / EngMeV <= 0.50)
			{
				//RatiolessTotDist->Fill(dist);
				//RatiolessTotxzAng->Fill(xzdiff);
				//RatiolessTotyzAng->Fill(yzdiff);
				RatiolessTotdedx->Fill(shwr_dedx[goodshowernumber][bestdedx] - mcshwr_dEdx[0]);
			}

			// if the start point offset in within the bump what is the dedx
			if (dist >= 1.0 && dist <= 2.0)
			{
				Startoffsetdistdedx->Fill(mcshwr_dEdx[0]);
			}

			//else if ()
			//{
			//	RatiomoreTotDist->Fill(dist);
			//	RatiomoreTotxzAng->Fill(xzdiff);
			//	RatiomoreTotyzAng->Fill(yzdiff);
			//}
		
		}
		
		// reset the boolean variables
		Angle = false;
		Nshowers = false;
		Dist = false;

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

	TCanvas* c8 = new TCanvas("c8", "", 700, 700);
	c8->SetLeftMargin(.1);
	c8->SetBottomMargin(.1);
	c8->SetTopMargin(.075);
	c8->SetRightMargin(.15);
	c8->cd();

	OneShoweryzAng->SetLineColor(kBlack);
	OneShoweryzAng->SetLineWidth(3);
	OneShoweryzAng->Draw();

	TCanvas* c9 = new TCanvas("c9", "", 700, 700);
	c9->SetLeftMargin(.1);
	c9->SetBottomMargin(.1);
	c9->SetTopMargin(.075);
	c9->SetRightMargin(.15);
	c9->cd();

	EffNumShowers->Divide(MoreThanOneShowerEng, Energy);

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

	//EffShowersGoodRecoEng->Divide(ShowersGoodRecoEng, Energy);

	//EffShowersGoodRecoEng->SetLineColor(kGreen);
	//EffShowersGoodRecoEng->SetLineWidth(3);
	//EffShowersGoodRecoEng->SetStats(false);
	//EffShowersGoodRecoEng->Draw("same");
	
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
/*
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

	XZ_angle->SetLineColor(kRed);
	XZ_angle->Draw();

	TCanvas* c30 = new TCanvas("c30", "", 700, 700);
	c30->SetLeftMargin(.1);
	c30->SetBottomMargin(.1);
	c30->SetTopMargin(.075);
	c30->SetRightMargin(.15);
	c30->cd();

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

	
	TCanvas* c49 = new TCanvas("c49", "", 700, 700);
	c49->SetLeftMargin(.1);
	c49->SetBottomMargin(.1);
	c49->SetTopMargin(.075);
	c49->SetRightMargin(.15);
	c49->cd();

	Energy->SetLineColor(kBlue);
	Energy->SetLineWidth(3);
	Energy->SetStats(true);
	Energy->Draw();

	Showereng->SetLineColor(kRed);
	Showereng->SetLineWidth(3);
	Showereng->SetStats(true);
	Showereng->Draw("same");

	FirstParticleEng->SetLineColor(kGreen);
	FirstParticleEng->SetLineWidth(3);
	FirstParticleEng->SetStats(true);
	FirstParticleEng->Draw("same");
	

	TCanvas* c50 = new TCanvas("c50", "", 700, 700);
	c50->SetLeftMargin(.1);
	c50->SetBottomMargin(.1);
	c50->SetTopMargin(.075);
	c50->SetRightMargin(.15);
	c50->cd();

	EffEng->Divide(Showereng, Energy);

	EffEng->SetLineColor(kBlue);
	EffEng->SetLineWidth(3);
	EffEng->SetStats(true);
	EffEng->Draw();

*/
	TCanvas* c51 = new TCanvas("c51", "", 700, 700);
	c51->SetLeftMargin(.1);
	c51->SetBottomMargin(.1);
	c51->SetTopMargin(.075);
	c51->SetRightMargin(.15);
	c51->cd();

	DiffMCCxdist->SetLineColor(kBlue);
	DiffMCCxdist->SetLineWidth(3);
	DiffMCCxdist->SetStats(true);
	DiffMCCxdist->Draw();

	TCanvas* c52 = new TCanvas("c52", "", 700, 700);
	c52->SetLeftMargin(.1);
	c52->SetBottomMargin(.1);
	c52->SetTopMargin(.075);
	c52->SetRightMargin(.15);
	c52->cd();

	DiffMCCydist->SetLineColor(kBlue);
	DiffMCCydist->SetLineWidth(3);
	DiffMCCydist->SetStats(true);
	DiffMCCydist->Draw();

	TCanvas* c53 = new TCanvas("c53", "", 700, 700);
	c53->SetLeftMargin(.1);
	c53->SetBottomMargin(.1);
	c53->SetTopMargin(.075);
	c53->SetRightMargin(.15);
	c53->cd();

	DiffMCCzdist->SetLineColor(kBlue);
	DiffMCCzdist->SetLineWidth(3);
	DiffMCCzdist->SetStats(true);
	DiffMCCzdist->Draw();

	TCanvas* c54 = new TCanvas("c54", "", 700, 700);
	c54->SetLeftMargin(.1);
	c54->SetBottomMargin(.1);
	c54->SetTopMargin(.075);
	c54->SetRightMargin(.15);
	c54->cd();

	DiffParticleeng->SetLineColor(kBlue);
	DiffParticleeng->SetLineWidth(3);
	DiffParticleeng->SetStats(true);
	DiffParticleeng->Draw();

	TCanvas* c55 = new TCanvas("c55", "", 700, 700);
	c55->SetLeftMargin(.1);
	c55->SetBottomMargin(.1);
	c55->SetTopMargin(.075);
	c55->SetRightMargin(.15);
	c55->cd();

	RatiolessTotDist->SetLineColor(kBlue);
	RatiolessTotDist->SetLineWidth(3);
	RatiolessTotDist->SetStats(true);
	RatiolessTotDist->Draw();

	TCanvas* c56 = new TCanvas("c56", "", 700, 700);
	c56->SetLeftMargin(.1);
	c56->SetBottomMargin(.1);
	c56->SetTopMargin(.075);
	c56->SetRightMargin(.15);
	c56->cd();

	RatiomoreTotDist->SetLineColor(kBlue);
	RatiomoreTotDist->SetLineWidth(3);
	RatiomoreTotDist->SetStats(true);
	RatiomoreTotDist->Draw();

	TCanvas* c58 = new TCanvas("c58", "", 700, 700);
	c58->SetLeftMargin(.1);
	c58->SetBottomMargin(.1);
	c58->SetTopMargin(.075);
	c58->SetRightMargin(.15);
	c58->cd();

	RatiolessTotxzAng->SetLineColor(kBlue);
	RatiolessTotxzAng->SetLineWidth(3);
	RatiolessTotxzAng->SetStats(true);
	RatiolessTotxzAng->Draw();

	TCanvas* c59 = new TCanvas("c59", "", 700, 700);
	c59->SetLeftMargin(.1);
	c59->SetBottomMargin(.1);
	c59->SetTopMargin(.075);
	c59->SetRightMargin(.15);
	c59->cd();

	RatiolessTotyzAng->SetLineColor(kBlue);
	RatiolessTotyzAng->SetLineWidth(3);
	RatiolessTotyzAng->SetStats(true);
	RatiolessTotyzAng->Draw();

	TCanvas* c62 = new TCanvas("c62", "", 700, 700);
	c62->SetLeftMargin(.1);
	c62->SetBottomMargin(.1);
	c62->SetTopMargin(.075);
	c62->SetRightMargin(.15);
	c62->cd();

	RatiomoreTotxzAng->SetLineColor(kBlue);
	RatiomoreTotxzAng->SetLineWidth(3);
	RatiomoreTotxzAng->SetStats(true);
	RatiomoreTotxzAng->Draw();

	TCanvas* c63 = new TCanvas("c63", "", 700, 700);
	c63->SetLeftMargin(.1);
	c63->SetBottomMargin(.1);
	c63->SetTopMargin(.075);
	c63->SetRightMargin(.15);
	c63->cd();

	RatiomoreTotyzAng->SetLineColor(kBlue);
	RatiomoreTotyzAng->SetLineWidth(3);
	RatiomoreTotyzAng->SetStats(true);
	RatiomoreTotyzAng->Draw();

	TCanvas* c64 = new TCanvas("c64", "", 700, 700);
	c64->SetLeftMargin(.1);
	c64->SetBottomMargin(.1);
	c64->SetTopMargin(.075);
	c64->SetRightMargin(.15);
	c64->cd();

	Startdir_MCshwrxzang->SetLineColor(kBlue);
	Startdir_MCshwrxzang->SetLineWidth(3);
	Startdir_MCshwrxzang->SetStats(true);
	Startdir_MCshwrxzang->Draw();


	TCanvas* c65 = new TCanvas("c65", "", 700, 700);
	c65->SetLeftMargin(.1);
	c65->SetBottomMargin(.1);
	c65->SetTopMargin(.075);
	c65->SetRightMargin(.15);
	c65->cd();

	Startdir_MCshwryzang->SetLineColor(kBlue);
	Startdir_MCshwryzang->SetLineWidth(3);
	Startdir_MCshwryzang->SetStats(true);
	Startdir_MCshwryzang->Draw();

	TCanvas* c66 = new TCanvas("c66", "", 700, 700);
	c66->SetLeftMargin(.1);
	c66->SetBottomMargin(.1);
	c66->SetTopMargin(.075);
	c66->SetRightMargin(.15);
	c66->cd();

	Startdir_shwrxzang->SetLineColor(kBlue);
	Startdir_shwrxzang->SetLineWidth(3);
	Startdir_shwrxzang->SetStats(true);
	Startdir_shwrxzang->Draw();

	TCanvas* c67 = new TCanvas("c67", "", 700, 700);
	c67->SetLeftMargin(.1);
	c67->SetBottomMargin(.1);
	c67->SetTopMargin(.075);
	c67->SetRightMargin(.15);
	c67->cd();

	Startdir_shwryzang->SetLineColor(kBlue);
	Startdir_shwryzang->SetLineWidth(3);
	Startdir_shwryzang->SetStats(true);
	Startdir_shwryzang->Draw();

	
	TCanvas* c68 = new TCanvas("c68", "", 700, 700);
	c68->SetLeftMargin(.1);
	c68->SetBottomMargin(.1);
	c68->SetTopMargin(.075);
	c68->SetRightMargin(.15);
	c68->cd();

	Startdir_firstpartxzang->SetLineColor(kBlue);
	Startdir_firstpartxzang->SetLineWidth(3);
	Startdir_firstpartxzang->SetStats(true);
	Startdir_firstpartxzang->Draw();

	TCanvas* c69 = new TCanvas("c69", "", 700, 700);
	c69->SetLeftMargin(.1);
	c69->SetBottomMargin(.1);
	c69->SetTopMargin(.075);
	c69->SetRightMargin(.15);
	c69->cd();

	Startdir_firstpartyzang->SetLineColor(kBlue);
	Startdir_firstpartyzang->SetLineWidth(3);
	Startdir_firstpartyzang->SetStats(true);
	Startdir_firstpartyzang->Draw();


	TCanvas* c70 = new TCanvas("c70", "", 700, 700);
	c70->SetLeftMargin(.1);
	c70->SetBottomMargin(.1);
	c70->SetTopMargin(.075);
	c70->SetRightMargin(.15);
	c70->cd();

	MCshwr_firstpartxzang->SetLineColor(kBlue);
	MCshwr_firstpartxzang->SetLineWidth(3);
	MCshwr_firstpartxzang->SetStats(true);
	MCshwr_firstpartxzang->Draw();

	TCanvas* c71 = new TCanvas("c71", "", 700, 700);
	c71->SetLeftMargin(.1);
	c71->SetBottomMargin(.1);
	c71->SetTopMargin(.075);
	c71->SetRightMargin(.15);
	c71->cd();

	MCshwr_firstpartyzang->SetLineColor(kBlue);
	MCshwr_firstpartyzang->SetLineWidth(3);
	MCshwr_firstpartyzang->SetStats(true);
	MCshwr_firstpartyzang->Draw();

	TCanvas* c72 = new TCanvas("c72", "", 700, 700);
	c72->SetLeftMargin(.1);
	c72->SetBottomMargin(.1);
	c72->SetTopMargin(.075);
	c72->SetRightMargin(.15);
	c72->cd();

	Shwr_firstpartxzang->SetLineColor(kBlue);
	Shwr_firstpartxzang->SetLineWidth(3);
	Shwr_firstpartxzang->SetStats(true);
	Shwr_firstpartxzang->Draw();


	TCanvas* c73 = new TCanvas("c73", "", 700, 700);
	c73->SetLeftMargin(.1);
	c73->SetBottomMargin(.1);
	c73->SetTopMargin(.075);
	c73->SetRightMargin(.15);
	c73->cd();

	Shwr_firstpartyzang->SetLineColor(kBlue);
	Shwr_firstpartyzang->SetLineWidth(3);
	Shwr_firstpartyzang->SetStats(true);
	Shwr_firstpartyzang->Draw();


	TCanvas* c74 = new TCanvas("c74", "", 700, 700);
	c74->SetLeftMargin(.1);
	c74->SetBottomMargin(.1);
	c74->SetTopMargin(.075);
	c74->SetRightMargin(.15);
	c74->cd();

	bestplanededx->SetLineColor(kBlue);
	bestplanededx->SetLineWidth(3);
	bestplanededx->SetStats(true);
	bestplanededx->Draw();

	TCanvas* c75 = new TCanvas("c75", "", 700, 700);
	c75->SetLeftMargin(.1);
	c75->SetBottomMargin(.1);
	c75->SetTopMargin(.075);
	c75->SetRightMargin(.15);
	c75->cd();

	diffshower_dedx->SetLineColor(kBlue);
	diffshower_dedx->SetLineWidth(3);
	diffshower_dedx->SetStats(true);
	diffshower_dedx->Draw();

	TCanvas* c76 = new TCanvas("c76", "", 700, 700);
	c76->SetLeftMargin(.1);
	c76->SetBottomMargin(.1);
	c76->SetTopMargin(.075);
	c76->SetRightMargin(.15);
	c76->cd();

	MCshower_dedx->SetLineColor(kGreen);
	MCshower_dedx->SetLineWidth(3);
	MCshower_dedx->SetStats(true);
	MCshower_dedx->Draw();


	Recoshowerbest_dedx->SetLineColor(kBlue);
	Recoshowerbest_dedx->SetLineWidth(3);
	Recoshowerbest_dedx->SetStats(true);
	Recoshowerbest_dedx->Draw("same");

	TLegend* leg = new TLegend(0.5, 0.82, 0.92, 0.98);
	leg->SetFillColor(kWhite);
	leg->SetTextSize(0.03);
	leg->AddEntry(MCshower_dedx, "dE/dx of MC Shower", "l");
	leg->AddEntry(Recoshowerbest_dedx, "dE/dx of Reco Shower", "l");
	leg->Draw();

	
	TCanvas* c78 = new TCanvas("c78", "", 700, 700);
	c78->SetLeftMargin(.1);
	c78->SetBottomMargin(.1);
	c78->SetTopMargin(.075);
	c78->SetRightMargin(.15);
	c78->cd();

	Negativededxdist->SetLineColor(kBlue);
	Negativededxdist->SetLineWidth(3);
	Negativededxdist->SetStats(true);
	Negativededxdist->Draw();

	TCanvas* c79 = new TCanvas("c79", "", 700, 700);
	c79->SetLeftMargin(.1);
	c79->SetBottomMargin(.1);
	c79->SetTopMargin(.075);
	c79->SetRightMargin(.15);
	c79->cd();

	Negativededxxzang->SetLineColor(kBlue);
	Negativededxxzang->SetLineWidth(3);
	Negativededxxzang->SetStats(true);
	Negativededxxzang->Draw();


	TCanvas* c80 = new TCanvas("c80", "", 700, 700);
	c80->SetLeftMargin(.1);
	c80->SetBottomMargin(.1);
	c80->SetTopMargin(.075);
	c80->SetRightMargin(.15);
	c80->cd();

	Negativededxyzang->SetLineColor(kBlue);
	Negativededxyzang->SetLineWidth(3);
	Negativededxyzang->SetStats(true);
	Negativededxyzang->Draw();


	TCanvas* c82 = new TCanvas("c82", "", 700, 700);
	c82->SetLeftMargin(.1);
	c82->SetBottomMargin(.1);
	c82->SetTopMargin(.075);
	c82->SetRightMargin(.15);
	c82->cd();

	Recoshower1_dedx->SetLineColor(kBlue);
	Recoshower1_dedx->SetLineWidth(3);
	//Recoshower1_dedx->SetStats(true);
	Recoshower1_dedx->Draw();

	Recoshower2_dedx->SetLineColor(kRed);
	Recoshower2_dedx->SetLineWidth(3);
	//Recoshower2_dedx->SetStats(true);
	Recoshower2_dedx->Draw("same");

	Recoshower3_dedx->SetLineColor(kGreen);
	Recoshower3_dedx->SetLineWidth(3);
	//Recoshower3_dedx->SetStats(true);
	Recoshower3_dedx->Draw("same");

	TLegend* leg = new TLegend(0.5, 0.82, 0.92, 0.98);
	leg->SetFillColor(kWhite);
	leg->SetTextSize(0.03);
	leg->AddEntry(Recoshower1_dedx, "dE/dx of Plane 0", "l");
	leg->AddEntry(Recoshower2_dedx, "dE/dx of Plane 1", "l");
	leg->AddEntry(Recoshower3_dedx, "dE/dx of Plane 2", "l");
	leg->Draw();

	TCanvas* c83 = new TCanvas("c83", "", 700, 700);
	c83->SetLeftMargin(.1);
	c83->SetBottomMargin(.1);
	c83->SetTopMargin(.075);
	c83->SetRightMargin(.15);
	c83->cd();

	Negdedx->SetLineColor(kGreen);
	Negdedx->SetFillColor(kGreen);
	Negdedx->SetLineWidth(3);
	Negativededx->Add(Negdedx);

	NotinTPCdedx->SetLineColor(kBlue);
	NotinTPCdedx->SetFillColor(kBlue);
	NotinTPCdedx->SetLineWidth(3);
	Negativededx->Add(NotinTPCdedx);

	PoorRecodedx->SetLineColor(kRed);
	PoorRecodedx->SetFillColor(kRed);
	PoorRecodedx->SetLineWidth(3);
	Negativededx->Add(PoorRecodedx);

	Negativededx->Draw();

	TLegend* leg = new TLegend(0.5, 0.82, 0.92, 0.98);
	leg->SetFillColor(kWhite);
	leg->SetTextSize(0.03);
	leg->AddEntry(Negdedx, "Events with Negative dE/dx", "l");
	leg->AddEntry(NotinTPCdedx, "Events not in TPC", "l");
	leg->AddEntry(PoorRecodedx, "Events with Poor Reconstruction", "l");
	leg->Draw();

	TCanvas* c84 = new TCanvas("c84", "", 700, 700);
	c84->SetLeftMargin(.1);
	c84->SetBottomMargin(.1);
	c84->SetTopMargin(.075);
	c84->SetRightMargin(.15);
	c84->cd();

	RatiolessTotdedx->SetLineColor(kBlue);
	RatiolessTotdedx->SetLineWidth(3);
	RatiolessTotdedx->SetStats(true);
	RatiolessTotdedx->Draw();

	TCanvas* c85 = new TCanvas("c85", "", 700, 700);
	c85->SetLeftMargin(.1);
	c85->SetBottomMargin(.1);
	c85->SetTopMargin(.075);
	c85->SetRightMargin(.15);
	c85->cd();

	Startoffsetdistdedx->SetLineColor(kBlue);
	Startoffsetdistdedx->SetLineWidth(3);
	Startoffsetdistdedx->SetStats(true);
	Startoffsetdistdedx->Draw();

	TCanvas* c86 = new TCanvas("c86", "", 700, 700);
	c86->SetLeftMargin(.1);
	c86->SetBottomMargin(.1);
	c86->SetTopMargin(.075);
	c86->SetRightMargin(.15);
	c86->cd();

	NegativeEnergyFirstPartdedx->SetLineColor(kBlue);
	NegativeEnergyFirstPartdedx->SetLineWidth(3);
	NegativeEnergyFirstPartdedx->SetStats(true);
	NegativeEnergyFirstPartdedx->Draw();


	TCanvas* c87 = new TCanvas("c87", "", 700, 700);
	c87->SetLeftMargin(.1);
	c87->SetBottomMargin(.1);
	c87->SetTopMargin(.075);
	c87->SetRightMargin(.15);
	c87->cd();

	NegativededxShowerEnergy->SetLineColor(kBlue);
	NegativededxShowerEnergy->SetLineWidth(3);
	NegativededxShowerEnergy->SetStats(true);
	NegativededxShowerEnergy->Draw();


	TCanvas* c88 = new TCanvas("c88", "", 700, 700);
	c88->SetLeftMargin(.1);
	c88->SetBottomMargin(.1);
	c88->SetTopMargin(.075);
	c88->SetRightMargin(.15);
	c88->cd();

	NegativededxFirstPart_MCshwreng->SetLineColor(kBlue);
	NegativededxFirstPart_MCshwreng->SetLineWidth(3);
	NegativededxFirstPart_MCshwreng->SetStats(true);
	NegativededxFirstPart_MCshwreng->Draw();

	TCanvas* c89 = new TCanvas("c89", "", 700, 700);
	c89->SetLeftMargin(.1);
	c89->SetBottomMargin(.1);
	c89->SetTopMargin(.075);
	c89->SetRightMargin(.15);
	c89->cd();

	NegativededxMCShowerEnergy->SetLineColor(kBlue);
	NegativededxMCShowerEnergy->SetLineWidth(3);
	NegativededxMCShowerEnergy->SetStats(true);
	NegativededxMCShowerEnergy->Draw();

	TCanvas* c90 = new TCanvas("c90", "", 700, 700);
	c90->SetLeftMargin(.1);
	c90->SetBottomMargin(.1);
	c90->SetTopMargin(.075);
	c90->SetRightMargin(.15);
	c90->cd();

	Negativededxfirstpart_Recoshowerenergy->SetLineColor(kBlue);
	Negativededxfirstpart_Recoshowerenergy->SetLineWidth(3);
	Negativededxfirstpart_Recoshowerenergy->SetStats(true);
	Negativededxfirstpart_Recoshowerenergy->Draw();


	TCanvas* c91 = new TCanvas("c91", "", 700, 700);
	c91->SetLeftMargin(.1);
	c91->SetBottomMargin(.1);
	c91->SetTopMargin(.075);
	c91->SetRightMargin(.15);
	c91->cd();

	NegativededxMCshwr_Recoshowerenergy->SetLineColor(kBlue);
	NegativededxMCshwr_Recoshowerenergy->SetLineWidth(3);
	NegativededxMCshwr_Recoshowerenergy->SetStats(true);
	NegativededxMCshwr_Recoshowerenergy->Draw();


	TCanvas* c92 = new TCanvas("c92", "", 700, 700);
	c92->SetLeftMargin(.1);
	c92->SetBottomMargin(.1);
	c92->SetTopMargin(.075);
	c92->SetRightMargin(.15);
	c92->cd();

	Positionxy->SetLineColor(kBlue);
	Positionxy->SetLineWidth(3);
	Positionxy->SetStats(true);
	Positionxy->Draw("colz");

	TCanvas* c93 = new TCanvas("c93", "", 700, 700);
	c93->SetLeftMargin(.1);
	c93->SetBottomMargin(.1);
	c93->SetTopMargin(.075);
	c93->SetRightMargin(.15);
	c93->cd();

	Positionyz->SetLineColor(kBlue);
	Positionyz->SetLineWidth(3);
	Positionyz->SetStats(true);
	Positionyz->Draw("colz");

	TCanvas* c94 = new TCanvas("c94", "", 700, 700);
	c94->SetLeftMargin(.1);
	c94->SetBottomMargin(.1);
	c94->SetTopMargin(.075);
	c94->SetRightMargin(.15);
	c94->cd();

	GoodAngledist->SetLineColor(kBlue);
	GoodAngledist->SetLineWidth(3);
	GoodAngledist->SetStats(true);
	GoodAngledist->Draw();

	TCanvas* c95 = new TCanvas("c95", "", 700, 700);
	c95->SetLeftMargin(.1);
	c95->SetBottomMargin(.1);
	c95->SetTopMargin(.075);
	c95->SetRightMargin(.15);
	c95->cd();

	Diffzdist->SetLineColor(kBlue);
	Diffzdist->SetLineWidth(3);
	Diffzdist->SetStats(true);
	Diffzdist->Draw();

	Diffzdistmaggreaterthan60->SetLineColor(kRed);
	Diffzdistmaggreaterthan60->SetLineWidth(3);
	Diffzdistmaggreaterthan60->SetStats(true);
	Diffzdistmaggreaterthan60->Draw("same");

	Diffzdistmaglessthan60->SetLineColor(kGreen);
	Diffzdistmaglessthan60->SetLineWidth(3);
	Diffzdistmaglessthan60->SetStats(true);
	Diffzdistmaglessthan60->Draw("same");

	Diffzdistgreaterthan60->SetLineColor(kViolet);
	Diffzdistgreaterthan60->SetLineWidth(3);
	Diffzdistgreaterthan60->SetStats(true);
	Diffzdistgreaterthan60->Draw("same");

	Diffzdistlessthanminus60->SetLineColor(kBlack);
	Diffzdistlessthanminus60->SetLineWidth(3);
	Diffzdistlessthanminus60->SetStats(true);
	Diffzdistlessthanminus60->Draw("same");

	
	TLegend* leg = new TLegend(0.5, 0.82, 0.92, 0.98);
	leg->SetFillColor(kWhite);
	leg->SetTextSize(0.02);
	leg->AddEntry(Diffzdist, "Shower Start - MC Start (z direction) All Angles", "l");
	leg->AddEntry(Diffzdistmaggreaterthan60, "Shower Start - MC Start (z direction) Mag Greater than or Equal to 60", "l");
	leg->AddEntry(Diffzdistmaglessthan60, "Shower Start - MC Start (z direction) Mag Less than 60", "l");
	leg->AddEntry(Diffzdistgreaterthan60, "Shower Start - MC Start (z direction) Greater than or Equal to 60", "l");
	leg->AddEntry(Diffzdistlessthanminus60, "Shower Start - MC Start (z direction) Less than -60", "l");
	leg->Draw();


	TCanvas* c96 = new TCanvas("c96", "", 700, 700);
	c96->SetLeftMargin(.1);
	c96->SetBottomMargin(.1);
	c96->SetTopMargin(.075);
	c96->SetRightMargin(.15);
	c96->cd();

	Diffxdist->SetLineColor(kBlue);
	Diffxdist->SetLineWidth(3);
	Diffxdist->SetStats(true);
	Diffxdist->Draw();

	Diffxdistmaggreaterthan60->SetLineColor(kRed);
	Diffxdistmaggreaterthan60->SetLineWidth(3);
	Diffxdistmaggreaterthan60->SetStats(true);
	Diffxdistmaggreaterthan60->Draw("same");

	Diffxdistmaglessthan60->SetLineColor(kGreen);
	Diffxdistmaglessthan60->SetLineWidth(3);
	Diffxdistmaglessthan60->SetStats(true);
	Diffxdistmaglessthan60->Draw("same");

	Diffxdistgreaterthan60->SetLineColor(kViolet);
	Diffxdistgreaterthan60->SetLineWidth(3);
	Diffxdistgreaterthan60->SetStats(true);
	Diffxdistgreaterthan60->Draw("same");

	Diffxdistlessthanminus60->SetLineColor(kBlack);
	Diffxdistlessthanminus60->SetLineWidth(3);
	Diffxdistlessthanminus60->SetStats(true);
	Diffxdistlessthanminus60->Draw("same");




	TLegend* leg = new TLegend(0.5, 0.82, 0.92, 0.98);
	leg->SetFillColor(kWhite);
	leg->SetTextSize(0.02);
	leg->AddEntry(Diffxdist, "Shower Start - MC Start (x direction) All Angles", "l");
	leg->AddEntry(Diffxdistmaggreaterthan60, "Shower Start - MC Start (x direction) Mag Greater than or Equal to 60", "l");
	leg->AddEntry(Diffxdistmaglessthan60, "Shower Start - MC Start (x direction) Mag Less than 60", "l");
	leg->AddEntry(Diffxdistgreaterthan60, "Shower Start - MC Start (x direction) Greater than or Equal to 60", "l");
	leg->AddEntry(Diffxdistlessthanminus60, "Shower Start - MC Start (x direction) Less than -60", "l");
	leg->Draw();


	TCanvas* c97 = new TCanvas("c97", "", 700, 700);
	c97->SetLeftMargin(.1);
	c97->SetBottomMargin(.1);
	c97->SetTopMargin(.075);
	c97->SetRightMargin(.15);
	c97->cd();

	Diffydistgreaterthan60->SetLineColor(kViolet);
	Diffydistgreaterthan60->SetLineWidth(3);
	Diffydistgreaterthan60->SetStats(true);
	Diffydistgreaterthan60->SetFillColor(kViolet);
	ycomponent->Add(Diffydistgreaterthan60);

	Diffydistlessthanminus60->SetLineColor(kBlack);
	Diffydistlessthanminus60->SetLineWidth(3);
	Diffydistlessthanminus60->SetStats(true);
	Diffydistlessthanminus60->SetFillColor(kBlack);
	ycomponent->Add(Diffydistlessthanminus60);

	Diffydistmaggreaterthan60->SetLineColor(kRed);
	Diffydistmaggreaterthan60->SetLineWidth(3);
	Diffydistmaggreaterthan60->SetStats(true);
	Diffydistmaggreaterthan60->SetFillColor(kRed);
	ycomponent->Add(Diffydistmaggreaterthan60);

	Diffydistmaglessthan60->SetLineColor(kGreen);
	Diffydistmaglessthan60->SetLineWidth(3);
	Diffydistmaglessthan60->SetStats(true);
	Diffydistmaglessthan60->SetFillColor(kGreen);
	ycomponent->Add(Diffydistmaglessthan60);

	Diffydist->SetLineColor(kBlue);
	Diffydist->SetLineWidth(3);
	Diffydist->SetStats(true);
	Diffydist->SetFillColor(kBlue);
	ycomponent->Add(Diffydist);

	ycomponent->Draw();
	
	TLegend* leg = new TLegend(0.5, 0.82, 0.92, 0.98);
	leg->SetFillColor(kWhite);
	leg->SetTextSize(0.02);
	leg->AddEntry(Diffydist, "Shower Start - MC Start (y direction) All Angles", "l");
	leg->AddEntry(Diffydistmaggreaterthan60, "Shower Start - MC Start (y direction) Mag Greater than or Equal to 60", "l");
	leg->AddEntry(Diffydistmaglessthan60, "Shower Start - MC Start (y direction) Mag Less than 60", "l");
	leg->AddEntry(Diffydistgreaterthan60, "Shower Start - MC Start (y direction) Greater than or Equal to 60", "l");
	leg->AddEntry(Diffydistlessthanminus60, "Shower Start - MC Start (y direction) Less than -60", "l");
	leg->Draw();


	TCanvas* c98 = new TCanvas("c98", "", 700, 700);
	c98->SetLeftMargin(.1);
	c98->SetBottomMargin(.1);
	c98->SetTopMargin(.075);
	c98->SetRightMargin(.15);
	c98->cd();

	GoodAngledist->SetLineColor(kRed);
	GoodAngledist->SetLineWidth(3);
	GoodAngledist->SetStats(true);
	GoodAngledist->Draw();

	Anglegreaterthan60dist->SetLineColor(kBlue);
	Anglegreaterthan60dist->SetLineWidth(3);
	Anglegreaterthan60dist->SetStats(true);
	Anglegreaterthan60dist->Draw("same");

	Anglelessthanminus60dist->SetLineColor(kGreen);
	Anglelessthanminus60dist->SetLineWidth(3);
	Anglelessthanminus60dist->SetStats(true);
	Anglelessthanminus60dist->Draw("same");

	TLegend* leg = new TLegend(0.5, 0.82, 0.92, 0.98);
	leg->SetFillColor(kWhite);
	leg->SetTextSize(0.02);
	leg->AddEntry(GoodAngledist, "Events with MC yz Angle magnitude greater than or equal to 60", "l");
	leg->AddEntry(Anglegreaterthan60dist, "Events with MC yz Angle greater than or equal to 60 degrees", "l");
	leg->AddEntry(Anglelessthanminus60dist, "Events with MC yz Angle less than or equal to -60 degrees", "l");
	leg->Draw();

	TCanvas* c99 = new TCanvas("c99", "", 700, 700);
	c99->SetLeftMargin(.1);
	c99->SetBottomMargin(.1);
	c99->SetTopMargin(.075);
	c99->SetRightMargin(.15);
	c99->cd();

	StartPointOffset->SetLineColor(kViolet);
	StartPointOffset->SetLineWidth(3);
	StartPointOffset->SetStats(true);
	StartPointOffset->SetFillColor(false);
	StartPointOffset->Draw();

	//Startpointoffsetlessthan60dist->SetLineColor(kBlack);
	//Startpointoffsetlessthan60dist->SetLineWidth(3);
	//Startpointoffsetlessthan60dist->SetStats(true);
	//Startpointoffsetlessthan60dist->SetFillColor(false);
	//Startpointoffsetlessthan60dist->Draw("same");

	//Startpointoffsetgreaterthan60dist->SetLineColor(kGreen);
	//Startpointoffsetgreaterthan60dist->SetLineWidth(3);
	//Startpointoffsetgreaterthan60dist->SetStats(true);
	//Startpointoffsetgreaterthan60dist->SetFillColor(false);
	//Startpointoffsetgreaterthan60dist->Draw("same");

	EndStartpointoffsetyzangledist->SetLineColor(kBlue);
	EndStartpointoffsetyzangledist->SetLineWidth(3);
	EndStartpointoffsetyzangledist->SetStats(true);
	EndStartpointoffsetyzangledist->SetFillColor(false);
	EndStartpointoffsetyzangledist->Draw("same");

	NotEndStartpointoffsetyzangledist->SetLineColor(kGreen);
	NotEndStartpointoffsetyzangledist->SetLineWidth(3);
	NotEndStartpointoffsetyzangledist->SetStats(true);
	NotEndStartpointoffsetyzangledist->SetFillColor(false);
	NotEndStartpointoffsetyzangledist->Draw("same");

	TLegend* leg = new TLegend(0.5, 0.82, 0.92, 0.98);
	leg->SetFillColor(kWhite);
	leg->SetTextSize(0.02);
	leg->AddEntry(StartPointOffset, "Start Point Offset (all events)", "l");
	//leg->AddEntry(Startpointoffsetlessthan60dist, "Start Point Offset (events with MC yz angle less than 60 degrees)", "l");
	//leg->AddEntry(Startpointoffsetgreaterthan60dist, "Start Point Offset (events with MC yz angle greater than or equal to 60 degrees)", "l");
	leg->AddEntry(NotEndStartpointoffsetyzangledist, "Start Point Offset (events with MC yz angle not between 90.0 - 180.0)", "l");
	leg->AddEntry(EndStartpointoffsetyzangledist, "Start Point Offset (events with MC yz angle between 90.0 - 180.0)", "l");
	leg->Draw();

	TCanvas* c100 = new TCanvas("c100", "", 700, 700);
	c100->SetLeftMargin(.1);
	c100->SetBottomMargin(.1);
	c100->SetTopMargin(.075);
	c100->SetRightMargin(.15);
	c100->cd();

	/*Uplanedist->SetLineColor(kRed);
	Uplanedist->SetLineWidth(3);
	Uplanedist->SetStats(false);
	Uplanedist->Draw();

	Unotplanedist->SetLineColor(kGreen);
	Unotplanedist->SetLineWidth(3);
	Unotplanedist->SetStats(false);
	Unotplanedist->Draw("same");
	
	Vplanedist->SetLineColor(kBlue);
	Vplanedist->SetLineWidth(3);
	Vplanedist->SetStats(false);
	Vplanedist->Draw();

	Vnotplanedist->SetLineColor(kRed);
	Vnotplanedist->SetLineWidth(3);
	Vnotplanedist->SetStats(false);
	Vnotplanedist->Draw("same");
	
	
	Yplanedist->SetLineColor(kGreen);
	Yplanedist->SetLineWidth(3);
	Yplanedist->SetStats(false);
	Yplanedist->Draw();

	Ynotplanedist->SetLineColor(kBlue);
	Ynotplanedist->SetLineWidth(3);
	Ynotplanedist->SetStats(false);
	Ynotplanedist->Draw("same");
	*/

	ParallelAngledist->SetLineColor(kGreen);
	ParallelAngledist->SetLineWidth(3);
	ParallelAngledist->SetStats(false);
	ParallelAngledist->Draw();

	NotParallelAngledist->SetLineColor(kBlue);
	NotParallelAngledist->SetLineWidth(3);
	NotParallelAngledist->SetStats(false);
	NotParallelAngledist->Draw("same");

	TLegend* leg = new TLegend(0.5, 0.82, 0.92, 0.98);
	leg->SetFillColor(kWhite);
	leg->SetTextSize(0.02);
	leg->AddEntry(ParallelAngledist, "Parallel to U, V or Y Wire Planes", "l");
	leg->AddEntry(NotParallelAngledist, "Not Parallel to U, V, or Y Wire Planes", "l");
	//leg->AddEntry(Vplanedist, "Vplanedist", "l");
	//leg->AddEntry(Yplanedist, "Yplanedist", "l");
	leg->Draw();

	TCanvas* c101 = new TCanvas("c101", "", 700, 700);
	c101->SetLeftMargin(.1);
	c101->SetBottomMargin(.1);
	c101->SetTopMargin(.075);
	c101->SetRightMargin(.15);
	c101->cd();

	StartPointOffset->SetLineColor(kCyan+3);
	StartPointOffset->SetLineWidth(3);
	StartPointOffset->SetStats(true);
	StartPointOffset->Draw();

	//Startpointoffsetgreaterthan50dist->SetLineColor(kGreen);
	//Startpointoffsetgreaterthan50dist->SetLineWidth(3);
	//Startpointoffsetgreaterthan50dist->SetStats(true);
	//Startpointoffsetgreaterthan50dist->Draw("same");

	//Startpointoffsetgreaterthan60dist->SetLineColor(kBlue);
	//Startpointoffsetgreaterthan60dist->SetLineWidth(3);
	//Startpointoffsetgreaterthan60dist->SetStats(true);
	//Startpointoffsetgreaterthan60dist->Draw("same");

	//Startpointoffsetgreaterthan70dist->SetLineColor(kBlack);
	//Startpointoffsetgreaterthan70dist->SetLineWidth(3);
	//Startpointoffsetgreaterthan70dist->SetStats(true);
	//Startpointoffsetgreaterthan70dist->Draw("same");

	//Startpointoffsetgreaterthan80dist->SetLineColor(kRed);
	//Startpointoffsetgreaterthan80dist->SetLineWidth(3);
	//Startpointoffsetgreaterthan80dist->SetStats(true);
	//Startpointoffsetgreaterthan80dist->Draw("same");

	Startpointoffsetgreaterthan90dist->SetLineColor(kViolet);
	Startpointoffsetgreaterthan90dist->SetLineWidth(3);
	Startpointoffsetgreaterthan90dist->SetStats(true);
	Startpointoffsetgreaterthan90dist->Draw("same");

	//Startpointoffsetgreaterthan100dist->SetLineColor(kRed+4);
	//Startpointoffsetgreaterthan100dist->SetLineWidth(3);
	//Startpointoffsetgreaterthan100dist->SetStats(true);
	//Startpointoffsetgreaterthan100dist->Draw("same");

	TLegend* leg = new TLegend(0.5, 0.82, 0.92, 0.98);
	leg->SetFillColor(kWhite);
	leg->SetTextSize(0.02);
	leg->AddEntry(StartPointOffset, "Start Point Offset (events with any MC xz or yz angle)", "l");
	//leg->AddEntry(Startpointoffsetgreaterthan50dist, "Start Point Offset (events with MC yz angle greater than or equal to 50 degrees)", "l");
	//leg->AddEntry(Startpointoffsetgreaterthan60dist, "Start Point Offset (events with MC yz angle greater than or equal to 60 degrees)", "l");
	//leg->AddEntry(Startpointoffsetgreaterthan70dist, "Start Point Offset (events with MC yz angle greater than or equal to 70 degrees)", "l");
	//leg->AddEntry(Startpointoffsetgreaterthan80dist, "Start Point Offset (events with MC yz angle greater than or equal to 80 degrees)", "l");
	leg->AddEntry(Startpointoffsetgreaterthan90dist, "Start Point Offset (events with MC xz or yz angle >= 90 degrees)", "l");
	//leg->AddEntry(Startpointoffsetgreaterthan100dist, "Start Point Offset (events with MC yz angle greater than or equal to 100 degrees)", "l");
	leg->Draw();

	TCanvas* c102 = new TCanvas("c102", "", 700, 700);
	c102->SetLeftMargin(.1);
	c102->SetBottomMargin(.1);
	c102->SetTopMargin(.075);
	c102->SetRightMargin(.15);
	c102->cd();

	Diffzdist->SetLineColor(kBlue);
	Diffzdist->SetLineWidth(3);
	Diffzdist->SetStats(true);
	Diffzdist->Draw();

	Posmomentumzdist->SetLineColor(kGreen);
	Posmomentumzdist->SetLineWidth(3);
	Posmomentumzdist->SetStats(true);
	Posmomentumzdist->Draw("same");

	Negmomentumzdist->SetLineColor(kRed);
	Negmomentumzdist->SetLineWidth(3);
	Negmomentumzdist->SetStats(true);
	Negmomentumzdist->Draw("same");


	TLegend* leg = new TLegend(0.5, 0.82, 0.92, 0.98);
	leg->SetFillColor(kWhite);
	leg->SetTextSize(0.02);
	leg->AddEntry(Diffzdist, "Shower Start - MC Start (z direction)", "l");
	leg->AddEntry(Posmomentumzdist, "Shower Start - MC Start (positive z direction)", "l");
	leg->AddEntry(Negmomentumzdist, "Shower Start - MC Start (negative z direction)", "l");
	leg->Draw();


	TCanvas* c103 = new TCanvas("c103", "", 700, 700);
	c103->SetLeftMargin(.1);
	c103->SetBottomMargin(.1);
	c103->SetTopMargin(.075);
	c103->SetRightMargin(.15);
	c103->cd();

	Diffydist->SetLineColor(kBlue);
	Diffydist->SetLineWidth(3);
	Diffydist->SetStats(true);
	Diffydist->SetFillColor(false);
	Diffydist->Draw();

	Posmomentumydist->SetLineColor(kGreen);
	Posmomentumydist->SetLineWidth(3);
	Posmomentumydist->SetStats(true);
	Posmomentumydist->SetFillColor(false);
	Posmomentumydist->Draw("same");

	Negmomentumydist->SetLineColor(kRed);
	Negmomentumydist->SetLineWidth(3);
	Negmomentumydist->SetStats(true);
	Negmomentumydist->SetFillColor(false);
	Negmomentumydist->Draw("same");


	TLegend* leg = new TLegend(0.5, 0.82, 0.92, 0.98);
	leg->SetFillColor(kWhite);
	leg->SetTextSize(0.02);
	leg->AddEntry(Diffydist, "Shower Start - MC Start (y direction)", "l");
	leg->AddEntry(Posmomentumydist, "Shower Start - MC Start (positive y direction)", "l");
	leg->AddEntry(Negmomentumydist, "Shower Start - MC Start (negative y direction)", "l");
	leg->Draw();


	TCanvas* c104 = new TCanvas("c104", "", 700, 700);
	c104->SetLeftMargin(.1);
	c104->SetBottomMargin(.1);
	c104->SetTopMargin(.075);
	c104->SetRightMargin(.15);
	c104->cd();

	Diffxdist->SetLineColor(kBlue);
	Diffxdist->SetLineWidth(3);
	Diffxdist->SetStats(true);
	Diffxdist->Draw();

	Posmomentumxdist->SetLineColor(kGreen);
	Posmomentumxdist->SetLineWidth(3);
	Posmomentumxdist->SetStats(true);
	Posmomentumxdist->Draw("same");

	Negmomentumxdist->SetLineColor(kRed);
	Negmomentumxdist->SetLineWidth(3);
	Negmomentumxdist->SetStats(true);
	Negmomentumxdist->Draw("same");


	TLegend* leg = new TLegend(0.5, 0.82, 0.92, 0.98);
	leg->SetFillColor(kWhite);
	leg->SetTextSize(0.02);
	leg->AddEntry(Diffzdist, "Shower Start - MC Start (x direction)", "l");
	leg->AddEntry(Posmomentumzdist, "Shower Start - MC Start (positive x direction)", "l");
	leg->AddEntry(Negmomentumzdist, "Shower Start - MC Start (negative x direction)", "l");
	leg->Draw();

	TCanvas* c105 = new TCanvas("c105", "", 700, 700);
	c105->SetLeftMargin(.1);
	c105->SetBottomMargin(.1);
	c105->SetTopMargin(.075);
	c105->SetRightMargin(.15);
	c105->cd();

	Startpointoffsetxzangledistlessthan->SetLineColor(kRed);
	Startpointoffsetxzangledistlessthan->SetLineWidth(3);
	Startpointoffsetxzangledistlessthan->SetStats(true);
	Startpointoffsetxzangledistlessthan->Draw();

	EndStartpointoffsetxzangledist->SetLineColor(kGreen);
	EndStartpointoffsetxzangledist->SetLineWidth(3);
	EndStartpointoffsetxzangledist->SetStats(true);
	EndStartpointoffsetxzangledist->Draw("same");

	NotEndStartpointoffsetxzangledist->SetLineColor(kBlue);
	NotEndStartpointoffsetxzangledist->SetLineWidth(3);
	NotEndStartpointoffsetxzangledist->SetStats(true);
	NotEndStartpointoffsetxzangledist->Draw("same");

	TLegend* leg = new TLegend(0.5, 0.82, 0.92, 0.98);
	leg->SetFillColor(kWhite);
	leg->SetTextSize(0.02);
	leg->AddEntry(Startpointoffsetxzangledistlessthan, "MC xz angle greater than or equal to 60 degrees", "l");
	leg->AddEntry(EndStartpointoffsetxzangledist, "MC xz angle between 90 - 180 degrees", "l");
	leg->AddEntry(NotEndStartpointoffsetxzangledist, "MC xz angle not between 90 - 180 degrees", "l");
	leg->Draw();

	TCanvas* c106 = new TCanvas("c106", "", 700, 700);
	c106->SetLeftMargin(.1);
	c106->SetBottomMargin(.1);
	c106->SetTopMargin(.075);
	c106->SetRightMargin(.15);
	c106->cd();

	DistvsAngleyz->SetLineColor(kBlue);
	DistvsAngleyz->SetLineWidth(3);
	DistvsAngleyz->SetStats(true);
	DistvsAngleyz->Draw("colz");

	TCanvas* c107 = new TCanvas("c107", "", 700, 700);
	c107->SetLeftMargin(.1);
	c107->SetBottomMargin(.1);
	c107->SetTopMargin(.075);
	c107->SetRightMargin(.15);
	c107->cd();

	DistvsAnglexy->SetLineColor(kBlue);
	DistvsAnglexy->SetLineWidth(3);
	DistvsAnglexy->SetStats(true);
	DistvsAnglexy->Draw("colz");


}


// this makes sure the angle is within 0 - 180 degrees
double Find_Angle(double angle)
{
	if (angle >= 180)
	{
		angle = 360 - angle;
	}

	return (angle);
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

//ActualEng->Fill(actualenergy);

// particles that cross the boundary
// what is their distance

//if (!(EndPointx_tpcAV[i] == -99999))
//{
//toteng = toteng + Eng[i] - EndE[i];
//std::cout << toteng << std::endl << std::endl;
//}
//}
//}

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

//MCshower_dEdx->Fill(mcshwr_dEdx[0]);

// Histogram (TH1F)  -> Fill(var) [function, var] 

/*
Showerstartx->Fill(shwr_startx[0]);
Showerstarty->Fill(shwr_starty[0]);
Showerstartz->Fill(shwr_startz[0]);

MCstartx->Fill(mcshwr_startX[0]);
MCstarty->Fill(mcshwr_startY[0]);
MCstartz->Fill(mcshwr_startZ[0]);
*/
//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Jun 29 11:27:00 2015 by ROOT version 5.34/22
// from TTree anatree/analysis tree
// found on file: prod_bnblike_gamma_standard_reco_hist.root
//////////////////////////////////////////////////////////

#ifndef anatree_h
#define anatree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.

class anatree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           run;
   Int_t           subrun;
   Int_t           event;
   Double_t        evttime;
   Double_t        beamtime;
   Double_t        pot;
   Char_t          isdata;
   Double_t        taulife;
   Int_t           no_hits;
   Short_t         hit_plane[2053];   //[no_hits]
   Short_t         hit_wire[2053];   //[no_hits]
   Short_t         hit_channel[2053];   //[no_hits]
   Float_t         hit_peakT[2053];   //[no_hits]
   Float_t         hit_charge[2053];   //[no_hits]
   Float_t         hit_ph[2053];   //[no_hits]
   Float_t         hit_startT[2053];   //[no_hits]
   Float_t         hit_endT[2053];   //[no_hits]
   Float_t         hit_trueX[2053];   //[no_hits]
   Float_t         hit_goodnessOfFit[2053];   //[no_hits]
   Short_t         hit_multiplicity[2053];   //[no_hits]
   Short_t         hit_trkid[2053];   //[no_hits]
   Float_t         hit_nelec[2053];   //[no_hits]
   Float_t         hit_energy[2053];   //[no_hits]
   Short_t         nvtx;
   Float_t         vtx[1][3];   //[nvtx]
   Int_t           no_flashes;
   Float_t         flash_time[65];   //[no_flashes]
   Float_t         flash_pe[65];   //[no_flashes]
   Float_t         flash_ycenter[65];   //[no_flashes]
   Float_t         flash_zcenter[65];   //[no_flashes]
   Short_t         nshowers;
   Int_t           showerID[4];   //[nshowers]
   Int_t           shwr_bestplane[4];   //[nshowers]
   Float_t         shwr_length[4];   //[nshowers]
   Float_t         shwr_startdcosx[4];   //[nshowers]
   Float_t         shwr_startdcosy[4];   //[nshowers]
   Float_t         shwr_startdcosz[4];   //[nshowers]
   Float_t         shwr_startx[4];   //[nshowers]
   Float_t         shwr_starty[4];   //[nshowers]
   Float_t         shwr_startz[4];   //[nshowers]
   Float_t         shwr_totEng[4][3];   //[nshowers]
   Float_t         shwr_dedx[4][3];   //[nshowers]
   Float_t         shwr_mipEng[4][3];   //[nshowers]
   Char_t          kNTracker;
   Int_t           mcevts_truth;
   Int_t           nuPDG_truth[1];   //[mcevts_truth]
   Int_t           ccnc_truth[1];   //[mcevts_truth]
   Int_t           mode_truth[1];   //[mcevts_truth]
   Float_t         enu_truth[1];   //[mcevts_truth]
   Float_t         Q2_truth[1];   //[mcevts_truth]
   Float_t         W_truth[1];   //[mcevts_truth]
   Float_t         X_truth[1];   //[mcevts_truth]
   Float_t         Y_truth[1];   //[mcevts_truth]
   Int_t           hitnuc_truth[1];   //[mcevts_truth]
   Float_t         nuvtxx_truth[1];   //[mcevts_truth]
   Float_t         nuvtxy_truth[1];   //[mcevts_truth]
   Float_t         nuvtxz_truth[1];   //[mcevts_truth]
   Float_t         nu_dcosx_truth[1];   //[mcevts_truth]
   Float_t         nu_dcosy_truth[1];   //[mcevts_truth]
   Float_t         nu_dcosz_truth[1];   //[mcevts_truth]
   Float_t         lep_mom_truth[1];   //[mcevts_truth]
   Float_t         lep_dcosx_truth[1];   //[mcevts_truth]
   Float_t         lep_dcosy_truth[1];   //[mcevts_truth]
   Float_t         lep_dcosz_truth[1];   //[mcevts_truth]
   Float_t         tpx_flux[1];   //[mcevts_truth]
   Float_t         tpy_flux[1];   //[mcevts_truth]
   Float_t         tpz_flux[1];   //[mcevts_truth]
   Int_t           tptype_flux[1];   //[mcevts_truth]
   Int_t           genie_no_primaries;
   Int_t           genie_primaries_pdg[1];   //[genie_no_primaries]
   Float_t         genie_Eng[1];   //[genie_no_primaries]
   Float_t         genie_Px[1];   //[genie_no_primaries]
   Float_t         genie_Py[1];   //[genie_no_primaries]
   Float_t         genie_Pz[1];   //[genie_no_primaries]
   Float_t         genie_P[1];   //[genie_no_primaries]
   Int_t           genie_status_code[1];   //[genie_no_primaries]
   Float_t         genie_mass[1];   //[genie_no_primaries]
   Int_t           genie_trackID[1];   //[genie_no_primaries]
   Int_t           genie_ND[1];   //[genie_no_primaries]
   Int_t           genie_mother[1];   //[genie_no_primaries]
   Int_t           no_primaries;
   Int_t           geant_list_size;
   Int_t           geant_list_size_in_tpcAV;
   Int_t           pdg[145];   //[geant_list_size]
   Int_t           status[145];   //[geant_list_size]
   Float_t         Mass[145];   //[geant_list_size]
   Float_t         Eng[145];   //[geant_list_size]
   Float_t         EndE[145];   //[geant_list_size]
   Float_t         Px[145];   //[geant_list_size]
   Float_t         Py[145];   //[geant_list_size]
   Float_t         Pz[145];   //[geant_list_size]
   Float_t         P[145];   //[geant_list_size]
   Float_t         StartPointx[145];   //[geant_list_size]
   Float_t         StartPointy[145];   //[geant_list_size]
   Float_t         StartPointz[145];   //[geant_list_size]
   Float_t         StartT[145];   //[geant_list_size]
   Float_t         EndPointx[145];   //[geant_list_size]
   Float_t         EndPointy[145];   //[geant_list_size]
   Float_t         EndPointz[145];   //[geant_list_size]
   Float_t         EndT[145];   //[geant_list_size]
   Float_t         theta[145];   //[geant_list_size]
   Float_t         phi[145];   //[geant_list_size]
   Float_t         theta_xz[145];   //[geant_list_size]
   Float_t         theta_yz[145];   //[geant_list_size]
   Float_t         pathlen[145];   //[geant_list_size]
   Int_t           inTPCActive[145];   //[geant_list_size]
   Float_t         StartPointx_tpcAV[145];   //[geant_list_size]
   Float_t         StartPointy_tpcAV[145];   //[geant_list_size]
   Float_t         StartPointz_tpcAV[145];   //[geant_list_size]
   Float_t         EndPointx_tpcAV[145];   //[geant_list_size]
   Float_t         EndPointy_tpcAV[145];   //[geant_list_size]
   Float_t         EndPointz_tpcAV[145];   //[geant_list_size]
   Int_t           NumberDaughters[145];   //[geant_list_size]
   Int_t           Mother[145];   //[geant_list_size]
   Int_t           TrackId[145];   //[geant_list_size]
   Int_t           MergedId[145];   //[geant_list_size]
   Int_t           origin[145];   //[geant_list_size]
   Int_t           MCTruthIndex[145];   //[geant_list_size]
   Int_t           process_primary[145];   //[geant_list_size]
   vector<string>  *processname;
   Short_t         ntracks_trackkalmanhit;
   Short_t         trkId_trackkalmanhit[14];   //[ntracks_trackkalmanhit]
   Short_t         trkncosmictags_tagger_trackkalmanhit[14];   //[ntracks_trackkalmanhit]
   Float_t         trkcosmicscore_tagger_trackkalmanhit[14];   //[ntracks_trackkalmanhit]
   Short_t         trkcosmictype_tagger_trackkalmanhit[14];   //[ntracks_trackkalmanhit]
   Short_t         trkncosmictags_flashmatch_trackkalmanhit[14];   //[ntracks_trackkalmanhit]
   Float_t         trkcosmicscore_flashmatch_trackkalmanhit[14];   //[ntracks_trackkalmanhit]
   Short_t         trkcosmictype_flashmatch_trackkalmanhit[14];   //[ntracks_trackkalmanhit]
   Float_t         trkke_trackkalmanhit[14][3];   //[ntracks_trackkalmanhit]
   Float_t         trkrange_trackkalmanhit[14][3];   //[ntracks_trackkalmanhit]
   Int_t           trkidtruth_trackkalmanhit[14][3];   //[ntracks_trackkalmanhit]
   Short_t         trkorigin_trackkalmanhit[14][3];   //[ntracks_trackkalmanhit]
   Int_t           trkpdgtruth_trackkalmanhit[14][3];   //[ntracks_trackkalmanhit]
   Float_t         trkefftruth_trackkalmanhit[14][3];   //[ntracks_trackkalmanhit]
   Float_t         trkpurtruth_trackkalmanhit[14][3];   //[ntracks_trackkalmanhit]
   Float_t         trkpitchc_trackkalmanhit[14][3];   //[ntracks_trackkalmanhit]
   Short_t         ntrkhits_trackkalmanhit[14][3];   //[ntracks_trackkalmanhit]
   Float_t         trkdedx_trackkalmanhit[14][3][2000];   //[ntracks_trackkalmanhit]
   Float_t         trkdqdx_trackkalmanhit[14][3][2000];   //[ntracks_trackkalmanhit]
   Float_t         trkresrg_trackkalmanhit[14][3][2000];   //[ntracks_trackkalmanhit]
   Float_t         trkxyz_trackkalmanhit[14][3][2000][3];   //[ntracks_trackkalmanhit]
   Float_t         trkstartx_trackkalmanhit[14];   //[ntracks_trackkalmanhit]
   Float_t         trkstarty_trackkalmanhit[14];   //[ntracks_trackkalmanhit]
   Float_t         trkstartz_trackkalmanhit[14];   //[ntracks_trackkalmanhit]
   Float_t         trkstartd_trackkalmanhit[14];   //[ntracks_trackkalmanhit]
   Float_t         trkendx_trackkalmanhit[14];   //[ntracks_trackkalmanhit]
   Float_t         trkendy_trackkalmanhit[14];   //[ntracks_trackkalmanhit]
   Float_t         trkendz_trackkalmanhit[14];   //[ntracks_trackkalmanhit]
   Float_t         trkendd_trackkalmanhit[14];   //[ntracks_trackkalmanhit]
   Float_t         trktheta_trackkalmanhit[14];   //[ntracks_trackkalmanhit]
   Float_t         trkphi_trackkalmanhit[14];   //[ntracks_trackkalmanhit]
   Float_t         trkstartdcosx_trackkalmanhit[14];   //[ntracks_trackkalmanhit]
   Float_t         trkstartdcosy_trackkalmanhit[14];   //[ntracks_trackkalmanhit]
   Float_t         trkstartdcosz_trackkalmanhit[14];   //[ntracks_trackkalmanhit]
   Float_t         trkenddcosx_trackkalmanhit[14];   //[ntracks_trackkalmanhit]
   Float_t         trkenddcosy_trackkalmanhit[14];   //[ntracks_trackkalmanhit]
   Float_t         trkenddcosz_trackkalmanhit[14];   //[ntracks_trackkalmanhit]
   Float_t         trkthetaxz_trackkalmanhit[14];   //[ntracks_trackkalmanhit]
   Float_t         trkthetayz_trackkalmanhit[14];   //[ntracks_trackkalmanhit]
   Float_t         trkmom_trackkalmanhit[14];   //[ntracks_trackkalmanhit]
   Float_t         trkmomrange_trackkalmanhit[14];   //[ntracks_trackkalmanhit]
   Float_t         trkmommschi2_trackkalmanhit[14];   //[ntracks_trackkalmanhit]
   Float_t         trkmommsllhd_trackkalmanhit[14];   //[ntracks_trackkalmanhit]
   Float_t         trklen_trackkalmanhit[14];   //[ntracks_trackkalmanhit]
   Short_t         trksvtxid_trackkalmanhit[14];   //[ntracks_trackkalmanhit]
   Short_t         trkevtxid_trackkalmanhit[14];   //[ntracks_trackkalmanhit]
   Int_t           trkpidpdg_trackkalmanhit[14][3];   //[ntracks_trackkalmanhit]
   Float_t         trkpidchi_trackkalmanhit[14][3];   //[ntracks_trackkalmanhit]
   Float_t         trkpidchipr_trackkalmanhit[14][3];   //[ntracks_trackkalmanhit]
   Float_t         trkpidchika_trackkalmanhit[14][3];   //[ntracks_trackkalmanhit]
   Float_t         trkpidchipi_trackkalmanhit[14][3];   //[ntracks_trackkalmanhit]
   Float_t         trkpidchimu_trackkalmanhit[14][3];   //[ntracks_trackkalmanhit]
   Float_t         trkpidpida_trackkalmanhit[14][3];   //[ntracks_trackkalmanhit]
   Short_t         trkpidbestplane_trackkalmanhit[14];   //[ntracks_trackkalmanhit]

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_subrun;   //!
   TBranch        *b_event;   //!
   TBranch        *b_evttime;   //!
   TBranch        *b_beamtime;   //!
   TBranch        *b_pot;   //!
   TBranch        *b_isdata;   //!
   TBranch        *b_taulife;   //!
   TBranch        *b_no_hits;   //!
   TBranch        *b_hit_plane;   //!
   TBranch        *b_hit_wire;   //!
   TBranch        *b_hit_channel;   //!
   TBranch        *b_hit_peakT;   //!
   TBranch        *b_hit_charge;   //!
   TBranch        *b_hit_ph;   //!
   TBranch        *b_hit_startT;   //!
   TBranch        *b_hit_endT;   //!
   TBranch        *b_hit_trueX;   //!
   TBranch        *b_hit_goodnessOfFit;   //!
   TBranch        *b_hit_multiplicity;   //!
   TBranch        *b_hit_trkid;   //!
   TBranch        *b_hit_nelec;   //!
   TBranch        *b_hit_energy;   //!
   TBranch        *b_nvtx;   //!
   TBranch        *b_vtx;   //!
   TBranch        *b_no_flashes;   //!
   TBranch        *b_flash_time;   //!
   TBranch        *b_flash_pe;   //!
   TBranch        *b_flash_ycenter;   //!
   TBranch        *b_flash_zcenter;   //!
   TBranch        *b_nshowers;   //!
   TBranch        *b_showerID;   //!
   TBranch        *b_shwr_bestplane;   //!
   TBranch        *b_shwr_length;   //!
   TBranch        *b_shwr_startdcosx;   //!
   TBranch        *b_shwr_startdcosy;   //!
   TBranch        *b_shwr_startdcosz;   //!
   TBranch        *b_shwr_startx;   //!
   TBranch        *b_shwr_starty;   //!
   TBranch        *b_shwr_startz;   //!
   TBranch        *b_shwr_totEng;   //!
   TBranch        *b_shwr_dedx;   //!
   TBranch        *b_shwr_mipEng;   //!
   TBranch        *b_kNTracker;   //!
   TBranch        *b_mcevts_truth;   //!
   TBranch        *b_nuPDG_truth;   //!
   TBranch        *b_ccnc_truth;   //!
   TBranch        *b_mode_truth;   //!
   TBranch        *b_enu_truth;   //!
   TBranch        *b_Q2_truth;   //!
   TBranch        *b_W_truth;   //!
   TBranch        *b_X_truth;   //!
   TBranch        *b_Y_truth;   //!
   TBranch        *b_hitnuc_truth;   //!
   TBranch        *b_nuvtxx_truth;   //!
   TBranch        *b_nuvtxy_truth;   //!
   TBranch        *b_nuvtxz_truth;   //!
   TBranch        *b_nu_dcosx_truth;   //!
   TBranch        *b_nu_dcosy_truth;   //!
   TBranch        *b_nu_dcosz_truth;   //!
   TBranch        *b_lep_mom_truth;   //!
   TBranch        *b_lep_dcosx_truth;   //!
   TBranch        *b_lep_dcosy_truth;   //!
   TBranch        *b_lep_dcosz_truth;   //!
   TBranch        *b_tpx_flux;   //!
   TBranch        *b_tpy_flux;   //!
   TBranch        *b_tpz_flux;   //!
   TBranch        *b_tptype_flux;   //!
   TBranch        *b_genie_no_primaries;   //!
   TBranch        *b_genie_primaries_pdg;   //!
   TBranch        *b_genie_Eng;   //!
   TBranch        *b_genie_Px;   //!
   TBranch        *b_genie_Py;   //!
   TBranch        *b_genie_Pz;   //!
   TBranch        *b_genie_P;   //!
   TBranch        *b_genie_status_code;   //!
   TBranch        *b_genie_mass;   //!
   TBranch        *b_genie_trackID;   //!
   TBranch        *b_genie_ND;   //!
   TBranch        *b_genie_mother;   //!
   TBranch        *b_no_primaries;   //!
   TBranch        *b_geant_list_size;   //!
   TBranch        *b_geant_list_size_in_tpcAV;   //!
   TBranch        *b_pdg;   //!
   TBranch        *b_status;   //!
   TBranch        *b_Mass;   //!
   TBranch        *b_Eng;   //!
   TBranch        *b_EndE;   //!
   TBranch        *b_Px;   //!
   TBranch        *b_Py;   //!
   TBranch        *b_Pz;   //!
   TBranch        *b_P;   //!
   TBranch        *b_StartPointx;   //!
   TBranch        *b_StartPointy;   //!
   TBranch        *b_StartPointz;   //!
   TBranch        *b_StartT;   //!
   TBranch        *b_EndPointx;   //!
   TBranch        *b_EndPointy;   //!
   TBranch        *b_EndPointz;   //!
   TBranch        *b_EndT;   //!
   TBranch        *b_theta;   //!
   TBranch        *b_phi;   //!
   TBranch        *b_theta_xz;   //!
   TBranch        *b_theta_yz;   //!
   TBranch        *b_pathlen;   //!
   TBranch        *b_inTPCActive;   //!
   TBranch        *b_StartPointx_tpcAV;   //!
   TBranch        *b_StartPointy_tpcAV;   //!
   TBranch        *b_StartPointz_tpcAV;   //!
   TBranch        *b_EndPointx_tpcAV;   //!
   TBranch        *b_EndPointy_tpcAV;   //!
   TBranch        *b_EndPointz_tpcAV;   //!
   TBranch        *b_NumberDaughters;   //!
   TBranch        *b_Mother;   //!
   TBranch        *b_TrackId;   //!
   TBranch        *b_MergedId;   //!
   TBranch        *b_origin;   //!
   TBranch        *b_MCTruthIndex;   //!
   TBranch        *b_process_primary;   //!
   TBranch        *b_processname;   //!
   TBranch        *b_ntracks_trackkalmanhit;   //!
   TBranch        *b_trkId_trackkalmanhit;   //!
   TBranch        *b_trkncosmictags_tagger_trackkalmanhit;   //!
   TBranch        *b_trkcosmicscore_tagger_trackkalmanhit;   //!
   TBranch        *b_trkcosmictype_tagger_trackkalmanhit;   //!
   TBranch        *b_trkncosmictags_flashmatch_trackkalmanhit;   //!
   TBranch        *b_trkcosmicscore_flashmatch_trackkalmanhit;   //!
   TBranch        *b_trkcosmictype_flashmatch_trackkalmanhit;   //!
   TBranch        *b_trkke_trackkalmanhit;   //!
   TBranch        *b_trkrange_trackkalmanhit;   //!
   TBranch        *b_trkidtruth_trackkalmanhit;   //!
   TBranch        *b_trkorigin_trackkalmanhit;   //!
   TBranch        *b_trkpdgtruth_trackkalmanhit;   //!
   TBranch        *b_trkefftruth_trackkalmanhit;   //!
   TBranch        *b_trkpurtruth_trackkalmanhit;   //!
   TBranch        *b_trkpitchc_trackkalmanhit;   //!
   TBranch        *b_ntrkhits_trackkalmanhit;   //!
   TBranch        *b_trkdedx_trackkalmanhit;   //!
   TBranch        *b_trkdqdx_trackkalmanhit;   //!
   TBranch        *b_trkresrg_trackkalmanhit;   //!
   TBranch        *b_trkxyz_trackkalmanhit;   //!
   TBranch        *b_trkstartx_trackkalmanhit;   //!
   TBranch        *b_trkstarty_trackkalmanhit;   //!
   TBranch        *b_trkstartz_trackkalmanhit;   //!
   TBranch        *b_trkstartd_trackkalmanhit;   //!
   TBranch        *b_trkendx_trackkalmanhit;   //!
   TBranch        *b_trkendy_trackkalmanhit;   //!
   TBranch        *b_trkendz_trackkalmanhit;   //!
   TBranch        *b_trkendd_trackkalmanhit;   //!
   TBranch        *b_trktheta_trackkalmanhit;   //!
   TBranch        *b_trkphi_trackkalmanhit;   //!
   TBranch        *b_trkstartdcosx_trackkalmanhit;   //!
   TBranch        *b_trkstartdcosy_trackkalmanhit;   //!
   TBranch        *b_trkstartdcosz_trackkalmanhit;   //!
   TBranch        *b_trkenddcosx_trackkalmanhit;   //!
   TBranch        *b_trkenddcosy_trackkalmanhit;   //!
   TBranch        *b_trkenddcosz_trackkalmanhit;   //!
   TBranch        *b_trkthetaxz_trackkalmanhit;   //!
   TBranch        *b_trkthetayz_trackkalmanhit;   //!
   TBranch        *b_trkmom_trackkalmanhit;   //!
   TBranch        *b_trkmomrange_trackkalmanhit;   //!
   TBranch        *b_trkmommschi2_trackkalmanhit;   //!
   TBranch        *b_trkmommsllhd_trackkalmanhit;   //!
   TBranch        *b_trklen_trackkalmanhit;   //!
   TBranch        *b_trksvtxid_trackkalmanhit;   //!
   TBranch        *b_trkevtxid_trackkalmanhit;   //!
   TBranch        *b_trkpidpdg_trackkalmanhit;   //!
   TBranch        *b_trkpidchi_trackkalmanhit;   //!
   TBranch        *b_trkpidchipr_trackkalmanhit;   //!
   TBranch        *b_trkpidchika_trackkalmanhit;   //!
   TBranch        *b_trkpidchipi_trackkalmanhit;   //!
   TBranch        *b_trkpidchimu_trackkalmanhit;   //!
   TBranch        *b_trkpidpida_trackkalmanhit;   //!
   TBranch        *b_trkpidbestplane_trackkalmanhit;   //!

   anatree(TTree *tree=0);
   virtual ~anatree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef anatree_cxx
anatree::anatree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("prod_bnblike_gamma_standard_reco_hist.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("prod_bnblike_gamma_standard_reco_hist.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("prod_bnblike_gamma_standard_reco_hist.root:/analysistree");
      dir->GetObject("anatree",tree);

   }
   Init(tree);
}

anatree::~anatree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t anatree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t anatree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void anatree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   processname = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("subrun", &subrun, &b_subrun);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("evttime", &evttime, &b_evttime);
   fChain->SetBranchAddress("beamtime", &beamtime, &b_beamtime);
   fChain->SetBranchAddress("pot", &pot, &b_pot);
   fChain->SetBranchAddress("isdata", &isdata, &b_isdata);
   fChain->SetBranchAddress("taulife", &taulife, &b_taulife);
   fChain->SetBranchAddress("no_hits", &no_hits, &b_no_hits);
   fChain->SetBranchAddress("hit_plane", hit_plane, &b_hit_plane);
   fChain->SetBranchAddress("hit_wire", hit_wire, &b_hit_wire);
   fChain->SetBranchAddress("hit_channel", hit_channel, &b_hit_channel);
   fChain->SetBranchAddress("hit_peakT", hit_peakT, &b_hit_peakT);
   fChain->SetBranchAddress("hit_charge", hit_charge, &b_hit_charge);
   fChain->SetBranchAddress("hit_ph", hit_ph, &b_hit_ph);
   fChain->SetBranchAddress("hit_startT", hit_startT, &b_hit_startT);
   fChain->SetBranchAddress("hit_endT", hit_endT, &b_hit_endT);
   fChain->SetBranchAddress("hit_trueX", hit_trueX, &b_hit_trueX);
   fChain->SetBranchAddress("hit_goodnessOfFit", hit_goodnessOfFit, &b_hit_goodnessOfFit);
   fChain->SetBranchAddress("hit_multiplicity", hit_multiplicity, &b_hit_multiplicity);
   fChain->SetBranchAddress("hit_trkid", hit_trkid, &b_hit_trkid);
   fChain->SetBranchAddress("hit_nelec", hit_nelec, &b_hit_nelec);
   fChain->SetBranchAddress("hit_energy", hit_energy, &b_hit_energy);
   fChain->SetBranchAddress("nvtx", &nvtx, &b_nvtx);
   fChain->SetBranchAddress("vtx", &vtx, &b_vtx);
   fChain->SetBranchAddress("no_flashes", &no_flashes, &b_no_flashes);
   fChain->SetBranchAddress("flash_time", flash_time, &b_flash_time);
   fChain->SetBranchAddress("flash_pe", flash_pe, &b_flash_pe);
   fChain->SetBranchAddress("flash_ycenter", flash_ycenter, &b_flash_ycenter);
   fChain->SetBranchAddress("flash_zcenter", flash_zcenter, &b_flash_zcenter);
   fChain->SetBranchAddress("nshowers", &nshowers, &b_nshowers);
   fChain->SetBranchAddress("showerID", showerID, &b_showerID);
   fChain->SetBranchAddress("shwr_bestplane", shwr_bestplane, &b_shwr_bestplane);
   fChain->SetBranchAddress("shwr_length", shwr_length, &b_shwr_length);
   fChain->SetBranchAddress("shwr_startdcosx", shwr_startdcosx, &b_shwr_startdcosx);
   fChain->SetBranchAddress("shwr_startdcosy", shwr_startdcosy, &b_shwr_startdcosy);
   fChain->SetBranchAddress("shwr_startdcosz", shwr_startdcosz, &b_shwr_startdcosz);
   fChain->SetBranchAddress("shwr_startx", shwr_startx, &b_shwr_startx);
   fChain->SetBranchAddress("shwr_starty", shwr_starty, &b_shwr_starty);
   fChain->SetBranchAddress("shwr_startz", shwr_startz, &b_shwr_startz);
   fChain->SetBranchAddress("shwr_totEng", shwr_totEng, &b_shwr_totEng);
   fChain->SetBranchAddress("shwr_dedx", shwr_dedx, &b_shwr_dedx);
   fChain->SetBranchAddress("shwr_mipEng", shwr_mipEng, &b_shwr_mipEng);
   fChain->SetBranchAddress("kNTracker", &kNTracker, &b_kNTracker);
   fChain->SetBranchAddress("mcevts_truth", &mcevts_truth, &b_mcevts_truth);
   fChain->SetBranchAddress("nuPDG_truth", nuPDG_truth, &b_nuPDG_truth);
   fChain->SetBranchAddress("ccnc_truth", ccnc_truth, &b_ccnc_truth);
   fChain->SetBranchAddress("mode_truth", mode_truth, &b_mode_truth);
   fChain->SetBranchAddress("enu_truth", enu_truth, &b_enu_truth);
   fChain->SetBranchAddress("Q2_truth", Q2_truth, &b_Q2_truth);
   fChain->SetBranchAddress("W_truth", W_truth, &b_W_truth);
   fChain->SetBranchAddress("X_truth", X_truth, &b_X_truth);
   fChain->SetBranchAddress("Y_truth", Y_truth, &b_Y_truth);
   fChain->SetBranchAddress("hitnuc_truth", hitnuc_truth, &b_hitnuc_truth);
   fChain->SetBranchAddress("nuvtxx_truth", nuvtxx_truth, &b_nuvtxx_truth);
   fChain->SetBranchAddress("nuvtxy_truth", nuvtxy_truth, &b_nuvtxy_truth);
   fChain->SetBranchAddress("nuvtxz_truth", nuvtxz_truth, &b_nuvtxz_truth);
   fChain->SetBranchAddress("nu_dcosx_truth", nu_dcosx_truth, &b_nu_dcosx_truth);
   fChain->SetBranchAddress("nu_dcosy_truth", nu_dcosy_truth, &b_nu_dcosy_truth);
   fChain->SetBranchAddress("nu_dcosz_truth", nu_dcosz_truth, &b_nu_dcosz_truth);
   fChain->SetBranchAddress("lep_mom_truth", lep_mom_truth, &b_lep_mom_truth);
   fChain->SetBranchAddress("lep_dcosx_truth", lep_dcosx_truth, &b_lep_dcosx_truth);
   fChain->SetBranchAddress("lep_dcosy_truth", lep_dcosy_truth, &b_lep_dcosy_truth);
   fChain->SetBranchAddress("lep_dcosz_truth", lep_dcosz_truth, &b_lep_dcosz_truth);
   fChain->SetBranchAddress("tpx_flux", tpx_flux, &b_tpx_flux);
   fChain->SetBranchAddress("tpy_flux", tpy_flux, &b_tpy_flux);
   fChain->SetBranchAddress("tpz_flux", tpz_flux, &b_tpz_flux);
   fChain->SetBranchAddress("tptype_flux", tptype_flux, &b_tptype_flux);
   fChain->SetBranchAddress("genie_no_primaries", &genie_no_primaries, &b_genie_no_primaries);
   fChain->SetBranchAddress("genie_primaries_pdg", &genie_primaries_pdg, &b_genie_primaries_pdg);
   fChain->SetBranchAddress("genie_Eng", &genie_Eng, &b_genie_Eng);
   fChain->SetBranchAddress("genie_Px", &genie_Px, &b_genie_Px);
   fChain->SetBranchAddress("genie_Py", &genie_Py, &b_genie_Py);
   fChain->SetBranchAddress("genie_Pz", &genie_Pz, &b_genie_Pz);
   fChain->SetBranchAddress("genie_P", &genie_P, &b_genie_P);
   fChain->SetBranchAddress("genie_status_code", &genie_status_code, &b_genie_status_code);
   fChain->SetBranchAddress("genie_mass", &genie_mass, &b_genie_mass);
   fChain->SetBranchAddress("genie_trackID", &genie_trackID, &b_genie_trackID);
   fChain->SetBranchAddress("genie_ND", &genie_ND, &b_genie_ND);
   fChain->SetBranchAddress("genie_mother", &genie_mother, &b_genie_mother);
   fChain->SetBranchAddress("no_primaries", &no_primaries, &b_no_primaries);
   fChain->SetBranchAddress("geant_list_size", &geant_list_size, &b_geant_list_size);
   fChain->SetBranchAddress("geant_list_size_in_tpcAV", &geant_list_size_in_tpcAV, &b_geant_list_size_in_tpcAV);
   fChain->SetBranchAddress("pdg", pdg, &b_pdg);
   fChain->SetBranchAddress("status", status, &b_status);
   fChain->SetBranchAddress("Mass", Mass, &b_Mass);
   fChain->SetBranchAddress("Eng", Eng, &b_Eng);
   fChain->SetBranchAddress("EndE", EndE, &b_EndE);
   fChain->SetBranchAddress("Px", Px, &b_Px);
   fChain->SetBranchAddress("Py", Py, &b_Py);
   fChain->SetBranchAddress("Pz", Pz, &b_Pz);
   fChain->SetBranchAddress("P", P, &b_P);
   fChain->SetBranchAddress("StartPointx", StartPointx, &b_StartPointx);
   fChain->SetBranchAddress("StartPointy", StartPointy, &b_StartPointy);
   fChain->SetBranchAddress("StartPointz", StartPointz, &b_StartPointz);
   fChain->SetBranchAddress("StartT", StartT, &b_StartT);
   fChain->SetBranchAddress("EndPointx", EndPointx, &b_EndPointx);
   fChain->SetBranchAddress("EndPointy", EndPointy, &b_EndPointy);
   fChain->SetBranchAddress("EndPointz", EndPointz, &b_EndPointz);
   fChain->SetBranchAddress("EndT", EndT, &b_EndT);
   fChain->SetBranchAddress("theta", theta, &b_theta);
   fChain->SetBranchAddress("phi", phi, &b_phi);
   fChain->SetBranchAddress("theta_xz", theta_xz, &b_theta_xz);
   fChain->SetBranchAddress("theta_yz", theta_yz, &b_theta_yz);
   fChain->SetBranchAddress("pathlen", pathlen, &b_pathlen);
   fChain->SetBranchAddress("inTPCActive", inTPCActive, &b_inTPCActive);
   fChain->SetBranchAddress("StartPointx_tpcAV", StartPointx_tpcAV, &b_StartPointx_tpcAV);
   fChain->SetBranchAddress("StartPointy_tpcAV", StartPointy_tpcAV, &b_StartPointy_tpcAV);
   fChain->SetBranchAddress("StartPointz_tpcAV", StartPointz_tpcAV, &b_StartPointz_tpcAV);
   fChain->SetBranchAddress("EndPointx_tpcAV", EndPointx_tpcAV, &b_EndPointx_tpcAV);
   fChain->SetBranchAddress("EndPointy_tpcAV", EndPointy_tpcAV, &b_EndPointy_tpcAV);
   fChain->SetBranchAddress("EndPointz_tpcAV", EndPointz_tpcAV, &b_EndPointz_tpcAV);
   fChain->SetBranchAddress("NumberDaughters", NumberDaughters, &b_NumberDaughters);
   fChain->SetBranchAddress("Mother", Mother, &b_Mother);
   fChain->SetBranchAddress("TrackId", TrackId, &b_TrackId);
   fChain->SetBranchAddress("MergedId", MergedId, &b_MergedId);
   fChain->SetBranchAddress("origin", origin, &b_origin);
   fChain->SetBranchAddress("MCTruthIndex", MCTruthIndex, &b_MCTruthIndex);
   fChain->SetBranchAddress("process_primary", process_primary, &b_process_primary);
   fChain->SetBranchAddress("processname", &processname, &b_processname);
   fChain->SetBranchAddress("ntracks_trackkalmanhit", &ntracks_trackkalmanhit, &b_ntracks_trackkalmanhit);
   fChain->SetBranchAddress("trkId_trackkalmanhit", trkId_trackkalmanhit, &b_trkId_trackkalmanhit);
   fChain->SetBranchAddress("trkncosmictags_tagger_trackkalmanhit", trkncosmictags_tagger_trackkalmanhit, &b_trkncosmictags_tagger_trackkalmanhit);
   fChain->SetBranchAddress("trkcosmicscore_tagger_trackkalmanhit", trkcosmicscore_tagger_trackkalmanhit, &b_trkcosmicscore_tagger_trackkalmanhit);
   fChain->SetBranchAddress("trkcosmictype_tagger_trackkalmanhit", trkcosmictype_tagger_trackkalmanhit, &b_trkcosmictype_tagger_trackkalmanhit);
   fChain->SetBranchAddress("trkncosmictags_flashmatch_trackkalmanhit", trkncosmictags_flashmatch_trackkalmanhit, &b_trkncosmictags_flashmatch_trackkalmanhit);
   fChain->SetBranchAddress("trkcosmicscore_flashmatch_trackkalmanhit", trkcosmicscore_flashmatch_trackkalmanhit, &b_trkcosmicscore_flashmatch_trackkalmanhit);
   fChain->SetBranchAddress("trkcosmictype_flashmatch_trackkalmanhit", trkcosmictype_flashmatch_trackkalmanhit, &b_trkcosmictype_flashmatch_trackkalmanhit);
   fChain->SetBranchAddress("trkke_trackkalmanhit", trkke_trackkalmanhit, &b_trkke_trackkalmanhit);
   fChain->SetBranchAddress("trkrange_trackkalmanhit", trkrange_trackkalmanhit, &b_trkrange_trackkalmanhit);
   fChain->SetBranchAddress("trkidtruth_trackkalmanhit", trkidtruth_trackkalmanhit, &b_trkidtruth_trackkalmanhit);
   fChain->SetBranchAddress("trkorigin_trackkalmanhit", trkorigin_trackkalmanhit, &b_trkorigin_trackkalmanhit);
   fChain->SetBranchAddress("trkpdgtruth_trackkalmanhit", trkpdgtruth_trackkalmanhit, &b_trkpdgtruth_trackkalmanhit);
   fChain->SetBranchAddress("trkefftruth_trackkalmanhit", trkefftruth_trackkalmanhit, &b_trkefftruth_trackkalmanhit);
   fChain->SetBranchAddress("trkpurtruth_trackkalmanhit", trkpurtruth_trackkalmanhit, &b_trkpurtruth_trackkalmanhit);
   fChain->SetBranchAddress("trkpitchc_trackkalmanhit", trkpitchc_trackkalmanhit, &b_trkpitchc_trackkalmanhit);
   fChain->SetBranchAddress("ntrkhits_trackkalmanhit", ntrkhits_trackkalmanhit, &b_ntrkhits_trackkalmanhit);
   fChain->SetBranchAddress("trkdedx_trackkalmanhit", trkdedx_trackkalmanhit, &b_trkdedx_trackkalmanhit);
   fChain->SetBranchAddress("trkdqdx_trackkalmanhit", trkdqdx_trackkalmanhit, &b_trkdqdx_trackkalmanhit);
   fChain->SetBranchAddress("trkresrg_trackkalmanhit", trkresrg_trackkalmanhit, &b_trkresrg_trackkalmanhit);
   fChain->SetBranchAddress("trkxyz_trackkalmanhit", trkxyz_trackkalmanhit, &b_trkxyz_trackkalmanhit);
   fChain->SetBranchAddress("trkstartx_trackkalmanhit", trkstartx_trackkalmanhit, &b_trkstartx_trackkalmanhit);
   fChain->SetBranchAddress("trkstarty_trackkalmanhit", trkstarty_trackkalmanhit, &b_trkstarty_trackkalmanhit);
   fChain->SetBranchAddress("trkstartz_trackkalmanhit", trkstartz_trackkalmanhit, &b_trkstartz_trackkalmanhit);
   fChain->SetBranchAddress("trkstartd_trackkalmanhit", trkstartd_trackkalmanhit, &b_trkstartd_trackkalmanhit);
   fChain->SetBranchAddress("trkendx_trackkalmanhit", trkendx_trackkalmanhit, &b_trkendx_trackkalmanhit);
   fChain->SetBranchAddress("trkendy_trackkalmanhit", trkendy_trackkalmanhit, &b_trkendy_trackkalmanhit);
   fChain->SetBranchAddress("trkendz_trackkalmanhit", trkendz_trackkalmanhit, &b_trkendz_trackkalmanhit);
   fChain->SetBranchAddress("trkendd_trackkalmanhit", trkendd_trackkalmanhit, &b_trkendd_trackkalmanhit);
   fChain->SetBranchAddress("trktheta_trackkalmanhit", trktheta_trackkalmanhit, &b_trktheta_trackkalmanhit);
   fChain->SetBranchAddress("trkphi_trackkalmanhit", trkphi_trackkalmanhit, &b_trkphi_trackkalmanhit);
   fChain->SetBranchAddress("trkstartdcosx_trackkalmanhit", trkstartdcosx_trackkalmanhit, &b_trkstartdcosx_trackkalmanhit);
   fChain->SetBranchAddress("trkstartdcosy_trackkalmanhit", trkstartdcosy_trackkalmanhit, &b_trkstartdcosy_trackkalmanhit);
   fChain->SetBranchAddress("trkstartdcosz_trackkalmanhit", trkstartdcosz_trackkalmanhit, &b_trkstartdcosz_trackkalmanhit);
   fChain->SetBranchAddress("trkenddcosx_trackkalmanhit", trkenddcosx_trackkalmanhit, &b_trkenddcosx_trackkalmanhit);
   fChain->SetBranchAddress("trkenddcosy_trackkalmanhit", trkenddcosy_trackkalmanhit, &b_trkenddcosy_trackkalmanhit);
   fChain->SetBranchAddress("trkenddcosz_trackkalmanhit", trkenddcosz_trackkalmanhit, &b_trkenddcosz_trackkalmanhit);
   fChain->SetBranchAddress("trkthetaxz_trackkalmanhit", trkthetaxz_trackkalmanhit, &b_trkthetaxz_trackkalmanhit);
   fChain->SetBranchAddress("trkthetayz_trackkalmanhit", trkthetayz_trackkalmanhit, &b_trkthetayz_trackkalmanhit);
   fChain->SetBranchAddress("trkmom_trackkalmanhit", trkmom_trackkalmanhit, &b_trkmom_trackkalmanhit);
   fChain->SetBranchAddress("trkmomrange_trackkalmanhit", trkmomrange_trackkalmanhit, &b_trkmomrange_trackkalmanhit);
   fChain->SetBranchAddress("trkmommschi2_trackkalmanhit", trkmommschi2_trackkalmanhit, &b_trkmommschi2_trackkalmanhit);
   fChain->SetBranchAddress("trkmommsllhd_trackkalmanhit", trkmommsllhd_trackkalmanhit, &b_trkmommsllhd_trackkalmanhit);
   fChain->SetBranchAddress("trklen_trackkalmanhit", trklen_trackkalmanhit, &b_trklen_trackkalmanhit);
   fChain->SetBranchAddress("trksvtxid_trackkalmanhit", trksvtxid_trackkalmanhit, &b_trksvtxid_trackkalmanhit);
   fChain->SetBranchAddress("trkevtxid_trackkalmanhit", trkevtxid_trackkalmanhit, &b_trkevtxid_trackkalmanhit);
   fChain->SetBranchAddress("trkpidpdg_trackkalmanhit", trkpidpdg_trackkalmanhit, &b_trkpidpdg_trackkalmanhit);
   fChain->SetBranchAddress("trkpidchi_trackkalmanhit", trkpidchi_trackkalmanhit, &b_trkpidchi_trackkalmanhit);
   fChain->SetBranchAddress("trkpidchipr_trackkalmanhit", trkpidchipr_trackkalmanhit, &b_trkpidchipr_trackkalmanhit);
   fChain->SetBranchAddress("trkpidchika_trackkalmanhit", trkpidchika_trackkalmanhit, &b_trkpidchika_trackkalmanhit);
   fChain->SetBranchAddress("trkpidchipi_trackkalmanhit", trkpidchipi_trackkalmanhit, &b_trkpidchipi_trackkalmanhit);
   fChain->SetBranchAddress("trkpidchimu_trackkalmanhit", trkpidchimu_trackkalmanhit, &b_trkpidchimu_trackkalmanhit);
   fChain->SetBranchAddress("trkpidpida_trackkalmanhit", trkpidpida_trackkalmanhit, &b_trkpidpida_trackkalmanhit);
   fChain->SetBranchAddress("trkpidbestplane_trackkalmanhit", trkpidbestplane_trackkalmanhit, &b_trkpidbestplane_trackkalmanhit);
   Notify();
}

Bool_t anatree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void anatree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t anatree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef anatree_cxx

/**
 * \file XiaoEventAna.h
 *
 * \ingroup CCInclusive
 *
 * \brief Ana module that uses XiaoNuFinder to find 1mu1p events then makes histograms about them
 *
 *     track: pandoraNuPMA
 *     vtx: pmtrack
 *     calorimetry: pandoraNuPMAcalo
 *
 *
 * @author davidkaleko
 */

/** \addtogroup CCInclusive

    @{*/

#ifndef LARLITE_XIAOEVENTANA_H
#define LARLITE_XIAOEVENTANA_H

#include "Analysis/ana_base.h"
#include "DataFormat/track.h"
#include "DataFormat/vertex.h"
#include "DataFormat/calorimetry.h"
#include "GeoAlgo/GeoVector.h"
#include "GeoAlgo/GeoSphere.h"
#include "GeoAlgo/GeoAABox.h"
#include "LArUtil/Geometry.h"
#include "XiaoNuFinder.h"
#include "TH1.h"
#include "TH2.h"
#include "TTree.h"
#include "CCInclusiveConstants.h"

namespace larlite {
  /**
     \class XiaoEventAna
     User custom analysis class made by SHELL_USER_NAME
   */
  class XiaoEventAna : public ana_base {

  public:

    /// Default constructor
    XiaoEventAna() {
      _name = "XiaoEventAna";
      _fout = 0;
      // _hmult = 0;
      // _hdedx = 0;
      _hcorrect_ID = 0;
      _running_on_data = false;
      _tree = 0;
      _filetype = kINPUT_FILE_TYPE_MAX;
    }
  
    /// Default destructor
    virtual ~XiaoEventAna() {}

    virtual bool initialize();

    virtual bool analyze(storage_manager* storage);

    virtual bool finalize();

    void setRunningOnData(bool flag) { _running_on_data = flag; }

    void setInputType(InputFileType_t filetype) { _filetype = filetype; }

  protected:

    XiaoNuFinder _nu_finder;

    void resetTTreeVars();

    InputFileType_t _filetype;

    size_t total_events;
    size_t passed_events;
    double fidvol_dist_x;
    double fidvol_dist_y;
    double fidvol_dist_z;
    // double BGW_mintime;
    // double BGW_maxtime;

    // // Fiducial volume box
    geoalgo::AABox _fidvolBox;

    // TH1F *_hmult;
    // TH2D *_hdedx;
    TH1F *_hcorrect_ID;

    bool _running_on_data;

    TTree *_tree;
    double _mu_start_dedx;
    double _mu_end_dedx;
    bool   _correct_ID;
    double _mu_phi;
    double _p_phi;
    double _mu_contained;
    double _true_nu_E;
    int    _true_nu_pdg;
    bool   _true_nu_CCNC;
    int    _true_nu_mode;
    int    _true_lepton_pdg;
    double _true_lepton_momentum;
    int    _fndecay;
    double _mu_p_dirdot;
    int _n_associated_tracks;

    double _longest_trk_len;
    double _longest_trk_theta;

  };
}
#endif

/** @} */ // end of doxygen group
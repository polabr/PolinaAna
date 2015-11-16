/**
 * \file ERAnaCosmicValidation.h
 *
 * \ingroup ERToolStuff
 *
 * \brief Class def header for a class ERAnaCosmicValidation
 *
 * @author davidkaleko
 */

/** \addtogroup ERToolStuff

    @{*/

#ifndef ERTOOL_ERANACOSMICVALIDATION_H
#define ERTOOL_ERANACOSMICVALIDATION_H

#include "ERTool/Base/AnaBase.h"
#include "TTree.h"

namespace ertool {

/**
   \class ERAnaCosmicValidation
   User custom Analysis class made by kazuhiro
 */
class ERAnaCosmicValidation : public AnaBase {

public:

  /// Default constructor
  ERAnaCosmicValidation(const std::string& name = "ERAnaCosmicValidation");

  /// Default destructor
  virtual ~ERAnaCosmicValidation() {}

  /// Reset function
  virtual void Reset() {};

  /// Function to accept fclite::PSet
  void AcceptPSet(const ::fcllite::PSet& cfg) {};

  /// Called @ before processing the first event sample
  void ProcessBegin() {};

  /// Function to evaluate input showers and determine a score
  bool Analyze(const EventData &data, const ParticleGraph &ps);

  /// Called after processing the last event sample
  void ProcessEnd(TFile* fout = nullptr);

  /// set the energy cut to be used when counting particles
  void SetECut(double c) { _eCut = c; }

private:

  float _eCut;

  // Result tree comparison for reconstructed events
  // Filled once per ERTool Track or ERTool Shower!
  TTree* _result_tree;
  bool _is_track; // Whether this ttree entry is from an ertool shower, or an ertool track
  bool _true_primary; // Whether this ertool object is truly a cosmic primary
  bool _true_secondary; // Whether this ertool object is truly a cosmic secondary
  bool _reco_primary; // Whether this ertool object was tagged a cosmic primary
  bool _reco_secondary; // Whether this ertool object was tagged a cosmic secondary

// prepare TTree with variables
  void PrepareTreeVariables();
  /// Function to re-set TTree variables
  void ResetTreeVariables();
};
}
#endif

/** @} */ // end of doxygen group
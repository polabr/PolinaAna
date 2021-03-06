/**
 * \file MC_1eNpNn0else_Filter.h
 *
 * \ingroup CCQESelection
 * 
 * \brief Class def header for a class MC_1eNpNn0else_Filter.h
 *
 * @author davidkaleko
 */

/** \addtogroup CCQESelection

    @{*/

#ifndef LARLITE_MC_1ENPNN0ELSE_FILTER_H
#define LARLITE_MC_1ENPNN0ELSE_FILTER_H

#include "Analysis/ana_base.h"
#include "DataFormat/mctruth.h"

namespace larlite {
  /**
     \class MC_1eNpNn0else_Filter
     User custom analysis class made by davidkaleko
   */
  class MC_1eNpNn0else_Filter : public ana_base{
  
  public:

    /// Default constructor
    MC_1eNpNn0else_Filter(){ _name="MC_1eNpNn0else_Filter"; _fout=0; _flip=false;};

    /// Default destructor
    virtual ~MC_1eNpNn0else_Filter(){};

    /** IMPLEMENT in MC_1eNpNn0else_Filter.cc!
        Initialization method to be called before the analysis event loop.
    */ 
    virtual bool initialize();

    /** IMPLEMENT in MC_1eNpNn0else_Filter.cc! 
        Analyze a data event-by-event  
    */
    virtual bool analyze(storage_manager* storage);

    /** IMPLEMENT in MC_1eNpNn0else_Filter.cc! 
        Finalize method to be called after all events processed.
    */
    virtual bool finalize();

    void flip(bool on) { _flip = on; }

    protected:

    size_t total_events;
    size_t kept_events;

    // boolean to flip logical operation of algorithm
    bool _flip;
    
  };
}
#endif

//**************************************************************************
// 
// For Analysis framework documentation, read Manual.pdf here:
//
// http://microboone-docdb.fnal.gov:8080/cgi-bin/ShowDocument?docid=3183
//
//**************************************************************************

/** @} */ // end of doxygen group 

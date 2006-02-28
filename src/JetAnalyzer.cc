// $Id: JetAnalyzer.cc,v 1.2 2006/02/21 10:37:34 llista Exp $
#include "PhysicsTools/JetExamples/src/JetAnalyzer.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "FWCore/Framework/interface/Handle.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include <iostream>
using namespace reco;
using namespace edm;
using namespace std;

typedef Candidate Jet;
typedef CandidateCollection JetCollection;

JetAnalyzer::JetAnalyzer( const ParameterSet & p ) :
  src( p.getParameter<string>( "src" ) ),
  file( p.getParameter<string>( "fileName" ).c_str(), "RECREATE" ),
  jetPt  ( "jetPt", "jet transverse momentun", 50, 0, 1000 ) {
}

JetAnalyzer::~JetAnalyzer() {
  file.cd();
  jetPt.Write();
}

void JetAnalyzer::analyze( const Event& evt, const EventSetup& ) {
  Handle<JetCollection> cands;
  evt.getByLabel( src, cands );
  cout << ">>> jets found: " << cands->size() << endl;
  for( JetCollection::const_iterator c = cands->begin(); c != cands->end(); ++ c ) {
    jetPt.Fill( c->pt() );
  } 
}

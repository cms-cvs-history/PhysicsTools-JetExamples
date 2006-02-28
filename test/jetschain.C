{
   gSystem->Load("libPhysicsToolsFWLite");
   AutoLibraryLoader::enable();
   TChain jets("Events");
   jets.Add("jets.root");
   gSystem->Load( "libPhysicsToolsJetExamples" );
   JetTSelector * selector = new JetTSelector;
   jets.Process( selector );
}

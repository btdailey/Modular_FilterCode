//System includes
#include <vector>

///////Global Variables (needed in more than 1 function)
#ifdef __MAKECINT__
#pragma link C++ class vector<vector<double> >+;
#endif

int groupFlag=0;
vector< vector<int> > antenna_group_holder;
vector<int> unique_phis;
int antenna_groups_size;
double baselineFreq[2000]={0.};
vector< vector<double> > baselinearray (NUM_ANTS_WITH_NADIRS, vector<double>(130));
vector< vector<double> > baselinearray_dB (NUM_ANTS_WITH_NADIRS, vector<double>(130));
vector< vector<double> > baselinearrayHoriz (NUM_ANTS_WITH_NADIRS, vector<double>(130));
vector< vector<double> > baselinearrayHoriz_dB (NUM_ANTS_WITH_NADIRS, vector<double>(130));

//////////////////////////////////////////////////// 

//For Use In PointThisEvent

vector< vector<double> > notchFreqs;
vector< vector<double> > notchBands;
vector< vector<double> > notchFreqs_Horiz;
vector< vector<double> > notchBands_Horiz;
vector< vector<double> > notchPhase;
vector< vector<double> > notchPhaseBands;
vector< vector<double> > notchPhase_Horiz;
vector< vector<double> > notchPhaseBands_Horiz;


vector< double > uniquefreqs;
vector< double > uniqueBands;
vector< double > uniquePhase;

int nAntennasToUse = 9;//number antennas to use in each group (9 for 3 phis sectors)
 
getNotchandBandwidth( nfreq,dBCut, nAntennasToUse,nadirFlag,notchFreqs,notchBands ,notchFreqs_Horiz,notchBands_Horiz ,notchPhase,notchPhaseBands ,notchPhase_Horiz,notchPhaseBands_Horiz,meanFreqVert,meanFreqHoriz);//Get notch locations and bandwidth of each notch for every antenna

for(int j=0;j<notchFreqs.size();j++){//loop through every antenna
  uniquefreqs = notchFreqs[j];//set vectors needed for functions
  uniqueBands = notchBands[j];
  uniquePhase = notchPhase[j];
  for(int k=0;k<(int)uniquefreqs.size();k++){
    
    if (uniquefreqs[k]!=-1 && printFlag==1) cout<<"WZ going to cut: "<<uniquefreqs[k]<<" MHz in Vert for ant == "<<j<<endl;
    if (uniquefreqs[k]!=-1) didIFilter++;
    if (uniquefreqs[k]!=-1 && uniquefreqs[k]>286) didIFilterAboveSatellite++;
    bandWidth = uniqueBands[k];	
    
    if(printFlag==1)	cout<<"bandwidth is "<<bandWidth<<"\n";
    
    if(uniquefreqs[k]>0) applyAdaptiveFilter_singleAnt(uniquefreqs[k], bandWidth,0,j);//apply filter in Vert
    
  }//k
  
  if(uniquefreqs.size()>0) GeomMethod(j,0,uniquefreqs, uniqueBands,uniquePhase);//apply phase filter 

 }//j

for(int j=0;j<notchFreqs_Horiz.size();j++){//loop through horizontal
  uniquefreqs = notchFreqs_Horiz[j];
  uniqueBands = notchBands_Horiz[j];
  uniquePhase = notchPhase_Horiz[j];
  for(int k=0;k<(int)uniquefreqs.size();k++){
    
    if (uniquefreqs[k]!=-1 && printFlag==1) cout<<"WZ going to cut: "<<uniquefreqs[k]<<" MHz in Horiz for ant == "<<j<<endl;
    
    bandWidth = uniqueBands[k];
    
    if(uniquefreqs[k]>0) applyAdaptiveFilter_singleAnt(uniquefreqs[k],bandWidth,1,j);//apply filter in Horiz
    
  }//k
  
  

  if(uniquefreqs.size()>0) GeomMethod(j,1,uniquefreqs, uniqueBands,uniquePhase);//apply phase filter in Horiz
 }//j


	

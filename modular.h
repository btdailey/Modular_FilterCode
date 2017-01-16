//include 
#include <vector>


void getNotchandBandwidth(int nfreq,double dBCut,int nAntennasToUse, int nadirFlag,std::vector< std::vector<double> > &notchFreqs,std::vector< std::vector<double> > &notchBands ,std::vector< std::vector<double> > &notchFreqs_Horiz,std::vector< std::vector<double> > &notchBands_Horiz ,std::vector< std::vector<double> > &notchPhase,std::vector< std::vector<double> > &notchPhaseBands ,std::vector< std::vector<double> > &notchPhase_Horiz,std::vector< std::vector<double> > &notchPhaseBands_Horiz,float meanFreqVert, float meanFreqHoriz);

void getGroupsofAntennas(int nantennasToUse, int nadirFlag);

void adaptiveFilterPartialPayload(int pol, double dBCut, int nfreq, double *frequencies,double *bandwidth,double *magPeaks,int nAntennasToUse, std::vector<int>& whichAntennasToUse,float &mean_freq);

void GetFrequenciestoCut(int antenna,std::vector< std::vector<double> > &antennaFreq,std::vector< std::vector<double> > &bandwidth, std::vector< std::vector<double> > &PeakMag, std::vector<double>& uniquefreqs,std::vector<double>& uniquebandwidth, int nfreq,std::vector<double>& uniquePhase,std::vector<double>& uniquePhase_bandwidth);
 

void readBaselineFFTs_Brian();

void GetBaselineperPhi(int pol, double *baseline, int nantennasToUse,std::vector<int>& whichAntennasToUse);
 

void applyAdaptiveFilter_singleAnt(double centerFrequency, double bandWidth, int polFlag,int ant);

void GeomMethod(int ant,int pol,std::vector<double> Freq,std::vector<double> bandWidth, std::vector<double> cutFreqs);
TGraph *interpolatedFilter(TGraph *grWave, Double_t minFreq, Double_t maxFreq);  
double solveGamma_plus(double theta, double psi, double delta);
double solveGamma_minus(double theta, double psi, double delta);

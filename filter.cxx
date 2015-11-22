#include <iostream>
#include <fstream>  //to print sth in file

using namespace std;

double* read(int&);

void filter(double*, const int);

void print(double*, const int);


int main(){
    int N;
    double* f;
    
    f= read(N);
    
    int iterations=1; // how many times is the filter used
    for(int i=0; i<iterations; i++)
    filter(f, N);
    
    print(f, N);
    
    delete[] f; //erst hier den Speicher wieder freigeben!!!!
    return 0;
}

double* read(int& N){
    //read in noisy.txt to get number of lines
    ifstream lines("noisy.txt"); // man kann die Datei nicht nur einmal einlesen,  noisy>>... springt dann zur nächste Spalte wenn man die signal values einlesen will (alle Werte 0, weil es keine zweite Spalte gibt)
    
    // find the number of lines
    double temp;
    N=0;
    while(lines>>temp) 
        N++;
            //cout<<N<<endl; //check N
    lines.close();

    // read in noisy.txt signal to save signal values in f
    ifstream noisy("noisy.txt");
    
    //dynamic allocation of memory
    double* f=new double[N];
    
        
    for(int i=0; i<N; i++)
        noisy>>f[i];
    
        noisy.close();

       return f;
    }
    
void filter(double* f, const int N){
    double f0=f[N-1];
    double flast=f[0];
    for (int i=0; i<(N-1); i++){ //the last value after for loop because of periodic boundaries
     double ftemp=f[i];
     f[i]=(f0+f[i]+f[i+1])/3;
     f0=ftemp;
    }
    
    f[N-1]=(f0+f[N-1]+flast)/3;
    
}

void print(double* f, const int N){
    ofstream filtered("filtered.txt");
    for(int i=0; i<N; i++)
        filtered<<f[i]<<endl;
    
    filtered.close();
    
}
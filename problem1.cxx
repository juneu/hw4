#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void fill(double*, const int);
void maxmin(const double* const, const int, double&, double&);

int main(){
    srand(time(NULL));
    const int N=100;
    double p[N];
    double max, min;
    fill(p, N);
    maxmin(p, N, max, min);
    
    cout<<"Maximum="<<max<<endl;
    cout<<"Minimum="<<min<<endl;
    
    return 0;
}

void fill(double* p, const int N){
    for(int i=0; i<N; i++){
        p[i]=rand();
    //cout<<p[i]<<endl;
    }
}

void maxmin(const double* const p, const int N, double& max, double&min){
    max=0; 
    min=RAND_MAX;
    for (int i=0; i<N; i++){
    if (p[i]<min)
         min=p[i];
    if (p[i]>max)
    max=p[i];
        
    }
    
}


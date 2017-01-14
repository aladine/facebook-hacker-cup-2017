#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

const int threshold = 50;
int getNumberTrip(int w[], int n){
  sort(w, w+n);
  int total = 0;
  for(int st = 0, ed = n-1; st <= ed; ed--){
    int t = ceil(float(threshold)/float(w[ed]));
    st += t-1;
    if(st<= ed) 
    total++;
  }
  return total;
} 

int main(){
    int T;
    scanf("%d", &T);
    
    for (int i=0; i< T;i++){
        int n;
        scanf("%d", &n);
        int w[n];
        for (int j=0; j< n;j++){
            scanf("%d", &w[j]);
        }
        cout << "Case #" << i+1<< ": "<< getNumberTrip(w,n) << endl;
    }
    return 0    ;
}



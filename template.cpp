#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int solve(int w[], int n){
    return 0;
}


int main(){
    int T;
    cin >> T;
    
    for (int i=0; i< T;i++){
        int n;
        cin >> n;
        int w[n];
        for (int j=0; j< n;j++){
            cin >> w[j];
        }
        cout << "Case #" << i+1<< ": "<< solve(w,n) << endl;
    }
    return 0    ;
}

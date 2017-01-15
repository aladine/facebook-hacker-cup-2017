#include <iostream>
#include <algorithm>
#include <math.h>

#define ll long long

using namespace std;

ll memo[300];

void preprocess(){
    memo[0]=1;
    for(int j = 1; j < 300; j++){
        memo[j] = memo[j-1]*j;
    }
}


ll getCombinator(ll balls, ll box){
    return memo[balls+box-1]/ (memo[box-1]* memo[balls]);
}

ll solve(int r[], int n, int m){
//     2 5
// r1
// r2
    ll ways = 0;
    // implementation
    if(n>m) return 0;
    // sort(r, r+n);
    // reverse(r, r+n);
    
    int sum = 0;
    int v[n];// 0..n
    for(int j = 0; j < n; j++){
        v[j] = j;
        sum += r[j];
    }
    // early prune 
    // if (2*sum -r[0]-r[1] > m-1) return 0;



    //using permutation 
    do {
        // cout << "permutation ";
        // for(int j = 0; j < n; j++){
        //     cout << v[j] << " ";
        // }
        // cout << endl;
        ll diff = m-1-(2*sum -r[v[0]]-r[v[n-1]]);
        cout << "diff: "<< diff << endl;
        if(diff < 0){
            continue;
        }
        if (diff == 0) {
            ways++;
            continue;
        }

        for(int j = 0; j <= diff; j++){
            // j outside the r0 and rn-1 position
            // inside is diff -j
            // int result = 0;
            // select diff -j space inside diff-r[0]-r[1]
            ll result = getCombinator(diff-j, n-1);


            result *= (j+1);
            cout << "result" << result << endl;
            ways += result;
        }


    }while( std::next_permutation(v,v+n) );
    return ways;
}


int main(){
    preprocess();
    int T;
    cin >> T;
    
    for (int i=0; i< T;i++){
        int n,m;
        cin >> n>> m;
        int r[n];
        for (int j=0; j< n;j++){
            cin >> r[j];
        }
        cout << "Case #" << i+1<< ": "<< solve(r,n,m) << endl;
    }
    return 0    ;
}

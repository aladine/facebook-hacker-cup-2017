#include <iostream>
#include <algorithm>
#include <math.h>

#define ll long long
#define MAX_MEMO 2000

using namespace std;

ll memo[MAX_MEMO];

void preprocess(){
    memo[0]=1;
    for(int j = 1; j < MAX_MEMO; j++){
        memo[j] = memo[j-1]*j;
    }
}


ll getCombinator(ll balls, ll box){
    ll b = box-1;

    if (balls > b ) {
        int tmp = balls;
        balls = b; 
        b = tmp;
    }

    ll rel = 1;
    for(int j = b+1; j <= b+balls; j++){
        rel*= j;
    }

    return rel/memo[balls];
}

ll solve(int r[], int n, int m){
if (n ==1) return m;
    ll ways = 0;
    // implementation
    if(n>m) return 0;
    
    int sum = 0;
    int v[n];// 0..n
    for(int j = 0; j < n; j++){
        v[j] = j;
        sum += r[j];
    }



    //using permutation 
    do {
        // cout << "permutation ";
        // for(int j = 0; j < n; j++){
        //     cout << v[j] << " ";
        // }
        // cout << endl;
        ll diff = m-1-(2*sum -r[v[0]]-r[v[n-1]]);
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
          //  cout << "diff: "<< diff << " j:" << j << " result:" << result << endl;
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

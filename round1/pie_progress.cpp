#include <iostream>
#include <algorithm>
#include <math.h>
#define ll long long

using namespace std;

ll c[300][300];

ll buy(ll arr[300], int l)
{
    ll result = 0;
    for (int j = 0; j < l; j++)
    {
        result += arr[j];
    }
    result += l * l;
    return result;
}

ll solve(int n, int m, int processRow, int required_pie)
{
//    cout << "Try to " <<  processRow << "-"  <<  required_pie << ":"<< endl;
    if (required_pie==0) return 0;
    if (processRow == n -1){
        // last row
        return buy(c[processRow], required_pie);
    }
    
    // assume first day take at least j
    ll total = INT_MAX;
    for (int j = 0; j <= min(required_pie,m); j++) // buy j pie
    {
        if (j==0  && processRow + required_pie >= n) {continue;}
        ll rel = buy(c[processRow], j) + solve(n, m, processRow + 1,  required_pie-j);
    
            // cout << "processRow "<<processRow<<  " rel: "<< j << " "<< rel << " buy "<< buy(c[processRow], j)<< endl;
        
        if (total > rel)
        {
            total = rel;
        }
    }
    // cout <<  processRow <<  "-" <<  required_pie << ":"<< total<< endl;
    return total;
}

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int n, m;
        cin >> n >> m;
        memset(c, 0, sizeof(c));
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                cin >> c[j][k];
            }
            sort(c[j], c[j] + m);
        }
        cout << "Case #" << i + 1 << ": " << solve(n, m, 0, n) << endl;
    }
    return 0;
}

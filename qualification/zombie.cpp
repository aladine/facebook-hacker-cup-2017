#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int memo[21][21][20000];

int ways(int sum, int x, int y)
{
    // x number,each has value of 1 to y, how many ways to get sum
    if (sum < x || sum > x * y)
        return 0;

    if (memo[x][y][sum] > 0 ) return memo[x][y][sum];

    if (x == 1)
    {
        return 1;
    }

    int total = 0;
    for (int l = 1; l <= y; l++)
    {
        if (sum - l +1 >= x){
            total += ways(sum - l, x - 1, y);
        }
    }
    cout << "ways="<<total <<  " sum="<< sum <<" x=" << x << " y="<< y << endl;
    memo[x][y][sum] = total;
    return total;
}

float calc(string s, int h)
{
    int x, y, z = 0;
    int health = h;
    string delimiter = "d";
    int pos = s.find(delimiter);
    string x_str = s.substr(0, pos);
    x = stoi(x_str);

    string s_new = s.substr(pos+1);
    
    string delim_pos = "+", delim_neg = "-";
    int pos2 = s_new.find(delim_pos);
    int pos3 = s_new.find(delim_neg);
    if (pos2 != -1)
    { //+
        string y_str = s_new.substr(0, pos2);
        y = stoi(y_str);
        string z_str = s_new.substr(pos2 + 1);
        z = stoi(z_str);
        health -= z;
    }
    else if (pos3 != -1)
    { //-
        string y_str = s_new.substr(0, pos3);
        y = stoi(y_str);
        string z_str = s_new.substr(pos3 + 1);
        z = stoi(z_str);
        health += z;
    }
    else
    {
        y = stoi(s_new);
    }
    int total_ways = 0;
    for (int j = health; j <= x * y; j++)
    {
        total_ways += ways(j, x, y);
    }
    // cout << "total_ways: "<< total_ways << "-"<< pow(float(y), x) << "-s=" << s<< endl;
    return float(total_ways) / float(pow(float(y), x));
}

int main()
{
    for(int i = 1;i< 21; ++i)
    for(int j = 1;j< 21; ++j)
    for(int k = 1;k< 20000; ++k)
    {
        if (k == i || k == i * j){

            memo[i][j][k] = 1;
        }
        else memo[i][j][k] = 0;
    }
    
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        // if(i!=2) continue;
        int H, S;
        scanf("%d", &H);
        scanf("%d", &S);
        float max_value = 0;
        for (int j = 0; j < S; j++)
        {
            string m;
            cin >> m;

            float result = calc(m, H);
            if (max_value < result)
                max_value = result;
        }
        printf("Case #%d: %0.5f\n", i+1, max_value);
        
    }
    return 0;
}
#include <iostream>
#include <math.h>

using namespace std;

#define PI 3.14159265

const int c = 50;
const int R = 50;

bool isWhite(int p, int x, int y){
    if( (x-c)*(x-c) + (y-c)*(y-c) >R*R) return true;
    float val = 90-p*3.6;
    float m = atan((x-50)/(y-50))* 180 / PI;
   // cout << m << "-" << val << endl;
    return !(m<=90 && m >= val);
} 

int main(){
    int T;
    scanf("%d", &T);
    for (int i=0; i< T;i++){
        int p, x, y;
        scanf("%d", &p);
        scanf("%d", &x);
        scanf("%d", &y);
        cout << "Case #" << i+1<< ": "<< (isWhite(p, x, y) ? "white" : "black") << endl;
    }
    return 0    ;
}



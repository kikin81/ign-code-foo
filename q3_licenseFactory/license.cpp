#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector< vector<double> > r(10000, vector<double>(10000));
vector< vector<double> > plate (20, vector<double>(20, INT_MAX));



int calculate(int n, int m) {
    if (r[n][m] > 0) {
        return r[n][m];
    }
    else{
        double x = 0;
        x = pow(10,n)*pow(26,m);
        r[n][m] = x;
        return x;
    }
}

/**
*
*
**/
int memoizedPlate(int pop){

    int tempM = 1000;
    int tempN = 1000;
    
    int m =0;
    int n = 0;
    for(m = 0; m < 10; m++){
        printf("m: %d", m);
        for(n=0; n < 10; n++){
            double ans = calculate(n, m);
            printf(" n: %d value: %g\n", n, ans);
            if(ans >= pop){
                printf("ans: %g", ans);
                tempM = m;
                tempN = n;
                plate[n][m] = (ans);
            }
        }
    }
    printf("How many times it iterated: m: %d and n %d\n", m,n);

    // return smallest
    int i, j, letters, numbers, leftover;
    int min = plate[0][0];

    for (i = 0; i < plate.size(); i++) {
        for (j = 0; j < plate.size(); j++) {
            if (plate[i][j] < min) {
                min = plate[i][j];
                numbers = i;
                letters = j;
            }
        }
    }

    leftover = min - pop;

    printf("Population:\t %d\nPattern:\t %d Letters %d Numbers\nTotal Plates:\t %d\nLeftover:\t %d\n",
            pop,
            letters,
            numbers,
            min,
            leftover);

}



/**
* Main function that asks for an input Population
*
**/
int main(){

    int x;
    printf("Input a number:\n>>");
    cin >> x;
    memoizedPlate(x);

    return 0;
}


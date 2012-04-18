#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void printResults(int pop, int letters, int numbers, int plates, int leftover) {
    printf("Population:\t%d", pop);
    printf("\nPattern:\t");
    if(letters > 0){
        if(letters == 1){
            printf("%d Letter ", letters);
        }
        else {
            printf("%d Letters ", letters);
        }
    }
    if(numbers > 0){
        if(numbers == 1){
            printf("%d Number", numbers);
        }
        else {
            printf("%d Numbers", numbers);
        }
    }
    printf("\nTotal Plates:\t%d", plates);
    printf("\nLeftover:\t%d\n", leftover);

}

/**
*
*
**/
int memoizedPlate(int pop){

    int tempM, tempN, leftover;
    int min = INT_MAX;
    double ans;
    
    for(int m = 0; m < 10; m++){
        for(int n=0; n < 10; n++){
            ans = pow(10,n)*pow(26,m);
            if(ans >= pop && ans < min){
                min = ans;
                tempM = m;
                tempN = n;
                leftover = min - pop;
            }
        }
    }

    printResults(pop, tempM, tempN, min, leftover);
}



/**
* Main function that asks for an input Population
**/
int main(){

    int x;
    printf("Input a number:\n>>");
    cin >> x;
    memoizedPlate(x);

    return 0;
}


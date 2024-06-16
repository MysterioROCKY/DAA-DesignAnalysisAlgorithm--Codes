//implement a recursive fun to implement 2^n
#include<stdio.h>
#include <time.h>

long double rec_2power(int n){
    if(n==0){
        return 1;
    }
    return 2*rec_2power(n-1);

}
int main(){
    clock_t start, end;
    start = clock();

    int n;
    printf("Enter the value of n = ");
    scanf("%d", &n);

    long double x = rec_2power(n);
    printf("%Lf\n", x);

    end = clock();
    double duration = ((double)end - start) / CLOCKS_PER_SEC;

    printf("Time taken to execute in seconds : %f", duration);

}
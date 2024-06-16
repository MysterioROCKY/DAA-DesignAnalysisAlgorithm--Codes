
#include<stdio.h>
#include <time.h>

long double rec_2power(int n){
    if(n==0){
        return 1;
    }
    return 2*rec_2power(n-1);

}
long double x;
double duration;
int main(){
    long double x;
    double duration;
    clock_t start, end;
    start = clock();

    int n;
    for(int i = 0; i <= 1000; i++){
    n = i;
    x = rec_2power(n);
    end = clock();
    duration = ((double)end - start) / CLOCKS_PER_SEC;

    printf("%f\n", duration);
} 
    return 0;

}
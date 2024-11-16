#include <stdio.h>
#include <math.h>
// Tinh S(n) = 1^2+2^2...(n-1)^2+n^2
int S(int n){
    if(n==1) return 1;
    else return pow(n,2) + S(n-1);
}
int main(){
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    printf("S(%d) = %d", n, S(n));
}
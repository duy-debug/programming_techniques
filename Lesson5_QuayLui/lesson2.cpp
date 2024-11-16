#include <stdio.h>
int Sum(int n){
    if(n==1) return 1;
    else return Sum(n-1)+n;
}
float S(int n){
    if(n==1) return 1;
    else return S(n-1)+(float)1/Sum(n);
}
int main(){
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    printf("S(%d) = %.2f", n, S(n));
}
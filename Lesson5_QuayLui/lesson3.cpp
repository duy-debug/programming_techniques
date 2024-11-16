#include <stdio.h>
int Count(int a[], int n, int x){
    if(n==0) return 0;
    else if(a[n-1]==x) return Count(a,n-1,x)+1;
    else return Count(a,n-1,x);
}
int main(){
    int n, x;
    int a[n];
    printf("Nhap n: "); scanf("%d", &n);
    printf("Nhap x: "); scanf("%d", &x);
    for(int i=0; i<n; i++){
        printf("Nhap a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    printf("So lan phan tu x xuat hien: %d", Count(a,n,x));
}
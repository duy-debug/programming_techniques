// Cho day so nguyen gom n phan tu. Hay tim tat ca cac tap con cua n phan tu sao cho tong tap con bang 15
#include <stdio.h>
int b[100];
int a[]={5,7,0,1,3,2,8,9};
int n=sizeof(a)/sizeof(a[0]);
void Print(){
    int sum=0;
    for(int i=0; i<n; i++){
        if(b[i]==1){
            sum+=a[i];
        }
    }
    if(sum==15){
        for(int i=0; i<n; i++){
        if(b[i]==1){
                sum+=a[i];
                printf("%d\t", a[i]);
            }
        }
        printf("\n");
    }
}
void Try(int i){
    for(int j=0; j<=1; j++){
        b[i]=j;
        if(i<n-1) 
        Try(i+1);
        else
        Print();
    }
}
int main(){
    int i=0;
    Try(i);
}

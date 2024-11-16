#include <stdio.h>
#define N 10
int a[N]; // luu ket qua
int n;
// in nghiem
void Print(){
    for(int i=1; i<=n; i++)
        printf("%d\t", a[i]);
    printf("\n");
}
// quay lui = vet can
void Try(int i){
    for(int j=0; j<n; j++){
        a[i]=j; // ghi nhan tap nghiem 
        if(i==n)
            Print(); // in nghiem ra man hinh
        else 
            Try(i+1);
    }
}
int main(){
    printf("Nhap do dai chuoi nhi phan: ");
    scanf("%d", &n);
    int i=1;
    Try(i);
}
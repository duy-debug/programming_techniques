#include <stdio.h>
#include <stdlib.h>
void Input(int a[], int &n){
	for(int i=0; i<n; i++){
		printf("Nhap phan tu thu %d: ", i);
		scanf("%d", &a[i]);
	}
}
void Print(int a[], int n){
	for(int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
}
// dem so luong so nguyen am nam o vi tri le
int dem(int a[], int n){
	if(n==0) return 0;
	if((n-1)%2==1 && a[n-1]<0)
		return 1+dem(a,n-1);
	return dem(a,n-1);
}
// dem va xuat ra so phan tu la boi cua x trong mang,
// voi x la tham so truyen vao
int kq[100];
int cnt=0;
int Boi_x(int a[], int n, int x){
	if(n==0) return 0;
	if(a[n-1]%x==0){
		kq[cnt++]=a[n-1];
		return Boi_x(a,n-1,x);
	}
	return Boi_x(a,n-1,x);
}
void Out(){
	for(int i=0; i<cnt; i++){
		printf("%d ", kq[i]);
	}
}
// kiem tra xem tat ca cac phan tu trong magn co phai toan
// la so le hay khong
int KT_sole(int a[], int n){
	if(n==0) return 1;
	if(a[n-1]%2==0)
		return 0;
	return KT_sole(a,n-1);
	
}
// kiem tra va xuat ket qua mang co dang theo thu tu
// giam dan hay khong
int KT_mang(int a[], int n){
	if(n<=1) return 1;
	if(a[n-1]>a[n-2])
		return 0;
	return KT_mang(a,n-1);
}
int main(){
	int a[100];
	int n;
	do{
		printf("Nhap n: ");
		scanf("%d", &n);
	}while(n<=2 || n>=100);
	Input(a,n);
	Print(a,n);
	printf("\nSo luong so nguyen am o vi tri le: %d", dem(a,n));
	int x;
	printf("\nNhap x: ");
	scanf("%d", &x);
	Boi_x(a,n,x);
	Out();
	if(KT_sole(a,n))
		printf("\nMang toan so le");
	else printf("\nMang khong phai toan so le");
	if(KT_mang(a,n)==1)
		printf("\nMang giam dan");
	else printf("\nMang khong giam dan");
}

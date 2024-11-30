#include <stdio.h>
// Trong cua hang co N goi hang, goi hang thu i co trong luong la Wi va gia tri la Vi. Mot ten trom dot nhap vao cua hang, ten trom mang theo mot cai tui co the mang duoc toi da trong luong la M. Hoi ten trom se lay di nhung goi hang nao de duoc tong gia tri la lon nhat. (dung ky thuat tham lam)
int n;
int a[100];
int b[100];
int m;
int kq[100];
void greedy(){
	int sum=0; // tong trong luong
	int res=0; // tong gia tri
	int cnt=0;
	int i=0;
	while(i<n){
		if(sum+a[i]<=m){
			sum+=a[i];
			res+=b[i];
			kq[cnt++]=i;
		}
		i++;
	}
	for(int i=0; i<cnt; i++){
		printf("Lay goi hang co trong luong %d va gia tri %d: \n", a[kq[i]], b[kq[i]]);
	}
	printf("Tong trong luong: %d\n", sum);
	printf("Tong gia tri: %d", res);
}
void swap(int *x, int *y){
	int tem=*x;
	*x=*y;
	*y=tem;
}
void sort(){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(b[i]<b[j]){
				swap(&a[i],&a[j]);
				swap(&b[i],&b[j]);
			}
		}
	}
}
int main(){
	printf("Nhap n goi hang: ");
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		printf("Nhap trong luong goi hang thu %d: ", i);
		scanf("%d", &a[i]);
	}
	for(int i=0; i<n; i++){
		printf("Nhap gia tri goi hang thu %d: ", i);
		scanf("%d", &b[i]);	
	}
	printf("Nhap trong luong toi da cai tui: ");
	scanf("%d", &m);
	sort();
	greedy();
}

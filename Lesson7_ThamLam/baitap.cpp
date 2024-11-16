#include <stdio.h>
void nhap(int a[], int &n){
	for(int i=0; i<n ;i++){
		printf("Gia tien mon qua thu %d: ", i+1);
		scanf("%d", &a[i]);
	}
}
void SORT(int a[], int n){
	int tem;
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			if(a[j]>a[j+1]){
				tem=a[j];
				a[j]=a[j+1];
				a[j+1]=tem;
			}
		}
	}
}
void bt_muaqua(int a[], int n, int s){
	int i=0;
	int cnt=0;
	while(s>=a[i] && i<n){
		if(s>=a[i]) {
			s-=a[i];
			cnt++;		
		}
		i++;	
	}
	printf("So mon qua toi da mua duoc: %d",cnt);
}
int main(){
	int a[100], n;
	int s;
	printf("So tien mua qua: ");
	scanf("%d", &s);
	printf("Nhap so mon qua: ");
	scanf("%d", &n);
	nhap(a,n);
	SORT(a,n);
	bt_muaqua(a,n,s);
	return 0;
}

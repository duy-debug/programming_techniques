#include <stdio.h>
void nhap(int a[], int &n){
	for(int i=0; i<n; i++){
		printf("Gia tri to tien %d: ", i+1);
		scanf("%d", &a[i]);
	}
}
void SORT(int a[], int n){
	int tem;
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			if(a[j]<a[j+1]){
				tem=a[j];
				a[j]=a[j+1];
				a[j+1]=tem;
			}
		}
	}
}
void bt_ATM(int a[], int n, int s){
	int i=0, cnt=0;
	int x[1000]={0};
	while(s>0 && i<n){
		if(s>=a[i]){
			s-=a[i];
			x[cnt++]=a[i];
		}
		else{
			i++;
		}
	}
	if(s==0){
		for(int i=0; i<cnt; i++){
		printf("%d ", x[i]);
		}
	}
	else{
		printf("Khong the rut duoc");
	}
}
int main(){
	int n, a[100], s;
	printf("So tien can rut: ");
	scanf("%d", &s);
	printf("Nhap so to tien: ");
	scanf("%d", &n);
	nhap(a,n);
	SORT(a,n);
	bt_ATM(a,n,s);
}

#include <stdio.h>
int n;
int a[100];
int Input(int a[], int &n){	// cau a: Nhap n day so nguyen (3<n<50)
	do{
		printf("Nhap n (3<n<50): ");
		scanf("%d", &n);
	}while(n <= 3 || n >= 50);
	for(int i=0; i<n; i++){
		printf("Nhap a[%d]: ", i);
		scanf("%d", &a[i]);
	}
}
int Count(int a[], int n){ //cau b: Dem so lan xuat hien cua gia tri x trong day so cho den khi gap linh canh
	int x;
	int linhcanh=-9999999;
	a[n]=linhcanh;
	printf("Nhap gia tri x: "); 
	scanf("%d", &x);
	int cnt=0, i=0;
	while(a[i]!=linhcanh){
		if(a[i]==x){
			cnt++; 
		}
		i++;
	}
	return cnt;	
}
int Testing(int a[], int n){ // cau c: Su dung ky thuat co hieu de kiem tra day so co giam dan hay khong
	bool flag=1;
	for(int i=0; i<n-1; i++){
		if(a[i]<a[i+1]){
			flag=0;
			break;
		}
	}
	return flag;
}
int main(){
	Input(a,n);
	printf("So luong phan tu x trong day so: %d\n", Count(a,n));
	if(Testing(a,n))
	printf("Day so co giam dan!\n");
	else printf("Day so khong giam dan!\n");
}

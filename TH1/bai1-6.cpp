#include <stdio.h>
void Nhap(int a[][10], int &n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("Nhap a[%d][%d]: ", i, j);
			scanf("%d",&a[i][j]);
		}
	}
}
void DiemYenNgua(int a[][10], int n){
	for(int i=0; i<n; i++){
		int max=a[i][0];
		int index=0;
		for(int j=1; j<n ;j++){
			if(a[i][j]>max){
				max=a[i][j];
				index=j;
			}
		}
		int tem=1; // gia su la diem yen ngua
	for(int k=0; k<n; k++){
		if(a[k][index]<max){
			tem=0; // khong phai la diem yen ngua
			break;
		}
	}
		if(tem==1){
			printf("Diem yen ngua: %d\n", max);
		}
	}
}
int main(){
	int n;
	int a[10][10];
	do{
		printf("Nhap ma tran n: ");
		scanf("%d", &n);
	}while(n<=2 || n>=10);
	Nhap(a,n);
	DiemYenNgua(a,n);
}

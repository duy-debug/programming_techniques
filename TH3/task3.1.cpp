#include <stdio.h>
#include <stdlib.h>
#define M 30
// Doc noi dung trong file "Lap3_1.inp"
void ReadFile(char *s, int a[], int &n){
	FILE*f=fopen(s,"r");
	if(f==NULL){
		printf("Khong the mo file!");
	}
	else{
		fscanf(f,"%d",&n);
		for(int i=0; i<n; i++){
			fscanf(f,"%d",&a[i]);
		}		
		fclose(f);
	}
}
// Xuat mang a ra man hinh
void fPrint(int a[], int n){
	for(int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
}
// Tim va xuat ra man hinh so lon nhat trong mang
// dung vong lap
int find_Max(int a[], int n){
	int max=a[0];
	for(int i=1; i<n; i++){
		if(a[i]>max) max=a[i];
	}
	return max;
}
// dung de quy
int find1_Max(int a[], int n){
	if(n==1) return a[0];
	if(a[n-1]>find1_Max(a,n-1))
		return a[n-1];
	else find1_Max(a,n-1);
}
// Tinh tong cac phan tu cua mang a
// de quy dau
int Sum(int a[], int n){
	if(n==0) return 0;
	else return Sum(a,n-1)+a[n-1];
}
// de quy duoi
int Sum1(int a[], int n, int sum){
	if(n==0) return sum;
	else return Sum1(a,n-1,sum+a[n-1]);
}

int main(){
	char *s="Lab3_1.inp";
	int a[M], n;
	ReadFile(s,a,n);
	fPrint(a,n);
	printf("\n");
	printf("Gia tri lon nhat (vong lap): %d\n", find_Max(a,n));
	printf("Gia tri lon nhat (de quy): %d\n", find1_Max(a,n));
	printf("Tong gia tri cua mang (de quy dau): %d\n", Sum(a,n));
	printf("Tong gia tri cua mang (de quy cuoi): %d\n", Sum1(a,n,0));	
}

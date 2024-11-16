#include <stdio.h>
#include <stdlib.h>
#define max 30
// Doc du lieu tu file "DaySo.inp" luu vao mang a
void ReadFile(char *s, int a[max], int &n){
	FILE *file=fopen(s, "r");
	if(file==NULL){
		printf("Khong the mo file\n");
	}
	else{
		fscanf(file,"%d",&n);
	for(int i=0; i<n; i++){
		fscanf(file,"%d",&a[i]);
		}
		fclose(file);
	}
}
// Ham xuat ma tran ra man hinh
void PrintArr(int a[max], int n){
	for(int i=0; i<n; i++){
		printf("%d\n", a[i]);
	}
}
// Ham dem so luong phan tu co gia tri x bang vong lap
int Count(int a[max], int n, int x){
	int cnt=0;
	for(int i=0; i<n; i++){
		if(a[i]==x) cnt++;
	}
	return cnt;
}
// Ham dem so luong phan tu co gia tri x bang de quy
int CountRecur(int a[max], int n, int x){
	if(n==0) return 0;
	else if(a[n-1]==x) return Count(a,n-1,x)+1;
	else return Count(a,n-1,x);
}
int main(){
	char *s="DaySo.inp";
	int n, a[max];
	ReadFile(s,a,n);
	PrintArr(a,n);
	int x;
	printf("Nhap gia tri x can dem: ");
	scanf("%d", &x);
	printf("So luong gia tri %d xuat hien trong mang (khong de quy) la: %d\n", x,Count(a,n,x));
	printf("So luong gia tri %d xuat hien trong mang (dung de quy) la: %d", x,CountRecur(a,n,x));
	
}

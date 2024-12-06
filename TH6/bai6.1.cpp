#include <stdio.h>
#include <stdlib.h>
void readfile(char *s, int a[], int &n){
	FILE *f=fopen(s,"r");
	if(f==NULL){
		printf("Khong the mo file");
	}
	else{
		fscanf(f,"%d",&n);
		for(int i=0; i<n; i++){
			fscanf(f,"%d",&a[i]);
		}
		fclose(f);
	}
}
void Print(int a[], int n){
	printf("%d\n",n);
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
// kiem tra ham co phai toan la so le hay khong
int KT_sole(int a[], int l, int r){
	if(l==r) return l;
	int mid=(l+r)/2;
	int check_left=KT_sole(a,l,mid);
	int check_right=KT_sole(a,mid+1,r);
	if(a[check_left]%2==0 || a[check_right]%2==0)
		return 0;
}
int main(){
	int a[100], n;
	char *s="input6.1.txt";
	readfile(s,a,n);
	Print(a,n);
	printf("\nSo luong so nguyen am nam o vi tri le: %d", dem(a,n));
	if(KT_sole(a,0,n-1)!=0)
		printf("\nMang toan so le");
	else printf("\nMang khong toan le");
}

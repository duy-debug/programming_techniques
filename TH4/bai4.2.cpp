#include <stdio.h>
// tim va xuat ra phan tu lon nhat trong mang
int Tim_max(int a[], int l, int r){
	if(l==r) return a[l];
	int mid=(l+r)/2;
	int left_max=Tim_max(a,l,mid);
	int right_max=Tim_max(a,mid+1,r);
	return left_max>right_max?left_max:right_max;
}
// dem va xuat ra so luan xuat hien cua phan tu co gia tri x trong mang
int Demx(int a[], int l, int r, int x){
	if(l>r) return 0;
	int mid=(l+r)/2;
	if(a[mid]==x) return Demx(a,l,mid-1,x)+Demx(a,mid+1,r,x)+1;
	else{
		if(x<a[mid]) return Demx(a,l,mid-1,x);
		else return Demx(a,mid+1,r,x);
	}
}
// tim va xuat ra phan tu co so lan nhieu nhat trong mang
int cnt(int a[], int l, int r, int k){
	int tes=0;
	for(int i=l; i<=r; i++){
		if(a[i]==k)
			tes++;
	}
	return tes;
}
int PhanTu_NhieuNhat(int a[], int l, int r){
	if(l==r) return a[l];
	int mid=(l+r)/2;
	int left=PhanTu_NhieuNhat(a,l,mid);
	int right=PhanTu_NhieuNhat(a,mid+1,r);
	int left_count=cnt(a,l,r,left);
	int right_count=cnt(a,l,r,right);
	return (left_count>right_count)?left:right;
}
int main(){
	int n;
	printf("Nhap n: ");
	scanf("%d", &n);
	int a[n];
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);
	printf("Phan tu lon nhat: %d\n", Tim_max(a,0,n-1));
	int x;
	printf("Nhap x: ");
	scanf("%d", &x);
	printf("So luong phan tu x: %d\n", Demx(a,0,n-1,x));
	printf("Phan tu xuat hien nhieu nhat: %d", PhanTu_NhieuNhat(a,0,n-1));
}

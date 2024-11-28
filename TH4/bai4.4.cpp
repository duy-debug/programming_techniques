#include <stdio.h>
// kiem tra mang co dang tang dan khong
int KT_mang(int a[], int l, int r){
	if(l==r) return a[r];
	int mid=(l+r)/2;
	int left_check=KT_mang(a,l,mid);
	int right_check=KT_mang(a,mid+1,r);
	if(left_check && right_check && a[mid] <= a[mid+1])
		return 1;
	return 0;
}
// tim va xuat ra vi tri phan tu nho nhat trong mang
int timvitri_nhonhat(int a[], int l, int r){
	if(l==r) return 	l;
	int mid=(l+r)/2;
	int check_left=timvitri_nhonhat(a,l,mid);
	int check_right=timvitri_nhonhat(a,mid+1,r);
	return a[check_left]<a[check_right]?check_left:check_right;
}	
// dem va xuat ra so phan tu la boi cua x trong mang, voi x la tham so truyen vao
int Demboi_x(int a[], int l, int r, int x){
	if(l==r) return (a[l]%x==0)?1:0;
	int mid=(l+r)/2;
	int	count_left=Demboi_x(a,l,mid,x);
	int count_right=Demboi_x(a,mid+1,r,x);
	return count_left+count_right;	
}
int main(){
	int n;
	printf("Nhap n: ");
	scanf("%d", &n);
	int a[n];
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	if(KT_mang(a,0,n-1))
		printf("Mang tang dan!\n");
	else printf("khong tang dan!\n");
	printf("Vi tri phan tu nho nhat: %d\n", timvitri_nhonhat(a,0,n-1));
	int x;
	printf("Nhap x: ");
	scanf("%d", &x);
	printf("So phan tu la boi cua la: %d", Demboi_x(a,0,n-1,x));
}

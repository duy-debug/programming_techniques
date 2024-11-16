	#include <stdio.h>
	int Min(int a[],int l, int r){
		if(l==r) return a[l];
		int mid=(l+r)/2;
		int left=Min(a,l,mid);
		int right=Min(a,mid+1,r);
		return left<right?left:right;
	}
	int main(){
		int a[100], n;
		printf("Nhap n: ");
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%d", &a[i]);
		}
		printf("Phan tu nho nhat: %d", Min(a,0,n-1));
	}

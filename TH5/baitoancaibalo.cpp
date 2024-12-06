#include <stdio.h>
void sort(int a[], float p[], int n){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(p[i]<p[j]){
				int tem=a[i];
				a[i]=a[j];
				a[j]=tem;
				float tes=p[i];
				p[i]=p[j];
				p[j]=tes;
			}
		}
	}
}
void greedy(int a[], float p[], int n, int m){
	int i=0;
	float sum=0;
	int tongtl=0;
	while(i<n && m>0){
		if(a[i]<=m){
			m-=a[i];
			tongtl+=a[i];
			sum+=p[i]*a[i];
		}
		i++;
	}
	printf("Tong trong luong: %d\n", tongtl);
	printf("Tong gia tri: %.2f", sum);
}
int main(){
	int n, m;
	printf("Nhap n: ");
	scanf("%d", &n);
	printf("Nhap trong luong cai tui: ");
	scanf("%d", &m);
	int a[n];
	int b[n];
	printf("Nhap trong luong cac do vat: ");
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	printf("Nhap gia tri cac do vat: ");
	for(int i=0; i<n; i++){
		scanf("%d", &b[i]);
	}
	float p[n];
	for(int i=0; i<n; i++){
		p[i]=(float)b[i]/a[i];
	}
	sort(a,p,n);
	greedy(a,p,n,m);
}

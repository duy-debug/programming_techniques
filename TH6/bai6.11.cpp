#include <stdio.h>
#define MAX 100
int a[]={12,1,4,7,5,8,7,9,16};
int n;
int L[MAX];
int t[MAX];
int lmax;
void init(){
	n=sizeof(a)/sizeof(a[0]);
	L[0]=0;
	for(int i=0; i<n; i++){
		t[i]=-1;
	}
}
void Dynamic(){
	for(int i=0; i<n; i++){
		lmax=0;
		for(int j=0; j<i; j++){
			if(a[j]<a[i] && lmax<L[j]){
				lmax=L[j];
				t[i]=j;
			}
		}
		L[i]=lmax+1;
	}
}
void Track(){
	int max=L[0], p=-1;
	for(int i=1; i<n; i++){
		if(max<L[i]){
			max=L[i];
			p=i;
		}
	}
	printf("\nDo dai day tang dai nhat la %d", max);
	printf("\nVi tri cac phan tu: ");
	while(p>=0){
		printf("%d ", p);
		p=t[p];
	}
} 
int main(){
	init();
	Dynamic();
	Track();
}

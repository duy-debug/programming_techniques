#include <stdio.h>
#include <stdlib.h>
#define MAX 50
int a[MAX], n;
int L[MAX], t[MAX], lmax;
void init(){
	printf("Nhap so luong phan tu: ");
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);
	for(int i=0; i<n; i++){
		L[i]=0;
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
	for(int i=0; i<n; i++){
		if(max<L[i]){
			max=L[i];
			p=i;
		}
	}
	printf("\nDo dai day tang dai nhat: %d", max);
	printf("\nDay con tang: ");
	int result[max], index=max-1;
	while(p>=0){
		result[index--]=a[p];
		p=t[p];
	}
	for(int i=0; i<max; i++)
		printf("%d ", result[i]);
}
int main(){
	init();
	Dynamic();
	Track();
}

#include <stdio.h>
#include <stdlib.h>
int a[100], b[100], n;
void Print(){
	int tonga=0;
	int tongb=0;
	for(int i=0; i<n; i++){
		if(a[i]==0)
			tonga+=b[i];
		else
			tongb+=b[i];
	}
	if(tonga==tongb){
		for(int i=0; i<n; i++){
			if(a[i]==0)
				printf("%d ",b[i]); 
		}
		printf("\n");
		for(int i=0; i<n; i++){
			if(a[i]==1)
				printf("%d ",b[i]); 
		}
		printf("\n");
	}
}
void thu(int i){
	for(int j=0; j<=1; j++){
		a[i]=j;
		if(i<n-1)
			thu(i+1);
		else
			Print();
	}
}
int main(){
	printf("Nhap n: ");
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &b[i]);
	}
	thu(0);
}

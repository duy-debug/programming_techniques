#include <stdio.h>
#include <stdlib.h>
int x[100], a[100], n;
bool tes=false;
void Print(FILE*f,int k){
	tes=true;
	for(int i=1; i<=k; i++){
		if(i!=k)
			fprintf(f,"%d + ", x[i]);
		else
			fprintf(f,"%d ",x[i]);
	}
	fprintf(f,"\n");
}
void phanTichSo(FILE*f,int i){
	for(int j=x[i-1]; j<=n-a[i-1]; j++){
		x[i]=j;
		a[i]=a[i-1]+j;
		if(a[i]==n)
			Print(f,i);
		else
			phanTichSo(f,i+1);
	}
}
int main(){
	FILE *f=fopen("Lab4_3.out", "w");
	do{
		printf("Nhap n: ");	
		scanf("%d", &n);
	}while(n<=0 || n>=20);
	x[0]=1, a[0]=0;
	phanTichSo(f,1);
		if(tes!=true)
			fprintf(f,"-1\n");
	fclose(f);
	return 0;
}

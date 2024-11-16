#include <stdio.h>
#include <stdlib.h>
#define max 20
#include <stdlib.h>
int b[1000];
bool tes=false;
void readfile(char *s, int a[], int &n, int &m){
	FILE *f=fopen(s,"r");
	if(f==NULL){
		printf("Khong the mo file");
	}
	else{
		fscanf(f,"%d",&n);
		fscanf(f,"%d",&m);
		for(int i=0; i<n; i++){
			fscanf(f,"%d",&a[i]);
		}
		fclose(f);
	}
}
void xuat(int a[], int n, int m){
	tes=true;
	printf("Gia tri to tien: %d\n",m);
	for(int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}
void Print(FILE*f,int a[], int n, int m){
    int sum=0;
    for(int i=0; i<n; i++){
    	sum+=b[i]*a[i];
    }
    if(sum==m){
    	for(int i=0; i<n; i++){
    		if(b[i]==1)
    			fprintf(f,"To thu %d menh gia %d\n",i,a[i]);
		}
		fprintf(f,"\n");
	}
}
void try1(FILE *f,int i, int a[], int n, int m){
	for(int j=0; j<=1; j++){
		b[i]=j;
		if(i==n-1)
			Print(f,a,n,m);
		else
			try1(f,i+1,a,n,m);
	}
}
int main(){
	FILE *f=fopen("ATM_out.out", "w");
	int a[max], n, m;
	char *s="ATM.inp";
	readfile(s,a,n,m);
	xuat(a,n,m);
	try1(f,0,a,n,m);
	if(tes!=true)
		fprintf(f,"-1");
	fclose(f);
	return 0;
}

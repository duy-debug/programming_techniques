#include <stdio.h>
#include <stdlib.h>
int a[100],n, m;
int b[100], cnt=0;
void readfile(char *s){
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
void Print(FILE*f){
	int sum=0;
	for(int i=0; i<n; i++){
		if(b[i]==0)
			sum+=a[i];
		else
			sum-=a[i];
	}
	if(sum==m){
		cnt++;
		fprintf(f,"%d",a[0]);
		for(int i=1; i<n; i++){
			if(b[i]==0)
				fprintf(f," + %d", a[i]);
			else 
				fprintf(f," - %d",a[i]);
		}
		fprintf(f,"\n");
	}
}
void try1(int i,FILE*f){
	for(int j=0; j<=1; j++){
		b[i]=j;
		if(i<n-1)
			try1(i+1,f);
		else Print(f);	
	}
}
int main(){
	char *s="input6.9.txt";
	FILE *f=fopen("output6.9.txt", "w");
	readfile(s);
	try1(1,f);
	if(cnt==0)
		fprintf(f,"0");
	else fprintf(f,"%d", cnt);
	fclose(f);
}

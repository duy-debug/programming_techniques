#include <stdio.h>
#include <stdlib.h>
int a[100];
int b[100];
int n;
int cnt=0;
void readfile(char *s){
	FILE *f=fopen(s,"r");
	if(f==NULL){
		printf("Khong the mo file");
	}
	else{
		fscanf(f,"%d\n",&n);
		for(int i=0; i<n; i++){
			fscanf(f,"%d",&b[i]);
		}
		fclose(f);
	}
}
void Print(FILE*f){
	int tonga=0;
	int tongb=0;
	for(int i=0; i<n; i++){
		if(a[i]==0)
			tonga+=b[i];
		else
			tongb+=b[i];
	}
	if(tonga==tongb){
		cnt++;
		for(int i=0; i<n; i++){
			if(a[i]==0)
				fprintf(f,"A ");
			else fprintf(f,"B ");
		}
		fprintf(f,"\n");
	}
}
void thu(int i,FILE*f){
	for(int j=0; j<=1; j++){
		a[i]=j;
		if(i<n-1)
			thu(i+1,f);
		else 
			Print(f);
	}
}
int main(){
	char *s="input6.8.txt";
	readfile(s);
	FILE*f=fopen("output6.8.txt", "w");
	if(f==NULL){
		printf("Khong the mo file");
	}
	thu(0,f);
	if(cnt==0)
		fprintf(f,"Khong duoc chon");
	fclose(f);
}

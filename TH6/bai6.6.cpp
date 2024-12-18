#include <stdio.h>
#include <stdlib.h>
int n, m, k;
int a[100];
int cnt=0;
void readfile(char *s){
	FILE *f=fopen(s,"r");
	if(f==NULL){
		printf("Khong the mo file");
	}
	else{
		fscanf(f,"%d", &n);
		fscanf(f,"%d", &m);
		fscanf(f,"%d", &k);
		fclose(f);
	}
}
void Print(FILE*f){
	int trung=0, trat=0;
	for(int i=0; i<n; i++){
		if(a[i]==0){
			trat++;
			if(trat>=m) return;
		}
		else{
			trung++;
			trat=0;
		}
	}
	if(trung>=k){
		cnt++;
		for(int i=0; i<n; i++){
			if(a[i]==1)
				fprintf(f,"x");
			else fprintf(f,"_");
		}
		fprintf(f,"\n");
	}
}
void thu(int i, FILE*f){
	for(int j=0; j<=1; j++){
		a[i]=j;
		if(i<n-1)
			thu(i+1,f);
		else
			Print(f);
	}
}
int main(){
	char *s="input6.6.txt";
	readfile(s);
	FILE *f=fopen("output6.6.txt","w");
	if(f==NULL){
		printf("Khong the mo file");
	}
	thu(0,f);
	if(cnt==0)
		fprintf(f,"-1");
	fclose(f);
}

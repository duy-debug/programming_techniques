#include <stdio.h>
#include <stdlib.h>
int a[100];
int b[100];
int n;
int cnt=0, kq[100][100];
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
		cnt++;
		for(int i=0; i<n; i++){
			if(a[i]==0)
				kq[cnt][i]='A';
			else 
				kq[cnt][i]='B';
		}
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
void writefile(FILE *f){
	fprintf(f,"%d\n",cnt);
	for(int i=1; i<=cnt; i++){
		for(int j=0; j<n; j++){
			fprintf(f,"%c",kq[i][j]);
		}
		fprintf(f,"\n");
	}
}
int main(){
	char *s="input6.8.txt";
	readfile(s);
	FILE*f=fopen("output6.8.txt", "w");
	if(f==NULL){
		printf("Khong the mo file");
	}
	thu(0);
	if(cnt==0)
		fprintf(f,"Khong chia duoc");
	else
		writefile(f);
	fclose(f);
}

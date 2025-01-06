#include <stdio.h>
#include <stdlib.h>
int a[100],n, m;
int b[100], cnt=0;
int kq[100][100];
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
void Print(){
	int sum=0;
	for(int i=0; i<n; i++){
		if(b[i]==0)
			sum+=a[i];
		else
			sum-=a[i];
	}
	if(sum==m){
		cnt++;
		for(int i=0; i<n; i++){
			if(b[i]==0)
				kq[cnt][i]=a[i];
			else 
				kq[cnt][i]=a[i];
		}
	}
}
void try1(int i){
	for(int j=0; j<=1; j++){
		b[i]=j;
		if(i<n-1)
			try1(i+1);
		else Print();	
	}
}
void writefile(FILE*f){
	cnt-=1;
	fprintf(f,"%d\n",cnt);
	for(int i=1; i<=cnt; i++){
		for(int j=0; j<n; j++){
			if(kq[i][j]<0)
				fprintf(f,"+(%d)",kq[i][j]);
			else
				fprintf(f,"+%d",kq[i][j]);
		}
		fprintf(f,"\n");
	}
}
int main(){
	char *s="input6.9.txt";
	FILE *f=fopen("output6.9.txt", "w");
	readfile(s);
	try1(0);
	if(cnt==0)
		fprintf(f,"0");
	else 
		writefile(f);
	fclose(f);
}

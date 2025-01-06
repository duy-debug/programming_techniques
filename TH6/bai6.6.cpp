#include <stdio.h>
#include <stdlib.h>
int n, m, k;
int a[100];
int kq[100][100];
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
void In(){
	int trung=0, trat=0, flag=1;
	for(int i=0; i<n; i++){
		if(a[i]==0){
			trat++;
			if(trat==m || m==0){
				flag=0;
				break;
			}
		}
		else{
			trung++;
			trat=0;
		}
	}
	if(trung>=k && flag==1){
		cnt++;
		for(int i=0; i<n; i++){
			if(a[i]==1)
				kq[cnt][i]='x';
			else 
				kq[cnt][i]='_';
		}
	}
}
void thu(int i){
	for(int j=0; j<=1; j++){
		a[i]=j;
		if(i<n-1)
			thu(i+1);
		else
			In();
	}
}
void writefile(FILE*f){
	fprintf(f,"%d\n", cnt);
	for(int i=1; i<=cnt; i++){
		for(int j=0; j<n; j++)
			fprintf(f,"%c", kq[i][j]);
		fprintf(f,"\n");
	}
}
int main(){
	char *s="input6.6.txt";
	readfile(s);
	FILE *f=fopen("output6.6.txt","w");
	thu(0);
	if(cnt==0)
		fprintf(f,"-1");
	else
		writefile(f);
	fclose(f);
}

#include <stdio.h>
#include <stdlib.h>
int n, m, a[100];
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
void sort(){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(a[i]<a[j]){
			int tem=a[i];
			a[i]=a[j];
			a[j]=tem;
			}
		}
	}
}
int kq[100], cnt=0;
void greedy(FILE*f){
	int i=0;
	while(i<n && m>0){
		if(a[i]<=m){
			m-=a[i];
			kq[cnt++]=a[i];
		}
		i++;
	}
	if(m==0){
		for(int i=0; i<cnt; i++){
			fprintf(f,"%d ", kq[i]);
		}
	}
	else
		fprintf(f,"Khong chon duoc");
}
int main(){
	char *s="input3.txt";
	readfile(s);
	FILE *f=fopen("output3.txt","w");
	if(f==NULL){
		printf("Khong the mo file");
	}
	sort();
	greedy(f);
	fclose(f);
}

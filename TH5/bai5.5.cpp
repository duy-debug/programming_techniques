#include <stdio.h>
#include <stdlib.h>
int a[1000];
int n,p;
int kq[1000];
int cnt=0;
void readfile(char *s){
	FILE *f=fopen(s,"r");
	if(f==NULL){
		printf("Khong the mo file");
	}
	else{
		fscanf(f,"%d",&n);
		fscanf(f,"%d",&p);
		for(int i=0; i<n; i++){
			fscanf(f,"%d",&a[i]);
		}
		fclose(f);
	}
}
void Print(){
	printf("%d %d\n",n,p);
	for(int i=0; i<n; i++){
		printf("%d ", a[i]);
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
void greedy(){
	int i=0;
	while(p>0 && i<n){
		if(a[i]<=p){
			p-=a[i];
			kq[cnt++]=a[i];
		}
		i++;
	}
}
void writefile(){
	FILE *f=fopen("ATM.out.txt", "w");
	if(f==NULL){
		printf("Khong the mo file");
	}
	else{
		if(p==0){
			for(int i=0; i<cnt; i++){
				fprintf(f,"%d ",kq[i]);
			}
			fprintf(f,"\nTong so to la: %d", cnt);
		}
		else{
			fprintf(f,"-1");
		}
		fclose(f);
	}
}
int main(){
	char *s="ATM.txt";
	readfile(s);
	Print();
	sort();
	greedy();
	writefile();
}

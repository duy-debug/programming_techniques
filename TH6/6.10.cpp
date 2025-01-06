#include <stdio.h>
#include <stdlib.h>
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
int kq[100];
void sort(int a[], int n){
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
int cnt=0;
void greedy(int a[], int n, int m){
	int i=0;
	while(i<n && m>0){
		if(a[i]<=m){
			m-=a[i];
			kq[cnt++]=a[i];
		}
		i++;
	}
}
void writefile(int a[], int n, int m, FILE*f){
	if(m!=0)
		fprintf(f,"Khong chon duoc");
	else{
		fprintf(f,"%d\n",cnt);
		for(int i=0; i<cnt; i++){
			fprintf(f,"%d ",kq[i]);
		}
	}
}
int main(){
	int a[100], n, m;
	char *s="input6.10.txt";
	FILE *f=fopen("output6.10.txt", "w");
	readfile(s,a,n,m);
	sort(a,n);
	greedy(a,n,m);
	writefile(a,n,m,f);
	fclose(f);

}

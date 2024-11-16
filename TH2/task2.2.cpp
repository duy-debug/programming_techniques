	#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FOR(i,a,b) for(i=a; i<b; i++)
void WriteFile(char *s){ // cau a: nhap mot day so nguyen gom n phan tu, ghi n so nguyen vua nhap vao file"DaySo.inp"
    FILE *file=fopen(s, "w");
    if(file==NULL){
        printf("Khong thay mo file.\n");
    }
    else{
    	int n, m;
    	printf("Nhap n: ");
    	scanf("%d", &n);
    	fprintf(file,"%d\n",n); // ghi vao file
    	for(int i=0; i<n; i++) {
        printf("Nhap phan tu thu %d: ", i);
        scanf("%d", &m);
		fprintf(file,"%d\t",m);        
    	}
    	fclose(file);
	}
}
void WriteFileMaTrix(){ // cau b: Tao ma tran nxn so nguyen duoc sinh ngau nhien trong [0,1000] (2<=n<=30) va ghi ma tran vao file "MaTran.inp"
	int i, j, n, m;
	char s[]="MaTran.inp";
	FILE *file=fopen(s,"w");
	if(file==NULL){
		printf("Loi.");
	}
	else{
		do{
		printf("Nhap kich thuoc ma tran nxn: ");
		scanf("%d", &n);
		}while(n<2 || n>30);
		fprintf(file,"%d\n",n); // ghi n vao file
	// sinh ngau nhien cac so trong khoang [0,1000]
	FOR(i,0,n){
		FOR(j,0,n){
			m = rand()%1000;
			fprintf(file,"%6d\t",m);
			}	
			fprintf(file,"\n");
		}
		fclose(file);
	}
}
int main(){
	char *s="DaySo.inp";
	WriteFile(s);
	WriteFileMaTrix();
} 

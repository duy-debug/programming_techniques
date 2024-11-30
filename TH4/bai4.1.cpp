#include <stdio.h>
#include <stdlib.h>
int a[100][100], n;
int x[100]; // nghiem dang xet
int kq[100]; //nghiem tot nhat
int chuaxet[100]; // danh dau thanh pho
int best_sum=10000; // chi phi toi uu
int sum=0; // tong chi phi hien tai
void readfile(char *s){
	FILE *f=fopen(s,"r");
	if(f==NULL){
		printf("Khong the mo file");
	}
	else{
		fscanf(f,"%d",&n);
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				fscanf(f,"%d", &a[i][j]);
			}
			fscanf(f,"\n");
		}
		fclose(f);
	}
}
void Print(){
	printf("%d\n", n);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
void khoitao(){
	x[1]=1;
	for(int i=2; i<=n; i++)
		chuaxet[i]=1;
}
void danhgia(){
	if(sum<best_sum){
		best_sum=sum;
		for(int i=1; i<=n; i++){
			kq[i]=x[i];
		}
	}
}
void thu(int i){
	if(sum<best_sum){
		for(int j=2; j<=n; j++){
			if(chuaxet[j]){
				x[i]=j;
				chuaxet[j]=0;
				sum+=a[x[i-1]][j];
				if(i==n) 
					danhgia();
				else
					thu(i+1);
				sum-=a[x[i-1]][j];
				chuaxet[j]=1;
			}
		}
	}
}
void inketqua(){
	printf("TP1 -> ");
	for(int i=2; i<=n; i++){
		printf("TP%d -> ", kq[i]);
	}
	printf("TP1\n");
	printf("Tong chi phi la: %d", best_sum+a[kq[n]][1]);
}
void writefile(){
	FILE *f=fopen("dulich.out.txt","w");
	if(f==NULL){
		printf("Khong the mo file");
	}
	else{
		fputs("TP1 ->",f);
		for(int i=2; i<=n; i++){
			fprintf(f,"TP%d -> ", kq[i]);
		}
		fputs("TP1\n",f);
		fprintf(f,"Tong chi phi la: %d", best_sum+a[kq[n]][1]);
		fclose(f);
	}
}
int main(){
	char *s="dulich.txt";
	readfile(s);
	Print();
	khoitao();
	thu(2);
	inketqua();
	writefile();
}

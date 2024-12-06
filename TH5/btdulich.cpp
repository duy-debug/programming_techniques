#include <stdio.h>
#define MAX 30
int n;
int maxc=10000;
int c[MAX][MAX]; // ma tran chi phi
int x[MAX]; // nghiem dang xet
int chuaxet[MAX]; // nghiem dang xet
int sum=0; // chi phi hanh trinh tot nhat
void readfile(){
	FILE *f=fopen("dulich", "r");
	if(f!=NULL){
		fscanf(f,"%d\n",&n);
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++)
				fscanf(f,"%d",&c[i][j]);
			fscanf(f,"\n");
		}
	}
}
void Init(){
	x[1]=1;
	chuaxet[1]=0;
	for(int i=1; i<n; i++)
		chuaxet[i]=1;
}
void print(){
	printf("TP1 -> ");
	for(int i=1; i<n; i++){
		printf("TP%d-> ",x[i]);
	}
	printf("TP1\n");
	printf("Tong chi phi la: %d", sum);
}
void writefile(){
	FILE*f=fopen("dulich.out.txt","w");
	if(f!=NULL){
		fputs("TP1-> ",f);
		for(int i=1; i<n; i++)
			fprintf(f,"TP%d-> ", x[i]);
			fputs("TP1\n",f);
			fprintf(f,"Tong chi phi la: %d", sum);
	}
}
void greedy(){
	int i, xi, tot;
	i=0;
	while(i<n){
		i++;
		tot=100000; xi=0;
		for(int j=2; j<=n; j++)
			if(chuaxet[j] && c[x[i-1]][j]<tot){
				xi=j;
				tot=c[x[i-1]][j];
			}
		x[i]=xi;
		chuaxet[xi]=0;
		sum+=c[x[i-1]][x[i]];
	}
	sum+=c[x[n]][1];
}
int main(){
	readfile();
	greedy();
	print();
	writefile();
}

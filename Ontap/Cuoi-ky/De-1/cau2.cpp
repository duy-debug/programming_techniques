#include <stdio.h>
int n, m, k, a[100], cnt=0;
void Print(){
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
			if(a[i]==0)
				printf("_");
			else 
				printf("x");
		}
		printf("\n");
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
int main(){
	printf("Nhap n: ");
	scanf("%d",&n);
	printf("Nhap m: ");
	scanf("%d",&m);
	printf("Nhap k: ");
	scanf("%d",&k);
	thu(0);
	if(cnt==0)
		printf("-1");
	else
		printf("%d", cnt);
}

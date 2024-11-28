//Bai 1: Mot may ATM co cac loai tien giay sau: 200.000, 100.000, 50.000, 20.000 va 10.000.
//Moi loai tien deu co so luong khong han che.
//Khach hang can rut mot so tien S.
//Hay tim phuong an tra tien sao cho so to tien la it nhat.
#include <bits/stdc++.h>
using namespace std;
long long a[64];
long long w;
int c;
int cnt=0, s=0;
void greedy(){
	int tem=w, i=0;
	while(tem>0 && i<4*c+4){
		if(tem>=a[i]){
			cnt+=tem/a[i];
			tem-=cnt*a[i];
		}
		i++;
	}
}
int x[64];
void Print(){
	int sum=0, count=0;
	for(int i=0; i<c*4+4; i++){
		sum+=x[i]*a[i];
		count+=x[i];
	}
	if(sum==w && count==cnt)
		s++;
}
void try1(int i){
	for(int j=0; j<=cnt; j++){
		x[i]=j;
		if(i==c*4+4-1)
			Print();
		else
			try1(i+1);
	}
}
int p[]={1000,2000,3000,5000};
int main(){
	cin>>w>>c;
	for(int i=0; i<=c; i++){
		for(int j=4*i; j<4*i+4; j++){
			a[j]=p[j%4]*pow(10,i);
		}
	}
	sort(a,a+4*c+4,greater<long long>());
	greedy();
	try1(0);
	cout<<cnt<<" "<<s;
	
}

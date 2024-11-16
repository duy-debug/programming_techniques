#include <bits/stdc++.h>
using namespace std;
bool KT_SNT(int n){
    if(n<2) return false;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0) return false;
    }
    return true;
}
int UCLN(int a, int b){
    abs(a); abs(b);
    int t=a%b;
    while(t!=0){
        a=b;
        b=t;
        t=a%b;
    }
    return b;
}
int KT_Armstrong(int c){
    int s=0, tem, m=c;
    while(m!=0){
        tem=m%10;
        s+=pow(tem,3);
        m/=10;
    }
    if(s==c) return 1;
    return 0;
}
int main(){
    int n;
    cin>>n;
    if(KT_SNT(n))
    cout<<"La so nguyen to"<<endl;
    else cout<<"Khong phai la so nguyen to"<<endl;
    int a,b;
    cin>>a>>b;
    cout<<"Uoc chung lon nhat cua hai so la: "<<UCLN(a,b);
    int c;
    cin>>c;
    if(KT_Armstrong(c))
    cout<<"So vua nhap la so armstrong";
    else cout<<"So vua nhap khong phai la so armstrong";
    }
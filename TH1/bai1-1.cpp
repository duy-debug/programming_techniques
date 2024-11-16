#include <bits/stdc++.h>
using namespace std;
bool KT_TamGiac(float a, float b, float c){
    if(a+b>c && a+c>b && b+c>a && a>0 && b>0 && c>0){
        return true;
    }
    return false;
}
float Dien_Tich(float a, float b, float c){
    float p=(a+b+c)/2;
    float dientich=sqrt(p*(p-a)*(p-b)*(p-c));
    return dientich;
}

int main(){
    float a,b,c;
    cin>>a>>b>>c;
    if(KT_TamGiac(a,b,c)){
    if(KT_TamGiac(a,b,c)) cout<<"yes";
    else cout<<"no";
    cout<<Dien_Tich(a,b,c)<<endl;
    }
    else{
        cout<<"LOI";
    }
}
#include <bits/stdc++.h>
using namespace std;
int a[101],i=0,s,n;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    if(n<=a[n]){
        cout<<n;
        return 0;
    }
    s=0;
    for(i=1;i<=n;i++)
        if(a[i]>=s)
            s++;
    cout<<s;
}


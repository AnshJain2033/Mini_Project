#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod = 1e9 + 7;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
       ll n;
       cin>>n;
       ll a[n];
        ll b[10]={0};
       for(ll i=0;i<n;i++) 
       {
           cin>>a[i];
           ((b[a[i]-1])++);
        }
        sort(b,b+n);
        cout<<b[10];
        // if(b[9]==n){cout<<"0"<<"\n";}
        // else if(b[9]<n){cout<<(n-b[9])<<"\n";}
        //code here
    }
    return 0;
}
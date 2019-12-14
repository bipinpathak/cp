#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        long int n,ans=0,d=0,temp;
        cin>>n;
        temp=n;
        while(temp) {
            d++;
            temp/=10;
        }
        ans+=9*(d-1);
        temp=0;
        while(d) {
            temp=temp*10+1;
            d--;
        }
        ans+=n/temp;
        cout<<ans<<endl;
    }
}
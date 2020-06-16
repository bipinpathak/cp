#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, i, odd=0, even=0;
        cin>>n;
        int a[n];
        for(i=0; i<n; i++) {
            cin>>a[i];
            if(i%2==0 && a[i]%2!=0) {
                even++;
            }
            else if(i%2!=0 && a[i]%2==0) {
                odd++;
            } 
        }
        if(odd==even) {
            cout<<odd<<endl;
        }
        else {
            cout<<-1<<endl;
        }
    }
	return 0;
}

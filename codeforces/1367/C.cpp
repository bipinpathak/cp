#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, k, i, last, ans=0;
        string s;
        cin>>n>>k;
        last=-k-1;
        cin>>s;
        for(i=0; i<n; i++) {
            if(s[i]=='1') {
                if(i-last<=k) {
                    ans--;
                }
                last=i;
            }
            else if(i-last>k) {
                last=i;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}

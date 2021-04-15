#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int k;
    cin>>k;
    string ans="-1";
    for(int i=5; i*i<=k; i++) {
        if(k%i==0 && (k/i)>=5) {
            int n=i, m=k/i;
            string vowels="aeiou";
            ans.clear();
            int curr=0;
            for(int row=0; row<n; row++) {
                for(int col=0; col<m; col++) {
                    if(curr>=5) {
                        curr-=5;
                    }      
                    ans.push_back(vowels[curr]);
                    curr++;
                }
                curr++;
            }
            break;
        }
    }
    cout<<ans<<endl;
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}


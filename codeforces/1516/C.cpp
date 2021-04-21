#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    int total=0;
    for(auto &i : a) {
        cin>>i;
        total+=i;
    }
    vector<int> ans;
    if(total%2==0) {
        vector<bool> possible(total+1, false);
        possible[0]=true;
        for(auto i : a) {
            for(int curr=total-i; curr>=0; curr--) {
                if(possible[curr]) {
                    possible[curr+i]=true;
                }
            }
        }
        if(possible[total/2]) {
            int low=20;
            for(auto i : a) {
                int curr=0;
                while(i%2==0) {
                    i/=2;
                    curr++;
                }
                low=min(low, curr);
            }
            low=1<<low;
            for(int i=0; i<n; i++) {
                a[i]/=low;
                if(a[i]&1) {
                    ans.push_back(i);
                    break;
                }
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto i : ans) {
        cout<<i+1<<" ";
    }
    cout<<endl;
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    auto start=clock();
    int t = 1;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}


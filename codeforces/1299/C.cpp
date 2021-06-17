#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct step{
    ll sum, len;
    step(ll sumi, ll leni) : sum(sumi), len(leni) {};
};

void solve() {
    int n;
    cin>>n;
    vector<ll> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    stack<step> steps;
    for(auto i : a) {
        step curr(i, 1); 
        while(!steps.empty()) {
            auto prev=steps.top();
            if((prev.sum+curr.sum)*prev.len<=prev.sum*(prev.len+curr.len)) {
                curr.len+=prev.len;
                curr.sum+=prev.sum;
                steps.pop();
            } else {
                break;
            }
        }
        steps.push(curr);
    }
    vector<double> ans;
    while(!steps.empty()) {
        auto curr=steps.top();
        double h=(double)curr.sum/(double)curr.len;
        while(curr.len--) {
            ans.push_back(h); 
        }
        steps.pop();
    }
    reverse(ans.begin(), ans.end());
    cout<<fixed<<setprecision(9);
    for(auto i : ans) {
        cout<<i<<'\n';
    }   
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


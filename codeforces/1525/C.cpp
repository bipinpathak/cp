#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct robot{
    int index, right, x;
    robot (int indexi=0, int righti=0, int xi=0) : index(indexi), right(righti), x(xi) {}
};

bool custom(robot a, robot b) {
    return a.x<b.x;
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<robot> a(n);
    for(int i=0; i<n; i++) {
        cin>>a[i].x;
        a[i].index=i;
    }
    for(int i=0; i<n; i++) {
        char c;
        cin>>c;
        a[i].right=(c=='R');
    }
    sort(a.begin(), a.end(), custom);
    vector<int> ans(n, -1);
    vector<stack<robot>> active(2);
    for(auto i : a) {
        int p=i.x%2;
        if(i.right) {
            active[p].push(i);
        } else if(!active[p].empty()) {
            auto j = active[p].top();
            active[p].pop();
            int t=(i.x-j.x)/2;
            ans[i.index]=ans[j.index]=t;
        }
    }
    vector<vector<robot>> left(2), right(2);
    for(auto i : a) {
        if(ans[i.index]!=-1) {
            continue;
        }
        int p=i.x%2;
        if(i.right) {
            right[p].push_back(i);
        } else {
            left[p].push_back(i);
        }
    }
    for(int p=0; p<2; p++) {
         reverse(left[p].begin(), left[p].end());
         while((int)left[p].size()>=2) {
            auto i = left[p].back();
            left[p].pop_back();
            auto j = left[p].back();
            left[p].pop_back();
            int t=(i.x+j.x)/2;
            ans[i.index]=ans[j.index]=t;
         }
         while((int)right[p].size()>=2) {
            auto i = right[p].back();
            right[p].pop_back();
            auto j = right[p].back();
            right[p].pop_back();
            int t=(2*m-i.x-j.x)/2;
            ans[i.index]=ans[j.index]=t;
         }
    }
    for(int p=0; p<2; p++) {
        while(!left[p].empty() && !right[p].empty()) {
            auto i=left[p].back();
            left[p].pop_back();
            auto j=right[p].back();
            right[p].pop_back();
            int t=(2*m+i.x-j.x)/2;
            ans[i.index]=ans[j.index]=t;
        }
    }
    for(auto i : ans) {
        cout<<i<<" ";
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}


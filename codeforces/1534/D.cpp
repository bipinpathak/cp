#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, moves;
    cin>>n;
    moves=(n+1)/2;
    set<int> active;
    vector<set<int>> adjacency(n);
    cout<<"? 1"<<endl;
    moves--;
    for(int i=0; i<n; i++) {
        int d;
        cin>>d;
        if(d==1) {
            adjacency[0].insert(i);
        } else if(d && d%2==0) {
            active.insert(i);
        }
    }
    if((int)active.size()>moves) {
        set<int> update;
        for(int i=1; i<n; i++) {
            if(active.count(i)) {
                continue;
            }
            update.insert(i);
        }
        active=update;
    }
    while(!active.empty()) {
        int curr=*active.begin();
        active.erase(curr);
        cout<<"? "<<curr+1<<endl;
        map<int, vector<int>> temp;
        for(int i=0; i<n; i++) {
            int d;
            cin>>d;
            temp[d].push_back(i);
        }       
        for(auto i : temp) {
            if((int)i.second.size()==1) {
                int u=i.second.front();
                for(auto v : temp[i.first+1]) {
                    adjacency[min(u, v)].insert(max(u, v));
                }
            }
        }
    }
    cout<<"!"<<endl;
    for(int u=0; u<n; u++) {
        for(auto v : adjacency[u]) {
            cout<<u+1<<" "<<v+1<<endl;
        }
    }   
    return;
}

int main() {
#ifdef bipinpathak
    //(void)!freopen("input.txt", "r", stdin);
    //(void)!freopen("output.txt", "w", stdout);
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


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int find_set(int v, vector<int> &parent) {
	if(parent[v]!=v) {
		parent[v]=find_set(parent[v], parent);
	}
    return parent[v];
}

void union_sets(int a, int b, vector<int> &parent, vector<int> &size) {
    a = find_set(a, parent);
    b = find_set(b, parent);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
	return;
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<int> parent(n), size(n);
    for(int i=0; i<n; i++) {
        parent[i]=i;
        size[i]=1;
    }
    while(m--) {
        int u, v;
        cin>>u>>v;
        u--, v--;
        union_sets(u, v, parent, size);
    }
    set<int> seen;
    stack<int> order;
    int ans=0;
    for(int i=0; i<n; i++) {
        int curr=find_set(i, parent);
        if(!order.empty() && curr==order.top()) {
            continue;
        }
        if(seen.count(curr)) {
            while(1) {
                auto prev=order.top();
                order.pop();
                seen.erase(prev);
                prev=find_set(prev, parent);
                if(prev==curr) {
                    break;
                }
                ans++;
                union_sets(prev, curr, parent, size);
                curr=find_set(curr, parent);
            }
        }
        order.push(curr);
        seen.insert(curr);
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


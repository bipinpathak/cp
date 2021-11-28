#include "bits/stdc++.h"
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
    int n, d;
    cin>>n>>d;
    vector<int> parent(n), size(n, 1);
    for(int i=0; i<n; i++) {
        parent[i]=i;
    }
    for(int di=1; di<=d; di++) {
        int x, y;
        cin>>x>>y;
        x--, y--;
        union_sets(x, y, parent, size);
        vector<int> options;
        int left=di;
        for(int i=0; i<n; i++) {
            if(parent[i]==i) {
                options.push_back(size[i]);
                left-=size[i]-1;
            }
        }
        sort(options.begin(), options.end());
        int ans=options.back()-1;
        options.pop_back();
        left=min(left, (int)options.size());
        while(left--) {
            ans+=options.back();
            options.pop_back();
        }
        cout<<ans<<endl;
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
    int t = 1;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}


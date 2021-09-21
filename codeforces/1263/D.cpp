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
    int n, m=26;
    cin>>n;
    vector<int> parent(m), size(m, 1);
    for(int i=0; i<m; i++) {
        parent[i]=i;
    }
    int have=0;
    while(n--) {
        string s;
        cin>>s;
        int curr=0;
        for(auto &i : s) {
            curr|=1<<(i-'a');
        }
        for(int i=0; i<m; i++) {
            if(!(curr&(1<<i))) {
                continue;    
            }
            for(int j=i+1; j<m; j++) {
                if(!(curr&(1<<j))) {
                    continue;
                }
                union_sets(i, j, parent, size);
            }
        }
        have|=curr;
    }
    set<int> key;
    for(int i=0; i<26; i++) {
        if(!(have&(1<<i))) {
            continue;
        }
        key.insert(find_set(i, parent));
    }
    cout<<key.size()<<endl;
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


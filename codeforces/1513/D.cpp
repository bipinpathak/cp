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
    ll n, p;
    cin>>n>>p;
    vector<vector<int>> a(n, vector<int> (2));
    vector<int> parent(n), size(n, 1), b(n);
    for(int i=0; i<n; i++) {
        parent[i]=i;
        cin>>a[i][0];
        a[i][1]=i;
        b[i]=a[i][0];
    }
    sort(a.begin(), a.end());
    ll ans=0;
    for(auto curr : a) {
        ll val=curr[0];
        int index=curr[1], left=index-1, right=index+1;
        if(val>=p) {
            break;
        }
        while(left>=0 && b[left]%val==0 && find_set(left, parent)!=find_set(index, parent)) {
            union_sets(left, index, parent, size);
            left--;
        }
        while(right<n && b[right]%val==0 && find_set(right, parent)!=find_set(index, parent)) {
            union_sets(right, index, parent, size);
            right++;
        }
        ans+=(right-left-2)*val;
    }
    for(int i=1; i<n; i++) {
        if(find_set(i, parent)!=find_set(i-1, parent)) {
            ans+=p;
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
    cin >> t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}


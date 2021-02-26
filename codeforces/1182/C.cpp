#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct word{
    int total, last;
};

void solve() {
    int n;
    cin>>n;
    vector<string> a(n);
    vector<word> x(n);
    map<char, int> index;
    index['a']=0;
    index['e']=1;
    index['i']=2;
    index['o']=3;
    index['u']=4;
    for(int i=0; i<n; i++) {
        cin>>a[i];
        for(auto j : a[i]) {
            if(index.find(j)!=index.end()) {
                x[i].total++;
                x[i].last=index[j];
            }
        }
    }
    vector<int> used(n);
    vector<vector<int>> pairs;
    for(int curr=0; curr<5; curr++) {
        map<int, int> seen;
        for(int i=0; i<n; i++) {
            if(used[i] || x[i].last!=curr) {
                continue;
            }
            if(seen.find(x[i].total)==seen.end()) {
                seen[x[i].total]=i;
            } else {
                pairs.push_back({i, seen[x[i].total]});
                used[i]=1;
                used[pairs.back().back()]=1;
                seen.erase(x[i].total);
            }
        }
    }
    vector<vector<int>> second;
    map<int, int> seen;
    for(int i=0; i<n; i++) {
        if(used[i]) {
            continue;
        }
        if(seen.find(x[i].total)==seen.end()) {
            seen[x[i].total]=i;
        } else {
            second.push_back({i, seen[x[i].total]});
            seen.erase(x[i].total);
        }
    }
    while(pairs.size()>second.size()) {
        second.push_back(pairs.back());
        pairs.pop_back();
    }
    cout<<pairs.size()<<endl;
    for(int i=0; i<(int)pairs.size(); i++) {
        cout<<a[second[i][0]]<<" "<<a[pairs[i][0]]<<endl;
        cout<<a[second[i][1]]<<" "<<a[pairs[i][1]]<<endl;
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
    while(t--) {
        solve();
    }
    return 0;
}


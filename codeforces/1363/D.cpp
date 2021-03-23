#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int query(vector<vector<int>> &s, int start, int end, int n) {
    set<int> build;
    for(int i=0; i<n; i++) {
        build.insert(i);
    }
    for(int i=start; i<=end && i>=0; i++) {
        for(auto j : s[i]) {
            if(build.find(j)!=build.end()) {
                build.erase(j);
            }
        }
    }
    cout<<"? "<<build.size();
    for(auto &i :build) {
        cout<<" "<<i+1;
    }
    cout<<endl;
    int res;
    cin>>res;
    return res;
}

void solve(string &res) {
    int n, k;
    cin>>n>>k;
    vector<vector<int>> s(k);
    for(auto &i : s) {
        int c;
        cin>>c;
        while(c--) {
            int x;
            cin>>x;
            x--;
            i.push_back(x);
        }
    }
    vector<int> ans(k);
    int largest;
    largest=query(s, -1, -1, n);
    int low=0, high=k-1, mid;
    while(low<high) {
        mid=low+(high-low)/2;
        int left;
        left=query(s, low, mid, n);
        if(left==largest) {
            for(int i=low; i<=mid; i++) {
                ans[i]=largest;
            }
            low=mid+1;
        } else {
            for(int i=mid+1; i<=high; i++) {
                ans[i]=largest;
            }
            high=mid;
        }
    }
    ans[low]=query(s, low, low, n);
    cout<<"!";
    for(auto i : ans) {
        cout<<" "<<i;
    }
    cout<<endl;
    cin>>res;
    return;
}

int main() {
#ifdef bipinpathak
    //(void)!freopen("input.txt", "r", stdin);
    //(void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    string res="Correct";
    for(int i=0; i<t && res=="Correct"; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve(res);
    }
    return 0;
}


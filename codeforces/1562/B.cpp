#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> good;

bool isPrime(int n) {
    for(int i=2; i*i<=n; i++) {
        if(n%i==0) {
            return false;
        }
    }
    return false;
}

void pre() {
    vector<int> a={2, 3, 5, 7};
    set<int> all={1, 4, 6, 8, 9, 22, 25, 27, 32, 33, 35, 52, 55, 57, 72, 75, 77};
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            for(int k=0; k<4; k++) {
                if(i!=j && i!=k && j!=k) {
                    all.insert(a[i]*100+a[j]*10+a[k]);          
                    for(int l=0; l<4; l++) {
                        if(i!=l && j!=l && k!=l) {
                            all.insert(a[i]*1000+a[j]*100+a[k]*10+a[l]);      
                        }
                    }
                }
            }
        }
    }
    for(auto i : all) {
        if(!isPrime(i)) {
            good.push_back(i);
        }
    }
}   

bool possible(int target, vector<int> &a) {
    for(auto i : a) {
        if(i==target%10) {
            target/=10;
        }
    }
    return target==0;
}

int count(int n) {
    int ans=0;
    while(n) {
        n/=10;
        ans++;
    }
    return ans;
}

void solve() {
    int n;
    string s;
    cin>>n>>s;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        a[i]=s[i]-'0';
    }
    reverse(a.begin(), a.end());
    for(auto i : good) {
        if(possible(i, a)) {
            cout<<count(i)<<endl;
            cout<<i<<endl;
            return;
        }
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
    cin>>t;
    pre();
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node{
    node *one=NULL, *zero=NULL;
};

void go(node *x, int &ans, int curr) {
    if(x==NULL) {
        return;
    }
    if(x->one==NULL && x->zero==NULL) {
        ans=min(ans, curr);
        return;
    } 
    curr=curr<<1;
    if(x->one!=NULL && x->zero!=NULL) {
        curr++;
    }
    go(x->one, ans, curr);
    go(x->zero, ans, curr);
    return;
}

void solve() {
    int n;
    cin>>n;
    node *head=new node;
    while(n--) {
       int x, curr=1<<29;;
       cin>>x;
       node *temp=head;
       while(curr) {
            if(x&curr) {
                if(temp->one==NULL) {
                    temp->one=new node;
                }
                temp=temp->one;
            } else {
                if(temp->zero==NULL) {
                    temp->zero=new node;
                }
                temp=temp->zero;
            }
            curr=curr>>1;
       }
    }
    int ans=(1<<30)-1, curr=0;
    go(head, ans, curr);
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
    while(t--) {
        solve();
    }
    return 0;
}


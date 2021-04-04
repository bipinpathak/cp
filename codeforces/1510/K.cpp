#include <bits/stdc++.h>
using namespace std;
void flip(vector<int>& a, int n){
	for(int i=0;i<2*n;i+=2){
			int temp=a[i];
			a[i]=a[i+1];
			a[i+1]=temp;
	}
}
void transfer(vector<int>& a, int n){
	for(int i=0;i<n;i++){
			int temp=a[i];
			a[i]=a[i+n];
			a[i+n]=temp;
		}
}
bool check(vector<int>& a, int n){
	for(int i=0;i<2*n;i++){
		if(a[i]!=i+1)
			return false;
	}
	return true;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(2*n), b(2*n);
    for(int i=0;i<2*n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	if(check(a, n)){
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(i%2){
			flip(a, n);
			transfer(b, n);
			if(check(a, n)||check(b, n)){
				cout<<i<<endl;
				return 0;
			}
		}
		else{
			transfer(a, n);
			flip(b, n);
			if(check(a, n)||check(b, n)){
				cout<<i<<endl;
				return 0;
			}
		}
	}
	cout<<-1<<endl;
	
}

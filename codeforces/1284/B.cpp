#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
	long long int n,i,j,ans=0;
	cin>>n;
	int nonIncreasingMin[n],nonIncreasingMax[n],t=0;
	for(i=0;i<n;i++) {
		int l;
		cin>>l;
		int a[l],min=1000000,max=0,key=1;
		for(j=0;j<l;j++) {
			cin>>a[j];
			if(a[j]<min) {
				min=a[j];
			}
			if(a[j]>max) {
				max=a[j];
			}
			if(a[j]>min) {
				key=0;
			}
		}
		if(key) {
			nonIncreasingMin[t]=min;
			nonIncreasingMax[t]=max;
			t++;
		}
	}
	ans=n*n;
	sort(nonIncreasingMin,nonIncreasingMin+t);
	sort(nonIncreasingMax,nonIncreasingMax+t);
	j=t-1;
	for(i=t-1;i>=0 && j>=0;i--) {
		while(nonIncreasingMax[j]>nonIncreasingMin[i] && j>=0) {
			j--;			
		}
		ans=ans-j-1;
	}
	cout<<ans<<endl;
}
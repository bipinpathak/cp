#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        int a[n];
        vector<int> ans;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ans.push_back(a[0]);
        for (i = 1; i < n - 1; i++)
        {
            if (a[i] > a[i - 1] && a[i] > a[i + 1])
            {
                ans.push_back(a[i]);
            }
            if (a[i] < a[i - 1] && a[i] < a[i + 1])
            {
                ans.push_back(a[i]);
            }
        }
        if (n > 1)
        {
            ans.push_back(a[n - 1]);
        }
        cout << ans.size() << endl;
        for (i = 0; i < ans.size(); i++)
        {
            cout << ans.at(i) << " ";
        }
        cout << endl;
    }
}
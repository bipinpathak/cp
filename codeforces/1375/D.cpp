#include <bits/stdc++.h>
using namespace std;
int mex(vector<int> &a)
{
    unordered_set<int> f;
    for (int i : a)
    {
        f.insert(i);
    }
    int count = 0;
    while (f.find(count) != f.end())
    {
        count++;
    }
    return count;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j, temp;
        cin >> n;
        vector<int> a(n), ans;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        while (1)
        {
            temp = mex(a);
            if (temp == n)
            {
                j = 0;
                while (j < n && a[j] == j)
                {
                    j++;
                }
                if (j == n)
                {
                    break;
                }
                else
                {
                    a[j] = temp;
                    ans.push_back(j + 1);
                }
            }
            else
            {
                a[temp] = temp;
                ans.push_back(temp + 1);
            }
        }
        cout << ans.size() << endl;
        for (int i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}

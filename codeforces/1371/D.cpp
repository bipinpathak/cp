#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, offset = 0, i, j;
        cin >> n >> k;
        if (k % n)
        {
            cout << "2" << endl;
        }
        else
        {
            cout << "0" << endl;
        }
        vector<int> temp(n, 0);
        vector<vector<int>> ans(n, temp);
        k--;
        while (k >= 0)
        {
            i = 0;
            while (k >= 0 && i < n)
            {
                ans.at(k % n).at((k + offset) % n) = 1;
                k--;
                i++;
            }
            offset++;
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                cout << ans.at(i).at(j);
            }
            cout << endl;
        }
    }
    return 0;
}

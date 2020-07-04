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
        int n, m, i, j;
        bool flag = true;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                cin >> grid[i][j];
                if (((i == 0 || j == 0 || i == n - 1 || j == m - 1) && grid[i][j] > 3) || grid[i][j] > 4)
                {
                    flag = false;
                }
                if (((i == 0 && j == 0) || (i == n - 1 && j == 0) || (i == 0 && j == m - 1) || (i == n - 1 && j == m - 1)) && grid[i][j] > 2)
                {
                    flag = false;
                }
            }
        }
        if (flag)
        {
            cout << "YES" << endl;
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < m; j++)
                {
                    if ((i == 0 && j == 0) || (i == n - 1 && j == 0) || (i == 0 && j == m - 1) || (i == n - 1 && j == m - 1))
                    {
                        cout << "2 ";
                    }
                    else if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                    {
                        cout << "3 ";
                    }
                    else
                    {
                        cout << "4 ";
                    }
                }
                cout << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}

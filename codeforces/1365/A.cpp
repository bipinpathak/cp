#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, i, j, temp, nr = 0, nc = 0;
        cin >> n >> m;
        vector<int> columns(m, 1), rows(n, 1);
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                cin >> temp;
                if (temp)
                {
                    columns.at(j) = 0;
                    rows.at(i) = 0;
                }
            }
        }
        for (i = 0; i < n; i++)
        {
            nr += rows.at(i);
        }
        for (i = 0; i < m; i++)
        {
            nc += columns.at(i);
        }
        if (min(nr, nc) % 2)
        {
            cout << "Ashish" << endl;
        }
        else
        {
            cout << "Vivek" << endl;
        }
    }
    return 0;
}
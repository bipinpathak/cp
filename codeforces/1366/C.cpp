#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, i, j, ans = 0, mid, sum;
        cin >> n >> m;
        vector<int> distances(n + m - 1, 0), temp(m);
        vector<vector<int>> matrix(n, temp);
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                cin >> matrix.at(i).at(j);
                distances.at(i + j) += matrix.at(i).at(j);
            }
        }
        mid = (n + m - 1) / 2;
        for (i = 0; i < mid; i++)
        {
            sum = distances.at(i) + distances.at(m + n - 2 - i);
            ans += min(sum, 2 * min(i + 1, min(n, m)) - sum);
            //cout << "for distance " << i << " changed " << min(sum, min(2 * i + 2, n * m) - sum) << " as there were  " << sum << " ones originally out of " << 2 * min(i + 1, min(n, m)) << " places" << endl;
        }
        cout << ans << endl;
    }
    return 0;
}
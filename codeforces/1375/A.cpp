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
        int n, i;
        cin >> n;
        vector<int> a(n);
        for (i = 0; i < n; i++)
        {
            cin >> a.at(i);
        }
        for (i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                a.at(i) = abs(a.at(i));
            }
            else
            {
                a.at(i) = -1 * abs(a.at(i));
            }
            cout << a.at(i) << " ";
        }
        cout << endl;
    }

    return 0;
}

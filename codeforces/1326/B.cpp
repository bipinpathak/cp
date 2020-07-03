#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, i, m;
    cin >> n;
    vector<int> b(n);
    for (i = 0; i < n; i++)
    {
        cin >> b.at(i);
    }
    m = b.at(0);
    for (i = 1; i < n; i++)
    {
        if (b.at(i - 1) > m)
        {
            m = b.at(i - 1);
        }
        b.at(i) += m;
    }
    for (i = 0; i < n; i++)
    {
        cout << b.at(i) << " ";
    }
    cout << endl;
    return 0;
}

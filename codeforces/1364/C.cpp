#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j = 0;
    cin >> n;
    vector<int> a(n), b(n, -1), f(n + 1, 0);
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        f[a[i]]++;
        if (i && a[i] != a[i - 1])
        {
            b[i] = a[i - 1];
            f[b[i]]++;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (b[i] == -1)
        {
            while (f[j] != 0)
            {
                j++;
            }
            b[i] = j;
            f[b[i]]++;
        }
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}

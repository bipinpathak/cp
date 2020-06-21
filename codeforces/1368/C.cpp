#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, i;
    cin >> n;
    cout << 3 * n + 4 << endl;
    for (i = 0; i <= n; i++)
    {
        cout << i << " " << i << endl
             << i << " " << i + 1 << endl
             << i + 1 << " " << i << endl;
    }
    cout << i << " " << i << endl;
    return 0;
}
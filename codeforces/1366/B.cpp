#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, m, left, right, i, j;
        cin >> n >> x >> m;
        left = right = x;
        while (m--)
        {
            cin >> i >> j;
            if (i < left && j >= left)
            {
                left = i;
            }
            if (j > right && i <= right)
            {
                right = j;
            }
        }
        cout << right - left + 1 << endl;
    }
    return 0;
}
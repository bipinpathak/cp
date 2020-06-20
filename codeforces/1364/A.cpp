#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, i, sum = 0, ans = -1, front = INT_MAX, back = INT_MIN;
        cin >> n >> x;
        int a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
            if (a[i] % x != 0)
            {
                front = min(front, i);
                back = max(back, i);
            }
        }
        if (sum % x != 0)
        {
            ans = n;
        }
        else
        {
            if (front < n)
            {
                ans = n - front - 1;
            }
            if (back >= 0)
            {
                ans = max(ans, back);
            }
        }
        cout << ans << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, front, back, i;
        string s, ans = "";
        cin >> n >> s;
        for (front = 0; front < n && s[front] != '1'; front++)
        {
        };
        for (back = n - 1; back >= 0 && s[back] != '0'; back--)
        {
        };
        if (front == n || back == -1 || front > back)
        {
            ans = s;
        }
        else
        {
            for (i = 0; i < front && i < n; i++)
            {
                ans += s[i];
            }
            for (i = back; i < n && i >= 0; i++)
            {
                ans += s[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
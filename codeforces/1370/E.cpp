#include <bits/stdc++.h>
using namespace std;

int countOne(string s)
{
    int count = 0;
    for (char c : s)
        if (c == '1')
            count++;
    return count;
}

int main()
{
    int n, i, ans = -1;
    string s, t;
    cin >> n >> s >> t;
    if (countOne(s) == countOne(t))
    {
        ans = 0;
        int up = 0, down = 0;
        for (i = 0; i < n; i++)
        {
            if (s[i] != t[i])
            {
                if (s[i] == '1')
                {
                    up++;
                    if (down)
                        down--;
                }
                else
                {
                    down++;
                    if (up)
                        up--;
                }
            }
        }
        ans = up + down;
    }
    cout << ans << endl;
    return 0;
}
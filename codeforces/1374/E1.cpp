#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, i, j, x, y, t;
    long long ans = 0;
    cin >> n >> k;
    vector<int> a, b, c;
    for (i = 0; i < n; i++)
    {
        cin >> t >> x >> y;
        if (x && y)
        {
            c.push_back(t);
        }
        else if (x)
        {
            a.push_back(t);
        }
        else if (y)
        {
            b.push_back(t);
        }
    }
    if (a.size() + c.size() < k || b.size() + c.size() < k)
    {
        ans = -1;
    }
    else
    {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        j = min(k, (int)c.size()) - 1;
        i = k - j - 1;
        while (i < min((int)a.size(), (int)b.size()) && j >= 0 && c.at(j) > a.at(i) + b.at(i))
        {
            i++;
            j--;
        }
        for (t = 0; t < i; t++)
        {
            ans += a.at(t) + b.at(t);
        }
        for (t = 0; t <= j; t++)
        {
            ans += c.at(t);
        }
    }
    cout << ans << endl;
    return 0;
}

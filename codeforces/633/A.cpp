#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b, int &x, int &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    else
    {
        int x1, y1, g = gcd(b % a, a, y1, x1);
        y = y1;
        x = x1 - y * (b / a);
        return g;
    }
}
int main()
{
    int a, b, c, g, x, y;
    string ans = "";
    cin >> a >> b >> c;
    g = gcd(a, b, x, y);
    if (c % g == 0)
    {
        x *= c / g;
        y *= c / g;
        int n;
        if (x < 0)
        {
            n = (-1 * x * g + (b - 1)) / b;
            x += n * (b / g);
            y -= n * (a / g);
        }
        if (y < 0)
        {
            n = (-1 * y * g + (a - 1)) / a;
            x -= n * (b / g);
            y += n * (a / g);
        }
        if (x >= 0 && y >= 0)
        {
            ans = "Yes";
        }
    }
    if (ans == "")
    {
        ans = "No";
    }
    cout << ans << endl;
    return 0;
}

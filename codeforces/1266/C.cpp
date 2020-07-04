#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    return gcd(b % a, a);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r, c, i, j, temp;
    cin >> r >> c;
    if (r == 1 && c == 1)
    {
        cout << 0 << endl;
    }
    else if (r == 1 || c == 1)
    {
        temp = 2;
        for (i = 1; i <= r; i++)
        {
            for (j = 1; j <= c; j++)
            {
                cout << temp;
                temp++;
                if (j < c)
                {
                    cout << " ";
                }
                else
                {
                    cout << endl;
                }
            }
        }
    }
    else
    {
        for (i = 1; i <= r; i++)
        {
            for (j = 1; j <= c; j++)
            {
                temp = i / gcd(i, r + j);
                temp *= (r + j);
                cout << temp;
                if (j < c)
                {
                    cout << " ";
                }
                else
                {
                    cout << endl;
                }
            }
        }
    }
    return 0;
}

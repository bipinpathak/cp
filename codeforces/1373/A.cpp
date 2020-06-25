#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int a, b, c, shop1, shop2;
        cin >> a >> b >> c;
        if (c <= a)
        {
            shop1 = -1;
            if (c == a)
            {
                shop2 = b;
            }
            else
            {
                shop2 = 1;
            }
        }
        else
        {
            if (b * a <= c)
            {
                shop1 = 1;
                shop2 = -1;
            }
            else
            {
                shop1 = 1;
                shop2 = b;
            }
        }
        cout << shop1 << " " << shop2 << endl;
    }
    return 0;
}
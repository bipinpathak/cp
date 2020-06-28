#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, two = 0, three = 0;
        cin >> n;
        while (n % 2 == 0)
        {
            n /= 2;
            two++;
        }
        while (n % 3 == 0)
        {
            n /= 3;
            three++;
        }
        if (n != 1 || three < two)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << 2 * three - two << endl;
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, count = 0, lastEven = -1, lastOdd = -1;
        cin >> n;
        int a[2 * n];
        for (i = 0; i < 2 * n; i++)
        {
            cin >> a[i];
            if (a[i] % 2)
            {
                if (lastOdd == -1)
                {
                    lastOdd = i + 1;
                }
                else if (count < n - 1)
                {
                    cout << lastOdd << " " << i + 1 << endl;
                    lastOdd = -1;
                    count++;
                }
            }
            else
            {
                if (lastEven == -1)
                {
                    lastEven = i + 1;
                }
                else if (count < n - 1)
                {
                    cout << lastEven << " " << i + 1 << endl;
                    lastEven = -1;
                    count++;
                }
            }
        }
    }
    return 0;
}

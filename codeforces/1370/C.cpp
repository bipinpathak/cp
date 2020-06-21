#include <bits/stdc++.h>
using namespace std;
bool isPowerOfTwo(int n)
{
    while (n % 2 == 0)
    {
        n /= 2;
    }
    return n == 1;
}
bool isPrime(int n)
{
    if (n == 3)
    {
        return true;
    }
    if (n < 3)
    {
        return false;
    }
    int i = 3;
    while (i * i <= n && n % i != 0)
    {
        i += 2;
    }
    return n % i;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, N, a = 0, b = 0, i = 3;
        string ans = "Ashishgup";
        cin >> n;
        if (n == 1 || (n > 2 && isPowerOfTwo(n)) || (n % 2 == 0 && n % 4 && isPrime(n / 2)))
        {
            ans = "FastestFinger";
        }
        cout << ans << endl;
    }
    return 0;
}

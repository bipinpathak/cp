#include <bits/stdc++.h>
using namespace std;
void filler(vector<int> &bits, int a)
{
    int i = 19;
    //cout << "Running filler for " << a << endl;
    while (a)
    {
        //cout << "running loop for " << i << endl;
        if (a & 1)
        {
            bits[i]++;
        }
        a = a >> 1;
        i--;
    }
}
int main()
{
    int n, i, a;
    long long int ans = 0;
    vector<int> bits(20, 0);
    cin >> n;
    //cout << "taking input" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> a;
        filler(bits, a);
    }
    a = INT_MAX;
    //cout << "calculating max" << endl;
    for (i = 0; i < 20; i++)
    {
        if (bits[i])
        {
            a = min(a, bits[i]);
        }
    }
    while (a != INT_MAX)
    {
        //cout << "a = " << a << endl;
        long long int temp = 1, sum = 0;
        n = a;
        a = INT_MAX;
        for (i = 19; i >= 0; i--)
        {
            if (bits[i] >= n)
            {
                bits[i] -= n;
                sum += temp;
            }
            temp *= 2;
            if (bits[i])
            {
                a = min(a, bits[i]);
            }
        }
        //cout << "Sum = " << sum << endl;
        ans += n * sum * sum;
    }
    cout << ans << endl;
    return 0;
}
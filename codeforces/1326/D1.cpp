#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string &s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
        {
            break;
        }
        i++;
        j--;
    }
    return i >= j;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s, a, c, b;
        cin >> s;
        int n = s.length(), start = 0, end = n - 1;
        while (start < end && s[start] == s[end])
        {
            a += s[start];
            start++;
            end--;
        }
        if (start < end)
        {
            b = a;
            reverse(b.begin(), b.end());
            string front = "", back = "";
            int i = start, j = end;
            while (i < end)
            {
                if (isPalindrome(s, start, i))
                {
                    front = s.substr(start, i - start + 1);
                }
                if (isPalindrome(s, j, end))
                {
                    back = s.substr(j, end - j + 1);
                }
                i++;
                j--;
            }
            c = (front.size() >= back.size()) ? front : back;
            s = a + c + b;
        }
        cout << s << endl;
    }
    return 0;
}

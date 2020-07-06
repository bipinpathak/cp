#include <bits/stdc++.h>
using namespace std;
void build(vector<vector<int>> &possible, vector<string> &maze, int i, int j)
{
    int n = maze.size(), m = maze.at(0).size();
    if (possible[i][j] == 1)
    {
        if (i - 1 >= 0 && possible[i - 1][j] == -1)
        {
            if (maze[i - 1][j] == '#')
            {
                possible[i - 1][j] = 0;
            }
            else
            {
                possible[i - 1][j] = 1;
                build(possible, maze, i - 1, j);
            }
        }
        if (j - 1 >= 0 && possible[i][j - 1] == -1)
        {
            if (maze[i][j - 1] == '#')
            {
                possible[i][j - 1] = 0;
            }
            else
            {
                possible[i][j - 1] = 1;
                build(possible, maze, i, j - 1);
            }
        }
        if (i + 1 < n && possible[i + 1][j] == -1)
        {
            if (maze[i + 1][j] == '#')
            {
                possible[i + 1][j] = 0;
            }
            else
            {
                possible[i + 1][j] = 1;
                build(possible, maze, i + 1, j);
            }
        }
        if (j + 1 < m && possible[i][j + 1] == -1)
        {
            if (maze[i][j + 1] == '#')
            {
                possible[i][j + 1] = 0;
            }
            else
            {
                possible[i][j + 1] = 1;
                build(possible, maze, i, j + 1);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, i, j;
        bool flag = true;
        string ans = "No";
        cin >> n >> m;
        vector<string> maze(n);
        vector<vector<int>> possible(n, vector<int>(m, -1));
        for (i = 0; i < n; i++)
        {
            cin >> maze[i];
        }
        for (i = 0; i < n && flag; i++)
        {
            for (j = 0; j < m && flag; j++)
            {
                if (maze[i][j] == 'B')
                {
                    if (i - 1 >= 0)
                    {
                        if (maze[i - 1][j] == 'G')
                        {
                            flag = false;
                        }
                        else if (maze[i - 1][j] != 'B')
                        {
                            maze[i - 1][j] = '#';
                        }
                    }
                    if (j - 1 >= 0)
                    {
                        if (maze[i][j - 1] == 'G')
                        {
                            flag = false;
                        }
                        else if (maze[i][j - 1] != 'B')
                        {
                            maze[i][j - 1] = '#';
                        }
                    }
                    if (i + 1 < n)
                    {
                        if (maze[i + 1][j] == 'G')
                        {
                            flag = false;
                        }
                        else if (maze[i + 1][j] != 'B')
                        {
                            maze[i + 1][j] = '#';
                        }
                    }
                    if (j + 1 < m)
                    {
                        if (maze[i][j + 1] == 'G')
                        {
                            flag = false;
                        }
                        else if (maze[i][j + 1] != 'B')
                        {
                            maze[i][j + 1] = '#';
                        }
                    }
                }
            }
        }
        if (flag)
        {
            if (maze[n - 1][m - 1] != '#')
            {
                possible[n - 1][m - 1] = 1;
            }
            build(possible, maze, n - 1, m - 1);
            for (i = 0; i < n && flag; i++)
            {
                for (j = 0; j < m && flag; j++)
                {
                    if ((maze[i][j] == 'G' && possible[i][j] != 1) || (maze[i][j] == 'B' && possible[i][j] == 1))
                    {
                        flag = false;
                    }
                }
            }
        }
        if (flag)
        {
            ans = "Yes";
        }
        cout << ans << endl;
    }
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 5; // Number of processes
    int m = 3; // Number of resources

    vector<vector<int>> alloc = {
        {0, 1, 0}, // P0 // Allocation Matrix
        {2, 0, 0}, // P1
        {3, 0, 2}, // P2
        {2, 1, 1}, // P3
        {0, 0, 2}  // P4
    };

    vector<vector<int>> max = {
        {7, 5, 3}, // P0 // MAX Matrix
        {3, 2, 2}, // P1
        {9, 0, 2}, // P2
        {2, 2, 2}, // P3
        {4, 3, 3}  // P4
    };

    vector<int> avail = {3, 3, 2}; // Available Resources

    vector<int> f(n, 0), ans(n);
    int ind = 0;

    // Calculate the need matrix
    vector<vector<int>> need(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            if (f[i] == 0)
            {
                bool flag = true;
                for (int j = 0; j < m; ++j)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    ans[ind++] = i;
                    for (int j = 0; j < m; ++j)
                    {
                        avail[j] += alloc[i][j];
                    }
                    f[i] = 1;
                }
            }
        }
    }

    bool isSafe = true;
    for (int i = 0; i < n; ++i)
    {
        if (f[i] == 0)
        {
            isSafe = false;
            cout << "The given sequence is not safe" << endl;
            break;
        }
    }

    if (isSafe)
    {
        cout << "Following is the SAFE Sequence:" << endl;
        for (int i = 0; i < n - 1; ++i)
        {
            cout << " P" << ans[i] << " ->";
        }
        cout << " P" << ans[n - 1] << endl;
    }

    return 0;
}

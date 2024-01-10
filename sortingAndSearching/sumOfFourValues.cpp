#include <bits/stdc++.h>
using namespace std;
typedef long long int;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    map<int, vector<array<int, 2>>> mp;
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            mp[nums[i] + nums[j]].push_back({i, j});

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (auto T : mp[k - (nums[i] + nums[j])])
            {
                if (T[0] != i && T[0] != j && T[1] != i && T[1] != j)
                {
                    cout << i + 1 << " " << j + 1 << " " << T[0] + 1 << " " << T[1] + 1 << "\n";
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}
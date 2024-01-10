#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void equal(multiset<ll> &men, multiset<ll> &mai)
{
    while (men.size() > 1 + mai.size())
    {
        auto temp = --men.end();
        mai.insert(*temp);
        men.erase(temp);
    }
    while (mai.size() > men.size())
    {
        auto temp = mai.begin();
        men.insert(*temp);
        mai.erase(temp);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    ll n, k;
    cin >> n >> k;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    if (k == 1)
    {
        for (int i = 0; i < n; i++)
            cout << nums[i] << " ";
        cout << "\n";
        return 0;
    }
    else if (k == 2)
    {
        for (int i = 1; i < n; i++)
            cout << min(nums[i], nums[i - 1]) << " ";
        cout << "\n";
        return 0;
    }
    multiset<ll> men, mai;

    for (int i = 0; i < k; i++)
        men.insert(nums[i]);
    equal(men, mai);
    cout << *(--men.end()) << " ";
    for (int i = k; i < n; i++)
    {

        if (nums[i - k] <= *(--men.end()))
        {
            auto temp = men.lower_bound(nums[i - k]);
            men.erase(temp);
        }
        else
        {
            auto temp = mai.lower_bound(nums[i - k]);
            mai.erase(temp);
        }

        if (nums[i] <= *(--men.end()))
            men.insert(nums[i]);
        else
            mai.insert(nums[i]);
        equal(men, mai);
        cout << *(--men.end()) << " ";
    }
    cout << "\n";
}
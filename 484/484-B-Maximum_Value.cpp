#include <bits/stdc++.h>
using namespace std;
#define ll long long

int maxModValue(ll arr[], ll n)
{
    ll ans = 0;
    sort(arr, arr + n);
     for (ll j = n - 2; j >= 0; --j) {
        if (ans >= arr[j])
            break;
        if (arr[j] == arr[j + 1])
            continue;
 
        for (ll i = 2 * arr[j]; i <= arr[n - 1] + arr[j]; i += arr[j]) {
            ll ind = lower_bound(arr, arr + n, i) - arr;
            ans = max(ans, arr[ind - 1] % arr[j]);
        }
    }
    return ans;
}
 
int main()
{
   ll n;
   cin>>n;
   ll arr[n];
   for(ll i=0; i<n; i++)
    cin>>arr[i];
    cout << maxModValue(arr, n);
}
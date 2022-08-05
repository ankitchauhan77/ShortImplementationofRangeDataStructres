#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ll long long

#define oset tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>  // for multiset use less_equal
#define ook order_of_key  //  s.ook(a)  returns position of a
#define fbo find_by_order  //  x = s.fbo(a)    ->   x = iterator of position a

//https://leetcode.com/problems/count-of-range-sum/

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        oset s;
        s.insert(0);
        ll sum = 0, ans = 0;
        int n = nums.size();
        auto go = [&](ll x) -> int{
            return s.ook(x + 1);
        };
        for (int i = 0; i < n; i++) {
            sum += (ll)nums[i];
            // cout << sum << "\n";
//             sum - x >= lower && sum - x <= upper    x <= sum - lower && x >= sum - upper
            ll l = sum - upper, r = sum - lower;
            if (l > r) {
                s.insert(sum);
                continue;
            }
            ans += go(r) - go(l - 1ll);
            // ans += (s.ook(r) - s.ook(l - 1));
            s.insert(sum);
        }
        return (int)ans;
    }
};









#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define rsrt(v) sort(v.begin(), v.end(), greater<int>())
#define fi(i,a,b) for(int i=a;i<b;i++)
#define srt(v) sort(v.begin(),v.end())
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define int long long
ll md = 1000000007;
int inf = 1e18;
#define X first
#define Y second
using namespace std;
#define dbg(x) cerr << #x << " = " << x << endl;
template <typename T>
T pw(T a, T b) {T c = 1, m = a;while(b) {if (b & 1) c=(c*m); m=(m*m); b/=2;} return c;}
template <typename T>
T ceel(T a, T b){if (a%b==0) return a/b; else return a/b + 1;}
template <typename T>
T gcd(T a, T b) {return b == 0 ? a : gcd(b, a % b);}
ll pwmd(ll a, ll b) {ll c = 1, m = a%md;while(b) {if (b & 1) c=(c*m)%md; m=(m*m)%md; b/=2;} return c;}
ll modinv(ll n){return pwmd(n, md - 2);}
//--------------------------------theartofwar-------------------------------------------//
class BIT { //1-indexed
public:
  int n; vector<int> t;
  BIT() {}
  BIT(int _n) {
    n = _n; t.assign(n + 1, 0);
  }
  int query(int i) {
    int ans = 0;
    for (; i >= 1; i -= (i & -i)) ans += t[i];
    return ans;
  }
  void upd(int i, int val) {
    if (i <= 0) return;
    for (; i <= n; i += (i & -i)) t[i] += val;
  }
  void upd(int l, int r, int val) {
    upd(l, val);
    upd(r + 1, -val);
  }
  int query(int l, int r) {
    return query(r) - query(l - 1);
  }
};
/* 
1)  We are adding on range not assigning
2)  If query is on range then use upd(l, r, val)
3)  You have to manually build tree
 */
signed main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n, m, a;
    cin >> n >> m;
    vi v;
    fi(i, 0, n) cin >> a, v.pb(a);
    BIT tree(n);
    fi(i, 1, n + 1) tree.upd(i, v[i - 1]);
    fi(i, 0, m) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            int e = tree.query(x + 1, x + 1);
            tree.upd(x + 1, y - e);
        } else {
            x++;
            cout << tree.query(x, y) << "\n";
        }
    }
}
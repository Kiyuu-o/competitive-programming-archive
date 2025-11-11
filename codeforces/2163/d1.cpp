// Author: Kexuan Miao
#include <bits/stdc++.h>
using namespace std;

#define cmax(u, v) u = max(u, v)
#define cmin(u, v) u = min(u, v)
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

typedef pair<ll, ll> pll;
const ll m = 1e9 + 7;

int c;

int query(int l, int r) {
	c++;
	cout << "? " << l << ' ' << r << endl;
	int x;
	cin >> x;
	return x;
}

void solve(){
	c = 0;
	int n, q;
	cin >> n >> q;
	vector<pii> a;
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		a.emplace_back(l, -r);
	}
	sort(all(a));
	vector<pii> v;
	int mx = 0;
	for (int i = 0; i < q; i++) {
		auto [l, r] = a[i];
		r = -r;
		if (r > mx) {
			mx = r;
			v.emplace_back(l, r);
		}
	}
	reverse(all(v));
	int mid = n / 2;
	int res = query(1, mid);
	vector<pii> b;
	for (auto &[l, r] : v) {
		if (res) {
			if (l <= mid) b.emplace_back(l, r);
		} else {
			if (r > mid) b.emplace_back(l, r);
		}
	}
	int ans = 0;
	for (auto& [l, r] : b) {
		ans = max(ans, query(l, r));
	}
	cout << "! " << ans << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}
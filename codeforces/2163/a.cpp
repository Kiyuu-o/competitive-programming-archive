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

void solve(){
	int n;
	cin >> n;
	vi a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(all(a));
	bool ok = true;
	for (int i = 0; i < n - 1; i++) {
		if (i  % 2 == 1) {
			if (a[i] != a[i + 1])
				ok = false;
		}
	}
	if (ok) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}
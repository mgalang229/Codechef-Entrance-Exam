#include <bits/stdc++.h>

using namespace std;

long long totals[10011];

long long select(int n, int i) {
	sort(totals, totals + n);
	return totals[i - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--) {
		int n, k, e, m;
		cin >> n >> k >> e >> m;
		for (int i = 0; i < n - 1; i++) {
			long long total = 0;
			for (int j = 0; j < e; j++) {
				long long score;
				cin >> score;
				total += score;
			}
			totals[i] = total;
		}
		long long x = select(n - 1, n - k);
		long long y = 0;
		for (int j = 0; j < e - 1; j++) {
			long long score;
			cin >> score;
			y += score;
		}
		long long ans = max(0LL, x - y + 1);
		if (ans > m) {
			cout << "Impossible";
		} else {
			cout << ans;
		}
		cout << '\n';
	}
	return 0;
}

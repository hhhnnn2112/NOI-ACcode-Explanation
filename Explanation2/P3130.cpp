#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[200020];
long long sm[600020];
long long mn[600020];
long long ad[600020];
void build(int x, int l, int r) {
	if (l == r) {
		sm[x] = a[l];
		mn[x] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(x * 2, l, mid);
	build(x * 2 + 1, mid + 1, r);
	sm[x] = sm[x * 2] + sm[x * 2 + 1];
	mn[x] = min(mn[x * 2], mn[x * 2 + 1]);
}
void add(int x, int l, int r, long long v) {
	sm[x] += (r - l + 1) * v;
	mn[x] += v;
	ad[x] += v;
}
void push(int x, int l, int r) {
	int mid = (l + r) / 2;
	add(x * 2, l, mid, ad[x]);
	add(x * 2 + 1, mid + 1, r, ad[x]);
	ad[x] = 0;
}
void change(int x, int l, int r, int L, int R, long long v) {
	if (r < L || R < l) {
		return;
	}
	if (L <= l && r <= R) {
		add(x, l, r, v);
		return;
	}
	push(x, l, r);
	int mid = (l + r) / 2;
	change(x * 2, l, mid, L, R, v);
	change(x * 2 + 1, mid + 1, r, L, R, v);
	sm[x] = sm[x * 2] + sm[x * 2 + 1];
	mn[x] = min(mn[x * 2], mn[x * 2 + 1]);
}
long long query(int x, int l, int r, int L, int R) {
	if (r < L || R < l) {
		return 0;
	}
	if (L <= l && r <= R) {
		return sm[x];
	}
	push(x, l, r);
	int mid = (l + r) / 2;
	return query(x * 2, l, mid, L, R) + query(x * 2 + 1, mid + 1, r, L, R);
}
long long ask(int x, int l, int r, int L, int R) {
	if (r < L || R < l) {
		return 1e18;
	}
	if (L <= l && r <= R) {
		return mn[x];
	}
	push(x, l, r);
	int mid = (l + r) / 2;
	return min(ask(x * 2, l, mid, L, R), ask(x * 2 + 1, mid + 1, r, L, R));
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	build(1, 1, n);
	for (int i = 0; i < m; i++) {
		char o;
		int x, y;
		long long z;
		scanf(" %c", &o);
		if (o == 'M') {
			scanf("%d%d", &x, &y);
			printf("%lld\n", ask(1, 1, n, x, y));
		} else if (o == 'P') {
			scanf("%d%d%lld", &x, &y, &z);
			change(1, 1, n, x, y, z);
		} else {
			scanf("%d%d", &x, &y);
			printf("%lld\n", query(1, 1, n, x, y));
		}
	}
	return 0;
}
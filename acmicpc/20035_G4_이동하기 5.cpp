#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int A[100'010];
int B[100'010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) cin >> A[i];
	for (int i = 0; i < M; ++i) cin >> B[i];

	int mx_a = *max_element(A, A + N);
	int mx_b = *max_element(B, B + M);

	int sa, ea;
	for (int i = 0; i < N; ++i) { if (A[i] == mx_a) { sa = i; break; } }
	for (int i = N - 1; i >= 0; --i) { if (A[i] == mx_a) { ea = i; break; } }

	int sm_a = mx_a * (M - 1);
	for (int i = 0; i < N; ++i) sm_a += A[i];

	int sm_b = B[0] * sa + mx_b * (ea - sa) + B[M - 1] * (N - ea - 1);
	for (int i = 0; i < M; ++i) sm_b += B[i];

	cout << (ll)sm_a * 1000000000LL + (ll)sm_b;

	return 0;
}

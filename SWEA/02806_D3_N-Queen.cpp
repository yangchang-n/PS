#include <iostream>

using namespace std;

int N;
int cnt;

bool vertical[16] = {};
bool diago_up[32] = {};
bool diago_dn[32] = {};

void bkt(int j)
{
	if (j == N)
	{
		cnt++;
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		if (vertical[i] || diago_up[i + j] || diago_dn[j - i + N - 1]) continue;

		vertical[i] = diago_up[i + j] = diago_dn[j - i + N - 1] = true;
		bkt(j + 1);
		vertical[i] = diago_up[i + j] = diago_dn[j - i + N - 1] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int T;
    cin >> T;
    
    for (int tc = 1; tc <= T; ++tc)
    {
        cin >> N;
        cnt = 0;
        
        bkt(0);
        
        cout << '#' << tc << ' ' << cnt << '\n';
    }

	return 0;
}

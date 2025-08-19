#include <iostream>

using namespace std;

string str;
int cnt0 = 0;
int cnt1 = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> str;
	int sz = str.size();

	if (str[0] == '0') cnt0++;
	else cnt1++;

	char pre = str[0];
	for (int i = 1; i < sz; ++i)
	{
		if (str[i] == pre) continue;

		if (str[i] == '0') cnt0++;
		else cnt1++;

		pre = str[i];
	}

	if (cnt0 < cnt1) cout << cnt0;
	else cout << cnt1;

	return 0;
}

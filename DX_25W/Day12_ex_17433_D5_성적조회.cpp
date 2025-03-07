#include <set>
#include <array>
#include <unordered_map>

using namespace std;

set<array<int, 2>> stu_score[6];
unordered_map<int, array<int, 3>> stu_info;
unordered_map<char, int> gender = { {'m', 0}, {'f', 1} };

void init()
{
	for (int i = 0; i < 6; ++i) stu_score[i].clear();
	stu_info.clear();

	return;
}

int add(int mId, int mGrade, char mGender[7], int mScore)
{
	int idx = mGrade * 2 + gender[mGender[0]] - 2;
	stu_score[idx].insert({ mScore, mId });
	stu_info[mId] = { mGrade, gender[mGender[0]], mScore };

	array<int, 2> ret = *stu_score[idx].rbegin();
	return ret[1];
}

int remove(int mId)
{
	if (stu_info.find(mId) == stu_info.end()) return 0;

	array<int, 3> cur = stu_info[mId];
	int idx = cur[0] * 2 + cur[1] - 2;

	stu_info.erase(mId);
	stu_score[idx].erase({ cur[2], mId });

	if (stu_score[idx].size() == 0) return 0;
	else
	{
		array<int, 2> ret = *stu_score[idx].begin();
		return ret[1];
	}
}

int query(int mGradeCnt, int mGrade[], int mGenderCnt, char mGender[][7], int mScore)
{
	array<int, 2> min_val = { 300001, 1000000001 };
	array<int, 2> temp = { 300001, 1000000001 };

	for (int i = 0; i < mGradeCnt; ++i)
	{
		for (int j = 0; j < mGenderCnt; ++j)
		{
			int idx = mGrade[i] * 2 + gender[mGender[j][0]] - 2;
			auto it = stu_score[idx].lower_bound({ mScore, -1 });
			if (it != stu_score[idx].end())
			{
				temp = *it;
				if (temp[0] < min_val[0]) min_val = temp;
				else if (temp[0] == min_val[0] && temp[1] < min_val[1]) min_val = temp;
			}
		}
	}

	if (temp[0] == 300001) return 0;
	else return min_val[1];
}

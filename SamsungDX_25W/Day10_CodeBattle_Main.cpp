#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define CMD_INIT 1
#define CMD_NUMBER_OF_CANDIDATE 2
#define CMD_MAX_AREA 3

extern void init(int N, int mMap[20][20]);
extern int numberOfCandidate(int M, int mStructure[5]);
extern int maxArea(int M, int mStructure[5], int mSeaLevel);

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

static int mMap[20][20];
static int mStructure[5];

static bool run()
{
	int numQuery;
	int N, M, mSeaLevel;
	int userAns, ans;

	bool isCorrect = false;

	scanf("%d", &numQuery);

	for (int i = 0; i < numQuery; ++i)
	{
		int cmd;
		scanf("%d", &cmd);

		switch (cmd)
		{
		case CMD_INIT:
			scanf("%d", &N);
			for (int j = 0; j < N; j++)
				for (int k = 0; k < N; k++)
					scanf("%d", &mMap[j][k]);
			init(N, mMap);
			isCorrect = true;
			break;
		case CMD_NUMBER_OF_CANDIDATE:
			scanf("%d", &M);
			for (int j = 0; j < M; j++)
				scanf("%d", &mStructure[j]);
			userAns = numberOfCandidate(M, mStructure);
			scanf("%d", &ans);
			if (userAns != ans)
			{
				isCorrect = false;
			}
			break;
		case CMD_MAX_AREA:
			scanf("%d", &M);
			for (int j = 0; j < M; j++)
				scanf("%d", &mStructure[j]);
			scanf("%d", &mSeaLevel);
			userAns = maxArea(M, mStructure, mSeaLevel);
			scanf("%d", &ans);
			if (userAns != ans)
			{
				isCorrect = false;
			}
			break;
		default:
			isCorrect = false;
			break;
		}
	}
	return isCorrect;
}

int main()
{
	setbuf(stdout, NULL);
	// freopen("sample_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++)
	{
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}

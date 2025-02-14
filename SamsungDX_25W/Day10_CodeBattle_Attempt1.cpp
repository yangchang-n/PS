////////// Main

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define CMD_INIT 1
#define CMD_NUMBER_OF_CANDIDATE 2
#define CMD_MAX_AREA 3

////////// User Code

#include <array>
#include <vector>
#include <queue>

using namespace std;

int n = 0, m = 0, sea_level;
int map_info[20][20];
int m_struct[5];
vector<array<int, 3>> struct_info(400, {0, 0, 0});

bool visited[20][20] = {false};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void init(int N, int mMap[20][20])
{
    n = N;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j) map_info[i][j] = mMap[i][j];
    }
    
    return;
}

int numberOfCandidate(int M, int mStructure[5])
{
    struct_info.clear();
    if (M == 1)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j) struct_info.push_back({i, j, 0});
        }
        
        return n * n;
    }
    
    m = M;
    for (int i = 0; i < m; ++i) m_struct[i] = mStructure[i];
    
    int cnt = 0, st_level;
    bool possible;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= n - m; ++j)
        {
            st_level = map_info[i][j] + m_struct[0];
            possible = true;

            for (int k = 1; k < m; ++k)
            {
                if (map_info[i][j + k] + m_struct[k] != st_level)
                {
                    possible = false;
                    break;
                }
            }

            if (possible)
            {
                cnt++;
                struct_info.push_back({i, j, 1});
            }
            else
            {
                st_level = map_info[i][j] + m_struct[m - 1];
                possible = true;
    
                for (int k = 1; k < m; ++k)
                {
                    if (map_info[i][j + k] + m_struct[m - 1 - k] != st_level)
                    {
                        possible = false;
                        break;
                    }
                }
                
                if (possible)
                {
                    cnt++;
                    struct_info.push_back({i, j, 2});
                }
            }
        }
    }

    for (int i = 0; i <= n - m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            st_level = map_info[i][j] + m_struct[0];
            possible = true;

            for (int k = 1; k < m; ++k)
            {
                if (map_info[i + k][j] + m_struct[k] != st_level)
                {
                    possible = false;
                    break;
                }
            }

            if (possible)
            {
                cnt++;
                struct_info.push_back({i, j, 3});
            }
            else
            {
                st_level = map_info[i][j] + m_struct[m - 1];
                possible = true;
    
                for (int k = 1; k < m; ++k)
                {
                    if (map_info[i + k][j] + m_struct[m - 1 - k] != st_level)
                    {
                        possible = false;
                        break;
                    }
                }
                
                if (possible)
                {
                    cnt++;
                    struct_info.push_back({i, j, 4});
                }
            }
        }
    }
    
	return cnt;
}

int area_bfs(int si, int sj, int sea_level)
{
    bool is_closed = true;
    int region = 0;
    queue<pair<int, int>> q;

    q.push({si, sj});
    visited[si][sj] = true;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        region++;

        if (x == 0 || x == n - 1 || y == 0 || y == n - 1)
		{
			is_closed = false;
			break;
		}
        
        for (int d = 0; d < 4; ++d)
        {
            int nx = x + dx[d], ny = y + dy[d];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
			{
				is_closed = false;
				break;
			}
            else if (!visited[nx][ny] && map_info[nx][ny] < sea_level)
            {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }

		if (!is_closed) break;
    }
    
    return is_closed ? region : 0;
}

int total_area(int m, int m_struct[5], array<int, 3> cur_struct, int sea_level)
{
    if (cur_struct[2] == 0) map_info[cur_struct[0]][cur_struct[1]] += m_struct[0];
    else if (cur_struct[2] == 1)
    {
        for (int i = 0; i < m; ++i) map_info[cur_struct[0]][cur_struct[1] + i] += m_struct[i];
    }
    else if (cur_struct[2] == 2)
    {
        for (int i = 0; i < m; ++i) map_info[cur_struct[0]][cur_struct[1] + i] += m_struct[m - 1 - i];
    }
    else if (cur_struct[2] == 3)
    {
        for (int i = 0; i < m; ++i) map_info[cur_struct[0] + i][cur_struct[1]] += m_struct[i];
    }
    else if (cur_struct[2] == 4)
    {
        for (int i = 0; i < m; ++i) map_info[cur_struct[0] + i][cur_struct[1]] += m_struct[m - 1 - i];
    }

    visited[20][20] = {false};
    int total = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (map_info[i][j] >= sea_level) total++;
            if (!visited[i][j] && map_info[i][j] < sea_level) total += area_bfs(i, j, sea_level);
        }
    }

    if (cur_struct[2] == 0) map_info[cur_struct[0]][cur_struct[1]] -= m_struct[0];
    else if (cur_struct[2] == 1)
    {
        for (int i = 0; i < m; ++i) map_info[cur_struct[0]][cur_struct[1] + i] -= m_struct[i];
    }
    else if (cur_struct[2] == 2)
    {
        for (int i = 0; i < m; ++i) map_info[cur_struct[0]][cur_struct[1] + i] -= m_struct[m - 1 - i];
    }
    else if (cur_struct[2] == 3)
    {
        for (int i = 0; i < m; ++i) map_info[cur_struct[0] + i][cur_struct[1]] -= m_struct[i];
    }
    else if (cur_struct[2] == 4)
    {
        for (int i = 0; i < m; ++i) map_info[cur_struct[0] + i][cur_struct[1]] -= m_struct[m - 1 - i];
    }
    
    return total;
}

int maxArea(int M, int mStructure[5], int mSeaLevel)
{
    if (numberOfCandidate(M, mStructure) == 0) return -1;
    // numberOfCandidate(M, mStructure);
    
    m = M, sea_level = mSeaLevel;
    for (int i = 0; i < m; ++i) m_struct[i] = mStructure[i];

    int area = 0, temp = 0;
    array<int, 3> cur_struct;
    // int cur_struct[3];
    while (!struct_info.empty())
    {
        cur_struct = struct_info.back();
        struct_info.pop_back();

        temp = total_area(m, m_struct, cur_struct, sea_level);
        if (temp > area) area = temp;
    }
    
	return area;
}

////////// Main

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

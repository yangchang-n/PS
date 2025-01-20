#define MAX_N 1000
#define MAX_M 20

using namespace std;

int wholeMap[MAX_N][MAX_N];
int wholeInfo[10000][2];
int pieceInfo[4][20][2];
int treasureInfo[4][2];

int wholeSize;
int pieceSize;
int treasureNum;

struct Result {
    int y, x;
};

void init(int N, int M, int Map[MAX_N][MAX_N])
{ 
    wholeSize = N;
    pieceSize = M;

    treasureNum = 0;

    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            if (Map[y][x] == 1)
            {
                wholeMap[y][x] = 1;
                wholeInfo[treasureNum][0] = y;
                wholeInfo[treasureNum][1] = x;
                treasureNum++;
            }
            else wholeMap[y][x] = 0;
        }
    }
}

Result findTreasureChest(int Pieces[MAX_M][MAX_M])
{
	Result res;
    res.y = res.x = 0;
    
    int check[2];
    int pieceInfoCnt = 0;
    
    bool found = false;
    bool possible = true;

    for (int y = 0; y < pieceSize; ++y)
    {
        for (int x = 0; x < pieceSize; ++x)
        {
            if (Pieces[y][x] == 1 || Pieces[y][x] == 9)
            {
                pieceInfo[0][pieceInfoCnt][0] = y;
                pieceInfo[0][pieceInfoCnt][1] = x;
                pieceInfo[1][pieceInfoCnt][0] = x;
                pieceInfo[1][pieceInfoCnt][1] = pieceSize - y - 1;
                pieceInfo[2][pieceInfoCnt][0] = pieceSize - y - 1;
                pieceInfo[2][pieceInfoCnt][1] = pieceSize - x - 1;
                pieceInfo[3][pieceInfoCnt][0] = pieceSize - x - 1;
                pieceInfo[3][pieceInfoCnt][1] = y;
                pieceInfoCnt++;
            }
            if (Pieces[y][x] == 9)
            {
                treasureInfo[0][0] = y;
                treasureInfo[0][1] = x;
                treasureInfo[1][0] = x;
                treasureInfo[1][1] = pieceSize - y - 1;
                treasureInfo[2][0] = pieceSize - y - 1;
                treasureInfo[2][1] = pieceSize - x - 1;
                treasureInfo[3][0] = pieceSize - x - 1;
                treasureInfo[3][1] = y;
            }
        }
    }

    for (int r = 0; r < 4; ++r)
    {
        for (int w = 0; w < treasureNum; ++w)
        {
            possible = true;
            
            for (int p = 1; p < pieceInfoCnt; ++p)
            {
                check[0] = wholeInfo[w][0] + pieceInfo[r][p][0] - pieceInfo[r][0][0];
                check[1] = wholeInfo[w][1] + pieceInfo[r][p][1] - pieceInfo[r][0][1];

                if (check[0] < 0 || check[0] >= wholeSize || check[1] < 0 || check[1] >= wholeSize)
                {
                    possible = false;
                    break;
                }
                
                if (wholeMap[check[0]][check[1]] != 1)
                {
                    possible = false;
                    break;
                }
            }

            if (possible)
            {
                found = true;
                res.y = wholeInfo[w][0] + treasureInfo[r][0] - pieceInfo[r][0][0];
                res.x = wholeInfo[w][1] + treasureInfo[r][1] - pieceInfo[r][0][1];
                break;
            }
        }

        if (found) break;
    }

	return res;
}

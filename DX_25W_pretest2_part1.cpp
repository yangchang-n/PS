#include <iostream>
#include <vector>

using namespace std;

const int dx[] = {1, 0, 1, 1};
const int dy[] = {0, 1, 1, -1};

bool inBounds(int x, int y, int W, int H)
{
    return x >= 0 && x < W && y >= 0 && y < H;
}

int dfs(int x, int y, const vector<vector<int>> &board, vector<vector<int>> &visited, int playerNum, int dir)
{
    int W = board[0].size();
    int H = board.size();
    
    int count = 1;
    visited[y][x] = 1;
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if (inBounds(nx, ny, W, H) && !visited[ny][nx] && board[ny][nx] == playerNum)
    {
        count += dfs(nx, ny, board, visited, playerNum, dir);
    }

    return count;
}

vector<vector<int>> findBlocks(const vector<vector<int>> &board)
{
    int W = board[0].size();
    int H = board.size();
    vector<vector<int>> result(H, vector<int>(W, 0));
    vector<vector<int>> visited(H, vector<int>(W, 0));

    for (int y = 0; y < H; ++y)
    {
        for (int x = 0; x < W; ++x)
        {
            if (board[y][x] != 0)
            {
                for (int dir = 0; dir < 4; ++dir)
                {
                    fill(visited.begin(), visited.end(), vector<int>(W, 0));

                    if (dfs(x, y, board, visited, board[y][x], dir) >= 5)
                    {
                        for (int vy = 0; vy < H; ++vy)
                        {
                            for (int vx = 0; vx < W; ++vx)
                            {
                                if (visited[vy][vx])
                                {
                                    result[vy][vx] = board[y][x];
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return result;
}

int main()
{
    int W, H;
    cin >> W >> H;
    vector<vector<int>> board(H, vector<int>(W));

    for (int y = 0; y < H; ++y)
    {
        for (int x = 0; x < W; ++x)
        {
            cin >> board[y][x];
        }
    }

    vector<vector<int>> result = findBlocks(board);

    cout << "결과 게임판 :" << endl;
    for (int y = 0; y < H; ++y)
    {
        for (int x = 0; x < W; ++x)
        {
            cout << result[y][x] << " ";
        }
        cout << endl;
    }

    int totalBlocks = 0;
    int playerOneBlocks = 0;
    int playerTwoBlocks = 0;
    for (const auto &row : result)
    {
        for (int cell : row)
        {
            if (cell != 0)
            {
                totalBlocks++;
                if (cell == 1) playerOneBlocks++;
                else if (cell == 2) playerTwoBlocks++;
            }
        }
    }

    cout << "성공한 블럭의 총 개수 : " << totalBlocks << endl;
    cout << "플레이어 1의 성공 개수 : " << playerOneBlocks << endl;
    cout << "플레이어 2의 성공 개수 : " << playerTwoBlocks << endl;

    return 0;
}

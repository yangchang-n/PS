#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board = {
    {0, 1, 0, 2},
    {1, 2, 1, 2},
    {2, 2, 2, 2},
    {1, 2, 2, 1}
};

vector<vector<int>> updateBoard(vector<vector<int>> &board, const vector<vector<int>> &result)
{
    int W = board[0].size();
    int H = board.size();

    for (int y = 0; y < H; ++y)
    {
        for (int x = 0; x < W; ++x)
        {
            if (result[y][x] == 1 || result[y][x] == 2)
            {
                board[y][x] = 0;
            }
        }
    }

    for (int x = 0; x < W; ++x)
    {
        int temp = H - 1;
        
        for (int y = H - 1; y >= 0; --y)
        {
            if (board[y][x] != 0)
            {
                board[temp][x] = board[y][x];
                --temp;
            }
        }

        for (int y = temp; y >= 0; --y)
        {
            board[y][x] = 0;
        }
    }

    return board;
}

int main()
{

    vector<vector<int>> result = {
        {0, 0, 0, 2},
        {0, 2, 1, 2},
        {0, 2, 0, 2},
        {1, 2, 0, 0}
    };

    vector<vector<int>> updatedBoard = updateBoard(board, result);

    for (const auto& row : updatedBoard)
    {
        for (int cell : row)
        {
            cout << cell;
        }
        cout << endl;
    }

    return 0;
}

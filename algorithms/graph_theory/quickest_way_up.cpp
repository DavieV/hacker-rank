#include <iostream>
#include <vector>
#include <queue>
#include <utility>

int priority(int, int*);
int my_abs(int);
int search(int*);

bool operator <(std::pair<int, int> p1, std::pair<int, int> p2) {
    return p1.first < p2.first;
}

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        int board[100];
        for (int j = 0; j < 100; ++j) {
            board[j] = -1;
        };

        // Read in the ladders
        int n;
        std::cin >> n;
        for (int j = 0; j < n; ++j) {
            int start, end;
            std::cin >> start >> end;
            board[start-1] = end - 1;
        }

        // Read in the snakes
        int m;
        std::cin >> m;
        for (int j = 0; j < m; ++j) {
            int start, end;
            std::cin >> start >> end;
            board[start-1] = end - 1;
        }

        std::cout << search(board) << std::endl;
    }

    return 0;
}

int priority(int pos, int* board) {
    return my_abs(pos - board[pos]) + pos;
}

int my_abs(int a) {
    return (a > 0) ? a : -a;
}

int search(int* board) {
    std::queue< std::pair<int, int> > q;
    bool visited[100] = {0};
    visited[0] = true;
    std::pair<int, int> pos = {0, 0};
    q.push(pos);

    while (!q.empty()) {
        pos = q.front();

        if (pos.first == 99)
            break;

        for (int i = pos.first + 1; i <= (pos.first + 6) && i < 100; ++i) {
            if (!visited[i]) {
                visited[i] = true;
                std::pair<int, int> new_pos;

                if (board[i] != -1)
                    new_pos = std::make_pair(board[i], pos.second + 1);
                else
                    new_pos = std::make_pair(i, pos.second + 1);

                q.push(new_pos);
            }
        }

        q.pop();
    }

    if (pos.first == 99)
        return pos.second;
    else
        return -1;
}

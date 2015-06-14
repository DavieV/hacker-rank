#include <iostream>

// even row map = {0, 2, 4, 6, 8} (last digit)
// odd row map  = {1, 3, 5, 7, 9} (last digit)

long grid_value(long, long);

int main() {
    long r, c;
    std::cin >> r >> c;
    std::cout << grid_value(r, c) << std::endl;
    return 0;
}

long grid_value(long r, long c) {
    --r; // for indexing purposes
    --c;
    int even[5] = {0, 2, 4, 6, 8};
    int odd[5] = {1, 3, 5, 7, 9};

    if (r % 2 == 0)
        return ((r / 2) * 10) + even[c];
    else
        return ((r / 2) * 10) + odd[c];
}

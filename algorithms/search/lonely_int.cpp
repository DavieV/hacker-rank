#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> ints;
  std::copy(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(),
            std::back_inserter(ints));
  auto lonely = std::accumulate(ints.begin() + 1, ints.end(), *ints.begin(),
                                std::bit_xor<int>());
  std::cout << lonely << std::endl;
}

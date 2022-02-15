#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int islandPerimeter(vector<vector<int>> &grid) {
    // FIXME
    return 0;
  }
};

void TestIslandPerimeter() {
  Solution s;
  {
    vector<vector<int>> grid{{0, 1, 0, 0},
                             {1, 1, 1, 0},
                             {0, 1, 0, 0},
                             {1, 1, 0, 0}};
    assert(16 == s.islandPerimeter(grid));
  }
  {
    vector<vector<int>> grid{1};
    assert(4 == s.islandPerimeter(grid));
  }
  {
    vector<vector<int>> grid{{1, 0}};
    assert(4 == s.islandPerimeter(grid));
  }
}

int main() {
  TestIslandPerimeter();
  std::cout << "Ok!" << std::endl;
  return 0;
}

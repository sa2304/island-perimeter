#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int islandPerimeter(vector<vector<int>>& grid) {
    int perimeter = 0;
    for (int row = 0; row < grid.size(); ++row) {
      for (int col = 0; col < grid[row].size(); ++col) {
        const bool is_water = (0 == grid[row][col]);

        const bool upper_is_water = (0 == row) or (0 == grid[row - 1][col]);
        if ( (is_water and not upper_is_water)
            or (not is_water and upper_is_water) )
        { ++perimeter; }

        const bool left_is_water = (0 == col) or (0 == grid[row][col - 1]);
        if ( (is_water and not left_is_water)
            or (not is_water and left_is_water) )
        { ++perimeter; }
      }
      // if rightmost cell is land
      perimeter += grid[row].back();
    }
    const auto& bottom_line = grid.back();
    for (const auto& cell: bottom_line) {
      perimeter += cell;
    }

    return perimeter;
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
    vector<vector<int>> grid{{1}};
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

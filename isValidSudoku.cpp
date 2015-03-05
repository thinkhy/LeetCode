#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits>
#include <utility>
#include <cstdio>
using namespace std;

/*******************************
 *["..4...63.",
   ".........",
   "5......9.",
   "...56....",
   "4.3.....1",
   "...7.....",
   "...5.....",
   ".........",
   "........."]
 *******************************/

class Solution {
public:
    bool isValidSudoku(vector< vector<char> > &board) {
        unordered_set<char> nums;

        // determine by row
        for(int i = 0; i < 9; i++) {
            nums.clear();
            for(int j = 0; j < 9; j++) {
                char cur = board[i][j];
                if(cur == '.') continue;
                if(cur > '9' || cur < '1' || nums.count(cur) == 1)
                    return false;
                else
                    nums.insert(cur);
            }
        }

        // determine by column
        for(int i = 0; i < 9; i++) {
            nums.clear();
            for(int j = 0; j < 9; j++) {
                char cur = board[j][i];
                if(cur == '.') continue;
                if(cur > '9' || cur < '1' || nums.count(cur) == 1)
                    return false;
                else
                    nums.insert(cur);
            }
        }
        
        // determine by 9 cells
        for(int i = 0; i < 9; i += 3)
            for(int j = 0; j < 9; j += 3) {
                nums.clear();
                for(int k = 0; k < 3; k++)
                    for(int h = 0; h < 3; h++) {
                        char cur = board[i+k][j+h];
                        if(cur == '.') continue;
                        if(cur > '9' || cur < '1' || nums.count(cur) == 1)
                            return false;
                        else
                            nums.insert(cur);
                    }
            }
        
       return true; 
    }
};


int main() {
    Solution s;
    
    /*
    char* mapstr[] ={"0.4...63.",
                     ".........",
                     "5......9.",
                     "...36....",
                     "4.3.....1",
                     "...7.....",
                     "...5.....",
                     ".........",
                     "........."};
    */

    char* mapstr[] ={".........",
                     ".........",
                     ".........",
                     ".........",
                     ".........",
                     ".........",
                     ".........",
                     ".........",
                     "........."};

    vector< vector<char> > m(9);

    for(int i = 0; i < 9; i++) {
        m[i].resize(9);
        for(int j = 0; j < 9; j++) {
            m[i][j] = mapstr[i][j];
        }
    }
    cout << s.isValidSudoku(m) << endl;
    
    return 0;
}






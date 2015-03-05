#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits>
#include <utility>
#include <cstring>
using namespace std;

#define DE(a) cout << #a << ": " << a << endl;

/*******************************************************************************************************************
 *
 * Maximum Product Subarray
 *
 * Find the contiguous subarray within an array (containing at least one number) which has the largest product.
 * 
 * For example, given the array [2,3,-2,4],
 *   the contiguous subarray [2,3] has the largest product = 6.
 *
 ************************************************************************************************************************/
class Solution {
public:
    int maxProduct(int a[], int n) {
        int result, min_product, max_product;
        result = INT_MIN;
        min_product = max_product = 1;

        /**
         * 2 * 3: 3, 6
         * 2, 3, -2: -12, -2 
         * 2,3,-2,-3: -3, 36
         * 2,3,-2,-3,-2: -72, 6
         */
        for(int i = 0; i < n; i++) {        
            int last_min = min_product;
            int last_max = max_product;

            if(a[i] > 0) {
                if(last_min <= 0) {
                    if(max_product <= 0)
                        max_product = a[i];
                    else
                        max_product = last_max * a[i];
                    min_product = last_min * a[i];
                }
                else {
                    max_product *= a[i];

                    if(last_min < 0)
                        min_product = last_min * a[i];
                    else 
                        min_product = a[i];
                }
            }
            else if(a[i] < 0) {
                if(min_product <= 0) {
                    max_product = a[i] * last_min;
                    if(last_max > 0)
                        min_product = last_max * a[i];
                    else
                        min_product = a[i];
                }
                else {
                    max_product = a[i];
                    min_product = last_max * a[i];
                }
            }
            else { // a[i] == 0 
                min_product = max_product = 0;
            }

            // cout << a[i] << ": " << min_product << " " << max_product << endl;
            result = max_product>result ? max_product : result;
        }

        return result;
    }
};

int main() {
    Solution s;
        
    int a[] = {2,-5,-2,-4,3};
    DE(s.maxProduct(a, sizeof(a)/sizeof(*a)));
        
    return 0;
}







#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <memory>
#include <limits>
#include <utility>
#include <cstdio>
#include <cstring>
#include <climits>      // for INT_MAX
using namespace std;

#define DE(a) cout << #a << ": " << (a) << endl;
#define EXPECT(a, b) cout << #a << ": result: " << (a) \
                                << "  expect: " << (b) << endl;

/*********************************************************************************************
 *
 * Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
 *
 * You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.
 * 
 * Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
 * 
 * For the last line of text, it should be left justified and no extra space is inserted between words.
 * 
 * For example,
 *   words: ["This", "is", "an", "example", "of", "text", "justification."]
 * L: 16.
 * 
 * Return the formatted lines as:
 * [       1234  1234
 *    "This    is    an",
 *     
 *    "example  of text",
 *    "justification.  "
 *                   12
 * ]
 * Note: Each word is guaranteed not to exceed L in length.
 * 
 * Corner Cases:
 *   A line other than the last line might contain only one word. What should you do in this case?
 *   In this case, that line should be left-justified.
 *
 *********************************************************************************************/
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int line_length) {
         vector<string>   res;
        /****************************************************************************************
         *
         * Contraints
         *
         *  1> pack as many words as you can in each line.
         *  2> Pad extra spaces ' ' when necessary so that each line has exactly L characters.
         *  3> If the number of spaces on a line do not divide evenly between words,
         *  the empty slots on the left will be assigned more spaces than the slots on the right.
         *  4> For the last line of text, it should be left justified and no extra space is inserted between words.
         *
         *****************************************************************************************/

        /* 
         * A line other than the last line might contain only one word. What should you do in this case?
         *   In this case, that line should be left-justified.
         *
         */
         int end = 0;
         while (end < words.size()) {
             string line;
             int cnt = 0;
             int start = end;

             // Each word is guaranteed not to exceed L in length.
             // so move forward to match up more words
             while (end < words.size() 
                     && cnt + (end-start) + words[end].size() <= line_length) {
                cnt += words[end].size(); 
                end++; 
             }

             int space_num = line_length - cnt;
             line = words[start];
             if(end - start > 1) {
                 // multiple words in a line
                 if(end < words.size()) {
                     // divide space evenly into words
                     int divided_space_num = space_num/(end-start-1);
                     int left_space_num = space_num%(end-start-1);
                     for(int k = start+1; k < end; k++) { 
                       line.insert(line.end(), divided_space_num, ' ');
                       if(k-start<=left_space_num)
                           line.insert(line.end(), ' ');
                       line += words[k];
                     }
                 }
                 // reach the last line
                 else {
                     for(int k = start+1; k < end; k++) { 
                         line.insert(line.end(), ' ');
                         line += words[k];
                     }
                     line.insert(line.end(), space_num-(end-start-1), ' ');
                 }
             }
             else  {
                 // only one word in a line
                 line.insert(line.end(), space_num, ' ');
             }

             res.push_back(line);
         }


         return res;
    }
};

int main() {
    Solution slt;

    vector<string> words = { "This", "is", "an", "example",
                             "of", "text", "justification." };
    int l = 16;
 
    vector<string> res = slt.fullJustify(words, l);

    EXPECT(res.size()>0, true);
    DE(res[0]);
    EXPECT(res[0] == "This    is    an", true);
    DE(res[1]);
    EXPECT(res[1] == "example  of text", true);
    DE(res[2]);
    EXPECT(res[2] == "justification.  ", true);

    cout << endl;
    /*
     * Corner Cases:
     *   A line other than the last line might contain only one word.
     *   What should you do in this case?
     *   In this case, that line should be left-justified.
     */
    words = { "This", "is", "an", "example",
              "TTTTTTTTTTTTTT",
              "ofFF", "text", "justification." };
    res = slt.fullJustify(words, l);
    for(int i = 0; i < res.size(); i++) {
        cout << "\"" << res[i] << "\"" << endl;
    }
    cout << endl;
    
    words = {"What","must","be","shall","be."};
    res = slt.fullJustify(words, 12);
    for(int i = 0; i < res.size(); i++) {
        cout << "\"" << res[i] << "\"" << endl;
    }

    return 0;
} 



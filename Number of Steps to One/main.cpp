#include <string>
class Solution {
public:
    int numSteps(std::string s) {
        int steps = 0;
        bool was_one = false;
        for(int i = s.size()-1; i>0 ;i--){
            steps += (s[i]=='1')!=was_one? 2 : 1;
            was_one = was_one || (s[i]=='1');
        }
        return steps + was_one;
    }
};
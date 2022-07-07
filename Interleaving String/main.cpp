#include <vector>
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size() + 1, l2 = s2.size() + 1;
        if(s1.size() + s2.size() != s3.size())return false;
        std::vector< std::vector< bool > > matrix (l1, vector< bool >(l2, false));
        
        matrix[0][0] = true;
        for(int i = 1; i < l1; i++)
            if(matrix[i-1][0] && s3[i-1] == s1[i-1])
                matrix[i][0]=true;
        for(int j = 1; j < l2; j++)
            if(matrix[0][j-1] && s3[j-1] == s2[j-1])
                matrix[0][j]=true;
        for(int i = 1; i < l1; i++)
            for(int j = 1; j < l2; j++){
                if(matrix[i-1][j] && s3[i+j-1] == s1[i-1])
                    matrix[i][j]=true;
                if(matrix[i][j-1] && s3[i+j-1] == s2[j-1])
                    matrix[i][j]=true;
            }
        
        return matrix[l1-1][l2-1];
    }
};
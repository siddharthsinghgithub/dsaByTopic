class Solution {
public:
    vector< vector<string>> M = {
        {"a"},
        {"a"},
        {"a", "b" ,"c"},
        {"d", "e" ,"f"},
        {"g", "h" ,"i"},
        {"j", "k" ,"l"},
        {"m", "n" ,"o"},
        {"p", "q" ,"r","s"},
        {"t" ,"u" , "v"},
        {"w", "x" ,"y","z"},
    };
    
    vector<string> letterCombinations(string A) {

        if(A.size() == 1)
            return M[ int(A[0] - '0')];
        
        vector<string> V = letterCombinations(string(A.begin() + 1 , A.end()) )
        for(int i =0; i < A.size();i++){
            for(int j =0; i < V.size();i++){
                V[j]=A[i]+V[j];
            }
        }
        
        return V;
    }
};
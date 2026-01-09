class Solution {
public:
    string convert(string s, int nr) {

        if(nr == 1) return s;

        int n = s.size();

        vector<vector<char>> matrix(nr, vector<char>(n,' '));

        int r = 0;
        int c = 0;
        int i = 0;

        while(i < n){

            while(r< nr && i <n){
                
                matrix[r][c] = s[i];
                i++;
                r++;
            }

            r = r-2;
            c = c+1;

            while(i<n && r>0 ){
                matrix[r][c] = s[i];
                r--;
                c++;
                
                i++;
            }


        }

        string ans  = "";

        for(int i = 0 ; i < nr; i++){
            for(int j  = 0 ; j < n; j++){
                if(matrix[i][j] != ' '){
                    ans.push_back(matrix[i][j]);
                }
            }
        }

        return ans;
        
    }
};
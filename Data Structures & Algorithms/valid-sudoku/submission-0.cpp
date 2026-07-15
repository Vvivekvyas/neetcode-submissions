class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>>row(9);
         vector<unordered_set<char>>col(9);
          vector<unordered_set<char>>boxes(9);

        for(int i=0 ; i<9 ; i++){
            for(int j=0 ; j<9 ; j++){

                char ch = board[i][j];
                if(ch == '.') continue;
                int boxidx = (i/3)*3 + (j/3); // to find which box it is

                if(row[i].count(ch) || col[j].count(ch) || boxes[boxidx].count(ch)){
                    return false;
                }
                else{
                    row[i].insert(ch);
                    col[j].insert(ch);
                    boxes[boxidx].insert(ch);
                }
            }
        } 
        return true; 
    }
};

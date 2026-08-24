class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>>row(9);
        vector<unordered_set<int>>col(9);
        vector<unordered_set<int>>box(9);

        for(int i=0 ; i<9 ; i++){
            for(int j=0 ; j<9 ; j++){

                char ch = board[i][j];
                if(ch == '.') continue;
                int boxid = (i/3)*3 + (j/3);

                if(row[i].count(ch) || col[j].count(ch) || box[boxid].count(ch)){
                    return false;
                }
                else{
                    row[i].insert(ch);
                    col[j].insert(ch);
                    box[boxid].insert(ch);
                }
            }
        }
        return true;
    }
};

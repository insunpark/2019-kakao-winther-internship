#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    vector <int> temp;
    int ttt = 0;
    int answer = 0;
    for (int i = 0; i < moves.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[j][moves[i]-1] != 0) {
                ttt = board[j][moves[i] - 1];
                board[j][moves[i] - 1] = 0;
                if (temp.size() >= 1) {
                    if (temp.back() == ttt) {
                        temp.pop_back();
                        answer += 2;
                    }
                    else {
                        temp.push_back(ttt);
                    }
                }
                else {
                    temp.push_back(ttt);
                }
                break;
            }
        }
    }
    return answer;
}

int main() {
    int value = 0;
    vector<vector<int> > arr({
        vector<int>({ 0, 0, 0, 0, 0 }),
        vector<int>({ 0, 0, 1, 0, 3 }),
        vector<int>({ 0, 2, 5, 0, 1 }),
        vector<int>({ 4, 2, 4, 4, 2 }),
        vector<int>({ 3, 5, 1, 3, 1 }),        
        });
    
    vector<int> arr2({ 1,5,3,5,1,2,1,4 });

    value = solution(arr, arr2); 

    cout << value << endl;

   
}
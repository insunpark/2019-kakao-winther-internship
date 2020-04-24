#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

bool visited[1 << 8];

bool isPossible(string a, string b) {
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); i++) {
        if (!(a[i] == b[i] || a[i] == '*' || b[i] == '*')) return false;
    }
    return true;
}

void dfs(int bannedIdx, int N, int bits, const vector<vector<int>>& v) {
    cout << bannedIdx << " " << bitset<8>(bits) << " ";
    if (bannedIdx == N) {
        visited[bits] = true;
        return;
    }
    for (auto next : v[bannedIdx]) {        
        if (bits & (1 << next)) {             
            continue; 
        }
        dfs(bannedIdx + 1, N, bits | (1 << next), v);
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    vector<vector<int>> temp(banned_id.size());    

    for (int i = 0; i < banned_id.size(); i++) {
        string bannedid = banned_id[i];
        for (int j = 0; j < user_id.size(); j++) {
            string userid = user_id[j];
            if (isPossible(userid, bannedid)) {
                temp[i].push_back(j);
            }
        }
    }

    for (auto tt : temp) {
        for (int i = 0; i < tt.size(); i++) {
            cout << tt[i] << " ";
        }
         cout << endl;
    }

    dfs(0, banned_id.size(), 0, temp);
    for (int i = 0; i < (1 << 8); i++) {
        if (visited[i]) answer++;
    }
    return answer;
}

int main() {
    vector <string> temp{ "frodo", "fradi", "crodo", "abc123", "frodoc" };
    vector <string> temp2{ "*rodo", "*rodo", "******" };
    
    int value = 0;
    
 /*   for (auto next : visited) {
        cout << next << " ";
    }

    cout << endl;
    */
    value = solution(temp, temp2);
    
/*    unsigned int a = 1;
    for (auto next : visited) {
        cout << bitset<8>(a) << " " << next << " ";
        a++;
    }
*/
    cout << endl;

    cout << value << endl;

    return 0;
}
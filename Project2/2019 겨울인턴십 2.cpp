#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> temp;

    for (int i = 1; i < s.size()-1; i++) {
        int sum = 0;
        if (s[i] == '{') {
            int idx = i + 1;
            for (int j = i+1; j<s.size(); j++) {
                if (s[j] == ',')
                {
                    sum += (stoi(s.substr(idx, j - idx)));
                    idx = j + 1;
                }
                if (s[j] == '}') {
                    sum += (stoi(s.substr(idx, j - idx)));
                    idx = j + 1;
                    break;
                }
            }
            temp.push_back(sum);
        }
    }
    sort(temp.begin(), temp.end());
    answer.push_back(temp[0]);
    for (int i = 1; i < temp.size(); i++) {
        answer.push_back(temp[i] - temp[i - 1]);
    }
    return answer;
}

int main() {
    string ex = "{{4,2,3},{3},{2,3,4,1},{2,3}}";

    vector<int> value;

    value = solution(ex);

    for (int i = 0; i < value.size(); i++) {
        cout << value[i] << ",";
    }

    return 0;
}
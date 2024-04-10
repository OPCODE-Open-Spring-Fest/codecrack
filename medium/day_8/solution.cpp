//Write your code here
#include <iostream>
#include <string>

using namespace std;

string func(const string& s) {
    int n = s.length();
    int max_length = 0;
    int max_index = -1;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int length = 0;
            while (j + length < n && s[i + length] == s[j + length]) {
                ++length;
            }
            if (length > max_length) {
                max_length = length;
                max_index = i;
            }
        }
    }

    if (max_length == 0) {
        return "-1";
    } else {
        return s.substr(max_index, max_length);
    }
}

int main() {
    string s;
    cin>>s;

    string result = func(s);
    cout << result << endl;

    return 0;
}


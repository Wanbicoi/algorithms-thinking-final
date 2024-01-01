#include <bits/stdc++.h>
using namespace std;

std::vector<int> getFailureArray(const std::string &pattern) {
    int pattern_length = pattern.size();
    std::vector<int> failure(pattern_length + 1);
    failure[0] = -1;
    int j = -1;

    for (int i = 0; i < pattern_length; i++) {
        while (j != -1 && pattern[j] != pattern[i]) {
            j = failure[j];
        }
        j++;
        failure[i + 1] = j;
    }
    return failure;
}

std::vector<int> failure;
int kmp(const std::string &pattern, const std::string &text, int start_pos) {
    int text_length = text.size(), pattern_length = pattern.size();

    int k = 0;
    for (int j = start_pos; j < text_length; j++) {
        while (k != -1 && pattern[k] != text[j]) {
            k = failure[k];
        }
        k++;
        if (k == pattern_length)
            return j - k + 1;
    }
    return -1;
}
int main() {
    std::string text = "Aaaaa";
    std::string pattern = "aa";
    failure = getFailureArray(pattern);

    int pos = 0;
    while((pos = kmp(pattern, text, pos)) > -1) {
        cout << pos << " " ;
        pos++;
    }
    cout << endl;
    return 0;
}

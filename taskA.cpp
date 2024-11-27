#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

void extractHashtags(const string& text) {
    stringstream ss(text); 
    string word;
    unordered_map<string, int> hashtag_count; 

    while (ss >> word) {
        if (word[0] == '#' && word.length() > 1) {
            bool is_valid = true;

            for (int i = 1; i < word.length(); ++i) {
                if (!isalnum(word[i])) {
                    is_valid = false;
                    break;
                }
            }

            if (is_valid) {
                hashtag_count[word]++;
            }
        }
    }

    cout << hashtag_count.size() << endl;

    for (const auto& entry : hashtag_count) {
        cout << entry.first << " " << entry.second << endl;
    }
}

int main() {
    string text = "have brought #peace #freedom #justice and #security to my new empire";
    extractHashtags(text); 
    return 0;
}

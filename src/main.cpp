#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<string> parseTags(const string& input) {
    vector<string> tags;
    stringstream ss(input);
    string tag;

    while (ss >> tag) {
        tags.push_back(tag);
    }
    return tags;
}

bool validateHTML(const vector<string>& tags) {
    stack<string> tagStack;

    for (const string& tag : tags) {
        if (tag[0] == '<' && tag[1] != '/') {
            // Opening tag - remove <>
            string tagName = tag.substr(1, tag.length() - 2);
            tagStack.push(tagName);
        }
        else if (tag[0] == '<' && tag[1] == '/') {
            // Closing tag
            if (tagStack.empty()) return false;

            string tagName = tag.substr(2, tag.length() - 3);
            if (tagStack.top() == tagName) {
                tagStack.pop();
            } else {
                return false;
            }
        }
    }

    return tagStack.empty();
}

int main() {
    string input1 = "<div> <p> </p> </div>";
    string input2 = "<div> <p> </div> </p>";

    vector<string> tags1 = parseTags(input1);
    vector<string> tags2 = parseTags(input2);

    cout << "Input 1: " << input1 << endl;
    cout << "Result: " << (validateHTML(tags1) ? "YES" : "NO") << endl;

    cout << "\nInput 2: " << input2 << endl;
    cout << "Result: " << (validateHTML(tags2) ? "YES" : "NO") << endl;

    return 0;
}

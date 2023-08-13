#include <iostream>
#include <stack>
#include <string>

using namespace std;

string removeConsecutiveDuplicates(const string& input) {
    stack<char> charStack;
    string result;

    for (char ch : input) {
        if (charStack.empty() || ch != charStack.top()) {
            charStack.push(ch);
            result += ch;
        }
    }

    return result;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    string result = removeConsecutiveDuplicates(input);

    cout << "String after removing consecutive duplicates: " << result << endl;

    return 0;
}


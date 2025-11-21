//concatenation
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    string result = str1 + str2;
    cout << "Concatenated string: " << result << endl;
    return 0;
}
//reverse
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    reverse(str.begin(), str.end());
    cout << "Reversed string: " << str << endl;
    return 0;
}
//vowels deletion
#include <iostream>
#include <string>
using namespace std;

bool isVowel(char ch) {
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main() {
    string str, result = "";
    cout << "Enter a string: ";
    cin >> str;

    for (char ch : str) {
        if (!isVowel(ch))
            result += ch;
    }

    cout << "String after removing vowels: " << result << endl;
    return 0;
}
//string sort
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<string> words = {"apple", "orange", "banana", "grape"};
    sort(words.begin(), words.end());

    cout << "Sorted strings:\n";
    for (const auto& word : words)
        cout << word << endl;
    return 0;
}
//character conversion
#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char ch;
    cout << "Enter uppercase character: ";
    cin >> ch;

    if (isupper(ch))
        cout << "Lowercase: " << char(tolower(ch)) << endl;
    else
        cout << "Character is not uppercase.\n";

    return 0;
}



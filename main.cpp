#include <iostream>
#include "String.h"

using namespace std;

int main() {
    char* string = "test 56 56";
    String newString = String(string);

    String newString2 = String(newString);
    cout << newString2.toString() << endl;

    newString2.concatStringIn(3, "kek");
    cout << newString2.toString() << endl;

    String seekString = String("kek");
    cout << newString2.seek("kek") << endl;

    cout << newString2 << endl;
    cin >> string;
    cout << endl;
    cout << string;
}
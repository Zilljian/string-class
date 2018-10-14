#include <iostream>
#include "String.h"

using namespace std;

int main() {
    char* string = "test 56 56";
    String newString = String(string);

    cout << newString.toString() << ' ' << newString.seek(string)
    << ' ' << newString.getSubstring(0,3).toString() << endl;


    String newString2 = String(newString);
    cout << newString2.toString() << endl;

    newString2.concatString("lol");
    cout << newString2.toString() << endl;

    newString2.concatStringIn(3, "kek");
    cout << newString2.toString() << endl;

    String newString3 = String(newString, newString2);
    cout << newString3.toString();
}
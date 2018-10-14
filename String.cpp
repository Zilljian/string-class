#include "String.h"

String::String (char* initString) : string(), length(0) {
    initVector(initString);
    getLength();
}

String::String (String firstString, String secondString) : string(), length(0) {
    initVector(firstString.toString());
    concatString(secondString);
    getLength();
}

String::String () : string(), length(0) {
    getLength();
}


void String::concatString(char* newString) {
    for (long i = 0; i < newString[i] != '\0'; i++) {
        this->string.push_back(newString[i]);
    }
    getLength();
}

void String::concatString(String newString) {
    //char* tempString = newString.toString();
    concatString(newString.toString());
}

void String::concatStringIn(long index, char* newString) {
    for (int i = 0; i < newString[i] != '\0'; i++) {
        this->string.insert(string.begin() + i + index, newString[i]);
    }
    getLength();
}

void String::concatStringIn(long index, String newString) {
    concatStringIn(index, newString.toString());
}

bool String::seek(char* subString) {
    bool isSought = false;

    for (auto item : string){
        for (long i = 0; subString[i] != '\0'; i++ ){
            if (!item == subString[i]){
                isSought = false;
                break;
            }
            isSought = true;
        }
        if (isSought) break;
    }

    return isSought;
}

bool String::seek(String subString) {
    seek(subString.toString());
}

String String::getSubstring(long begin, long end) {
    char* tempString = new (char);

    if (begin == end) return String (&string[begin]);

    for (long i = begin; i <= end; i++) {
        tempString[i] = string[i];
    }

    return String (tempString);
}

char* String::toString() {
    stringBuilder();
    return toStringVar;
}

void String::initVector(char* initString) {
   for (long i = 0; i < initString[i] != '\0'; i++) {
       this->string.push_back(initString[i]);
   }
}

void String::getLength() {
    length = string.size();
}

void String::stringBuilder() {
    toStringVar = new (char);
    for (int i = 0; i < length; i++) {
        toStringVar[i] = string[i];
    }
}

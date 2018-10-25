#include "String.h"

String::String (char* initString) : string(), length(0) {
    initVector(initString);
    getLength();
    stringBuilder();
}

String::String (String firstString, String secondString) : string(), length(0) {
    initVector(firstString.toString());
    concatString(secondString);
    getLength();
    stringBuilder();
}

String::String () : string(), length(0) {
    getLength();
    stringBuilder();
}


String String::operator + (String addend) {
    return String(*(this), addend);
}

bool String::operator < (String rightExpr) {
    return length < rightExpr.size();
}

bool String::operator > (String rightExpr) {
    return length > rightExpr.size();
}

bool String::operator == (String rightExpr) {
    if (rightExpr.size() == length){
        if (rightExpr.seek(*(this)) == 0) return true;
    }
    return false;
}

String& String::operator = (String rightExpr) {
    initVector(rightExpr.toString());
    getLength();
    return *this;
}

std::istream& operator >> (std::istream& in, String& initString) {
    char buffer;
    in.get(buffer);
    if (buffer != '\n') {
        initString.string.erase(initString.string.begin(), initString.string.end());
        initString.length = 0;
        while (buffer != '\n') {
            initString.concatString(&buffer);
            in.get(buffer);
        }
    }
    return in;
}

std::ostream& operator << (std::ostream& out, const String& outString) {
    out << outString.toStringVar;
    return out;
}

void String::concatString(char* newString) {
    for (long i = 0; i < newString[i] != '\0'; i++) {
        this->string.push_back(newString[i]);
    }
    getLength();
    this->stringBuilder();
}

void String::concatString(String newString) {
    concatString(newString.toString());
}

void String::concatStringIn(long index, char* newString) {
    for (int i = 0; i < newString[i] != '\0'; i++) {
        this->string.insert(string.begin() + i + index, newString[i]);
    }
    getLength();
    this->stringBuilder();
}

void String::concatStringIn(long index, String newString) {
    return concatStringIn(index, newString.toString());
}

long String::seek(char* subString) {
    bool isSought = false;
    long temp = 0;
    long tempPosition = length + 1;

    for (int i = 0; i < string.size(); i++) {
        if (string[i] != subString[temp]) {
            isSought = false;
            temp = 0;
        } else {
            tempPosition = !isSought ? i : tempPosition;
            temp++;
            isSought = true;
            if (subString[temp] == '\0') return tempPosition;
        }
    }
    return length + 1;
}

long String::seek(String subString) {
    return seek(subString.toString());
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

long String::size() {
    return length;
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
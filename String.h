#include <vector>
#include <iostream>
#ifndef STRING_CLASS_STRING_H
#define STRING_CLASS_STRING_H


class String {

public:
    String (char*);
    String ();
    String (String, String);

    String operator + (String);
    bool operator < (String);
    bool operator > (String);
    bool operator == (String);
    String& operator = (String);
    friend std::istream& operator >> (std::istream&,String&);
    friend std::ostream& operator << (std::ostream&,const String&);


    void concatString(char*);
    void concatString(String);
    void concatStringIn(long, char*);
    void concatStringIn(long, String);
    String getSubstring(long, long);
    long seek(char*);
    long seek(String);
    char* toString();
    long size();

private:
    void initVector(char*);
    void getLength();
    void stringBuilder();

    std::vector<char> string;
    long length;
    char* toStringVar;

};


#endif //STRING_CLASS_STRING_H

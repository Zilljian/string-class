#include <vector>
#ifndef STRING_CLASS_STRING_H
#define STRING_CLASS_STRING_H


class String {

public:
    String (char*);
    String ();
    String (String, String);

    void concatString(char*);
    void concatString(String);
    void concatStringIn(long, char*);
    void concatStringIn(long, String);
    String getSubstring(long, long);
    bool seek(char*);
    bool seek(String);
    char* toString();

private:
    void initVector(char*);
    void stringBuilder();
    void getLength();

    std::vector<char> string;
    long length;
    char* toStringVar;

};


#endif //STRING_CLASS_STRING_H

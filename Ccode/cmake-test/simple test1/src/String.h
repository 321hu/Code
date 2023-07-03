#ifndef _STRING_HEAD_
#define _STRING_HEAD_

#include <iostream>
#include <string.h>
using namespace std;

class String
{
public:
    String(const char* _s);
    ~String();
    String(const String & _s);
    String &operator=(const String & _s);
    int operator==(const String & _s) const;
    // String operator+(const String& _s) const;
    String operator+(const String& _s);
    int length() const;
    const char *getRaw() const;
    // const char *getRaw();
    int refCount() const;
private:
    struct StringData {
        char* str;
        int refCount;
    };
    StringData* data;
    void releaseData() {
        data->refCount--;
        if (data->refCount == 0) {
            delete[] data->str;
            delete data;
        }
    }
};

#endif 
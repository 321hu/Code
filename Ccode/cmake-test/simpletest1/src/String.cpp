#include "String.h"

String::String(const char* _s) {
    data = new StringData;
    data->str = new char[strlen(_s)+1];
    strcpy(data->str, _s);
    data->refCount = 1;
}

String::~String() {
    releaseData();
}

String::String(const String & _s) {
    data = _s.data;
    data->refCount++;
}

String& String::operator=(const String& _s) {
    if(this != &_s) { 
        releaseData();
        data = _s.data;
        data->refCount++;
    }
    return *this;
}

int String::operator==(const String& _s) const {
    return (strcmp(data->str, _s.data->str) == 0);
}

String String::operator+(const String& _s) {
    char* newStr = new char[length() + _s.length() + 1];
    strcpy(newStr, data->str);
    strcat(newStr, _s.data->str);
    return String(newStr);
}

int String::length() const {
    return strlen(data->str);
}
const char* String::getRaw() const {
    return data->str;
}
int String::refCount() const {
    return data->refCount;
}
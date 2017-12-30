#pragma once
#include <string>
#include <cstring>


class String
{
public:
    String(const char *cstr);
    String(const String &str);
    ~String();

    char charAt(unsigned int index) const;
    String substring(unsigned int beginIndex, unsigned int endIndex) const;
    unsigned char startsWith(const String &prefix) const;
        
    String & operator =(String &&rval);
    void replace(const String& find, const String& replace);
    long toInt(void) const;
    unsigned char equals(const char *cstr) const;
    unsigned char operator ==(const char *cstr) const;
    unsigned int length(void) const;
    String substring(unsigned int beginIndex) const {
            return substring(beginIndex, length());
    }
    ;
    int indexOf(const String &str) const;
    std::string pString;

private:
};
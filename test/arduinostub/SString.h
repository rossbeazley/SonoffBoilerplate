#pragma once
#include <string>
#include <cstring>
#include <ostream>


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
    String & operator =(const String &rval);
    void replace(const String& find, const String& replace);
    long toInt(void) const;
    unsigned char equals(const char *cstr) const;
    unsigned char operator ==(const char *cstr) const;
    unsigned char operator ==(String &rval) const;
    unsigned int length(void) const;
    String substring(unsigned int beginIndex) const {
            return substring(beginIndex, length());
    }
    ;
    int indexOf(const String &str) const;

    int indexOf(char ch, unsigned int fromIndex) const;
    int indexOf(char ch) const {
        return indexOf(ch, 0);
    };
    
    const char* c_str() const;

    std::string pString;

private:
};


#include "SString.h"
#include <stdlib.h>

String::String(const char *cstr = "")
{
    this->pString = std::string(cstr);
}


String::String(const String &value) {
    this->pString = value.pString;
}

String::~String()
{
    //this->pString = nul;
}


char String::charAt(unsigned int index) const
{
    return this->pString.c_str()[index];
}

String String::substring(unsigned int beginIndex, unsigned int endIndex) const
{
    //const char *result = " ";
    String s{};
    s.pString = this->pString.substr(beginIndex, endIndex);
    return s;
}


const char* String::c_str() const {
    return this->pString.c_str();
}

unsigned char String::startsWith(const String &prefix) const
{
    std::string t = prefix.pString;
    return this->pString.compare(0, t.length(), t) == 0;    
}
        
String & String::operator =(String &&rval) {
    this->pString = rval.pString;
    return *this;
}
        
String & String::operator =(const String &rval) {
    this->pString = rval.pString;
    return *this;
}


void String::replace(const String& find, const String& replace) {
    
    
    int indexFrom = this->pString.find_first_of(find.pString);
    int numberOfChars = find.pString.length();

    this->pString.replace(indexFrom, numberOfChars, replace.pString);
}

long String::toInt(void) const {
    return atoi(this->pString.c_str());
    
}

unsigned char String::equals(const char *cstr) const {
    String that{cstr};
    return that.pString == this->pString;
    
}

unsigned char String::operator ==(const char *cstr) const {
    String that{cstr};
    return that.pString == this->pString;
}

unsigned char String::operator ==(String &rval) const {
    return rval.pString == this->pString;
}

unsigned int String::length(void) const {
    return this->pString.length();
}

int String::indexOf(const String &str) const {
    return this->pString.find_first_of(str.pString);
}

int String::indexOf(char ch, unsigned int fromIndex) const {
    return this->pString.find_first_of(ch,fromIndex);
}

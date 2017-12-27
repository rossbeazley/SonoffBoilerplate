#include "SString.h"



String::String(const char *cstr = "")
{
    
}


String::String(const String &value) {
    //*this = value;
}

String::~String()
{

}


char String::charAt(unsigned int index) const
{
    const char result = ' ';
    return result;
}

String String::substring(unsigned int beginIndex, unsigned int endIndex) const
{
    //const char *result = " ";
    String result;
    return result;
}

unsigned char String::startsWith(const String &prefix) const
{
    const char result = ' ';
    return result;
}
        
String & String::operator =(String &&rval) {
    return *this;
}


void String::replace(const String& find, const String& replace) {
}

long String::toInt(void) const {
    return 0;
}

unsigned char String::equals(const char *cstr) const {
    return 0 == 0;
}
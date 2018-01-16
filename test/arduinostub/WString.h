
#ifndef String_class_h
#define String_class_h
#ifdef __cplusplus

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// The string class
class String {

    public:
        String(const char *cstr = "");
        
        ~String(void);

        
        inline unsigned int length(void) const {
            return 0;
        }

        // creates a copy of the assigned value.  if the value is null or
        // invalid, or if the memory allocation fails, the string will be
        // marked as invalid ("if (s)" will be false).
        String & operator =(const String &rhs);
        String & operator =(const char *cstr);
        
        
        unsigned char equals(const String &s) const;
        unsigned char equals(const char *cstr) const;
        unsigned char operator ==(const String &rhs) const {
            return equals(rhs);
        }
        unsigned char operator ==(const char *cstr) const {
            return equals(cstr);
        }
        
        // character acccess
        char charAt(unsigned int index) const;
       
       
       
};



#endif  // __cplusplus
#endif  // String_class_h

#include <iostream>
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy


using namespace std;

struct String {
    String (const String &other) {
        size = other.size;
        str = new char[size + 1];
        str[size] = '\0';
        
        const char * i = other.str;
        while (i != other.str + other.size) {
            str[i - other.str] = *i;
            i++;
        };
    }
    
    String(const char *str = "") {
        size = 0;
        this->str = 0;
        size = lengthOfStr(str);
        this->str = (size > 0) ? cpStr(str, size) : 0;
    }
    
    String(size_t n, char c) {
        size = n;
        str = new char[size + 1];
        str[size] = '\0';
        char * i = str;
        while (i - str < size) {
            *i = c;
            i++;
        };
    }
    
    ~String() {
        if (str != 0)
            delete [] str;
        str = 0;
        size = 0;
    }
    
    String &operator=(const String &other)
    {
        if (this != &other)
            String(other).swap(*this);
        return *this;
    }
    
    void swap(String & a) {
        std::swap(size, a.size);
        std::swap(str, a.str);
    }
    
    void append(String &other) {
        size_t newSz = size + other.size;
        char *newStr = new char[newSz + 1];
        newStr[newSz] = '\0';
        
        const char * i = str;
        while (i != str + size) {
            newStr[i - str] = *i;
            i++;
        };
        
        i = other.str;
        while (i != other.str + other.size) {
            newStr[size + i - other.str] = *i;
            i++;
        };
        
        delete [] str;
        size = newSz;
        str = newStr;
    }
    
    size_t lengthOfStr(const char * const str) {
        const char * i = str;
        while (*i != '\0') {
            i++;
        };
        return i - str;
    }
    
    char* cpStr(const char * const str, size_t strSz) {
        char *newStr = new char[strSz + 1];
        newStr[strSz] = '\0';
        
        const char * i = str;
        while (i != str + strSz) {
            newStr[i - str] = *i;
            i++;
        };
        
        return newStr;
    }
    
    /* ... */
    char & at(size_t idx)       {
        return str[idx];
    }
    char   at(size_t idx) const {
        return str[idx];
    }
    /* ... */
    
    String(const char *str, size_t len) {
        size = len;
        this->str = cpStr(str, size);
    }
    struct OperatorBracketHelper {
        OperatorBracketHelper(char *str, size_t i) {
            str_ = str;
            i_ = i;
        }
        String operator []( size_t j ) const {
            String s(str_ + i_, j-i_);
            return s;
        }
        char *str_;
        size_t i_;
    };
    OperatorBracketHelper operator []( size_t i ) const {
        cout << "str:" << str << endl;
        cout << "i:" << i << endl;
        OperatorBracketHelper o(str, i);
        return o;
    }
    
    size_t size;
    char *str;
};


void test3()
{
    String const hello("hello");
    //printf("%s\n", hello.str);
    
    String const hell = hello[0][4]; // теперь в hell хранится подстрока "hell"
    //printf("%s\n", hell.str);
    
    //String const ell  = hello[1][4]; // теперь в ell хранится подстрока "ell"
    //printf("%s\n", ell.str);

}

int main(int argc, const char * argv[]) {
    test3();
    return 0;
}

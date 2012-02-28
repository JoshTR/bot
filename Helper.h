#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <ctype.h>
#include <iostream>

class Helper
{
    public:
        static bool is_valid(std::string in);
        static std::string replace_all(std::string in, char replace, char with);
        static std::string replace_all(std::string in, char replace);
    protected:
    private:
};

#endif // HELPER_H

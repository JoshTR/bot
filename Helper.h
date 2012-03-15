#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <ctype.h>
#include <iostream>
#include <vector>
#include "regex.h"

class Helper
{
    public:
        static bool is_valid(std::string in);
        static std::string replace_all(std::string in, char replace, char with);
        static std::string replace_all(std::string in, char replace);
        static std::string Parser(std::string in);
        static void ExplodeString(std::string base, std::string delim, std::vector<std::string>& str_store);
        static std::string RegexMatch(const std::string given,const std::vector<std::string>match,const std::vector<std::string>result);
    protected:
    private:
};

#endif // HELPER_H

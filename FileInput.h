#ifndef FILEINPUT_H
#define FILEINPUT_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "Helper.h"
class FileInput
{
    public:
        FileInput(std::string in,std::string sym);
        ~FileInput();
        std::string get_first_result(std::string key);
        std::string get_random_result();
    protected:
    private:
        std::vector<std::string>Lines;
        std::string symbol;
        std::string title;
        std::string const_affirm;
        std::string const_negative;
};

#endif // FILEINPUT_H

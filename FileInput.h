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
        std::vector<std::string> get_line_vector(){ return Lines; }
    protected:
    private:
        std::vector<std::string>Lines;
        std::string symbol;
        std::string title;

};

#endif // FILEINPUT_H

#ifndef MATRIXMATCH_H
#define MATRIXMATCH_H

#include <string>
#include <vector>
#include <iostream>
#include "FileInput.h"
#include "Helper.h"
class MatrixMatch
{
    public:
        MatrixMatch(std::string name, std::string seperator);
        ~MatrixMatch();
        std::string get_result(std::string in);
        void SetSpecialVector(std::vector<std::string>in,std::string seperator);
    protected:
    private:
        std::string m_seperator,m_name;
        std::vector<std::string>m_Special,m_Special_Answer;
};

#endif // MATRIXMATCH_H

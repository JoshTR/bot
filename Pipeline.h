#ifndef PIPELINE_H
#define PIPELINE_H

#include <string>
#include <iostream>

class Pipeline
{
    public:
        Pipeline();
        ~Pipeline();
        void operator<<(std::string var){ m_str.append(var);}

        std::string str();
        void clr();
    protected:
    private:
        std::string m_str;
        int m_maxlength;
};

#endif // PIPELINE_H

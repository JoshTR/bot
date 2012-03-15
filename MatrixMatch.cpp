#include "MatrixMatch.h"

MatrixMatch::MatrixMatch(std::string name, std::string seperator)
{
    //ctor
    m_seperator=seperator;
    m_name=name;
}

MatrixMatch::~MatrixMatch()
{
    //dtor
}

void MatrixMatch::SetSpecialVector(std::vector<std::string>in,std::string seperator)
{
    for (int i=0;i<in.size();i++)
    {
        m_Special.push_back(in[i].substr(0,in[i].find(seperator)));
        m_Special_Answer.push_back(in[i].substr(in[i].find(seperator)+1));
    }

}

std::string MatrixMatch::get_result(std::string in)
{
    //returns a result, based on in.
    //std::cout<<"IN="<<in<<"\n";
    //essentially needs to explode in, compare each word inside in to the multi database, for each match found, swap out for matched word, retry special database.
    //also try a database that is like regex ish.. *hate*you = aww..i wish i wasn't hated.

    std::vector<std::string>explode;
    Helper::ExplodeString(in," ",explode);
    FileInput matrixFile(m_name,"|");
    std::vector<std::string> explodeMeToo=matrixFile.get_line_vector();
    std::vector<std::vector<std::string> >Matrix;
    //std::cout<<"Exploded\n";
    for (int i=0;i<explodeMeToo.size();i++)
    {
        std::vector<std::string>matrixwords;
        Helper::ExplodeString(explodeMeToo[i],"|",matrixwords);
        Matrix.push_back(matrixwords);
    }
    //std::cout<<"2d exploded\n";
    //now Matrix is a 2d vector of words. each line is the matrixfile lines, each element on each line is a word to condense into the [0] of that line

    for (int i=0;i<explode.size();i++)
    {
        for (int a=0;a<Matrix.size();a++)
        {
            for (int b=0;b<Matrix[a].size();b++)
            {
                if (explode[i].compare(Matrix[a][b])==0)
                {
                    explode[i]=Matrix[a][0];
                }
            }
        }
    }
    //now your explode should contain the replacement words, so check that against special again, and then if still no, check it against regex
    //std::cout<<"corrected explode\n";
    std::string explodeConcat="";
    for (int i=0;i<explode.size();i++)
    {
        explodeConcat+=explode[i];
        if (i!=explode.size()-1)
        explodeConcat+=" ";
    }

    //std::cout<<"EXPLODECONCAT="<<explodeConcat<<"\n";
    //now check explodeConcat against special

    for (int i=0;i<m_Special.size();i++)
    {
        if (m_Special[i].compare(explodeConcat)==0)
        {
            return m_Special_Answer[i];
        }
    }

    //if still here, then using matrix replacement didn't work on special, so try regex

//    Helper::RegexMatch(explodeConcat,regexVector);

    return "[FAIL]";
}

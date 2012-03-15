#include "Helper.h"

/***********************************

Currently not used, was initally
designed to check if a string is
something a user would normally say.

************************************/
bool Helper::is_valid(std::string in)
{
    int punct=0;
    int digit=0;

    //count up # punctuation,digits. if contains a control character, return false.
    for (int i=0;i<in.length();i++)
    {
        if (ispunct(in[i])) punct++;
        if (isdigit(in[i])) digit++;
        if (iscntrl(in[i])) return false;
    }

    //these will need tweaking, most likely.

    if ((in.length()>5)&&(punct>in.length()/3))
        return false;//length is >5 and 1/3 string is punctuation, so we say invalid

    if ((in.length()>5)&&(digit>in.length()/2))
        return false;//if length >5 and 1/2 string is digit, invalid

    return true;
}

/**********************************************************************

Replace instances of <replace> with <with> in <in>

**********************************************************************/
std::string Helper::replace_all(std::string in, char replace,char with)
{

        for (int i=0;i<in.length();i++)
            if (in[i]==replace)
                in[i]=with;


    return in;
}

/***********************************************************

Remove instances of <replace> in <in>

************************************************************/
std::string Helper::replace_all(std::string in, char replace)
{
    std::string t="";
    for (int i=0;i<in.length();i++)
            if (in[i]==replace)
                    t=in.substr(0,i)+in.substr(i+1);
return t;
}

/****************************************

Extra Parsing that needs to be done

*****************************************/
std::string Helper::Parser(std::string in)
{
    in=Helper::replace_all(in,'|');
    if (in.compare("[AFFIRM]")==0)
        return "[AFFIRMATIVE]";
    else if (in.compare("[NEGATIVE]")==0)
        return "[NEGATIVE]";
    else
        return in;
}

/***************************************************************************************************

Explode a string into a vector

***************************************************************************************************/
void Helper::ExplodeString(std::string base, std::string delim, std::vector<std::string>& str_store){
    size_t pos = base.find(delim);

    if(pos == std::string::npos){
        if(base != ""){
            str_store.push_back(base);
        }
        return;
    }else{
        str_store.push_back(base.substr(0, pos));
        ExplodeString(base.substr(pos+1, base.length()), delim, str_store);
    }
}

/**********************************************************************************

Match a given string to one of the regex strings. returns the result string

**********************************************************************************/
std::string Helper::RegexMatch(const std::string given,const std::vector<std::string>match,const std::vector<std::string>result)
{
    //process matchto, and then based on matchto, check given. if fits, then return true

    for (int i=0;i<match.size();i++)
    {
        if (match[i].find("*")!=std::string::npos)
        {
            //we have a * regex.

        }
    }


}

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
    for (int i=0;i<in.length();i++)
            if (in[i]==replace)
                for (int x=i;x<in.length();x++)
                    if (i!=in.length())
                    in[x]=in[x+1];
                    else
                    in[x]='\0';
return in;
}

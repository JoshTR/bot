#include "Pipeline.h"

/******************

Constructor

******************/
Pipeline::Pipeline()
{
    //ctor
    m_str = "";
    m_maxlength=60;
}

/*******************

Deconstructor

*******************/
Pipeline::~Pipeline()
{
    //dtor
}

/**************************

Format and return the pipeline.

**************************/
std::string Pipeline::str()
{
    //this isn't perfect. may crash sometimes.

    if (m_str.length()>m_maxlength)
    {
        for (int i=0;i<m_str.length();i++)
        {
            if ((i!=0)&&(i%m_maxlength==0))
            {
                m_str=m_str.substr(0,i)+"-\n"+m_str.substr(i);
            }

            //if (i%m_maxlength==0)
                //m_str=m_str.substr(0,i)+"-\n"+m_str.substr(i);
        }

        /*for (int i=0;i<m_str.length();i++)
        {
            if ((m_str[i]=='\n')&&(m_str[i-2]==' '))
                m_str=m_str.substr(0,i-3)+m_str.substr(i-1);
            if ((m_str[i]=='\n')&&(m_str[i+1]==' '))
                m_str=m_str.substr(0,i)+m_str.substr(i+2);
        }*/
    }


    return m_str;
}

/******************

Clear the pipeline.

******************/
void Pipeline::clr()
{
    m_str="";
}

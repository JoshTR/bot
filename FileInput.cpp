#include "FileInput.h"

/**************************************************

Constructor. Reads in file into Lines vector, and does some parsing.
Should be redone, offload parsing.

**************************************************/
FileInput::FileInput(std::string in,std::string sym)
{
    //ctor
    const_affirm="[AFFIRM]";
    const_negative="[NEGATIVE]";
    symbol=sym;
    title=in;
    std::string line;
  std::ifstream myfile (in.c_str());
  if (myfile.is_open())
  {
    while ( myfile.good() )
    {
      getline (myfile,line,';');
      if ((line.length()>1)||((line.length()<=1)&&(line[0]!='\n')))
      {

        line = Helper::replace_all(line,'\n');
        if (line.length()>0)
        {
          std::cout<<"|-"<<line.length()<<"-|"<<line<<"|--|\n";
          Lines.push_back(line);
          line="";
        }
      }

    }
    myfile.close();
  }

  else std::cout << "[FileInput] Unable to open file "<<in<<" PROGRAM ERROR\n";
}

/**********************
Deconstructs
**********************/
FileInput::~FileInput()
{
    //dtor
}

/*******************************************************

Processes getting the first value for <key>, and parses affirm and unsure.bcf's also
Should rewrite to not parse affirm/unsure in this function, offload.

*******************************************************/
std::string FileInput::get_first_result(std::string key)
{
    for(unsigned int i=0;i<Lines.size()-1;i++)
    {
        if (Lines[i].substr(0,Lines[i].find(symbol)).compare(key)==0)
            {
                //std::cout<<const_affirm<<".compare("<<Lines[i].substr(Lines[i].find(symbol)+1)<<")\n";
                if (const_affirm.compare(Lines[i].substr(Lines[i].find(symbol)+1))==0)
                    {
                        FileInput a(title.substr(0,title.find(".bcf"))+"-affirm.bcf","|");
                        return a.get_random_result();
                    }
                    else if (const_negative.compare(Lines[i].substr(Lines[i].find(symbol)+1))==0)
                    {
                        FileInput a(title.substr(0,title.find(".bcf"))+"-negative.bcf","|");
                        return a.get_random_result();
                    }
                    else
                        return Lines[i].substr(Lines[i].find(symbol)+1);
            }
    }

    FileInput t(title.substr(0,title.find(".bcf"))+"-unsure.bcf","|");
    return t.get_random_result();

}

/****************************************

Straightforward. Get's a random Line from a file and returns the whole line

****************************************/
std::string FileInput::get_random_result()
{
    return Lines[rand() % (Lines.size()-1)];
}

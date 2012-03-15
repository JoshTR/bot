#include "FileInput.h"

/**************************************************

Constructor. Reads in file into Lines vector, and does some parsing.
Should be redone, offload parsing.

**************************************************/
FileInput::FileInput(std::string in,std::string sym)
{
    //ctor
    symbol=sym;
    title=in;
    std::string line;
  std::ifstream myfile (in.c_str());
  if (myfile.is_open())
  {
    while ( myfile.good() )
    {
      getline (myfile,line,';');
      if (line.length()>1)
      {

        line = Helper::replace_all(line,'\n');
        if (line.length()>0)
        {
          //std::cout<<"|-"<<line.length()<<"-|"<<line<<"|--|\n";
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

Processes getting the first value for <key>

*******************************************************/
std::string FileInput::get_first_result(std::string key)
{
    for(unsigned int i=0;i<Lines.size()-1;i++)
    {
        if (Lines[i].substr(0,Lines[i].find(symbol)).compare(key)==0)
            {
                return Lines[i].substr(Lines[i].find(symbol));
            }
    }

    return "[NOMATCH]";

}

/****************************************

Straightforward. Get's a random Line from a file and returns the whole line

****************************************/
std::string FileInput::get_random_result()
{
    return Lines[rand() % (Lines.size()-1)];
}

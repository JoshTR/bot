#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include "Helper.h"
#include "Pipeline.h"
#include "FileInput.h"

std::string Process(std::string userinput,std::string title);

int main()
{
    //load dynamically from file (perhaps)
    std::string title = "ishmaelbot";

    /* initialize random seed: */
    srand ( time(NULL) );

    std::cout<<"You're chatting with "<<title<<"\n";

    //chat loop vars
    std::string userinput;
    Pipeline pipeline;


    //chat loop
    while(1)
    {
        std::cout<<"User: ";
        std::getline(std::cin,userinput,'\n');
        pipeline<<title;
        pipeline<<": ";
        pipeline<<Process(userinput,title);
        pipeline<<"\n";
        std::cout<<pipeline.str();
        pipeline.clr();
    }

}

std::string Process(std::string userinput,std::string title)
{

    //please note, efficency WILL be effected, since this opens files each time a response is needed.
    FileInput special(title+".bcf","|");//the special cases, check here for matches first
    FileInput multi(title+"-multi.bcf","|");//the multilist, piece together ui to try to gather a response

    //for now, until multi-Process-ing is complete, just check the special
    return special.get_first_result(userinput);


}


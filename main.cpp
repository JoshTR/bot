#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include "Helper.h"
#include "Pipeline.h"
#include "FileInput.h"
#include "MatrixMatch.h"

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
    MatrixMatch trix(title+"-multi.bcf","|");//a new MatrixMatch-er using | to seperate terms.

    std::string tString=Helper::Parser(special.get_first_result(userinput));//scan special for result
    trix.SetSpecialVector(special.get_line_vector(),"|");//set our MatrixMatch special words vector to the vector of all specials

    //for now, until multi-Process-ing is complete, just check the special
     if ("[NOMATCH]" == tString)//this seems to not hit anymore..see else for this reaction...
     {
         FileInput unsure(title+"-unsure.bcf","|");
         return unsure.get_random_result();
     }else if ("[AFFIRMATIVE]"==tString)
     {
         FileInput certain(title+"-affirm.bcf","|");
         return certain.get_random_result();
     }else if ("[NEGATIVE]"==tString)
     {
         FileInput negative(title+"-negative.bcf","|");
         return negative.get_random_result();
     }else
     {
         //no special match. call matrix.
         std::string matrixMatch=trix.get_result(userinput);
         if (matrixMatch=="[FAIL]")
         { //no matrix match. no clue what is being said.
             FileInput unsure(title+"-unsure.bcf","|");
             return unsure.get_random_result();
         }
         else
         { //matrix matched. finish processing, then return.
                     if ("[AFFIRMATIVE]"==matrixMatch)
                        {
                            FileInput certain(title+"-affirm.bcf","|");
                            return certain.get_random_result();
                        }else if ("[NEGATIVE]"==matrixMatch)
                        {
                            FileInput negative(title+"-negative.bcf","|");
                            return negative.get_random_result();
                        }else
                        {
                            return matrixMatch;
                        }
         }

     }


}


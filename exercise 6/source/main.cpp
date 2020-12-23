#include "io_obj.h"

int main()
{
    Output* out= new Output[DIMENSION];
    Input* in= new Input[DIMENSION];
    
    printOutput(out);
    
    buildOutput(out);
    printOutput(out);
    
    write(out, "./file.txt");
    read(in,"./file.txt");
    
    printInput(in);
    
    delete[]out;
    delete[]in;
    
    return 0;
}
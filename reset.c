#include<stdlib.h>
void reset()
{
    system("rm Student.dat");
    system("cp default.dat Student.dat");

}

#include "libCapture/include/Cap1.h"
#include "libCapture/include/Cap2.h"
int main(int argc, char* argv[])
{
    if (argc<2){
        printf("usage app1.exe cfg.xml\n");
        return -1;
    }
    std::string cfg ( argv[1] );



    return 0;
}

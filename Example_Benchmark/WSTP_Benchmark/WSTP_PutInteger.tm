:Begin:
:Function:	WSTPPutInteger
:Pattern:	WSTPPutInteger[x_Integer]
:Arguments:	{x}
:ArgumentTypes:	{Integer}
:ReturnType:	Manual
:End:
#include "wstp.h"
void WSTPPutInteger(int x)
{
     WSPutInteger32(stdlink,x);
}
int main(int argc, char *argv[])
{ 
    return WSMain(argc, argv); 
}
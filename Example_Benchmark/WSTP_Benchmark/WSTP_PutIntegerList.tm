:Begin:
:Function:	WSTPPutIntegerList
:Pattern:	WSTPPutIntegerList[x_Integer]
:Arguments:	{x}
:ArgumentTypes:	{Integer}
:ReturnType:	Manual
:End:
#include "wstp.h"
void WSTPPutIntegerList(int x)
{
    int a[x];
    for(int i=0;i<x;a[i++]=i+1);
    WSPutInteger32List(stdlink,a,x);
}
int main(int argc, char *argv[])
{ 
    return WSMain(argc, argv); 
}
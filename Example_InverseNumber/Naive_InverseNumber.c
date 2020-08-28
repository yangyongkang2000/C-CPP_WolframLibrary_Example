#include"WolframLibrary.h"
#include"stdio.h"
EXTERN_C DLLEXPORT mint WolframLibrary_getVersion( ) { return WolframLibraryVersion; }
EXTERN_C DLLEXPORT int WolframLibrary_initialize( WolframLibraryData libData) { return 0; }
EXTERN_C DLLEXPORT void WolframLibrary_uninitialize( WolframLibraryData libData) { return; }
EXTERN_C DLLEXPORT int Naive_InverseNumber(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res)
{
            mint *list,tmp,j;
            unsigned long long int count=0;
            const mint  *dims;
          MTensor tensor;
         tensor=MArgument_getMTensor(Args[0]);
        dims=libData->MTensor_getDimensions(tensor);
       list=libData->MTensor_getIntegerData(tensor);
       for(int i=1;i<*dims;i++)
       {
              tmp=list[i];
              for( j=i;j>0;j--)
            {
                 if(tmp<list[j-1])
                 {
                       list[j]=list[j-1];
                       count++;
                }else break;
            }
            list[j]=tmp;
       }
       MArgument_setInteger(Res,count);
       return LIBRARY_NO_ERROR;
}
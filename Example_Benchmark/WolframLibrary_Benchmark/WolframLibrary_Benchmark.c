#include"WolframLibrary.h"
EXTERN_C DLLEXPORT mint WolframLibrary_getVersion( ) { return WolframLibraryVersion; }
EXTERN_C DLLEXPORT int WolframLibrary_initialize( WolframLibraryData libData) { return 0; }
EXTERN_C DLLEXPORT void WolframLibrary_uninitialize( WolframLibraryData libData) { return; }
EXTERN_C DLLEXPORT int PutInteger(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res)
{
    mint m=MArgument_getInteger(Args[0]);
    MArgument_setInteger(Res,m);
    return LIBRARY_NO_ERROR;
}
EXTERN_C DLLEXPORT int PutIntegerList(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res)
{
    mint m=MArgument_getInteger(Args[0]),*list;
    MTensor tensor;
  const  mint dims=m;
    libData->MTensor_new(MType_Integer,1,&dims,&tensor);
   list=libData->MTensor_getIntegerData(tensor);
   for(int i=0;i<m;list[i++]=i+1);
   MArgument_setMTensor(Res,tensor);
   return LIBRARY_NO_ERROR;
}

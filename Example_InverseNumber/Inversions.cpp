#include"Inversions.h"
#include"WolframLibrary.h"
#include<string>
EXTERN_C DLLEXPORT mint WolframLibrary_getVersion( ) { return WolframLibraryVersion; }
EXTERN_C DLLEXPORT int WolframLibrary_initialize( WolframLibraryData libData) { return 0; }
EXTERN_C DLLEXPORT void WolframLibrary_uninitialize( WolframLibraryData libData) { return; }
EXTERN_C DLLEXPORT int InverseNumber(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res)
{
            mint *list;
            const mint  *dims;
          MTensor tensor;
         tensor=MArgument_getMTensor(Args[0]);
        dims=libData->MTensor_getDimensions(tensor);
       list=libData->MTensor_getIntegerData(tensor);
       Inversions<mint> inversions(list,*dims);
       if(*dims<=12)
       {
         inversions.InverseNumber();
       }else{
         inversions.MergeSort();
       }
      MArgument_setUTF8String(Res,(char *)(std::to_string(inversions.Get()).c_str()));
       return LIBRARY_NO_ERROR;
}


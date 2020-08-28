#ifndef _Inversions_
#define _Inversions_
template<typename ElementType=int,typename IntegerType=unsigned long long int>
class Inversions 
{
    public:
    Inversions(ElementType *list,int count, int _count=0):_list(list),list_count(count),inversions_count(_count)
    {
       _arr= new ElementType[count];
    };
    ~Inversions() {delete [] _arr;}
    void MSort(int left,int right);
   void Merge(int left,int right);
   void MergeSort();
   void InverseNumber();
  IntegerType Get() {return inversions_count;}
   private:
       ElementType * _list;
      IntegerType inversions_count;
       int list_count;
       ElementType *_arr;
};
template<typename ElementType,typename IntegerType>
 void Inversions<ElementType,IntegerType>:: MSort(int left,int right)
{
           if(right>left)
           {
               int center=(left+right)>>1;
               MSort(left,center);
               MSort(center+1,right);
               Merge(left,right);
           }
}
template <typename ElementType,typename IntegerType>
void Inversions<ElementType,IntegerType>::MergeSort()
{
    MSort(0,list_count-1);
}
template <typename ElementType,typename IntegerType>
inline void Inversions<ElementType,IntegerType>::Merge(int left,int right)
{
      int center=(left+right)>>1,count=0,index1=left,index2=center+1,index3=0;
      for(;;)
      {
          if(_list[index1]<=_list[index2])
          {
              _arr[index3++]=_list[index1++];
              inversions_count+=index3-index1+left;
              if(index1>center)
              {
                  for(;index2<=right;_arr[index3++]=_list[index2++]);
                  break;
              }
              }else{
                  _arr[index3++]=_list[index2++];
                  if(index2>right)
                  {
                     while(index1<=center)
                     {
                         _arr[index3++]=_list[index1++];
                         inversions_count+=index3-index1+left;
                     }
                     break;
                  }
              }
          }
             for(int i=left;i<=right;_list[i++]=_arr[i-left]);
}
template<typename ElementType,typename IntegerType>
 inline void Inversions<ElementType,IntegerType>:: InverseNumber()
 {
     for(int i=0;i<list_count;i++)
      for(int j=i+1;j<list_count;inversions_count+=_list[i]>_list[j++]?1:0);
 }
#endif
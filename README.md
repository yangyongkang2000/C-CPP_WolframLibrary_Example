# C-CPP_WolframLibrary_Example
## WolframLibrary与C/C++交互简单例子
* 声明 
> 本文不是具体讲解如何操作，也不是教大家C/C++和程序设计相关知识，只是展示一下特定例子下的代码。
* 系统环境
> Ubuntu18.04
* 前言
> 之前用WSTP进行Wolfram和C/C++之间的相互调用，但是效率很低，所以我在Example_Benchmark里面用几个例子做简单的测试，速度差距大的惊人，用WolframLibrary比用WSTP快千倍。 

* WSTP和WolframLibrary用途
> 对个人来说建议用WolframLibrary，速度更快，也支持双向调用。对于WSTP，适合做远程连接程序，但是写算法开发函数，建议使用WolframLibrary。
![](https://raw.githubusercontent.com/yangyongkang2000/C-CPP_WolframLibrary_Example/master/Example_Benchmark/Image/Benchmark1.png)
* 例子
> 我写了几个简单例子，其中一个是用归并排序求逆序数，我与python写的速度对比了一下。python代码如下 ,Python代码来自于[LeetCode](https://zhuanlan.zhihu.com/p/40695917)

```  Python
import timeit
def mergeSort(alist):
    n = len(alist)
    __mergeSort(alist, 0, n-1)
def __mergeSort(alist, start, end):
    if (end-start <= 15):
        insertionSortHelp(alist, start, end)
        return
    if start >= end:
        return
    mid = (start + end) // 2
    __mergeSort(alist, start, mid)
    __mergeSort(alist, mid + 1, end)
    if alist[mid] > alist[mid+1]:
        merge(alist, start, mid, end)
def merge(alist, start, mid, end):
    blist = alist[start:end+1]
    l = start
    k = mid + 1
    pos = start
    while pos <= end:
        if (l > mid):
            alist[pos] = blist[k-start]
            k += 1
        elif (k > end):
            alist[pos] = blist[l-start]
            l += 1
        elif blist[l-start] <= blist[k-start]:
            alist[pos] = blist[l-start]
            l += 1
        else:
            alist[pos] = blist[k-start]
            k += 1
        pos += 1
def insertionSortHelp(alist,l, r):
    for i in range(l+1,r+1):
        currentvalue=alist[i]
        position=i
        while alist[position-1]>currentvalue and position>l:
            alist[position]=alist[position-1]
            position=position-1
        alist[position]=currentvalue
    return alist
``` 
``` Python
%%timeit -n 10
a=list(range(100000,0,-1))
mergeSort(a)
``` 
速度差距百倍，大家有兴趣可以尝试一下。

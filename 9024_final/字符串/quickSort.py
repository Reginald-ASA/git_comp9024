def partition(arr,low,high): 
    i = ( low-1 )         # 最小元素索引
    pivot = arr[low]     
    print('当前pivot为',end='')
    print(pivot)
    for j in range(low , high): 
        # 当前元素小于或等于 pivot 
        if   arr[j] <= pivot: 
          
            i = i+1 
            arr[i],arr[j] = arr[j],arr[i] 
            print(arr)
    arr[i+1],arr[high] = arr[high],arr[i+1] 
    print(arr)
    return ( i+1 ) 
  
 
# arr[] --> 排序数组
# low  --> 起始索引
# high  --> 结束索引
  
# 快速排序函数
def quickSort(arr,low,high): 
    if low < high: 
        
        pi = partition(arr,low,high) 
        quickSort(arr, low, pi-1) 
        quickSort(arr, pi+1, high) 
  
  
arr = [10, 7, 8, 9, 1, 5]


n = len(arr) 

print(arr)
quickSort(arr,0,n-1) 

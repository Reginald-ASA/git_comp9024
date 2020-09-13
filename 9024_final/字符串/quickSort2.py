def partition(array,low,high): 

    pivot_item = array[low]
    left=low+1
    right=high

    while left<right:
        for j in range(low , high):
            if array[j] > pivot_item:
                left = j
            elif j == high -1:
                left = high

        for j in range(high , low-1,-1):
            if array[j] <= pivot_item:
                right = j
        if left < right:
            array[left],array[right] = array[right],array[left]

    array[low]=array[right]
    array[right]=pivot_item
    return right 
  
 
# arr[] --> 排序数组
# low  --> 起始索引
# high  --> 结束索引
  
# 快速排序函数
def quickSort(arr,low,high): 
    if high > low: 
        
        pi = partition(arr,low,high) 
        quickSort(arr, low, pi-1) 
        quickSort(arr, pi+1, high) 
  
  
arr = [10, 7, 8, 9, 1, 5]


n = len(arr) 

print(arr)
quickSort(arr,0,n) 


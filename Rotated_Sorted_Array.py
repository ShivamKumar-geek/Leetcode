def rotated_binary_search(nums,item):
    low=0
    high=len(nums)-1
    while(low<=high):
        mid=low+(high-low)//2
        if(nums[mid]==item):
            return mid
        if(nums[low]<=nums[mid]):
            if (nums[low]<=item and item<nums[mid]):
                high=mid-1
            else:
                low=mid+1
        else:
            if(nums[high]>=item and nums[mid]<item):
                low=mid+1
            else:
                high=mid-1
    return -1
while(True):   
    nums = list(map(int,input().split()))
    item= int(input("Enter the item"))
    print("The item is at "+str(rotated_binary_search(nums,item)))


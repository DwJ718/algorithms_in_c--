### 一些关于二分的知识

1.二分查找

在一个有序数组中，你想找到第一个大于等于n的位置，如果所有都小于n则返回数组长度

暴力解法：遍历每个数

优解：用L，R指向数组的左右边界即闭区间[L,R]，T表示当前询问的数

当T指向的数小于n时，更新L，让L指向T+1（因为**闭区间表示要查询的**，T已经小于n了，再进一步，**L-1所指向的一定小于n，R+1指向的一定大于n**）

```python
#[]左闭右闭
left = 0
right = len(nums) - 1
while left <= right
	mid = (left + right)//2  #防止溢出可以用 left + (right - left)//2
	if nums[mid] < target:
		left = mid + 1
	else
		right = mid - 1
return left
```

```python
#[)左闭右开
left = 0
right = len(nums)
while left < right
	mid = (left + right)//2  #防止溢出可以用 left + (right - left)//2
	if nums[mid] < target:
		left = mid + 1
	else
		right = mid
return left
```

```python
#()左开右开
left = -1
right = len(nums)
while left + 1 < right
	mid = (left + right)//2  #防止溢出可以用 left + (right - left)//2
	if nums[mid] < target:
		left = mid
	else
		right = mid
return right （可以理解成按照左闭右闭时R+1一定大于n，这里是右开，那么这里的right相当于R+）
```

对于大于，可以转换成大于等于n+1

对于小于，可以转换成大于等于n然后位置减1

对于小于等于，可以转换成大于n然后位置减1

时间O(log n) 空间O(1)

抽象一点的二分题目：力扣162，153，33
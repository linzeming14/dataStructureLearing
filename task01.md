## 学习任务

### Task01：数组（1天）
<b>理论部分</b>

- 理解数组的存储与分类。
- 实现动态数组，该数组能够根据需要修改数组的长度。

<b>练习部分</b>

<u>1. 利用动态数组解决数据存放问题</u>

编写一段代码，要求输入一个整数`N`，用动态数组`A`来存放`2~N`之间所有5或7的倍数，输出该数组。

示例：
```c
输入：
N = 100 

输出：
5 7 10 14 15 20 21 25 28 30 35 40 42 45 49 50 55 56 60 63 65 70 75 77 80 84 85 90 91 95 98 100
```

```c++
void D_array(int N)
{
	int count =0;
	for(int i = 2; i <= N; ++i)
	{
		if(i%5==0 || i%7==0)
		{
			count +=1;
		}
	}
	int *d_array = (int*)malloc(sizeof(int*)* count);
	count =0;
	for(int i = 2; i <= N; ++i)
	{
		if(i%5==0 || i%7==0)
		{
			d_array[count] = i;
			count +=1;
		}
	}

	for(int i =0; i< count;++i)
	{
		printf("%d ",d_array[i]);
	}
	printf("\n");
	free(d_array);
}
```



<u>

2. 托普利茨矩阵问题</u>

如果一个矩阵的每一方向由左上到右下的对角线上具有相同元素，那么这个矩阵是托普利茨矩阵。

给定一个`M x N`的矩阵，当且仅当它是托普利茨矩阵时返回`True`。

示例：

```c
输入:
matrix = [
  [1,2,3,4],
  [5,1,2,3],
  [9,5,1,2]
]

输出: True
```
解释:

在上述矩阵中, 其对角线为:
`"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]"`。
各条对角线上的所有元素均相同, 因此答案是`True`。

```c++
bool t_matrix(int M[][4], int rows, int cols)
{
	for(int i =0; i< rows-1;++i)
	{
		for(int j = 0; j < cols-1;++j)
		{
			
			if(M[i][j] != M[i+1][j+1])
			{
				printf("false\n");
				return false;
			}
		}
	}
	return true;
}
```



<u>3. 三数之和</u>

https://leetcode-cn.com/problems/3sum/

给定一个包含 n 个整数的数组`nums`，判断`nums`中是否存在三个元素`a，b，c`，使得`a + b + c = 0`？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

示例：

```c
给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
```

```c++
void sum3num(int arr[], int length)
{
	std::vector<std::vector<int>> temp;
	for(int i=0; i< length; ++i)
	{
		for(int j =i+1; j < length; ++j)
		{
			for(int k =j+1; k<length; ++k)
			{
				if(k==j ||k ==i ||i==j)
				{
					continue;
				}
				if(arr[i]+arr[j]+arr[k] ==0)
				{
					std::vector<int> t;
					t.push_back(arr[i]);
					t.push_back(arr[j]);
					t.push_back(arr[k]);
					if(temp.size()>0)
					{
						bool is_same=false;
						for(int p =0; p< temp.size(); ++p)
						{
							std::vector<int> t1= temp[p];
							int same=0;
							for(int q =0; q<3;q++)
							{
								for(int r=0; r < t.size(); r++)
								{
									if(t[q]==t1[r])
									{
										same +=1;
									}
								}
								
							}
							if(same==3)
								{

										is_same =true;
										break;
									}
								else
									same = 0;

						}
						if(!is_same)
							{
								temp.push_back(t);
								printf("%d %d %d\n ", arr[i],  arr[j],  arr[k] );
						}
					}
					else{
						temp.push_back(t);
						printf("%d %d %d\n ", arr[i],  arr[j],  arr[k] );
					}


				}
			}
		}
	}
}

```


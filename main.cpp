#include <iostream>
#include <vector>


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


int main()
{
	std::cout <<"Task01"<< std::endl;
	
	D_array(100);

	int a[3][4]={1,2,3,4, 5,1,2,3, 9,5,1,2};
	t_matrix(a, 3,3);


	int nums[]={-1,0,1,2,-1,-4};
	sum3num(nums, 6);
	system("pause");
}
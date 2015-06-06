#include <iostream>
#include <vector>
using namespace std;

int total_count;

void merge(int nums[], int low, int mid, int high, int tmpArr[])
{
	int indexTmpArr=low, indexLeft=low, indexRight=mid+1;

	while(indexLeft<=mid && indexRight<=high)
	{
		if(nums[indexLeft]<=nums[indexRight])
		{
			tmpArr[indexTmpArr++]=nums[indexLeft++];
		}
		else 
		{
			tmpArr[indexTmpArr++]=nums[indexRight++];
			total_count=total_count+mid+1-indexLeft;
		}
	}
	while(indexLeft<=mid)
	{
		tmpArr[indexTmpArr++]=nums[indexLeft++];
	}
	while(indexRight<=high)
		tmpArr[indexTmpArr++]=nums[indexRight++];

	for(int i=low; i<=high; i++)
	{
		nums[i]=tmpArr[i];
	}
}

void mergeSort(int nums[], int low, int high, int tmp[])
{
	if(low<high)
	{
		int mid=(low+high)/2;
		mergeSort(nums, low, mid, tmp);
		mergeSort(nums, mid+1, high, tmp);
		merge(nums, low, mid, high, tmp);
	}
}

bool exMerge(int nums[], int n)
{
	int *tmp=new int[n];
	if(tmp==NULL)
		return false;
	
	cout<<"before sort"<<endl;
	for(int i=0; i<n; i++)
		cout<<nums[i]<<"\t";
	cout<<endl;

	//mergeSort(nums, tmp, 0, n-1);
	mergeSort(nums, 0, n-1, tmp);

	cout<<"after sort"<<endl;
	for(int i=0; i<n; i++)
		cout<<nums[i]<<"\t";
	cout<<endl;

	cout<<total_count<<endl;

	return true;
}

//void main()
//{
//	/*int aa[]={2,3,5,7,8,
//				1,2,6,4,3,
//				2,7,56,34,23,
//				1,2,54,6};
//	exMerge(aa, 19);*/
//
//	int aa[]={7,5,2,6,4,};
//	exMerge(aa, 5);
//
//	/*int aa[]={2,6,5,2,8,};*/
//	/*exMerge(aa, 5);*/
//
//	//for(int i=0; i<19; i++)
//	//	cout<<aa[i]<<"\t";
//	cout<<endl;
//}
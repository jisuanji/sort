#include <iostream>
#include <vector>
using namespace std;

void quikSort(vector<int> & vec, int low, int high)
{
	if(low>=high)
		return ;
	int key=vec[low];
	int begin=low;
	int end=high;
	while(begin<end)
	{
		while(begin<end && vec[end]>=key)
			end--;

		vec[begin]=vec[end];

		while(begin<end && vec[begin]<=key)
			begin++;

		vec[end]=vec[begin];
	}
	vec[begin]=key;
	quikSort(vec, low, begin-1);
	quikSort(vec, begin+1, high);
}

int partition(vector<int> & vec, int begin, int end)
{
	int ret_idx;
	int key=vec[begin];
	while(begin<end)
	{
		while(begin<end && vec[end]>=key)
			end--;

		vec[begin]=vec[end];

		while(begin<end && vec[begin]<=key)
			begin++;

		vec[end]=vec[begin];
	}
	vec[begin]=key;
	ret_idx=begin;
	return ret_idx;
}

int getKthNum(vector<int> & vec, int k)
{
	if(k>vec.size())
		return 0;
	int index=-1;
	int low=0;
	int high=vec.size()-1;
	
	index=partition(vec, low, high);
	while(low<high)
	{
		if(index+1==k)
			return vec[index];
		else if(index+1<k)
		{
			low=index+1;
			index=partition(vec, low, high);
		}
		else if(index+1>k)
		{
			high=index-1;
			index=partition(vec, low, high);
		}
	}
	if(index+1==k)
		return vec[index];
	return 0;
}
//
//void main()
//{
//	int aa[]={2,3,5,7,8,
//			  1,2,6,4,3,
//			  2,7,56,34,23,
//			  1,2,54,6};
//	/*int aa[]={2,3,5,7,8,};*/
//	vector<int> vec(aa, aa+19);
//	vector<int> vec1(vec.begin(), vec.end());
//	quikSort(vec, 0, vec.size()-1);
//
//	for(int i=0; i<vec.size(); i++)
//		cout<<vec[i]<<"\t";
//	cout<<endl;
//
//	cout<<"第9小的数是："<<getKthNum(vec1, 15)<<endl;
//}
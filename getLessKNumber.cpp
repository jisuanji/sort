#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition1(vector<int> &vec, int start, int end)
{
	if(start>=end)
		return start;

	int key=vec[start];
	while(start<end)
	{
		while(start<end && vec[end]>=key)
			end--;

		vec[start]=vec[end];

		while(start<end && vec[start]<=key)
			start++;

		vec[end]=vec[start];
	}
	vec[start]=key;
	return start;
}

vector<int> getLessKNumberss(vector<int> & vec, int k)
{
	vector<int> ret;
	if(vec.size()==0)
		return ret;
	ret.resize(k);

	int start=0;
	int end=vec.size()-1;
	int index=partition1(vec, start, end);
	while(index!=k)
	{
		if(index<k-1)
		{
			start=index+1;
			index=partition1(vec, start, end);	
		}
		else
		{
			end=index-1;
			index=partition1(vec, start, end);
		}
	}
	for(int i=0; i<k; i++)
	{
		ret[i]=vec[i];
	}
	return ret;
}

	
//void main()
//{
//	int aa[]={2,3,5,7,8,
//			  1,2,6,4,3,
//			  2,7,56,34,23,
//			  1,2,54,6};
//	vector<int> vec(aa, aa+19);
//	vector<int> data;
//
//	data=getLessKNumberss(vec, 10);
//	for(int i=0; i<data.size(); i++)
//	{
//		cout<<data[i]<<"\t";
//	}
//	cout<<endl;
//	sort(vec.begin(), vec.end());
//	for(int i=0; i<vec.size(); i++)
//	{
//		cout<<vec[i]<<"\t";
//	}
//	cout<<endl;
//}
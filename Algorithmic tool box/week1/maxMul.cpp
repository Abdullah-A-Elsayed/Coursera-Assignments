#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n,maxi_in=0,maxii_in=1;
	cin>>n;
	long maxi,maxii;
	vector<long> nums(n);

	for (int i = 0; i < n; ++i)
	{
		cin>>nums[i];
		if (i==0)
		{
			maxi = nums[i];
		}
		else if(nums[i]>maxi){
			maxi = nums[i]; maxi_in = i;
		}
	}
	maxii = 0;
	for (int i = 0; i < n; ++i)
	{
		if (nums[i]>maxii&&i!=maxi_in)
		{
			maxii = nums[i];
		}
	}
	cout<<maxi*maxii;
	return 0;
}
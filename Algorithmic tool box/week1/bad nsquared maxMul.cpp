#include <iostream>
#include <iomanip> // manipulators to deal with precision
					// fixed to remove scientifical form
//or use long ya 7abeb 2lby!
#include <vector>
using namespace std;
int main()
{
	int n;
	cin>>n;
	long mul = 0;
	vector<long> nums(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>nums[i];
	}
	for (int k = 0; k < n; ++k)
	{
		if(k==n-1){
			break;
		}
		for (int j = k+1; j < n; ++j)
		{ 
			if (nums[k]*nums[j] > mul)
			{
				mul = nums[k]*nums[j];
			}
		}
	}
	cout<<mul;
	//fixed<<setprecision(0)<<mul;
	return 0;
}
#include <bits/stdc++.h> 
using namespace std; 
void swap(int& x, int& y) 
{ 
	int temp = x; 
	x = y; 
	y = temp; 
}
void permutations(vector<vector<int> >& res, vector<int> nums, int l, int h){ 
     if (l == h) { 
        res.push_back(nums); 
        return; 
    }
    for (int i = l; i <= h; i++) { 
        swap(nums[l], nums[i]); 
        permutations(res, nums, l + 1, h); 
        swap(nums[l], nums[i]); 
    } 
} 
vector<vector<int> > permute(vector<int>& nums){ 
    vector<vector<int> > res; 
    int x = nums.size() - 1; 
    permutations(res, nums, 0, x); 
    return res; 
}

int main() 
{ 
	vector<int> nums = { 1, 2, 3 ,4}; 
	vector<vector<int> > res = permute(nums); 
	for (auto x : res) { 
		for (auto y : x) { 
			cout << y << " "; 
		} 
		cout << endl; 
	} 

	return 0; 
}

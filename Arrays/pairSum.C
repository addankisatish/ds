#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

#define MAX_NUM 1000

using namespace std;


void printPairs(int arr[], int size, int sum)
{
    bool binMap[MAX_NUM] = {0};
    for(int i = 0; i < size; i++)
    {
        int rem = sum - arr[i];
        if(rem >= 0 && binMap[rem] == 1)
        {
            cout << "Pair with given sum " << sum << " is (" << arr[i] << "," << rem << ")" << endl;
        }
        binMap[arr[i]] = 1;
    }
}

vector<int> printPairs(vector<int>& nums, int target)
{
    map<int, int> hash;
    std::vector<int> result;
    for(int i = 0; i < nums.size() ; i++)
    {
        int temp = target - nums[i];
        if(hash.find(temp) != hash.end()) 
        {
            result.push_back(hash[temp]);
            result.push_back(i);
            break;   
        }
        else
        {
            hash.insert(pair<int, int>(nums[i], i));   
        }   
    }
    return result;
}

vector<int> twoSum(vector<int>& nums, int target)
{
    std::sort(nums.begin(), nums.end());
    int i = 0;
    int j = nums.size() - 1;
    std::vector<int> result;

    while(i < j)
    {
        int sum = nums[i] + nums[j];
        cout << i << "," << j << "," << nums[i] << "," << nums[j] << "," << target << endl; 
        if(sum < target)
            i++;
        else if(sum > target)
            j--;
        else
        {
            result.push_back(i);
            result.push_back(j);
            break;  
        } 
    } 
    return result;
}

int main()
{
    int arr[] = {1, 4, 45, 6, 10, 8};
    int n = 16;
    int size = sizeof(arr)/sizeof(int);
 
    printPairs(arr, size, n);

    std::vector<int> nums = {3, 2, 4};
    std::vector<int> result;
    result = printPairs(nums, 6);
    if(result.size() > 0)
    {
        cout << "[" << result[0] << "," << result[1] << "]" << endl;
    }
    else
    {
        cout << "Not found.";
    }
    return 0;
}

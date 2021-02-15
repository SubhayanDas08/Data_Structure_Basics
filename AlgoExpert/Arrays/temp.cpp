#include<iostream>
#include<queue>
#include <cstring>

using namespace std;
class compare{
	public:
bool operator()(pair<int,int>a,pair<int,int>b)
{
if(a.second==b.second)
return a.first>b.first;
else
return a.second<b.second;
}
};
void print(priority_queue<pair<int,int>,vector<pair<int,int>>,compare>pq,int k)
{
while(!pq.empty()&&k)
{

pair<int,int>p;
p=pq.top();
cout<<p.first<<" ";
pq.pop();
--k;
}
}
int main() {
	
priority_queue<pair<int,int>,vector<pair<int,int>>,compare>pq;
int arr[256]={0};
int t;
cin>>t;
while(t--)
{
	long long int n,k;
cin>>n>>k;
for(long long int i=0;i<n;++i)
{
int num;
cin>>num;
arr[num]++;
pq.push({num,arr[num]});
print(pq,k);
}
cout<<endl;
pq = priority_queue <pair<int,int>,vector<pair<int,int>>,compare>();
memset(arr,0,sizeof(arr));
}
	return 0;
}
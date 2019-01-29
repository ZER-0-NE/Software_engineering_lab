#include<bits/stdc++.h>
using namespace  std;
int main()
{
	long long n,mi;
	cin>>n>>mi;
	vector<long long>arr[n+1];
	for(long long i=0;i<mi;i++)
	{
		long long a,b;
		cin>>a>>b;
		arr[a].push_back(b);
	}

	//cout<<"starting node "<<1<<endl;
	queue<long long>q;
	q.push(1);
	int m[n+1];
	m[1]=1;
	long long parent[n+1];
	parent[1]=1;
	long long count=0;
	while(!q.empty())
	{
		long long t=q.front();
		q.pop();
		for(long long i=0;i<arr[t].size();i++)
		{
			if(m[arr[t][i]] == 0 )
			{
				m[arr[t][i]]=1;
				q.push(arr[t][i]);
				parent[arr[t][i]]=t;
				//cout<<t<<"--->"<<arr[t][i]<<endl;
			}
			else
			{
				if(parent[arr[t][i]]!=t)
				{
					count++;
				}
			}
		}
	}
	long long exit;
	for(long long i=1;i<=n;i++)
	{
		if(arr[i].size()==0 && i!=1)
		exit=i;
	}
	cout<<"number of bounded regions "<<count<<endl;
}

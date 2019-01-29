#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,mi;
	cin>>n>>mi;
	vector<long long>arr[n+1]; // creating a graph
	// inserting values in the graph
	for(long long i=0;i<mi;i++)
	{
		long long a,b;
		cin>>a>>b;
		arr[a].push_back(b);
	}

	cout<<"Starting node: "<< 1 <<endl;
	queue<long long>q; // maintaining all the node values in a queue
	q.push(1);
	int m[n+1]; //  a linear array
	m[1]=1;
	while(!q.empty())
	{
		long long t=q.front();
		q.pop();
		for(long long i=0;i<arr[t].size();i++)
		{
			if(m[arr[t][i]] != 0)
			{
				m[arr[t][i]]=1;
				q.push(arr[t][i]);
				cout<<t<<"--->"<<arr[t][i]<<endl;
			}
		}
	}
	long long exit;
	for(long long i=1;i<=n;i++)
	{
		if(arr[i].size()==0 && i!=1)
		exit=i;
	}
	cout<<"exit node "<<exit<<endl;
}

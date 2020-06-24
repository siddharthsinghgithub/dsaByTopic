#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> ADJ[], int u, int v)
{
	ADJ[u].push_back(v);
	ADJ[v].push_back(u);
}

void printGraph(vector<int> ADJ[])
{

	for (int i = 0; i < 5; i++)
	{
		cout << "Vertex " << i << " has edges  : ";
		for (auto V : ADJ[i])
		{
			cout << V << "\t";
		}
		cout << endl;
	}
}
void DFSUtil(vector<int> ADJ[], vector<bool> &visited, int start)
{

	visited[start] = true;
	cout << start << " -->\t";
	for (int i = 0; i < ADJ[start].size(); i++)
	{
		if (!visited[ADJ[start][i]])
		{
			DFSUtil(ADJ, visited, ADJ[start][i]);
		}
	}
}

void DFS(vector<int> ADJ[], int start)
{
	cout << " DFS Path" << endl;
	vector<bool> visited(5, false);
	DFSUtil(ADJ, visited, start);
	for (int i = 0; i < 5; i++)
	{
		if (visited[i] == false)
			DFSUtil(ADJ, visited, i);
	}
}


void BFS(vector<int> ADJ[], int start){
	cout<<"\n BFS Path"<<endl;

	vector<bool> visited(5, false);
	queue<int> Q;
	Q.push(start);
	while (!Q.empty())
	{	
		if(!visited[Q.front()])
		{	
			visited[Q.front()] = true;
			for(auto c : ADJ[Q.front()]){
				if(!visited[c])
					Q.push(c);
			}
			Q.pop();
		}
	}
	

}

int main()
{

	vector<int> ADJ[5];
	addEdge(ADJ, 0, 2);
	addEdge(ADJ, 0, 4);
	addEdge(ADJ, 4, 1);
	addEdge(ADJ, 3, 3);
	addEdge(ADJ, 2, 1);

	// printGraph(ADJ);

	DFS(ADJ, 2);
	return 0;
}
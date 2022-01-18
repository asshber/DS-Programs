#include<iostream>
#include<list>
#include<vector>
//k201051
using namespace std;
class Edge
{
public:
	int cost;
	int to;
	Edge(int x, int y) :cost(x), to(y) {}
};
vector<int> result;
class Vert
{
public:
	int ver;
	list<Edge> ll;
	Vert()
	{
		ver = -4;
	}
	void set(int x)
	{
		ver = x;
	}
	void display()
	{
		cout << ver << "->" << " ";
		for (auto i = ll.begin(); i != ll.end(); i++)
		{
			cout << i->to << " " << i->cost << " ";
		}
		cout << endl;
	}
	void DFS(Vert* arr, int dest, bool* visited, int n, int cost)
	{
		bool flag = 0;
		visited[this->ver] = true;
		result.push_back(this->ver);
		for (auto i = ll.begin(); i != ll.end(); i++)
		{
			if (i->to == dest)
			{
				for (int i = 0; i < result.size(); i++)
				{
					cout << result[i] << " ";
				}
				cout << dest;
				cout << "\n Cost is: " << cost + i->cost;
				exit(0);
			}
			if (!visited[i->to])
			{
				arr[i->to].DFS(arr, dest, visited, n, cost + i->cost);
			}
		}
	}
};
int main()
{
	int n;
	cin >> n;
	Vert* arr = new Vert[n];
	cout << "Name of vertices: ";
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		arr[i].set(x);
	}
	int z;
	cout << "Enter number of edges: ";
	cin >> z;
	int a, b, cost;
	for (int i = 0; i < z; i++)
	{
		cin >> a >> b >> cost;
		for (int i = 0; i < n; i++)
		{
			if (arr[i].ver == a)
			{
				Edge* obj = new Edge(cost, b);
				arr[i].ll.push_back(*obj);
			}
			if (arr[i].ver == b)
			{
				Edge* obj = new Edge(cost, a);
				arr[i].ll.push_back(*obj);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		arr[i].display();
	}
	int source, dest;
	cout << "\nEnter source and dest: ";
	cin >> source >> dest;
	bool* visited = new bool[n];
	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
	}
	int xyz = 0;
	for (; xyz < n; xyz++)
	{
		if (arr[xyz].ver == source)
			break;
	}
	cout << "\nPath is: ";
	arr[xyz].DFS(arr, dest, visited, n, 0);
	cout << "Not found";

}
#include <bits/stdc++.h>

using namespace std;

class adjecency_matrix
{
private:
	int V;

public:
	vector<vector<int>> matrix;
	adjecency_matrix(int V)
	{
		vector<vector<int>> A(V, vector<int>(V, 0));
		this->matrix = A;
		this->V = V;
	}

	void addPath(int V1, int V2)
	{
		this->matrix[V1][V2] = 1;
	}

	void removePath(int V1, int V2)
	{
		this->matrix[V1][V2] = 0;
	}

	void display()
	{
		for (auto r : this->matrix)
		{
			for (auto c : r)
			{
				cout << c << "\t";
			}
			cout << endl;
		}
	}
};

int main()
{
	adjecency_matrix *P = new adjecency_matrix(6);

	P->addPath(4, 3);
	P->addPath(2, 3);
	P->addPath(1, 3);
	P->addPath(4, 1);
	P->addPath(4, 5);
	P->addPath(4, 2);
	P->addPath(3, 3);
	P->addPath(4, 3);

	P->display();

	return 0;
}
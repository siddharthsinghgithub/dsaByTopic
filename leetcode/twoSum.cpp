#include <bits/stdc++.h>
using namespace std;

int calculate(string s)
{

	stack<char> o;
	stack<int> n;

	string num;
	for (int i = 0; i < s.size(); i++)
	{

		if (s[i] == ' ')
			continue;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			num += s[i];
		}
		else if (n.empty())
		{
			cout << num << endl;
			n.push(stoi(num));
			num = "";
		}
		else if (s[i] == '*')
		{
			cout << num << endl;
			int temp = n.top();
			n.pop();
			string s1 = num;

			n.push(temp * stoi(s1));
			num = "";
		}
		else if (s[i] == '/')
		{
			cout << num << endl;
			int temp = n.top();
			n.pop();
			string s1 = num;
			n.push(temp / stoi(s1));
			num = "";
		}
		else if (s[i] == '+' || s[i] == '-')
		{
			cout << num << endl;
			o.push(s[i]);
		}
		else
		{
			string s1 = num;
			n.push(stoi(s1));
			num = "";
		}
	}

	while (!o.empty())
	{

		if (o.top() == '+')
		{
			int temp = n.top();
			n.pop();
			int temp2 = n.top();
			n.pop();
			n.push(temp + temp2);
			o.pop();
		}
		else
		{
			int temp = n.top();
			n.pop();
			int temp2 = n.top();
			n.pop();
			n.push(temp - temp2);
			o.pop();
		}
	}

	return n.top();
}

int main()
{
	cout << calculate(" 33 / 11 ") << "\n";

	//code
	return 0;
}
#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

const int maxN = 200 + 10;
const int maxM = 20000 + 10;

int n, m;

vector<string> cls[maxN];

map<string, int> kind;
set<string> dict;

string buf, str;

int main()
{
	int i, j, k;
	int flag;
	map<string, int>::iterator p;
	set<string>::iterator dp;

	cin >> n >> m;
	for (i = 1; i <= n; ++i)
	{
		cin >> str;
		cout << str << ' ' << str.size() << endl;
		for (j = 0; j < str.size(); j += 2)
		{
			buf = str.substr(j, 1) + str.substr(j + 1, 1);
			kind[buf] = i;
			cls[i].push_back(buf);
		}
		//cout << cls[i].size() << endl;
	}
	for (i = 1; i <= m; ++i)
	{
		cin >> str;
		dict.insert(str);
	}

	cout << endl << dict.size() << endl;

	cin >> str;
	flag = 0;
	for (i = 0; i < str.size(); i += 2)
	{
		buf = str.substr(i, 1) + str.substr(i + 1, 1);
		cout << buf << endl; 
		p = kind.find(buf);
		if (p == kind.end())
		{
			continue;
		}
		k = p->second;
		for (j = 0; j < cls[k].size(); ++j)
		{
			buf = str.substr(0, i) + cls[k][j] + str.substr(i + 2, str.size() - i - 2);
			dp = dict.find(buf);
			if (dp != dict.end())
			{
				flag = 1;
				str = buf;
				break;
			}
		}
		if (flag)
		{
			break;
		}
	}
	cout << str << endl;
	return 0;
}

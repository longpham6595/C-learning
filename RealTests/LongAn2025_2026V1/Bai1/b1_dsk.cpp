#include <bits/stdc++.h>
#include <vector>
using namespace std;
// SPEED UP
#pragma GCC optimize("O2")
#pragma GCC optimize("-ftree-vectorize")
// #pragma GCC optimize("O3") //how good is this? lol
// #pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
// #pragma GCC optimize("unroll-loops")
#define fast_io                   \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);
//============================================================================
// START PROGRAM
//============================================================================
long long n, nLen;
string stn, temptSt;
vector<string> stCom, temptDecode, preAns;
void initAllCompo(string curSt, long long limit, long long pos)
{
	if (pos < 9)
	{
		initAllCompo(curSt, limit, pos + 1);

		if (limit + pos + 1 < nLen)
		{
			curSt[pos] = '1';
			initAllCompo(curSt, limit + pos + 1, pos + 1);
		}
		else if (limit + pos + 1 == nLen || limit + pos + 1 == nLen + 1)
		{
			curSt[pos] = '1';
			stCom.push_back(curSt);
		}
	}
}

vector<string> decodeCompo(string inputSt)
{
	string sourceSt;
	vector<string> funcAns;
	for (int i = 0; i < inputSt.length(); i++)
		if (inputSt[i] == '1')
			for (int j = 0; j < i + 1; j++)
				sourceSt += to_string(i + 1);
	do
	{
		funcAns.push_back(sourceSt);
	} while (next_permutation(sourceSt.begin(), sourceSt.end()));
	return funcAns;
}

bool strSort(string &a, string &b)
{
	if (a.size() > b.size())
		return false;
	if (a.size() < b.size())
		return true;
	return a < b;
}

int main()
{
	fast_io;
	cin >> n;
	temptSt = "000000000";
	stn = to_string(n);
	nLen = stn.length();
	initAllCompo(temptSt, 0, 0);

	for (auto it : stCom)
	{
		temptDecode = decodeCompo(it);
		preAns.insert(preAns.end(), temptDecode.begin(), temptDecode.end());
	}

	sort(preAns.begin(), preAns.end(), strSort);

	for (auto it : preAns)
		if (!strSort(it, stn) && it != stn)
		{
			cout << it << endl;
			break;
		}
	// getchar();
}
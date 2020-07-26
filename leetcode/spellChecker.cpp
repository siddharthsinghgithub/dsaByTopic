#include <bits/stdc++.h>

using namespace std;

string toLowerCaseWord(string str)
{
	for (auto &ch : str)
		ch = tolower(ch);

	return str;
}

string toWordWithoutVowels(string str)
{
	for (auto &ch : str)
		if (isVowel(ch))
			ch = '-';

	return str;
}

bool isVowel(char ch)
{
	return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u';
}

vector<string> spellchecker(vector<string> wordlist, vector<string> queries)
{
	unordered_set<string> us;
	unordered_map<string, string> um;
	vector<string> result;

	for (auto word : wordlist)
	{
		us.insert(word);

		string lowerCaseWord = toLowerCaseWord(word);
		string wordWithoutVowels = toWordWithoutVowels(lowerCaseWord);

		um.insert({lowerCaseWord, word});
		um.insert({wordWithoutVowels, word});
	}

	for (auto query : queries)
	{
		if (us.count(query))
		{
			result.push_back(query);
			continue;
		}

		query = toLowerCaseWord(query);
		if (um.count(query))
		{
			result.push_back(um[query]);
			continue;
		}

		query = toWordWithoutVowels(query);
		if (um.count(query))
		{
			result.push_back(um[query]);
			continue;
		}

		result.push_back("");
	}

	for (auto r : result)
		cout << r << " ";
	return result;
}

int main()
{

	spellchecker({"KiTe", "kite", "hare", "Hare"}, {"kite", "Kite", "KiTe", "Hare", "HARE", "Hear", "hear", "keti", "keet", "keto"});
	return 0;
}
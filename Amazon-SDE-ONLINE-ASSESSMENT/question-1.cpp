#include <bits/stdc++.h>

using namespace std;

map<string, int> M;
int comp(pair<string, int> s1, pair<string, int> s2)
{
	if (s1.second > s2.second)
	{
		return true;
	}
	else
	{
		return false;
	}
}

vector<string> popularNFeatures(int numFeatures,
								int topFeatures,
								vector<string> possibleFeatures,
								int numFeatureRequests,
								vector<string> featureRequests)
{

	for (int i = 0; i < possibleFeatures.size(); i++)
	{
		transform(possibleFeatures[i].begin(), possibleFeatures[i].end(), possibleFeatures[i].begin(), ::tolower);
		M[possibleFeatures[i]] = 1;
	}

	for (int j = 0; j < featureRequests.size(); j++)
	{
		transform(featureRequests[j].begin(), featureRequests[j].end(), featureRequests[j].begin(), ::tolower);
	}

	for (int i = 0; i < possibleFeatures.size(); i++)
	{

		for (int j = 0; j < featureRequests.size(); j++)
		{

			if (featureRequests[j].find(possibleFeatures[i]) < featureRequests[j].size())
			{
				M[possibleFeatures[i]]++;
			}
		}
	}

	vector<pair<string, int>> V(M.begin(), M.end());
	sort(V.begin(), V.end(), comp);

	vector<string> vs;
	for (int i = 0; i < topFeatures; i++)
	{
		cout << V[i].first << "\t";
		vs.push_back(V[i].first);
	}
	return vs;
}

int main()
{
	vector<string> possibleFeatures = {"storage", "battery", "hover", "alexa", "waterproof", "solar"};
	vector<string> featureRequests = {
		"I wish my kindle had even more storage",
		"I wish the battery life on kindle lasted two years",
		"Waterproof and increased battery are my top priority",
		"I read in the bath and would enjoy a waterproof kindle",
		"waterproof and increased battery life are my top two request",
		"I want to take my kindle in the shower Waterproof please waterproof"
		"It would be neat if my kindle would hover on the desk when not in use",
		"How cool it would be if my kindle charged in the sun via solar power"};

	popularNFeatures(6, 2, possibleFeatures, 8, featureRequests);
	return 0;
}
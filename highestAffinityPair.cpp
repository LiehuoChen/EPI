#include <set>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>

using namespace std;

pair<string, string> highestAffinityPair( istream &ifs) {
	unordered_map<string, set<string>> page_user_map;
	string page, user;
	while (ifs >> page >> user) {
		page_user_map[page].insert(user);
	}
    pair<string, string> result;
	int max_count = 0;
	for (auto a = page_user_map.begin(); a != page_user_map.end(); a++) {
		auto b = a;
		for (advance(b, 1); b != page_user_map.end(); b++)
		{
			vector<string> intersect_users;
			set_intersection(a->second.begin(), a->second.end(),
					b->second.begin(), b->second.end(),
					back_inserter(intersect_users));
			if (intersect_users.size() > (size_t)max_count) {
				max_count = intersect_users.size();
				result = {a->first, b->first};
			}
		}
	}
	return result;
}

int main(void) {
    pair<string, string> res = highestAffinityPair(cin);
	cout << "{ " << res.first << " -> " << res.second << " }" << endl;
    return 0;
}

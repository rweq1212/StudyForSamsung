#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int L;
int C;
char vowel[5] = { 'a','e','i','o','u' };
bool*visited;
vector<int>num;
vector<char>result;

void recursive();

int main() {
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		char in;
		cin >> in;
		num.push_back(in);
	}
	sort(num.begin(), num.end());
	visited = new bool[num.size()];
	for (int i = 0; i < C; i++) {
		visited[i] = false;
	}

	recursive();

	delete[] visited;
	//system("pause");
	return 0;
}

void recursive() {
	if (result.size() == L) {
		int v_cnt = 0;
		int c_cnt = 0;
		for (int i = 0; i < result.size(); i++) {
			for (int j = 0; j < 5; j++) {
				if (result[i] == vowel[j]) {
					v_cnt++;
					break;
				}
				if (j == 4) {
					c_cnt++;
				}
			}
		}
		if (v_cnt < 1 || c_cnt < 2)
			return;

		for (char y : result) {
			cout << y;
		}
		cout << endl;
		return;
	}

	for (int i = 0; i < C; i++) {
		if (!visited[i] && result.size() == 0) {
			visited[i] = true;
			result.push_back((char)num[i]);
			recursive();
			result.pop_back();
			visited[i] = false;
		}
		if (!visited[i] && result.size() > 0 && (int)result.back() < num[i]) {
			visited[i] = true;
			result.push_back((char)num[i]);
			recursive();
			result.pop_back();
			visited[i] = false;
		}

	}

}
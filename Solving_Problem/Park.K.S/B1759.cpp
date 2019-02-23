#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int L, C;
vector<char> v(15);

bool isvalid(string s) {
	int j = 0, m = 0;
	for (char c : s) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			m++;	// ���� ���� ����
		else
			j++;	// ���� ���� ����
	}
	return j >= 2 && m >= 1;	// ���� 2�� �̻�, ���� 1�� �̻� ���� ���� ���� ��ȯ
}

void go(int i, string s) {
	if (i == C) {
		if (s.length() == L && isvalid(s))
			cout << s << endl;	// ���ɼ� �ִ� ��ȣ ���
		return;
	}

	go(i + 1, s + v[i]);
	go(i + 1, s);
}

int main(void) {
	// �Էº�
	cin >> L >> C;
	for (int i = 0; i < C; i++)
		cin >> v[i];

	// ó����
	sort(v.begin(), v.begin() + C);
	go(0, "");

	return 0;
}
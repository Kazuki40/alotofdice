#include<iostream>
#include<vector>
#include<random>
#include<cmath>
#include<fstream>
#include<iomanip>
#include"shack.h"

using namespace std;

int main() {

	unsigned int n;
	unsigned int i;
	bool a;

	cout << "サイコロの個数を入力してください！" << endl;
	cout << "excel max16384まで 以外 1000000000(10億個まで)" << endl;
	cin >> n;

	shack ans;
	ans.roll(n);

	cout << "結果を見ますか？\n" << "Yes:1,No:0" << endl;
	cin >> a;

	if (a == 0) {
		cout << "スキップ" << endl;
	}
	else {
		for (i = 0; i < n; i++) {
			cout << ans.value[i] << " ";
		}
		cout << endl;
	}

	cout << "詳細を見ますか？\n" << "Yes:1,No:0" << endl;
	cin >> a;

	if (a == 0) {
		cout << "終わります" << endl;
	}
	else {
		ans.summary();
	}

	return 0;
}
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

	cout << "�T�C�R���̌�����͂��Ă��������I" << endl;
	cout << "excel max16384�܂� �ȊO 1000000000(10���܂�)" << endl;
	cin >> n;

	shack ans;
	ans.roll(n);

	cout << "���ʂ����܂����H\n" << "Yes:1,No:0" << endl;
	cin >> a;

	if (a == 0) {
		cout << "�X�L�b�v" << endl;
	}
	else {
		for (i = 0; i < n; i++) {
			cout << ans.value[i] << " ";
		}
		cout << endl;
	}

	cout << "�ڍׂ����܂����H\n" << "Yes:1,No:0" << endl;
	cin >> a;

	if (a == 0) {
		cout << "�I���܂�" << endl;
	}
	else {
		ans.summary();
	}

	return 0;
}
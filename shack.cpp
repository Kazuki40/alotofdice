#include "shack.h"
#include<iostream>
#include<vector>
#include<random>
#include<cmath>
#include<fstream>
#include<iomanip>

using namespace std;

shack::shack() {

	i = 0;
	sum = 0;
	av = 0;
	v = 0;
	kakuritu = 0;
	var = 0;
	n = 0;

	for (i = 0; i < 6; i++) {
		val[i] = 0;
	}

}

void shack::roll(unsigned int n) {

	//�T�C�R���̏���
	random_device rad1;
	mt19937_64 rad2(rad1());
	uniform_int_distribution<> dist(1, 6);

	//�T�C�R���ӂ�
	cout << "�T�C�R���ӂ�" << endl;

	for (i = 0; i < n; i++) {

		value.push_back(dist(rad2));
		val[(int)value[i] - 1] ++;

	}
	cout << "�����" << endl;

	return;
}

void shack::summary() {

	n = value.size();

	cout << "�m���F" << endl;

	for (i = 0; i < 6; i++) {

		kakuritu = (val[i] / (long double)n) * 100;
		sum += (1 + i) * val[i];
		var += ((pow((i + 1), 2)) * val[i]) / n;
		cout << fixed << setprecision(1) << i + 1 << ": " << kakuritu << " %" << " �F" << val[i] << endl;

	}

	//���ρ@���U
	av = (long double)sum / n;
	v = var - pow(av, 2);


	//��������
	cout << "���F" << n << endl;
	cout << "���a�F" << sum << endl;
	cout << fixed << setprecision(3) << "����: " << av << endl;
	cout << fixed << setprecision(3) << "�W�{���U: " << v << endl;

	//�t�@�C��
	cout << "�t�@�C���ɏ������݂܂����H\n" << "Yes:1,No:0" << endl;
	cin >> i;

	if (i == 1) {
		write();
	}

	return;

}


void shack::write() {

	ofstream csv("ans.csv");
	n = value.size();

	//��������
	csv << "��:," << n << ",����:," << av << ",�W�{���U:," << v << ",���a:," << sum << endl;
	csv << "����" << endl;
	for (i = 0; i < 6; i++)csv << i + 1 <<","<< val[i] << endl;
	csv << "�T�C�R������" << endl;
	for (i = 0; i < n; i++)csv << value[i] << ",";
	csv << endl;

	return;
}
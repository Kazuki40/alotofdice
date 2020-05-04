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

	//サイコロの準備
	random_device rad1;
	mt19937_64 rad2(rad1());
	uniform_int_distribution<> dist(1, 6);

	//サイコロふる
	cout << "サイコロふる" << endl;

	for (i = 0; i < n; i++) {

		value.push_back(dist(rad2));
		val[(int)value[i] - 1] ++;

	}
	cout << "おわり" << endl;

	return;
}

void shack::summary() {

	n = value.size();

	cout << "確率：" << endl;

	for (i = 0; i < 6; i++) {

		kakuritu = (val[i] / (long double)n) * 100;
		sum += (1 + i) * val[i];
		var += ((pow((i + 1), 2)) * val[i]) / n;
		cout << fixed << setprecision(1) << i + 1 << ": " << kakuritu << " %" << " 個：" << val[i] << endl;

	}

	//平均　分散
	av = (long double)sum / n;
	v = var - pow(av, 2);


	//書き込み
	cout << "個数：" << n << endl;
	cout << "総和：" << sum << endl;
	cout << fixed << setprecision(3) << "平均: " << av << endl;
	cout << fixed << setprecision(3) << "標本分散: " << v << endl;

	//ファイル
	cout << "ファイルに書き込みますか？\n" << "Yes:1,No:0" << endl;
	cin >> i;

	if (i == 1) {
		write();
	}

	return;

}


void shack::write() {

	ofstream csv("ans.csv");
	n = value.size();

	//書き込み
	csv << "個数:," << n << ",平均:," << av << ",標本分散:," << v << ",総和:," << sum << endl;
	csv << "内訳" << endl;
	for (i = 0; i < 6; i++)csv << i + 1 <<","<< val[i] << endl;
	csv << "サイコロ結果" << endl;
	for (i = 0; i < n; i++)csv << value[i] << ",";
	csv << endl;

	return;
}
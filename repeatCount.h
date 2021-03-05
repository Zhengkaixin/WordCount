#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "word.h";
using namespace std;
class repeatCount {
private:
	int number;
	my_word* myword;
	vector<string> v_sort;//��������
	vector<string> v;//��������Ƶ����ߵ�10����
	vector<string>::iterator it;
	int* num;

public:
	repeatCount(int n) {
		myword = new my_word[100];
		num = (int*)malloc((n + 1) * sizeof(int));
	}

	int getNumber() {
		return number;
	}

	void setNumber(int number_1) {
		number = number_1;
	}

	void outWord(fstream& outputFile) {
		for (it = v.begin();it != v.end();it++) {
			outputFile << *it << endl;
		}
	}

	void wordFrequence(fstream& inputFile) {
		//string str;
		char data[256];
		int tmp = 0;
		int tmp_1 = 0;//ͳ�Ƶ��ʿ�ͷ��ĸ����
		int tmp_2 = 0;//��¼���ʿ�ͷ���ֵ�λ��
		bool flag = true;//��־�ָ���
		
		while (inputFile.getline(data,256)){
			for (int i = 0;i < strlen(data);i++) {
				if (isalpha(data[i])) {
					data[i]=tolower(data[i]);
				}//ȫ��ת��ΪСд
				if ((data[i] >= 'a' && data[i] <= 'z') || (data[i] >= 'A' && data[i] <= 'Z')||(tmp_1>=4&& (data[i] >= '0' && data[i] <= '9'))){
					if (flag) {
						if (tmp_1 == 0) {
							tmp_2 = i;
						}
						tmp_1++;
					}
				}
				else if ((data[i] >= '0' && data[i] <= '9') && tmp_1 < 4) {
					tmp_1 = 0;
					flag = false;
				}
				else if (!((data[i] >= 'a' && data[i] <= 'z') || (data[i] >= '0' && data[i] <= '9'))) {
					flag = true;
					if (tmp_1 < 4) {
						tmp_1 = 0;
					}
					else {
						char ch[256]=" ";
						for (int a=0;a<i;a++) {
							ch[a] = data[tmp_2];
							tmp_2++;
						}
						ch[i] = '\0';
						
						string ch_1(ch);
						int z = 0;
						for (z = 0;z < tmp;z++) {
							if (ch_1 == myword[z].getStr()) {
								myword[z].addFreque();
								break;
							}
						}
						if (z == tmp) {
							myword[tmp].setStr(ch_1);
							myword[tmp].addFreque();
							tmp++;
						}
						tmp_1 = 0;
					}
				}
			}
			if (tmp_1 >= 4) {
				char ch[256]=" ";
				for (int a = 0;a < tmp_1;a++) {
					ch[a] = data[tmp_2];
					tmp_2++;
				}
				ch[tmp_1] = '\0';
				string ch_1(ch);
				int z = 0;
				for (z = 0;z < tmp;z++) {
					if (ch_1 == myword[z].getStr()) {
						myword[z].addFreque();
						break;
					}
				}
				if (z == tmp) {
					myword[tmp].setStr(ch_1);
					myword[tmp].addFreque();
					tmp++;
				}
				tmp_1 = 0;
			}
		}
		cout << tmp << endl;
		setNumber(tmp);
		mySort();
	}

	void mySort() {
		int max = myword[0].getFreque();
		int max_1=0;
		int max_2 = 0;
		int max_len = 0;//����ֵĵ�����Ŀ
		num[0] = 0;
		for (int j = 0;j < number;j++) {
			if (myword[j].getFreque() > max) {
				max = myword[j].getFreque();
				num[0] = j;
			}
		}
		//v.push_back(myword[num[0]].getStr());
		for (int i = 1;i < number;i++) {
			v_sort.push_back(myword[num[i - 1]].getStr());
			max_len = i;
			for (int j = 0;j < number;j++) {
				if (myword[j].getFreque() == max && j!=num[i-1]) {
					num[i] = j;
					i++;
				}
			}
			if (i > max_len) {
				for (int a = max_len;a < i;a++) {
					v_sort.push_back(myword[num[a]].getStr());
				}
				sort(v_sort.begin(), v_sort.end());
				for (it = v_sort.begin();it != v_sort.end();it++) {
					v.push_back(*it);
				}
				v_sort.clear();
			}
			else {
				it = v_sort.begin();
				v.push_back(*it);
				v_sort.clear();
			}

			if (i >= 10) {
				max_len = i;
				break;
			}
			for (int j = 0;j < number;j++) {
				if (myword[j].getFreque() < max) {
					max_1 = myword[j].getFreque();
					num[i] = j;
					break;
				}
			}
			for (int j = 0;j < number;j++) {
				if (myword[j].getFreque() > max_1 && myword[j].getFreque() < max) {
					max_1 = myword[j].getFreque();
					num[i] = j;
				}
			}
			max = max_1;
		}
		for (it = v.begin();it != v.end();it++) {
			max_2++;
		}
		if (max_2 < 10 && number>10) {
			v.push_back(myword[num[max_2]].getStr());
		}
	}
};
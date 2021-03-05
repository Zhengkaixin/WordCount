#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include"word.h";
using namespace std;
class repeatCount {
private:
	int number;
	my_word* myword;
	vector<string> v_sort;//用来排序
	vector<string> v;//用来保存频率最高的10个词
	vector<string>::iterator it;
	int* num;
public:
	repeatCount(int n) {
		myword = (my_word*)malloc((n + 1) * sizeof(my_word));
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
		string str;
		int tmp = 0;
		int tmp_1 = 0;//统计单词开头字母个数
		int tmp_2 = 0;//记录单词开头部分的位置
		bool flag = true;//标志分隔符
		
		while (inputFile >> str) {
			char* data;
			int len = str.length();
			data = (char*)malloc((len + 1) * sizeof(char));
			str.copy(data, len, 0);
			for (int i = 0;i < len;i++) {
				if (isalpha(data[i])) {
					tolower(data[i]);
				}//全部转换为小写
				if ((data[i] >= 'a' && data[i] <= 'z') || (data[i] >= 'A' && data[i] <= 'Z')) {
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
				else if (!((data[i] >= 'a' && data[i] <= 'z') ||/* (data[i] >= 'A' && data[i] <= 'Z') ||*/ (data[i] >= '0' && data[i] <= '9'))) {
					flag = true;
					if (tmp_1 < 4) {
						tmp_1 = 0;
					}
					else {
						char* ch= (char*)malloc((tmp_1 + 1) * sizeof(char));
						for (int a=0;a<tmp_1;a++) {
							ch[a] = data[tmp_2];
							tmp_2++;
						}
						myword[tmp].setStr(ch);
						myword[tmp].addFreque();
						tmp++;
						tmp_1 = 0;
						
					}
				}
			}
			if (tmp_1 >= 4) {
				char* ch = (char*)malloc((tmp_1 + 1) * sizeof(char));
				for (int a = 0;a < tmp_1;a++) {
					ch[a] = data[tmp_2];
					tmp_2++;
				}
				myword[tmp].setStr(ch);
				myword[tmp].addFreque();
				tmp++;
				tmp_1 = 0;
			}
		}
		setNumber(tmp);
		mySort();
	}

	void mySort() {
		int max = myword[0].getFreque();
		int max_1;
		int max_len = 10;//最常出现的单词数目
		num[0] = 0;
		for (int j = 0;j < number;j++) {
			if (myword[j].getFreque() > max) {
				max = myword[j].getFreque();
				num[0] = j;
			}
		}
		for (int i = 1;i < number;i++) {
			for (int j = 0;j < number;j++) {
				max_len = i;
				if (myword[j].getFreque() == max) {
					num[i] = j;
					i++;
				}
			}

			if (i > max_len) {
				for (int a = max_len;a < i;a++) {
					v_sort.push_back(myword[a].getStr());
				}
				sort(v_sort.begin(), v_sort.end());
				for (it = v_sort.begin();it != v_sort.end();it++) {
					v.push_back(*it);
				}
				v_sort.clear();
			}
			else {
				v.push_back(myword[i].getStr());
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
					num[0] = j;
				}
			}
			max = max_1;
		}
	}
};
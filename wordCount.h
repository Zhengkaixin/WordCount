#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class wordCount {
private:
	int number;
public:
	int getNumber() {
		return number;
	}

	void setNumber(int number_1) {
		number = number_1;
	}

	void wordcount(fstream& inputFile) {
		string str;
		int tmp = 0;
		int tmp_1 = 0;//ͳ�Ƶ��ʿ�ͷ��ĸ����
		bool flag = true;//��־�ָ���
		while (inputFile>>str) {
			char* data;
			int len = str.length();
			data = (char*)malloc((len + 1) * sizeof(char));
			str.copy(data, len, 0);
			for (int i = 0;i < len;i++) {
				if (isalpha(data[i])) {
					tolower(data[i]);
				}//ȫ��ת��ΪСд
				if ((data[i] >= 'a' && data[i] <= 'z') || (data[i] >= 'A' && data[i] <= 'Z')) {
					if (flag) {
						tmp_1++;
					}
				}
				else if ((data[i] >= '0' && data[i] <= '9')&&tmp_1 < 4) {
					tmp_1 = 0;
					flag = false;
				}
				else if (!((data[i] >= 'a' && data[i] <= 'z') ||/* (data[i] >= 'A' && data[i] <= 'Z') ||*/ (data[i] >= '0' && data[i] <= '9'))) {
					flag = true;
					if (tmp_1 < 4) {
						tmp_1 = 0;
					}
					else {
						tmp_1 = 0;
						tmp++;
					}
				}
			}
			if (tmp_1 >= 4) {
				tmp++;
				tmp_1 = 0;
			}
		}
		setNumber(tmp);
	}
};
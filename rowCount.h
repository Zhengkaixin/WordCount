#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class rowCount {
private:
	int number;
public:
	int getNumber() {
		return number;
	}

	void setNumber(int number_1) {
		number = number_1;
	}

	void rowcount(fstream& inputFile) {
		string str;
		int tmp = 0;
		while (getline(inputFile,str)) {
			char* data;
			int len = str.length();
			data = (char*)malloc((len + 1) * sizeof(char));
			str.copy(data, len, 0);
			for (int i = 0;i < len;i++) {
				if (data[i] != ' ') {
					tmp++;
					break;
				}
			}
		}
		setNumber(tmp);
	}
};
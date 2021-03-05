// Wordcount.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <iostream>
#include <string>
#include <fstream>
#include "charCount.h"
#include "repeatCount.h"
#include "rowCount.h"
#include "wordCount.h"

using namespace std;
int main(int argc, char* argv[])
{
	fstream stream;
	stream.open("input.txt", ios::in);
	charCount charcount;
	wordCount wordcount;
	rowCount rowcount;
	charcount.charcount(stream);
	stream.close();
	stream.open("input.txt", ios::in);
	wordcount.wordcount(stream);
	stream.close();
	stream.open("input.txt", ios::in);
	rowcount.rowcount(stream);
	stream.close();
	stream.open("input.txt", ios::in);
	repeatCount repeatcount(wordcount.getNumber());
	repeatcount.wordFrequence(stream);
	stream.close();

	stream.open("output.txt", ios::out);
	stream << charcount.getNumber() << endl;
	stream << wordcount.getNumber() << endl;
	stream << rowcount.getNumber() << endl;
	repeatcount.outWord(stream);
	stream.close();
	cout << "����ļ��ɹ�" << endl;

}

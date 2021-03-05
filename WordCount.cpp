// Wordcount.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
	cout << "输出文件成功" << endl;

}

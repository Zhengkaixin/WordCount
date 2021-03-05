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
int main(int argc,char* argv[] )
{
	fstream stream;
	stream.open(argv[1], ios::in);
	charCount charcount;
	wordCount wordcount;
	rowCount rowcount;
	charcount.charcount(stream);
	wordcount.wordcount(stream);
	rowcount.rowcount(stream);
	repeatCount repeatcount(wordcount.getNumber());
	stream.close();

	stream.open(argv[2], ios::out);
	stream << charcount.getNumber() << endl;
	stream << wordcount.getNumber() << endl;
	stream << rowcount.getNumber() << endl;
	repeatcount.outWord(stream);
	stream.close();

}

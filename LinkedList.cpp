#include "LinkedList.h"

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main() {

	LinkedList<string> list;
	string cmd;
	int index;
	string item;

	ifstream in;
	in.open("in53.txt");

	ofstream out;
	out.open("actual.txt");

	while (in >> cmd) {
		if (cmd == "clear") {
			out << "clear" << endl;
			list.clear();
		}
		if (cmd == "insert") {
			in >> index;
			in >> item;
			out << "insert " << index << " " << item << endl;
			list.insert(index, item);
		}
		if (cmd == "remove") {
			in >> index;
			out << "remove " << index << " " << list.remove(index) << endl;
		}
		if (cmd == "find") {
			in >> item;
			out << "find " << item << " " << list.find(item) << endl;
		}
		if (cmd == "print") {
			list.print(out);
		}
	}

	out.close();

	system("pause");
	return 0;
}
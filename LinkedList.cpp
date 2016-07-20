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
	in.open("insert.txt");

	while (in >> cmd) {
		if (cmd == "clear") {
			list.clear();
		}
		if (cmd == "insert") {
			in >> index;
			in >> item;
			list.insert(index, item);
		}
		if (cmd == "remove") {
			in >> index;
			list.remove(index);
		}
		if (cmd == "find") {
			in >> item;
			list.find(item);
		}
		if (cmd == "print") {
			list.print();
		}
	}



	system("pause");
	return 0;
}
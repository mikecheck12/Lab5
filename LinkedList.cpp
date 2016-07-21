#include "LinkedList.h"

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(int argc, char* argv[]) {

	LinkedList<string> list;
	string cmd;
	int index;
	string item;

	ifstream in;
	in.open(argv[1]);

	ofstream out;
	out.open(argv[2]);

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

	return 0;
}
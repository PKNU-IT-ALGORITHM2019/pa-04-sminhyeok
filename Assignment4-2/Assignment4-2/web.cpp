#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

struct log {
	string IP, Time, URL, Status;
}typedef LOG;
// IP���� Status�� ���ı���
bool compare1(const LOG& x, const LOG& y) { return x.IP < y.IP; }
bool compare2(const LOG& x, const LOG& y) { return x.Time < y.Time; }
bool compare3(const LOG& x, const LOG& y) { return x.URL < y.URL; }
bool compare4(const LOG& x, const LOG& y) { return x.Status < y.Status; }

int index[4] = { 0,1,2,3 };	// ������ ��, ǥ���� ���� 
// print�� ����
string index2[4] = { "    IP: ","    Time: ", "    URL: ", "    Status: " };
vector<LOG> csv;

void process();
void read(string file);
void sort(string type);
void print();

int main() {
	process();
}

void process() {
	string parse, cmd = "";

	while (cmd != "exit") {
		cout << "$ ";
		getline(cin, cmd);
		stringstream ss(cmd);
		ss >> parse;

		if (parse == "read") {
			string name;
			if (ss >> name) read(name);
		}
		else if (parse == "sort") {
			string type;
			if (ss >> type) sort(type);
		}
		else if (parse == "print") print();
	}


}


void read(string file) {
	ifstream fin(file);
	if (!fin) {
		cout << "Failed to open file\n";
		return;
	}
	string parse;
	getline(fin, parse);	// �ʵ�� ����

	while (getline(fin, parse, ',')) {
		LOG temp;
		temp.IP = parse;
		getline(fin, parse, '[');
		getline(fin, parse, ',');
		temp.Time = parse;
		getline(fin, parse, ',');
		temp.URL = parse;
		getline(fin, parse);
		temp.Status = parse;
		csv.push_back(temp);
	}// csv ���Ϳ� , �� �����Ͽ� csv������ ����

}
void sort(string type) {	// ���� ���, ��� ���� ����
	if (type == "-ip") { sort(csv.begin(), csv.end(), compare1); index[0] = 0; index[1] = 1; index[2] = 2; index[3] = 3; }
	else if (type == "-t") { sort(csv.begin(), csv.end(), compare2); index[0] = 1; index[1] = 0; index[2] = 2; index[3] = 3; }
	else if (type == "-u") { sort(csv.begin(), csv.end(), compare3); index[0] = 2; index[1] = 0; index[2] = 1; index[3] = 3; }
	else if (type == "s") { sort(csv.begin(), csv.end(), compare4); index[0] = 3; index[1] = 0; index[2] = 1; index[3] = 2; }
}
void print() {
	for (int i = 0; i < csv.size(); i++) {
		string temp[4];
		temp[0] = csv.at(i).IP;
		temp[1] = csv.at(i).Time;
		temp[2] = csv.at(i).URL;
		temp[3] = csv.at(i).Status;

		cout << temp[index[0]] << "\n";
		for (int j = 1; j <= 3; j++) {
			cout << index2[index[j]] << temp[index[j]] << "\n";
		}
	}
}
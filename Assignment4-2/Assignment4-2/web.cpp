#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

struct log {
	string IP, Time, URL, Status;	// IP, �ð� �� �� �� ��, URL, Status
}typedef LOG;

string month[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
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
void change(int n);		// 0�� ������ ����  ��/��/�� ������ ��ȯ, 1�� ���� �� ��/��/�� ������ ����

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
// 30/Nov/2017:14:27:53
void change(int n) {
	if (n == 0) {
		for (int i = 0; i < csv.size(); i++) {
			string tempD = csv.at(i).Time.substr(0, 2);
			string tempM = csv.at(i).Time.substr(3,3);
			string tempY = csv.at(i).Time.substr(7, 4);
			for(int j = 100; j < 112; j++)
				if (tempM == month[j - 100]) { csv.at(i).Time.replace(3,3,to_string(j)); break; }	// ���� ���ڷ� ��ȯ
			csv.at(i).Time.replace(7,4,tempD);		// ��, �� ��ġ ��ȯ
			csv.at(i).Time.replace(0, 2, tempY);	
		}
	}
	else {
		
		for (int i = 0; i < csv.size(); i++) {
			string tempD = csv.at(i).Time.substr(9, 2);
			string tempY = csv.at(i).Time.substr(0, 4);
			csv.at(i).Time.replace(0, 4, tempD);		// ��, �� ��ġ ��ȯ
			csv.at(i).Time.replace(7, 2, tempY);

			int index = stoi(csv.at(i).Time.substr(3,3))-100;
			csv.at(i).Time.replace(3, 3, month[index]);
		}
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
		getline(fin, parse, '[');	// [ ����
		getline(fin, parse, ',');	// parse�� �ð� ����
		temp.Time = parse;
		getline(fin, parse, ',');	// parse�� URL ����
		temp.URL = parse;
		getline(fin, parse);		// parse�� Status����
		temp.Status = parse;
		csv.push_back(temp);
	}// csv ���Ϳ� , �� �����Ͽ� csv������ ����
	change(0);
}
void sort(string type) {	// ���� ���, ��� ���� ����
	if (type == "-ip") { sort(csv.begin(), csv.end(), compare1); index[0] = 0; index[1] = 1; index[2] = 2; index[3] = 3; }
	else if (type == "-t") { 
		sort(csv.begin(), csv.end(), compare2); 
		change(1);
		index[0] = 1; index[1] = 0; index[2] = 2; index[3] = 3; 
	}
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
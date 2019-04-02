#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

struct log {
	string IP, Time, URL, Status;	// IP, 시간 연 월 일 시, URL, Status
}typedef LOG;
vector<LOG> csv;

// IP부터 Status순 정렬까지
bool compare1(const LOG& x, const LOG& y) { return x.IP < y.IP; }
bool compare2(const LOG& x, const LOG& y) { return x.Time < y.Time; }
bool compare3(const LOG& x, const LOG& y) { return x.URL < y.URL; }
bool compare4(const LOG& x, const LOG& y) { return x.Status < y.Status; }

int index[4] = { 0,1,2,3 };	// 정렬한 후, 표기할 순서 Print에 이용
string index2[4] = { "    IP: ","    Time: ", "    URL: ", "    Status: " };
string month[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };


void process();
void change(int n);		// 0은 정렬을 위해  연/월/일 순으로 변환, 1은 정렬 후 일/월/연 순으로 복원
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

void change(int n) {
	if (n == 0) {
		for (int i = 0; i < csv.size(); i++) {
			string tempD = csv.at(i).Time.substr(0, 2);
			string tempM = csv.at(i).Time.substr(3,3);
			string tempY = csv.at(i).Time.substr(7, 4);
			for(int j = 100; j < 112; j++)
				if (tempM == month[j - 100]) { csv.at(i).Time.replace(3,3,to_string(j)); break; }	// 월을 숫자로 변환
			csv.at(i).Time.replace(7,4,tempD);		// 연, 일 위치 교환
			csv.at(i).Time.replace(0, 2, tempY);	
		}
	}
	else {
		
		for (int i = 0; i < csv.size(); i++) {
			string tempD = csv.at(i).Time.substr(9, 2);
			string tempY = csv.at(i).Time.substr(0, 4);
			csv.at(i).Time.replace(0, 4, tempD);		// 연, 일 위치 교환
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
	getline(fin, parse);	// 필드명 생략

	while (getline(fin, parse, ',')) {
		LOG temp;
		temp.IP = parse;
		getline(fin, parse, '[');	// [ 제거
		getline(fin, parse, ',');	// parse에 시간 저장
		temp.Time = parse;
		getline(fin, parse, ',');	// parse에 URL 저장
		temp.URL = parse;
		getline(fin, parse);		// parse에 Status저장
		temp.Status = parse;
		csv.push_back(temp);
	}// csv 벡터에 , 로 구분하여 csv데이터 저장
}

void sort(string type) {	// 정렬 방식, 출력 순서 선택
	if (type == "-ip") { sort(csv.begin(), csv.end(), compare1); index[0] = 0; index[1] = 1; index[2] = 2; index[3] = 3; }
	else if (type == "-t") { 
		change(0);	// 정렬 위해 순서변환
		sort(csv.begin(), csv.end(), compare2); 
		change(1);	// 출력 위해 순서복원
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
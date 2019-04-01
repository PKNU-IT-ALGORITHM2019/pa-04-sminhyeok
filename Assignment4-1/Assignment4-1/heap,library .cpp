#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <time.h>
using namespace std;
int N, *datas;										// 데이터의 크기, 데이터가 담길 배열

void init(int n);
void analyze();
void BubbleSort(int n);
void SelectionSort(int n);
void InsertSort(int n);
void MergeSort(int first, int last);
void Merge(int first, int middle, int last);
void QuickSort1(int first, int last);
void QuickSort2(int first, int last);
void QuickSort3(int first, int last);
void Heapify(int i);
void HeapBuild();
void HeapSort();

int main() {
	analyze();
}

void init(int n) {
	if (n == 0 || n == 1) N = 1000;
	else if (n == 2 || n == 3) N = 10000;
	else N = 100000;

	if (n % 2 == 0) {
		for (int i = 1; i <= N; i++)
			datas[i] = 1 + rand() % N;
	}
	else {
		for (int i = 1; i <= N; i++)
			datas[i] = N + 1 - i;
	}
}

void analyze() {
	datas = new int[100001];

	clock_t begin, end;
	vector<int> library;
	cout << "               Random1000     Reverse1000     Random10000     Reverse10000     Random100000     Reverse100000\n";

	cout << "Bubble            ";
	for (int i = 0; i <= 5; i++) {
		double mean = 0;
		if (i % 2 == 0) {	// 랜덤 데이터는	10개의 테스트 데이터 실행후 평균 구함
			for (int j = 0; j < 10; j++) {
				init(i);
				begin = clock();
				BubbleSort(N);
				end = clock();
				mean += (double)(end - begin);
			}
			mean /= 10;
		}
		else {
			init(i);
			begin = clock();
			BubbleSort(N);
			end = clock();
			mean += (double)(end - begin);
		}
		cout << mean / 1000 << "s          ";
	}
	cout << "\nSelection         ";
	for (int i = 0; i <= 5; i++) {
		double mean = 0;
		if (i % 2 == 0) {	// 랜덤 데이터는	10개의 테스트 데이터 실행후 평균 구함
			for (int j = 0; j < 10; j++) {
				init(i);
				begin = clock();
				SelectionSort(N);
				end = clock();
				mean += (double)(end - begin);
			}
			mean /= 10;
		}
		else {
			init(i);
			begin = clock();
			SelectionSort(N);
			end = clock();
			mean += (double)(end - begin);
		}
		cout << mean / 1000 << "s          ";
	}
	cout << "\nInsertion         ";
	for (int i = 0; i <= 5; i++) {
		double mean = 0;
		if (i % 2 == 0) {	// 랜덤 데이터는	10개의 테스트 데이터 실행후 평균 구함
			for (int j = 0; j < 10; j++) {
				init(i);
				begin = clock();
				InsertSort(N);
				end = clock();
				mean += (double)(end - begin);
			}
			mean /= 10;
		}
		else {
			init(i);
			begin = clock();
			InsertSort(N);
			end = clock();
			mean += (double)(end - begin);
		}
		cout << mean / 1000 << "s          ";
	}
	cout << "\nMerge             ";
	for (int i = 0; i <= 5; i++) {
		double mean = 0;
		if (i % 2 == 0) {	// 랜덤 데이터는	10개의 테스트 데이터 실행후 평균 구함
			for (int j = 0; j < 10; j++) {
				init(i);
				begin = clock();
				MergeSort(1, N);
				end = clock();
				mean += (double)(end - begin);
			}
			mean /= 10;
		}
		else {
			init(i);
			begin = clock();
			MergeSort(1, N);
			end = clock();
			mean += (double)(end - begin);
		}
		cout << mean / 1000 << "s          ";
	}
	cout << "\nQuick1            ";					// 마지막 값을 pivot으로 가지는 퀵정렬
	for (int i = 0; i <= 5; i++) {
		double mean = 0;
		if (i % 2 == 0) {							// 랜덤 데이터는	10개의 테스트 데이터 실행후 평균 구함
			for (int j = 0; j < 10; j++) {
				init(i);
				begin = clock();
				QuickSort1(1, N);
				end = clock();
				mean += (double)(end - begin);
			}
			mean /= 10;
		}
		else {
			init(i);
			begin = clock();
			QuickSort1(1, N);
			end = clock();
			mean += (double)(end - begin);
		}
		cout << mean / 1000 << "s          ";
	}
	cout << "\nQuick2            ";					// 처음 중간 마지막 값 중 가운데 값을 pivot으로 가지는 퀵정렬 
	for (int i = 0; i <= 5; i++) {
		double mean = 0;
		if (i % 2 == 0) {							// 랜덤 데이터는	10개의 테스트 데이터 실행후 평균 구함
			for (int j = 0; j < 10; j++) {
				init(i);
				begin = clock();
				QuickSort2(1, N);
				end = clock();
				mean += (double)(end - begin);
			}
			mean /= 10;
		}
		else {
			init(i);
			begin = clock();
			QuickSort2(1, N);
			end = clock();
			mean += (double)(end - begin);
		}
		cout << mean / 1000 << "s          ";
	}

	cout << "\nQuick3            ";					// 랜덤한 값을 pivot으로 가지는 퀵정렬
	for (int i = 0; i <= 5; i++) {
		double mean = 0;
		if (i % 2 == 0) {							// 랜덤 데이터는	10개의 테스트 데이터 실행후 평균 구함
			for (int j = 0; j < 10; j++) {
				init(i);
				begin = clock();
				QuickSort3(1, N);
				end = clock();
				mean += (double)(end - begin);
			}
			mean /= 10;
		}
		else {
			init(i);
			begin = clock();
			QuickSort3(1, N);
			end = clock();
			mean += (double)(end - begin);
		}

		cout << mean / 1000 << "s          ";
	}

	cout << "\nHeap              ";					// Heap 정렬 시작
	for (int i = 0; i <= 5; i++) {
		double mean = 0;
		if (i % 2 == 0) {							// 랜덤 데이터는	10개의 테스트 데이터 실행후 평균 구함
			for (int j = 0; j < 10; j++) {
				init(i);
				begin = clock();
				HeapSort();
				end = clock();
				mean += (double)(end - begin);
			}
			mean /= 10;
		}
		else {
			init(i);
			begin = clock();
			HeapSort();
			end = clock();
			mean += (double)(end - begin);
		}
		cout << mean / 1000 << "s          ";
	}

	// 라이브러리 Sort를 하기위해선 vector가 필요. vector에 데이터를 담아 정렬
	cout << "\nLibrary           ";
	library.resize(100000);
	for (int i = 0; i <= 5; i++) {
		double mean = 0; int n;
		if (i == 0 || i == 1) n = 1000;
		else if (i == 2 || i == 3) n = 10000;
		else n = 100000;

		if (i % 2 == 0) {
			for (int k = 0; k < 10; k++) {
				for (int j = 0; j < n; j++)
					library[j] = 1 + rand() % N;
				begin = clock();
				sort(library.begin(), library.end());
				end = clock();
				mean += (double)(end - begin);
			}
			mean /= 10;
		}
		else {
			for (int j = 0; j < n; j++)
				library[j] = n - j;
			begin = clock();
			sort(library.begin(), library.end());
			end = clock();
			mean = (double)(end - begin);
		}
		cout << mean / 1000 << "s          ";
	}




}

// 오름차순 정렬
// 좌우 비교해가며 왼쪽이 큰 값일시 교환, 마지막부터 큰 값을 채움
void BubbleSort(int n) {
	for (int i = n; i > 0; i--) {
		for (int j = 1; j < i; j++) {

			if (datas[j + 1] < datas[j]) {
				int temp = datas[j + 1];
				datas[j + 1] = datas[j];
				datas[j] = temp;
			}
		}
	}
}
// 한 번 실행시 최대값을 찾아서 마지막에 삽입, 마지막부터 큰 값을 채움
void SelectionSort(int n) {
	for (int i = n; i > 0; i--) {
		int max = datas[i], index = i;
		for (int j = 0; j < i; j++) {
			if (datas[j] > max) { max = datas[j]; index = j; }
		}
		if (max > datas[i]) {
			datas[index] = datas[i];
			datas[i] = max;
		}
	}
}
// 왼쪽부터 끝까지 진행해가며, 각 값이 삽입될 위치를 찾아 삽입
void InsertSort(int n) {
	for (int i = 1; i <= n; i++) {
		int max = datas[i];
		int j = i - 1;
		while (j >= 1 && max < datas[j]) {
			datas[j + 1] = datas[j];
			datas[j] = max;
			j--;
		}
	}
}

// 데이터를 반으로 나눠 오름차순 으로 합치는 방식
void MergeSort(int first, int last) {
	if (first < last) {
		int middle = (first + last) / 2;
		// 데이터 반으로 나눔
		MergeSort(first, middle);
		MergeSort(middle + 1, last);
		// 데이터 정렬한 후 통합
		Merge(first, middle, last);
	}
}

void Merge(int first, int middle, int last) {
	int i = first, j = middle + 1, k = first;
	// 정렬된 데이터를 담을 temp배열 생성
	int *temp = new int[last + 1];
	// 작은 데이터가 먼저 temp에 담기게 하여 오름차순 정렬
	while (i <= middle && j <= last) {
		if (datas[i] < datas[j]) { temp[k++] = datas[i++]; }
		else { temp[k++] = datas[j++]; }
	}
	while (i <= middle) {
		temp[k++] = datas[i++];
	}
	while (j <= last) {
		temp[k++] = datas[j++];
	}
	// temp에 담긴 정렬된 데이터를 다시 data에 반환
	for (int index = first; index <= last; index++)
		datas[index] = temp[index];
	delete temp;
}

// 마지막 값을 피봇으로하는 퀵정렬
void QuickSort1(int first, int last) {
	stack<int> s;								// 내림차순 데이터 정렬시 오버플로우 발생 대체 위해 스택을 이용한 반복문 작성
	s.push(last); s.push(first);

	while (!s.empty()) {
		int F = s.top(); s.pop();				// First
		int L = s.top(); s.pop();				// Last

		if (F < L) {
			int pivot = datas[L];				// 가장 마지막 데이터를 pivot으로 잡음
			int i = F - 1;
			for (int j = F; j < L; j++) {		// pivot을 기준으로 작은 데이터는 왼쪽, 큰 데이터는 오른쪽으로 정렬
				if (datas[j] <= pivot) {
					i++;
					int temp = datas[j];
					datas[j] = datas[i];
					datas[i] = temp;
				}
			}
			i++;
			datas[last] = datas[i];
			datas[i] = pivot;

			s.push(L);							// pivot의 좌우 기준으로 데이터 분할
			s.push(i + 1);
			s.push(i - 1);
			s.push(F);
		}

	}

}

// 첫번째, 가운데, 마지막 중 중간값을 pivot으로 선택
void QuickSort2(int first, int last) {
	stack<int> s;
	s.push(last); s.push(first);
	while (!s.empty()) {
		int F = s.top(); s.pop();
		int L = s.top(); s.pop();

		if (F < L) {
			int middle = (F + L) / 2, max = datas[F], index = F;
			int mid[3] = { F,middle,L };		// 처음, 가운데, 마지막 값의 위치를 담을 mid 배열
			for (int i = 0; i < 3; i++)
				if (max > datas[mid[i]]) {
					max = datas[mid[i]]; index = mid[i];
				}
			max = 0;
			for (int i = 0; i < 3; i++) {
				if (mid[i] == index) continue;
				if (max > datas[mid[i]]) {
					max = datas[mid[i]]; index = mid[i];
				}
			}									// index는 중간값의 pivot 위치

			int pivot = datas[index];			// 중간값을 pivot으로 잡은 뒤, 마지막에 있는 데이터와 교환 후 QuickSort 실시
			datas[index] = datas[L];
			datas[L] = pivot;

			int i = F - 1;
			for (int j = F; j < L; j++) {
				if (datas[j] <= pivot) {
					i++;
					int temp = datas[j];
					datas[j] = datas[i];
					datas[i] = temp;
				}
			}
			i++;
			datas[L] = datas[i];
			datas[i] = pivot;

			s.push(L);
			s.push(i + 1);
			s.push(i - 1);
			s.push(F);
		}

	}
}

// pivot을 랜덤하게 선택
void QuickSort3(int first, int last) {
	stack<int> s;
	s.push(last); s.push(first);
	while (!s.empty()) {
		int F = s.top(); s.pop();
		int L = s.top(); s.pop();

		if (F < L) {
			int index = (rand() % (L - F)) + F;	//	F 와 L 사이에 있는 랜덤 데이터를 pivot으로 잡음
			int pivot = datas[index];
			datas[index] = datas[L];
			datas[L] = pivot;					// 랜덤한 데이터를 pivot으로 잡은뒤, 마지막 데이터와 교환하여 QuickSort 실시

			int i = F - 1;
			for (int j = F; j < L; j++) {
				if (datas[j] <= pivot) {
					i++;
					int temp = datas[j];
					datas[j] = datas[i];
					datas[i] = temp;
				}
			}
			i++;
			datas[L] = datas[i];
			datas[i] = pivot;

			s.push(L);
			s.push(i + 1);
			s.push(i - 1);
			s.push(F);
		}

	}
}
// Heap 성질을 유지시키기 위한 Heapify, 입력한 위치부터 Heap로 만듬
void Heapify(int i) {
	if (2 * i > N) return;			// 자식노드가 없을 때는 동작 X
	int index = 2 * i;				// 자식중 가장 큰 노드의 위치를 index에 저장
	int k2, k1 = datas[index];		// k2 오른쪽 자식 노드의 값, k1 자식 중 가장 큰 값을 가진 노드

	if (index + 1 <= N) {			// 오른쪽 자식 노드가 있는 경우
		k2 = datas[index + 1];		// k2에 오른쪽 자식 노드의 값 할당
		if (k2 > k1) { k1 = k2; index++; }	// 오른쪽 자식 노드가 가장 클 경우, k1에 그 값을 담고 인덱스에 위치 저장
	}

	if (datas[i] > k1) return;		// 부모 노드가 자식 노드보다 클 경우 동작 x -> max_heap이기 문
	datas[index] = datas[i];		// 부모 노드가 자식 노드보다 작을시, 가장 큰 자식 노드와 교체
	datas[i] = k1;
	Heapify(index);					// 교체한 자식 노드의 위치에서 다시 Heapify 시작
}
// Heap를 생성
void HeapBuild() {
	for (int i = N / 2; i >= 1; i--)	// 마지막 부모 노드부터 꼭대기까지 Heapify 함으로써 Heap 생성
		Heapify(i);
}
// Heap를 정렬된 데이터로 만듬
void HeapSort() {
	HeapBuild();
	for (int i = N; i >= 2; i--) {		// 마지막 노드의 값과 꼭대기를 교체함으로써 가장 큰 값을 마지막으로 보내 오름차순 정렬
		int max = datas[1];				// max_heap에선 가장 큰 값이 항사 꼭대기에 있음
		datas[1] = datas[i];
		datas[i] = max;
		N--;							// 노드 수를 줄임으로써 마지막 노드에 가장 큰 값이 담기게함

		Heapify(1);
	}
}
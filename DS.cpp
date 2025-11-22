#include <iostream>
using namespace std;

struct SV {
	string Ten;
	char MSSV;
	int NamSinh;
	double GPA;
	SV* next;
};
struct DSSV {
	SV* firstSV;

};

void SV_M(DSSV* DS) {
	SV* SV = DS-> firstSV;
	int t = DSSV_length(DS);
	cout << "\n Do dai danh sach" << t << endl;
	if (DS->firstSV == 0)
		cout << "Danh sach rong" << endl;
	else {
		while (SV) {
			cout << "SV thu\t" << t;
			cout << "\n Ten" << SV->Ten;
			cout << "\n Nam Sinh" << SV->NamSinh;
			cout << "\n GPA" << SV->GPA;
			SV = SV->next;
			t--;
		}
		cout << endl;
	}
}
int Dem_GPA(DSSV* DS) {
	SV* SV = DS->firstSV;
	int m = 0;
	while (SV) {
		if (SV->GPA > 3.2) m++;
		SV = SV->next;
	}
	return m;
}
int DSSV_length(DSSV* DS) {
	SV* SV = DS->firstSV;
	int m = 0;
	while (SV != 0) {
		++m; SV = SV->next;
	}
	return m;
}
void SortByGPA(DSSV* DS) {
	if (!DS->firstSV) return;
	SV* SV, * q;
	for (SV = DS->firstSV; SV->next != 0; SV = SV->next) {
		for (q = SV->next; q != 0; q = q->next) {
			if (SV->GPA > q->GPA) {
				swap(SV->GPA, q->GPA);
				swap(SV->Ten, q->Ten);
				swap(SV->MSSV, q->MSSV);
				swap(SV->NamSinh, q->NamSinh);
			}
		}
	}
	void InsertSorted(DSSV * DS, SV * newSV) {
		SV*& head = DS->firstSV;
		if (!head || newSV->GPA < head->GPA) {
			newSV->next = head;
			head = newSV;
			return;
		}
		SV* cur = head;
		while (cur->next && cur->next->GPA < newSV->GPA) {
			cur = cur->next;
		}
		newSV->next = cur->next;
		cur->next = newSV;
	}

int main(){}
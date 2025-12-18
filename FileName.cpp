// Project 1: CaiDatCay_Mang_TuanTu
#include <iostream>
#include <string>

using namespace std;

#define MAX_SIZE 100
struct Nut {
    string duLieu; 
    bool coDuLieu; 
};
Nut Cay[MAX_SIZE];
void KhoiTaoCay() {
    for (int i = 0; i < MAX_SIZE; i++) {
        Cay[i].coDuLieu = false;
    }
}

bool KiemTraRong() {
    return !Cay[1].coDuLieu; 
}

void TaoNutGoc(string x) {
    if (Cay[1].coDuLieu) {
        cout << "Cay da co goc roi!" << endl;
    }
    else {
        Cay[1].duLieu = x;
        Cay[1].coDuLieu = true;
    }
}
void ThemConTrai(int chiSoCha, string x) {
    if (!Cay[chiSoCha].coDuLieu) {
        cout << "Nut cha khong ton tai!" << endl;
        return;
    }
    int chiSoCon = 2 * chiSoCha;
    if (chiSoCon >= MAX_SIZE) {
        cout << "Mang day" << endl;
        return;
    }
    Cay[chiSoCon].duLieu = x;
    Cay[chiSoCon].coDuLieu = true;
}
void ThemConPhai(int chiSoCha, string x) {
    if (!Cay[chiSoCha].coDuLieu) {
        cout << "Nut cha khong ton tai!" << endl;
        return;
    }
    int chiSoCon = 2 * chiSoCha + 1;
    if (chiSoCon >= MAX_SIZE) {
        cout << "Mang day, khong them duoc!" << endl;
        return;
    }
    Cay[chiSoCon].duLieu = x;
    Cay[chiSoCon].coDuLieu = true;
}
void DuyetTruoc(int i) {
    if (i >= MAX_SIZE || !Cay[i].coDuLieu) return;

    cout << Cay[i].duLieu << " "; 
    DuyetTruoc(2 * i);            
    DuyetTruoc(2 * i + 1);        
}

void DuyetGiua(int i) {
    if (i >= MAX_SIZE || !Cay[i].coDuLieu) return;

    DuyetGiua(2 * i);            
    cout << Cay[i].duLieu << " "; 
    DuyetGiua(2 * i + 1);         
}

void DuyetSau(int i) {
    if (i >= MAX_SIZE || !Cay[i].coDuLieu) return;

    DuyetSau(2 * i);              
    DuyetSau(2 * i + 1);          
    cout << Cay[i].duLieu;
}

int main() {
    KhoiTaoCay();
    TaoNutGoc("A");
    ThemConTrai(1, "A.1");
    ThemConPhai(1, "A.2");
    ThemConTrai(2, "A.1.1");
    ThemConPhai(2, "A.1.2");
    ThemConTrai(3, "A.2.1");
    ThemConPhai(3, "A.2.2");
    cout << "Duyet Truoc: ";
    DuyetTruoc(1);
    cout << endl;
    cout << "Duyet Giua:   ";
    DuyetGiua(1);
    cout << endl;
    cout << "Duyet Sau:  ";
    DuyetSau(1);
    cout << endl;
    return 0;
}
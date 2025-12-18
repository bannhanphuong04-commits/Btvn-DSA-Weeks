// Project 2: CaiDatCay_MocNoi_ConTro
#include <iostream>
#include <string>

using namespace std;

struct Nut {
    string duLieu;
    Nut* conTrai;
    Nut* conPhai;
};

typedef Nut* Cay;
void KhoiTaoCay(Cay& t) {
    t = NULL;
}

bool KiemTraRong(Cay t) {
    return t == NULL;
}

Nut* TaoNutMoi(string x) {
    Nut* p = new Nut;
    p->duLieu = x;
    p->conTrai = NULL;
    p->conPhai = NULL;
    return p;
}

void ThemConTrai(Cay& cha, string x) {
    if (cha == NULL) {
        cout << "Nut cha khong ton tai!" << endl;
        return;
    }
    if (cha->conTrai != NULL) {
        cout << "Da co con trai roi!" << endl;
        return;
    }
    cha->conTrai = TaoNutMoi(x);
}

void ThemConPhai(Cay& cha, string x) {
    if (cha == NULL) {
        cout << "Nut cha khong ton tai" << endl;
        return;
    }
    if (cha->conPhai != NULL) {
        cout << "Da co con phai roi" << endl;
        return;
    }
    cha->conPhai = TaoNutMoi(x);
}

void DuyetTruoc(Cay t) {
    if (t != NULL) {
        cout << t->duLieu << " ";
        DuyetTruoc(t->conTrai);
        DuyetTruoc(t->conPhai);
    }
}

void DuyetGiua(Cay t) {
    if (t != NULL) {
        DuyetGiua(t->conTrai);
        cout << t->duLieu << " ";
        DuyetGiua(t->conPhai);
    }
}
void DuyetSau(Cay t) {
    if (t != NULL) {
        DuyetSau(t->conTrai);
        DuyetSau(t->conPhai);
        cout << t->duLieu << " ";
    }
}

int main() {
    Cay Goc;
    KhoiTaoCay(Goc);
    Goc = TaoNutMoi("A");
    ThemConTrai(Goc, "A.1");
    ThemConPhai(Goc, "A.2");
    ThemConTrai(Goc->conTrai, "A.1.1");
    ThemConPhai(Goc->conTrai, "A.1.2");
    ThemConTrai(Goc->conPhai, "A.2.1");
    ThemConPhai(Goc->conPhai, "A.2.2");
    cout << "Duyet Truoc (Pre-order): ";
    DuyetTruoc(Goc);
    cout << endl;
    cout << "Duyet Giua (In-order):   ";
    DuyetGiua(Goc);
    cout << endl;
    cout << "Duyet Sau (Post-order):  ";
    DuyetSau(Goc);
    cout << endl;

    return 0;
}
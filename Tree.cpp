#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct MucLuc {
    string ten;         
    int soTrangRieng;   
    int tongSoTrang;    
    vector<MucLuc*> dsCon; 

  
    MucLuc(string t, int trang) {
        ten = t;
        soTrangRieng = trang;
        tongSoTrang = trang;
    }
};

void capNhatSoTrang(MucLuc* goc) {
    if (goc == NULL) return;

    int tong = goc->soTrangRieng;
   
    for (int i = 0; i < goc->dsCon.size(); i++) {
        capNhatSoTrang(goc->dsCon[i]); 
        tong = tong + goc->dsCon[i]->tongSoTrang;
    }
    goc->tongSoTrang = tong;
}

int demSoChuong(MucLuc* sach) {
    if (sach == NULL) return 0;
    return sach->dsCon.size();
}

void timChuongDaiNhat(MucLuc* sach) {
    if (sach == NULL || sach->dsCon.size() == 0) {
        cout << "Sach chua co chuong nao ca." << endl;
        return;
    }
    MucLuc* chuongMax = sach->dsCon[0];
    for (int i = 1; i < sach->dsCon.size(); i++) {
        if (sach->dsCon[i]->tongSoTrang > chuongMax->tongSoTrang) {
            chuongMax = sach->dsCon[i];
        }
    }
    cout << "Chuong dai nhat la: " << chuongMax->ten
        << " (" << chuongMax->tongSoTrang << " trang)" << endl;
}
bool xoaMuc(MucLuc* goc, string tenCanXoa) {
    if (goc == NULL) return false;

    for (int i = 0; i < goc->dsCon.size(); i++) {
        if (goc->dsCon[i]->ten == tenCanXoa) {
            goc->dsCon.erase(goc->dsCon.begin() + i);
            return true;
        }

    
        bool ketQua = xoaMuc(goc->dsCon[i], tenCanXoa);
        if (ketQua == true) return true; 
    }
    return false;
}
void timVaIn(MucLuc* goc, string ten) {
    if (goc == NULL) return;
    if (goc->ten == ten) {
        cout << "Tim thay: " << goc->ten << endl;
        return;
    }
    for (int i = 0; i < goc->dsCon.size(); i++) {
        timVaIn(goc->dsCon[i], ten);
    }
}
/*************Bai2********************************/
struct NutSach {
    int maSo;       
    string tenMuc;  
    NutSach* trai;  
    NutSach* phai; 
};
NutSach* taoNut(int ma, string ten) {
    NutSach* p = new NutSach;
    p->maSo = ma;
    p->tenMuc = ten;
    p->trai = NULL;
    p->phai = NULL;
    return p;
}


bool kiemTraCopy(NutSach* sach1, NutSach* sach2) {
    if (sach1 == NULL && sach2 == NULL) {
        return true;
    }
    if (sach1 == NULL || sach2 == NULL) {
        return false;
    }

    if (sach1->maSo != sach2->maSo) return false;
    if (sach1->tenMuc != sach2->tenMuc) return false; 
    bool traiGiong = kiemTraCopy(sach1->trai, sach2->trai);
    bool phaiGiong = kiemTraCopy(sach1->phai, sach2->phai);
    return traiGiong && phaiGiong;
}

int main() {
    
    MucLuc* sach = new MucLuc("Giao trinh C++", 0);

    MucLuc* c1 = new MucLuc("Chuong 1: Co ban", 2);
    c1->dsCon.push_back(new MucLuc("Muc 1.1: Nhap xuat", 3));
    c1->dsCon.push_back(new MucLuc("Muc 1.2: Bien", 4));
    MucLuc* c2 = new MucLuc("Chuong 2: Nang cao", 5);
    c2->dsCon.push_back(new MucLuc("Muc 2.1: Con tro", 10));

    sach->dsCon.push_back(c1);
    sach->dsCon.push_back(c2);

    capNhatSoTrang(sach);

    cout << "So chuong cua sach: " << demSoChuong(sach) << endl;

    timChuongDaiNhat(sach);

    cout << "\n--- Xoa muc 'Muc 1.1: Nhap xuat' ---" << endl;
    if (xoaMuc(sach, "Muc 1.1: Nhap xuat")) {
        cout << "Da xoa ok" << endl;
    
        capNhatSoTrang(sach);
        cout << "Tong so trang cua sach sau khi xoa: " << sach->tongSoTrang << endl;
    }
    else {
        cout << "Ko tim thay de xoa." << endl;
    }
    NutSach* sachA = taoNut(1, "Loi noi dau");
    sachA->trai = taoNut(2, "Chuong 1");
    sachA->phai = taoNut(3, "Chuong 2");

    NutSach* sachB = taoNut(1, "Loi noi dau");
    sachB->trai = taoNut(2, "Chuong 1");
    sachB->phai = taoNut(3, "Chuong 2");

    NutSach* sachC = taoNut(1, "Loi noi dau");
    sachC->trai = taoNut(2, "Chuong 1");
    sachC->phai = taoNut(99, "Chuong bi sua"); 

    if (kiemTraCopy(sachA, sachB)) {
        cout << "Hai cuon sach A va B la ban copy cua nhau." << endl;
    }
    else {
        cout << "Hai cuon sach A va B khac nhau." << endl;
    }

    if (kiemTraCopy(sachA, sachC)) {
        cout << "Hai cuon sach A va C la ban copy cua nhau." << endl;
    }
    else {
        cout << "Hai cuon sach A va C khac nhau." << endl;
    }
    return 0;
}
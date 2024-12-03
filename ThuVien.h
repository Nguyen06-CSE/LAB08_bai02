#define MAX 1000

struct PhanSo {
    int tu;
    int mau;
};

typedef PhanSo Mang[MAX];

// Khai báo các hàm
void nhapMangPhanSo(Mang a, int n);
void taoMangPhanSo(Mang a, int n);
void xuatPhanSo(PhanSo& ps);
void xuatMangPhanSo(Mang a, int n);
double giaTriThuc(Mang a, int viTri);
void xuatGiaTriCuaMang(Mang a, int n);
int viTriPhanSoLonNhat(Mang a, int n);
void rutGonPhanSo(PhanSo& ps);
void timCacPhanSoCoGiaTriLonNhat(Mang a, int n);
void xuatCacPhanSoODangToiGian(Mang a, int n);
void sapXepTangGiaTri(Mang a, int n);
void timPhanSoChoTruoc(Mang a, int n, PhanSo& p);
void timPhanSoCoGiaTriBang0(Mang a, int n);
int demPhanSoKhongLayNghichDao(Mang a, int n);
void xuatPhanSoNghichDao(Mang a, int n);
void dinhDangPhanSo(Mang a, int n);
double tongGiaTriThuc(Mang a, int n);
PhanSo tongPhanSo(PhanSo& ps1, PhanSo& ps2);
PhanSo tongPhanSoMang(Mang a, int n);
void sapXepGiamTheoMau(Mang a, int n);
int viTriPhanSoAmLonNhat(Mang a, int n);
void timPhanSoGanTrungBinh(Mang a, int n);




// Hàm nhập phân số
void nhapMangPhanSo(Mang a, int n) {
    
    for(int i = 0; i < n; i++){
        cout << "Nhap tu so: ";
        cin >> a[i].tu;
        do {
            cout << "Nhap mau so (khac 0): ";
            cin >> a[i].mau;
            if (a[i].mau == 0) cout << "Mau so phai khac 0!\n";
    } while (a[i].mau == 0);
    }
    
}

// Hàm tạo mảng phân số ngẫu nhiên
void taoMangPhanSo(Mang a, int n) {
    
    for (int i = 0; i < n; i++) {
        cout << "tu va mau duoc tao ngau nhien thu " << i << " la: \n";
        a[i].tu = rand() % 21 - 10;
        cout << a[i].tu << " "; // Tử số từ -10 đến 10
        do {
            
            a[i].mau = rand() % 21 - 10; // Mẫu số từ -10 đến 10
            cout << a[i].mau << endl; 
        } while (a[i].mau == 0);
    }
    
}

// Hàm xuất phân số
void xuatPhanSo(PhanSo& ps) {
    if (ps.mau == 1) // Nếu mẫu số là 1 thì chỉ in tử số
        cout << ps.tu;
    else
        cout << ps.tu << "/" << ps.mau;
}

// Hàm xuất mảng phân số
void xuatMangPhanSo(Mang a, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Phan so thu " << i + 1 << ": ";
        xuatPhanSo(a[i]);
        cout << endl;
    }
}

// Hàm tính giá trị thực của phân số
double giaTriThuc(Mang a, int viTri) {
    return static_cast<double>(a[viTri].tu) / a[viTri].mau;
}

void xuatGiaTriCuaMang(Mang a, int n){
    cout << "gia tri cua cac phan so trong mang la: \n";
    for(int i = 0; i < n; i++){
        cout << giaTriThuc(a, i) << " ";
    }
    cout << endl;
}

int viTriPhanSoLonNhat(Mang a, int n){
    double max = giaTriThuc(a, 0);
    int vitri = 0;
    for(int i = 1; i < n; i++){
        if(giaTriThuc(a, i) > max){
            max = giaTriThuc(a, i);
            vitri = i;
        }  
        else vitri = 0;
    }
    return vitri;
}

void timCacPhanSoCoGiaTriLonNhat(Mang a, int n) {
    double maxVal = giaTriThuc(a, 0);
    for (int i = 1; i < n; i++) {
        if (giaTriThuc(a, i) > maxVal) {
            maxVal = giaTriThuc(a, i);
        }
    }

    cout << "Cac phan so co gia tri lon nhat: ";
    for (int i = 0; i < n; i++) {
        if (giaTriThuc(a, i) == maxVal) {
            xuatPhanSo(a[i]);
            cout << " ";
        }
    }
    cout << endl;
}


void rutGonPhanSo(PhanSo& ps) {
    //cout << "phan so truoc khi rut gon la: \n" << ps.tu << "/" << ps.mau << endl;
    int a = abs(ps.tu), b = abs(ps.mau);
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    int gcd = a; 
    ps.tu /= gcd;
    ps.mau /= gcd;
    if (ps.mau < 0) { 
        ps.tu = -ps.tu;
        ps.mau = -ps.mau;
    }
    cout << "phan so sau khi rut gon la: \n" << ps.tu << "/" << ps.mau << endl;
}


void xuatCacPhanSoODangToiGian(Mang a, int n){
    for(int i = 0; i < n; i++){
        rutGonPhanSo(a[i]);
    }
}



void sapXepTangGiaTri(Mang a, int n) {
    for (int i = 0; i < n - 1; i++) {
        rutGonPhanSo(a[i]);
        for (int j = i + 1; j < n; j++) {
            rutGonPhanSo(a[j]);
            if (giaTriThuc(a, i) > giaTriThuc(a, j)) {
                swap(a[i], a[j]);
            }
        }
    }
}

void timPhanSoChoTruoc(Mang a, int n, PhanSo& p) {
    cout << "Nhap tu va mau cua phan so can tim: ";
    cin >> p.tu >> p.mau;
    rutGonPhanSo(p);

    bool kt = false;
    for (int i = 0; i < n; i++) {
        if (a[i].tu * p.mau == p.tu * a[i].mau) { // So sánh chính xác
            kt = true;
            cout << "Tim thay phan so: ";
            xuatPhanSo(a[i]);
            cout << endl;
        }
    }

    if (!kt)
        cout << "Khong tim thay phan so " << p.tu << "/" << p.mau << " trong mang.\n";
}


void timPhanSoCoGiaTriBang0(Mang a, int n) {
    cout << "Cac phan so co gia tri bang 0: ";
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (a[i].tu == 0) {
            xuatPhanSo(a[i]);
            cout << " ";
            found = true;
        }
    }
    if (!found) cout << "Khong co phan so nao bang 0.";
    cout << endl;
}


int demPhanSoKhongLayNghichDao(Mang a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].tu == 0) { // Tử số bằng 0 thì không lấy nghịch đảo được
            count++;
        }
    }
    return count;
}

void xuatPhanSoNghichDao(Mang a, int n) {
    cout << "Cac phan so nghich dao: ";
    for (int i = 0; i < n; i++) {
        if (a[i].tu != 0) { // Chỉ xuất phân số có thể lấy nghịch đảo
            cout << a[i].mau << "/" << a[i].tu << " ";
        }
    }
    cout << endl;
}

void dinhDangPhanSo(Mang a, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i].mau < 0) { // Mẫu âm
            a[i].tu = -a[i].tu;
            a[i].mau = -a[i].mau;
        }
        if (a[i].tu < 0 && a[i].mau < 0) { // Tử và mẫu đều âm
            a[i].tu = -a[i].tu;
            a[i].mau = -a[i].mau;
        }
    }
    cout << "Cac phan so sau khi dinh dang: ";
    xuatMangPhanSo(a, n);
}

double tongGiaTriThuc(Mang a, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += giaTriThuc(a, i);
    }
    return sum;
}


PhanSo tongPhanSo(PhanSo& ps1, PhanSo& ps2) {
    PhanSo result;
    result.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
    result.mau = ps1.mau * ps2.mau;
    rutGonPhanSo(result);
    return result;
}

PhanSo tongPhanSoMang(Mang a, int n) {
    PhanSo sum = {0, 1};
    for (int i = 0; i < n; i++) {
        sum = tongPhanSo(sum, a[i]);
    }
    return sum;
}



void sapXepGiamTheoMau(Mang a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].mau < a[j].mau || (a[i].mau == a[j].mau && a[i].tu > a[j].tu)) {
                swap(a[i], a[j]);
            }
        }
    }
    cout << "Mang sau khi sap xep giam dan theo mau so: ";
    xuatMangPhanSo(a, n);
}


int viTriPhanSoAmLonNhat(Mang a, int n) {
    double maxAm = -1e9;
    int viTri = -1;
    for (int i = 0; i < n; i++) {
        double giaTri = giaTriThuc(a, i);
        if (giaTri < 0 && giaTri > maxAm) {
            maxAm = giaTri;
            viTri = i;
        }
    }
    return viTri;
}


void timPhanSoGanTrungBinh(Mang a, int n) {
    double tongGiaTri = tongGiaTriThuc(a, n);
    double trungBinh = tongGiaTri / n;

    double minKhoangCach = 1e9;
    int viTriGanNhat = -1;

    for (int i = 0; i < n; i++) {
        double khoangCach = abs(giaTriThuc(a, i) - trungBinh);
        if (khoangCach < minKhoangCach) {
            minKhoangCach = khoangCach;
            viTriGanNhat = i;
        }
    }

    cout << "Phan so gan gia tri trung binh nhat: ";
    xuatPhanSo(a[viTriGanNhat]);
    cout << endl;
}



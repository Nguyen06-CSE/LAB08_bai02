void XuatMenu();
int ChonMenu(int SoMenu);
void XuLyMenu(int chon, Mang a, PhanSo ps, int& n);
void ChayChuongTrinh();


void XuatMenu() 
{
    cout << "________________________________MENU_____________________________\n"
        << "0. thoat khoi chuong trinh\n"
        << "1. nhap vao mang phan so \n"
        << "2. mhap ngau nhien mot mang phan so vo dieu kien tu so, mau so nam trong [-10, 10]\n"
        << "3. xuat cac phan so ra man hinh \n"
        << "4. tinh gia tri cua mot phan so tai vi tri cho truoc \n"
        << "5. xuat gia tri cac phan so trong mang\n"
        << "6. tim vi tri cua cac phan so co gia tri lon nhat \n"
        << "7. tim cac phan so co gia tri lon nhat \n"
        << "8. toi gian mot phan so\n"
        << "9. xuat cac phan so o dang toi gian \n"
        << "10. sap xep cac phan so tang dan theo gia tri \n"
        << "11. tim cac phan so co gia tri bang voi mot phan so p cho truoc \n"
        << "12. tim nhung phan so co gia tri bang 0\n"
        << "13. dem so luong phan so ko the lay nghich dao \n"
        << "14. xuat phan so nghich dao cua cac phan so trong mang \n"
        << "15. dinh dang lai cac phan so \n"
        << "16. tinh tong gia tri  cua tat ca cac phan so trong mang (tra ve so thuc) \n"
        << "17. tinh tong tat ca cac phan so trong mang (tra ve phan so)  \n"
        << "18. sap xep cac phan so theo mau so, neu mau so bang nhaum sap tang theo tu so\n"
        << "19. tim vi tri cua phan so co gia tri am lon nhat. Neu ko co phan so am trave -1\n"
        << "20. tim nhung phan so co gia tri gan voi gia tri trung binh cua tat ca cac phan so nhat\n";
}

int ChonMenu(int SoMenu)
{
    int chon;
    do
    {
        cout << "nhap chon [0...." << SoMenu << "]=";
        cin >> chon;
        if(chon >= 0 && chon <= SoMenu)
        {
            break;
        }
    } while (true);
    return chon;
}

void XuLyMenu(int chon, Mang a, PhanSo ps, int& n)
{
    int viTri;
    PhanSo p;
    switch (chon)
    {
    case 0:
        cout << "thoat khoi chuong trinh \n";
        break;
    case 1:
        cout << "nhap kich co cua mang: ";
        cin >> n;
        cout << "1. nhap vao mang phan so \n";
        nhapMangPhanSo(a, n);
        break;
    case 2:
        cout << "nhap kich co cua mang: ";
        cin >> n;
        cout << "2. mhap ngau nhien mot mang phan so vo dieu kien tu so, mau so nam trong [-10, 10]\n";
        taoMangPhanSo(a, n);
        
        break;
    case 3:
    cout << n << endl;
        cout << "3. xuat cac phan so ra man hinh \n";
        xuatMangPhanSo(a, n);
        break;
    case 4:
        cout << "4. tinh gia tri cua mot phan so tai vi tri cho truoc \n";
        
        cout << "nhap vi tri cua phan so (tu 0 - " << n - 1 << ")=";
        cin >> viTri;
        cout << "gia tri tai vi tri " << viTri << " la " << giaTriThuc(a, viTri) << endl;
        break;
    case 5:
        cout << "5. xuat gia tri cac phan so trong mang\n";
        xuatGiaTriCuaMang(a, n);
        break;
    case 6:
        cout << "6. tim vi tri cua cac phan so co gia tri lon nhat \n";
        cout << "phan tu lon nhat co vi tri la: " << viTriPhanSoLonNhat(a, n) << endl;
        break;
    case 7:
        cout << "7. tim cac phan so co gia tri lon nhat \n";
        timCacPhanSoCoGiaTriLonNhat(a, n);
        break;
    case 8:
        cout << "8. toi gian mot phan so\n";
        int viTri;
        cout << "ban hay nhap vi tri cua phan so muon toi gian trong mang (0-" << n-1 << ")=";
        cin >> viTri;
        rutGonPhanSo(a[viTri]);
        break;
    case 9:
        cout << "9. xuat cac phan so o dang toi gian \n";
        xuatCacPhanSoODangToiGian(a, n);


        break;
    case 10:
        cout << "10. sap xep cac phan so tang dan theo gia tri \n";
        cout << "gia tri truoc khi sap xep la: \n";
        xuatMangPhanSo(a, n);
        cout << "gia tri sau khi sap xep theo gia tri tang dan la:\n";
        sapXepTangGiaTri(a, n);
        xuatMangPhanSo(a, n);
        break;
    case 11:
        cout << "11. tim cac phan so co gia tri bang voi mot phan so p cho truoc \n";
        timPhanSoChoTruoc(a, n, p);
        break;
    case 12:
        cout << "12. tim nhung phan so co gia tri bang 0\n";
        timPhanSoCoGiaTriBang0(a, n);
        break;
    case 13:
        cout << "13. dem so luong phan so ko the lay nghich dao \n";
        cout << "so luong phan so ko the lay nghich dao la: " << demPhanSoKhongLayNghichDao(a, n);
        break;
    case 14:
        cout << "14. xuat phan so nghich dao cua cac phan so trong mang \n";
        xuatPhanSoNghichDao( a,  n);
        break;
    case 15:
        cout << "15. dinh dang lai cac phan so \n";
        dinhDangPhanSo(a, n);
        break;
    case 16:
        cout << "16. tinh tong gia tri  cua tat ca cac phan so trong mang (tra ve so thuc) \n";
        cout << "tong gia tri cua tat cac cac phan so tra ve kieu so thuc la: " << tongGiaTriThuc(a, n) << endl;
 
        break;
    case 17:
        cout << "17. tinh tong tat ca cac phan so trong mang (tra ve phan so)  \n";
        PhanSo sum = tongPhanSoMang(a, n);
        cout << "tong phan so trong mang tra ve kieu phan so la: ";
        xuatPhanSo(sum);

        break;
    case 18:
        cout << "18. sap xep cac phan so theo mau so, neu mau so bang nhaum sap tang theo tu so\n";
        sapXepGiamTheoMau(a, n);

        break;
    case 19:
        cout << "19. tim vi tri cua phan so co gia tri am lon nhat. Neu ko co phan so am trave -1\n";
        cout << "vi tri cua phan tu so am lon nhat trong mang la: " << viTriPhanSoAmLonNhat(a, n) << endl;

        break;
    case 20:
        cout << "20. tim nhung phan so co gia tri gan voi gia tri trung binh cua tat ca cac phan so nhat\n";
        cout << "phan so co gia tri gan voi gia tri trung binh  xua tat ca cac phan so nhat la: ";
        timCacPhanSoCoGiaTriLonNhat(a, n);
        break;
    default:
        break;
    }
    _getch();
}

void ChayChuongTrinh()
{
    int SoMenu = 20, chon, n;

    Mang a;
    PhanSo ps;
    
    do
    {
        system("cls");
        XuatMenu();
        chon = ChonMenu(SoMenu);
        XuLyMenu(chon, a, ps, n);
    } while (chon != 0);
    
}
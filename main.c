#include "library.h"

int main()
{
    int n = 1;
    do
    {
        system("cls");
        if (n <= 0)
            printf("Nhap lai, lop phai co it nhat mot sinh vien\n");
        printf("Nhap so luong sinh vien: ");
        scanf("%d", &n);
        getchar();
    } while (n <= 0); // lop co it nhat 1 ng

    sv *a = (sv *)malloc(n * sizeof(sv));
    // nhapDSSV(a, n);
    // nhapFile(a, n, "sinhvien.txt");
    nhapFileBang(a, n, "sinhvien.txt");
    // nhap file bang thi thay xuatDDSV(a, n); thanh -DSSVtable(a, n);

    int number, request;
    do
    {
    start:
        system("cls");
        printf("Nhan phim\n");
        printf("(1) hien thi danh sach sinh vien\n");
        printf("(2) tra cuu thong tin sinh vien\n");
        printf("(3) sap xep danh sach sinh vien\n");
        printf("(4) chinh sua thong tin sinh vien\n");
        printf("(5) them, xoa, chen sinh vien\n");

        scanf("%d", &number);
        getchar();
        switch (number)
        {
        // Danh sach
        case 1:
        {
        danhsach:
            system("cls");
            printf("Nhan phim\n");
            printf("(1) danh sach lop\n");
            printf("(2) danh sach lop dang bang\n\n");
            printf("(3) danh sach sinh vien Gioi (diem >= 8)\n");
            printf("(4) danh sach sinh vien Kha (6.5 <= diem < 8)\n");
            printf("(5) danh sach sinh vien Trung Binh(5 <= diem < 6.5)\n");
            printf("(6) danh sach sinh vien Yeu (diem < 5)\n\n");
            printf("(7) sinh vien co diem cao nhat\n");
            printf("(8) sinh vien co diem thap nhat\n");
            printf("\n(99) menu\n");
            scanf("%d", &request);
            getchar();
            if (request == 1)
            {
                // xuatDDSV(a, n);
                DSSVtable(a, n);
            }
            else if (request == 2)
                DSSVtable(a, n);
            else if (request == 3)
                danhSachSVGioi(a, n);
            else if (request == 4)
                danhSachSVKha(a, n);
            else if (request == 5)
                danhSachSVTrungBinh(a, n);
            else if (request == 6)
                danhSachSVYeu(a, n);
            else if (request == 7)
                top1(a, n);
            else if (request == 8)
                topN(a, n);
            else if (request == 99)
                goto start;
            else
                goto danhsach;
            break;
        }
        // Tra cuu
        case 2:
        {
        tracuu:
            system("cls");
            printf("Nhan phim\n");
            printf("(1) tra cuu thong tin sinh vien theo MSSV\n");
            printf("(2) tra cuu thong tin sinh vien theo ho ten\n");
            printf("\n(99) menu\n");
            scanf("%d", &request);
            getchar();
            if (request == 1)
                traCuuMSSV(a, n);
            else if (request == 2)
                traCuuHoTen(a, n);
            else if (request == 99)
                goto start;
            else
                goto tracuu;
            break;
        }
        // Sap xep
        case 3:
        {
        sapxep:
            system("cls");
            printf("Nhan phim\n");
            printf("(1) sap xep danh sach sinh vien diem tang dan\n");
            printf("(2) sap xep danh sach sinh vien diem giam dan\n");
            printf("(3) sap xep danh sach sinh vien theo alphabet\n");
            printf("\n(99) menu\n");
            scanf("%d", &request);
            getchar();
            if (request == 1)
                sapXepDiemTangDan(a, n);
            else if (request == 2)
                sapXepDiemGiamDan(a, n);
            else if (request == 3)
                sapXepTheoTen(a, n);
            else if (request == 99)
                goto start;
            else
                goto sapxep;
            break;
        }
        // chinh sua thong tin
        case 4:
        {
            system("cls");
            chinhSua(a, n);
            break;
        }
        // them, xoa sinh vien
        case 5:
        {
        themxoa:
            system("cls");
            printf("Nhan phim\n");
            printf("(1) them sinh vien vao danh sach\n");
            printf("(2) chen sinh vien danh sach\n");
            printf("(3) xoa sinh vien khoi danh sach\n");
            printf("(4) xoa sinh vien duoi 5 diem khoi danh sach\n");
            printf("\n(99) menu\n");
            scanf("%d", &request);
            getchar();
            if (request == 1)
            {
                themSV(&a, &n);
                // xuatDDSV(a, n);
                DSSVtable(a, n);
            }
            else if (request == 2)
            {
                chenSinhVien(&a, &n);
                // xuatDDSV(a, n);
                DSSVtable(a, n);
            }
            else if (request == 3)
            {
                xoaSV(a, &n);
                // xuatDDSV(a, n);
                DSSVtable(a, n);
            }
            else if (request == 4)
            {
                xoaSVDuoi5(a, &n);
                // xuatDDSV(a, n);
                DSSVtable(a, n);
            }
            else if (request == 99)
                goto start;
            else
                goto themxoa;
            break;
        }

        default:
            goto start;
            break;
        }
        printf("\n");
        system("pause");
    } while (1);

    return 0;
}
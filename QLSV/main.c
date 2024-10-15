#include "textColor.h"
#include "SinhVien.h"

int main()
{
    int n = 1;
    do
    {
        system("cls");
        if (n <= 0)
        {
            set_color("01;91");
            printf("Nhap lai! ");
            set_color("01;97");
            printf("Lop phai co it nhat mot sinh vien\n\n");
        }
        printf("Nhap so luong sinh vien: ");
        scanf("%d", &n);
        getchar();
    } while (n <= 0); // lop co it nhat 1 ng

    sv *a = (sv *)malloc(n * sizeof(sv));
    nhapFile(a, n, "sinhvien.txt");
    // nhapDSSV(a, n);

    int number, request;
    do
    {
    start:
        system("cls");
        set_color_sc(14);
        printf("Nhan phim\n\n");
        set_color_sc(15);
        printf("(0) Thoat chuong trinh\n");
        printf("(1) Hien thi danh sach sinh vien\n");
        printf("(2) Tra cuu thong tin sinh vien\n");
        printf("(3) Sap xep danh sach sinh vien\n");
        printf("(4) Chinh sua thong tin sinh vien\n");
        printf("(5) Them, xoa, chen sinh vien\n");

        scanf("%d", &number);
        getchar();
        switch (number)
        {
        case 0:
            goto quit;
            break;
        // Danh sach
        case 1:
        {
        danhsach:
            system("cls");
            set_color_sc(14);
            printf("Nhan phim\n\n");
            set_color_sc(15);
            printf("(0) menu\n");
            printf("(1) Danh sach lop\n");
            printf("(2) Danh sach sinh vien Gioi (diem >= 8)\n");
            printf("(3) Danh sach sinh vien Kha (6.5 <= diem < 8)\n");
            printf("(4) Danh sach sinh vien Trung Binh(5 <= diem < 6.5)\n");
            printf("(5) Danh sach sinh vien Yeu (diem < 5)\n");
            printf("(6) Sinh vien co diem cao nhat\n");
            printf("(7) Sinh vien co diem thap nhat\n");
            printf("(8) Sinh vien co gioi tinh Nam\n");
            printf("(9) Sinh vien co gioi tinh Nu\n");
            scanf("%d", &request);
            getchar();
            if (request == 1)
                xuatDSSV(a, n);
            else if (request == 2)
                danhSachSVGioi(a, n);
            else if (request == 3)
                danhSachSVKha(a, n);
            else if (request == 4)
                danhSachSVTrungBinh(a, n);
            else if (request == 5)
                danhSachSVYeu(a, n);
            else if (request == 6)
                top1(a, n);
            else if (request == 7)
                topN(a, n);
            else if (request == 8)
                danhSachSVNam(a, n);
            else if (request == 9)
                danhSachSVNu(a, n);
            else if (request == 0)
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
            set_color_sc(14);
            printf("Nhan phim\n\n");
            set_color_sc(15);
            printf("(0) menu\n");
            printf("(1) tra cuu thong tin sinh vien theo MSSV\n");
            printf("(2) tra cuu thong tin sinh vien theo ho ten\n");
            scanf("%d", &request);
            getchar();
            if (request == 1)
                traCuuMSSV(a, n);
            else if (request == 2)
                traCuuHoTen(a, n);
            else if (request == 0)
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
            set_color_sc(14);
            printf("Nhan phim\n\n");
            set_color_sc(15);
            printf("(0) menu\n");
            printf("(1) sap xep danh sach sinh vien diem tang dan\n");
            printf("(2) sap xep danh sach sinh vien diem giam dan\n");
            printf("(3) sap xep danh sach sinh vien theo alphabet\n");
            scanf("%d", &request);
            getchar();
            if (request == 1)
                sapXepDiemTangDan(a, n);
            else if (request == 2)
                sapXepDiemGiamDan(a, n);
            else if (request == 3)
                sapXepTheoTen(a, n);
            else if (request == 0)
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
            set_color_sc(14);
            printf("Nhan phim\n\n");
            set_color_sc(15);
            printf("(0) menu\n");
            printf("(1) them sinh vien vao danh sach\n");
            printf("(2) chen sinh vien danh sach\n");
            printf("(3) xoa sinh vien khoi danh sach\n");
            scanf("%d", &request);
            getchar();
            if (request == 1)
                themSV(&a, &n);
            else if (request == 2)
                chenSV(&a, &n);
            else if (request == 3)
                xoaSV(&a, &n);
            else if (request == 0)
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
        xuatFile(a, n, "dssv.txt");
    } while (1);
quit:
    return 0;
}
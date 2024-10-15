#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>

#ifndef SINHVIEN_H_INCLUDED
#define SINHVIEN_H_INCLUDED

struct SinhVien
{
    char MSSV[10];
    char hoTen[40];
    char gioiTinh[5];
    char ngaySinh[12];
    char SDT[12];
    char Email[40];
    char lop[10];
    char khoa[30];
    char diaChi[30];
    float diemTB;
};
typedef struct SinhVien sv;

struct MonHoc
{
    char maMH[10];
    char tenMH[30];
};
typedef struct MonHoc mh;

// hoan vi hai cau truc
void hoanVi(sv *x, sv *y)
{
    sv temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void xoaKiTuXuongDong(char *str)
{
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
}

void nhapTTSV(sv *x)
{
    for (int i = 0; i < 1; i++)
    {
        printf("Nhap MSSV: ");
        fgets(x->MSSV, sizeof(x->MSSV), stdin);
        if (strcmp(x->MSSV, "\n") == 0)
            break;
        xoaKiTuXuongDong(x->MSSV);

        printf("Nhap ten: ");
        fgets(x->hoTen, sizeof(x->hoTen), stdin);
        xoaKiTuXuongDong(x->hoTen);

        printf("Nhap gioi tinh: ");
        fgets(x->gioiTinh, sizeof(x->gioiTinh), stdin);
        xoaKiTuXuongDong(x->gioiTinh);

        printf("Nhap ngay sinh: ");
        fgets(x->ngaySinh, sizeof(x->ngaySinh), stdin);
        xoaKiTuXuongDong(x->ngaySinh);

        printf("Nhap SDT: ");
        fgets(x->SDT, sizeof(x->SDT), stdin);
        xoaKiTuXuongDong(x->SDT);

        printf("Nhap Email: ");
        fgets(x->Email, sizeof(x->Email), stdin);
        xoaKiTuXuongDong(x->Email);

        printf("Nhap lop: ");
        fgets(x->lop, sizeof(x->lop), stdin);
        xoaKiTuXuongDong(x->lop);

        printf("Nhap khoa: ");
        fgets(x->khoa, sizeof(x->khoa), stdin);
        xoaKiTuXuongDong(x->khoa);

        printf("Nhap dia chi: ");
        fgets(x->diaChi, sizeof(x->diaChi), stdin);
        xoaKiTuXuongDong(x->diaChi);

        printf("Nhap diem trung binh: ");
        scanf("%f", &x->diemTB);
        getchar();
        if (x->diemTB > 10 || x->diemTB < 0)
            x->diemTB = 0;
    }
}

void nhapDSSV(sv *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nNhap thong tin cho sinh vien thu %d: \n", i + 1);
        nhapTTSV(&a[i]);
    }
}

void xuatTTSV(sv x)
{
    printf("  %-20s %-12s %-8s %-8s %-7s %-14s %-14s %-17s %-13s  %.2f\n",
           x.hoTen,
           x.MSSV,
           x.lop,
           x.khoa,
           x.gioiTinh,
           x.ngaySinh,
           x.SDT,
           x.Email,
           x.diaChi,
           x.diemTB);
}

void xuatDSSV(sv *a, int n)
{
    system("cls");
    set_color("01;1");
    printf("STT   Ho Ten               MSSV         Lop      Khoa     Sex     Ngay Sinh      SDT            Email             Dia chi        Diem TB\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------\n");
    // set_color("01;0");
    for (int i = 0; i < n; i++)
    {
        set_color_sc(9);
        printf("%-4d", i + 1); // STT
        set_color_sc(15);
        xuatTTSV(a[i]);
    }
}

void xuatTT1SV(sv x)
{
    printf("\nHo ten: %s\n", x.hoTen);
    printf("MSSV: %s\n", x.MSSV);
    printf("Lop: %s\n", x.lop);
    printf("Khoa: %s\n", x.khoa);
    printf("Gioi tinh: %s\n", x.gioiTinh);
    printf("Ngay Sinh: %s\n", x.ngaySinh);
    printf("SDT: %s\n", x.SDT);
    printf("Email: %s\n", x.Email);
    printf("Dia chi: %s\n", x.diaChi);
    printf("Diem trung binh: %.2f\n", x.diemTB);
}

void nhapFile(sv *a, int n, char *fileName)
{
    FILE *file = fopen(fileName, "r");
    if (file == NULL)
    {
        printf("Khong mo duoc file\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        // Nhập Mã số sinh viên
        fgets(a[i].MSSV, sizeof(a[i].MSSV), file);
        xoaKiTuXuongDong(a[i].MSSV);

        // Nhập Họ tên
        fgets(a[i].hoTen, sizeof(a[i].hoTen), file);
        xoaKiTuXuongDong(a[i].hoTen);

        // Nhập Lớp
        fgets(a[i].lop, sizeof(a[i].lop), file);
        xoaKiTuXuongDong(a[i].lop);

        // Nhập Khoa
        fgets(a[i].khoa, sizeof(a[i].khoa), file);
        xoaKiTuXuongDong(a[i].khoa);

        // Nhập Giới tính
        fgets(a[i].gioiTinh, sizeof(a[i].gioiTinh), file);
        xoaKiTuXuongDong(a[i].gioiTinh);

        // Nhập Ngày sinh
        fgets(a[i].ngaySinh, sizeof(a[i].ngaySinh), file);
        xoaKiTuXuongDong(a[i].ngaySinh);

        // Nhập Số điện thoại
        fgets(a[i].SDT, sizeof(a[i].SDT), file);
        xoaKiTuXuongDong(a[i].SDT);

        // Nhập Email
        fgets(a[i].Email, sizeof(a[i].Email), file);
        xoaKiTuXuongDong(a[i].Email);

        // Nhập địa chỉ
        fgets(a[i].diaChi, sizeof(a[i].diaChi), file);
        xoaKiTuXuongDong(a[i].diaChi);

        // Nhập Điểm
        a[i].diemTB = (double)rand() / RAND_MAX * 10.0;
    }

    fclose(file);
}

void traCuuMSSV(sv *a, int n)
{
    system("cls");
    char mssv[10];
    printf("Nhap MSSV can tim: ");
    fgets(mssv, sizeof(mssv), stdin);
    xoaKiTuXuongDong(mssv);
    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(a[i].MSSV, mssv) == 0)
        {
            found++;
            xuatTT1SV(a[i]);
            break;
        }
    }
    if (found == 0)
    {
        set_color("01;91");
        printf("\nKhong tim thay thong tin sinh vien co MSSV: %s\n", mssv);
        set_color("01;97");
    }
}

void traCuuHoTen(sv *a, int n)
{
    system("cls");
    char hoten[40];
    printf("Nhap ten sinh vien can tim: ");
    fgets(hoten, sizeof(hoten), stdin);
    xoaKiTuXuongDong(hoten);
    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(a[i].hoTen, hoten) == 0)
        {
            found++;
            xuatTT1SV(a[i]);
        }
    }
    if (found == 0)
    {
        set_color("01;91");
        printf("\nKhong tim thay thong tin sinh vien co ho ten: %s\n", hoten);
        set_color("01;97");
    }
}

void danhSachSVGioi(sv *a, int n)
{
    system("cls");
    int gioi = 0;
    set_color_sc(14);
    printf("Danh sach sinh vien loai Gioi\n\n");
    set_color_sc(15);
    set_color("01;1");
    printf("STT   Ho Ten               MSSV         Lop      Khoa     Sex     Ngay Sinh      SDT            Email             Dia chi        Diem TB\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        if (a[i].diemTB >= 8 && a[i].diemTB <= 10)
        {
            set_color_sc(9);
            printf("%-4d", i + 1); // STT
            set_color_sc(15);
            gioi++;
            xuatTTSV(a[i]);
        }
    }
    if (gioi == 0)
    {
        system("cls");
        printf("\nDanh sach lop khong co sinh vien gioi");
    }
}

void danhSachSVKha(sv *a, int n)
{
    system("cls");
    int kha = 0;
    set_color_sc(14);
    printf("Danh sach sinh vien loai Kha\n\n");
    set_color_sc(15);
    set_color("01;1");
    printf("STT   Ho Ten               MSSV         Lop      Khoa     Sex     Ngay Sinh      SDT            Email             Dia chi        Diem TB\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        if (a[i].diemTB < 8 && a[i].diemTB >= 6.5)
        {
            set_color_sc(9);
            printf("%-4d", i + 1); // STT
            set_color_sc(15);
            kha++;
            xuatTTSV(a[i]);
        }
    }
    if (kha == 0)
    {
        system("cls");
        printf("\nDanh sach lop khong co sinh vien kha");
    }
}

void danhSachSVTrungBinh(sv *a, int n)
{
    system("cls");
    int trungbinh = 0;
    set_color_sc(14);
    printf("Danh sach sinh vien loai Trung Binh\n\n");
    set_color_sc(15);
    set_color("01;1");
    printf("STT   Ho Ten               MSSV         Lop      Khoa     Sex     Ngay Sinh      SDT            Email             Dia chi        Diem TB\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        if (a[i].diemTB < 6.5 && a[i].diemTB >= 5)
        {
            set_color_sc(9);
            printf("%-4d", i + 1); // STT
            set_color_sc(15);
            trungbinh++;
            xuatTTSV(a[i]);
        }
    }
    if (trungbinh == 0)
    {
        system("cls");
        printf("\nDanh sach lop khong co sinh vien Trung Binh");
    }
}

void danhSachSVYeu(sv *a, int n)
{
    system("cls");
    int yeu = 0;
    set_color_sc(14);
    printf("Danh sach sinh vien loai Yeu\n\n");
    set_color_sc(15);
    set_color("01;1");
    printf("STT   Ho Ten               MSSV         Lop      Khoa     Sex     Ngay Sinh      SDT            Email             Dia chi        Diem TB\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        if (a[i].diemTB < 5)
        {
            set_color_sc(9);
            printf("%-4d", i + 1); // STT
            set_color_sc(15);
            yeu++;
            xuatTTSV(a[i]);
        }
    }
    if (yeu == 0)
    {
        system("cls");
        printf("\nDanh sach lop khong co sinh vien Yeu");
    }
}

void danhSachSVNam(sv *a, int n)
{
    system("cls");
    int Nam = 0;
    set_color_sc(14);
    printf("Danh sach sinh vien loai co gioi tinh nam\n\n");
    set_color_sc(15);
    set_color("01;1");
    printf("STT   Ho Ten               MSSV         Lop      Khoa     Sex     Ngay Sinh      SDT            Email             Dia chi        Diem TB\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        if (strcmp(a[i].gioiTinh, "Nam") == 0)
        {
            set_color_sc(9);
            printf("%-4d", i + 1); // STT
            set_color_sc(15);
            Nam++;
            xuatTTSV(a[i]);
        }
    }
    if (Nam == 0)
    {
        system("cls");
        printf("\nDanh sach lop khong co sinh vien gioi tinh nam");
    }
}

void danhSachSVNu(sv *a, int n)
{
    system("cls");
    int Nu = 0;
    set_color_sc(14);
    printf("Danh sach sinh vien loai co gioi tinh nu\n\n");
    set_color_sc(15);
    set_color("01;1");
    printf("STT   Ho Ten               MSSV         Lop      Khoa     Sex     Ngay Sinh      SDT            Email             Dia chi        Diem TB\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        if (strcmp(a[i].gioiTinh, "Nu") == 0)
        {
            set_color_sc(9);
            printf("%-4d", i + 1); // STT
            set_color_sc(15);
            Nu++;
            xuatTTSV(a[i]);
        }
    }
    if (Nu == 0)
    {
        system("cls");
        printf("\nDanh sach lop khong co sinh vien gioi tinh nu");
    }
}

void top1(sv *a, int n)
{
    system("cls");
    float max = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].diemTB > max && a[i].diemTB <= 10)
            max = a[i].diemTB;
    }

    set_color_sc(14);
    printf("Sinh vien co diem cao nhat\n");
    set_color_sc(15);

    for (int i = 0; i < n; i++)
    {
        if (a[i].diemTB == max)
        {
            xuatTT1SV(a[i]);
        }
    }
}

void topN(sv *a, int n)
{
    system("cls");
    float min = 10;
    for (int i = 0; i < n; i++)
    {
        if (a[i].diemTB < min && a[i].diemTB >= 0)
            min = a[i].diemTB;
    }

    set_color_sc(14);
    printf("Sinh vien co diem thap nhat\n");
    set_color_sc(15);

    for (int i = 0; i < n; i++)
    {
        if (a[i].diemTB == min)
        {
            xuatTT1SV(a[i]);
        }
    }
}

void sapXepDiemTangDan(sv *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].diemTB > a[j].diemTB)
                hoanVi(&a[i], &a[j]);
        }
    }
    xuatDSSV(a, n);
}

void sapXepDiemGiamDan(sv *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].diemTB < a[j].diemTB)
                hoanVi(&a[i], &a[j]);
        }
    }
    xuatDSSV(a, n);
}

// Hàm lấy tên (phần sau cùng của họ tên)
char *layTen(char *hoTen)
{
    // Tìm ký tự khoảng trắng cuối cùng
    char *ten = strrchr(hoTen, ' ');
    if (ten != NULL)
    {
        return ten + 1; // Trả về chuỗi sau ký tự khoảng trắng cuối cùng (phần tên)
    }
    return hoTen; // Nếu không tìm thấy khoảng trắng, trả về toàn bộ họ tên
}

void sapXepTheoTen(sv *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            // So sánh phần tên
            if (strcmp(layTen(a[j].hoTen), layTen(a[j + 1].hoTen)) > 0)
            {
                hoanVi(&a[j], &a[j + 1]);
            }
            // Nếu tên giống nhau, so sánh toàn bộ họ tên
            else if (strcmp(layTen(a[j].hoTen), layTen(a[j + 1].hoTen)) == 0)
            {
                if (strcmp(a[j].hoTen, a[j + 1].hoTen) > 0)
                {
                    hoanVi(&a[j], &a[j + 1]);
                }
            }
        }
    }
    xuatDSSV(a, n);
}

void *sua(char *inf)
{
    char infix[40];
    fgets(infix, sizeof(infix), stdin);
    xoaKiTuXuongDong(infix);
    strcpy(inf, infix);
}

void suaDiem(float *inf)
{
    float infix;
    scanf("%f", &infix);
    getchar();
    *inf = infix;
}

void chinhSua(sv *a, int n)
{
    system("cls");
    char thongTin[40];
    printf("Nhap MSSV cua sinh vien ban muon chinh sua thong tin: ");
    fgets(thongTin, sizeof(thongTin), stdin);
    xoaKiTuXuongDong(thongTin);

    int found = 0;
    int x;
    for (int i = 0; i < n; i++)
    {
        if ((strcmp(thongTin, a[i].hoTen) == 0) || (strcmp(thongTin, a[i].MSSV) == 0))
        {
            found++;
            xuatTT1SV(a[i]);

            set_color_sc(14);
            printf("\nNhan phim de chinh sua\n");
            set_color_sc(15);
            printf("(1) Ho ten\n");
            printf("(2) MSSV  \n");
            printf("(3) Lop   \n");
            printf("(4) Khoa  \n");
            printf("(5) Gioi tinh  \n");
            printf("(6) Ngay sinh  \n");
            printf("(7) SDT  \n");
            printf("(8) Email  \n");
            printf("(9) Diem  \n");

            scanf("%d", &x);
            getchar();
            switch (x)
            {
            case 1:
                printf("\nTen moi: ");
                sua(a[i].hoTen);
                break;
            case 2:
                printf("\nMSSV moi: ");
                sua(a[i].MSSV);
                break;
            case 3:
                printf("\nLop moi: ");
                sua(a[i].lop);
                break;
            case 4:
                printf("\nKhoa moi: ");
                sua(a[i].khoa);
                break;
            case 5:
                printf("\nGioi tinh moi: ");
                sua(a[i].gioiTinh);
                break;
            case 6:
                printf("\nNgay sinh moi: ");
                sua(a[i].ngaySinh);
                break;
            case 7:
                printf("\nSDT moi: ");
                sua(a[i].SDT);
                break;
            case 8:
                printf("\nEmail moi: ");
                sua(a[i].Email);
                break;
            case 9:
                printf("\nDiem moi: ");
                suaDiem(&a[i].diemTB);
                break;
            default:
                break;
            }
            break;
        }
    }
    if (found == 0)
        printf("\nKhong tim thay thong tin sinh vien can chinh sua\n");
}

void themSV(sv **a, int *n)
{
    system("cls");
    sv *b = (sv *)realloc(*a, (*n + 1) * sizeof(sv));

    if (b == NULL)
    {
        printf("Khong the cap phat bo nho!\n");
        return;
    }
    // Cập nhật con trỏ a
    *a = b;
    (*n)++;
    printf("Nhap thong tin sinh vien\n\n");
    nhapTTSV(&(*a)[*n - 1]);
    xuatDSSV(*a, *n);
}

void chenSV(sv **a, int *n)
{
    system("cls");
    int viTri;
    printf("Nhap vi tri ban muon chen: ");
    scanf("%d", &viTri);
    getchar();

    sv *b = (sv *)realloc(*a, (*n + 1) * sizeof(sv));
    if (b == NULL)
    {
        printf("Khong the cap phat bo nho!\n");
        return;
    }
    // Cập nhật con trỏ a
    *a = b;
    (*n)++;

    for (int i = 0; i < *n - 1; i++)
    {
        if (viTri == i)
        {
            for (int j = i + 1; j < *n; j++)
            {
                hoanVi(&(*a)[i], &(*a)[j]);
            }
            break;
        }
    }
    printf("\nNhap thong tin sinh vien\n");

    nhapTTSV(&(*a)[viTri]);
    hoanVi(&(*a)[viTri], &(*a)[viTri - 1]);

    xuatDSSV(*a, *n);
}

void xoaSV(sv **a, int *n)
{
    system("cls");
    char thongTin[40];
    printf("Nhap ten hoac MSSV cua sinh vien ban muon xoa: ");
    fgets(thongTin, sizeof(thongTin), stdin);
    xoaKiTuXuongDong(thongTin);

    int found = 0;
    for (int i = 0; i < *n; i++)
    {
        if ((strcmp(thongTin, (*a)[i].hoTen) == 0) || (strcmp(thongTin, (*a)[i].MSSV) == 0))
        {
            found++;
            memset((*a)[i].hoTen, 0, sizeof((*a)[i].hoTen));
            memset((*a)[i].MSSV, 0, sizeof((*a)[i].MSSV));
            memset((*a)[i].lop, 0, sizeof((*a)[i].lop));
            memset((*a)[i].khoa, 0, sizeof((*a)[i].khoa));
            memset((*a)[i].gioiTinh, 0, sizeof((*a)[i].gioiTinh));
            memset((*a)[i].ngaySinh, 0, sizeof((*a)[i].ngaySinh));
            memset((*a)[i].SDT, 0, sizeof((*a)[i].SDT));
            memset((*a)[i].Email, 0, sizeof((*a)[i].Email));
            memset((*a)[i].diaChi, 0, sizeof((*a)[i].diaChi));
            (*a)[i].diemTB = 0;
            // break;
        }
    }

    if (found == 0)
    {
        printf("\nKhong tim thay thong tin sinh vien can xoa\n");
        return;
    }

    for (int i = 0; i < *n - 1; i++)
    {
        for (int j = i + 1; j < *n; j++)
        {
            if ((strcmp("\0", (*a)[i].hoTen) == 0) &&
                (strcmp("\0", (*a)[i].MSSV) == 0) &&
                (strcmp("\0", (*a)[i].lop) == 0) &&
                (strcmp("\0", (*a)[i].khoa) == 0) &&
                (strcmp("\0", (*a)[i].ngaySinh) == 0) &&
                (strcmp("\0", (*a)[i].diaChi) == 0) &&
                (strcmp("\0", (*a)[i].Email) == 0) &&
                (strcmp("\0", (*a)[i].gioiTinh) == 0) &&
                ((*a)[i].diemTB == 0))
            {
                hoanVi(&(*a)[i], &(*a)[j]);
            }
        }
    }

    (*n) -= found;

    sv *b = (sv *)realloc(*a, *n * sizeof(sv));
    if (b != NULL)
    {
        *a = b;
    }
    else
    {
        printf("Khong the cap phat bo nho\n");
        exit(1);
    }

    xuatDSSV(*a, *n);
}

void xuatFile(sv *a, int n, char *fileName)
{
    FILE *file = fopen(fileName, "w");
    // if (file == NULL)
    // {
    //     printf("Khong mo duoc file\n");
    //     return;
    // }
    fprintf(file, "STT   Ho Ten               MSSV         Lop      Khoa     Sex     Ngay Sinh      SDT            Email             Dia chi        Diem TB\n");
    fprintf(file, "----------------------------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        fprintf(file, "%-4d", i + 1);
        fprintf(file, "  %-20s %-12s %-8s %-8s %-7s %-14s %-14s %-17s %-13s  %.2f\n",
                a[i].hoTen,
                a[i].MSSV,
                a[i].lop,
                a[i].khoa,
                a[i].gioiTinh,
                a[i].ngaySinh,
                a[i].SDT,
                a[i].Email,
                a[i].diaChi,
                a[i].diemTB);
    }
    fclose(file);
}

#endif // SINHVIEN_H_INCLUDED

// danh sách sinh viên theo năm sinh, dia chi, khoa, lop
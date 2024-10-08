#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

struct SinhVien
{
    char hoTen[40];
    char MSSV[10];
    char lop[10];
    char khoa[30];
    float diem;
};

typedef struct SinhVien sv;

void DSSVtable(sv *a, int n);
void xuatNgang(sv x);
void xoaKiTuXuongDong(char *str);

void nhap(sv *x)
{
    for (int i = 0; i < 1; i++)
    {
        printf("Nhap ten: ");
        fgets(x->hoTen, sizeof(x->hoTen), stdin);
        if (strcmp(x->hoTen, "\n") == 0)
            break;
        xoaKiTuXuongDong(x->hoTen);

        printf("Nhap MSSV: ");
        fgets(x->MSSV, sizeof(x->MSSV), stdin);
        xoaKiTuXuongDong(x->MSSV);

        printf("Nhap lop: ");
        fgets(x->lop, sizeof(x->lop), stdin);
        xoaKiTuXuongDong(x->lop);

        printf("Nhap khoa: ");
        fgets(x->khoa, sizeof(x->khoa), stdin);
        xoaKiTuXuongDong(x->khoa);

        printf("Nhap diem: ");
        scanf("%f", &x->diem);
        getchar();
        if (x->diem > 10 || x->diem < 0)
            x->diem = 0;
    }
}

void xuat(sv x)
{
    // printf("Ho ten: %s", x.hoTen);
    // printf("MSSV: %s", x.MSSV);
    // printf("Lop: %s", x.lop);
    // printf("Khoa: %s", x.khoa);
    // printf("Diem: %.2f\n", x.diem);
    printf("\nHo ten: %s\n", x.hoTen);
    printf("MSSV: %s\n", x.MSSV);
    printf("Lop: %s\n", x.lop);
    printf("Khoa: %s\n", x.khoa);
    printf("Diem: %.2f\n", x.diem);
}

void nhapDSSV(sv *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nNhap thong tin cho sinh vien thu %d: \n", i + 1);
        nhap(&a[i]);
    }
}

void xuatDDSV(sv *a, int n)
{
    system("cls");
    for (int i = 0; i < n; i++)
    {
        // if (strcmp(a[i].hoTen, "\0") == 0)
        // {
        //     continue;
        // }
        // else
        // {
        if (strcmp(a[i].hoTen, "\n") == 0)
            printf("\nKhong tim thay thong tin sinh vien thu %d\n", i + 1);
        else
        {
            printf("\nThong tin sinh vien thu %d:\n", i + 1);
            xuat(a[i]);
        }
        // }
    }
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
            printf("\nThong tin sinh vien co MSSV: %s", mssv);
            xuat(a[i]);
            break;
        }
    }
    if (found == 0)
    {
        printf("\nKhong tim thay thong tin sinh vien co MSSV: %s", mssv);
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
            printf("\nThong tin sinh vien co Ten: %s", hoten);
            xuat(a[i]);
            break;
        }
    }
    if (found == 0)
    {
        printf("\nKhong tim thay thong tin sinh vien co ho ten: %s", hoten);
    }
}

void danhSachSVGioi(sv *a, int n)
{
    system("cls");
    int gioi = 0;
    printf("Danh sach sinh vien loai Gioi\n");
    printf("Ho Ten\t\t     MSSV\tLop\t Khoa\t  Diem\n\n");
    for (int i = 0; i < n; i++)
    {
        if (a[i].diem >= 8 && a[i].diem <= 10)
        {
            // printf("\nThong tin sinh vien thu %d:\n", i + 1);
            gioi++;
            // xuat(a[i]);
            xuatNgang(a[i]);
        }
    }
    if (gioi == 0)
        printf("\nDanh sach lop khong co sinh vien gioi");
}

void danhSachSVKha(sv *a, int n)
{
    system("cls");
    int kha = 0;
    printf("Danh sach sinh vien loai Kha\n");
    printf("Ho Ten\t\t     MSSV\tLop\t Khoa\t  Diem\n\n");
    for (int i = 0; i < n; i++)
    {
        if (a[i].diem < 8 && a[i].diem >= 6.5)
        {
            // printf("\nThong tin sinh vien thu %d:\n", i + 1);
            kha++;
            // xuat(a[i]);
            xuatNgang(a[i]);
        }
    }
    if (kha == 0)
        printf("\nDanh sach lop khong co sinh vien kha");
}

void danhSachSVTrungBinh(sv *a, int n)
{
    system("cls");
    int trungbinh = 0;
    printf("Danh sach sinh vien loai Trung Binh\n");
    printf("Ho Ten\t\t     MSSV\tLop\t Khoa\t  Diem\n\n");
    for (int i = 0; i < n; i++)
    {
        if (a[i].diem < 6.5 && a[i].diem >= 5)
        {
            // printf("\nThong tin sinh vien thu %d:\n", i + 1);
            trungbinh++;
            // xuat(a[i]);
            xuatNgang(a[i]);
        }
    }
    if (trungbinh == 0)
        printf("\nDanh sach lop khong co sinh vien Trung Binh");
}

void danhSachSVYeu(sv *a, int n)
{
    system("cls");
    int yeu = 0;
    printf("Danh sach sinh vien loai Yeu\n");
    printf("Ho Ten\t\t     MSSV\tLop\t Khoa\t  Diem\n\n");
    for (int i = 0; i < n; i++)
    {
        if (a[i].diem < 5)
        {
            // printf("\nThong tin sinh vien thu %d:\n", i + 1);
            yeu++;
            // xuat(a[i]);
            xuatNgang(a[i]);
        }
    }
    if (yeu == 0)
        printf("\nDanh sach lop khong co sinh vien Yeu");
}

void top1(sv *a, int n)
{
    system("cls");
    float max = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].diem > max && a[i].diem <= 10)
            max = a[i].diem;
    }
    printf("Sinh vien co diem cao nhat\n");
    for (int i = 0; i < n; i++)
    {
        if (a[i].diem == max)
            xuat(a[i]);
    }
}

void topN(sv *a, int n)
{
    system("cls");
    float min = 10;
    for (int i = 0; i < n; i++)
    {
        if (a[i].diem < min && a[i].diem >= 0)
            min = a[i].diem;
    }
    printf("Sinh vien co diem thap nhat\n");
    for (int i = 0; i < n; i++)
    {
        if (a[i].diem == min)
            xuat(a[i]);
    }
}

// hoan vi hai cau truc
void hoanVi(sv *x, sv *y)
{
    sv temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void sapXepDiemTangDan(sv *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].diem > a[j].diem)
                hoanVi(&a[i], &a[j]);
        }
    }
    // xuatDDSV(a, n);
    DSSVtable(a, n);
}

void sapXepDiemGiamDan(sv *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].diem < a[j].diem)
                hoanVi(&a[i], &a[j]);
        }
    }
    // xuatDDSV(a, n);
    DSSVtable(a, n);
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
    // xuatDDSV(a, n);
    DSSVtable(a, n);
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
    char thongTin[40];
    int x;
    printf("Nhap Ten hoac MSSV cua sinh vien ban muon chinh sua thong tin: ");
    fgets(thongTin, sizeof(thongTin), stdin);
    xoaKiTuXuongDong(thongTin);
    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if ((strcmp(thongTin, a[i].hoTen) == 0) || (strcmp(thongTin, a[i].MSSV) == 0))
        {
            found++;
            xuat(a[i]);

            printf("\nNhan phim de chinh sua\n");
            printf("(1) Ho ten\n");
            printf("(2) MSSV  \n");
            printf("(3) Lop   \n");
            printf("(4) Khoa  \n");
            printf("(5) Diem  \n");

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
                printf("\nDiem moi: ");
                suaDiem(&a[i].diem);
                break;
            default:
                break;
            }
            break;
        }
    }
    if (found == 0)
        printf("\nKhong tim thay thong tin sinh vien can chinh sua.");
}

void themSV(sv **a, int *n)
{
    sv *b = (sv *)realloc(*a, (*n + 1) * sizeof(sv));

    if (b == NULL)
    {
        printf("Khong the cap phat bo nho!\n");
        return;
    }
    // Cập nhật con trỏ a
    *a = b;
    (*n)++;
    printf("\nNhap thong tin sinh vien\n");
    nhap(&(*a)[*n - 1]);
}

void chenSinhVien(sv **a, int *n)
{
    system("cls");
    int viTri;
    printf("Nhap vi tri ban muon chen\n");
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
    nhap(&(*a)[viTri]);
    hoanVi(&(*a)[viTri], &(*a)[viTri - 1]);
}

void xoaSV(sv *a, int *n)
{
    char thongTin[40];
    printf("\nNhap ten hoac MSSV cua sinh vien ban muon xoa: ");
    fgets(thongTin, sizeof(thongTin), stdin);
    xoaKiTuXuongDong(thongTin);
    int found = 0;

    for (int i = 0; i < *n; i++)
    {
        if ((strcmp(thongTin, a[i].hoTen) == 0) || (strcmp(thongTin, a[i].MSSV) == 0))
        {
            found++;
            strcpy(a[i].hoTen, "\0");
            strcpy(a[i].MSSV, "\0");
            strcpy(a[i].lop, "\0");
            strcpy(a[i].khoa, "\0");
            a[i].diem = 0;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nKhong tim thay thong tin sinh vien can xoa\n");
        getch();
        return;
    }

    for (int i = 0; i < *n - 1; i++)
    {
        for (int j = i + 1; j < *n; j++)
        {
            if ((strcmp("\0", a[i].hoTen) == 0) && (strcmp("\0", a[i].MSSV) == 0) && (strcmp("\0", a[i].lop) == 0) && (strcmp("\0", a[i].khoa) == 0) && (a[i].diem == 0))
            {
                hoanVi(&a[i], &a[j]);
            }
        }
    }

    (*n)--;
}

void xoaSVDuoi5(sv *a, int *n)
{
    int found = 0;

    for (int i = 0; i < *n; i++)
    {
        if (a[i].diem < 5)
        {
            found++;
            strcpy(a[i].hoTen, "\0");
            strcpy(a[i].MSSV, "\0");
            strcpy(a[i].lop, "\0");
            strcpy(a[i].khoa, "\0");
            a[i].diem = 0;
        }
    }

    if (found == 0)
    {
        printf("\nKhong co sinh vien nao duoi 5 diem\n");
        getch();
        return;
    }

    for (int i = 0; i < *n - 1; i++)
    {
        for (int j = i + 1; j < *n; j++)
        {
            if ((strcmp("\0", a[i].hoTen) == 0) && (strcmp("\0", a[i].MSSV) == 0) && (strcmp("\0", a[i].lop) == 0) && (strcmp("\0", a[i].khoa) == 0) && (a[i].diem == 0))
            {
                hoanVi(&a[i], &a[j]);
            }
        }
    }

    (*n) -= found;
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
        fgets(a[i].hoTen, sizeof(a[i].hoTen), file);
        fgets(a[i].MSSV, sizeof(a[i].MSSV), file);
        fgets(a[i].lop, sizeof(a[i].lop), file);
        fgets(a[i].khoa, sizeof(a[i].khoa), file);
        a[i].diem = 1.0 * (rand() % 10 + 1);
    }

    fclose(file);
}

void xoaKiTuXuongDong(char *str)
{
    size_t len = strlen(str);            // Lấy độ dài của chuỗi
    if (len > 0 && str[len - 1] == '\n') // Kiểm tra xem ký tự cuối có phải '\n' không
    {
        str[len - 1] = '\0'; // Nếu có, thay thế bằng ký tự kết thúc chuỗi '\0'
    }
}

void nhapFileBang(sv *a, int n, char *fileName)
{
    FILE *file = fopen(fileName, "r");
    if (file == NULL)
    {
        printf("Khong mo duoc file\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fgets(a[i].hoTen, sizeof(a[i].hoTen), file);
        xoaKiTuXuongDong(a[i].hoTen); // Loại bỏ ký tự xuống dòng

        fgets(a[i].MSSV, sizeof(a[i].MSSV), file);
        xoaKiTuXuongDong(a[i].MSSV);

        fgets(a[i].lop, sizeof(a[i].lop), file);
        xoaKiTuXuongDong(a[i].lop);

        fgets(a[i].khoa, sizeof(a[i].khoa), file);
        xoaKiTuXuongDong(a[i].khoa);
        a[i].diem = 1.0 * (rand() % 10 + 1);
    }

    fclose(file);
}

void xuatNgang(sv x)
{
    printf("%-20s %-10s %-8s %-8s %.2f\n", x.hoTen, x.MSSV, x.lop, x.khoa, x.diem);
}

void DSSVtable(sv *a, int n)
{
    system("cls");
    printf("Ho Ten\t\t     MSSV\tLop\t Khoa\t  Diem\n\n");
    for (int i = 0; i < n; i++)
    {
        xuatNgang(a[i]);
    }
}

#endif // LIBRARY_H_INCLUDED
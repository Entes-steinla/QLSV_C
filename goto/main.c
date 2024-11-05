#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

struct SinhVien
{
    long maDK;
    char CCCD[15];
    char hoTen[30];
    int KQXT;
};
typedef struct SinhVien sv;

void gotoxy(int x, int y)
{
    COORD toaDo;
    toaDo.X = x;
    toaDo.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), toaDo);
}

void remove_newline(char *str)
{
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
}

void nhapHoSo(sv *s, int x, int y)
{
    // gotoxy(x, y);

    scanf("%ld", &s->maDK);
    getchar();

    gotoxy(x + (2 * 10 - 1), y);
    fgets(s->CCCD, sizeof(s->CCCD), stdin);
    remove_newline(s->CCCD);

    gotoxy(x + (3 * 10 + 3), y);
    fgets(s->hoTen, sizeof(s->hoTen), stdin);
    remove_newline(s->hoTen);

    gotoxy(x + (6 * 10 + 2), y);
    scanf("%d", &s->KQXT);
    getchar();
}

void nhapDSHS(sv *a, int n)
{
    printf("Nhap danh sach hoc sinh\n");
    printf("Ma Dang Ky          CCCD          Ho va Ten                    Ket qua xet tuyen\n");
    for (int i = 0; i < n; i++)
    {
        nhapHoSo(&a[i], 1, i + 2);
    }
}

void xuatHoSo(sv s)
{
    printf("%-20ld%-14s%-29s%d\n", s.maDK, s.CCCD, s.hoTen, s.KQXT);
}

void xuatDSHS(sv *a, int n)
{
    system("cls");
    printf("Danh sach hoc sinh\n");
    printf("Ma Dang Ky          CCCD          Ho va Ten                    Ket qua xet tuyen\n");
    for (int i = 0; i < n; i++)
    {
        xuatHoSo(a[i]);
    }
    system("pause");
}

void traCuuMaDK(sv *a, int n)
{
    system("cls");
    long maDK;
    printf("Nhap ma dang ky: ");
    scanf("%ld", &maDK);
    getchar();
    for (int i = 0; i < n; i++)
    {
        if (maDK == a[i].maDK)
        {
            printf("Ma Dang Ky          CCCD          Ho va Ten                    Ket qua xet tuyen\n");
            xuatHoSo(a[i]);
            break;
        }
    }
    system("pause");
}

void traCuuCCCD(sv *a, int n)
{
    system("cls");
    char CCCD[15];
    printf("Nhap ma CCCD: ");
    fgets(CCCD, sizeof(CCCD), stdin);
    remove_newline(CCCD);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(CCCD, a[i].CCCD) == 0)
        {
            printf("Ma Dang Ky          CCCD          Ho va Ten                    Ket qua xet tuyen\n");
            xuatHoSo(a[i]);
            break;
        }
    }
    system("pause");
}

void sinhVienDat(sv *a, int n, float diemXT)
{
    system("cls");
    printf("Ma Dang Ky          CCCD          Ho va Ten                    Ket qua xet tuyen\n");
    for (int i = 0; i < n; i++)
    {
        if (diemXT <= a[i].KQXT)
        {
            xuatHoSo(a[i]);
        }
    }
    system("pause");
}

void xetTuyen(sv *a, int n, const char *fileName)
{
    FILE *file;
    file = fopen(fileName, "wb");
    if (file == NULL)
    {
        return;
    }
    for (int i = 0; i < n; i++)
    {
        fwrite(&a[i], sizeof(sv), 1, file);
    }
    fclose(file);
}

void docFile(sv *a, int *n, const char *fileName)
{
    FILE *file;
    file = fopen(fileName, "rb");
    if (file == NULL)
    {
        return;
    }

    int i = 0;
    while (fread(&a[i], sizeof(sv), 1, file))
    {
        i++;
    }

    *n = i;
    fclose(file);
}

int main()
{
    int n;
    printf("Nhap so luong ho so: ");
    scanf("%d", &n);
    system("cls");

    sv *a = (sv *)malloc((sizeof a) * n);
    nhapDSHS(a, n);
    xuatDSHS(a, n);
    // traCuuMaDK(a, n);
    // traCuuCCCD(a, n);
    float diemXT;
    printf("Nhap diem xet tuyen: ");
    scanf("%f", &diemXT);
    getchar();
    sinhVienDat(a, n, diemXT);
    docFile(a, &n, "xetTuyen.dat");
    xuatDSHS(a, n);

    xetTuyen(a, n, "XetTuyen.dat");
    system("pause");
}
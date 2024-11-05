#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

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

void xuatFile(sv *a, int n, char *fileName)
{
    FILE *file = fopen(fileName, "w");
    if (file == NULL)
    {
        printf("Khong mo duoc file\n");
        return;
    }
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

void xuatFileHocLai(sv *a, int n, char *fileName)
{
    FILE *file = fopen(fileName, "w");
    if (file == NULL)
    {
        printf("Khong mo duoc file\n");
        return;
    }
    fprintf(file, "STT   Ho Ten               MSSV         Lop      Khoa     Sex     Ngay Sinh      SDT            Email             Dia chi        Diem TB\n");
    fprintf(file, "----------------------------------------------------------------------------------------------------------------------------------------\n");
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i].diemTB < 5)
        {
            fprintf(file, "%-4d", count++);
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
    }
    fclose(file);
}

void ghiBangDiem_bin(sv *a, int n, char *fileName)
{
    FILE *file = fopen(fileName, "wb");
    if (file == NULL)
    {
        printf("Khong mo duoc file\n");
        return;
    }
    for (int i = 0; i < n; i++)
        fwrite(&a[i], sizeof(sv), 1, file);

    fclose(file);
}

void docBangDiem_bin(sv *a, int n, char *fileName)
{
    FILE *file = fopen(fileName, "rb");
    if (file == NULL)
    {
        printf("Khong mo duoc file\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fread(&a[i], sizeof(sv), 1, file);
    }

    fclose(file);
}

void ghiHocLai_bin(sv *a, int n, char *fileName)
{
    FILE *file = fopen(fileName, "wb");
    if (file == NULL)
    {
        printf("Khong mo duoc file\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i].diemTB < 5)
        {
            fwrite(&a[i], sizeof(a[i]), 1, file);
        }
    }
    fclose(file);
}

void docHocLai_bin(sv *a, int n, char *fileName)
{
    FILE *file = fopen(fileName, "rb");
    if (file == NULL)
    {
        printf("Khong mo duoc file\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fread(&a[i], sizeof(sv), 1, file);
    }

    fclose(file);
}

#endif // FILE_H_INCLUDED

// sua noi dung txt, sua ham nhap diem de check sv
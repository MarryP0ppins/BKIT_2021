#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include <stdlib.h>
#define lenght 10

inline bool is_a_ß(unsigned char c) {
	return 'a' <= c && c <= 'z' || 'A' <= c && c <= 'Z' || 192 <= c && c <= 255;
}


/*-----NIK----*/

struct nik {
	char* name;
	int len;
	nik();
	char& operator[](int);
	const char& operator[](int) const;
};

/*---PROVERKA---*/

struct proverka {
	int* num;
	int size;
	proverka();
	int& operator[](int);
	const int& operator[](int) const;
	void sort();
};

/*---NUMER---*/

struct numer {
	char* name;
	int ram;
	int hdd;
	int len;
	numer();
	char& operator[](int);
	const char& operator[](int) const;
	numer& operator=(const nik&);
};

/*-----INFO------*/


struct info {
	numer* str;
	int size;
	info();
	info(int len);
	int dublicate(int);
	numer& operator[](int);
	const numer& operator[](int) const;
	void zero(proverka&);
	void erase();
	void sort(int, int);
	void sdvig(int);
	void copy(int, int);
};

/*-------OTHER-------*/

bool operator>(const numer&, const numer&);
bool operator==(const numer&, const char*);
bool operator>(const numer&, const nik&);
bool operator<(const numer&, const nik&);

int menu();
void input(info&, int);
void output(info&, int);
void dlt(info&);
void sort(info&);
void search(info&);
void filter(info&);
void delet(info&);
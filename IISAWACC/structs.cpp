#include "header.h"

/*-----NIK-----*/


nik::nik() {
	name = nullptr;
	len = 0;
}

char& nik::operator[](int i) {
	if (i >= len)
	{
		name = (char*)realloc(name, (i + 1) * sizeof(char));
		len = i + 1;
	}
	return name[i];
}

const char& nik::operator[](int i) const {
	return name[i];
}


/*---PROVERKA---*/


proverka::proverka() {
	size = 0;
	num = new int[size];
}

int& proverka::operator[](int i) {
	if (i >= size)
	{
		num = (int*)realloc(num, (i + 1) * sizeof(int));
		size = i + 1;
	}
	return num[i];
}

const int& proverka::operator[](int i) const {
	return num[i];
}

void proverka::sort() {
	bool flag = true;
	for (int i = 0; i < size - 1; i++)
	{
		flag = true;
		for (int j = 0; j < size - i - 1; j++)
		{
			if (num[j] > num[j + 1])
			{
				flag = false;
				std::swap(num[j], num[j + 1]);
			}
		}
		if (flag) break;
	}
}


/*---NUMER---*/


numer::numer() {
	len = 0;
	name = nullptr;
	ram = 0;
	hdd = 0;
}

// Операторы индексирования
char& numer::operator[](int i) {
	if (i >= len)
	{
		name = (char*)realloc(name, (i + 1) * sizeof(char));
		this->len = i + 1;
	}
	return name[i];
}

const char& numer::operator[](int i) const {
	return name[i];
}


numer& numer::operator=(const nik& n) {
	name = (char*)realloc(name, len * sizeof(char));
	for (int i = 0; i < n.len; i++) this->name[i] = n[i];
	this->len = n.len;
	return *this;
}


/*-----INFO------*/


info::info() {
	size = 0;
	str = nullptr;
}

info::info(int len) {
	size = len;
	str = new numer[size];
}

int info::dublicate(int index) {
	bool flag;
	for (int i = 0; i < size; i++) {
		if (i != index) {
			flag = true;
			if (str[i].len != str[index].len) continue;
			for (int j = 0; j < str[index].len; j++)
				if (str[i][j] != str[index][j]) {
					flag = false;
					break;
				}
			if (flag) return i;
		}
	}
	return -1;
}

numer& info::operator[](int i) {
	if (i >= size) {
		str = (numer*)realloc(str, (i + 1) * sizeof(numer));
		for (size; size <= i; size++) str[i] = numer();
		size = i + 1;
	}
	return str[i];
}

const numer& info::operator[](int i) const {
	return str[i];
}

void info::zero(proverka& index) {
	for (int i = 0; i < index.size; i++) str[index[i]] = numer();
}

void info::erase() {
	int kol;
	for (int i = 1; i < size; i++) {
		kol = 0;
		if (str[i].name != NULL) {
			do kol++; while (str[i - kol].name == NULL && (i - kol) >= 0);
			kol--;
			if (kol > 0) {
				str[i - kol] = str[i];
				str[i] = numer();
			}
		}
	}
	kol = 0;
	for (int i = size - 1; true && i >= 0; i--) {
		if (str[i].name != NULL) break;
		kol++;
	}
	str = (numer*)realloc(str, (size - kol) * sizeof(numer));
	size -= kol;
}

void info::sort(int s1, int s2) {
	bool flag = true;
	for (int i = 0; i < size; i++) {
		flag = true;
		for (int j = 0; j < size - i - 1; j++) {
			if (s1 == 1 && abs(s2 + (str[j] > str[j + 1]))) {
				flag = false;
				std::swap(str[j], str[j + 1]);
			}
			else if (s1 == 2 && abs(s2 + (str[j].ram > str[j + 1].ram))) {
				flag = false;
				std::swap(str[j], str[j + 1]);
			}
			else if (s1 == 3 && abs(s2 + (str[j].hdd > str[j + 1].hdd))) {
				flag = false;
				std::swap(str[j], str[j + 1]);
			}
		}
		if (flag) break;
	}
}

void info::sdvig(int index) {
	for (int i = size; i > index; i--)
		str[i] = str[i - 1];
	size++;
}

void info::copy(int from, int to) {
	str[to] = numer();
	for (int i = 0; i < str[from].len; i++) str[to][i] = str[from][i];
	str[to][str[to].len] = '\0';
	str[to].hdd = str[from].hdd;
	str[to].ram = str[from].ram;
}

/*-------OTHER-------*/


bool operator>(const numer& n1, const numer& n2) {
	for (int i = 0; i < min(n1.len, n2.len); i++)
		if ((unsigned char)(n1[i]) - ((islower((unsigned char)(n1[i])) > 0) * 31.5) > (unsigned char)(n2[i]) - ((islower((unsigned char)(n2[i])) > 0) * 31.5)) return true;
		else if ((unsigned char)(n1[i]) != (unsigned char)(n2[i])) return false;
	if (n1.len > n2.len) return true;
	return false;
}

bool operator==(const numer& n1, const char* n2) {
	for (int i = 0; i < n1.len; i++)
		if (n1[i] != n2[i]) return false;
	return true;
}

bool operator>(const numer& n1, const nik& n2) {
	for (int i = 0; i < min(n1.len, n2.len); i++)
		if ((unsigned char)(n1[i]) - ((islower((unsigned char)(n1[i])) > 0) * 31.5) > (unsigned char)(n2[i]) - ((islower((unsigned char)(n2[i])) > 0) * 31.5)) return true;
		else if ((unsigned char)(n1[i]) != (unsigned char)(n2[i])) return false;
	if (n1.len > n2.len) return true;
	return false;
}

bool operator<(const numer& n1, const nik& n2) {
	for (int i = 0; i < min(n1.len, n2.len); i++)
		if ((unsigned char)(n1[i]) - ((islower((unsigned char)(n1[i])) > 0) * 31.5) < (unsigned char)(n2[i]) - ((islower((unsigned char)(n2[i])) > 0) * 31.5)) return true;
		else if ((unsigned char)(n1[i]) != (unsigned char)(n2[i])) return false;
	if (n1.len < n2.len) return true;
	return false;
}
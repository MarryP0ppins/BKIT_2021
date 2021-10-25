#include "Header.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	info spisok;
	input(spisok, 0);
	while (true) {
		spisok.erase();
		system("cls");
		output(spisok, 0);
		switch (menu()) {
		case 1: input(spisok, 1); break;
		case 2: input(spisok, 2); break;
		case 3: dlt(spisok); break;
		case 4: sort(spisok); break;
		case 5: search(spisok); break;
		case 6: filter(spisok); break;
		case 7: output(spisok, 1); break;
		case 8: delet(spisok); return 0;
		default: std::cout << "Введите число от 1 до 9\n"; break;
		}
	}
}
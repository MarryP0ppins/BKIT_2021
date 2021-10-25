#include "Header.h"
int menu() {
	setlocale(LC_ALL, "RUS");
	int num;
	std::cout << "\nФункции:\n";
	std::cout << "1) Добавление новых данных в список\n";
	std::cout << "2) Изменение данных в списке\n";
	std::cout << "3) Удаление данных из списка\n";
	std::cout << "4) Сортировка данных\n";
	std::cout << "5) Поиск по имени компьютера\n";
	std::cout << "6) Фильтр\n";
	std::cout << "7) Запись списка в файл\n";
	std::cout << "8) Завершить\n\n";
	std::cin >> num;
	std::cout << "\n";
	return num;
}

void input(info& spisok, int mode) {
	std::ifstream in("spisok.txt", std::ios::in);
	if (mode == 0 && !in) return;
	if (mode == 2 && spisok.size == 0) {
		system("cls");
		output(spisok, 0); std::cin.get();
		std::cout << "\nНажмите Enter что бы продолжить..."; while (std::cin.get() != 10) {};
		return;
	}
	if (mode != 0) std::cin.get();
	unsigned char simvl; int k, index, num;
	bool error, probel, stop = false;
	for (int i = spisok.size; true; i++) {
		if (spisok.size != 0 && mode != 0) spisok.erase();
		system("cls");
		if (mode != 0) output(spisok, 0);
		if (mode == 1) std::cout << "\nИмя компьютера - набор букв и цифр\nРазмер RAM и HDD - целые положительные числа\nВсе три значения вводятся через пробел\nЧтобы вернутся в главное меню - напечатайте 'stop'\n\n";
		else if (mode == 2) {
			std::cout << "\nВведите номер строки и новые данные для изменения\nЗапись, которую вы хотите изменить, должна быть в списке\n";
			std::cout << "Формат ввода: 1 Вася 10 10\nДля завершения ввода изменений нажмите enter.\nДля выхода в главное меню повторно нажмите Enter.\n\n";
		}
		error = false; probel = true; k = 0; num = 0;
		if (mode == 2) { i = spisok.size; k--; }
		for (int len = 0; true; len++) {
			if (mode == 0) { simvl = in.get(); if (in.eof()) break; }
			else simvl = std::cin.get();
			if (simvl == 32) { probel = true; continue; }
			if (!is_a_Я(simvl) && !isdigit(simvl) && simvl != 32 && simvl != 10 || (simvl == 48 && num == 0 && mode == 2 && (k == 0 || k == -1))) error = true;
			if (simvl == 10 && mode == 2 && len == 0) return;
			if (simvl == 10) break;
			if (simvl != 32 && probel) {
				len = 0; k++;
				probel = false;
				if (mode == 2 && k == 1) {
					if (!error && num <= spisok.size) num--;
					else error = true;
				}
				if (k > 3) error = true;
			}
			if (k == 0) {
				if (!isdigit(simvl)) error = true;
				else num = num * 10 + int(simvl) - 48;
			}
			else if (k == 1) {
				spisok[i][len] = simvl;
				spisok[i][len + 1] = '\0';
			}
			else if (k == 2) {
				if (!isdigit(simvl)) error = true;
				else spisok[i].ram = spisok[i].ram * 10 + int(simvl) - 48;
			}
			else if (k == 3) {
				if (!isdigit(simvl)) error = true;
				else spisok[i].hdd = spisok[i].hdd * 10 + int(simvl) - 48;
			}
		}
		spisok[i].len--;
		if (mode == 1 && k == 1 && spisok[i].len == 4 && spisok[i] == "stop") { spisok[i] = numer(); break; }

		if (k < 3) error = true;
		if (error) {
			spisok[i] = numer(); i--;
			spisok.size--;
			if (mode != 0) { std::cout << "\nНеправильный формат ввода\n"; std::cout << "Нажмите Enter что бы продолжить..."; while (std::cin.get() != 10) {}; }
			error = false;
			if (in.eof()) { spisok.erase(); break; }
			continue;
		}
		if (in.eof()) break;
		if (mode != 0) {
			index = spisok.dublicate(i);
			if (index >= 0 && ((num != index && mode == 2) || mode == 1)) {
				std::cout << "\nЗапись с идентичным ником уже существует: " << index + 1 << ") " << spisok[index].name << ' ' << spisok[index].ram << ' ' << spisok[index].hdd << '\n';
				do { std::cout << "1)Оставить введенную запись;2)Оставить существующую запись (1/2): "; simvl = std::cin.get(); } while (simvl != '1' && simvl != '2'); std::cin.get();
				std::cout << '\n';
				if (simvl == '1') {
					if (mode == 2) spisok.copy(i, num);
					spisok[index] = numer();
				}
				if (mode != 1 || mode == 1 && simvl == '2') spisok[i] = numer();
				i--;
			}
			else if (mode == 2) { spisok.copy(i, num); spisok[i] = numer(); i--; }
		}
	}
	in.close();
	if (mode != 0) spisok.erase();
}

void output(info& spisok, int mode) {
	if (spisok.size == 0) {
		std::cout << "Список пуст\n";
		return;
	}
	if (mode) {
		std::ofstream out("spisok.txt", std::ios::trunc);
		out << std::left << std::setw(lenght) << "NAME" << std::setw(lenght) << "RAM" << std::setw(lenght) << "HDD" << '\n';
		for (int i = 0; i < spisok.size; i++) out << std::left << std::setw(lenght) << spisok[i].name << std::setw(lenght) << spisok[i].ram << std::setw(lenght) << spisok[i].hdd << '\n';
		out.close();
		std::cout << "Запись в файл прошла успешно"; std::cin.get();
		std::cout << "\nНажмите Enter что бы продолжить..."; while (std::cin.get() != 10) {};
	}
	else {
		std::cout << std::right << std::setw(17) << "Список\n";
		std::cout << "   " << std::left << std::setw(lenght) << "NAME" << std::setw(lenght) << "RAM" << std::setw(lenght) << "HDD" << '\n';
		for (int i = 0; i < spisok.size; i++) std::cout << i + 1 << ") " << std::left << std::setw(lenght) << spisok[i].name << std::setw(lenght) << spisok[i].ram << std::setw(lenght) << spisok[i].hdd << '\n';
		for (int i = 0; i < 40; i++) std::cout << '-'; std::cout << '\n';
	}
}

void dlt(info& spisok)
{
	system("cls");
	output(spisok, 0);
	if (spisok.size == 0) {
		std::cin.get();
		std::cout << "\nНажмите Enter что бы продолжить..."; while (std::cin.get() != 10) {};
		return;
	}
	std::cout << "Введите номера строк, которые вы хотите исключить из списка, через пробел\nПосле завершения ввода строк, которые вы ходите удалить - нажмите Enter\n\n"; std::cin.get();
	unsigned char simvl; int x;
	bool digit, xlam, error = false;
	proverka index;
	for (index.size = 0; true;) {
		x = 0;
		digit = false, xlam = false;
		for (int i = 0; true; i++) {
			simvl = std::cin.get();
			if (isdigit(simvl)) { x = x * 10 + int(simvl) - 48; }
			if (!isdigit(simvl) && simvl != 32 && simvl != 10 || simvl == 48 && i == 0) { xlam = true; error = true; }
			if (simvl == 32 || simvl == 10) break;
		}
		if (x != 0 && !xlam) {
			if (x <= spisok.size) index[index.size] = x - 1;
			else error = true;
		}
		if (simvl == 10) break;
	}
	if (error) std::cout << "\nВводимые номера строк должжны быть сторого положительными, целыми числами и не превосходить размер списка";
	std::cout << "\nСледующие записи будут удалены:\n";
	for (int i = 0; i < index.size; i++) std::cout << index[i] + 1 << ' ';
	std::cout << "\n\nНажмите Enter что бы продолжить..."; while (std::cin.get() != 10) {};
	if (index.size == 0) return;
	index.sort();
	spisok.zero(index);
	spisok.erase();
	delete[] index.num;
}

void sort(info& spisok) {
	system("cls");
	output(spisok, 0);
	if (spisok.size == 0) {
		std::cin.get();
		std::cout << "\nНажмите Enter что бы продолжить..."; while (std::cin.get() != 10) {};
		return;
	}
	int setup1, setup2;
	std::cout << "Выберите тип сортирорвки:\n";
	do { std::cout << "1)Сортировка по имени компьютера;2)Сортировка по размеру RAM;3)Сортировка по размеру HDD (1/2/3): "; std::cin.get(); setup1 = std::cin.get() - 48; } while (setup1 != 1 && setup1 != 2 && setup1 != 3);
	do { std::cout << "Сортировка по 1)Возрастанию;2)Убыванию (1/2): "; std::cin.get(); setup2 = std::cin.get() - 48; } while (setup2 != 1 && setup2 != 2);
	spisok.sort(setup1, -setup2 + 1);
}

void search(info& spisok) {
	int index, ind = spisok.size;
	char simvl; bool error = false;
	system("cls");
	output(spisok, 0);
	if (spisok.size == 0) {
		std::cin.get();
		std::cout << "\nНажмите Enter что бы продолжить..."; while (std::cin.get() != 10) {};
		return;
	}
	std::cout << "Ведите имя компьютера без пробелов: "; std::cin.get();
	for (int i = 0; true; i++) {
		simvl = std::cin.get();
		if (!is_a_Я(simvl) && !isdigit(simvl) && simvl != 10) error = true;
		if (simvl == 10) {
			if (error) {
				std::cout << "Неправильный формат имени компьютера\n\nВедите имя компьютера без пробелов: ";
				spisok[ind] = numer();
				i = -1;
				error = false;
				continue;
			}
			break;
		}
		spisok[ind][i] = simvl;
	}
	spisok[ind][spisok[ind].len] = '\0';
	spisok[ind].len--;
	if (spisok[ind].name == NULL) return;
	index = spisok.dublicate(ind);
	if (index >= 0) {
		std::cout << "\nНайдена запсь: " << index + 1 << ") " << spisok[index].name << ' ' << spisok[index].ram << ' ' << spisok[index].hdd;
		spisok[ind] = numer();
		std::cout << "\n\nНажмите Enter что бы продолжить..."; while (std::cin.get() != 10) {};
	}
	else {
		std::cout << '\n';
		do { std::cout << "Запись не найдена. Хотите добавить новую запись в список? (y/n): "; simvl = std::cin.get(); } while (simvl != 'y' && simvl != 'n'); std::cin.get();
		if (simvl == 'y') {
			bool probel = true; int k = 0;
			std::cout << spisok[ind].name << ' ';
			for (int i = 0; true; i++) {
				simvl = std::cin.get();
				if (simvl == 32) { probel = true; continue; }
				if (!isdigit(simvl) && simvl != 32 && simvl != 10) error = true;
				if (simvl == 10) {
					if (error || k < 2) {
						spisok[ind].hdd = 0;
						spisok[ind].ram = 0;
						std::cout << "Неправильный формат ввода\n";
						error = false; k = 0; probel = true;
						std::cout << spisok[ind].name << ' ';
						continue;
					}
					break;
				}
				if (simvl != 32 && probel) {
					probel = false; k++;
					if (k > 2) error = true;
				}
				if (k == 1) spisok[ind].ram = spisok[ind].ram * 10 + int(simvl) - 48;
				else if (k == 2) spisok[ind].hdd = spisok[ind].hdd * 10 + int(simvl) - 48;
			}
		}
		else spisok[ind] = numer();
	}
}

void filter(info& spisok) {
	system("cls");
	output(spisok, 0);
	if (spisok.size == 0) {
		std::cin.get();
		std::cout << "\nНажмите Enter что бы продолжить..."; while (std::cin.get() != 10) {};
		return;
	}
	int setup1, setup2, setup3, x = 0; nik name;
	char simvl; bool error = false;
	do {
		std::cout << "1)Фильтрация по имени компьютера;2)Фильтрация по размеру RAM;3)Фильтрация по размеру HDD (1/2/3): ";
		std::cin.get();
		setup1 = std::cin.get() - 48;
	} while (setup1 != 1 && setup1 != 2 && setup1 != 3); std::cin.get();
	spisok.sort(setup1, 0);
	if (setup1 == 1) {
		std::cout << "Имя компьютера: ";
		for (int i = 0; true; i++) {
			simvl = std::cin.get();
			if (!is_a_Я(simvl) && !isdigit(simvl) && simvl != 10) error = true;
			if (simvl == 10) {
				if (error) {
					std::cout << "Неправильный формат имени компьютера\nВедите имя компьютера без пробелов: ";
					name = nik(); i = -1;
					error = false;
					continue;
				}
				break;
			}
			name[i] = simvl;
		}
		if (name.name == NULL) return;
	}
	else {
		if (setup1 == 2) std::cout << "Размер RAM: ";
		else std::cout << "Размер HDD: ";
		for (int i = 0; true; i++) {
			simvl = std::cin.get();
			if ((!isdigit(simvl) && simvl != 10) || (simvl == 48 && x == 0)) error = true;
			if (simvl == 10) {
				if (error) {
					if (setup1 == 3) std::cout << "Неправильный формат RAM\n\nВедите размер RAM без пробелов: ";
					else std::cout << "Неправильный формат HDD\n\nВедите размер HDD без пробелов: ";
					x = 0; i = -1;
					error = false;
					continue;
				}
				break;
			}
			x = x * 10 + int(simvl) - 48;
		}
		if (x == 0) return;
	}
	do { std::cout << "Показать 1)До записи включительно;2)Начиная с записи, до конца: "; setup2 = std::cin.get() - 48; std::cin.get(); } while (setup2 != 1 && setup2 != 2);
	do { std::cout << "1)Записать в файл;2)Вывести в консоль: ";  setup3 = std::cin.get() - 48; std::cin.get(); } while (setup3 != 1 && setup3 != 2);
	std::ofstream out; std::cout << '\n';
	if (setup3 == 1) {
		out.open("filtered.txt", std::ios::trunc);
		out << std::left << std::setw(lenght) << "NAME" << std::setw(lenght) << "RAM" << std::setw(lenght) << "HDD" << '\n';
	}
	else std::cout << std::left << std::setw(lenght) << "NAME" << std::setw(lenght) << "RAM" << std::setw(lenght) << "HDD" << '\n';
	for (int i = 0; i < spisok.size; i++) {
		if ((setup1 == 1 && ((setup2 == 1 && !(spisok[i] > name)) || (setup2 == 2 && !(spisok[i] < name)))) || (setup1 == 2 && ((setup2 == 1 && spisok[i].ram <= x) || (setup2 == 2 && spisok[i].ram >= x))) || (setup1 == 3 && ((setup2 == 1 && spisok[i].hdd <= x) || (setup2 == 2 && spisok[i].hdd >= x)))) {
			if (setup3 == 1) out << std::left << std::setw(lenght) << spisok[i].name << std::setw(lenght) << spisok[i].ram << std::setw(lenght) << spisok[i].hdd << '\n';
			else std::cout << std::left << std::setw(lenght) << spisok[i].name << std::setw(lenght) << spisok[i].ram << std::setw(lenght) << spisok[i].hdd << '\n';
		}
	}
	if (setup3 == 2) { std::cout << "Нажмите Enter что бы продолжить..."; while (std::cin.get() != 10) {}; }
	out.close();
	delete[] name.name;
}

void delet(info& spisok) {
	for (int i = 0; i < spisok.size; i++) delete[] spisok[i].name;
	delete[] spisok.str;
	std::cout << "Нажмите любую клавишу что бы завершить программу..."; std::cin.get(); std::cin.get();
}
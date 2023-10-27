#include <iostream>
#include <string>
#include <cstring>

using namespace std;
int main()
{
	setlocale(0, "");
	cout << "Введите количество заказанных блюд: ";
	int number_of_dishes;
	cin >> number_of_dishes;

	// Выделяем динамические массивы для названия блюд, количества порций и стоимости за порцию
	char** name_of_the_dish = new char* [number_of_dishes]; // Название блюда
	int* size = new int[number_of_dishes]; // Количество порций
	float* price = new float[number_of_dishes]; // Стоимость за порцию

	cin.ignore(); // очищаем буфер после ввода числа
	// Ввод названия блюд, количества порций и стоимости за порцию
	for (int i = 0; i < number_of_dishes; ++i) {
		cout << "Введите название блюда " << i + 1 << ": ";
		char buffer[100];
		cin.getline(buffer, 100);
		name_of_the_dish[i] = new char[strlen(buffer) + 1];
		strcpy(name_of_the_dish[i], buffer);

		cout << "Введите количество порций " << i + 1 << ": ";
		cin >> size[i];
		cout << "Введите стоимость за порцию " << i + 1 << ": ";
		cin >> price[i];
		cin.ignore(); // очищаем буфер после ввода числа
	}
	// Сортировка названий блюд по алфавиту
	for (int i = 0; i < number_of_dishes - 1; ++i) {
		for (int j = 0; j < number_of_dishes - i - 1; ++j) {
			if (strcmp(name_of_the_dish[j], name_of_the_dish[j + 1]) > 0) {
				swap(name_of_the_dish[j], name_of_the_dish[j + 1]);
				swap(size[j], size[j + 1]);
				swap(price[j], price[j + 1]);
			}
		}
	}
	// Вывод отсортированного списка заказанных блюд
	cout << "\nОтсортированный список заказанных блюд:\n";
	for (int i = 0; i < number_of_dishes; ++i) {
		cout << "Название блюда: " << name_of_the_dish[i] << ", Количество порций: " << size[i] << ", Стоимость за порцию: " << price[i] << endl;
	}
	// Расчет общей стоимости заказа
	float all_price;
	for (int i = 0; i < number_of_dishes; i++) {
		all_price = price[i] * size[i];
		cout << "Общая стоимость заказа: " << all_price << endl;
	}
	// Расчет общей суммы всех заказов
	float sum = 0;
	for (int i = 0; i < number_of_dishes; i++) {
		sum = sum + size[i] * price[i];
	}
	cout << "Общая сумма всех заказов: " << sum << endl;
	// освобождаем память
	delete[] name_of_the_dish;
	delete[] size;
	delete[] price;

	return 0;
}
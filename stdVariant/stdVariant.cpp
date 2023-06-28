// stdVariant.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <variant>
#include <vector>
//Данный код представляет собой функцию get_variant(), которая возвращает объект типа std::variant<int, std::string, std::vector<int>>.
//std::variant позволяет хранить значения разных типов в одном объекте.указываем какие типы данных могут храниться здесь -int string vector
std::variant <int, std::string, std::vector<int>> get_variant() {
	// Здесь устанавливается начальное значение генератора псевдослучайных чисел с помощью функции std::srand
	std::srand(std::time(nullptr));
	//Здесь генерируется случайное число от 0 до 2 с помощью функции std::rand(). Затем оно сохраняется в переменную random_variable
	int random_variable = std::rand() % 3;
// Здесь объявляется объект result типа std::variant<int, std::string, std::vector<int>>, который будет хранить значение возвращаемое функцией
	std::variant<int, std::string, std::vector<int>> result;//переменная
	//Здесь начинается блок switch, который основан на значении random_variable
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	//После выполнения блока switch, объект result возвращается как результат функции get_variant()
	return result;
}
//В итоге, функция get_variant() генерирует случайное число от 0 до 2 и возвращает объект result, 
//который может содержать либо целое число, либо строку, 
//либо вектор чисел в зависимости от значения random_variable
int main()
//Вам нужно написать обработку результата этой функции следующим образом:
//Если в результате функции содержится int, то вывести число, умноженное на 2.
//Если в результате функции содержится строка, то просто вывести её в консоль.
//Если в результате функции содержится вектор чисел, то вывести все его элементы в консоль.
{
	setlocale(LC_ALL, "RU");
//Используйте функции std::holds_alternative, std::get или std::get_if
// вызываем функцию get_variant(), которая возвращает случайное значение типа std::variant<int, std::string, std::vector<int>>
	auto result = get_variant();
//проверяем есть ли вообще такое значение в variante при помощи std::holds_alternative
	if (std::holds_alternative<int>(result)) {
//Если тип совпадает, мы используем функцию std::get для получения значения из варианта 
		int value = std::get<int>(result);
		std::cout << "Число: " << value * 2 << std::endl;
	}
	else if (std::holds_alternative<std::string>(result)) {
		std::string value = std::get<std::string>(result);
		std::cout << "Строка: " << value << std::endl;
	}
	else if (std::holds_alternative<std::vector<int>>(result)) {
		std::vector<int> value = std::get<std::vector<int>>(result);
		std::cout << "Вектор чисел: ";
		//выводим все его элементы в консоль
		for (const auto& num : value) {
			std::cout << num << " ";
		}
		std::cout << std::endl;
	}

	return 0;

}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


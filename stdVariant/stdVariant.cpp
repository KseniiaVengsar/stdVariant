// stdVariant.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <variant>
#include <vector>
//������ ��� ������������ ����� ������� get_variant(), ������� ���������� ������ ���� std::variant<int, std::string, std::vector<int>>.
//std::variant ��������� ������� �������� ������ ����� � ����� �������.��������� ����� ���� ������ ����� ��������� ����� -int string vector
std::variant <int, std::string, std::vector<int>> get_variant() {
	// ����� ��������������� ��������� �������� ���������� ��������������� ����� � ������� ������� std::srand
	std::srand(std::time(nullptr));
	//����� ������������ ��������� ����� �� 0 �� 2 � ������� ������� std::rand(). ����� ��� ����������� � ���������� random_variable
	int random_variable = std::rand() % 3;
// ����� ����������� ������ result ���� std::variant<int, std::string, std::vector<int>>, ������� ����� ������� �������� ������������ ��������
	std::variant<int, std::string, std::vector<int>> result;//����������
	//����� ���������� ���� switch, ������� ������� �� �������� random_variable
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
	//����� ���������� ����� switch, ������ result ������������ ��� ��������� ������� get_variant()
	return result;
}
//� �����, ������� get_variant() ���������� ��������� ����� �� 0 �� 2 � ���������� ������ result, 
//������� ����� ��������� ���� ����� �����, ���� ������, 
//���� ������ ����� � ����������� �� �������� random_variable
int main()
//��� ����� �������� ��������� ���������� ���� ������� ��������� �������:
//���� � ���������� ������� ���������� int, �� ������� �����, ���������� �� 2.
//���� � ���������� ������� ���������� ������, �� ������ ������� � � �������.
//���� � ���������� ������� ���������� ������ �����, �� ������� ��� ��� �������� � �������.
{
	setlocale(LC_ALL, "RU");
//����������� ������� std::holds_alternative, std::get ��� std::get_if
// �������� ������� get_variant(), ������� ���������� ��������� �������� ���� std::variant<int, std::string, std::vector<int>>
	auto result = get_variant();
//��������� ���� �� ������ ����� �������� � variante ��� ������ std::holds_alternative
	if (std::holds_alternative<int>(result)) {
//���� ��� ���������, �� ���������� ������� std::get ��� ��������� �������� �� �������� 
		int value = std::get<int>(result);
		std::cout << "�����: " << value * 2 << std::endl;
	}
	else if (std::holds_alternative<std::string>(result)) {
		std::string value = std::get<std::string>(result);
		std::cout << "������: " << value << std::endl;
	}
	else if (std::holds_alternative<std::vector<int>>(result)) {
		std::vector<int> value = std::get<std::vector<int>>(result);
		std::cout << "������ �����: ";
		//������� ��� ��� �������� � �������
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

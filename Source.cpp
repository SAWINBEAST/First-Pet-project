#include <iostream>
#include "Header.h"
#include <ostream>
#include <istream>
#include <fstream>
#include <string>
#include <cstdio>




// ���������� ���� � �������
void General_Functions::show_menu() {
	cout << "[1] Get card details. " << endl;
	cout << "[2] Enter new card. " << endl;
	cout << "[3] Change old card details. " << endl;
	cout << "[4] Remove one card. " << endl;
	cout << "[5] Remove all cards. " << endl;
	cout << "[6] Exit. " << endl;
}

// �������� ����������� ������ ������������ � ������ ��� ������ � ����
void General_Functions::registration() {
	
	string username, password;

	cout << "Select an username: "; cin >> username;
	cout << "Select a password: "; cin >> password;

	ofstream file;
	file.open("C:\\" + username + ".txt");
	//file.open("C:\Users\79296\\hello.txt");
	if (!file.is_open()) {
		cout << "[-] File is not opened!";
		exit(EXIT_FAILURE);
	}
	file << username << endl << password;
	file.close();
	cout << "Successfully registered.\n " << endl;

}

// ������������ ���� ��� ������������������� ������������
bool General_Functions::IsLoggedIn() {

	string username, password, un, pw;

	cout << "Enter username: "; cin >> username;
	cout << "Enter password: "; cin >> password;

	ifstream read("C:\\" + username + ".txt");
	//ifstream read("C:\Users\79296\\hello.txt");
	if (!read.is_open()) {
		cout << "[-] File is not opened!";
		exit(EXIT_FAILURE);
	}
	getline(read, un);		// ��� ����� ������ ������� ��������� (while)
	getline(read, pw);

	read.close();
	if (un == username && pw == password)
	{
		return true;
	}
	else
	{
		return false;
	}

}

//
void GetCardNums::get_nums() {

	//exists() - ��� ������� ��������
	// if (file.bad() == true)


	fstream file("" + received_card + ".txt", std::ios::in);		//ofstream ?

	if (!file.is_open()) {
		cout << "[-] File is not opened! 1 level of get_nums() ";
		exit(EXIT_FAILURE);
	}
	string desired_card_nums;
	while (getline(file, desired_card_nums))
	{
		std::string decrypt_nums;
		std::string tempStr; // ������������� ������
		for (size_t i = 0; i < desired_card_nums.size(); i += 3)
		{
			tempStr.push_back(desired_card_nums[i]);
			tempStr.push_back(desired_card_nums[i + 1]);
			tempStr.push_back(desired_card_nums[i + 2]);
			decrypt_nums.push_back(char(std::stoi(tempStr)));
			tempStr.clear();
		}

		std::cout << decrypt_nums << std::endl;
	}

	file.close();

	cout << "Above you see the details of card \"" + received_card + "\" " << endl;
}

// ���������� ����� ������ ����� 
void CardNumActions::enter_new() {			
	//(string cardnums, string cardname) 
	//cout << "\n cardnums: "<< cardnums << endl;
	ofstream file(""+cardname+".txt", std::ios::app );		// std::ios::app - ���������� �������� � ���� � ����� �������� ����� ; 
	if (!file.is_open()) {
		cout << "[-] File is not opened!";
		exit(EXIT_FAILURE);
	}

	string encrypt_cardnums = "";

	for (size_t i = 0; i < cardnums.size(); i++)
	{
		for (size_t j = 0; j < 3 - (std::to_string((int)cardnums[i])).size(); j++)
		{
			encrypt_cardnums += "0";
		}
		encrypt_cardnums += std::to_string((int)(cardnums[i]));
	}

	file << encrypt_cardnums;			// ��� ����� ���-�� ������������ ������ ������
	file.close();

	cout << "New cardnumbers was succesfully recorded. " << endl;
}

//
void ChangeCardNums::change_nums() {// �������� ������, ���� ������� ����������� ������ ��� ����� ����� ���. ��� � get_name()
	
	fstream file(""+ change_name+".txt",  std::ios::out  | std::ios::trunc  );		// ios::out: ���� ����������� ��� ������ (������). ��� ���� ������ ������ ���������  // ios::trunc: ���� ��������� ��� ��������. ����� ���� ����������, ���� ����� ���������� ����� out    
	if (!file.is_open()) {
		cout << "[-] File is not openned! 1 level of change_nums() ";							
		exit(EXIT_FAILURE);
	}
	file.close();

}

//
void ChangeCardNums::change_nums_seclev() {

	fstream file("" + change_name + ".txt", std::ios::app);		//ofstream ?
	if (!file.is_open()) {
		cout << "[-] File is not opened! 2 level of change_nums() ";
		exit(EXIT_FAILURE);
	}

	string encrypt_cardnums = "";

	for (size_t i = 0; i < changing_nums.size(); i++)
	{
		for (size_t j = 0; j < 3 - (std::to_string((int)changing_nums[i])).size(); j++)
		{
			encrypt_cardnums += "0";
		}
		encrypt_cardnums += std::to_string((int)(changing_nums[i]));
	}

	file << encrypt_cardnums;			// ��� ����� ���-�� ������������ ������ ������
	file.close();

	cout << "Actual cardnumbers for " + change_name + " was succesfully changed. " << endl;
}

void RemoveOneCard::removecard() {
	//�������� ��������:
				//rmdir (	if (!rmdir(removable_card)) printf("FORMLET removed\n"); )
				
				//boost:: filesystem:: remove_all (yourPath)		// ��� �� ��� �++17
				//std::filesystem::path::remove("myEmptyDirectoryOrFile"); 
				//std::filesystem::path::remove_all("myDirectory");
				//#include <experimental/filesystem>
				//std::experimental::filesystem::path::remove("myDirectory");
				//std::experimental::filesystem::path::remove_filename
	
				/*if (remove(removable_card)) {		// ��� ����� ����� ��� char. � �����  char ��������� �������� ��� ��������������� ������ � ����� �� main
				printf("Error removing file");
				return 1;
				}
				else return 0;
				*/
	char file_name[30];
	cout << "Which card would you like to remove?\nEnter the nickname of your card with postscript (.txt): ";
	cin >> file_name;
	if (remove(file_name) != 0)             
		std::cout << "huita. file has NOT been removed \n";
	else
		std::cout << "succes. file has been removed\n";
	
}

void RemoveAllCards::removecards() {


}













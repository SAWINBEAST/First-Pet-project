#include <iostream>
#include "CardActions.h"
#include <ostream>
#include <istream>
#include <fstream>
#include <string>
#include <cstdio>

// ���������� ������ ����� 
void CardActions::GetNums(const string& card_to_get) {
	//13
	fstream file("" + card_to_get + ".txt", std::ios::in);
	if (!file.is_open()) {
		cout << "[-] File is not opened! 1 level of get_nums() ";
		exit(EXIT_FAILURE);
	}
	string desired_card_nums;
	while (getline(file, desired_card_nums))
	{
		std::string decrypt_nums;
		std::string tempStr;	//14
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

	cout << "Above you see the details of card \"" + card_to_get + "\" " << endl;
}

// ���������� ����� ������ ����� 
void CardActions::EnterNew(const string& new_cardnums, const string& new_cardname) {
	ofstream file("" + new_cardname + ".txt", std::ios::app);	//15
	if (!file.is_open()) {
		cout << "[-] File is not opened!";
		exit(EXIT_FAILURE);
	}

	string encrypt_cardnums = "";
	for (size_t i = 0; i < new_cardnums.size(); i++)
	{
		for (size_t j = 0; j < 3 - (std::to_string((int)new_cardnums[i])).size(); j++)
		{
			encrypt_cardnums += "0";
		}
		encrypt_cardnums += std::to_string((int)(new_cardnums[i]));
	}

	file << encrypt_cardnums;	//16
	file.close();

	cout << "New cardnumbers was succesfully recorded. " << endl;
}

// ������� ������ ������������ ����� 
void CardActions::ChangeNumsFirst(const string& change_cardname) {//17

	fstream file("" + change_cardname + ".txt", std::ios::out | std::ios::trunc);		//18  
	if (!file.is_open()) {
		cout << "[-] File is not openned! 1 level of change_nums() ";
		exit(EXIT_FAILURE);
	}
	file.close();

}

// ������(���������) ������ ������������ �����
void CardActions::ChangeNumsSecond(const string& change_cardname, const string& change_cardnums) {

	fstream file("" + change_cardname + ".txt", std::ios::app);		//ofstream ?
	if (!file.is_open()) {
		cout << "[-] File is not opened! 2 level of change_nums() ";
		exit(EXIT_FAILURE);
	}

	string encrypt_cardnums = "";

	for (size_t i = 0; i < change_cardnums.size(); i++)
	{
		for (size_t j = 0; j < 3 - (std::to_string((int)change_cardnums[i])).size(); j++)
		{
			encrypt_cardnums += "0";
		}
		encrypt_cardnums += std::to_string((int)(change_cardnums[i]));
	}

	file << encrypt_cardnums;			// ��� ����� ���-�� ������������ ������ ������
	file.close();

	cout << "Actual cardnumbers for " + change_cardname + " was succesfully changed. " << endl;
}

// ������� ������ ����������� �����
void CardActions::RemoveCard() {
	//19
	char file_name[30];	//20
	cout << "Which card would you like to remove?\nEnter the nickname of your card with postscript (.txt): ";
	cin >> file_name;
	if (remove(file_name) != 0)
		std::cout << "huita. file has NOT been removed \n";
	else
		std::cout << "succes. file has been removed\n";

}

// ������� ��� �����
void CardActions::RemoveCards() {
	cout << "This action is temporarily unavailable.\nContact the developer\nWe suggest you delete all files separately." << endl;

}
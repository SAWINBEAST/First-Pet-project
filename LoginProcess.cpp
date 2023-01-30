﻿#include "LoginProcess.h"
#include <iostream>
#include <ostream>
#include <istream>
#include <fstream>
#include <string>
#include <cstdio>

// Проводит регистрацию нового пользователя и запись его данных в файл
void LoginProcess::Registration() {

	string* username = new string;
	string* password = new string;

	cout << "Select an username: "; cin >> *username;
	cout << "Select a password: "; cin >> *password;

	ofstream file;
	file.open("C:\\" + *username + ".txt");
	if (!file.is_open()) {
		cout << "[-] File is not opened!";
		exit(EXIT_FAILURE);
	}
	file << *username << endl << *password;
	file.close();
	cout << "Successfully registered.\n " << endl;

	delete username;
	delete password;
	username = nullptr;
	password = nullptr;
}

// Осуществляет вход уже зарегистрированного пользователя
bool LoginProcess::IsLoggedIn() {

	string* username = new string;
	string* password = new string;
	string* un = new string;
	string* pw = new string;

	//string  un, pw;

	cout << "Enter username: "; cin >> *username;
	cout << "Enter password: "; cin >> *password;

	ifstream read("C:\\" + *username + ".txt");
	if (!read.is_open()) {
		cout << "[-] File is not opened!";
		exit(EXIT_FAILURE);
	}
	getline(read, *un);		// тут можно циклом сделать прочтение (while)
	getline(read, *pw);
	read.close();

	if (*un == *username && *pw == *password)
	{
		return true;
	}
	else
	{
		return false;
	}

	delete un;
	delete pw;
	delete username;
	delete password;
	username = nullptr;
	password = nullptr;
	un = nullptr;
	pw = nullptr;
}
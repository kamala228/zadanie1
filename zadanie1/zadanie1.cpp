#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#define c cout
#define e endl

void task1() {
    ifstream input("zadaniee1.txt");
    ofstream output("file.txt");

    if (!input.is_open()) {
        c << "Не вдалося відкрити файл" << e;
        return;
    }

    string word;
    while (input >> word) {
        if (word[0] == 'о' || word[0] == 'а' || word[0] == 'О' || word[0] == 'А') {
            output << word << e;
        }
    }

    input.close();
    output.close();

    c << "Завдання 1 виконано. Файл 'file' створено." << e;
}

void task2() {
    ifstream input("zadanie2.txt");
    ofstream evenFile("parni.txt");
    ofstream oddFile("ne_parni.txt");

    if (!input.is_open()) {
        c << "Не вдалося відкрити файл" << e;
        return;
    }

    int number;
    while (input >> number) {
        if (number % 2 == 0) {
            evenFile << number << e;
        }
        else {
            oddFile << number << e;
        }
    }

    input.close();
    evenFile.close();
    oddFile.close();

    c << "Завдання 2 виконано. Файли 'parni.txt' та 'ne_parni.txt' створено." << e;
}

void task3() {
    ifstream file1("zadanie3.txt");
    ifstream file2("zadaniee3.txt");

    if (!file1.is_open() || !file2.is_open()) {
        c << "Не вдалося відкрити якийсь файл" << e;
        return;
    }

    vector<char> file1Chars, file2Chars;

    char ch;
    while (file1.get(ch)) file1Chars.push_back(ch);
    while (file2.get(ch)) file2Chars.push_back(ch);

    file1.close();
    file2.close();

    ofstream outFile1("file1.txt");
    for (char c : file2Chars) outFile1 << c;

    ofstream outFile2("file2.txt");
    for (char c : file1Chars) outFile2 << c;

    outFile1.close();
    outFile2.close();

    c << "Завдання 3 виконано. Файли 'file1.txt' та 'file2.txt' обмінялися вмістом." << e;
}

int main() {
    system("chcp 1251>null");
    int choice;

    c << "Оберіть завдання:" << e;
    c << "1 - Фільтрація слів (починаються на 'о' або 'а')" << e;
    c << "2 - Розділення чисел на парні та непарні" << e;
    c << "3 - Обмін символами між двома файлами" << e;
    c << "Ваш вибір: ";
    cin >> choice;

    switch (choice) {
    case 1:
        task1();
        break;
    case 2:
        task2();
        break;
    case 3:
        task3();
        break;
    default:
        c << "Невірний вибір." << e;
    }

    return 0;
}

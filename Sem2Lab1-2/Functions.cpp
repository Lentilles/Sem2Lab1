#include "students.h" // Подключение пользовательского заголовочного файла

using namespace std;

struct Students // Структура из задания
{
	string* group;
	string* faculty;
	int* countOfStudents;
	int* countOfGoodStudents;
};

// Блок логических переменных

bool flag = false;

// Блок целочисленных глобальных переменных

int totalAmountStudents = 0;
int totalGoodStudents = 0;
int storagedMemory = 0;

// Создание глобальной переменной структуры

Students students;

// Блок меню

void menu() {
	int k = 0;

	while (k != 5) {
		cout << "\n Выберите пункт меню \n";
		cout << " 1 - прочитать файл" << "\n";
		cout << " 2 - изменить файл" << "\n";
		cout << " 3 - найти процент от умных студентов" << "\n";
		cout << " 4 - сохранить файл" << "\n";
		cout << " 5 - выход" << "\n";
		cin >> k;
		switch (k)
		{
			case 1:{
					inputFromFile();
			}break;

			case 2: {
					choseEdit();
			}break;

			case 3: {
					cout << "\n" << percentOfGoodStudents();
			}break;

			case 4: {
					writeFile();
			}break;
			case 5: {
					exit;
			}break;

			default: {
					cout << "\n Не предусмотренное значение \n";
			}break;
		}
	}
}

// Получить или изменить значение памяти

int getsetMemory(int memory)  { // >0 для вывода значения памяти <=0 для ввода значения памяти

	if(memory < 0){
		return storagedMemory;
	}
	else {
		storagedMemory = memory;
	}
}

// Блок автоматического нахождения необходимого количества ячеек для массива

int findValueOfMemory(string fileName) {
	// Временные переменные
	char *temp;
	string *tempS;

	//
	
	int memorySTR = 0; // Количество строк
	int memoryCOL = 0; // Количество колонок


	ifstream fin;
	fin.open(fileName);
	// Выделение памяти временным данным

	tempS = new string;
	temp = new char[32];

	while (!fin.eof())
	{
		fin.getline(temp, 32, '\n');
		memorySTR++;
	}
	fin.close();
	
	fin.open(fileName);

	while (!fin.eof())
	{
		fin >> *tempS;
		memoryCOL++;
	}
	fin.close();

	// Делим количество колонок на количество строк, а так же округляем для большего, чтобы всегда хватало памяти для записи доп информации.

	memoryCOL = floor(memoryCOL/memorySTR);
	
	cout << "Размер массива определен: "<< memorySTR << "\n";
	cout << "Размер массива определен: "<< memoryCOL << "\n";

	// Освобождение временной памяти
	delete tempS;
	delete temp;

	// Установка количества ячеек и передача информации о количестве необходимых ячеек

	getsetMemory(memorySTR);
	return memorySTR;
}

	// Блок ввода из файла в переменные 

void inputFromFile() {
	string fileName;
	int memory = 0;

	ifstream finp;

	cout << "\n Задайте имя читаемого файла, без расширения.\n";
	cout << "Если файл в папке с программой, просто имя файла. Иначе путь до него. \n";
	cout << "Файл:  "; 
	cin >> fileName;

	// Вызов функции автоматического определения размера массива
	memory = findValueOfMemory(fileName);
	finp.open(fileName);


	students.faculty = new string[memory];
	students.group = new string[memory];
	students.countOfGoodStudents = new int[memory];
	students.countOfStudents = new int[memory];
	
	int it = 0;

	while (it < memory) {
		finp >> students.faculty[it];
		finp >> students.group[it];
		finp >> students.countOfStudents[it];
		finp >> students.countOfGoodStudents[it];
		totalAmountStudents += students.countOfStudents[it];
		totalGoodStudents += students.countOfGoodStudents[it];
		cout << "\n В этом цикле всего студентов: " << totalAmountStudents << " |  " << students.countOfStudents[it];
		cout << "\n В этом цикле всего good студентов: " << totalGoodStudents << " |  " << students.countOfGoodStudents[it];
		it++;
	}

	if(memory > 0){
		flag = true;
	}
	else {
		cout << "К сожалению ничего не было записано, потому что файл пустой.";
	}

}

// Блок выбора необходимого элемента для редактирования

void choseEdit() {
	int p = 0;
	int memory = getsetMemory(-1);
	int elementNum;

	if (flag == true) {
		cout << "Что вы хотите изменить? \n";
		cout << "1 - Факультет \n";
		cout << "2 - Группу \n";
		cout << "3 - Количество студентов\n";
		cout << "4 - Количество отличников \n";
		cout << "5 - Назад в меню \n";

		
		cin >> p;

		switch (p)
		{
		case 1: {
			cout << "Какой элемент по счету вы хотите редактировать? \n";
			cout << "в диапазоне от 1 до " << memory << "\n";
			cin >> elementNum;
			if (elementNum < memory && flag == true) {
				edit(p, elementNum);
			}
			else {
				cout << "Такого элемента не существует";
			}
		}break;
		case 2: {
			cout << "Какой элемент по счету вы хотите редактировать? \n";
			cout << "в диапазоне от 1 до " << memory << "\n";
			cin >> elementNum;
			if (elementNum < memory && flag == true) {
				edit(p, elementNum);
			}
			else {
				cout << "Такого элемента не существует";
			}
		}break;
		case 3: {
			cout << "Какой элемент по счету вы хотите редактировать? \n";
			cout << "в диапазоне от 1 до " << memory << "\n";
			cin >> elementNum;
			if (elementNum < memory && flag == true) {
				edit(p, elementNum);
			}
			else {
				cout << "Такого элемента не существует";
			}
		}break;
		case 4: {
			cout << "Какой элемент по счету вы хотите редактировать? \n";
			cout << "в диапазоне от 1 до " << memory << "\n";
			cin >> elementNum;
			if (elementNum < memory && flag == true) {
				edit(p, elementNum);
			}
			else {
				cout << "Такого элемента не существует";
			}
		}break;
		case 5: {
			menu();
		}
		default:
			break;
		}
	}
	else
	{
		cout << "\n Файл не был прочитан, невозможно изменить значения \n";
	}
}

 //Блок редактирования прочитанной информации

void edit(int typeForEditing, int elementForEditing) {
	string newStr;
	int newInt = 0;


	switch (typeForEditing)
	{
	case 1: {
		cout << "Введите строку на которую хотите поменять" << '\n';
		cin >> newStr;
		students.faculty[elementForEditing - 1] = newStr;
	}break;
	case 2: {
		cout << "Введите строку на которую хотите поменять" << '\n';
		cin >> newStr;
		students.group[elementForEditing - 1] = newStr;
	}break;
	case 3: {
		cout << "Введите целое число на которое хотите поменять" << '\n';
		cin >> newInt;
		students.countOfStudents[elementForEditing - 1] = newInt;
	}break;
	case 4: {
		cout << "Введите целое число на которое хотите поменять" << '\n';
		cin >> newInt;
		students.countOfGoodStudents[elementForEditing - 1] = newInt;
	}break;

	default:
		break;
	}

}

// Блок вычисления процента хороших студентов

double percentOfGoodStudents() {
	double percantage = 0.0;
	double allStudents = totalAmountStudents;
	double goodStudents = totalGoodStudents;

	if (allStudents > 0 && goodStudents > 0) {
		percantage = (goodStudents / allStudents) * 100.0;
		return percantage;
	}
	else
	{
		cout << "\n Невозможное количество студентов \n Попробуйте воспользоваться пунктом меню 1. \n";
	}

}

// Блок записи в файл

void writeFile() {
	int counter = 0;
	int amountOfUnits = getsetMemory(-1);
	double percent;
	if (percentOfGoodStudents > 0) {
		percent = percentOfGoodStudents();
	}
	else {
		cout << "\n Студентов нет. \n";
	}
	cout << percent;
	string fileName;
	cout << "\n Введите имя файла и расширение. \n";
	cin >> fileName;

	ofstream ofs(fileName);
	ofs <<"Процент отличников = "  << percent << "% \n";
	ofs << "Факультет | " << " Группа | " << " Количество учеников | " << " Количество отличников " << "\n";

	while (counter < amountOfUnits) {
		ofs << students.faculty[counter] << " ";
		ofs << students.group[counter] << " ";
		ofs << students.countOfStudents[counter] << " ";
		ofs << students.countOfGoodStudents[counter] << "\n";
		counter++;
	}
}
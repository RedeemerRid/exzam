#include <iostream>  ///    MUSUKOV ----------
#include <iomanip>
#include <io.h>
#include <stdio.h>


using namespace std;

struct workdate {
	int day;
	int month;
	int year;
};

struct worker{
	char name[10];
	char surename[10];
	char post [10];
	workdate date;
};


void addWorker(worker *a, int& m, const int n)
{
	if (m < n)
	{
		worker newa;
		cout << "input name :";
		cin >> newa.name;
		cout << "input surneme :";
		cin >> newa.surename;
		cout << "input post :";
		cin >> newa.post;
		cout << "input date of input work :";
		cout << "day :";
		cin >> newa.date.day;
		cout << "month :";
		cin >> newa.date.month;
		cout << "year : ";
		cin >> newa.date.year;
		a[m] = newa;
		m++;
	}
	else
	{
		cout << "Размер превышен";
		system("pause");
		cout << endl;
	}
	
	
}





void printWorker(worker *a, int& m) {
	cout << setw(15) << left << setw(15) << "NAME" << setw(15) << "SURNAME" << setw(15) << "POST" << setw(15) << "DATE" << endl;
	for (int i = 0; i < m; i++)
	{
		cout << setw(15) << left << setw(15) << a[i].name << setw(15) << a[i].surename << setw(15) << a[i].post << a[i].date.day <<"."<< a[i].date.month <<"."<< a[i].date.year << endl;
	}
	system("pause");
}

void delWorker(worker* a, int& m) {
	char f[10];
	int q = 0;
	cout << "What you want to delete - name : ";
	cin >> f;

	for (int i = 0; i < m; i++)
	{
		if (strcmp(f, a[i].name) == 0)
		{
			q = i;
			for (int i = q; i < m - 1; i++)
			{
				a[i] = a[i + 1];

			}
			m--;
			i--;
			
		}

	}
	

}


// ------------------------------------------------------------------MUSUKOV

// GUBIROV ---------------------------------
void loaddata_bin(worker* arr, int& size)
{
	FILE* f;
	const char* filename = "firstfile.txt";
	struct _finddata_t fileinfo;
	intptr_t done = _findfirst(filename, &fileinfo);
	if (done == -1)
	{
		fopen_s(&f, filename, "wb");
		fclose(f);
	}
	fopen_s(&f, filename, "rb");
	while (!feof(f))
	{
		fread(&arr[size], sizeof(worker), 1, f);
		size++;
	}
	fclose(f);
	size--;
} //---------------------------------------------------
// -------------------------------------
void savedata_bin(worker* arr, int& size)
{
	FILE* f;
	const char* filename = "firstfile.txt";
	fopen_s(&f, filename, "wb");
	fwrite(&arr[0], sizeof(worker), size, f);
	fclose(f);
} //------------------------------------------------------GUBIROV


// SOKUROVA---------------------------------
void search1(worker *a, int& m) {
	cout << "Поиск по имени" << endl;
	char name[10];
	cin >> name;
	cout << setw(15) << left << setw(15) << "NAME" << setw(15) << "SURNAME" << setw(15) << "POST" << setw(15) << "DATE" << endl;
	for (int i = 0;i < m;i++) {
		if (strcmp(name, a[i].name) == 0)
			cout << setw(15) << left << setw(15) << a[i].name << setw(15) << a[i].surename << setw(15) << a[i].post << a[i].date.day << "." << a[i].date.month << "." << a[i].date.year << endl;
	}
	system("pause");
}
void search2(worker*a, int& m) {
	cout << "Поиск по Фамилий" << endl;
	char famely[10];
	cin >> famely;
	cout << setw(15) << left << setw(15) << "NAME" << setw(15) << "SURNAME" << setw(15) << "POST" << setw(15) << "DATE" << endl;
	for (int i = 0;i < m;i++) {
		if (strcmp(famely, a[i].surename) == 0)
			cout << setw(15) << left << setw(15) << a[i].name << setw(15) << a[i].surename << setw(15) << a[i].post << a[i].date.day << "." << a[i].date.month << "." << a[i].date.year << endl;
	}
	system("pause");
}
void search3(worker*a, int& m) {
	cout << "Поиск по Должности" << endl;
	char post[10];
	cin >> post;
	cout << setw(15) << left << setw(15) << "NAME" << setw(15) << "SURNAME" << setw(15) << "POST" << setw(15) << "DATE" << endl;
	for (int i = 0;i < m;i++) {
		if (strcmp(post, a[i].post) == 0)
			cout << setw(15) << left << setw(15) << a[i].name << setw(15) << a[i].surename << setw(15) << a[i].post << a[i].date.day << "." << a[i].date.month << "." << a[i].date.year << endl;
	}
	system("pause");
}

void sortWorker(worker* a, int& m) {
	


		for (int i = 0; i < m - 1; i++)
		{
			for (int j = i + 1; j < m; j++)
			{
				if (a[i].date.year > a[j].date.year)
				{
					int tmp = a[i].date.year;
					a[i].date.year = a[j].date.year;
					a[j].date.year = tmp;
				}
			}

		}
}

// SOKUROVA-----------------------------
 
 

// MUSUKOV ----------------------
int main()
{
	setlocale(LC_ALL, "rus");
	bool exit = true;
	const int n = 3;
	int m = 0;
	worker a[n];
	int x;
	
	do
	{
		cout << "1 - print" << endl;
		cout << "2 - add" << endl;
		cout << "3 - delete position" << endl;
		cout << "4 - write to file" << endl;
		cout << "5 - read to file" << endl;
		cout << "6 - find by nname" << endl;
		cout << "7 - find by fname" << endl;
		cout << "8 - find by date" << endl;
		cout << "9 - sort by year" << endl;
		
		cout << "0 - quit" << endl;

		cout << "     chooose position : ";

		while (!isdigit(char(cin.peek())))                      //  проверка. когда вместо int вводишь что то другоу, игнорирует ввод
		{
			system("cls");
			cin.ignore();       //-----------------------------------------------------

			cout << "1 - print" << endl;
			cout << "2 - add" << endl;
			cout << "3 - delete position" << endl;
			cout << "4 - write to file" << endl;
			cout << "5 - read to file" << endl;
			cout << "6 - find by nname" << endl;
			cout << "7 - find by fname" << endl;
			cout << "8 - find by post" << endl;
			cout << "9 - sort by year" << endl;
			cout << "0 - quit" << endl;

			cout << "     chooose position : ";

		}

		cin >> x;

		switch (x)
		{
		case 0://0
			cout << "do you shure that you exit, exit = 0, moving = 1 : ";
			cin >> exit;
			break;
		case 1://1
			printWorker(a, m);
			break;
		case 2://2
			addWorker(a, m, n);
			break;
		case 3://2
			delWorker(a, m);
			break;
		case 4://2
			savedata_bin(a, m);
			break;
		case 5://2
			loaddata_bin(a, m);
			break;
		case 6://2
			search1(a, m);
			break;
		case 7://2
			search2(a, m);
			break;
		case 8://2
			search3(a, m);
			break;
		case 9://2
			sortWorker(a, m);
			break;
		

		}
	} while (exit != 0);
	return 0;
}
// MUSUKOV ------------------------
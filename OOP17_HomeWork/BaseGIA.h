#pragma once
#include <iostream>

using namespace std;

class CarOffenses {
	bool first = true; // There is any offens (true - no, false - yes)
	// Struct one offense
	struct Offense {
		char* title;
		char* describe;
	};
	Offense* offenses; // Array all offenses
	int lenght = 0;
public:
	// Constructor
	CarOffenses(){
		offenses = new Offense[lenght+1];
	}
	
	// Add new Offense
	void addOf(char* t, char* d) {
		first = false;
		offenses[lenght].title = new char[41];
		offenses[lenght].describe = new char[126];
		strcpy_s(offenses[lenght].title, strlen(t) + 1, t);
		strcpy_s(offenses[lenght].describe, strlen(d) + 1, d);
		lenght++;
	}

	// Remove offense  on index (if delete offense, other offenses shift)
	void removeOf(int index) {
		if (lenght > 0) {
			for (int i = 0; i < lenght; i++) {
				if (i == index) {
					//sh
					for (int j = i; j < lenght-1; j++) {
						offenses[j] = offenses[j + 1];
					}
					lenght--;
					break;
				}
			}
		}

	}

	// Print oll offense
	void showOfs() {
		if (!first) {
			for (int i = 0; i < lenght; i++) {
				cout << "---------------\n";
				cout << "Offence's name - " << offenses[i].title << endl;
				cout << "Offence's describe - " << offenses[i].describe << endl;
				cout << "---------------\n";
			}
		}
		else
			cout << "There isn't any offense\n";
	}
};

class Car {
	char CarNumber[6]; // Number car
	CarOffenses CarOf; // It offense
public:
	// Constructor
	Car(const char* number) {
		strcpy_s(CarNumber, 7, number);
	};

	// Add new offense
	void add(char* t, char* d) {
		CarOf.addOf(t, d);
	}

	// Remove offense on index
	void remove(int i) {
		CarOf.removeOf(i);
	}

	// Print all offenses
	void show() {
		cout << "|||Car number - " << CarNumber << endl;
		cout << "Offenses:\n";
		CarOf.showOfs();
	}

	// Return car's number
	char* getNumber() {
		return CarNumber;
	}
};

class BaseOfCars {
	int lenght = 0;
	Car* Cars[250]; // Array cars
public:
	// Add new cars with a buffer
	void add_new_car(const char* n) {
		Car buff(n);
		Cars[lenght] = &buff;
		lenght++;
	}
	
	// Remove car on index(like in class CarOffenses)
	void remove_car(int index) {
		if (index < 250 && lenght > 0) {
			for (int i = 0; i < lenght; i++) {
				if (i == index) {
					for (int j = i; j < lenght - 1; j++) {
						Cars[j] = Cars[j + 1];
					}
					lenght--;
					break;
				}
			}
		}
	}

	// Remove car's offense on number and index
	void remove_car_offense(char* numbCar, int indexOf) {
		for (int i = 0; i < lenght; i++) {
			if (strcmp(Cars[i]->getNumber(), numbCar) == 0)
				Cars[i]->remove(indexOf);
		}
	}

	// Print all cars
	void show_all() {
		for (int i = 0; i < lenght; i++) {
			Cars[i]->show();
			cout << endl;
		}
	}

	// Print one car on it number
	void show_numb(char* numbCar) {
		for (int i = 0; i < lenght; i++) {
			if (strcmp(Cars[i]->getNumber(), numbCar) == 0)
				Cars[i]->show();
		}
	}

	// Print car in range (rangeF1 must be before ranfeF2)
	void show_numb_range(char* rangeF1, char* rangeF2) {
		// Look for indexes rangeF1 and rangeF2
		int index1 = -1, index2 = -1;
		for (int i = 0; i < lenght; i++) {
			if (strcmp(Cars[i]->getNumber(), rangeF1) == 0)
				index1 = i;
			if (strcmp(Cars[i]->getNumber(), rangeF2) == 0)
				index2 = i;
			if (index1 != -1 && index2 != -1)
				break;
		}

		// Print in range
		for (int i = index1; i <= index2; i++) {
			Cars[i]->show();
			cout << endl;
		}
	}
};












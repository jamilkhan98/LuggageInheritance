//Jamil Khan
//CECS 282 - 05
//Prog 6 - Inheritance/Virtual Functions
//Dec 11, 2018

#include <math.h>
#include <map>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef LUGGAGE_H
#define LUGGAGE_H
class Luggage {
protected:
	string type;
public:
	virtual double volume() = 0;
	void print() {
		cout << type << ": " << volume() << endl;
	}
};

class Box : public Luggage {
private:
	double w, h, l;
public:
	Box(int width, int height, int length) {
		type = "Box";
		w = width;
		h = height;
		l = length;
	}

	double volume() {
		return w * h * l;
	}
};

class Sphere : public Luggage {
private:
	double r;
public:
	Sphere(double radius) {
		type = "Sphere";
		r = radius;
	}

	double volume() {
		return ((4 / 3.0) * 3.14) * (pow(r, 3));
	}
};

class Cube : public Luggage {
private:
	double edge;
public:
	Cube(double width) {
		type = "Cube";
		edge = width;
	}
	double volume() {
		return pow(edge, 3.0);
	}
};

class Pyramid : public Luggage {
private:
	double b, h;
public:
	Pyramid(double base, double height) {
		type = "Pyramid";
		b = base;
		h = height;
	}
	double volume() {
		return (pow(b, 2) * (h / 3.0));
	}
};

class Cylinder : public Luggage {
private:
	double r, l;
public:
	Cylinder(double radius, double length) {
		type = "Cylinder";
		r = radius;
		l = length;
	}
	double volume() {
		return (3.14) * (pow(r, 2) * l);
	}
};

class Cone : public Luggage {
private:
	double r, h;
public:
	Cone(double radius, double height) {
		type = "Cone";
		r = radius;
		h = height;
	}
	double volume() {
		return (3.14) * (pow(r, 2)) * (h / 3.0);
	}
};

class Hemisphere : public Luggage {
private:
	double r;
public:
	Hemisphere(double radius) {
		type = "Hemisphere";
		r = radius;
	}
	double volume() {
		return (2 / 3.0) * (3.14) * (pow(r, 3));
	}
};

class Tri_Pyramid : public Luggage {
private:
	double A, h;
public:
	Tri_Pyramid(double base, double length, double height) {
		type = "Triangular Pyramid";
		A = base * length;
		h = height;
	}
	double volume() {
		return (1 / 3.0) * A * h;
	}
};
#endif

void displayLuggageTypes();
void displayLuggage();
void addLuggage();
void removeLuggage();
Luggage* createBox();
Luggage* createSphere();
Luggage* createCube();
Luggage* createPyramid();
Luggage* createCylinder();
Luggage* createCone();
Luggage* createHemisphere();
Luggage* createTriangularPyramid();
vector<Luggage*> storage;

int main() {
	int selection;
	bool going = true;
	while (going) {
		cout << "1) Add luggage to storage container" << endl;
		cout << "2) Remove luggage from storage container" << endl;
		cout << "3) Show all luggage" << endl;
		cout << "4) Quit" << endl;

		cin >> selection;

		switch (selection) {
		case 1:
			//show user the available luggage types
			displayLuggageTypes();
			//allow user to choose one and ask for parameters
			//add luggage to storage container
			addLuggage();
			break;
		case 2:
			//show user all luggage in storage container
			displayLuggage();
			//ask user which one they want to remove
			//remove luggage
			removeLuggage();
			break;
		case 3:
			//show all luggage
			//Format:
			//		Luggage type: Volume:
			displayLuggage();
			break;
		case 4:
			going = false;
			break;
		default:
			cout << "Invalid input" << endl;
			break;
		}
		getchar();
	}
}

void displayLuggage() {
	double total_volume = 0;
	double count = 0;
	if (storage.size() > 0) {
		vector<Luggage*>::iterator it;
		for (it = storage.begin(); it != storage.end(); it++) {
			if (*it != 0) {
				cout << count + 1 << ". ";
				(*it)->print();
				total_volume += (*it)->volume();
				count++;
			}
		}
		cout << "Total Volume: " << total_volume << endl;
	}
	else {
		cout << "No luggage stored in container." << endl;
	}
}

void displayLuggageTypes() {
	string containers[8] = { "Box", "Sphere", "Cube", "Pyramid", "Cylinder", "Cone",
		"Hemisphere", "Triangular Pyramid" };
	for (int i = 0; i < 8; i++) {
		cout << i + 1 << "." << containers[i] << endl;
	}
}


void addLuggage() {
	int selection;
	Luggage* container;
	cout << "Choose luggage to create." << endl;

	cin >> selection;

	switch (selection) {
	case 1:
		container = createBox();
		break;
	case 2:
		container = createSphere();
		break;
	case 3:
		container = createCube();
		break;
	case 4:
		container = createPyramid();
		break;
	case 5:
		container = createCylinder();
		break;
	case 6:
		container = createCone();
		break;
	case 7:
		container = createHemisphere();
		break;
	case 8:
		container = createTriangularPyramid();
		break;
	}
	storage.push_back(container);
}

void removeLuggage() {
	int selection;
	if (storage.size() > 0) {
		cout << "Choose luggage to remove by number: " << endl;
		cin >> selection;
		while (selection < 1 || selection > storage.size()) {
			cout << "Invalid selection. Must enter # between 1 and " << storage.size() << endl;
			cin >> selection;
		}
		storage.erase(storage.begin() + (selection - 1));

	}
}

Luggage* createBox() {
	int w, h, l;
	cout << "Enter width, height, and length dimensions of box: " << endl;
	cout << "Width: "; cin >> w; cout << "Height: "; cin >> h; cout << "Length: "; cin >> l;
	Luggage* B = new Box(w, h, l);
	return B;
}

Luggage* createSphere() {
	int r;
	cout << "Enter radius of sphere: " << endl;
	cin >> r;
	Luggage* S = new Sphere(r);
	return S;
}

Luggage* createCube() {
	int e;
	cout << "Enter length of edge of cube: " << endl;
	cin >> e;
	Luggage* C = new Cube(e);
	return C;
}

Luggage* createPyramid() {
	int b, h;
	cout << "Enter base and height dimensions of pyramid: " << endl;
	cout << "Base: "; cin >> b; cout << "Height: "; cin >> h;
	Luggage* P = new Pyramid(b, h);
	return P;
}

Luggage* createCylinder() {
	int r, l;
	cout << "Enter radius and length of cylinder: " << endl;
	cout << "Radius: "; cin >> r; cout << "Length: "; cin >> l;
	Luggage* C = new Cylinder(r, l);
	return C;
}

Luggage* createCone() {
	int r, h;
	cout << "Enter radius and height of cone: " << endl;
	cout << "Radius: "; cin >> r; cout << "Height: "; cin >> h;
	Luggage* C = new Cone(r, h);
	return C;
}

Luggage* createHemisphere() {
	int r;
	cout << "Enter radius of hemisphere: " << endl;
	cin >> r;
	Luggage* H = new Hemisphere(r);
	return H;
}

Luggage* createTriangularPyramid() {
	int b, l, h;
	cout << "Enter base and length of triangle, and height of triangular pyramid: " << endl;
	cout << "Base: "; cin >> b; cout << "Length: "; cin >> l; cout << "Height: "; cin >> h;
	Luggage* TP = new Tri_Pyramid(b, l, h);
	return TP;
}
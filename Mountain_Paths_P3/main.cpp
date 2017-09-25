//#include <iostream>
//#include <fstream>
//#include <cstdlib>
//#include <sstream>
//#include <string>
//
//
//int maxFound = 0;
//int height = 0;
//int width = 0;
//int maximum = 0;
//int z = 0;
//int size = 0;
//int i = 0;
//int row = 0;
//std::string filename = "";
//
//using namespace std;
//
//void greed(int index, int arr[], int height) {
//
//	for (int z = 0; z< height; z++) {
//		int up = index - height - 1;
//		int middle = index + 1;
//		int down = index + height + 1;
//
//
//		if (up < 0) {
//			if (arr[middle] <= arr[down]) {
//				arr[index] = 0;
//				index += 1;
//				cout << endl << " going mid , up is less than 0";
//			}
//			else {
//
//				arr[index] = 0;
//				index += (height + 1);
//				cout << endl << " going down ";
//			}
//		}
//
//		else if (down >= width*height) {
//			if (arr[middle] <= arr[up]) {
//				arr[index] = 0;
//				index += 1;
//				cout << endl << " going mid, down is greater than width* height ";
//			}
//			else {
//				arr[index] = 0;
//				index -= (height - 1);
//				cout << endl << " going up, down is greater than width*height";
//			}
//		}
//
//		else if (arr[up] <= arr[middle]) {
//			if (arr[up] <= arr[down]) {
//				arr[index] = 0;
//				index -= (height - 1);
//				cout << endl << " going up ";
//			}
//
//			else {
//				arr[index] = 0;
//				index += (height + 1);
//				cout << endl << " going down ";
//			}
//		}
//
//
//		else if (arr[middle] <= arr[down]) {
//			if (arr[middle] <= arr[up]) {
//				arr[index] = 0;
//				index += 1;
//				cout << endl << " going mid ";
//			}
//			else {
//				arr[index] = 0;
//				index -= (height - 1);
//				cout << endl << " going up ";
//			}
//		}
//
//		else if (arr[down] <= arr[up]) {
//			if (arr[down] <= arr[middle]) {
//				arr[index] = 0;
//				index += (height + 1);
//				cout << endl << " going down ";
//			}
//			else {
//				arr[index] = 0;
//				index += 1;
//				cout << endl << " going mid ";
//			}
//		}
//	}
//
//
//}
//void writeToFile(int h, int w, int arr[]) {
//	std::filebuf res;
//	res.open("out.ppm", std::ios::out);
//	std::ostream output(&res);
//	output << "P2\n" << h << " " << w << "\n" << maximum << "\n";
//	for (int i = 0; i<((h*w)); i++) {
//		if (i%h == 0 && i != 0) {
//			output << "\n" << arr[i] << " ";
//		}
//		else {
//			output << arr[i] << " ";
//
//		}
//
//	}
//	res.close();
//}
//
//
//int main()
//{
//	stringstream k;
//	string line;
//	int value = 0;
//	std::string::size_type sz;
//
//
//	cout << "Which index do u want to start from" << endl;
//	cin >> row;
//	cout << "Enter the name of the file";
//	cin >> filename;
//	filename += ".dat";
//	//std::string totalpath = "H:\\Documents\\Visual Studio 2015\\Projects\\Assignment2-3116\\";
//	std::fstream myFile(("H:\\Documents\\Visual Studio 2015\\Projects\\Assignment2-3116\\" + filename).c_str(), std::ios_base::in);
//
//
//
//	myFile >> height;
//	myFile >> width;
//	int* arr;
//	//int arr[n1*10];
//	arr = new int[height*width];
//	while (myFile >> z) {
//		arr[i] = z;
//		//cout << arr[i];
//		if (arr[i] > maximum)
//		{
//			maximum = arr[i];
//			
//		}
//		i++;
//	}
//	myFile.close();
//	//convert row to specifici spot
//	row = ((row*width) - (width - 1)) - 1;
//	//cout << endl << "new row is " << row;
//	greed(row, arr, height);
//	writeToFile(height, width, arr);
//	system("PAUSE");
//	return 0;
//
//}



#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <string>


int maxFound = 0;
int height = 0;
int width = 0;
int maximum = 0;
int z = 0;
int size = 0;
int i = 0;
int row = 0;
std::string filename = "";

using namespace std;


void greed2(int index, int** hold, int height) {
	int inner = 0;
	int* upRow;
	int* midRow;
	int* downRow;
	while (inner < height) {
		//for (int j = 0; j < height; j++) {
			//Gives us the pointer to the row beginning
			//int* currentRow = hold[j];

			//for (int k = 0; k < width; k++) {
		cout << endl << " starting at index =  " << index << " inner = " << inner;
		upRow = &hold[index - 1][inner + 1];
		midRow = &hold[index][inner + 1];
		downRow = &hold[index + 1][inner + 1];
		cout << endl << "comparing  mid" << index << "," << inner + 1 << " to down" << index - 1 << "," << inner + 1;
		//If down can cause crash
		if (index + 1 >= height)
		{
			//compare mid and up
			if (*midRow <= *upRow) {
				hold[index][inner + 1] = 0;
				inner++;
				cout << endl << " going mid ";
			}
			else {
				hold[index - 1][inner + 1] = 0;
				index--;
				inner++;
				cout << endl << " going up ";
			}
		}
		//If up can cause crash
		else if (index - 1 < 0) {
			//compare mid and down
			if (*midRow <= *downRow) {
				hold[index][inner + 1] = 0;
				inner++;
				cout << endl << " going mid ";
			}
			else {
				hold[index + 1][inner + 1] = 0;
				index++;
				inner++;
				cout << endl << " going down ";
			}

		}


		else if (*upRow <= *midRow) {
			if (*upRow <= *downRow) {
				hold[index - 1][inner + 1] = 0;
				index--;
				inner++;
				cout << endl << " going up ";
			}

			else {
				hold[index + 1][inner + 1] = 0;
				index++;
				inner++;
				cout << endl << " going down ";
			}
		}

		else if (*midRow <= *downRow) {
			if (*midRow <= *upRow) {
				hold[index][inner + 1] = 0;
				inner++;
				cout << endl << " going mid ";
			}
			else {
				hold[index - 1][inner + 1] = 0;
				index--;
				inner++;
				cout << endl << " going up ";
			}
		}

		else if (*downRow <= *upRow) {
			if (*downRow <= *midRow) {
				hold[index + 1][inner + 1] = 0;
				index++;
				inner++;
				cout << endl << " going down ";
			}
			else {
				hold[index][inner + 1] = 0;
				inner++;
				cout << endl << " going mid ";
			}
		}
		
	}
		//}
	//}
	delete[] upRow, midRow, downRow;


}
void writeToFile(int h, int w, int** hold) {
	std::filebuf res;
	res.open("out.ppm", std::ios::out);
	std::ostream output(&res);
	output << "P2\n" << h << " " << w << "\n" << maximum << "\n";

	for (int outer = 0; outer < width; outer++) {
		for (int inner = 0; inner < height; inner++) {
			output << hold[outer][inner] << " ";
		}
		output << "\n" << " ";
	}
	/*for (int i = 0; i<((h*w)); i++) {
		if (i%h == 0 && i != 0) {
			output << "\n" << arr[i] << " ";
		}
		else {
			output << arr[i] << " ";

		}

	}*/
	res.close();
}


int main()
{
	stringstream k;
	string line;
	int value = 0;
	std::string::size_type sz;
	int numOfRowsToPathFind = 0;



	cout << "How many rows do u want to path find? " << endl;
	cin >> numOfRowsToPathFind;
	int* rows = new int[numOfRowsToPathFind];

	for(int c= 0; c < numOfRowsToPathFind; c++ ){
		cout << endl << "Enter the row to start from for row " << c <<endl;
		cin >> rows[c];
	}

	//cin >> row;
	cout << "Enter the name of the file"<<endl;
	cin >> filename;
	filename += ".dat";
	//std::string totalpath = "H:\\Documents\\Visual Studio 2015\\Projects\\Assignment2-3116\\";
	std::fstream myFile(("H:\\Documents\\Visual Studio 2015\\Projects\\Assignment2-3116\\" + filename).c_str(), std::ios_base::in);



	myFile >> height;
	myFile >> width;
	int* arr;
	//A pointer to hold the beginnings of each row
	int** holder = new int*[height];
	//A pointer to hold the values of each row
	int* rowBeginning = new int[width];
	for (int x = 0; x < height; x++) {
		holder[x] = rowBeginning;
	}
	int holderPos = 0;
	int positionOfRow = 0;

	//int arr[n1*10];
	arr = new int[height*width];
	while (myFile >> z) {
		arr[i] = z;
		//cout << arr[i];
		if (arr[i] > maximum)
		{
			maximum = arr[i];
		}

		//If the ith element is the beginning of a row
		if (i%width == 0) {
			//Update the holder position to point to the address of arr
			holder[positionOfRow] = &arr[i];
			//Increment the position of row
			positionOfRow++;
		}
		i++;
	}
	myFile.close();

	//for (int outer = 0; outer < width; outer++) {
	//	for (int inner = 0; inner < height; inner++) {
	//		//output << hold[outer][inner] << " ";
	//		cout << endl << holder[outer][inner];
	//	}
		//output << "\n" << " ";
	//}

	for (int z = 0; z < numOfRowsToPathFind; z++) {
		//cout << endl << " the row pointer for row " << z << " is " << holder[z] << " it's corresponding value is " << *holder[z] << " the value after this is " << holder[z][1];
		row = rows[z];
		//row = ((row*width) - (width - 1)) - 1;
		cout << endl << " the height is " << height;
		greed2(row, holder, height);

	}
	writeToFile(height, width, holder);
	delete[] arr,holder, rowBeginning;


	

	//convert row to specifici spot
	//row = ((row*width) - (width - 1)) - 1;
	//greed(row, arr, height);
	//writeToFile(height, width, arr);
	system("PAUSE");
	return 0;

}




#include <iostream>
#include <Windows.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	FILE* out;
	char arr[36];
	const char* T = "C:\\Users\\User\\Desktop\\T.txt";
	if (fopen_s(&out, T, "r") == NULL) {
		for (int i = 0; i < 35; i++) {
			arr[i] = fgetc(out);
		}
		arr[35] = '\0';
	}
	else {
		cout << "error";
	}
	int k = 0;
	FILE* in;
	const char* W = "C:\\Users\\User\\Desktop\\W.txt";
	fopen_s(&in, W, "w");
	for (int j = 0; j < 36; j++) {
		if (arr[j] != ',' && arr[j] != ' ' && arr[j] != '.') {
			k++;
		}
		else {
			if (k >= 7) {
				for (int i = j - k; i <= j; i++) {
					fputc(arr[i], in);
					cout << arr[i];
				}
			}
			k = 0;
		}
	}
	fclose(in);
	fclose(out);
	system("pause");
}
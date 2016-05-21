#include <iostream>
#include <math.h>
#include <string.h>
#include <time.h>

using namespace std;

int main() {
	int count;

	cout << "java RecordMarker ";
	cin >> count;
	int* arr = new int[count];

	srand((unsigned int)time(NULL));
	for (int i = 0; i < count; i++) {
		int check = 1;
		int random;
		// random 1 ~ 99999�� ������ ���ڰ� ����.
		random = rand() % 99999 + 1;
		for (int j = 0; j < i; j++) {
			// �ߺ��� ���� Ȯ��
			if (arr[j] == random) {
				i--;
				check = 0;
				break;
			}
		}
		if (check == 1) {
			// �ߺ��� ���ڰ� ������ ���
			arr[i] = random;
		}
	}

	char number[6];
	char zero[6];
	char result[8] = "NT";
	int digit_check;
	for (int i = 0; i < count; i++) {
		memset(&result, 0, sizeof(result));
		memset(&zero, 0, sizeof(zero));
		result[0] = 'N';
		result[1] = 'T';

		itoa(arr[i], number, 10);
		digit_check = strlen(number);	// �� �ڸ� �������� üũ
		
		for (int j = 0; j < 5 - digit_check; j++) {
			// �ڸ��� ����
			strcat(zero, "0");
		}

		strcat(zero, number);
		strcat(result, zero);

		// ��� �� ���
		cout << result << " " << rand() % 100 << endl;
	}
	
	delete [] arr;
}
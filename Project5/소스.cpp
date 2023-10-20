#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("mybin.dat", ios::binary | ios::out);
    if (!file) {
        cout << "������ �� �� �����ϴ�.";
        return 1;
    }

    // 1. int 1234 ����
    int num1 = 1234;
    file.write(reinterpret_cast<const char*>(&num1), sizeof(int));

    // 2. 1000���� 5000���� ���ڿ� 5�� ���Ͽ� ����
    for (int i = 1000; i <= 5000; i += 5) {
        int result = i * 5;
        file.write(reinterpret_cast<const char*>(&result), sizeof(int));
    }

    // 3. float -0.5���� 0.5�� �����ϸ鼭 �ڽ��� �ϰ� ����
    float num2 = -0.5;
    for (int i = 0; i < 3; i++) {
        float result = num2 * num2;
        file.write(reinterpret_cast<const char*>(&result), sizeof(float));
        num2 += 0.5;
    }

    file.close();
    return 0;
}

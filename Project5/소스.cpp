#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("mybin.dat", ios::binary | ios::out);
    if (!file) {
        cout << "파일을 열 수 없습니다.";
        return 1;
    }

    // 1. int 1234 저장
    int num1 = 1234;
    file.write(reinterpret_cast<const char*>(&num1), sizeof(int));

    // 2. 1000부터 5000까지 숫자에 5를 곱하여 저장
    for (int i = 1000; i <= 5000; i += 5) {
        int result = i * 5;
        file.write(reinterpret_cast<const char*>(&result), sizeof(int));
    }

    // 3. float -0.5에서 0.5씩 증가하면서 자승을 하고 저장
    float num2 = -0.5;
    for (int i = 0; i < 3; i++) {
        float result = num2 * num2;
        file.write(reinterpret_cast<const char*>(&result), sizeof(float));
        num2 += 0.5;
    }

    file.close();
    return 0;
}

#include <iostream>
#include <cmath>

using namespace std;

void print_piramida(int SizeArray, int Array[]) {
    cout << "Исходный массив: ";
    for (int i = 0; i < SizeArray; i++) {
        cout << Array[i] << " ";
    }
    cout << endl;

    for (int index = 0; index < SizeArray; index++) {
        int level = static_cast<int>(log2(index + 1));
        int parent_index = (index - 1) / 2;
        string type;

        if (index == 0) {
            type = "root";
        } else if (index == 2 * parent_index + 1) {
            type = "left";
        } else {
            type = "right";
        }

        if (type == "root") {
            cout << level << " " << type << " " << Array[index] << endl;
        } else {
            int parent_value = Array[parent_index];
            cout << level << " " << type << "(" << parent_value << ") " << Array[index] << endl;
        }
    }

   
    int CurrentIndex = 0;
    string Move;

    cout << "Вы находитесь здесь: 0 root " << Array[CurrentIndex] << endl;

    while (true) {
        cout << "Введите команду (up/left/right/exit): ";
        cin >> Move;

        if (Move == "exit") {
            break; 
        } else if (Move == "up") {
            if (CurrentIndex == 0) {
                cout << "Ошибка: Вы уже находитесь в корне." << endl;
            } else {
                CurrentIndex = (CurrentIndex - 1) / 2;
                int level = static_cast<int>(log2(CurrentIndex + 1));
                cout << "Вы находитесь здесь: " << level << " ";
                if (CurrentIndex == 0) {
                    cout << "root " << Array[CurrentIndex] << endl;
                } else {
                    int parent_index = (CurrentIndex - 1) / 2;
                    cout << ((CurrentIndex % 2 == 1) ? "left" : "right")
                         << "(" << Array[parent_index] << ") " << Array[CurrentIndex] << endl;
                }
            }
        } else if (Move == "left") {
            int left_child_index = 2 * CurrentIndex + 1;
            if (left_child_index >= SizeArray) {
                cout << "Ошибка: Отсутствует левый потомок." << endl;
            } else {
                CurrentIndex = left_child_index;
                int level = static_cast<int>(log2(CurrentIndex + 1));
                cout << "Вы находитесь здесь: " << level << " left("
                     << Array[(CurrentIndex - 1) / 2] << ") " << Array[CurrentIndex] << endl;
            }
        } else if (Move == "right") {
            int right_child_index = 2 * CurrentIndex + 2;
            if (right_child_index >= SizeArray) {
                cout << "Ошибка: Отсутствует правый потомок." << endl;
            } else {
                CurrentIndex = right_child_index;
                int level = static_cast<int>(log2(CurrentIndex + 1));
                cout << "Вы находитесь здесь: " << level << " right("
                     << Array[(CurrentIndex - 1) / 2] << ") " << Array[CurrentIndex] << endl;
            }
        } else {
            cout << "Ошибка: Неизвестная команда." << endl;
        }
    }
}

int main() {
    int SizeArray = 10;
    int array[SizeArray] = {55, 3, 10, 100, 234, 47, 33, 8, 26, 22};
    print_piramida(SizeArray, array);
    return 0;
}
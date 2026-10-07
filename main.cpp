#include <clocale>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

int ReadInt(const std::string& prompt) {
  while (true) {
    std::cout << prompt;
    int value;
    if (std::cin >> value) {
      std::string remainder;
      std::getline(std::cin, remainder);
      if (remainder.find_first_not_of(" \t\r") == std::string::npos) {
        return value;
      }
      std::cout << "Ошибка: введите только одно целое число.\n";
      continue;
    }
    if (std::cin.eof()) {
      std::exit(0);
    }

    std::cin.clear();
    std::string discarded;
    std::getline(std::cin, discarded);
    std::cout << "Ошибка: введите целое число в диапазоне типа int.\n";
  }
}

int ReadIntMin(const std::string& prompt, int min_value) {
  int value = ReadInt(prompt);
  while (value < min_value) {
    std::cout << "Ошибка: число должно быть не меньше "
              << min_value << ".\n";
    value = ReadInt(prompt);
  }
  return value;
}

int ReadIntRange(const std::string& prompt, int min_value, int max_value) {
  int value = ReadInt(prompt);
  while (value < min_value || value > max_value) {
    std::cout << "Ошибка: число должно быть в диапазоне от " << min_value
              << " до " << max_value << ".\n";
    value = ReadInt(prompt);
  }
  return value;
}

char ReadChar(const std::string& prompt) {
  while (true) {
    std::cout << prompt;
    std::string line;
    if (!std::getline(std::cin, line)) std::exit(0);
    if (line.size() == 1) {
      return line[0];
    }
    std::cout << "Ошибка: введите ровно один " << "символ.\n";
  }
}

int* ReadArray(const std::string& name) {
  int size = ReadIntMin(
      "Сколько элементов в массиве " + name + "? ", 1);
  int* arr = new int[size + 1];
  arr[0] = size;
  for (int i = 1; i <= size; ++i) {
    arr[i] = ReadInt("Массив " + name + ", элемент " +
                     std::to_string(i) + ": ");
  }
  return arr;
}

void PrintArray(int arr[]) {
  if (arr[0] == 0) {
    std::cout << "пустой массив\n";
    return;
  }
  for (int i = 1; i <= arr[0]; ++i) {
    if (i > 1) {
      std::cout << ", ";
    }
    std::cout << arr[i];
  }
  std::cout << "\n";
}

// Задание 1. Методы

int sumLastNums(int x) {
  const int last_digit = x % 10;
  const int second_last_digit = (x / 10) % 10;
  return (last_digit < 0 ? -last_digit : last_digit) +
         (second_last_digit < 0 ? -second_last_digit : second_last_digit);
}

bool isPositive(int x) {
  return x > 0;
}

bool isUpperCase(char x) {
  return x >= 'A' && x <= 'Z';
}

bool isDivisor(int a, int b) {
  if (a == -1 || b == -1) {
    return true;
  }
  return (a != 0 && b % a == 0) || (b != 0 && a % b == 0);
}

int lastNumSum(int a, int b) {
  const int last_a = a % 10;
  const int last_b = b % 10;
  return (last_a < 0 ? -last_a : last_a) +
         (last_b < 0 ? -last_b : last_b);
}

// Задание 2. Условия

double safeDiv(int x, int y) {
  if (y == 0) {
    return 0;
  }
  return static_cast<double>(x) / y;
}

std::string makeDecision(int x, int y) {
  std::string sign = "==";
  if (x < y) {
    sign = "<";
  } else if (x > y) {
    sign = ">";
  }
  return std::to_string(x) + " " + sign + " " + std::to_string(y);
}

bool sum3(int x, int y, int z) {
  return static_cast<double>(x) + y == z ||
         static_cast<double>(x) + z == y ||
         static_cast<double>(y) + z == x;
}

std::string age(int x) {
  int last = x % 10;
  int last_two = x % 100;
  std::string word = "лет";
  if (last == 1 && last_two != 11) {
    word = "год";
  } else if (last >= 2 && last <= 4 &&
             (last_two < 12 || last_two > 14)) {
    word = "года";
  }
  return std::to_string(x) + " " + word;
}

void printDays(int x) {
  switch (x) {
    case 1:
      std::cout << "понедельник\n";
      [[fallthrough]];
    case 2:
      std::cout << "вторник\n";
      [[fallthrough]];
    case 3:
      std::cout << "среда\n";
      [[fallthrough]];
    case 4:
      std::cout << "четверг\n";
      [[fallthrough]];
    case 5:
      std::cout << "пятница\n";
      [[fallthrough]];
    case 6:
      std::cout << "суббота\n";
      [[fallthrough]];
    case 7:
      std::cout << "воскресенье\n";
      break;
    default:
      std::cout << "это не день недели\n";
      break;
  }
}

// Задание 3. Циклы

std::string reverseListNums(int x) {
  std::string result;
  for (int i = x; i >= 0; --i) {
    result += std::to_string(i);
    if (i > 0) {
      result += " ";
    }
  }
  return result;
}

int pow(int x, int y) {
  if (x == 0 && y > 0) {
    return 0;
  }
  if (x == 1) {
    return 1;
  }
  if (x == -1) {
    return y % 2 == 0 ? 1 : -1;
  }
  int result = 1;
  for (int i = 0; i < y; ++i) {
    result *= x;
  }
  return result;
}

bool equalNum(int x) {
  int digit = x % 10;
  while (x != 0) {
    if (x % 10 != digit) {
      return false;
    }
    x /= 10;
  }
  return true;
}

void leftTriangle(int x) {
  for (int row = 1; row <= x; ++row) {
    for (int col = 0; col < row; ++col) {
      std::cout << '*';
    }
    std::cout << '\n';
  }
}

std::string AttemptsWord(int n) {
  int last = n % 10;
  int last_two = n % 100;
  if (last == 1 && last_two != 11) {
    return "попытку";
  }
  if (last >= 2 && last <= 4 && (last_two < 12 || last_two > 14)) {
    return "попытки";
  }
  return "попыток";
}

void guessGame() {
  int secret = std::rand() % 10;
  int attempts = 1;
  int guess = ReadIntRange("Введите число от 0 до 9:\n", 0, 9);
  while (guess != secret) {
    guess = ReadIntRange(
        "Вы не угадали, введите число от 0 до 9:\n", 0, 9);
    ++attempts;
  }
  std::cout << "Вы угадали!\n";
  std::cout << "Вы отгадали число за " << attempts << " "
            << AttemptsWord(attempts) << "\n";
}

// Задание 4. Массивы

int findLast(int arr[], int x) {
  for (int i = arr[0]; i >= 1; --i) {
    if (arr[i] == x) {
      return i - 1;
    }
  }
  return -1;
}

int* add(int arr[], int x, int pos) {
  int size = arr[0];
  int* result = new int[size + 2];
  result[0] = size + 1;
  for (int i = 0; i < pos; ++i) {
    result[i + 1] = arr[i + 1];
  }
  result[pos + 1] = x;
  for (int i = pos; i < size; ++i) {
    result[i + 2] = arr[i + 1];
  }
  return result;
}

void reverse(int arr[]) {
  int size = arr[0];
  for (int i = 0; i < size / 2; ++i) {
    int tmp = arr[1 + i];
    arr[1 + i] = arr[size - i];
    arr[size - i] = tmp;
  }
}

int* concat(int arr1[], int arr2[]) {
  int size1 = arr1[0];
  int size2 = arr2[0];
  int* result = new int[size1 + size2 + 1];
  result[0] = size1 + size2;
  for (int i = 1; i <= size1; ++i) {
    result[i] = arr1[i];
  }
  for (int i = 1; i <= size2; ++i) {
    result[size1 + i] = arr2[i];
  }
  return result;
}

int* deleteNegative(int arr[]) {
  int count = 0;
  for (int i = 1; i <= arr[0]; ++i) {
    if (arr[i] >= 0) {
      ++count;
    }
  }
  int* result = new int[count + 1];
  result[0] = count;
  int j = 1;
  for (int i = 1; i <= arr[0]; ++i) {
    if (arr[i] >= 0) {
      result[j] = arr[i];
      ++j;
    }
  }
  return result;
}

void ShowBool(bool result) {
  std::cout << "Результат: " << (result ? "true" : "false") << "\n";
}

bool PowOverflows(int x, int y) {
  if (x >= -1 && x <= 1) {
    return false;
  }
  double result = 1;
  for (int i = 0; i < y; ++i) {
    result *= x;
    if (result < -2147483648.0 || result > 2147483647.0) {
      return true;
    }
  }
  return false;
}

// Интерфейс

void Info(const std::string& text) {
  std::cout << "\nЧто делает задача: " << text << "\n\n";
}

void RunTask1(int task) {
  if (task == 1) {
    Info("Складывает две последние цифры числа.");
    int x = ReadInt("Введите число (минимум две цифры): ");
    while (x > -10 && x < 10) {
      std::cout << "В числе должно быть не менее двух цифр.\n";
      x = ReadInt("Введите число еще раз: ");
    }
    std::cout << "Результат: " << sumLastNums(x) << "\n";
  } else if (task == 2) {
    Info("Проверяет, больше ли число нуля.");
    int x = ReadInt("Введите число: ");
    ShowBool(isPositive(x));
  } else if (task == 3) {
    Info("Проверяет, является ли символ заглавной "
         "латинской буквой.");
    char x = ReadChar("Введите один символ: ");
    ShowBool(isUpperCase(x));
  } else if (task == 4) {
    Info("Проверяет делимость чисел друг на друга.");
    int a = ReadInt("Введите a: ");
    int b = ReadInt("Введите b: ");
    ShowBool(isDivisor(a, b));
  } else {
    Info("Последовательно складывает цифры единиц пяти чисел.");
    int result = ReadInt("Число 1: ");
    for (int i = 2; i <= 5; ++i) {
      int next = ReadInt("Число " + std::to_string(i) + ": ");
      std::cout << result << "+" << next << " это ";
      result = lastNumSum(result, next);
      std::cout << result << "\n";
    }
    std::cout << "Итого " << result << "\n";
  }
}

void RunTask2(int task) {
  if (task == 1) {
    Info("Делит x на y; при y = 0 возвращает 0.");
    int x = ReadInt("Введите x: ");
    int y = ReadInt("Введите y: ");
    if (y == 0) {
      std::cout << "На ноль делить нельзя, поэтому результат 0.\n";
    }
    std::cout << "Результат: " << safeDiv(x, y) << "\n";
  } else if (task == 2) {
    Info("Возвращает строку сравнения двух чисел.");
    int x = ReadInt("Введите x: ");
    int y = ReadInt("Введите y: ");
    std::cout << "Результат: \"" << makeDecision(x, y) << "\"\n";
  } else if (task == 3) {
    Info("Проверяет, дает ли сумма двух чисел третье число.");
    int x = ReadInt("Введите x: ");
    int y = ReadInt("Введите y: ");
    int z = ReadInt("Введите z: ");
    ShowBool(sum3(x, y, z));
  } else if (task == 4) {
    Info("Добавляет к числу правильное слово: год, года или лет.");
    int x = ReadIntMin("Введите возраст: ", 0);
    std::cout << "Результат: \"" << age(x) << "\"\n";
  } else {
    Info("Выводит указанный день недели и последующие до воскресенья.");
    int x = ReadInt("Введите номер дня: ");
    printDays(x);
  }
}

void RunTask3(int task) {
  if (task == 1) {
    Info("Выводит числа от x до 0 через пробел.");
    int x = ReadIntMin("Введите x (не меньше 0): ", 0);
    std::cout << "Результат: \"" << reverseListNums(x) << "\"\n";
  } else if (task == 2) {
    Info("Возводит число x в степень y с помощью цикла.");
    int x = ReadInt("Введите основание x: ");
    int y = ReadIntMin("Введите степень y (не меньше 0): ", 0);
    if (PowOverflows(x, y)) {
      std::cout << "Результат не помещается в тип int. "
                   "Допустимый диапазон: от -2147483648 "
                   "до 2147483647.\n";
    } else {
      std::cout << "Результат: " << pow(x, y) << "\n";
    }
  } else if (task == 3) {
    Info("Проверяет, одинаковы ли все цифры числа.");
    int x = ReadInt("Введите число: ");
    ShowBool(equalNum(x));
  } else if (task == 4) {
    Info("Рисует левый треугольник из звездочек заданной высоты.");
    int x = ReadIntMin("Введите высоту (не меньше 1): ", 1);
    leftTriangle(x);
  } else {
    Info("Предлагает угадать число от 0 до 9 и считает попытки.");
    guessGame();
  }
}

void RunTask4(int task) {
  if (task == 1) {
    Info("Ищет последнее вхождение числа в массиве.");
    int* arr = ReadArray("arr");
    int x = ReadInt("Введите x: ");
    int index = findLast(arr, x);
    if (index == -1) {
      std::cout << "Результат: числа " << x << " в массиве нет.\n";
    } else {
      std::cout << "Индекс последнего вхождения: " << index << ".\n";
    }
    delete[] arr;
  } else if (task == 2) {
    Info("Вставляет число в массив на указанную позицию.");
    int* arr = ReadArray("arr");
    int size = arr[0];
    int x = ReadInt("Введите x: ");
    int place = ReadIntMin(
        "На какое место вставить число (от 1 до " +
            std::to_string(size + 1) + "): ",
        1);
    while (place > size + 1) {
      std::cout << "Место не может быть больше " << size + 1 << ".\n";
      place = ReadIntMin("На какое место вставить число: ", 1);
    }
    int* result = add(arr, x, place - 1);
    std::cout << "Результат: ";
    PrintArray(result);
    delete[] result;
    delete[] arr;
  } else if (task == 3) {
    Info("Переворачивает массив задом наперед.");
    int* arr = ReadArray("arr");
    reverse(arr);
    std::cout << "Результат: ";
    PrintArray(arr);
    delete[] arr;
  } else if (task == 4) {
    Info("Объединяет два массива в исходном порядке.");
    int* arr1 = ReadArray("arr1");
    int* arr2 = ReadArray("arr2");
    int* result = concat(arr1, arr2);
    std::cout << "Результат: ";
    PrintArray(result);
    delete[] result;
    delete[] arr1;
    delete[] arr2;
  } else {
    Info("Создает новый массив без отрицательных чисел.");
    int* arr = ReadArray("arr");
    int* result = deleteNegative(arr);
    std::cout << "Результат: ";
    PrintArray(result);
    delete[] result;
    delete[] arr;
  }
}

void RunSet(int set) {
  while (true) {
    std::cout << "\nЗадание " << set << "\n";
    if (set == 1) {
      std::cout << "1. Сумма знаков\n2. Есть ли позитив\n3. Большая буква\n"
                   "4. Делитель\n"
                   "5. Многократный вызов\n";
    } else if (set == 2) {
      std::cout << "1. Безопасное деление\n2. Строка сравнения\n"
                   "3. Тройная сумма\n4. Возраст\n"
                   "5. Вывод дней недели\n";
    } else if (set == 3) {
      std::cout << "1. Числа наоборот\n2. Степень числа\n"
                   "3. Одинаковость\n4. Левый треугольник\n"
                   "5. Угадайка\n";
    } else {
      std::cout << "1. Поиск последнего значения\n2. Добавление в массив\n"
                   "3. Реверс\n4. Объединение\n"
                   "5. Удалить негатив\n";
    }
    std::cout << "0. Назад\n";
    int task = ReadInt("Выберите задачу (0-5): ");
    if (task == 0) {
      return;
    }
    if (task < 1 || task > 5) {
      std::cout << "Такой задачи нет. Выберите от 0 до 5.\n";
      continue;
    }
    if (set == 1) {
      RunTask1(task);
    } else if (set == 2) {
      RunTask2(task);
    } else if (set == 3) {
      RunTask3(task);
    } else {
      RunTask4(task);
    }
  }
}

int main() {
  std::setlocale(LC_ALL, "Russian");
  std::srand(static_cast<unsigned int>(std::time(nullptr)));
  while (true) {
    std::cout << "\nЛабораторная работа №1\n"
                 "1. Задание 1. Методы\n"
                 "2. Задание 2. Условия\n"
                 "3. Задание 3. Циклы\n"
                 "4. Задание 4. Массивы\n"
                 "0. Выход\n";
    int set = ReadInt("Выберите задание (0-4): ");
    if (set == 0) {
      std::cout << "До свидания!\n";
      return 0;
    }
    if (set < 1 || set > 4) {
      std::cout << "Такого задания нет, выберите от 0 до 4.\n";
      continue;
    }
    RunSet(set);
  }
}

# Горбунова Софья ДВБ7-ЛА2-2025 НБ Лабораторная №1

# Задание 1

## Задача 2

### Сумма знаков.

Дана сигнатура функции: int sumLastNums (int x);
Необходимо реализовать функцию таким образом, чтобы она возвращала
результат сложения двух последних знаков числах, предполагая, что знаков в
числе не менее двух. 
Подсказки:
int x=123%10; // х будет иметь значение 3
int у=123/10; // у будет иметь значение 12
Пример:
x=4568
результат: 14

### Алгоритм решения

1. Получить последнюю цифру через x % 10.
2. Получить предпоследнюю цифру через (x / 10) % 10.
3. Сложить полученные цифры и вернуть результат.

### Тестирование

<img width="382" height="54" alt="image" src="https://github.com/user-attachments/assets/03b6cd5e-71ee-4060-b94e-9b63b67b72d3" />
<img width="385" height="74" alt="image" src="https://github.com/user-attachments/assets/ccbe98fe-cdaa-43ef-8197-9a75f0a116a9" />


## Задача 4

### Есть ли позитив.

Дана сигнатура функции: bool isPositive (intx);
Необходимо реализовать функцию таким образом, чтобы она принимала число
x и возвращала true, если оно положительное.
Пример 1:
x=3
результат: true
Пример 2:
x=-5
результат: false

### Алгоритм решения

Проверить условие: x > 0.

### Тестирование

<img width="215" height="48" alt="image" src="https://github.com/user-attachments/assets/62016be3-7298-44e0-a884-294df6d0ce58" />
<img width="216" height="50" alt="image" src="https://github.com/user-attachments/assets/ad3f55cf-2f59-423f-b679-fa8aa8423423" />
<img width="472" height="69" alt="image" src="https://github.com/user-attachments/assets/91405735-29e9-4b0a-86f1-841fe6a0eb45" />


## Задача 6

### Большая буква. 

Дана сигнатура функции: bool isUpperCase (char x);
Необходимо реализовать функцию таким образом, чтобы она принимала
символ x и возвращала true, если это большая буква в диапазоне от ‘A’ до ‘Z’.
Пример 1:
x=’D’
результат: true
Пример 2:
x=’q’
результат: false

### Алгоритм решения

Проверить, что x >= 'A' && x <= 'Z'.

### Тестирование

<img width="235" height="55" alt="image" src="https://github.com/user-attachments/assets/a25ee550-0c99-4742-9435-93a273d1c297" />
<img width="233" height="52" alt="image" src="https://github.com/user-attachments/assets/87a80084-d9b3-4f19-98cc-6a2fc7bbd90a" />
<img width="234" height="46" alt="image" src="https://github.com/user-attachments/assets/97d19be1-36cb-4907-a01e-8101d223c237" />


## Задача 8

### Делитель.

Дана сигнатура функции: bool isDivisor (int a, int b);
Необходимо реализовать функцию таким образом, чтобы она возвращала true,
если любое из принятых чисел делит другое нацело.
Пример 1:
a=3 b=6
результат: true
Пример 2:
a=2 b=15
результат: false

### Алгоритм решения

Проверить, что делитель не равен нулю, и затем одно из условий: a != 0 && b % a == 0, b != 0 && a % b == 0

### Тестирование

<img width="198" height="65" alt="image" src="https://github.com/user-attachments/assets/fe8c0b49-01e3-4fa8-badd-f34b0d37d7eb" />
<img width="209" height="76" alt="image" src="https://github.com/user-attachments/assets/7e9f651b-9a1e-431e-b45d-a928d4dc9ac2" />


## Задача 10

### Многократный вызов. 

Дана сигнатура функции: int lastNumSum(int a, int b)
Необходимо реализовать функцию таким образом, чтобы она считала сумму
цифр двух чисел из разряда единиц. Выполните с его помощью
последовательное сложение пяти чисел и результат выведите на экран.
Постарайтесь выполнить задачу, используя минимально возможное
количество вспомогательных переменных.
Пример:
5+11 это 6
6+123 это 9
9+14 это 13
13+1 это 4
Итого 4

### Алгоритм решения

1. Для каждого следующего числа взять цифру единиц.
2. Суммировать его с текущим результатом.
3. Повторять пять раз.

### Тестирование

<img width="175" height="224" alt="image" src="https://github.com/user-attachments/assets/a4bb12da-bbbf-45c0-b480-e7aa91ee07f2" />
<img width="459" height="273" alt="image" src="https://github.com/user-attachments/assets/a102cc46-f008-4bdd-96dc-296450f36b06" />


# Задание 2

## Задача 2

### Безопасное деление. 

Дана сигнатура функции: double safeDiv (int x, int y);
Необходимо реализовать функцию таким образом, чтобы она возвращала
деление x на y, и при этом гарантировала, что не будет выкинута ошибка
деления на 0. При делении на 0 следует вернуть из функции число 0. Подсказка:
смотри ограничения на операции типов данных.
Пример 1:
x=5 y=0
результат: 0
Пример 2:
x=8 y=2
результат: 4

### Алгоритм решения

Проверить:
- если y == 0, вернуть 0;
- иначе вернуть (double)x / y.

### Тестирование

<img width="416" height="94" alt="image" src="https://github.com/user-attachments/assets/c4eeefc9-a6da-4884-9251-a7e25b8d5e46" />
<img width="190" height="71" alt="image" src="https://github.com/user-attachments/assets/c286e712-47f1-4798-b2e5-71bdb91f1793" />
<img width="169" height="72" alt="image" src="https://github.com/user-attachments/assets/bf598ef2-9073-49d4-8c62-fc52ce50a6da" />



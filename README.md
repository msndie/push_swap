# push_swap
Проект выполнен в строгом соответствии с внутренними правилами Школы 21 и сабджектом.
Суть проекта заключается в сортировке стека по определенным правилам:
- Есть 2 стека a и b.
Стек а содержит случайное число положительных и/или отрицательных чисел, повторения запрещены. Стек b пуст.
Задача отсортировать числа в стеке а по возрастанию. Чтобы это сделать нам доступны следующие операции:
- sa (swap a): поменять местами 2 верхних элемента стека а.
-sb (swap b): поменять местами 2 верхних элемента стека b.
- ss (sa and sb at the same time) 
- pa (push a): переместить первый элемент стека b на верх стека а
- pb (push b): переместить первый элемент стека а на верх стека b
- ra (rotate a): Сместить все элементы стека а на 1 позицию вверх
- rb (rotate b): Сместить все элементы стека b на 1 позицию вверх
- rr: (rotate a and b at the same time)
- rra (reverse rotate a):  Сместить все элементы стека а на 1 позицию вниз
- rrb (reverse rotate b): Сместить все элементы стека b на 1 позицию вниз
- rrr (reverse rotate a and b at the same time)

Пример использования:
```
$>./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
```
```
$>./push_swap 0 one 2 3
Error
$>
```

В репозитории находится 2 чекера, для Linux и для Mac. Они используются следующим образом:
```
$>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6
```
```
$>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
OK
$>
```

При вызове make также скомпилируется чекер написанный мной, его можно использовать точно также как показано выше.

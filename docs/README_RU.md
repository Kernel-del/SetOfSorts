<div style="width: 100%; overflow-x: auto;">
  <pre style="font-family: monospace; font-size: 2vw; line-height: 1.14; white-space: pre;">
 ███              ███        ███  ████████████████████████
█░░░█            █░░░█   █  █░░░█ ░░░░░░░░░░░░░██░░░░░░░░
█░░░░  ██   █    █░░░█  █░█ █░░░░ ░███░░░█░██░░██░░███░░░
▒███░ █░░█ ████  █░░░█  █░░ ░███░ █▒▒▒█░░██▒▒█░██░█▒▒▒░░
▒▒▒▒█ ████ ░█░░  █░░░█  █░░ ░▒▒▒█ █▒▒▒█░░█▒▒▒▒░██░▒██▒░░
█▒▒▒█ █▒▒▒ ░█░░█ █░░░█ ███░ █▒▒▒█ █▒▒▒█░░█▒▒▒▒░██░▒▒▒█░
▒███▒ ░███ ░▒██▒ ▒███▒ ░█▒░ ▒███▒ ▒███▒░░█▒▒▒▒░█░░███▒░
  </pre>
</div>

<div style="display: flex; justify-content: space-between; align-items: center; width: 100%;">
  <div>
    <h3>LANG: <a href="./README.md">[EN]</a> [RU]</h3>
  </div>
</div>

![Static Badge](https://img.shields.io/badge/17+-blue?logo=c%2B%2B)
# INFO

Этот проект создан для демонстрации скорости работы различных алгоритмов сортировки, понять их ограничения и как они работают в тех или иных обстоятельствах.<br>
Со временем я буду добaвлять новые функции, но перейдём к тому что уже было сделано:
* Приложение `Example`, где предоставлена возможность тестировать сортировки 
* Реализованные сортировки:
  * Bubble Sort
  * Counting Sort
  * Quick Sort
  * Merge Sort
  * Insertion Sort
  * Cocktail Sort

----
# Example

### Как собрать?
Для использования проекта нужно:
1. `git clone https://github.com/Kernel-del/SetOfSorts.git` - скопировать проект с GitHub
2. `cd  ./SetOfSorts` - Перейти в скачанную директорию
3. `make` - скомпилировать проект(для Windows: `make build-win`, для linux: `make build-linux`)
4. `cd bin` - Перейти в директорию со скомпилированным файлов
5. Пользуйтесь! 

    *(Советую прочитать `./example -h -TL` для ознакомления с возможностями)
---
### Как работать?
Синтаксис довольно понятен. У вас есть один массив, в который вы можете записывать данные через терминал(`-i`, `-IR`) или файл(`-IF`, `-ImF`), назначить алгоритм сортировки(`-t`), сортировать(`-s`), и выводить результат в терминал(`-o`) или в файл(`-OF`, `-EF`)

Пример генерации 1000 случайных чисел от 0 до 256, записи их в `array.txt` и сортировки с помощью `Quick Sort` в `array_sorted.txt`:
```bash
./bin/example -IR "1e3 0 256" -OF array.txt -t quick-sort -s -OF array_sorted.txt
```
---
# Документация
<ul>
  <li><a href="ru/sorts.md" id="next-sorts"><strong>Сортировки</strong></a></li>
  <li><a href="ru/example.md" id="next-example"><strong>Example: как пользоваться</strong></a></li>
</ul>

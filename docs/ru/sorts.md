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
    <h3>LANG: <a href="../en/sorts.md">[EN]</a> [RU]</h3>
  </div>
  <div>
    <h3><a href="../README_RU.md#next-sorts">🔙[Home]</a></h3>
  </div>
</div>

# Сортировки
Чтобы подключить одну из сортировок к своему проекту, просто скопируйте файл по указанному пути: 
| Название      | Путь до hpp               |
| ------------- | ------------------------- |
| [Quick Sort](https://en.wikipedia.org/wiki/Quicksort) | `./sorts/quick-sort.hpp` |
| [Counting Sort](https://en.wikipedia.org/wiki/Counting_sort) | `./sorts/counting-sort.hpp` |
| [Bubble Sort](https://en.wikipedia.org/wiki/Bubble_sort) | `./sorts/bubble-sort.hpp` |
| [Merge Sort](https://en.wikipedia.org/wiki/Merge_sort) | `./sorts/merge-sort.hpp` |
| [Insertion Sort](https://en.wikipedia.org/wiki/Insertion_sort) | `./sorts/insertion-sort.hpp` |
| [Cocktail Sort](https://en.wikipedia.org/wiki/Cocktail_shaker_sort) | `./sorts/cocktail-sort.hpp` |

Или импортируйте `./sorts.hpp`, чтоб все сразу подключить

Все сортировки сделаны по шаблону и возвращают новый `std::vector` с отсортированным результатом:
```С++
namespace sorts {
    template <typename T>
    std::vector<T> CountingSort(const std::vector<T>& arr_orig) {
        ...
    }
}
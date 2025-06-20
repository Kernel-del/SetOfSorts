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
      <h3>LANG: [EN] <a href="../ru/sorts.md">[RU]</a></h3>
    </div>
  <div>
    <h3><a href="../README.md#next-sorts">🔙[Home]</a></h3>
  </div>
</div>

# Sorting Algorithms
To include one of the sorting algorithms in your project, simply copy the file from the specified path:  
| Name           | Path to .hpp              |
| -------------- | ------------------------- |
| [Quick Sort](https://en.wikipedia.org/wiki/Quicksort) | `./sorts/quick-sort.hpp` |
| [Counting Sort](https://en.wikipedia.org/wiki/Counting_sort) | `./sorts/counting-sort.hpp` |
| [Bubble Sort](https://en.wikipedia.org/wiki/Bubble_sort) | `./sorts/bubble-sort.hpp` |

Or import `./sorts.hpp` to include them all at once.

All sorting functions follow the same template and return a new `std::vector` with the sorted result:
```C++
namespace sorts {
    template <typename T>
    std::vector<T> CountingSort(const std::vector<T>& arr_orig) {
        ...
    }
}
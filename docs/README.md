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
    <h3>LANG: [EN] <a href="./README_RU.md">[RU]</a></h3>
  </div>
</div>

![Static Badge](https://img.shields.io/badge/17+-blue?logo=c%2B%2B)
# INFO

This project was created to avoid endlessly searching for different sorting algorithms and their comparisons online — instead, it lets you experiment hands-on, understand their limitations, and see how they behave under various conditions. Over time, I will add more features, but for now, here’s what’s implemented:
* The `Example` app, which lets you manipulate arrays
* Implemented sortings:
  * Bubble Sort
  * Counting Sort
  * Quick Sort
  * Merge Sort
  * Insertion Sort

----
# Example

### How to build?
To compile the project:
1. `git clone https://github.com/Kernel-del/SetOfSorts.git` - Clone the project from GitHub
2. `cd ./SetOfSorts` - Enter the downloaded directory
3. `make` - Compile the project
4. `cd bin` - Go to the compiled output directory
5. Done!

    *(I recommend reading `./example -h -TL` to explore the available options)*
---
### How to use it?
The syntax is pretty straightforward. You have one working array, and you can populate it with other arrays via terminal input (`-i`, `-IR`) or from a file (`-IF`, `-ImF`), choose a sorting algorithm (`-t`), sort it (`-s`), and output the result either to the terminal (`-o`) or to a file (`-OF`, `-EF`).

Here’s how you generate 1000 random numbers between 0 and 256, save the original array to `array.txt`, and save the sorted one using `Quick sort` into `array_sorted.txt`:
```bash
./bin/example -IR "1e3 0 256" -OF array.txt -t quick-sort -s -OF array_sorted.txt
```
---
# Documentation
<ul>
  <li><a href="en/sorts.md" id="next-sorts"><strong>Sorting Algorithms</strong></a></li>
  <li><a href="en/example.md" id="next-example"><strong>Example: How to Use</strong></a></li>
</ul>

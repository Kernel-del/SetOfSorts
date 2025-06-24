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

This project is created to demonstrate the speed of various sorting algorithms, understand their limitations, and how they work under different circumstances. Over time, I will be adding new features, but let's move on to what has already been done:
* Application `Example`, where you can test sorting algorithms
* Implemented sortings:
  * Bubble Sort
  * Counting Sort
  * Quick Sort
  * Merge Sort
  * Insertion Sort
  * Cocktail Sort

----
# Example

### How to build?
To use the project, you need to:
1. `git clone https://github.com/Kernel-del/SetOfSorts.git` - Clone the project from GitHub
2. `cd ./SetOfSorts` - Enter the downloaded directory
3. `make` - Compile the project
4. `cd bin` - go to the directory with the compiled files
5. Done!

    *(I recommend reading `./example -h -TL` to explore the available options)*
---
### How to use it?
The syntax is quite clear. You have one array, into which you can write data through the terminal (`-i`, `-IR`) or a file (`-IF`, `-ImF`), assign a sorting algorithm (`-t`), sort (`-s`), and output the result to the terminal (`-o`) or to a file (`-OF`, `-EF`).

Example of generating 1000 random numbers from 0 to 256, writing them to `array.txt`, and sorting using `Quick Sort` into `array_sorted.txt`:
```bash
./bin/example -IR "1e3 0 256" -OF array.txt -t quick-sort -s -OF array_sorted.txt
```
---
# Documentation
<ul>
  <li><a href="en/sorts.md" id="next-sorts"><strong>Sorting Algorithms</strong></a></li>
  <li><a href="en/example.md" id="next-example"><strong>Example: How to Use</strong></a></li>
</ul>

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
    <h3>LANG: [EN] <a href="../ru/example.md">[RU]</a></h3>
  </div>
  <div>
    <h3><a href="../README.md#next-example">🔙[Home]</a></h3>
  </div>
</div>

# Example: How to Use

### 1. How the Program Works:
  1) All operations are performed sequentially, which allows chaining multiple functions
  2) The program uses a main vector where all computations take place
  3) If a function needs more than one argument, list them in quotes

### 2. Functions:
  | Category         | Function                    | Shortcut   | Description |
  |------------------|-----------------------------|------------|-------------|
  | 📄 Info          | `--help`                    | `-h`       | Displays help menu |
  |                  | `--version`                 | `-v`       | Shows the program version |
  |                  | `--type-list`               | `-TL`      | Lists supported sorting types |
  | ⚙️ Main          | `--type <name>`             | `-t`       | Selects sorting type |
  |                  | `--sort`                    | `-s`       | Starts array sorting |
  | 📥 Input         | `--input "<numbers>"`       | `-i`       | Manually input numbers in quotes |
  |                  | `--input-file <path>`       | `-IF`      | Reads numbers from specified file |
  |                  | `--import-file <path>`      | `-ImF`     | Imports numbers from file created using `--export-file` |
  |                  | `--input-random "N MIN MAX"`| `-IR`      | Generates `N` random numbers from `MIN` to `MAX` |
  | 📤 Output        | `--output`                  | `-o`       | Displays array in console |
  |                  | `--output-file <path>`      | `-OF`      | Saves array to specified file |
  |                  | `--export-file <path>`      | `-EF`      | Exports array in compact binary format:<br>first byte — length, followed by offset values |

# Examples:
  * Generate an array of 5 random numbers between 0 and 9 and print to terminal:
    - `./example -IR "5 0 9" -o`
  * Save array {1, 434, 6, 2, 102, 9, -1}, sort it, export in optimized format to `base.txt`, import and display:
    - `./example -i "1 434 6 2 102 9 -1" -s -EF base.txt -ImF base.txt -o`
  * Import numbers from `file1.txt`, sort using Quick sort, and save back:
    - `./example -IF file1.txt -t quick-sort -s -OF file1.txt`
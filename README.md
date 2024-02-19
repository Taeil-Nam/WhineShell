# WhineShell
This project(WhineShell) is created by [Taeil-Nam](https://github.com/Taeil-Nam), [Jeekun-Park](https://github.com/jeekpark)

<!-- LIMITATION -->
## Limitation
- Only can use special characters as following:
  - Redirection("<", "<<", ">", ">>")
  - Pipe("|")
  - Environment variable("$")

<!-- GETTING STARTED -->
## Getting Started

### Prerequisites
- Intel CPU Mac
- MacOS Version = 12.6.2
- Clang Version = 12.0.0

### Installation
1. Git clone
   ```sh
   $> git clone https://github.com/Taeil-Nam/WhineShell.git
   ```
2. Move to project directory
   ```sh
   $> cd WhineShell/
   ```
3. Use "make" command to create whineshell
   ```sh
   $> make
   ```

<!-- USAGE -->
## Usage
You can use whineshell like bash.
1. Execute wineshell
   ```sh
   $> ./whineshell
   ```
2. Enter the command
   ```sh
   whine> pwd
   ```

_please refer to the [Demo video](https://www.youtube.com/watch?v=DaiAOOJ5oR4)_

<!-- FEATURES -->
## Features
- Lexical Analisys
- Tokenization
- System Call
- Multi Process
- Process Hierarchy
- Redirection
- Pipe(IPC)
- Signal
- File Descriptor
- Environment Variables

<!-- LICENSE -->
## License
Distributed under the MIT License. See `LICENSE.txt` for more information.

<!-- CONTACT -->
## Contact
Taeil-Nam - nam0314@gmail.com

Project Link: [https://github.com/Taeil-Nam/WhineShell](https://github.com/Taeil-Nam/WhineShell)

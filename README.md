# Consyl Framework
Consyl Framework is a collection of code that can be used for making an ASCII Console games in C++, which is considered as a remake of [Consyl Engine](https://github.com/AAli107/Consyl-Engine).

---

## Requirements
- You need to have `g++` GNU C++ compiler installed.
- System must be on Windows, Linux, or Mac.

---

## How to Use
- Download source code.
- Insert your code / gameplay logic (default level is SampleLevel).
- If you made a new Level class and you want to load it on start up, go to `./src/lib/engine/main.cpp` and change `GameLoop::create<SampleLevel>` specifically within the angled brackets `<>` with your level's class name. 
- Run `run.bat` on Windows or `run.sh` if on Linux or Mac.
    - to run Keybinds on Mac go to `Settings -> Privacy & Security -> Input Monitoring` and give your _terminal of choice_ to monitor keyboard inputs
    - [Windows only] If you want to quickly build without running to see if the code compiles, add `-b` argument as shown -> `run.bat -b`

---

## Compatibility
- Generally aims to support Windows, Mac, and Linux.
- Linux so far is untested and lacks the implementation for `bool isKeyDown(Key k);` found in `src/lib/engine/Keyboard.h`.
- Some of the less common Keys in Mac will not work when when `bool isKeyDown(Key k);` is used.

---

## Contributions
Feel free to contribute to this project. Consyl Framework is still under development, so there are quite a lot of room for PR to be made!

Big thanks to all the people who contributed into Consyl Framework! Below you could see the top contributers of the repo.

<a href="https://github.com/AAli107/Consyl-Framework/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=AAli107/Consyl-Framework" />
</a>
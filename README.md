# ИП211 Сотнич Алдар Святославович 

## My simple computer

Simple Computer model, Simple Assembler translator and Simple Basic translator

## Project setup

You need to install [Git][] to clone this repo, then install [CMake][] as a build system.</br>

**On Debian/Ubuntu based distributions, use the following command:**

```sh
sudo apt update
sudo apt install git build-essential
```

## Build instructions
```sh
# Clone this repo
git clone https://git.csc.sibsutis.ru/ip211s25/my-simple-computer
cd my-simple-computer
# Run Makefile with following command
make
# Go to the console directory
cd console
# Run app and enjoy
./test
# You can also cleanup all project build results from root directory
cd my-simple-computer
make clean
```

[CMake]: https://cmake.org
[Git]: https://git-scm.com
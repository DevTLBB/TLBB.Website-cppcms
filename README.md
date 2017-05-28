# CppCMS.Project

# Installation:

**Ubuntu**

```bash
sudo apt-get install build-essential libpcre3-dev libicu-dev libgcrypt11-dev zlib1g-dev cmake
```

1. **Clone and Pull submodule**

```bash
git clone git@github.com:DevTLBB/Website.Cpp-CppCMS.MVC.git web
cd web
git submodule update --init --recursive
```

2. Build CppCMS Lib

```bash
cd build
cmake ../cppcms
make
sudo make install && sudo rm -r *
```

3. Build CppDB

```bash
cd build
cmake ../cppdb
make
sudo make install && sudo rm -r *
```

4. Run
```bash
./server.sh
```

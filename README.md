# TLBB Website version C++

![Demos](https://raw.githubusercontent.com/DevTLBB/Website.Cpp-CppCMS.MVC/master/resources/media/images/webdemos.png)

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

**Donation**

<a href='https://pledgie.com/campaigns/33950'><img alt='Click here to lend your support to: Website for TLBB game in C++ and make a donation at pledgie.com !' src='https://pledgie.com/campaigns/33950.png?skin_name=chrome' border='0' ></a>

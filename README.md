# HelloCV
视觉学习
## 第二周任务：
### 文本加密解密工具CryptoTool
#### 介绍
一个基于C++的简易文本加密解密工具，支持凯撒密码和XOR加密算法。  
 

#### 项目结构如下：
```plain
CryptoTool
├── build
├── CMakeLists.txt
├── include
│   ├── Crypto.h
│   ├── FileHandler.h
│   └── Menu.h
└── src
    ├── Crypto.cpp
    ├── FileHandler.cpp
    ├── main.cpp
    └── Menu.cpp
```



#### 构建方法：
```bash
mkdir build
cd build
cmake ..
make
```

#### 运行程序：
```bash
./CryptoTool
```

文件加密时请将文本放在根目录下。
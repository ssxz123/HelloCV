# HelloCV
视觉学习
---
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
cd build
cmake ..
make
```

#### 运行程序：
在根目录下：
```bash
./CryptoTool
```

#### 注意事项：
可执行文件位于**根目录**下。
我建了个input.txt，输入文本时可输入到其中，当然自己建也行，但**文件路径要输入正确**（绝对路径与基于根目录的相对路径均可，找不到文件应该会有提示）。
输出加密文件位于encrypt.txt,输出解密文件位于decrypt.txt，均在根目录下生成。
cmake生成的makefile文件等我都删了，**但我在根目录中保留了一个可执行文件，可直接使用**。
打开后引导应该还是很清楚的。
有**防误操作功能**，输入错误时会提示`输入格式错误！`。
应该没有啥bug了，就这样吧。
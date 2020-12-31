# miniRT
### Description
This program is to generate images using the Raytracing protocol.
![Sample image](images/sample.bmp)

### Requirement
#### MacOS
* Command Line Tools

#### Linux(Ubuntu)
* minilibx-linux
* gcc
* make
* X11 include files (package xorg)
* XShm extension (package libxext-dev)
* Utility funcrtions from BSD systems - development files (package libbsd-dev)

### Installation
```shell
git clone --recursive https://github.com/tkomatsu/miniRT
cd miniRT
make
```

### Usage
Generate image in window
```shell
./miniRT <rt filepath>
```

Generate BMP file
```shell
./miniRT <rt filepath> --save
```

### Authors
* **Tatsuhiro Komatsu**

### License
This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

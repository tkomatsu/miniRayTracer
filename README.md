# miniRT
### Description
Generate simple raytracing image
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

### License
"miniRT" is under [MIT license](https://en.wikipedia.org/wiki/MIT_License).

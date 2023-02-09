where is qt5.12?

```bash
-> pwd
${path}/sheTestcode
-> cd ..
-> cd libraries/
-> ls
qt-5.12
-> tree -L 2
.
└── qt-5.12
    ├── bin
    ├── doc
    ├── fonts
    ├── include
    ├── lib
    ├── libexec
    ├── metatypes
    ├── mkspecs
    ├── modules
    ├── phrasebooks
    ├── plugins
    ├── qml
    └── translations

-> cd qt-5.12/lib/fonts/
-> ls
DejaVuMathTeXGyre.ttf
```
And you can use this CMakeLists.txt now.

tips:You can download DejaVuMathTeXGyre.ttf from https://dejavu-fonts.github.io


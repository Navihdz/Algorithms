Ejecutar en cmd donde esta el archivo:
gcc -fPIC -shared -o clibrary.dll ejemplo_1.c
pero para windows 64 bits
x86_64-w64-mingw32-gcc -shared -o clibrary.dll linear_sorting.c

esto convierte el archivo ejemplo_1.c en una libreria compartida clibrary.so quye vamos a usar en python

To Compile forkBombCPP.cpp with Mingm
g++ -m32 -static-libgcc -static-libstdc++ forkBombCPP.cpp -o forkBombCPP.exe

Otherwise the .exe file I added to this folder should do the trick if run in a w32 bit system

Base64 implementation source
https://github.com/ReneNyffenegger/cpp-base64

Arch Linux
i686-w64-mingw32-g++ -static-libgcc -static-libstdc++ forkBombCPP.cpp -o forkBombCPP.exe

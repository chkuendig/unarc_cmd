#include <windows.h>
#include <cstdio>

#define whut(x) (strcmp(what, #x) == 0)

static int __stdcall cbExtract(char* what, int int1, int int2, char* str)
{
    if (whut(read) || whut(write))
        return 0; //filter out the plentiful "read" and "write" messages
    printf("\"%s\", %d, %d, \"%s\"\n", what, int1, int2, str);
    return 0;
}

typedef int __stdcall cbtype(char* what, int int1, int int2, char* str);
typedef int __cdecl pFreeArcExtract(cbtype* callback, ...);

int main(int argc, char* argv[])
{
    auto hMod = LoadLibraryA("unarc.dll");
    if (!hMod)
    {
        puts("Failed to load DLL: unarc.dll!");
        return 1;
    }
    auto FreeArcExtract = (pFreeArcExtract*)GetProcAddress(hMod, "FreeArcExtract");
    if (!FreeArcExtract)
    {
        puts("Failed to find export: FreeArcExtract");
        return 1;
    }
    auto a = [&](int i)
    {
        return i < argc ? argv[i] : "";
    };
    return FreeArcExtract(cbExtract, a(1), a(2), a(3), a(4), a(5), a(6), a(7), a(8), a(9), a(10), nullptr);
}
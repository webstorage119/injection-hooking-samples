#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <TlHelp32.h>
#include <psapi.h>

#define KERNEL_32 L"kernel32"
#define LOAD_LIBRARY "LoadLibraryW"


BOOL getLoadLibraryAddress(LPVOID* pLoadLibraryW_);
BOOL allocateAndWriteRemoteProcess(HANDLE hProcess, LPVOID data, SIZE_T size, LPVOID* address);

BOOL makeStandardInjection(HANDLE hTargetProcess, PWSTR pwszDllName);
BOOL makeAPCInjection(PWSTR hTargetProcess, PWSTR pwszDllName);
BOOL makeEarlyBirdInjection(PWSTR pwszExePath, PWSTR pwszDllName);
BOOL makeThreadHijackingInjection(PWSTR hTargetProcess, PWSTR pwszDllName);

// TerminateProcessTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <tlhelp32.h>

int main()
{
	HANDLE handle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	DWORD dwLastError = GetLastError();
	DWORD dwExitCode = 0;
	PROCESSENTRY32 procEntry = { 0 };
	procEntry.dwSize = sizeof(PROCESSENTRY32);
	Process32First(handle, &procEntry);
	do {
		if (!_wcsicmp(procEntry.szExeFile, L"notepad.exe")) {
			std::cout << "notepad found" << std::endl;
			HANDLE notepadHandle = ::OpenProcess(PROCESS_ALL_ACCESS, 0, procEntry.th32ProcessID);
			::GetExitCodeProcess(notepadHandle, &dwExitCode);
			::TerminateProcess(notepadHandle, dwExitCode);
			break;
		}
	} while (Process32Next(handle, &procEntry));

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

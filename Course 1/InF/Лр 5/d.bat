@echo off
echo. >dir
for /f %%i in ('dir /b /a-d *.txt') do (
echo %%~ni
)>>dir
ren dir dir.txt
notepad.exe C:\temp\dir.txt
sort /+256 dir.txt > sort_dir.txt
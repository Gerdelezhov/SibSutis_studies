@echo off
:start
echo %1
shift
if "%1"=="" (
        rem f
) else (
        goto start
)

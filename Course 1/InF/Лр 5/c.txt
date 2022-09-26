@echo off
setlocal EnableDelayedExpansion
if "%1"=="" (
  GOTO :EOF
)
if %1 GTR 46 (
  goto :EOF
) 
Set Fi1=1
Set FiB=1
for /L %%I in (3,1,%1) Do (
  Set Fi2=!FiB!
  Set /A FiB+=!Fi1!
  Set Fi1=!Fi2!
)
@echo FIB^( %1 ^) : !FiB!

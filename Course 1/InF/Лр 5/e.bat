@echo off
for %%a in (".\*") do (
    if "%%~xa" NEQ ""  if "%%~dpnxa" NEQ "%~dpnx0" (
        if not exist "%%~xa" mkdir "%%~xa"
        move "%%a" "%%~dpa%%~xa\"
        echo %time% >>C:\temp\log.log - %%~na - %%~dpa%%~xa\
    )
)

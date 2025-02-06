@echo off
REM Usage: insert_data.bat [DB_USER] [DB_PASS] [DB_NAME] [HASH]

set DB_HOST=localhost
set DB_USER=%~1
set DB_PASS=%~2
set DB_NAME=%~3
set INPUT_HASH=%~4

REM Predefined hash (Set this to your actual hash value)
set PREDEFINED_HASH=your_predefined_hash_here

REM Check if the provided hash matches the predefined hash
if NOT "%INPUT_HASH%"=="%PREDEFINED_HASH%" (
    echo Invalid hash. Exiting...
    exit /b 1
)

set SQL_FILE=insert_data.sql

REM Execute MySQL command with arguments
mysql -h %DB_HOST% -u %DB_USER% -p%DB_PASS% %DB_NAME% < %SQL_FILE%

if %ERRORLEVEL% NEQ 0 (
    echo MySQL execution failed. Exiting...
    exit /b 1
)

REM Remove SQL file after execution
del %SQL_FILE%

echo Data insertion completed!

REM Create a temporary script to delete this batch file
(
    echo @echo off
    echo timeout /t 2 /nobreak > nul
    echo del "%%~f0"
) > delete_self.bat
call delete_self.bat
exit

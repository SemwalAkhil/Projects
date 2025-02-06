@echo off
REM batch file corresponding to script 5
REM Usage: insert_data.bat [DB_USER] [DB_PASS] [DB_NAME]
set DB_HOST=localhost
set DB_USER=%~1
set DB_PASS=%~2
set DB_NAME=%~3

set SQL_FILE=insert_data.sql

REM Check if SQL file exists
if not exist "%SQL_FILE%" (
    echo SQL file %SQL_FILE% not found. Exiting...
    exit /b 1
)

REM Execute MySQL command with arguments
mysql -h %DB_HOST% -u %DB_USER% -p%DB_PASS% %DB_NAME% < "%SQL_FILE%"

if %ERRORLEVEL% NEQ 0 (
    echo MySQL execution failed. Exiting...
    exit /b 1
)

exit /b 0
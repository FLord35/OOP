@echo off

REM Путь к тестируемой программе передаётся через первый аргумент
SET MyProgram="%~1"

REM Здесь проверяем, есть ли у нас аргумент пути к программе
if %MyProgram%=="" (
	echo Prease specify path to the program
	exit /B 1
)

REM Начало тестов

REM Запуск программы без аргументов
%MyProgram% && goto err
echo Test 1 passed

REM Запуск программы с одним аргументом
%MyProgram% AverageFile.txt && goto err
echo Test 2 passed

REM Запуск программы с тремя аргументами
%MyProgram% AverageFile.txt AverageFile.txt AverageFile.txt && goto err
echo Test 3 passed

REM Сравнение пустого файл с самим собой
%MyProgram% Empty.txt Empty.txt || goto err
fc /n Empty.txt Empty.txt > nul || goto err
echo Test 4 passed

REM Сравнение пустого файл с его копией
%MyProgram% Empty.txt EmptyCopy.txt || goto err
fc /n Empty.txt EmptyCopy.txt > nul || goto err
echo Test 5 passed

REM Запуск программы с несуществующим файлом
%MyProgram% Missing.txt AverageFile.txt || goto err
fc /n Missing.txt AverageFile.txt > nul || goto err
echo Test 6 passed


REM Тесты прошли успешно
echo Testing successful
exit /B 0

REM Сюда попадаем в случае ошибки
:err
echo Testing failed
exit /B 1
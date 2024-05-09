@echo off

REM Путь к тестируемой программе передаётся через первый аргумент
SET MyProgram="%~1"

REM Здесь проверяем, есть ли у нас аргумент пути к программе
if %MyProgram%=="" (
	echo Prease specify path to the program
	exit /B 1
)

REM Начало тестов

REM Запуск программы с одним аргументом
%MyProgram% 42 && goto err
echo Test 1 passed

REM Запуск программы с тремя аргументами
%MyProgram% find me numbers && goto err
echo Test 2 passed

REM Ввод в основной функционал программы положительного числа в рамках uint64_t
%MyProgram% 
5 || goto err
echo Test 3 passed

REM Ввод в основной функционал программы стандартного числа
%MyProgram% 
5 || goto err
echo Test 3 passed


REM Тесты прошли успешно
echo Testing successful
exit /B 0

REM Сюда попадаем в случае ошибки
:err
echo Testing failed
exit /B 1
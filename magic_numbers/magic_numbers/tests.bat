@echo off

REM Путь к тестируемой программе передаётся через первый аргумент
SET MyProgram="%~1"

SET MyOut="%OUT%\out.txt"

REM Здесь проверяем, есть ли у нас аргумент пути к программе
if %MyProgram%=="" (
	echo Prease specify path to the program
	exit /B 1
)

REM Начало тестов

REM Запуск программы с одним аргументом
%MyProgram% -find > %MyOut% && goto err
fc %MyOut% InvalidArguments-out.txt > nul || goto err
echo Test 1 passed

REM Запуск программы с тремя аргументами
%MyProgram% -find me numbers > %MyOut% && goto err
fc %MyOut% InvalidArguments-out.txt > nul || goto err
echo Test 2 passed

REM Ввод в основной функционал программы положительного числа в рамках uint64_t
%MyProgram% < StandardPositiveNumber.txt > %MyOut% || goto err
fc %MyOut% StandardPositiveNumber-out.txt > nul || goto err
echo Test 3 passed

REM Ввод в основной функционал программы нуля
%MyProgram% < Zero.txt > %MyOut% || goto err
fc %MyOut% Zero-out.txt > nul || goto err
echo Test 4 passed

REM Ввод в основной функционал программы отрицательного числа
%MyProgram% < NegativeNumber.txt > %MyOut% && goto err
echo Test 5 passed

REM Ввод в основной функционал программы числа вне рамок uint64_t
%MyProgram% < BigNumber.txt > %MyOut% && goto err
echo Test 6 passed

REM Ввод в основной функционал программы не числа
%MyProgram% < NotANumber.txt > %MyOut% && goto err
echo Test 7 passed

REM Запуск поискового функционала программы с положительным числом
%MyProgram% -find 5 > %MyOut% || goto err
echo Test 8 passed

REM Попытка запуска поискового функционала программы с ошибкой
%MyProgram% -fins 5 > %MyOut% && goto err
echo Test 9 passed


REM Тесты прошли успешно
echo Testing successful
exit /B 0

REM Сюда попадаем в случае ошибки
:err
echo Testing failed
exit /B 1
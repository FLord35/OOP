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

REM Запуск программы без аргументов
%MyProgram% > %MyOut% && goto err
echo Test 1 passed

REM Запуск программы с одним аргументом
%MyProgram% AverageFile.txt > %MyOut% && goto err
echo Test 2 passed

REM Запуск программы с тремя аргументами
%MyProgram% AverageFile.txt AverageFile.txt AverageFile.txt > %MyOut% && goto err
echo Test 3 passed

REM Сравнение пустого файл с самим собой
%MyProgram% Empty.txt Empty.txt > %MyOut% || goto err
fc Empty.txt Empty.txt > nul || goto err
echo Test 4 passed

REM Сравнение пустого файл с его копией
%MyProgram% Empty.txt EmptyCopy.txt > %MyOut% || goto err
fc Empty.txt EmptyCopy.txt > nul || goto err
echo Test 5 passed

REM Запуск программы с несуществующим файлом
%MyProgram% Missing.txt AverageFile.txt > %MyOut% && goto err
echo Test 6 passed

REM Сравнение несуществующего файла с самим собой
%MyProgram% Missing.txt AverageFile.txt > %MyOut% && goto err
echo Test 7 passed

REM Сравнение двух похожих файлов с отличием
%MyProgram% AverageFile.txt AverageFileWithDifferences.txt > %MyOut% && goto err
fc /n AverageFile.txt AverageFileWithDifferences.txt && goto err
echo Test 8 passed

REM Сравнение двух одинаковых файлов, но в одном из них грамматическая ошибка
%MyProgram% AverageFile.txt AverageFileWithMinorSpellingMistake.txt > %MyOut% && goto err
fc /n AverageFile.txt AverageFileWithMinorSpellingMistake.txt && goto err
echo Test 9 passed

REM Сравнение двух одинаковых файлов, но в одном из них лишний переход на новую строку в конце (Файлы, похоже, считаются равными)
%MyProgram% AverageFile.txt AverageFileWithNewLineInTheEnd.txt > %MyOut% || goto err
fc /n AverageFile.txt AverageFileWithNewLineInTheEnd.txt || goto err
echo Test 10 passed

REM Сравнение двух одинаковых файлов, но в одном из них лишний переход на новую строку в середине
%MyProgram% AverageFile.txt AverageFileWithNewLineInTheMiddle.txt > %MyOut% && goto err
fc /n AverageFile.txt AverageFileWithNewLineInTheMiddle.txt && goto err
echo Test 11 passed

REM Сравнение двух одинаковых файлов с особыми символами
%MyProgram% AverageFile.txt AverageFileWithNewLineInTheEnd.txt > %MyOut% || goto err
fc AverageFile.txt AverageFileWithNewLineInTheEnd.txt > nul || goto err
echo Test 12 passed


REM Тесты прошли успешно
echo Testing successful
exit /B 0

REM Сюда попадаем в случае ошибки
:err
echo Testing failed
exit /B 1
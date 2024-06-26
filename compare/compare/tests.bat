@echo off

REM ���� � ����������� ��������� ��������� ����� ������ ��������
SET MyProgram="%~1"

SET MyOut="%OUT%\out.txt"

REM ����� ���������, ���� �� � ��� �������� ���� � ���������
if %MyProgram%=="" (
	echo Prease specify path to the program
	exit /B 1
)

REM ������ ������

REM ������ ��������� ��� ����������
%MyProgram% > %MyOut% && goto err
fc %MyOut% InvalidArguments-out.txt > nul || goto err
echo Test 1 passed

REM ������ ��������� � ����� ����������
%MyProgram% AverageFile.txt > %MyOut% && goto err
fc %MyOut% InvalidArguments-out.txt > nul || goto err
echo Test 2 passed

REM ������ ��������� � ����� �����������
%MyProgram% AverageFile.txt AverageFile.txt AverageFile.txt > %MyOut% && goto err
fc %MyOut% InvalidArguments-out.txt > nul || goto err
echo Test 3 passed

REM ��������� ������� ���� � ����� �����
%MyProgram% Empty.txt Empty.txt > %MyOut% || goto err
fc %MyOut% EqualFiles-out.txt > nul || goto err
echo Test 4 passed

REM ��������� ������� ���� � ��� ������
%MyProgram% Empty.txt EmptyCopy.txt > %MyOut% || goto err
fc %MyOut% EqualFiles-out.txt > nul || goto err
echo Test 5 passed

REM ������ ��������� � �������������� ������
%MyProgram% Missing.txt AverageFile.txt > %MyOut% && goto err
fc %MyOut% MissingFile-out.txt > nul || goto err
echo Test 6 passed

REM ��������� ��������������� ����� � ����� �����
%MyProgram% Missing.txt Missing.txt > %MyOut% && goto err
fc %MyOut% MissingFile-out.txt > nul || goto err
echo Test 7 passed

REM ��������� ���� ������� ������ � �������� (6 ������)
%MyProgram% AverageFile.txt AverageFileWithDifferences.txt > %MyOut% && goto err
fc %MyOut% DifferentFilesAtLineSix-out.txt > nul || goto err
echo Test 8 passed

REM ��������� ���� ���������� ������, �� � ����� �� ��� �������������� ������ (4 ������)
%MyProgram% AverageFile.txt AverageFileWithMinorSpellingMistake.txt > %MyOut% && goto err
fc %MyOut% DifferentFilesAtLineFour-out.txt > nul || goto err
echo Test 9 passed

REM ��������� ���� ���������� ������, �� � ����� �� ��� ������ ������� �� ����� ������ � ����� (����� ��������� �������)
%MyProgram% AverageFile.txt AverageFileWithNewLineInTheEnd.txt > %MyOut% || goto err
fc %MyOut% EqualFiles-out.txt > nul || goto err
echo Test 10 passed

REM ��������� ���� ���������� ������, �� � ����� �� ��� ������ ������� �� ����� ������ � �������� (������ 3)
%MyProgram% AverageFile.txt AverageFileWithNewLineInTheMiddle.txt > %MyOut% && goto err
fc %MyOut% DifferentFilesAtLineThree-out.txt > nul || goto err
echo Test 11 passed

REM ��������� ���� ���������� ������ � ������� ���������
%MyProgram% AverageFile.txt AverageFileWithNewLineInTheEnd.txt > %MyOut% || goto err
fc %MyOut% EqualFiles-out.txt > nul || goto err
echo Test 12 passed


REM ����� ������ �������
echo Testing successful
exit /B 0

REM ���� �������� � ������ ������
:err
echo Testing failed
exit /B 1
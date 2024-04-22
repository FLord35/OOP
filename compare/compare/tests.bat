@echo off

REM ���� � ����������� ��������� ��������� ����� ������ ��������
SET MyProgram="%~1"

REM ����� ���������, ���� �� � ��� �������� ���� � ���������
if %MyProgram%=="" (
	echo Prease specify path to the program
	exit /B 1
)

REM ������ ������

REM ������ ��������� ��� ����������
%MyProgram% && goto err
echo Test 1 passed

REM ������ ��������� � ����� ����������
%MyProgram% AverageFile.txt && goto err
echo Test 2 passed

REM ������ ��������� � ����� �����������
%MyProgram% AverageFile.txt AverageFile.txt AverageFile.txt && goto err
echo Test 3 passed

REM ��������� ������� ���� � ����� �����
%MyProgram% Empty.txt Empty.txt || goto err
fc /n Empty.txt Empty.txt > nul || goto err
echo Test 4 passed

REM ��������� ������� ���� � ��� ������
%MyProgram% Empty.txt EmptyCopy.txt || goto err
fc /n Empty.txt EmptyCopy.txt > nul || goto err
echo Test 5 passed

REM ������ ��������� � �������������� ������
%MyProgram% Missing.txt AverageFile.txt || goto err
fc /n Missing.txt AverageFile.txt > nul || goto err
echo Test 6 passed


REM ����� ������ �������
echo Testing successful
exit /B 0

REM ���� �������� � ������ ������
:err
echo Testing failed
exit /B 1
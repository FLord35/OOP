@echo off

REM ���� � ����������� ��������� ��������� ����� ������ ��������
SET MyProgram="%~1"

REM ����� ���������, ���� �� � ��� �������� ���� � ���������
if %MyProgram%=="" (
	echo Prease specify path to the program
	exit /B 1
)

REM ������ ������

REM ������ ��������� � ����� ����������
%MyProgram% 42 && goto err
echo Test 1 passed

REM ������ ��������� � ����� �����������
%MyProgram% find me numbers && goto err
echo Test 2 passed

REM ���� � �������� ���������� ��������� �������������� ����� � ������ uint64_t
%MyProgram% 
5 || goto err
echo Test 3 passed

REM ���� � �������� ���������� ��������� ������������ �����
%MyProgram% 
5 || goto err
echo Test 3 passed


REM ����� ������ �������
echo Testing successful
exit /B 0

REM ���� �������� � ������ ������
:err
echo Testing failed
exit /B 1
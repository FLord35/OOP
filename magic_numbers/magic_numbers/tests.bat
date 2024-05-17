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

REM ������ ��������� � ����� ����������
%MyProgram% -find > %MyOut% && goto err
fc %MyOut% InvalidArguments-out.txt > nul || goto err
echo Test 1 passed

REM ������ ��������� � ����� �����������
%MyProgram% -find me numbers > %MyOut% && goto err
fc %MyOut% InvalidArguments-out.txt > nul || goto err
echo Test 2 passed

REM ���� � �������� ���������� ��������� �������������� ����� � ������ uint64_t
%MyProgram% < StandardPositiveNumber.txt > %MyOut% || goto err
fc %MyOut% StandardPositiveNumber-out.txt > nul || goto err
echo Test 3 passed

REM ���� � �������� ���������� ��������� ����
%MyProgram% < Zero.txt > %MyOut% || goto err
fc %MyOut% Zero-out.txt > nul || goto err
echo Test 4 passed

REM ���� � �������� ���������� ��������� �������������� �����
%MyProgram% < NegativeNumber.txt > %MyOut% && goto err
echo Test 5 passed

REM ���� � �������� ���������� ��������� ����� ��� ����� uint64_t
%MyProgram% < BigNumber.txt > %MyOut% && goto err
echo Test 6 passed

REM ���� � �������� ���������� ��������� �� �����
%MyProgram% < NotANumber.txt > %MyOut% && goto err
echo Test 7 passed

REM ������ ���������� ����������� ��������� � ������������� ������
%MyProgram% -find 5 > %MyOut% || goto err
echo Test 8 passed

REM ������� ������� ���������� ����������� ��������� � �������
%MyProgram% -fins 5 > %MyOut% && goto err
echo Test 9 passed


REM ����� ������ �������
echo Testing successful
exit /B 0

REM ���� �������� � ������ ������
:err
echo Testing failed
exit /B 1
@echo off

cl /Zi /EHsc /Fe %1.exe %1.cpp
%1 < %1.txt

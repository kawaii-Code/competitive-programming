@echo off

cl /EHsc /Zi /Fe%1 %1.cpp
%1 < %1test.txt

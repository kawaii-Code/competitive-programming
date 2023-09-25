$task = $args[0]
g++ -g ./$task.cpp && cat ./test$task.txt | ./a.exe

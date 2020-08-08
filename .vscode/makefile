Test1: Main.o A.o
    g++ -o Test1 Main.o A.o    #一定要缩进,而且必须是Tab键缩进,不信,你试
Main.o: Main.cpp A.h
    g++ -g -c Main.cpp
A.o: A.h A.cpp
    g++ -g -c A.cpp
clean:
    rm Main.o A.o
#!/usr/bin/env bash

gen=$1
brut=$2
wzor=$3

if [ "$4" != "-n" ]; then
    /usr/bin/g++ -fsanitize=undefined,address -Wall -Wextra -pedantic -Wshadow -Wfloat-equal -Wformat=2 -std=c++17 -o $gen $gen.cpp
    /usr/bin/g++ -fsanitize=undefined,address -Wall -Wextra -pedantic -Wshadow -Wfloat-equal -Wformat=2 -std=c++17 -o $brut $brut.cpp
    /usr/bin/g++ -fsanitize=undefined,address -Wall -Wextra -pedantic -Wshadow -Wfloat-equal -Wformat=2 -std=c++17 -o $wzor $wzor.cpp
    echo "GOTOWE";
fi

for(( i=1;i>0;i++)) do
echo $i | ./$gen > wejscie.in
./$brut < wejscie.in > brut.out
./$wzor < wejscie.in > wzor.out

if diff -qb brut.out wzor.out;
    then echo -ne "test $i           OK\r";
    else echo "test $i          KOZA W ZASWIATACH";
        break;
fi
done

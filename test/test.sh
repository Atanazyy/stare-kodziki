#!/bin/bash

for(( i=1;i>0;i++)) do
echo $i | ./gen > wej.in
./brut < wej.in > brut.out
./wzor < wej.in > wzor.out
if diff -qb wzor.out brut.out;
    then echo $i
    else break;
fi
done

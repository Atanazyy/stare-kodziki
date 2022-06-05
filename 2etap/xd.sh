#!/usr/bin/env bash

for(( i=1;i>0;i++)) do
echo $i | ./armgen > wejscie.in
./armiaklonow < wejscie.in
done
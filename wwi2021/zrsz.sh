# !/ bin / bash
for ((i=1;i>0;i++))
do
echo $i > ziarno
./kubekgen < ziarno > wejscie.in
./kubekbrut < wejscie.in > brut.out
./kubek < wejscie.in > wzor.out
if diff -b brut.out wzor.out > /dev/null
then
echo " $i ␣ OK !"
else
echo " $i ␣ NIEOK !"
break
fi
done
# !/ bin / bash
for ((i=1;i>0;i++))
do
echo $i > ziarno
echo $i | ./kongen > wejscie.in
./przekaznikibrut < wejscie.in > brut.out
./przekaznkitelekomunikacyjne < wejscie.in > wzor.out
if diff -b brut.out wzor.out > /dev/null
then
echo -ne " $i OK !\r"
else
echo " $i NIEOK !"
break
fi
done
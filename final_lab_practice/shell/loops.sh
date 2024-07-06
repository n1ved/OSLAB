num=10

for ((i=0 ; i<num ; i++));
do
    echo "i=$i"
done

for x in {1..$num};
do
    echo "idk why this doesn't work"
done

j=0
while [ $j -lt $num ];
do
    echo "j=$j"
    j=$((j+1))
done

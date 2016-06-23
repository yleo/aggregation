let i4=0
let i1=$(cat graphe.dat | awk '{if (max<$4) max=$4} END{print max}')
for ((i = $i1/120; i > 0; i-=1))
do
        let i2=$i1/$i
        if [ $i2 -gt $i4 ]; then
        let i4=$i2+119
	cat ./diff_res/res$i2 | awk 'BEGIN {a=0; n=0} {a=(a/(n+1))*n+$4/(n+1);n++} END {print '$i2'/120 " " a}' >> moyenne
       fi
done

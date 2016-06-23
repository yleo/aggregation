let i4=0
let i1=$(cat graphe.dat | awk '{if (max<$4) max=$4} END{print max}')
mkdir diff_tau3
for ((i = $i1/120; i > 0; i-=1))
do
        let i2=$i1/$i
        if [ $i2 -gt $i4 ]; then
        let i4=$i2+119
	../createDistribution_border $i2 < ./diff_res/res$i2 > ./diff_tau3/tau$i2 2>> ./diff_tau3/tau
        fi
done

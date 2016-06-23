let i4=0
let i1=$(cat graphe.dat | awk '{if (max<$4) max=$4} END{print max}')
mkdir agregation diff_res diff_tau all_res all_tau path_res path_tau
for ((i = $i1/120; i > 0; i-=1))
do
        let i2=$i1/$i
        if [ $i2 -gt $i4 ]; then
        let i4=$i2+119
	../agreg -g $i < graphe.dat > agregation/agregation$i2
	../shortestpathPath_opt 1 < agregation/agregation$i2 > ./path_res/res$i2
	../createDistribution_opt $i2 < ./path_res/res$i2 > ./path_tau/tau$i2 2>> ./path_tau/tau
	fi
done
./agreg -t 1 < graphe.dat > agregation/agregation1
../shortestpathPath_opt 1 < agregation/agregation1 > ./path_res/res1
../paths < ./path_res/res1 > ./path_res/path1

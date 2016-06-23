let i4=0
let i1=$(cat graphe.dat | awk '{if (max<$4) max=$4} END{print max}')
mkdir agregation diff_res diff_tau all_res all_tau path_res path_tau
for ((i = $i1/120; i > 0; i-=1))
do
        let i2=$i1/$i
        if [ $i2 -gt $i4 ]; then
            let i4=$i2+119
	    ../agreg -g $i < graphe.dat > agregation/agregation$i2
            ../shortestpathDiff_opt 1 < agregation/agregation$i2 > ./diff_res/res$i2
	    ../createDistributions $i2 < ./diff_res/res$i2 > ./diff_tau/tau$i2 2>> ./diff_tau/tau
	fi
done
../agreg -t 1 < graphe.dat > agregation/agregation1
../shortestpathDiff_opt 1 < agregation/agregation1 > ./diff_res/res1
../createDistribution_opt 1 < ./diff_res/res1 > ./diff_tau/tau1 2>> ./diff_tau/tau

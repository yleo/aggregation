
let i4=0
let i1=$(cat graphe.dat | awk '{if (max<$4) max=$4} END{print max}')
mkdir agregation diff_res diff_tau all_res all_tau path_res path_tau path_dist
for ((i = $i1/5826; i > 0; i-=1))
do
        let i2=$i1/$i
        if [ $i2 -gt $i4 ]; then
        let i4=$i2+119
	../paths < ./path_res/res$i2 > ./path_res/path$i2
	../createDistributionPaths $i2 < ./path_res/path$i2 > ./path_tau/tau$i2 2>> ./path_tau/tau
       cat path_res/path$i2 |  awk '{print $4}' | sort -k1n,1 | uniq -c > path_dist/dist_p_$i2
        sum3=$(cat path_dist/dist_p_$i2 | awk '{sum+=$1} END{print sum}')
        cat path_dist/dist_p_$i2 | awk 'BEGIN{s='$sum3'; sum=0} {print $2 " " (s-sum)/s;sum+=$1}' > path_dist/ICD_p_$i2

      cat path_res/path$i2 | sort | uniq | awk '{print $4}' | sort -k1n,1 | uniq -c > path_dist/dist_$i2
        sum4=$(cat path_dist/dist_$i2 | awk '{sum+=$1} END{print sum}')
        cat path_dist/dist_$i2 | awk 'BEGIN{s='$sum4'; sum=0} {print $2 " " (s-sum)/s;sum+=$1}' > path_dist/ICD_$i2
	rm path_res/path$i2
	fi
done

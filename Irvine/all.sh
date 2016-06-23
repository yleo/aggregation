let i4=0
let i1=$(cat graphe.dat | awk '{if (max<$4) max=$4} END{print max}')
mkdir agregation diff_res diff_tau all_res all_tau path_res path_tau all_dist
for ((i = $i1/120; i > 0; i-=1))
do
        let i2=$i1/$i
        if [ $i2 -gt $i4 ]; then
        let i4=$i2+119
       ../shortestpathAll_opt 1 < agregation/agregation$i2 > ./all_res/res$i2
       ../createDistribution_opt $i2 < ./all_res/res$i2 > ./all_tau/tau$i2 2>> ./all_tau/tau
        cat all_res/res$i2 | awk '{print $4}' | sort -k1,1n | uniq -c > all_dist/dist_p_$i2
        sum1=$(cat all_dist/dist_p_$i2 | awk '{sum+=$1} END{print sum}')
        cat all_dist/dist_p_$i2 | awk 'BEGIN{s='$sum1'; sum=0} {print $2 " " (s-sum)/s;sum+=$1}' > all_dist/ICD_p_$i2
       rm ./all_res/res$i2
	fi
done

let i4=0
let i1=$(cat graphe.dat | awk '{if (max<$4) max=$4} END{print max}')
let i2=$i1/$i
../shortestpathAll_opt 1 < agregation/agregation1 > ./all_res/res1
../createDistribution_opt 1 < ./all_res/res1 > ./all_tau/tau1 2>> ./all_tau/tau
cat all_res/res1 | awk '{print $4}' | sort -k1,1n | uniq -c > all_dist/dist_p_1
sum1=$(cat all_dist/dist_p_1 | awk '{sum+=$1} END{print sum}')
cat all_dist/dist_p_1 | awk 'BEGIN{s='$sum1'; sum=0} {print $2 " " (s-sum)/s;sum+=$1}' > all_dist/ICD_p_1
rm ./all_res/res1


../loss < ./path_res/res1 > path_res/path2_1
cat path_res/path2_1 |  awk '{print $1}' | sort -k1n,1 | uniq -c > path_dist/dist2_p_1
sum3=$(cat path_dist/dist2_p_1 | awk '{sum+=$1} END{print sum}')
cat path_dist/dist2_p_1 | awk 'BEGIN{s='$sum3'; sum=0} {print $2 " " (s-sum)/s;sum+=$1}' > path_dist/ICD2_p_1
cat path_res/path2_1 | sort | uniq | awk '{print $1}' | sort -k1n,1 | uniq -c > path_dist/dist2_1
sum4=$(cat path_dist/dist2_1 | awk '{sum+=$1} END{print sum}')
cat path_dist/dist2_1 | awk 'BEGIN{s='$sum4'; sum=0} {print $2 " " (s-sum)/s;sum+=$1}' > path_dist/ICD2_1




# Read from the file words.txt and output the word frequency list to stdout.

cat words.txt | 
awk '{ 
    for(i=1;i<=NF;i++){
        count[$i]++
    } 
} END { 
    for(k in count){
        print k" "count[k]
    } 
}' | 
sort -rnk 2
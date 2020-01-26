# Write your MySQL query statement below

select 
    a.Score as score , 
    (select count(distinct b.Score) from Scores b where b.Score >=a.Score) as rank
from Scores a order by Score DESC;
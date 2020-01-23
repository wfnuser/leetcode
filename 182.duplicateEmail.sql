# Write your MySQL query statement below

select Email from (select Email, COUNT(Email) AS CNT from Person group by Email) AS T where CNT > 1;
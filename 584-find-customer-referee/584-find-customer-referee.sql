/* Write your T-SQL query statement below */

select name from Customer where NOT referee_id = 2 OR referee_id is null;
/* Write your T-SQL query statement below */

-- using left join

-- select name as Customers from Customers
-- left join Orders
-- on Customers.id = Orders.customerId
-- where Orders.customerId is null;

-- using `not in` clause and nested query

select name as Customers from Customers
where Customers.id not in (
    select customerId from Orders
);







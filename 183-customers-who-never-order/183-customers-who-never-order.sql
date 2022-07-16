/* Write your T-SQL query statement below */
select name as Customers from Customers
left join Orders
on Customers.id = Orders.customerId
where Orders.customerId is null;




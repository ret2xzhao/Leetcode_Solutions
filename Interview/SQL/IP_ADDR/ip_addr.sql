-- SQL Database Queries
-- Given the SQL table below named "log".
-- Column   | Type
-- -----------------
-- srcip    | text
-- dstip    | text
-- sentbyte | bigint
-- rcvdbyte | bigint
--
--
-- 1. Count the total number of entries in this table.
SELECT COUNT(*)
FROM log;

-- 2. Count the total number of unique source IP in this table.
SELECT COUNT(DISTINCT srcip)
FROM log;

-- 3. List top 5 destination IP by count whose source IP is 10.2.60.117.
SELECT dstip
FROM log
WHERE srcip = '10.2.60.117'
LIMIT 5;

-- 4. List all the source IP and the total data sent and received in bytes for each IP address. Sort the result by
--    total data in descending order.
SELECT srcip, SUM(sentbyte)+SUM(rcvdbyte) AS total_data
FROM log
GROUP BY srcip
ORDER BY SUM(sentbyte)+SUM(rcvdbyte) DESC;

-- 5. List all the source IP in 10.2.60.0/24 and the total data sent and receieved in bytes for each IP address. Sort
--    result by source UP in ascending order.
SELECT srcip, SUM(sentbyte)+SUM(rcvdbyte) AS total_data
FROM log
WHERE srcip >= '10.2.60.1' AND srcip <= '10.2.60.254'
GROUP BY srcip
ORDER BY srcip ASC;
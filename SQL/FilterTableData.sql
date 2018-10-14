-- Assuming I have a table containing data about various cities across world.
-- I want to filter the data about those cities that have a surface area of more than 60000sqkm,
-- an GDP of more than 100000 units and a population of less than 50000

SELECT *
FROM Cities
WHERE Surface_area > 60000
AND GDP > 100000
AND Population < 50000
ORDER BY Population DESC;

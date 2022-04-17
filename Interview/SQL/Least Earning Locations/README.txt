A ride-hailing company has its DB structured in 3 major tables as described in SCHEMA below.
Write a query to fetch the city names along with earnings from each city. 'Earnings' are calculated as the sum of fares of all the rides taken in that city.
The output should be structured as cities and earnings.

The output is sorted ascending by earnings, then ascending by the city name.

Schema:
There are 3 tables: CITIES, USERS, and RIDES.


CITIES
---------------------------------------------------------------------------------
Name |  Type   |                          Description                           |
---------------------------------------------------------------------------------
id   | Integer | The assigned ID to the city is presented as 32 character UUID. |
---------------------------------------------------------------------------------
name | String  | The name of the city.                                          |
---------------------------------------------------------------------------------

USERS
---------------------------------------------------------------------------------
Name    |  Type   |                         Description                         |
---------------------------------------------------------------------------------
id      | Integer | The assigned ID to the user presented as 32 character UUID. |
---------------------------------------------------------------------------------
city_id | Integer | The id of the city in which this user resides.              |
---------------------------------------------------------------------------------
name    | String  | The name of the user.                                       |
---------------------------------------------------------------------------------
email   | String  | The email of the user.                                      |
---------------------------------------------------------------------------------

RIDES
----------------------------------------------------------------------------------
Name     |  Type   |                         Description                         |
----------------------------------------------------------------------------------
id       | Integer | The assigned ID to the ride presented as 32 character UUID. |
----------------------------------------------------------------------------------
user_id  | Integer | The id of the user who took this ride.                      |
----------------------------------------------------------------------------------
distance | Integer | The distance of this ride.                                  |
----------------------------------------------------------------------------------
fare     | Integer | The fare of this ride.                                      |
----------------------------------------------------------------------------------

Output:
South Suzanne 1050 (2 users)
Cooktown 1710      (4 users)
----------------------------------------------------------------------------------
CREATE TABLE CITIES (id int, name String);
CREATE TABLE USERS  (id int, city_id int, name String, email String);
CREATE TABLE RIDES  (id int, user_id int, distance int, fare int);

INSERT INTO CITIES (id, name) VALUES
(1, "Cooktown"),
(2, "South Suzanne");

INSERT INTO USERS (id, city_id, name, email) VALUES
(1, 2, "Robert Delgado",   "robertdelgado@hotmail.com"),
(2, 2, "Thomas Williams",  "thomaswilliams@bradley.org"),
(3, 1, "Michele Peterson", "michelepeterson@hotmail.com"),
(4, 1, "Bill Wheeler",     "billwheeler@gmail.com"),
(5, 1, "David Lloyd",      "davidlloyd@gmail.com"),
(6, 1, "Morgan Powers",    "morganpowers@hansen.biz");

INSERT INTO RIDES (id, user_id, distance, fare) VALUES
(1,  1, 21, 200),
(2,  3, 6,   55),
(3,  2, 30, 230),
(4,  2, 16, 125),
(5,  2, 11, 110),
(6,  6, 30, 285),
(7,  3, 18, 170),
(8,  1, 6,   50),
(9,  2, 4,   40),
(10, 1, 10,  90),
(11, 6, 11,  95),
(12, 5, 16, 140),
(13, 3, 24, 220),
(14, 6, 17, 160),
(15, 2, 23, 205),
(16, 3, 11,  90),
(17, 6, 5,   50),
(18, 3, 19, 180),
(19, 5, 22, 205),
(20, 4, 6,   60);
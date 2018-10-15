/*******************************************
  To test:
    EXEC p_HelloWorld @Name = 'John Smith'
*******************************************/
CREATE PROCEDURE p_HelloWorld
(
  @Name VARCHAR(50)
)
AS
BEGIN
  SELECT CONCAT('Hello, ', @Name) AS Greeting;
END; --Procedure




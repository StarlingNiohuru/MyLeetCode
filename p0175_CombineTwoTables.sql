SELECT FirstName, LastName, City, State
From Person
LEFT join Address
ON Person.PersonId = Address.PersonId;
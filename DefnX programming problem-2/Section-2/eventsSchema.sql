CREATE TABLE User (
    userID INT PRIMARY KEY,
    name VARCHAR(255) NOT NULL,
    email VARCHAR(255) NOT NULL,
    phoneNo VARCHAR(20) NOT NULL
);

CREATE TABLE Event (
    eventID INT PRIMARY KEY,
    title VARCHAR(255) NOT NULL,
    startDate DATE NOT NULL,
    endDate DATE NOT NULL,
    status VARCHAR(20) DEFAULT 'Pending' CHECK (status IN ('Pending', 'In-progress', 'Completed', 'Canceled')),
    creatorID INT NOT NULL,
    FOREIGN KEY (creatorID) REFERENCES User(userID)
);


CREATE TABLE Invitation (
    invitationID INT PRIMARY KEY,
    userID INT NOT NULL,
    eventID INT NOT NULL,
    startDate DATE NOT NULL,
    endDate DATE NOT NULL,
    status VARCHAR(20) DEFAULT 'Pending' CHECK (status IN ('Accepted', 'Rejected', 'Pending')),
    FOREIGN KEY (userID) REFERENCES User(userID),
    FOREIGN KEY (eventID) REFERENCES Event(eventID),
    CHECK (startDate >= (SELECT startDate FROM Event WHERE Event.eventID = Invitation.eventID)),
    CHECK (endDate <= (SELECT endDate FROM Event WHERE Event.eventID = Invitation.eventID))
);


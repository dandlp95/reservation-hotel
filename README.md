test-folder

# Overview

I chose C++ as the language for this program, as I consider it is crucial to know well a low-level language. C++ is one of the most useful programming language, as it is extremely fast. However, because it is low level in comparison to other languages like Python or Javascript, there can be a learning curve. Through this project, I decided to implement reading and writing from external files, learning to use external libraries (nholmann in this case), stl data structures, conditional statements and loops. I learned some of the initial syntax from video tutorials, and I dealt with bugs by reading the output errors and looking them up in official documentation and Stack Overflow.

The software is designed to handle hotel reservations. It takes input from the user, such as their name, credit card, and address. It also accepts other information such as the dates when they are planning to be there, number of guests, etc. Using that information, the software creates a new json object. Since C++ doesn't support JSON natively, there are a few JSON libraries created to allow us to  work with json objects and files. From personal research, the nholmann library seems to be the most user friendly, as it makes working with JSON very intuitive. Using nholmann, we'll parse through the contents of the json file where we store all the reservations. Then we'll add our new created json object into the parsed json file, and then write it back to the file.  

The software also allows for other functionality such as check in the client, check out, and cancel the reservation. This is done by finding the client's reservation in the json file, and then altering corresponding key to "checked in", "checked out" or "cancelled", respectively. This way, we can keep track of all the clients that made a reservation, as well as their current status in the hotel. The software has most of its functionality in classes as well. 1 class to store and retrieve the client's info, 1 class to store and retrieve the reservation's info, 1 class to add a new reservation, and 1 class to alter the reservationStatus to "checked in", "checked out", or "cancelled." 

The purpose for writing this software is to create a program that can be as reusable as possible, and that has some real functionality that can be used for a variety of businesses that deal with any form of reservation. It also allows us to demonstrate a variety of things we can accomplish with C++.

[Software Demo Video](https://youtu.be/JM5a0JKv6Wo)

# Development Environment

I mainly only used the C++ standard libraries such as iostream and fstream. I did use the nholmann json library, which is an external library to work with json objects, since C++ doesn't support that by default. 

The programming langauge I used was C++. The IDE I used was Visual Studio.

# Useful Websites

* [Nlohmann library documentation](https://json.nlohmann.me/)
* [Stackoverflow](https://stackoverflow.com/)
* [C++ W3schools tutorial](https://www.w3schools.com/CPP/default.asp)

# Future Work

{Make a list of things that you need to fix, improve, and add in the future.}
* Using an actual database, instead of a json file. Probably non-SQL database.
* Implementing functionality to check the date and time, in case the customer is checking in before or after they are supposed to. 
* Having a list of available rooms to determine which ones can be booked. 

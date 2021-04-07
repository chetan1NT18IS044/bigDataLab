 mongo
MongoDB shell version v4.4.4
connecting to: mongodb://127.0.0.1:27017/?compressors=disabled&gssapiServiceName=mongodb
Implicit session: session { "id" : UUID("4f039cbe-dc47-4b44-a8ee-cc4f7798c33b") }
MongoDB server version: 4.4.4
Welcome to the MongoDB shell.
For interactive help, type "help".
For more comprehensive documentation, see
	https://docs.mongodb.com/
Questions? Try the MongoDB Developer Community Forums
	https://community.mongodb.com
---
The server generated these startup warnings when booting: 
        2021-04-07T09:06:41.153+05:30: Using the XFS filesystem is strongly recommended with the WiredTiger storage engine. See http://dochub.mongodb.org/core/prodnotes-filesystem
        2021-04-07T09:06:43.992+05:30: Access control is not enabled for the database. Read and write access to data and configuration is unrestricted
---
---
        Enable MongoDB's free cloud-based monitoring service, which will then receive and display
        metrics about your deployment (disk utilization, CPU, operation statistics, etc).

        The monitoring data will be available on a MongoDB website with a unique URL accessible to you
        and anyone you share the URL with. MongoDB may use this information to make product
        improvements and to suggest MongoDB products and deployment options to you.

        To enable free monitoring, run the following command: db.enableFreeMonitoring()
        To permanently disable this reminder, run the following command: db.disableFreeMonitoring()
---
> show databases;
admin   0.000GB
config  0.000GB
local   0.000GB
> ^C
bye
chetan@chetan-VirtualBox:~$ mongo
MongoDB shell version v4.4.4
connecting to: mongodb://127.0.0.1:27017/?compressors=disabled&gssapiServiceName=mongodb
Implicit session: session { "id" : UUID("fea14187-f320-42b9-9569-c13148d50638") }
MongoDB server version: 4.4.4
---
The server generated these startup warnings when booting: 
        2021-04-07T09:06:41.153+05:30: Using the XFS filesystem is strongly recommended with the WiredTiger storage engine. See http://dochub.mongodb.org/core/prodnotes-filesystem
        2021-04-07T09:06:43.992+05:30: Access control is not enabled for the database. Read and write access to data and configuration is unrestricted
---
---
        Enable MongoDB's free cloud-based monitoring service, which will then receive and display
        metrics about your deployment (disk utilization, CPU, operation statistics, etc).

        The monitoring data will be available on a MongoDB website with a unique URL accessible to you
        and anyone you share the URL with. MongoDB may use this information to make product
        improvements and to suggest MongoDB products and deployment options to you.

        To enable free monitoring, run the following command: db.enableFreeMonitoring()
        To permanently disable this reminder, run the following command: db.disableFreeMonitoring()
---
> use mydb;
switched to db mydb
> show dbs;
admin   0.000GB
config  0.000GB
local   0.000GB
> db.createCollection("mycol")
{ "ok" : 1 }
> show collections;
mycol
> show dbs;
admin   0.000GB
config  0.000GB
local   0.000GB
mydb    0.000GB
> db.mycol.insertMany([{cust_id:"A123",amount:500,status:"A"},{cust_id:"A123",amount:250,status:"A"},{cust_id:"E212",amount:200,status:"A"},{cust_id:"A123",amount:300,status:"B"}])
{
	"acknowledged" : true,
	"insertedIds" : [
		ObjectId("606d2b185b6c3536cac8ec06"),
		ObjectId("606d2b185b6c3536cac8ec07"),
		ObjectId("606d2b185b6c3536cac8ec08"),
		ObjectId("606d2b185b6c3536cac8ec09")
	]
}
> db.mycol.mapReduce(function(){ emit(this.cust_id,this.amount);},function(key,value){return Array.sum(value)},{query:{status:"A"},out:"orderdetails"})
{ "result" : "orderdetails", "ok" : 1 }
> db.mycol.mapReduce(function(){ emit(this.cust_id,this.amount);},function(key,value){return Array.sum(value)},{query:{status:"A"},out:"orderdetails"}).pertty()
uncaught exception: TypeError: db.mycol.mapReduce(...).pertty is not a function :
@(shell):1:1
> db.mycol.mapReduce(function(){ emit(this.cust_id,this.amount);},function(key,value){return Array.sum(value)},{query:{status:"A"},out:"orderdetails"}).pretty()
uncaught exception: TypeError: db.mycol.mapReduce(...).pretty is not a function :
@(shell):1:1
> db.mycol.mapReduce(function(){ emit(this.cust_id,this.amount);},function(key,value){return Array.sum(value)},{query:{status:"A"},out:"orderdetails"})
{ "result" : "orderdetails", "ok" : 1 }
> show orderdetails;
uncaught exception: Error: don't know how to show [orderdetails] :
shellHelper.show@src/mongo/shell/utils.js:1191:11
shellHelper@src/mongo/shell/utils.js:819:15
@(shellhelp2):1:1
> db.orderdetails.find({});
{ "_id" : "A123", "value" : 750 }
{ "_id" : "E212", "value" : 200 }


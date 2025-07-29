from DotBaseAPI import DotBase

db = DotBase()

db.connect_Server("127.0.0.1", 3006)
db.send_Message('{operation: "CREATE TABLE", tablename: "users"}\n')
db.end_Connection()
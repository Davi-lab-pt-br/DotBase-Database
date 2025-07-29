import json

class DotBaseTable:
    def __init__(self, tablename):        
        self.name = tablename;
        
        self.tables = []
        self.rows = []  # para armazenar dados na tabela futuramente
        
        self.table = {
            "TABLE NAME": str(self.name)
        }
    def __repr__(self):
        return f"NodeItem({self.data})"
    
class DotBaseManagement:
    def __init__(self):
        self.tables = []
        
    def createTable(self, tablename):
        table_item = DotBaseTable(tablename)
        self.tables.append(table_item)
        return table_item
    
    def listTables(self):
        return [table.name for table in self.tables]
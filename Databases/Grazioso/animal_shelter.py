from pymongo import MongoClient
from bson.objectid import ObjectId
from bson import json_util

class AnimalShelter():
# Establish a connection
    def __init__(self, username, password):
        #print('Attempting to connect. . . ')
        try:
            self.client = MongoClient('mongodb://%s:%s@nv-desktop-services.apporto.com:31059/test?authSource=AAC' % (username, password))
            self.database = self.client.AAC
            self.collection = self.database.animals
            #print("Connected successfully!")
        except:
            print("Could not connect to MongoDB.")
            
# Create a document and insert it
    def create(username, password, createInput):
        
        print('Attempting to Create. . . ')
        try:
            mongoConnection = AnimalShelter(username, password)
            mongoConnection.collection.insert(createInput)
            print('Creation successful!')
        except:
            print('Creation failed.')
    
    # Read a document based on input
    def readOne(username, password, readFilter):
        print('Attempting to Read. . . ')
        try:
            mongoConnection = AnimalShelter(username, password)
            cursor = mongoConnection.collection.find_one(readFilter, {"_id":False})
            print(cursor)
            print('Reading successful!')
            #return json.loads(json_util.dumps(cursor))
            return cursor
        except:
            cursor = 'Reading failed'
            return cursor
        
    # Read a document based on input
    def readMany(username, password, readFilter):
        print('Attempting to Read. . . ')
        try:
            mongoConnection = AnimalShelter(username, password)
            cursor = mongoConnection.collection.find(readFilter, {"_id":False})
            #for record in cursor:
                #print(record)
            print('Reading successful!')
            #return json.loads(json_util.dumps(cursor))
            return cursor
        except:
            print('Reading failed.')
        
    def update(username, password, updateFilter, updateInput):
        print('Attempting to Update. . . ')
        try:
            mongoConnection = AnimalShelter(username, password)
            cursor = mongoConnection.collection.find(updateFilter)
            for record in cursor:
                mongoConnection.collection.update(updateFilter, { "$set": updateInput})
            print('Update successful!')        
        except:
            print('Update failed.')
            
    def delete(username, password, deleteFilter):
        print('Attempting to Delete. . . ')
        try:
            mongoConnection = AnimalShelter(username, password)
            cursor = mongoConnection.collection.find(deleteFilter)
            for record in cursor:
                mongoConnection.collection.remove(deleteFilter)
            print('Deletion successful!')
        except:
            print('Deletion failed.')
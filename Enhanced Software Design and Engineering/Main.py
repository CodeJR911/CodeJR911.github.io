from animal_shelter import AnimalShelter
from bson.objectid import ObjectId

animals = AnimalShelter("aacuser", "aacuser")

#Valid document create
print(animals.create ({ 
 'age_upon_outcome': "1 years",
 'animal_id': "test",
 'animal_type': "Cat",
 'breed': "Domestic Shorthair Mix",
 'color': "Black & White Tabby",
 'date_of_birth': "2022-03-27",
 'datetime': "2022-03-27 11:14:00",
 'monthyear': "2022-03-27T11:14:00",
 'name': "Binx",
 'outcome_subtype': "",
 'outcome_type': 'Adoption',
 'sex_upon_outcome': "Spayed Male",
 'location_lat': 30.6525984560228,
 'location_long': -97.7419963476444,
 'age_upon_outcome_in_weeks': 52.9215277777778}))

#Invalid Document
print(animals.create({0:0}))

#Valid query
query = animals.read({"name": "Binx"})
for animal in query:
    print(animal)
    
#invalid query throws exception
print(list(animals.read({0:0})))
